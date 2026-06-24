using UnityEngine;

namespace Game.Character.Skills
{
    /// <summary>
    /// 技能运行时上下文。
    /// 由 CharacterController2D 在 Bind 时创建并注入到 SkillSystem / 每个 Skill，
    /// 技能通过它访问角色状态、变换、物理、世界信息等。
    /// </summary>
    public sealed class SkillContext
    {
        public Transform Transform;
        public Rigidbody2D Rigidbody;
        public Collider2D Collider;
        public CharacterCollision2D Collision;
        public CharacterController2D Controller;
        public LayerMask ObstacleMask = ~0;

        /// <summary>当前水平朝向：1=右，-1=左</summary>
        public int FacingDirection => Controller != null ? Controller.FacingDirection : 1;

        public bool IsBound => Transform != null && Rigidbody != null;
    }
}