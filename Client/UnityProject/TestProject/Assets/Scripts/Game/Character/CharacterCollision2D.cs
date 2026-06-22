using System;
using UnityEngine;

namespace Game.Character
{
    /// <summary>
    /// 挂载在角色预制件上的碰撞检测组件，通过事件向外抛出碰撞状态变化
    /// </summary>
    [RequireComponent(typeof(Rigidbody2D), typeof(Collider2D))]
    public class CharacterCollision2D : MonoBehaviour
    {
        [Header("Ground Check")]
        [SerializeField] private LayerMask _groundLayer = ~0;
        [SerializeField] private float _groundCheckDistance = 0.1f;
        [SerializeField] private float _groundCheckWidth = 0.8f;

        [Header("Wall Check")]
        [SerializeField] private float _wallCheckDistance = 0.15f;
        [SerializeField] private float _wallCheckHeightOffset = 0f;

        [Header("Ceiling Check")]
        [SerializeField] private float _ceilingCheckDistance = 0.1f;
        [SerializeField] private float _ceilingCheckWidth = 0.8f;

        private Rigidbody2D _rigidbody;
        private Collider2D _collider;
        private int _groundContactCount;
        private int _wallContactCount;
        private int _ceilingContactCount;

        private bool _isGrounded;
        private bool _isTouchingWall;
        private bool _isTouchingCeiling;

        public bool IsGrounded => _isGrounded;
        public bool IsTouchingWall => _isTouchingWall;
        public bool IsTouchingCeiling => _isTouchingCeiling;
        public int FacingDirection => transform.localScale.x > 0 ? 1 : -1;

        public event Action<bool> OnGroundedChanged;
        public event Action<bool> OnWallContactChanged;
        public event Action<bool> OnCeilingContactChanged;
        public event Action<Collision2D> OnCollisionEnter;
        public event Action<Collision2D> OnCollisionStay;
        public event Action<Collision2D> OnCollisionExit;
        public event Action<Collider2D> OnTriggerEnter;
        public event Action<Collider2D> OnTriggerStay;
        public event Action<Collider2D> OnTriggerExit;

        private void Awake()
        {
            _rigidbody = GetComponent<Rigidbody2D>();
            _collider = GetComponent<Collider2D>();
        }

        private void FixedUpdate()
        {
            DetectGround();
            DetectWall();
            DetectCeiling();
        }

        private void DetectGround()
        {
            Bounds bounds = _collider.bounds;
            Vector2 size = new Vector2(bounds.size.x * _groundCheckWidth, _groundCheckDistance);
            Vector2 origin = new Vector2(bounds.center.x, bounds.min.y + _groundCheckDistance);
            RaycastHit2D[] hits = Physics2D.BoxCastAll(origin, size, 0f, Vector2.down, _groundCheckDistance * 2f, _groundLayer);

            bool grounded = false;
            foreach (var hit in hits)
            {
                if (hit.collider == _collider) continue;
                if (hit.distance <= 0f) continue;
                grounded = true;
                break;
            }
            SetGrounded(grounded);
        }

        private void DetectWall()
        {
            Bounds bounds = _collider.bounds;
            float direction = FacingDirection;
            Vector2 size = new Vector2(_wallCheckDistance, bounds.size.y * 0.8f);
            Vector2 origin = new Vector2(
                bounds.center.x,
                bounds.center.y + _wallCheckHeightOffset);
            RaycastHit2D[] hits = Physics2D.BoxCastAll(origin, size, 0f, Vector2.right * direction, bounds.extents.x + _wallCheckDistance, _groundLayer);

            bool touchingWall = false;
            foreach (var hit in hits)
            {
                if (hit.collider == _collider) continue;
                if (hit.collider.isTrigger) continue;
                if (hit.distance <= 0f) continue;
                touchingWall = true;
                break;
            }
            SetWallContact(touchingWall);
        }

        private void DetectCeiling()
        {
            Bounds bounds = _collider.bounds;
            Vector2 size = new Vector2(bounds.size.x * _ceilingCheckWidth, _ceilingCheckDistance);
            Vector2 center = new Vector2(bounds.center.x, bounds.max.y + _ceilingCheckDistance * 0.5f);
            Collider2D[] hits = Physics2D.OverlapBoxAll(center, size, 0f, _groundLayer);

            bool touchingCeiling = false;
            foreach (var col in hits)
            {
                if (col == _collider) continue;
                touchingCeiling = true;
                break;
            }
            SetCeilingContact(touchingCeiling);
        }

        private void SetGrounded(bool grounded)
        {
            if (_isGrounded == grounded) return;
            _isGrounded = grounded;
            OnGroundedChanged?.Invoke(grounded);
        }

        private void SetWallContact(bool touchingWall)
        {
            if (_isTouchingWall == touchingWall) return;
            _isTouchingWall = touchingWall;
            OnWallContactChanged?.Invoke(touchingWall);
        }

        private void SetCeilingContact(bool touchingCeiling)
        {
            if (_isTouchingCeiling == touchingCeiling) return;
            _isTouchingCeiling = touchingCeiling;
            OnCeilingContactChanged?.Invoke(touchingCeiling);
        }

        private void OnCollisionEnter2D(Collision2D collision)
        {
            OnCollisionEnter?.Invoke(collision);
        }

        private void OnCollisionStay2D(Collision2D collision)
        {
            OnCollisionStay?.Invoke(collision);
        }

        private void OnCollisionExit2D(Collision2D collision)
        {
            OnCollisionExit?.Invoke(collision);
        }

        private void OnTriggerEnter2D(Collider2D other)
        {
            OnTriggerEnter?.Invoke(other);
        }

        private void OnTriggerStay2D(Collider2D other)
        {
            OnTriggerStay?.Invoke(other);
        }

        private void OnTriggerExit2D(Collider2D other)
        {
            OnTriggerExit?.Invoke(other);
        }
    }
}
