Shader "Hidden/Game/CharacterFocusBrightness"
{
    Properties
    {
        _MainTex ("Texture", 2D) = "white" {}
    }
    SubShader
    {
        Cull Off ZWrite Off ZTest Always

        Pass
        {
            CGPROGRAM
            #pragma vertex vert
            #pragma fragment frag
            #pragma target 2.0

            #include "UnityCG.cginc"

            sampler2D _MainTex;
            float4 _MainTex_TexelSize;
            float2 _Center;
            float _FullRadius;
            float _FalloffRadius;
            float _MinimumBrightness;
            fixed4 _OverlayColor;
            float _OverlayStrength;
            float _GrayscaleStrength;
            float _Aspect;

            struct appdata
            {
                float4 vertex : POSITION;
                float2 uv : TEXCOORD0;
            };

            struct v2f
            {
                float4 vertex : SV_POSITION;
                float2 uv : TEXCOORD0;
            };

            v2f vert(appdata v)
            {
                v2f o;
                o.vertex = UnityObjectToClipPos(v.vertex);
                o.uv = v.uv;
                return o;
            }

            fixed4 frag(v2f i) : SV_Target
            {
                fixed4 col = tex2D(_MainTex, i.uv);

                float2 delta = i.uv - _Center;
                delta.x *= _Aspect;
                float dist = length(delta);
                float falloff = saturate((dist - _FullRadius) / max(0.0001, _FalloffRadius - _FullRadius));
                float brightness = lerp(1.0, _MinimumBrightness, smoothstep(0.0, 1.0, falloff));

                fixed3 rgb = col.rgb * brightness;
                float gray = dot(rgb, fixed3(0.299, 0.587, 0.114));
                rgb = lerp(rgb, gray.xxx, saturate(_GrayscaleStrength));

                float darkArea = saturate(1.0 - brightness);
                rgb = lerp(rgb, _OverlayColor.rgb, saturate(_OverlayStrength) * darkArea);

                return fixed4(rgb, col.a);
            }
            ENDCG
        }
    }
}
