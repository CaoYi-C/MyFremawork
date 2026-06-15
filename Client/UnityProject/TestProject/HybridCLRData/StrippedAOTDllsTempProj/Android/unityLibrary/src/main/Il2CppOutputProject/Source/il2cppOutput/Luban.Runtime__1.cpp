#include "pch-cpp.hpp"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif


#include <limits>



struct CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB;
struct JSONNode_tB935BFE8571E9CE3B5B31142780ECB495B5BE22A;
struct String_t;
struct StringBuilder_t;

IL2CPP_EXTERN_C RuntimeClass* JSONNode_tB935BFE8571E9CE3B5B31142780ECB495B5BE22A_il2cpp_TypeInfo_var;


IL2CPP_EXTERN_C_BEGIN
IL2CPP_EXTERN_C_END

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
struct U3CPrivateImplementationDetailsU3E_tD61DC7E301FF867D1626EAB694A99592D7D9C7A8  : public RuntimeObject
{
};
struct JSON_t9FCE2D06ED3B79967E11965AAD83E93F8A4F3425  : public RuntimeObject
{
};
struct JSONNode_tB935BFE8571E9CE3B5B31142780ECB495B5BE22A  : public RuntimeObject
{
};
struct String_t  : public RuntimeObject
{
	int32_t ____stringLength;
	Il2CppChar ____firstChar;
};
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F  : public RuntimeObject
{
};
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F_marshaled_pinvoke
{
};
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F_marshaled_com
{
};
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2  : public ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F
{
};
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2_marshaled_pinvoke
{
};
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2_marshaled_com
{
};
#pragma pack(push, tp, 1)
struct __StaticArrayInitTypeSizeU3D677_tF482FFE55795A1A9D474DB5C779562E4797C1555 
{
	union
	{
		struct
		{
			union
			{
			};
		};
		uint8_t __StaticArrayInitTypeSizeU3D677_tF482FFE55795A1A9D474DB5C779562E4797C1555__padding[677];
	};
};
#pragma pack(pop, tp)
#pragma pack(push, tp, 1)
struct __StaticArrayInitTypeSizeU3D888_tE2E163107F6F0767C4BB6B1C98CBC43ECA52D0C1 
{
	union
	{
		struct
		{
			union
			{
			};
		};
		uint8_t __StaticArrayInitTypeSizeU3D888_tE2E163107F6F0767C4BB6B1C98CBC43ECA52D0C1__padding[888];
	};
};
#pragma pack(pop, tp)
struct JSONContainerType_tAB361DD8D309B1D99C8777CE0F24E695C77F086B 
{
	int32_t ___value__;
};
struct U3CPrivateImplementationDetailsU3E_tD61DC7E301FF867D1626EAB694A99592D7D9C7A8_StaticFields
{
	__StaticArrayInitTypeSizeU3D677_tF482FFE55795A1A9D474DB5C779562E4797C1555 ___373F8828319A02FA6C83E995257345114096584F8868974233E3B25A5BF5459B;
	__StaticArrayInitTypeSizeU3D888_tE2E163107F6F0767C4BB6B1C98CBC43ECA52D0C1 ___6F76A22B812FA08DE2BA17538D3A80B403D954BF39F1155B537141C5CF837A3C;
};
struct JSONNode_tB935BFE8571E9CE3B5B31142780ECB495B5BE22A_StaticFields
{
	bool ___forceASCII;
	bool ___longAsString;
	bool ___allowLineComments;
	uint8_t ___Color32DefaultAlpha;
	float ___ColorDefaultAlpha;
	int32_t ___VectorContainerType;
	int32_t ___QuaternionContainerType;
	int32_t ___RectContainerType;
	int32_t ___ColorContainerType;
};
struct JSONNode_tB935BFE8571E9CE3B5B31142780ECB495B5BE22A_ThreadStaticFields
{
	StringBuilder_t* ___m_EscapeBuilder;
};
struct String_t_StaticFields
{
	String_t* ___Empty;
};
#ifdef __clang__
#pragma clang diagnostic pop
#endif



IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR JSONNode_tB935BFE8571E9CE3B5B31142780ECB495B5BE22A* JSONNode_Parse_mD028B64E418685D0E3E520D181AA58723CD02D25 (String_t* ___0_aJSON, const RuntimeMethod* method) ;
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR JSONNode_tB935BFE8571E9CE3B5B31142780ECB495B5BE22A* JSON_Parse_m0E7405F23EE53FCEB50BFA072C24D350202DD879 (String_t* ___0_aJSON, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&JSONNode_tB935BFE8571E9CE3B5B31142780ECB495B5BE22A_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	JSONNode_tB935BFE8571E9CE3B5B31142780ECB495B5BE22A* V_0 = NULL;
	{
		String_t* L_0 = ___0_aJSON;
		il2cpp_codegen_runtime_class_init_inline(JSONNode_tB935BFE8571E9CE3B5B31142780ECB495B5BE22A_il2cpp_TypeInfo_var);
		JSONNode_tB935BFE8571E9CE3B5B31142780ECB495B5BE22A* L_1;
		L_1 = JSONNode_Parse_mD028B64E418685D0E3E520D181AA58723CD02D25(L_0, NULL);
		V_0 = L_1;
		goto IL_000a;
	}

IL_000a:
	{
		JSONNode_tB935BFE8571E9CE3B5B31142780ECB495B5BE22A* L_2 = V_0;
		return L_2;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif
