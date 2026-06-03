// AudioSourceData 淡入淡出公式的烟测。
// 旧实现：_as.volume += _fadeOffsetVolume / _fadeSeconds * dt * _fadeDir;
//         公式错误 — _fadeOffsetVolume 从未随每次 fade 刷新，导致音量不会朝目标收敛。
// 新实现：_as.volume = Mathf.MoveTowards(_as.volume, _fadeTargetVolume, _fadeDeltaVolume / _fadeSeconds * dt);
using NUnit.Framework;
using UnityEngine;
using System.Reflection;
using Fuel.Manager.AudioManager;

namespace Fuel.Tests
{
    [TestFixture]
    public class AudioSourceDataFadeTests
    {
        private GameObject _go;
        private AudioSource _as;
        private AudioManager.AudioSourceData _data;

        [SetUp]
        public void SetUp()
        {
            _go = new GameObject("test_audio");
            _as = _go.AddComponent<AudioSource>();
            _as.volume = 0f;
            _data = new AudioManager.AudioSourceData(_as, instanceID: 0);
        }

        [TearDown]
        public void TearDown()
        {
            if (_go != null) Object.DestroyImmediate(_go);
        }

        /// <summary>
        /// 把 AudioSourceData 的私有 State 字段置为 Playing（默认是 None 会让 TickFade 早退）
        /// </summary>
        private void SetStatePlaying()
        {
            var stateField = typeof(AudioManager.AudioSourceData)
                .GetField("State", BindingFlags.Public | BindingFlags.Instance);
            stateField!.SetValue(_data, AudioSourceState.Playing);
        }

        [Test]
        public void Fade_FadeIn_ReachesTarget_WithinTotalSeconds()
        {
            SetStatePlaying();
            _as.volume = 0f;

            // 从 0 → 1，1 秒内完成
            _data.SetVolume(volume: 1.0f, fadeTime: 1.0f);

            // 推 0.1 秒一次，累计推 1.0 秒
            const float dt = 0.1f;
            for (int i = 0; i < 10; i++) _data.Update(dt);

            // 应当精确收敛到 1.0（不允许超过 / 欠收敛）
            Assert.That(_as.volume, Is.EqualTo(1.0f).Within(0.001f),
                "fade in 1s should reach exactly 1.0 after 1s of accumulated dt");
        }

        [Test]
        public void Fade_FadeOut_ReachesZero_WithinTotalSeconds()
        {
            SetStatePlaying();
            _as.volume = 1.0f;

            _data.SetVolume(volume: 0.0f, fadeTime: 0.5f);

            const float dt = 0.05f;
            for (int i = 0; i < 10; i++) _data.Update(dt);

            Assert.That(_as.volume, Is.EqualTo(0.0f).Within(0.001f),
                "fade out 0.5s should reach exactly 0.0 after 0.5s of accumulated dt");
        }

        [Test]
        public void Fade_Midway_ApproximatesLinearProgression()
        {
            // 中点（0.5s / 1.0s）应约等于 0.5
            SetStatePlaying();
            _as.volume = 0f;
            _data.SetVolume(1.0f, 1.0f);
            for (int i = 0; i < 5; i++) _data.Update(0.1f);
            Assert.That(_as.volume, Is.InRange(0.4f, 0.6f),
                "midway should be ~0.5; old broken formula would diverge");
        }

        [Test]
        public void Fade_ZeroFadeTime_SnapsImmediately()
        {
            SetStatePlaying();
            _as.volume = 0.2f;
            _data.SetVolume(0.9f, 0f);
            Assert.That(_as.volume, Is.EqualTo(0.9f).Within(0.001f),
                "zero fade time should snap directly to target");
        }
    }
}
