using UnityEngine;

namespace Game.Visual
{
    [ExecuteAlways]
    [RequireComponent(typeof(Camera))]
    public sealed class CharacterFocusBrightnessEffect : MonoBehaviour
    {
        [SerializeField] private Shader effectShader;
        [SerializeField] private Transform target;
        [SerializeField, Min(0f)] private float fullBrightnessRadius = 0.18f;
        [SerializeField, Min(0.001f)] private float falloffRadius = 0.5f;
        [SerializeField, Range(0f, 1f)] private float minimumBrightness = 0.25f;
        [SerializeField, Range(0f, 1f)] private float overlayStrength = 0f;
        [SerializeField] private Color overlayColor = Color.black;
        [SerializeField, Range(0f, 1f)] private float grayscaleStrength = 0f;
        [SerializeField, Min(0f)] private float grayscaleTransitionDuration = 2f;
        [SerializeField, Min(0.001f)] private float fullscreenRadius = 1.5f;

        private static readonly int CenterId = Shader.PropertyToID("_Center");
        private static readonly int FullRadiusId = Shader.PropertyToID("_FullRadius");
        private static readonly int FalloffRadiusId = Shader.PropertyToID("_FalloffRadius");
        private static readonly int MinimumBrightnessId = Shader.PropertyToID("_MinimumBrightness");
        private static readonly int OverlayColorId = Shader.PropertyToID("_OverlayColor");
        private static readonly int OverlayStrengthId = Shader.PropertyToID("_OverlayStrength");
        private static readonly int GrayscaleStrengthId = Shader.PropertyToID("_GrayscaleStrength");
        private static readonly int AspectId = Shader.PropertyToID("_Aspect");

        private Camera _camera;
        private Material _material;
        private float _grayscaleStart;
        private float _grayscaleTarget;
        private float _grayscaleTransitionTimer;
        private float _grayscaleTransitionLength;
        private float _fullRadiusStart;
        private float _fullRadiusTarget;
        private float _falloffRadiusStart;
        private float _falloffRadiusTarget;
        private float _radiusTransitionTimer;
        private float _radiusTransitionLength;

        public Transform Target
        {
            get => target;
            set => target = value;
        }

        public float FullBrightnessRadius
        {
            get => fullBrightnessRadius;
            set => fullBrightnessRadius = Mathf.Max(0f, value);
        }

        public float FalloffRadius
        {
            get => falloffRadius;
            set => falloffRadius = Mathf.Max(0.001f, value);
        }

        public float MinimumBrightness
        {
            get => minimumBrightness;
            set => minimumBrightness = Mathf.Clamp01(value);
        }

        public float OverlayStrength
        {
            get => overlayStrength;
            set => overlayStrength = Mathf.Clamp01(value);
        }

        public Color OverlayColor
        {
            get => overlayColor;
            set => overlayColor = value;
        }

        public float GrayscaleStrength
        {
            get => grayscaleStrength;
            set => SetGrayscaleStrength(value, grayscaleTransitionDuration);
        }

        public float GrayscaleTransitionDuration
        {
            get => grayscaleTransitionDuration;
            set => grayscaleTransitionDuration = Mathf.Max(0f, value);
        }

        public float FullscreenRadius
        {
            get => fullscreenRadius;
            set => fullscreenRadius = Mathf.Max(0.001f, value);
        }

        public void SetRadii(float fullRadius, float falloffRadius, float duration)
        {
            fullRadius = Mathf.Max(0f, fullRadius);
            falloffRadius = Mathf.Max(fullRadius + 0.001f, falloffRadius);
            duration = Mathf.Max(0f, duration);

            if (!Application.isPlaying || duration <= 0f)
            {
                fullBrightnessRadius = fullRadius;
                this.falloffRadius = falloffRadius;
                _radiusTransitionLength = 0f;
                return;
            }

            _fullRadiusStart = fullBrightnessRadius;
            _fullRadiusTarget = fullRadius;
            _falloffRadiusStart = this.falloffRadius;
            _falloffRadiusTarget = falloffRadius;
            _radiusTransitionTimer = 0f;
            _radiusTransitionLength = duration;
        }

        public void ExpandToFullscreen(float duration)
        {
            SetRadii(fullscreenRadius, fullscreenRadius + 0.001f, duration);
        }

        public void RestoreRadii(float fullRadius, float falloffRadius, float duration)
        {
            SetRadii(fullRadius, falloffRadius, duration);
        }

        public void SetGrayscaleStrength(float value, float duration)
        {
            value = Mathf.Clamp01(value);
            duration = Mathf.Max(0f, duration);

            if (!Application.isPlaying || duration <= 0f)
            {
                grayscaleStrength = value;
                _grayscaleTarget = value;
                _grayscaleTransitionTimer = 0f;
                _grayscaleTransitionLength = 0f;
                return;
            }

            _grayscaleStart = grayscaleStrength;
            _grayscaleTarget = value;
            _grayscaleTransitionTimer = 0f;
            _grayscaleTransitionLength = duration;
        }

        private void Update()
        {
            UpdateGrayscaleTransition();
            UpdateRadiusTransition();
        }

        private void UpdateGrayscaleTransition()
        {
            if (_grayscaleTransitionLength <= 0f) return;

            _grayscaleTransitionTimer += Time.deltaTime;
            float t = Mathf.Clamp01(_grayscaleTransitionTimer / _grayscaleTransitionLength);
            grayscaleStrength = Mathf.Lerp(_grayscaleStart, _grayscaleTarget, t);

            if (t >= 1f)
                _grayscaleTransitionLength = 0f;
        }

        private void UpdateRadiusTransition()
        {
            if (_radiusTransitionLength <= 0f) return;

            _radiusTransitionTimer += Time.deltaTime;
            float t = Mathf.Clamp01(_radiusTransitionTimer / _radiusTransitionLength);
            fullBrightnessRadius = Mathf.Lerp(_fullRadiusStart, _fullRadiusTarget, t);
            falloffRadius = Mathf.Lerp(_falloffRadiusStart, _falloffRadiusTarget, t);

            if (t >= 1f)
                _radiusTransitionLength = 0f;
        }

        private void OnEnable()
        {
            _camera = GetComponent<Camera>();
            EnsureMaterial();
        }

        private void OnDisable()
        {
            if (_material == null) return;

            if (Application.isPlaying)
                Destroy(_material);
            else
                DestroyImmediate(_material);

            _material = null;
        }

        private void OnRenderImage(RenderTexture source, RenderTexture destination)
        {
            if (target == null || !EnsureMaterial())
            {
                Graphics.Blit(source, destination);
                return;
            }

            Vector3 viewportPosition = _camera.WorldToViewportPoint(target.position);
            if (viewportPosition.z < 0f)
            {
                Graphics.Blit(source, destination);
                return;
            }

            _material.SetVector(CenterId, new Vector4(viewportPosition.x, viewportPosition.y, 0f, 0f));
            _material.SetFloat(FullRadiusId, fullBrightnessRadius);
            _material.SetFloat(FalloffRadiusId, Mathf.Max(fullBrightnessRadius + 0.001f, falloffRadius));
            _material.SetFloat(MinimumBrightnessId, minimumBrightness);
            _material.SetColor(OverlayColorId, overlayColor);
            _material.SetFloat(OverlayStrengthId, overlayStrength);
            _material.SetFloat(GrayscaleStrengthId, grayscaleStrength);
            _material.SetFloat(AspectId, source.width / (float)source.height);

            Graphics.Blit(source, destination, _material);
        }

        private bool EnsureMaterial()
        {
            if (effectShader == null)
                effectShader = Shader.Find("Hidden/Game/CharacterFocusBrightness");

            if (effectShader == null || !effectShader.isSupported)
                return false;

            if (_material == null || _material.shader != effectShader)
            {
                _material = new Material(effectShader)
                {
                    hideFlags = HideFlags.HideAndDontSave
                };
            }

            return true;
        }
    }
}
