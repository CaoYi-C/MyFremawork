using System.Collections.Generic;
using Game.Character.Skills;
using UnityEngine;
using UnityEngine.UI;

namespace Game.Character.Skills
{
    /// <summary>
    /// 程序化技能栏 HUD，无需 Prefab，挂在任意 GameObject 上即可。
    /// 自动为 SkillSystem 中每个已注册技能生成图标、冷却遮罩和快捷键提示。
    /// </summary>
    public sealed class SkillHUD : MonoBehaviour
    {
        // ── 配置（可在 Inspector 调整）──
        [SerializeField] private float _slotSize = 72f;
        [SerializeField] private float _slotSpacing = 10f;
        [SerializeField] private Vector2 _screenOffset = new Vector2(0, 30f); // 距底部偏移
        [SerializeField] private Color _slotBackground = new Color(0.15f, 0.15f, 0.15f, 0.8f);
        [SerializeField] private Color _cooldownOverlayColor = new Color(0, 0, 0, 0.6f);

        private SkillSystem _system;
        private Canvas _canvas;
        private readonly Dictionary<string, SlotUI> _slots = new Dictionary<string, SlotUI>();

        /// <summary>初始化 HUD，传入角色的 SkillSystem</summary>
        public void Initialize(SkillSystem system)
        {
            _system = system;
            BuildCanvas();
            RebuildSlots();
            _system.OnSkillChanged += OnSkillChanged;
        }

        private void OnDestroy()
        {
            if (_system != null) _system.OnSkillChanged -= OnSkillChanged;
        }

        private void BuildCanvas()
        {
            var canvasGo = new GameObject("SkillHUD_Canvas");
            canvasGo.transform.SetParent(transform, false);
            _canvas = canvasGo.AddComponent<Canvas>();
            _canvas.renderMode = RenderMode.ScreenSpaceOverlay;
            _canvas.sortingOrder = 999;

            var scaler = canvasGo.AddComponent<CanvasScaler>();
            scaler.uiScaleMode = CanvasScaler.ScaleMode.ScaleWithScreenSize;
            scaler.referenceResolution = new Vector2(1920, 1080);
            scaler.screenMatchMode = CanvasScaler.ScreenMatchMode.MatchWidthOrHeight;
            scaler.matchWidthOrHeight = 0.5f;

            canvasGo.AddComponent<GraphicRaycaster>();
        }

        private void RebuildSlots()
        {
            // 清理旧的
            foreach (var kv in _slots)
            {
                if (kv.Value.Root != null) Destroy(kv.Value.Root);
            }
            _slots.Clear();

            // 创建水平布局容器（居中底部）
            var containerGo = new GameObject("SkillBar");
            containerGo.transform.SetParent(_canvas.transform, false);
            var containerRect = containerGo.AddComponent<RectTransform>();
            containerRect.anchorMin = new Vector2(0.5f, 0f);
            containerRect.anchorMax = new Vector2(0.5f, 0f);
            containerRect.pivot = new Vector2(0.5f, 0f);
            containerRect.anchoredPosition = _screenOffset;

            var hlg = containerGo.AddComponent<HorizontalLayoutGroup>();
            hlg.spacing = _slotSpacing;
            hlg.childAlignment = TextAnchor.MiddleCenter;
            hlg.childForceExpandWidth = false;
            hlg.childForceExpandHeight = false;
            hlg.childControlWidth = false;
            hlg.childControlHeight = false;

            // 为每个已注册技能创建 slot
            foreach (var skill in _system.Skills)
            {
                var slot = CreateSlot(containerGo.transform, skill);
                _slots[skill.Id] = slot;
            }

            // 根据技能数量动态调整容器宽度
            int count = Mathf.Max(1, _slots.Count);
            float totalWidth = count * _slotSize + Mathf.Max(0, count - 1) * _slotSpacing;
            containerRect.sizeDelta = new Vector2(totalWidth, _slotSize);

            // 初始刷新一次冷却显示
            RefreshAll();
        }

        private SlotUI CreateSlot(Transform parent, ISkill skill)
        {
            var slot = new SlotUI();

            // ── 根节点（背景底框）──
            var root = new GameObject($"Slot_{skill.Id}");
            root.transform.SetParent(parent, false);
            slot.Root = root;

            var rootRect = root.AddComponent<RectTransform>();
            rootRect.sizeDelta = new Vector2(_slotSize, _slotSize);

            var bgImage = root.AddComponent<Image>();
            bgImage.color = _slotBackground;

            // ── 技能图标（居中，比底框略小）──
            var iconGo = new GameObject("Icon");
            iconGo.transform.SetParent(root.transform, false);
            var iconRect = iconGo.AddComponent<RectTransform>();
            iconRect.anchorMin = Vector2.zero;
            iconRect.anchorMax = Vector2.one;
            iconRect.offsetMin = new Vector2(4, 4);
            iconRect.offsetMax = new Vector2(-4, -4);
            var iconImage = iconGo.AddComponent<Image>();
            iconImage.color = skill.IconColor;
            slot.Icon = iconImage;

            // ── 冷却遮罩（从下往上填充，覆盖整个 slot）──
            var cdGo = new GameObject("CooldownOverlay");
            cdGo.transform.SetParent(root.transform, false);
            var cdRect = cdGo.AddComponent<RectTransform>();
            cdRect.anchorMin = Vector2.zero;
            cdRect.anchorMax = Vector2.one;
            cdRect.offsetMin = Vector2.zero;
            cdRect.offsetMax = Vector2.zero;
            var cdImage = cdGo.AddComponent<Image>();
            cdImage.color = _cooldownOverlayColor;
            cdImage.type = Image.Type.Filled;
            cdImage.fillMethod = Image.FillMethod.Vertical;
            cdImage.fillOrigin = (int)Image.Origin360.Bottom;
            cdImage.fillAmount = 0f; // 0 = 无遮罩 = 可用
            slot.CooldownOverlay = cdImage;

            // ── 冷却倒计时文字 ──
            var cdTextGo = new GameObject("CooldownText");
            cdTextGo.transform.SetParent(root.transform, false);
            var cdTextRect = cdTextGo.AddComponent<RectTransform>();
            cdTextRect.anchorMin = Vector2.zero;
            cdTextRect.anchorMax = Vector2.one;
            cdTextRect.offsetMin = Vector2.zero;
            cdTextRect.offsetMax = Vector2.zero;
            var cdText = cdTextGo.AddComponent<Text>();
            cdText.font = Resources.GetBuiltinResource<Font>("LegacyRuntime.ttf");
            cdText.alignment = TextAnchor.MiddleCenter;
            cdText.fontSize = 22;
            cdText.fontStyle = FontStyle.Bold;
            cdText.color = Color.white;
            cdText.supportRichText = false;
            cdText.text = "";
            slot.CooldownText = cdText;

            // ── 快捷键提示（右下角小字）──
            if (!string.IsNullOrEmpty(skill.HotkeyHint))
            {
                var hintGo = new GameObject("HotkeyHint");
                hintGo.transform.SetParent(root.transform, false);
                var hintRect = hintGo.AddComponent<RectTransform>();
                hintRect.anchorMin = new Vector2(1, 0);
                hintRect.anchorMax = new Vector2(1, 0);
                hintRect.pivot = new Vector2(1, 0);
                hintRect.anchoredPosition = new Vector2(-4, 2);
                hintRect.sizeDelta = new Vector2(30, 20);
                var hintText = hintGo.AddComponent<Text>();
                hintText.font = Resources.GetBuiltinResource<Font>("LegacyRuntime.ttf");
                hintText.alignment = TextAnchor.LowerRight;
                hintText.fontSize = 16;
                hintText.fontStyle = FontStyle.Bold;
                hintText.color = new Color(1, 1, 1, 0.7f);
                hintText.text = skill.HotkeyHint;
            }

            // ── 点击按钮（透明覆盖层）──
            var btnGo = new GameObject("ClickArea");
            btnGo.transform.SetParent(root.transform, false);
            var btnRect = btnGo.AddComponent<RectTransform>();
            btnRect.anchorMin = Vector2.zero;
            btnRect.anchorMax = Vector2.one;
            btnRect.offsetMin = Vector2.zero;
            btnRect.offsetMax = Vector2.zero;
            var btnImage = btnGo.AddComponent<Image>();
            btnImage.color = Color.clear;
            var btn = btnGo.AddComponent<Button>();
            btn.targetGraphic = btnImage;
            var capturedId = skill.Id;
            btn.onClick.AddListener(() => OnSlotClicked(capturedId));
            slot.Button = btn;

            return slot;
        }

        private void OnSlotClicked(string skillId)
        {
            _system?.TryActivate(skillId);
        }

        private void OnSkillChanged(ISkill skill)
        {
            if (_slots.TryGetValue(skill.Id, out var slot))
            {
                RefreshSlot(slot, skill);
            }
        }

        private void RefreshAll()
        {
            foreach (var skill in _system.Skills)
            {
                if (_slots.TryGetValue(skill.Id, out var slot))
                {
                    RefreshSlot(slot, skill);
                }
            }
        }

        private void RefreshSlot(SlotUI slot, ISkill skill)
        {
            if (slot.CooldownOverlay != null)
            {
                // fillAmount: 0=可用, 1=完全冷却中
                float ratio = skill.CooldownDuration > 0f
                    ? Mathf.Clamp01(skill.CooldownRemaining / skill.CooldownDuration)
                    : 0f;
                slot.CooldownOverlay.fillAmount = ratio;
            }

            if (slot.CooldownText != null)
            {
                slot.CooldownText.text = skill.CooldownRemaining > 0.1f
                    ? Mathf.CeilToInt(skill.CooldownRemaining).ToString()
                    : "";
            }
        }

        // 每帧刷新冷却文字（因为 FixedUpdate 频率可能不够平滑）
        private void Update()
        {
            if (_system == null) return;
            foreach (var skill in _system.Skills)
            {
                if (_slots.TryGetValue(skill.Id, out var slot))
                {
                    RefreshSlot(slot, skill);
                }
            }
        }

        private sealed class SlotUI
        {
            public GameObject Root;
            public Image Icon;
            public Image CooldownOverlay;
            public Text CooldownText;
            public Button Button;
        }
    }
}
