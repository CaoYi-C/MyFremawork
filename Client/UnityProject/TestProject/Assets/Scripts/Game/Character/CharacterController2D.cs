using System;
using Game.Character.Skills;
using UnityEngine;

namespace Game.Character
{
    /// <summary>
    /// 纯C# 2D角色控制器，不依赖MonoBehaviour。
    /// 通过 Bind 绑定到角色GameObject，由外部驱动Update。
    /// 支持：左右移动、跳跃、爬墙/墙跳
    /// </summary>
    public class CharacterController2D
    {
        // ── 绑定引用 ──
        private Transform _transform;
        private Rigidbody2D _rigidbody;
        private Animator _animator;
        private CharacterCollision2D _collision;
        private SkillSystem _skillSystem;

        // ── 配置参数 ──
        public float MoveSpeed = 5f;
        public float MaxMoveSpeed = 8f;
        public float JumpForce = 10f;
        public float WallSlideSpeed = 1.5f;
        public float WallJumpHorizontalForce = 6f;
        public float WallJumpVerticalForce = 10f;
        public float WallClimbSpeed = 3f;
        public float WallExitPush = 3f;
        public int MaxJumpCount = 2;
        public float GroundDamping = 8f;
        public float AirDamping = 2f;
        public float FallGravityMultiplier = 2.5f;

        /// <summary>壁跳后短时间内禁止反向输入吸墙</summary>
        public float WallJumpCooldown = 0.25f;

        /// <summary>退出攀爬后禁止重新攀爬的冷却时间</summary>
        public float WallClimbExitCooldown = 0.3f;

        // ── Animator状态名称（可按项目实际动画状态配置）──
        public string AnimStateIdle = "Idle";
        public string AnimStateWalk = "Walk";
        public string AnimStateRun = "Run";
        public string AnimStateJump = "Idle";

        // ── 内部状态 ──
        private float _moveInput;
        private float _climbInput;
        private bool _jumpQueued;
        private int _jumpCount;
        private bool _isGrounded;
        private bool _isTouchingWall;
        private bool _isWallSliding;
        private bool _isWallClimbing;
        private bool _wallClimbJumped;
        private float _wallJumpTimer;
        private float _wallClimbExitTimer;
        private int _facingDirection = 1;

        public bool IsGrounded => _isGrounded;
        public bool IsTouchingWall => _isTouchingWall;
        public bool IsWallSliding => _isWallSliding;
        public bool IsWallClimbing => _isWallClimbing;
        public int JumpCount => _jumpCount;
        public int FacingDirection => _facingDirection;
        public SkillSystem Skills => _skillSystem;
        public bool IsBound => _transform != null;

        /// <summary>
        /// 绑定到指定的GameObject。会自动获取/添加Rigidbody2D、CharacterCollision2D、Animator。
        /// </summary>
        /// <param name="target">角色GameObject实例</param>
        /// <param name="animController">AnimatorController资源（可由调用方通过YooAsset/Resources加载传入），为null则不修改已有Controller</param>
        public void Bind(GameObject target, RuntimeAnimatorController animController = null)
        {
            if (target == null) throw new ArgumentNullException(nameof(target));

            Unbind();

            _transform = target.transform;
            _rigidbody = target.GetComponent<Rigidbody2D>();
            if (_rigidbody == null)
            {
                _rigidbody = target.AddComponent<Rigidbody2D>();
                _rigidbody.gravityScale = 3f;
                _rigidbody.constraints = RigidbodyConstraints2D.FreezeRotation;
            }

            _collision = target.GetComponent<CharacterCollision2D>();
            if (_collision != null)
            {
                _collision.OnGroundedChanged += HandleGroundedChanged;
                _collision.OnWallContactChanged += HandleWallContactChanged;
                // Sync initial state (events may have fired before subscription)
                HandleGroundedChanged(_collision.IsGrounded);
                HandleWallContactChanged(_collision.IsTouchingWall);
            }

            // 查找Visual子节点上的Animator
            Transform visual = target.transform.Find("Visual");
            if (visual != null)
            {
                _animator = visual.GetComponent<Animator>();
            }

            if (_animator == null)
            {
                _animator = target.GetComponentInChildren<Animator>();
            }

            // 动态设置AnimatorController
            if (_animator != null && animController != null)
            {
                _animator.runtimeAnimatorController = animController;
            }

            // 初始化技能系统
            _skillSystem = _skillSystem ?? new SkillSystem();
            var ctx = new SkillContext
            {
                Transform = _transform,
                Rigidbody = _rigidbody,
                Collider = target.GetComponent<Collider2D>(),
                Collision = _collision,
                Controller = this,
            };
            _skillSystem.Bind(ctx);

            _facingDirection = 1;
        }

        public void Unbind()
        {
            if (_collision != null)
            {
                _collision.OnGroundedChanged -= HandleGroundedChanged;
                _collision.OnWallContactChanged -= HandleWallContactChanged;
            }

            _skillSystem?.Unbind();

            _transform = null;
            _rigidbody = null;
            _animator = null;
            _collision = null;
        }

        /// <summary>设置移动输入。horizontal: 正=右负=左，vertical: 正=上下=下（爬墙时使用）</summary>
        public void Move(float horizontal, float vertical = 0f)
        {
            _moveInput = Mathf.Clamp(horizontal, -1f, 1f);
            _climbInput = Mathf.Clamp(vertical, -1f, 1f);
        }

        /// <summary>请求跳跃（会被下一帧FixedUpdate消费）</summary>
        public void Jump()
        {
            _jumpQueued = true;
        }

        /// <summary>
        /// 每帧由外部调用（通常在MonoBehaviour.Update中）
        /// </summary>
        public void Update(float deltaTime)
        {
            if (!IsBound) return;

            UpdateFacing();
            UpdateAnimator();
        }

        /// <summary>
        /// 每FixedUpdate由外部调用（通常在MonoBehaviour.FixedUpdate中）
        /// </summary>
        public void FixedUpdate(float deltaTime)
        {
            if (!IsBound) return;

            _wallJumpTimer -= deltaTime;
            _wallClimbExitTimer -= deltaTime;

            ApplyHorizontalMovement(deltaTime);
            ApplyWallClimb();
            ApplyWallSlide();
            ApplyJump();
            ApplyGravity();

            // 技能系统 Tick（冷却递减）
            _skillSystem?.Tick(deltaTime);
        }

        // ── 内部逻辑 ──

        private void ApplyHorizontalMovement(float deltaTime)
        {
            if (_isWallSliding && _wallJumpTimer > 0f) return;

            float targetSpeed = _moveInput * MoveSpeed;
            float damping = _isGrounded ? GroundDamping : AirDamping;
            float newX = Mathf.MoveTowards(_rigidbody.velocity.x, targetSpeed, damping * deltaTime * MoveSpeed);

            // 限速
            newX = Mathf.Clamp(newX, -MaxMoveSpeed, MaxMoveSpeed);
            _rigidbody.velocity = new Vector2(newX, _rigidbody.velocity.y);
        }

        private void ApplyWallClimb()
        {
            if (_wallClimbExitTimer > 0f)
            {
                _isWallClimbing = false;
                return;
            }

            bool canClimb = _isTouchingWall && !_isGrounded
                            && Mathf.Abs(_climbInput) > 0.01f;

            bool wasClimbing = _isWallClimbing;

            if (canClimb && _wallJumpTimer <= 0f)
            {
                _isWallClimbing = true;
                _isWallSliding = false;
                _rigidbody.velocity = new Vector2(_rigidbody.velocity.x, _climbInput * WallClimbSpeed);
            }
            else
            {
                _isWallClimbing = false;
            }

            if (wasClimbing && !_isWallClimbing)
            {
                _wallClimbExitTimer = WallClimbExitCooldown;
                float pushDir = _facingDirection;
                _rigidbody.velocity = new Vector2(pushDir * WallExitPush, _rigidbody.velocity.y);
            }
        }

        private void ApplyWallSlide()
        {
            if (_isWallClimbing) return;
            if (_wallClimbExitTimer > 0f) return;

            bool canWallSlide = _isTouchingWall && !_isGrounded && _moveInput != 0
                                && Mathf.Sign(_moveInput) == _facingDirection;

            if (canWallSlide && _wallJumpTimer <= 0f)
            {
                _isWallSliding = true;
                float vy = _rigidbody.velocity.y;
                vy = Mathf.Max(vy, -WallSlideSpeed);
                _rigidbody.velocity = new Vector2(_rigidbody.velocity.x, vy);
            }
            else
            {
                _isWallSliding = false;
            }
        }

        private void ApplyJump()
        {
            if (!_jumpQueued) return;
            _jumpQueued = false;

            if (_isGrounded)
            {
                _jumpCount = 1;
                _rigidbody.velocity = new Vector2(_rigidbody.velocity.x, JumpForce);
            }
            else if (_isWallClimbing && !_wallClimbJumped)
            {
                _wallClimbJumped = true;
                _isWallClimbing = false;
                _jumpCount = MaxJumpCount;
                _wallJumpTimer = WallJumpCooldown;
                float jumpDirX = _moveInput * WallJumpHorizontalForce;
                _rigidbody.velocity = new Vector2(jumpDirX, WallJumpVerticalForce);

                if (jumpDirX > 0.01f && _facingDirection != 1)
                {
                    _facingDirection = 1;
                    _transform.localScale = new Vector3(1, 1, 1);
                }
                else if (jumpDirX < -0.01f && _facingDirection != -1)
                {
                    _facingDirection = -1;
                    _transform.localScale = new Vector3(-1, 1, 1);
                }
            }
            else if (_isWallSliding)
            {
                _wallJumpTimer = WallJumpCooldown;
                _isWallSliding = false;
                _jumpCount = 1;
                float jumpDirX = -_facingDirection * WallJumpHorizontalForce;
                _rigidbody.velocity = new Vector2(jumpDirX, WallJumpVerticalForce);
                Flip();
            }
            else if (_jumpCount < MaxJumpCount)
            {
                _jumpCount++;
                _rigidbody.velocity = new Vector2(_rigidbody.velocity.x, JumpForce);
            }
        }

        private void ApplyGravity()
        {
            if (_isWallClimbing) return;

            if (_rigidbody.velocity.y < 0 && !_isWallSliding)
            {
                float extraGravity = Physics2D.gravity.y * (FallGravityMultiplier - 1f);
                _rigidbody.velocity += new Vector2(0f, extraGravity * Time.fixedDeltaTime);
            }
        }

        private void UpdateFacing()
        {
            if (_isWallSliding || _isWallClimbing) return;
            if (_wallJumpTimer > 0f) return;

            if (_moveInput > 0.01f && _facingDirection != 1)
            {
                _facingDirection = 1;
                _transform.localScale = new Vector3(1, 1, 1);
            }
            else if (_moveInput < -0.01f && _facingDirection != -1)
            {
                _facingDirection = -1;
                _transform.localScale = new Vector3(-1, 1, 1);
            }
        }

        private void Flip()
        {
            _facingDirection = -_facingDirection;
            _transform.localScale = new Vector3(_facingDirection, 1, 1);
        }

        private void UpdateAnimator()
        {
            if (_animator == null) return;

            string targetState;
            if (!_isGrounded && _isWallClimbing)
                targetState = AnimStateRun;
            else if (!_isGrounded && (_isWallSliding || _isTouchingWall))
                targetState = AnimStateIdle;
            else if (!_isGrounded)
                targetState = AnimStateJump;
            else if (Mathf.Abs(_moveInput) > 0.01f)
                targetState = AnimStateWalk;
            else
                targetState = AnimStateIdle;

            var currentState = _animator.GetCurrentAnimatorStateInfo(0);
            if (!currentState.IsName(targetState))
                _animator.Play(targetState);
        }

        // ── 事件回调 ──

        private void HandleGroundedChanged(bool grounded)
        {
            _isGrounded = grounded;
            if (grounded)
            {
                _isWallSliding = false;
                _wallClimbJumped = false;
                _jumpCount = 0;
                _wallJumpTimer = 0f;
            }
        }

        private void HandleWallContactChanged(bool touchingWall)
        {
            _isTouchingWall = touchingWall;
            if (!touchingWall)
            {
                _isWallSliding = false;
                _isWallClimbing = false;
                _wallClimbJumped = false;
            }
        }
    }
}
