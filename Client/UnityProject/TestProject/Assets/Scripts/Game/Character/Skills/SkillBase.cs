using UnityEngine;

namespace Game.Character.Skills
{
    /// <summary>
    /// 技能抽象基类。提供：
    /// - 冷却管理（冷却时长、剩余时间、IsReady）
    /// - Tick 调度（由 SkillSystem 驱动）
    /// - 激活钩子（OnActivate 子类重写）
    /// 子类实现具体效果，无需关心冷却计时。
    /// </summary>
    public abstract class SkillBase : ISkill
    {
        public abstract string Id { get; }
        public virtual string DisplayName => Id;
        public virtual Color IconColor => new Color(0.4f, 0.7f, 1f);
        public virtual string HotkeyHint => string.Empty;

        protected SkillContext Context { get; private set; }
        public bool IsReady => _cooldownRemaining <= 0f;
        public float CooldownRemaining => Mathf.Max(0f, _cooldownRemaining);
        public virtual float CooldownDuration => _cooldown;

        private float _cooldown = 1f;
        private float _cooldownRemaining;

        /// <summary>冷却时长（秒）。子类或外部配置可改写。</summary>
        public float Cooldown
        {
            get => _cooldown;
            set => _cooldown = Mathf.Max(0f, value);
        }

        public void Initialize(SkillContext context)
        {
            Context = context;
            OnInitialized();
        }

        /// <summary>子类可选重写：初始化时的钩子</summary>
        protected virtual void OnInitialized() { }

        public bool TryActivate()
        {
            if (Context == null || !Context.IsBound) return false;
            if (!IsReady) return false;

            if (!CanActivate()) return false;

            OnActivate();
            _cooldownRemaining = _cooldown;
            return true;
        }

        public void Tick(float fixedDeltaTime)
        {
            if (_cooldownRemaining > 0f)
            {
                _cooldownRemaining = Mathf.Max(0f, _cooldownRemaining - fixedDeltaTime);
            }
            OnTick(fixedDeltaTime);
        }

        /// <summary>子类可选重写：额外激活条件（如需要 HP 大于 0）</summary>
        protected virtual bool CanActivate() => true;

        /// <summary>子类必须实现：技能触发时的实际效果</summary>
        protected abstract void OnActivate();

        /// <summary>子类可选重写：每帧 Tick 逻辑</summary>
        protected virtual void OnTick(float fixedDeltaTime) { }
    }
}