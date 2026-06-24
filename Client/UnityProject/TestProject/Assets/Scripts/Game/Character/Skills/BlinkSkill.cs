using UnityEngine;

namespace Game.Character.Skills
{
    /// <summary>
    /// 闪烁（Blink）技能。
    /// 从当前角色位置朝当前朝向瞬移一段距离，遇墙则瞬移到墙体前。
    /// </summary>
    public sealed class BlinkSkill : SkillBase
    {
        public override string Id => "Blink";
        public override string DisplayName => "闪烁";
        public override Color IconColor => new Color(0.3f, 0.6f, 1f);
        public override string HotkeyHint => "Q";

        // ── 可配置参数 ──

        /// <summary>瞬移最大距离（像素单位）</summary>
        public float BlinkDistance = 6f;

        /// <summary>碰撞检测胶囊/射线半径，用于防止穿墙</summary>
        public float SkinWidth = 0.05f;

        /// <summary>瞬移后施加的额外水平速度（0 = 不额外推力）</summary>
        public float PostBlinkMomentumX = 0f;

        // ── 内部状态 ──
        private static readonly RaycastHit2D[] _hitBuffer = new RaycastHit2D[8];

        protected override void OnInitialized()
        {
            // 可由外部覆盖冷却
            Cooldown = 2f;
        }

        protected override bool CanActivate()
        {
            // 已绑定即允许
            return Context.IsBound;
        }

        protected override void OnActivate()
        {
            var rb = Context.Rigidbody;
            var tf = Context.Transform;
            var col = Context.Collider;

            float dir = Context.FacingDirection; // 1 or -1
            Vector2 origin = rb.position;
            Vector2 dirVec = Vector2.right * dir;

            // 用 BoxCast / Raycast 探测前方最大可移动距离
            float maxDist = BlinkDistance;

            // 使用角色碰撞体宽度进行 BoxCast，避免穿过缝隙
            if (col != null)
            {
                Bounds bounds = col.bounds;
                Vector2 boxSize = new Vector2(
                    bounds.size.x * 0.5f,  // 窄一些，只检测正前方
                    bounds.size.y * 0.9f   // 高度略小于角色，避免边缘误触
                );
                Vector2 boxCenter = origin + new Vector2(0, bounds.extents.y * 0.5f);

                int count = Physics2D.BoxCastNonAlloc(
                    boxCenter, boxSize, 0f, dirVec, _hitBuffer, BlinkDistance + SkinWidth, Context.ObstacleMask
                );

                float closest = float.MaxValue;
                for (int i = 0; i < count; i++)
                {
                    var hit = _hitBuffer[i];
                    if (hit.collider == col) continue;
                    if (hit.collider.isTrigger) continue;
                    if (hit.distance <= 0f) continue;
                    if (hit.distance < closest) closest = hit.distance;
                }

                if (closest < maxDist)
                {
                    maxDist = Mathf.Max(0f, closest - SkinWidth);
                }
            }
            else
            {
                // 没有 Collider 时退化为简单 Raycast
                int count = Physics2D.RaycastNonAlloc(origin, dirVec, _hitBuffer, BlinkDistance, Context.ObstacleMask);
                float closest = float.MaxValue;
                for (int i = 0; i < count; i++)
                {
                    var hit = _hitBuffer[i];
                    if (hit.collider.isTrigger) continue;
                    if (hit.distance <= 0f) continue;
                    if (hit.distance < closest) closest = hit.distance;
                }
                if (closest < maxDist)
                {
                    maxDist = Mathf.Max(0f, closest - SkinWidth);
                }
            }

            if (maxDist < 0.01f) return; // 前方完全被墙挡住，不浪费冷却

            // 瞬移：直接设置位置，清空速度避免惯性干扰
            Vector2 dest = origin + dirVec * maxDist;
            rb.position = dest;
            rb.velocity = new Vector2(dir * PostBlinkMomentumX, 0f);
        }
    }
}