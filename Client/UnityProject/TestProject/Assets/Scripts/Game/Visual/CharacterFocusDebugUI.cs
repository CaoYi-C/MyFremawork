using UnityEngine;

namespace Game.Visual
{
    public sealed class CharacterFocusDebugUI : MonoBehaviour
    {
        [SerializeField] private CharacterFocusBrightnessEffect effect;
        [SerializeField] private float aliveFullBrightnessRadius = 0.12f;
        [SerializeField] private float aliveFalloffRadius = 0.45f;
        [SerializeField] private float aliveMinimumBrightness = 0.25f;
        [SerializeField] private float transitionDuration = 2f;
        [SerializeField] private float deadMinimumBrightness = 0.12f;
        [SerializeField] private float deadOverlayStrength = 0.2f;
        [SerializeField] private Color deadOverlayColor = Color.black;

        public void SetDead()
        {
            if (effect == null)
                effect = FindObjectOfType<CharacterFocusBrightnessEffect>();

            if (effect == null) return;

            effect.MinimumBrightness = deadMinimumBrightness;
            effect.OverlayColor = deadOverlayColor;
            effect.OverlayStrength = deadOverlayStrength;
            effect.SetGrayscaleStrength(1f, transitionDuration);
            effect.ExpandToFullscreen(transitionDuration);
        }

        public void SetRevived()
        {
            if (effect == null)
                effect = FindObjectOfType<CharacterFocusBrightnessEffect>();

            if (effect == null) return;

            effect.MinimumBrightness = aliveMinimumBrightness;
            effect.OverlayStrength = 0f;
            effect.SetGrayscaleStrength(0f, transitionDuration);
            effect.RestoreRadii(aliveFullBrightnessRadius, aliveFalloffRadius, transitionDuration);
        }
    }
}
