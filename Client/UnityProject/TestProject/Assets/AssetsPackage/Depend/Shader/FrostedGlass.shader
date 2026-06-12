Shader "Custom/FrostedGlass"
{
    Properties
    {
        _Color ("Water Tint", Color) = (0.5, 0.7, 0.9, 0.25)
        _WaveSpeed ("Wave Speed", Range(0, 5)) = 1.5
        _WaveFreq ("Wave Frequency", Range(1, 30)) = 8
        _WaveAmp ("Wave Distortion", Range(0, 0.1)) = 0.015
        _WaveDetail ("Detail Waves", Range(0, 20)) = 12
        _WaveDetailAmp ("Detail Distortion", Range(0, 0.05)) = 0.005
        _FresnelPower ("Fresnel Power", Range(0.1, 10)) = 3
        _FresnelStrength ("Fresnel Strength", Range(0, 1)) = 0.5
        _SpecularPower ("Specular Power", Range(1, 128)) = 64
        _SpecularStrength ("Specular Strength", Range(0, 2)) = 0.8
        [Header(Depth Gradient)]
        _ShallowColor ("Shallow Color", Color) = (0.6, 0.85, 0.95, 0.3)
        _DeepColor ("Deep Color", Color) = (0.1, 0.3, 0.5, 0.9)
        _DepthMaxDistance ("Depth Max Distance", Range(0.1, 50)) = 10
        [Header(Foam)]
        _FoamColor ("Foam Color", Color) = (1, 1, 1, 0.9)
        _FoamWidth ("Foam Width", Range(0.01, 5)) = 1.5
        _FoamNoiseScale ("Foam Noise Scale", Range(1, 50)) = 20
        _FoamNoiseAmp ("Foam Noise Strength", Range(0, 1)) = 0.3
        [Header(Outline)]
        _OutlineColor ("Outline Color", Color) = (0.6, 0.8, 1.0, 1)
        _OutlineWidth ("Outline Width", Range(0, 0.1)) = 0.005
    }

    SubShader
    {
        Tags
        {
            "Queue" = "Transparent"
            "RenderType" = "Transparent"
            "IgnoreProjector" = "True"
        }

        GrabPass { "_GrabTexture" }

        Pass
        {
            Name "OUTLINE"
            Cull Front
            ZWrite Off

            CGPROGRAM
            #pragma vertex vert
            #pragma fragment frag
            #include "UnityCG.cginc"

            float4 _OutlineColor;
            float _OutlineWidth;

            struct appdata
            {
                float4 vertex : POSITION;
                float3 normal : NORMAL;
            };

            struct v2f
            {
                float4 pos : SV_POSITION;
            };

            v2f vert(appdata v)
            {
                v2f o;
                float3 viewNormal = normalize(mul((float3x3)UNITY_MATRIX_IT_MV, v.normal));
                float3 viewPos = UnityObjectToViewPos(v.vertex.xyz);
                viewPos += viewNormal * _OutlineWidth;
                o.pos = mul(UNITY_MATRIX_P, float4(viewPos, 1.0));
                return o;
            }

            fixed4 frag(v2f i) : SV_Target
            {
                return _OutlineColor;
            }
            ENDCG
        }

        Pass
        {
            Name "WATER_RIPPLE"
            Cull Back
            Blend SrcAlpha OneMinusSrcAlpha
            ZWrite Off

            CGPROGRAM
            #pragma vertex vert
            #pragma fragment frag
            #include "UnityCG.cginc"

            sampler2D _GrabTexture;
            float4 _GrabTexture_TexelSize;
            sampler2D _CameraDepthTexture;
            float4 _Color;
            float _WaveSpeed;
            float _WaveFreq;
            float _WaveAmp;
            float _WaveDetail;
            float _WaveDetailAmp;
            float _FresnelPower;
            float _FresnelStrength;
            float _SpecularPower;
            float _SpecularStrength;
            float4 _ShallowColor;
            float4 _DeepColor;
            float _DepthMaxDistance;
            float4 _FoamColor;
            float _FoamWidth;
            float _FoamNoiseScale;
            float _FoamNoiseAmp;

            struct appdata
            {
                float4 vertex : POSITION;
                float3 normal : NORMAL;
                float2 uv : TEXCOORD0;
            };

            struct v2f
            {
                float4 pos : SV_POSITION;
                float4 grabPos : TEXCOORD0;
                float3 worldNormal : TEXCOORD1;
                float3 worldPos : TEXCOORD2;
                float2 uv : TEXCOORD3;
            };

            v2f vert(appdata v)
            {
                v2f o;
                o.pos = UnityObjectToClipPos(v.vertex);
                o.grabPos = ComputeGrabScreenPos(o.pos);
                o.worldNormal = UnityObjectToWorldNormal(v.normal);
                o.worldPos = mul(unity_ObjectToWorld, v.vertex).xyz;
                o.uv = v.uv;
                return o;
            }

            float2 wave(float2 uv, float time)
            {
                float2 w1 = sin(float2(1.0, 0.7) * _WaveFreq + time * _WaveSpeed) * _WaveAmp;
                float2 w2 = sin(float2(-0.5, 1.3) * _WaveFreq * 0.7 + time * _WaveSpeed * 1.3) * _WaveAmp * 0.6;
                float2 w3 = sin(float2(0.8, -0.6) * _WaveFreq * 1.5 + time * _WaveSpeed * 0.8) * _WaveAmp * 0.3;

                float2 d1 = sin(float2(2.1, 1.8) * _WaveDetail + time * _WaveSpeed * 2.0) * _WaveDetailAmp;
                float2 d2 = sin(float2(-1.5, 2.3) * _WaveDetail * 1.3 + time * _WaveSpeed * 1.7) * _WaveDetailAmp * 0.5;

                return w1 + w2 + w3 + d1 + d2;
            }

            float hash21(float2 p)
            {
                p = frac(p * float2(123.34, 456.21));
                p += dot(p, p + 45.32);
                return frac(p.x * p.y);
            }

            float foamNoise(float2 uv)
            {
                float2 i = floor(uv);
                float2 f = frac(uv);
                f = f * f * (3.0 - 2.0 * f);

                float a = hash21(i);
                float b = hash21(i + float2(1, 0));
                float c = hash21(i + float2(0, 1));
                float d = hash21(i + float2(1, 1));

                return lerp(lerp(a, b, f.x), lerp(c, d, f.x), f.y);
            }

            fixed4 frag(v2f i) : SV_Target
            {
                float time = _Time.y;
                float2 uv = i.grabPos.xy / i.grabPos.w;
                float2 texelSize = _GrabTexture_TexelSize.xy;

                float2 distortion = wave(i.uv, time);
                float2 distortedUV = uv + distortion;

                half4 col = tex2D(_GrabTexture, distortedUV);

                float rawDepth = tex2D(_CameraDepthTexture, uv).r;
                float sceneDepth = LinearEyeDepth(rawDepth);
                float waterDepth = i.grabPos.w;
                float depthDiff = sceneDepth - waterDepth;
                depthDiff = max(depthDiff, 0);
                float depthFactor = saturate(depthDiff / _DepthMaxDistance);

                float3 shallow = _ShallowColor.rgb;
                float3 deep = _DeepColor.rgb;
                float3 depthColor = lerp(shallow, deep, depthFactor);
                float depthAlpha = lerp(_ShallowColor.a, _DeepColor.a, depthFactor);

                col.rgb *= 0.95;

                float3 viewDir = normalize(_WorldSpaceCameraPos - i.worldPos);
                float3 normal = normalize(i.worldNormal);

                float fresnel = pow(1.0 - saturate(dot(normal, viewDir)), _FresnelPower);
                fresnel *= _FresnelStrength;

                float3 lightDir = normalize(_WorldSpaceLightPos0.xyz);
                float3 halfDir = normalize(lightDir + viewDir);
                float specular = pow(saturate(dot(normal, halfDir)), _SpecularPower) * _SpecularStrength;

                col.rgb += fresnel * float3(0.7, 0.85, 1.0);
                col.rgb += specular * float3(1.0, 1.0, 1.0);
                col.rgb = lerp(col.rgb, depthColor, 0.7);

                float2 waveHighlight = sin((i.uv + distortion) * _WaveFreq * 2.0 + time * _WaveSpeed);
                float highlight = saturate(waveHighlight.x * waveHighlight.y * 2.0);
                col.rgb += highlight * 0.05 * float3(0.8, 0.9, 1.0);

                float foamMask = 1.0 - saturate(depthDiff / _FoamWidth);
                float foamPattern = foamNoise(i.uv * _FoamNoiseScale + time * 0.1);
                foamPattern = saturate(foamPattern + 0.3);
                float foam = foamMask * foamPattern;
                col.rgb = lerp(col.rgb, _FoamColor.rgb, foam * _FoamColor.a);

                col.a = saturate(depthAlpha + fresnel * 0.4 + foam * 0.5);

                return col;
            }
            ENDCG
        }
    }

    FallBack "Transparent/Diffuse"
}
