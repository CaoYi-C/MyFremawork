#if UNITY_EDITOR
using Fuel.AssetManager;
#endif
using Cysharp.Threading.Tasks;
using Game.Visual;
using UnityEngine;
using YooAsset;

namespace Game.Character
{
    /// <summary>
    /// 角色启动器：实例化CharacterLoader预制件，加载动画控制器，绑定CharacterController2D
    /// </summary>
    public class CharacterLauncher : MonoBehaviour
    {
        [Header("Prefab")]
        public string PrefabName = "CharacterLoader";

        [Header("AnimController")]
        public string AnimControllerName = "AngryPig";

        [Header("Controller Settings")]
        public float MoveSpeed = 5f;
        public float JumpForce = 10f;
        public int MaxJumpCount = 2;
        public float WallSlideSpeed = 1.5f;
        public float WallJumpHorizontalForce = 6f;
        public float WallJumpVerticalForce = 10f;
        public float WallExitPush = 3f;
        public float WallClimbExitCooldown = 0.3f;

        private CharacterController2D _controller;

        private async void Start()
        {
#if UNITY_EDITOR
            await AssetsManager.Instance.EnsureYooAssetInitializedAsync("Main");
#endif
            var package = YooAssets.GetPackage("Main");

            // 加载预制件（只传名称，无需路径和扩展名）
            var prefabHandle = package.LoadAssetAsync<GameObject>(PrefabName);
            await prefabHandle.ToUniTask();
            if (prefabHandle.Status != EOperationStatus.Succeeded)
            {
                Debug.LogError($"Failed to load prefab: {PrefabName}");
                return;
            }

            var prefab = prefabHandle.AssetObject as GameObject;
            var instance = Instantiate(prefab);
            instance.name = "Character";
            BindFocusBrightnessEffect(instance.transform);

            // 把角色放到场景原点稍上方
            instance.transform.position = new Vector3(0, 2, 0);

            // 加载动画控制器（只传名称，无需路径和扩展名）
            var animHandle = package.LoadAssetAsync<RuntimeAnimatorController>(AnimControllerName);
            await animHandle.ToUniTask();

            RuntimeAnimatorController animCtrl = null;
            if (animHandle.Status == EOperationStatus.Succeeded)
            {
                animCtrl = animHandle.AssetObject as RuntimeAnimatorController;
            }
            else
            {
                Debug.LogWarning($"Failed to load anim controller: {AnimControllerName}, using prefab default");
            }

            // 创建纯C#控制器并绑定
            _controller = new CharacterController2D
            {
                MoveSpeed = MoveSpeed,
                JumpForce = JumpForce,
                MaxJumpCount = MaxJumpCount,
                WallSlideSpeed = WallSlideSpeed,
                WallJumpHorizontalForce = WallJumpHorizontalForce,
                WallJumpVerticalForce = WallJumpVerticalForce,
                WallExitPush = WallExitPush,
                WallClimbExitCooldown = WallClimbExitCooldown,
            };
            _controller.Bind(instance, animCtrl);
        }

        private void BindFocusBrightnessEffect(Transform character)
        {
            var mainCamera = Camera.main;
            if (mainCamera == null) return;

            var effect = mainCamera.GetComponent<CharacterFocusBrightnessEffect>();
            if (effect != null)
                effect.Target = character;
        }

        private void Update()
        {
            if (_controller == null || !_controller.IsBound) return;

            float h = Input.GetAxis("Horizontal");
            float v = Input.GetAxis("Vertical");
            _controller.Move(h, v);

            if (Input.GetButtonDown("Jump"))
                _controller.Jump();

            _controller.Update(Time.deltaTime);
        }

        private void FixedUpdate()
        {
            if (_controller == null || !_controller.IsBound) return;
            _controller.FixedUpdate(Time.fixedDeltaTime);
        }

        private void OnDestroy()
        {
            _controller?.Unbind();
            _controller = null;
        }
    }
}
