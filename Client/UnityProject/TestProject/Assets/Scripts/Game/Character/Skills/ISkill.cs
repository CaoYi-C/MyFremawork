namespace Game.Character.Skills
{
    /// <summary>
    /// 技能接口。所有可插拔技能必须实现该接口。
    /// 推荐继承 <see cref="SkillBase"/> 以获得冷却 / Tick 等通用能力。
    /// </summary>
    public interface ISkill
    {
        /// <summary>技能唯一 ID（用于外部触发与查询）</summary>
        string Id { get; }

        /// <summary>技能显示名（用于 UI）</summary>
        string DisplayName { get; }

        /// <summary>图标颜色（用于 UI 占位色）</summary>
        UnityEngine.Color IconColor { get; }

        /// <summary>绑定的快捷键提示（仅用于 UI 显示，可为空）</summary>
        string HotkeyHint { get; }

        /// <summary>是否当前可用（冷却结束 + 条件满足）</summary>
        bool IsReady { get; }

        /// <summary>当前冷却剩余时间（秒）</summary>
        float CooldownRemaining { get; }

        /// <summary>最大冷却时间（秒）。用于 UI 计算进度。</summary>
        float CooldownDuration { get; }

        /// <summary>注入运行时上下文，由 SkillSystem 在注册时调用</summary>
        void Initialize(SkillContext context);

        /// <summary>尝试激活技能。返回 true 表示成功触发。</summary>
        bool TryActivate();

        /// <summary>每帧更新（FixedUpdate 频率）</summary>
        void Tick(float fixedDeltaTime);
    }
}