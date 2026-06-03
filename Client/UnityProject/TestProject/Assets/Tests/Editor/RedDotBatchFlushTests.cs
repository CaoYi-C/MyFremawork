// RedDotTree.LocalSave 攒批落盘的烟测。
// 旧实现：每次 LocalSave 都 PlayerPrefs.Save() 同步刷盘，频繁调用会卡帧。
// 新实现：SetString 立即生效（语义不变），但 Save 攒批 ——
//         达到 PendingRedDotFlushThreshold 次或调用 FlushPendingSaves() 才统一落盘。
using NUnit.Framework;
using UnityEngine;
using Fuel.RedDot.RunTime;

namespace Fuel.Tests
{
    [TestFixture]
    public class RedDotBatchFlushTests
    {
        private const string TestKey = "__FuelTests_RedDot_Sample";
        private const string OtherKey = "__FuelTests_RedDot_Other";

        [SetUp]
        public void SetUp()
        {
            // 清掉残留
            if (PlayerPrefs.HasKey(TestKey)) PlayerPrefs.DeleteKey(TestKey);
            if (PlayerPrefs.HasKey(OtherKey)) PlayerPrefs.DeleteKey(OtherKey);
            RedDotTree.FlushPendingSaves();
        }

        [TearDown]
        public void TearDown()
        {
            if (PlayerPrefs.HasKey(TestKey)) PlayerPrefs.DeleteKey(TestKey);
            if (PlayerPrefs.HasKey(OtherKey)) PlayerPrefs.DeleteKey(OtherKey);
            RedDotTree.FlushPendingSaves();
        }

        [Test]
        public void LocalSave_StoresValue_AndFlushPersists()
        {
            RedDotTree.LocalSave(bindRole: false, TestKey, "v1");
            // SetString 是同步生效的；不调 flush 也能读到
            Assert.That(PlayerPrefs.GetString(TestKey), Is.EqualTo("v1"));

            // 显式 flush 后仍然能读到
            RedDotTree.FlushPendingSaves();
            Assert.That(PlayerPrefs.GetString(TestKey), Is.EqualTo("v1"));
        }

        [Test]
        public void LocalSave_Overwrite_LatestWins()
        {
            RedDotTree.LocalSave(false, TestKey, "v1");
            RedDotTree.LocalSave(false, TestKey, "v2");
            RedDotTree.LocalSave(false, TestKey, "v3");
            RedDotTree.FlushPendingSaves();
            Assert.That(PlayerPrefs.GetString(TestKey), Is.EqualTo("v3"),
                "last write should win after flush");
        }

        [Test]
        public void FlushPendingSaves_IsIdempotent_WhenNoPending()
        {
            // 第一次 flush 清除标记
            RedDotTree.FlushPendingSaves();
            Assert.That(RedDotTree.HasPendingSaves, Is.False,
                "after flush, no pending writes should remain");

            // 二次 flush 仍然是 no-op，不抛
            Assert.DoesNotThrow(() => RedDotTree.FlushPendingSaves());
        }

        [Test]
        public void RemoveLocalSave_DeletesKey_AndFlushPersists()
        {
            RedDotTree.LocalSave(false, TestKey, "v1");
            RedDotTree.FlushPendingSaves();
            Assert.That(PlayerPrefs.HasKey(TestKey), Is.True);

            RedDotTree.RemoveLocalSave(false, TestKey);
            RedDotTree.FlushPendingSaves();
            Assert.That(PlayerPrefs.HasKey(TestKey), Is.False,
                "after remove + flush, key should be gone");
        }

        [Test]
        public void BindRole_PrefixesKeyWithUniqueKey()
        {
            // Save+set+restore UniqueKey，避免污染其他测试
            var orig = RedDotTree.UniqueKey;
            try
            {
                RedDotTree.UniqueKey = "role123:";
                RedDotTree.LocalSave(bindRole: true, TestKey, "bound");
                Assert.That(PlayerPrefs.GetString("role123:" + TestKey), Is.EqualTo("bound"),
                    "bindRole should prefix with UniqueKey");
            }
            finally
            {
                RedDotTree.UniqueKey = orig;
                if (PlayerPrefs.HasKey("role123:" + TestKey)) PlayerPrefs.DeleteKey("role123:" + TestKey);
            }
        }
    }
}
