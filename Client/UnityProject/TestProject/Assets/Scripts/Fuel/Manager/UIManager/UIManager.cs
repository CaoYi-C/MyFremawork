using System;
using System.Collections.Generic;
using Fuel.Singleton;
using UnityEngine;
using UI = UnityEngine.UI;

namespace Fuel.Manager.UIManager
{
    public class UIManager : MonoSingleton<UIManager>
    {
        [SerializeField]
        private Camera _uiCamera;

        public Camera UICamera => _uiCamera;

        [SerializeField]
        private Vector2 _referenceResolution = new Vector2(1920, 1080);

        public Vector2 ReferenceResolution
        {
            get => _referenceResolution;
            set
            {
                _referenceResolution = value;
                UpdateCanvasScaler();
            }
        }

        private Dictionary<UILayer, Canvas> _layerCanvases = new Dictionary<UILayer, Canvas>();
        private Dictionary<UILayer, Transform> _layerRoots = new Dictionary<UILayer, Transform>();
        private Dictionary<UILayer, UI.CanvasScaler> _layerScalers = new Dictionary<UILayer, UI.CanvasScaler>();
        private UIStack _stack;
        private UIResourceManager _resourceManager;
        private Dictionary<string, Func<UIWindowData, UIWindow>> _windowFactory = new Dictionary<string, Func<UIWindowData, UIWindow>>();

        private int _maxStackCount = 10;

        public int MaxStackCount
        {
            get => _maxStackCount;
            set => _maxStackCount = Mathf.Max(1, value);
        }

        public UIStack Stack => _stack;
        public UIResourceManager ResourceManager => _resourceManager;

        public event Action<UIWindow> OnWindowShow;
        public event Action<UIWindow> OnWindowHide;

        private int _lastScreenWidth;
        private int _lastScreenHeight;

        protected override void OnInit()
        {
            base.OnInit();

            _resourceManager = new UIResourceManager();
            _stack = new UIStack(OnWindowPop, OnWindowClear);
            _lastScreenWidth = Screen.width;
            _lastScreenHeight = Screen.height;

            CreateUICamera();
            CreateLayerCanvases();

            Debug.Log("[UIManager] Initialized successfully");
        }

        private void OnEnable()
        {
            Canvas.preWillRenderCanvases += OnPreWillRenderCanvases;
        }

        private void OnDisable()
        {
            Canvas.preWillRenderCanvases -= OnPreWillRenderCanvases;
        }

        private void OnPreWillRenderCanvases()
        {
            if (Screen.width != _lastScreenWidth || Screen.height != _lastScreenHeight)
            {
                _lastScreenWidth = Screen.width;
                _lastScreenHeight = Screen.height;
                UpdateCanvasScaler();
            }
        }

        private void CreateUICamera()
        {
            if (_uiCamera != null) return;

            var cameraObj = new GameObject("UICamera");
            cameraObj.transform.SetParent(transform);
            cameraObj.transform.localPosition = Vector3.back * 1000;
            _uiCamera = cameraObj.AddComponent<Camera>();
            _uiCamera.clearFlags = CameraClearFlags.Depth;
            _uiCamera.cullingMask = ~0;
            _uiCamera.depth = -1;
            _uiCamera.orthographic = true;
            _uiCamera.orthographicSize = 1;
            _uiCamera.nearClipPlane = 1;
            _uiCamera.farClipPlane = 2000;
            _uiCamera.useOcclusionCulling = false;
        }

        // 预缓存 UILayer 枚举值，避免 Enum.GetValues 的装箱分配
        private static readonly UILayer[] _allLayers = (UILayer[])Enum.GetValues(typeof(UILayer));

        private void CreateLayerCanvases()
        {
            for (int i = 0; i < _allLayers.Length; i++)
            {
                UILayer layer = _allLayers[i];
                var layerObj = new GameObject(layer.ToString());
                layerObj.transform.SetParent(transform);

                var canvas = layerObj.AddComponent<Canvas>();
                canvas.renderMode = RenderMode.ScreenSpaceCamera;
                canvas.worldCamera = _uiCamera;
                canvas.planeDistance = 100;
                canvas.sortingLayerName = "UI";
                canvas.sortingOrder = (int)layer * 100;

                var scaler = layerObj.AddComponent<UI.CanvasScaler>();
                scaler.uiScaleMode = UI.CanvasScaler.ScaleMode.ScaleWithScreenSize;
                scaler.referenceResolution = _referenceResolution;
                scaler.screenMatchMode = UI.CanvasScaler.ScreenMatchMode.MatchWidthOrHeight;
                scaler.matchWidthOrHeight = Screen.width > Screen.height ? 0f : 1f;

                layerObj.AddComponent<UI.GraphicRaycaster>();

                var rect = layerObj.GetComponent<RectTransform>();
                rect.anchorMin = Vector2.zero;
                rect.anchorMax = Vector2.one;
                rect.sizeDelta = Vector2.zero;
                rect.localPosition = Vector3.zero;
                rect.localRotation = Quaternion.identity;
                rect.localScale = Vector3.one;

                _layerCanvases[layer] = canvas;
                _layerScalers[layer] = scaler;
                _layerRoots[layer] = layerObj.transform;
            }
        }

        private void UpdateCanvasScaler()
        {
            bool isLandscape = Screen.width > Screen.height;
            float matchValue = isLandscape ? 0f : 1f;

            foreach (var kvp in _layerScalers)
            {
                if (kvp.Value != null)
                {
                    kvp.Value.referenceResolution = _referenceResolution;
                    kvp.Value.matchWidthOrHeight = matchValue;
                }
            }
        }

        public void RegisterWindowFactory(string windowId, Func<UIWindowData, UIWindow> factory)
        {
            _windowFactory[windowId] = factory;
        }

        public void RegisterWindowPrefab(string windowId, string prefabPath)
        {
            _resourceManager.RegisterPrefabPath(windowId, prefabPath);
        }

        public void RegisterWindow(string windowId, string prefabPath, Func<UIWindowData, UIWindow> factory)
        {
            _windowFactory[windowId] = factory;
            _resourceManager.RegisterPrefabPath(windowId, prefabPath);
        }

        public T OpenWindow<T>(UIWindowData data = null) where T : UIWindow
        {
            string windowId = typeof(T).Name;
            return OpenWindow(windowId, data) as T;
        }

        public UIWindow OpenWindow(string windowId, UIWindowData data = null)
        {
            UIWindow window = _resourceManager.GetWindow(windowId);

            if (window == null)
            {
                if (!_windowFactory.TryGetValue(windowId, out var factory))
                {
                    Debug.LogError($"[UIManager] No factory registered for window: {windowId}");
                    return null;
                }

                window = factory(data);
                _resourceManager.RegisterWindow(windowId, window);

                var layerRoot = GetLayerRoot(window.LayerId);
                var viewObj = _resourceManager.CreateInstance(windowId, layerRoot);
                window.ViewObject = viewObj;
                if (viewObj != null)
                {
                    viewObj.SetActive(false);
                    window.OnAwake();
                }
            }

            if (_stack.Contains(windowId))
            {
                _stack.PushToWindow(windowId);
                var topWindow = _stack.TopWindow;
                if (topWindow != null)
                {
                    topWindow.OnShow(data);
                    OnWindowShow?.Invoke(topWindow);
                }
                return topWindow;
            }

            HandleStackOverflow();

            _stack.Push(window);
            window.OnShow(data);
            OnWindowShow?.Invoke(window);
            return window;
        }

        public void CloseWindow(string windowId)
        {
            int index = _stack.FindIndex(windowId);
            if (index < 0) return;

            _stack.PopToIndex(index); // pop everything above the target
            _stack.Pop();             // pop the target window itself
        }

        public void CloseTopWindow()
        {
            _stack.Pop();
        }

        private void HandleStackOverflow()
        {
            while (_stack.Count >= _maxStackCount)
            {
                _stack.PopBottom();
            }
        }

        private void OnWindowPop(UIWindow window)
        {
            window.OnHide();
            OnWindowHide?.Invoke(window);
        }

        private void OnWindowClear(UIWindow window)
        {
            window.OnRelease();
        }

        public Transform GetLayerRoot(UILayer layer)
        {
            return _layerRoots.TryGetValue(layer, out var root) ? root : null;
        }

        public Transform GetLayerRoot(int layerId)
        {
            return GetLayerRoot((UILayer)layerId);
        }

        public Canvas GetLayerCanvas(UILayer layer)
        {
            return _layerCanvases.TryGetValue(layer, out var canvas) ? canvas : null;
        }

        public UIWindow ReloadWindow(string windowId)
        {
            var window = _resourceManager.GetWindow(windowId);
            if (window == null) return null;

            // 记录 reload 前的显示状态。OnRelease 内部会把 IsShow 置为 false，
            // 但窗口对象本身仍留在 _stack 中（OnRelease 不负责出栈）。
            // 修 #29：reload 完成后如果原本是显示态，需要重新触发 OnShow 恢复运行时状态
            // （重注册事件、设 IsShow=true、激活 GameObject），否则窗口会处于"在栈里但 IsShow=false"的撕裂态。
            bool wasShown = window.IsShow;

            window.OnRelease();

            var layerRoot = GetLayerRoot(window.LayerId);
            var viewObj = _resourceManager.CreateInstance(windowId, layerRoot);
            if (viewObj == null)
            {
                Debug.LogError($"[UIManager] Reload window failed, create instance returned null: {windowId}");
                return null;
            }

            window.ViewObject = viewObj;
            window.OnReload();

            if (wasShown)
            {
                // 复用 OnShow 路径重新激活 + 注册事件 + 触发 OnShowEvent
                window.OnShow();
                OnWindowShow?.Invoke(window);
            }
            else
            {
                // 未显示态：保持隐藏
                if (viewObj != null) viewObj.SetActive(false);
            }

            return window;
        }
    }

    public static class UIStackExtensions
    {
        public static void PushToWindow(this UIStack stack, string windowId)
        {
            if (stack == null) return;
            int index = stack.FindIndex(windowId);
            if (index >= 0)
            {
                stack.PopToIndex(index);
            }
        }
    }
}
