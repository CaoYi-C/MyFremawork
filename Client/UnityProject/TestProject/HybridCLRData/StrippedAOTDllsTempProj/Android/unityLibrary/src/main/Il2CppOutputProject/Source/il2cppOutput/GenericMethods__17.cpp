#include "pch-cpp.hpp"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif




template <typename R>
struct VirtualFuncInvoker0
{
	typedef R (*Func)(void*, const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeObject* obj)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		return ((Func)invokeData.methodPtr)(obj, invokeData.method);
	}
};
template <typename T1>
struct InvokerActionInvoker1;
template <typename T1>
struct InvokerActionInvoker1<T1*>
{
	static inline void Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1* p1)
	{
		void* params[1] = { p1 };
		method->invoker_method(methodPtr, method, obj, params, params[0]);
	}
};
template <typename T1, typename T2>
struct InvokerActionInvoker2;
template <typename T1, typename T2>
struct InvokerActionInvoker2<T1*, T2*>
{
	static inline void Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1* p1, T2* p2)
	{
		void* params[2] = { p1, p2 };
		method->invoker_method(methodPtr, method, obj, params, params[1]);
	}
};
template <typename R, typename T1>
struct InvokerFuncInvoker1;
template <typename R, typename T1>
struct InvokerFuncInvoker1<R, T1*>
{
	static inline R Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1* p1)
	{
		R ret;
		void* params[1] = { p1 };
		method->invoker_method(methodPtr, method, obj, params, &ret);
		return ret;
	}
};

struct Dictionary_2_t14FE4A752A83D53771C584E4C8D14E01F2AFD7BA;
struct Dictionary_2_t954AEC357FE7190582B8255D4ACEF81F5E94A6A5;
struct EqualityComparer_1_t92563A67F1C1ECDC3FE387C46498E2E56B59F3C2;
struct FieldCodec_1_t5E5853045CAC4F051697FDB8A12CC79D264D40D7;
struct FieldCodec_1_tB1F4F5B504DB6A9556F8A62B1E1A7505CD128658;
struct FieldCodec_1_tB0617798EF40F19054BE58235A7396E95CC2319B;
struct Func_2_t9A0D493A82DCC47C9C819A3B045E02D9B5DDCE1B;
struct Func_2_tECC0CFC575314169268AC4D7DE437B7DD3A62962;
struct Func_2_t8DB808B3690BFDBD7B936631B430453B90DBBDE7;
struct IBufferWriter_1_t09B22D28ED83DD9237FC6D4E8014388593A8C897;
struct IEqualityComparer_1_t0C79004BFE79D9DBCE6C2250109D31D468A9A68E;
struct ITypeConstructor_1_t81670FEA206550EF92A986F4A63FC5302AB1D638;
struct ITypeConstructor_1_t3B0FE01881012CC548F6EE132D9D04AA93EDE092;
struct ITypeConstructor_1_t2957C3F3F922000D05C6AE59163AF0088BB8D2E4;
struct ITypeConstructor_1_t73C3366FF37ECFD1CC6142A80D1A0E31E89DDB04;
struct ITypeConstructor_1_t0FE2B73907C0A0AEB0E84716E021DD7420B23A2B;
struct ITypeConstructor_1_t5E4FD8D127EC0F24B375DF611109A9783C9949D0;
struct ITypeConstructor_1_tCC196E183FB5A7CF798C682F9C3B70CDDA50CFFF;
struct ITypeConstructor_1_tADCE5163310B602EB1878CA0050295BFB0F6B542;
struct ITypeConstructor_1_t61D5D3D9EDD28391B0FE316A5641A34D7FF16FD0;
struct ITypeConstructor_1_t5B814DBA70C191660AF27E38032998417073D7A2;
struct ITypeConstructor_1_t63AA3F84ED218C4C0589371B74758F62E3EFCF85;
struct InputMerger_t542A2DA3E03419636477930C3E4FDB8F47053F30;
struct InputMerger_t2DB27318075169CCBF8D0A4D86DCF511B67FE6FC;
struct InputMerger_tB6116E0E2F9D05AB008606CE16C5727B159FA2A4;
struct KeyCollection_t06BF4E8028DD7CCA572FE96F996862FCB21C8ED4;
struct ValueCollection_t9EB9C5634AB88E4E9CA993FE202AEE842111C914;
struct ValueReader_1_t0E918B17E2768F18588C8D2085E3D4B954C220B5;
struct ValueReader_1_t914179245F7AF92982120EBE2E1F0005B7120D6A;
struct ValueReader_1_t9F38C64596B97F44283CC4982C584BDA4CAF104D;
struct ValueReader_1_t0BA827CC5DA5070032FF53D83C96399AEE9F4F77;
struct ValueWriter_1_t6C508A7B681A703426E0375B37A02159DB7676BE;
struct ValueWriter_1_t96D8EE881652905D1D111ADDEE3FD3E98294DD34;
struct ValueWriter_1_tAED9E83499DA71A5ECF8E3540ED52F4F0516EA48;
struct ValuesMerger_t3E9CBE0258C114AB31F0638D167BFAB32545E61B;
struct ValuesMerger_t23AC7DD3FE99776A832CDCC240F9FFC10DF7DE91;
struct ValuesMerger_tEEBC50C7E3944744C2B8D2596562542308DF1B2C;
struct EntryU5BU5D_t756A95E079BB929872956FD3C32190FE718B2B92;
struct ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031;
struct CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB;
struct DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771;
struct Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C;
struct IntPtrU5BU5D_tFD177F8C806A6921AD7150264CCC62FA00CAD832;
struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918;
struct StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF;
struct StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248;
struct TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB;
struct AsyncCallback_t7FEF460CBDCFB9C5FA2EF776984778B9A4145F4C;
struct Binder_t91BFCE95A7057FADF4D8A1A342AFE52872246235;
struct CodedInputStream_t271CAE9006F3226F28E8F9FCF8E2B0C35E64B425;
struct CodedOutputStream_tEA7C97F94CE101273611192E2A22CD872F584163;
struct DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E;
struct ExtensionRegistry_t3A02F9CABE27F85D70F5444B20C9640194BCBDCC;
struct IAsyncResult_t7B9B5A0ECB35DCEC31B8A8122C37D687369253B5;
struct IDictionary_t6D03155AF1FA9083817AA5B6AD7DEEACC26AB220;
struct InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB;
struct MemberFilter_tF644F1AE82F611B677CE1964D5A3277DDA21D553;
struct MethodInfo_t;
struct SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6;
struct String_t;
struct StringBuilder_t;
struct Type_t;
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915;
struct Expression_t24E9476A15D0D7F6495CF8292DA48C63C871E4B7;
struct ITypeConstructor_tAEA6BC4B87F0F3739E4457F21908EF55F666EB08;
struct TypeConstructorVisitor_tFC61250F68BF43FE889F5B1002CBFF90648E9C7F;

IL2CPP_EXTERN_C RuntimeClass* CodedOutputStream_tEA7C97F94CE101273611192E2A22CD872F584163_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ExpressionEvaluator_tF912A1FA6CB7EA697DFA7926E78D808A446B48F0_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ParsingPrimitivesMessages_t7E329824B6CDE2975470D909F2DB2073F4ACF0F2_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ParsingPrimitives_t4F870CEF214FECD314006BA436D0866A59B90004_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* StringBuilder_t_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* TypeUtility_t62F146E51B66BB18FA0E1EFA84A564FF2B8AAD03_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Type_t_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* WrapperCodecs_tE553F7639B839C368D43033A632BD1D30EC9BCFB_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C String_t* _stringLiteral622F5FF68A93093A1D312703FF92713F8BF2C946;
IL2CPP_EXTERN_C String_t* _stringLiteral7210D872E945C71ACA8CEF51ACA40552C43E8605;
IL2CPP_EXTERN_C String_t* _stringLiteralA6A94DCA4A0604385AFC755179D51DDE7BF9BE25;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2_TryGetValue_m76D0309695A0582B3E29E97942ACD35DC4EFD128_RuntimeMethod_var;
struct Delegate_t_marshaled_com;
struct Delegate_t_marshaled_pinvoke;
struct Exception_t_marshaled_com;
struct Exception_t_marshaled_pinvoke;

struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918;
struct StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248;

IL2CPP_EXTERN_C_BEGIN
IL2CPP_EXTERN_C_END

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
struct U3CU3Ec__DisplayClass3_0_1_tF5F0082B732265B8C79EB91362F5070AE725217C  : public RuntimeObject
{
	FieldCodec_1_tB1F4F5B504DB6A9556F8A62B1E1A7505CD128658* ___nestedCoded;
};
struct Dictionary_2_t954AEC357FE7190582B8255D4ACEF81F5E94A6A5  : public RuntimeObject
{
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____buckets;
	EntryU5BU5D_t756A95E079BB929872956FD3C32190FE718B2B92* ____entries;
	int32_t ____count;
	int32_t ____freeList;
	int32_t ____freeCount;
	int32_t ____version;
	RuntimeObject* ____comparer;
	KeyCollection_t06BF4E8028DD7CCA572FE96F996862FCB21C8ED4* ____keys;
	ValueCollection_t9EB9C5634AB88E4E9CA993FE202AEE842111C914* ____values;
	RuntimeObject* ____syncRoot;
};
struct FieldCodec_1_t5E5853045CAC4F051697FDB8A12CC79D264D40D7  : public RuntimeObject
{
	bool ___U3CPackedRepeatedFieldU3Ek__BackingField;
	ValueWriter_1_t6C508A7B681A703426E0375B37A02159DB7676BE* ___U3CValueWriterU3Ek__BackingField;
	Func_2_t9A0D493A82DCC47C9C819A3B045E02D9B5DDCE1B* ___U3CValueSizeCalculatorU3Ek__BackingField;
	ValueReader_1_t914179245F7AF92982120EBE2E1F0005B7120D6A* ___U3CValueReaderU3Ek__BackingField;
	InputMerger_t542A2DA3E03419636477930C3E4FDB8F47053F30* ___U3CValueMergerU3Ek__BackingField;
	ValuesMerger_t3E9CBE0258C114AB31F0638D167BFAB32545E61B* ___U3CFieldMergerU3Ek__BackingField;
	int32_t ___U3CFixedSizeU3Ek__BackingField;
	uint32_t ___U3CTagU3Ek__BackingField;
	uint32_t ___U3CEndTagU3Ek__BackingField;
	RuntimeObject* ___U3CDefaultValueU3Ek__BackingField;
	int32_t ___tagSize;
};
struct FieldCodec_1_tB1F4F5B504DB6A9556F8A62B1E1A7505CD128658 : public RuntimeObject {};
struct FieldCodec_1_tB0617798EF40F19054BE58235A7396E95CC2319B : public RuntimeObject {};
struct MemberInfo_t  : public RuntimeObject
{
};
struct String_t  : public RuntimeObject
{
	int32_t ____stringLength;
	Il2CppChar ____firstChar;
};
struct StringBuilder_t  : public RuntimeObject
{
	CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* ___m_ChunkChars;
	StringBuilder_t* ___m_ChunkPrevious;
	int32_t ___m_ChunkLength;
	int32_t ___m_ChunkOffset;
	int32_t ___m_MaxCapacity;
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
struct _AndroidJNIHelper_tA796944DDB1B1459DF68C9FFA518F452C81364F3  : public RuntimeObject
{
};
struct Expression_t24E9476A15D0D7F6495CF8292DA48C63C871E4B7  : public RuntimeObject
{
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* ___rpnTokens;
	bool ___hasVariables;
};
struct WrapperCodecs_tE553F7639B839C368D43033A632BD1D30EC9BCFB  : public RuntimeObject
{
};
struct TypeConstructorVisitor_tFC61250F68BF43FE889F5B1002CBFF90648E9C7F  : public RuntimeObject
{
	RuntimeObject* ___TypeConstructor;
};
struct Nullable_1_tCF32C56A2641879C053C86F273C0C6EC1B40BC28 
{
	bool ___hasValue;
	int32_t ___value;
};
typedef Il2CppFullySharedGenericStruct Nullable_1_t71C4EA4E848DBD7A4A97704069FB951159A3A339;
struct ReadOnlyMemory_1_t63F301BF893B0AB689953D86A641168CA66D2399 
{
	RuntimeObject* ____object;
	int32_t ____index;
	int32_t ____length;
};
#ifndef ReadOnlyMemory_1_t766DD3EE24B08138FB23CBC5B315D83C6E1272F5_marshaled_pinvoke_define
#define ReadOnlyMemory_1_t766DD3EE24B08138FB23CBC5B315D83C6E1272F5_marshaled_pinvoke_define
struct ReadOnlyMemory_1_t766DD3EE24B08138FB23CBC5B315D83C6E1272F5_marshaled_pinvoke
{
	Il2CppIUnknown* ____object;
	int32_t ____index;
	int32_t ____length;
};
#endif
#ifndef ReadOnlyMemory_1_t766DD3EE24B08138FB23CBC5B315D83C6E1272F5_marshaled_com_define
#define ReadOnlyMemory_1_t766DD3EE24B08138FB23CBC5B315D83C6E1272F5_marshaled_com_define
struct ReadOnlyMemory_1_t766DD3EE24B08138FB23CBC5B315D83C6E1272F5_marshaled_com
{
	Il2CppIUnknown* ____object;
	int32_t ____index;
	int32_t ____length;
};
#endif
struct ReadOnlySequence_1_t85097489C00952FC58DF9F3ACE926EAE9A51898A 
{
	RuntimeObject* ____startObject;
	RuntimeObject* ____endObject;
	int32_t ____startInteger;
	int32_t ____endInteger;
};
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22 
{
	bool ___m_value;
};
struct Char_t521A6F19B456D956AF452D926C32709DC03D6B17 
{
	Il2CppChar ___m_value;
};
struct Double_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F 
{
	double ___m_value;
};
struct Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C 
{
	int32_t ___m_value;
};
struct Int64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3 
{
	int64_t ___m_value;
};
struct IntPtr_t 
{
	void* ___m_value;
};
struct SequencePosition_tF4FA2B48A1A5B3A50EFDA1174069C749D986EA14 
{
	RuntimeObject* ____object;
	int32_t ____integer;
};
struct SequencePosition_tF4FA2B48A1A5B3A50EFDA1174069C749D986EA14_marshaled_pinvoke
{
	Il2CppIUnknown* ____object;
	int32_t ____integer;
};
struct SequencePosition_tF4FA2B48A1A5B3A50EFDA1174069C749D986EA14_marshaled_com
{
	Il2CppIUnknown* ____object;
	int32_t ____integer;
};
struct UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B 
{
	uint32_t ___m_value;
};
struct UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF 
{
	uint64_t ___m_value;
};
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915 
{
	union
	{
		struct
		{
		};
		uint8_t Void_t4861ACF8F4594C3437BB48B6E56783494B843915__padding[1];
	};
};
struct WriteBufferHelper_t88D4023E94B7D52F4C518E266A90BE267DD10557 
{
	RuntimeObject* ___bufferWriter;
	CodedOutputStream_tEA7C97F94CE101273611192E2A22CD872F584163* ___codedOutputStream;
};
struct WriteBufferHelper_t88D4023E94B7D52F4C518E266A90BE267DD10557_marshaled_pinvoke
{
	RuntimeObject* ___bufferWriter;
	CodedOutputStream_tEA7C97F94CE101273611192E2A22CD872F584163* ___codedOutputStream;
};
struct WriteBufferHelper_t88D4023E94B7D52F4C518E266A90BE267DD10557_marshaled_com
{
	RuntimeObject* ___bufferWriter;
	CodedOutputStream_tEA7C97F94CE101273611192E2A22CD872F584163* ___codedOutputStream;
};
struct ByReference_1_t9C85BCCAAF8C525B6C06B07E922D8D217BE8D6FC 
{
	intptr_t ____value;
};
struct Enumerator_t81A4C70A8A186500F66FD3F505D8B2E7C805D770 
{
	ReadOnlySequence_1_t85097489C00952FC58DF9F3ACE926EAE9A51898A ____sequence;
	SequencePosition_tF4FA2B48A1A5B3A50EFDA1174069C749D986EA14 ____next;
	ReadOnlyMemory_1_t63F301BF893B0AB689953D86A641168CA66D2399 ____currentMemory;
};
struct Delegate_t  : public RuntimeObject
{
	intptr_t ___method_ptr;
	intptr_t ___invoke_impl;
	RuntimeObject* ___m_target;
	intptr_t ___method;
	intptr_t ___delegate_trampoline;
	intptr_t ___extra_arg;
	intptr_t ___method_code;
	intptr_t ___interp_method;
	intptr_t ___interp_invoke_impl;
	MethodInfo_t* ___method_info;
	MethodInfo_t* ___original_method_info;
	DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E* ___data;
	bool ___method_is_virtual;
};
struct Delegate_t_marshaled_pinvoke
{
	intptr_t ___method_ptr;
	intptr_t ___invoke_impl;
	Il2CppIUnknown* ___m_target;
	intptr_t ___method;
	intptr_t ___delegate_trampoline;
	intptr_t ___extra_arg;
	intptr_t ___method_code;
	intptr_t ___interp_method;
	intptr_t ___interp_invoke_impl;
	MethodInfo_t* ___method_info;
	MethodInfo_t* ___original_method_info;
	DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E* ___data;
	int32_t ___method_is_virtual;
};
struct Delegate_t_marshaled_com
{
	intptr_t ___method_ptr;
	intptr_t ___invoke_impl;
	Il2CppIUnknown* ___m_target;
	intptr_t ___method;
	intptr_t ___delegate_trampoline;
	intptr_t ___extra_arg;
	intptr_t ___method_code;
	intptr_t ___interp_method;
	intptr_t ___interp_invoke_impl;
	MethodInfo_t* ___method_info;
	MethodInfo_t* ___original_method_info;
	DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E* ___data;
	int32_t ___method_is_virtual;
};
struct Exception_t  : public RuntimeObject
{
	String_t* ____className;
	String_t* ____message;
	RuntimeObject* ____data;
	Exception_t* ____innerException;
	String_t* ____helpURL;
	RuntimeObject* ____stackTrace;
	String_t* ____stackTraceString;
	String_t* ____remoteStackTraceString;
	int32_t ____remoteStackIndex;
	RuntimeObject* ____dynamicMethods;
	int32_t ____HResult;
	String_t* ____source;
	SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6* ____safeSerializationManager;
	StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF* ___captured_traces;
	IntPtrU5BU5D_tFD177F8C806A6921AD7150264CCC62FA00CAD832* ___native_trace_ips;
	int32_t ___caught_in_unmanaged;
};
struct Exception_t_marshaled_pinvoke
{
	char* ____className;
	char* ____message;
	RuntimeObject* ____data;
	Exception_t_marshaled_pinvoke* ____innerException;
	char* ____helpURL;
	Il2CppIUnknown* ____stackTrace;
	char* ____stackTraceString;
	char* ____remoteStackTraceString;
	int32_t ____remoteStackIndex;
	Il2CppIUnknown* ____dynamicMethods;
	int32_t ____HResult;
	char* ____source;
	SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6* ____safeSerializationManager;
	StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF* ___captured_traces;
	Il2CppSafeArray* ___native_trace_ips;
	int32_t ___caught_in_unmanaged;
};
struct Exception_t_marshaled_com
{
	Il2CppChar* ____className;
	Il2CppChar* ____message;
	RuntimeObject* ____data;
	Exception_t_marshaled_com* ____innerException;
	Il2CppChar* ____helpURL;
	Il2CppIUnknown* ____stackTrace;
	Il2CppChar* ____stackTraceString;
	Il2CppChar* ____remoteStackTraceString;
	int32_t ____remoteStackIndex;
	Il2CppIUnknown* ____dynamicMethods;
	int32_t ____HResult;
	Il2CppChar* ____source;
	SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6* ____safeSerializationManager;
	StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF* ___captured_traces;
	Il2CppSafeArray* ___native_trace_ips;
	int32_t ___caught_in_unmanaged;
};
struct RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B 
{
	intptr_t ___value;
};
struct WriterInternalState_tAACF88B10900BCAB675899ED5D745BC2882A1780 
{
	int32_t ___limit;
	int32_t ___position;
	WriteBufferHelper_t88D4023E94B7D52F4C518E266A90BE267DD10557 ___writeBufferHelper;
};
struct WriterInternalState_tAACF88B10900BCAB675899ED5D745BC2882A1780_marshaled_pinvoke
{
	int32_t ___limit;
	int32_t ___position;
	WriteBufferHelper_t88D4023E94B7D52F4C518E266A90BE267DD10557_marshaled_pinvoke ___writeBufferHelper;
};
struct WriterInternalState_tAACF88B10900BCAB675899ED5D745BC2882A1780_marshaled_com
{
	int32_t ___limit;
	int32_t ___position;
	WriteBufferHelper_t88D4023E94B7D52F4C518E266A90BE267DD10557_marshaled_com ___writeBufferHelper;
};
struct ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D 
{
	ByReference_1_t9C85BCCAAF8C525B6C06B07E922D8D217BE8D6FC ____pointer;
	int32_t ____length;
};
struct Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 
{
	ByReference_1_t9C85BCCAAF8C525B6C06B07E922D8D217BE8D6FC ____pointer;
	int32_t ____length;
};
struct MulticastDelegate_t  : public Delegate_t
{
	DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771* ___delegates;
};
struct MulticastDelegate_t_marshaled_pinvoke : public Delegate_t_marshaled_pinvoke
{
	Delegate_t_marshaled_pinvoke** ___delegates;
};
struct MulticastDelegate_t_marshaled_com : public Delegate_t_marshaled_com
{
	Delegate_t_marshaled_com** ___delegates;
};
struct SegmentedBufferHelper_tB533BBE3FC95EE78A9A8120BCFCBFF46AE02126B 
{
	Nullable_1_tCF32C56A2641879C053C86F273C0C6EC1B40BC28 ___totalLength;
	Enumerator_t81A4C70A8A186500F66FD3F505D8B2E7C805D770 ___readOnlySequenceEnumerator;
	CodedInputStream_t271CAE9006F3226F28E8F9FCF8E2B0C35E64B425* ___codedInputStream;
};
struct SegmentedBufferHelper_tB533BBE3FC95EE78A9A8120BCFCBFF46AE02126B_marshaled_pinvoke
{
	Nullable_1_tCF32C56A2641879C053C86F273C0C6EC1B40BC28 ___totalLength;
	Enumerator_t81A4C70A8A186500F66FD3F505D8B2E7C805D770 ___readOnlySequenceEnumerator;
	CodedInputStream_t271CAE9006F3226F28E8F9FCF8E2B0C35E64B425* ___codedInputStream;
};
struct SegmentedBufferHelper_tB533BBE3FC95EE78A9A8120BCFCBFF46AE02126B_marshaled_com
{
	Nullable_1_tCF32C56A2641879C053C86F273C0C6EC1B40BC28 ___totalLength;
	Enumerator_t81A4C70A8A186500F66FD3F505D8B2E7C805D770 ___readOnlySequenceEnumerator;
	CodedInputStream_t271CAE9006F3226F28E8F9FCF8E2B0C35E64B425* ___codedInputStream;
};
struct SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295  : public Exception_t
{
};
struct Type_t  : public MemberInfo_t
{
	RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B ____impl;
};
struct InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB  : public SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295
{
};
struct ParserInternalState_t3044183736150999B222F94BFC5A875FA33EB36C 
{
	int32_t ___bufferPos;
	int32_t ___bufferSize;
	int32_t ___bufferSizeAfterLimit;
	int32_t ___currentLimit;
	int32_t ___totalBytesRetired;
	int32_t ___recursionDepth;
	SegmentedBufferHelper_tB533BBE3FC95EE78A9A8120BCFCBFF46AE02126B ___segmentedBufferHelper;
	uint32_t ___lastTag;
	uint32_t ___nextTag;
	bool ___hasNextTag;
	int32_t ___sizeLimit;
	int32_t ___recursionLimit;
	bool ___U3CDiscardUnknownFieldsU3Ek__BackingField;
	ExtensionRegistry_t3A02F9CABE27F85D70F5444B20C9640194BCBDCC* ___U3CExtensionRegistryU3Ek__BackingField;
};
struct ParserInternalState_t3044183736150999B222F94BFC5A875FA33EB36C_marshaled_pinvoke
{
	int32_t ___bufferPos;
	int32_t ___bufferSize;
	int32_t ___bufferSizeAfterLimit;
	int32_t ___currentLimit;
	int32_t ___totalBytesRetired;
	int32_t ___recursionDepth;
	SegmentedBufferHelper_tB533BBE3FC95EE78A9A8120BCFCBFF46AE02126B_marshaled_pinvoke ___segmentedBufferHelper;
	uint32_t ___lastTag;
	uint32_t ___nextTag;
	int32_t ___hasNextTag;
	int32_t ___sizeLimit;
	int32_t ___recursionLimit;
	int32_t ___U3CDiscardUnknownFieldsU3Ek__BackingField;
	ExtensionRegistry_t3A02F9CABE27F85D70F5444B20C9640194BCBDCC* ___U3CExtensionRegistryU3Ek__BackingField;
};
struct ParserInternalState_t3044183736150999B222F94BFC5A875FA33EB36C_marshaled_com
{
	int32_t ___bufferPos;
	int32_t ___bufferSize;
	int32_t ___bufferSizeAfterLimit;
	int32_t ___currentLimit;
	int32_t ___totalBytesRetired;
	int32_t ___recursionDepth;
	SegmentedBufferHelper_tB533BBE3FC95EE78A9A8120BCFCBFF46AE02126B_marshaled_com ___segmentedBufferHelper;
	uint32_t ___lastTag;
	uint32_t ___nextTag;
	int32_t ___hasNextTag;
	int32_t ___sizeLimit;
	int32_t ___recursionLimit;
	int32_t ___U3CDiscardUnknownFieldsU3Ek__BackingField;
	ExtensionRegistry_t3A02F9CABE27F85D70F5444B20C9640194BCBDCC* ___U3CExtensionRegistryU3Ek__BackingField;
};
struct WriteContext_tF80B3959AE2E6F9D5F8D447B35D859DA2ABD226D 
{
	Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 ___buffer;
	WriterInternalState_tAACF88B10900BCAB675899ED5D745BC2882A1780 ___state;
};
struct WriteContext_tF80B3959AE2E6F9D5F8D447B35D859DA2ABD226D_marshaled_pinvoke
{
	Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 ___buffer;
	WriterInternalState_tAACF88B10900BCAB675899ED5D745BC2882A1780_marshaled_pinvoke ___state;
};
struct WriteContext_tF80B3959AE2E6F9D5F8D447B35D859DA2ABD226D_marshaled_com
{
	Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 ___buffer;
	WriterInternalState_tAACF88B10900BCAB675899ED5D745BC2882A1780_marshaled_com ___state;
};
struct ParseContext_tC04F8D72236E3ED9155AAD861769A3C56AEEB0EF 
{
	ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D ___buffer;
	ParserInternalState_t3044183736150999B222F94BFC5A875FA33EB36C ___state;
};
struct ParseContext_tC04F8D72236E3ED9155AAD861769A3C56AEEB0EF_marshaled_pinvoke
{
	ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D ___buffer;
	ParserInternalState_t3044183736150999B222F94BFC5A875FA33EB36C_marshaled_pinvoke ___state;
};
struct ParseContext_tC04F8D72236E3ED9155AAD861769A3C56AEEB0EF_marshaled_com
{
	ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D ___buffer;
	ParserInternalState_t3044183736150999B222F94BFC5A875FA33EB36C_marshaled_com ___state;
};
struct ValueReader_1_t0E918B17E2768F18588C8D2085E3D4B954C220B5  : public MulticastDelegate_t
{
};
struct FieldCodec_1_t5E5853045CAC4F051697FDB8A12CC79D264D40D7_StaticFields
{
	EqualityComparer_1_t92563A67F1C1ECDC3FE387C46498E2E56B59F3C2* ___EqualityComparer;
	RuntimeObject* ___DefaultDefault;
	bool ___TypeSupportsPacking;
};
struct String_t_StaticFields
{
	String_t* ___Empty;
};
struct WrapperCodecs_tE553F7639B839C368D43033A632BD1D30EC9BCFB_StaticFields
{
	Dictionary_2_t954AEC357FE7190582B8255D4ACEF81F5E94A6A5* ___Codecs;
	Dictionary_2_t954AEC357FE7190582B8255D4ACEF81F5E94A6A5* ___Readers;
};
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_StaticFields
{
	String_t* ___TrueString;
	String_t* ___FalseString;
};
struct Char_t521A6F19B456D956AF452D926C32709DC03D6B17_StaticFields
{
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___s_categoryForLatin1;
};
struct IntPtr_t_StaticFields
{
	intptr_t ___Zero;
};
struct Type_t_StaticFields
{
	Binder_t91BFCE95A7057FADF4D8A1A342AFE52872246235* ___s_defaultBinder;
	Il2CppChar ___Delimiter;
	TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB* ___EmptyTypes;
	RuntimeObject* ___Missing;
	MemberFilter_tF644F1AE82F611B677CE1964D5A3277DDA21D553* ___FilterAttribute;
	MemberFilter_tF644F1AE82F611B677CE1964D5A3277DDA21D553* ___FilterName;
	MemberFilter_tF644F1AE82F611B677CE1964D5A3277DDA21D553* ___FilterNameIgnoreCase;
};
#ifdef __clang__
#pragma clang diagnostic pop
#endif
struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918  : public RuntimeArray
{
	ALIGN_FIELD (8) RuntimeObject* m_Items[1];

	inline RuntimeObject* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline RuntimeObject** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, RuntimeObject* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline RuntimeObject* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline RuntimeObject** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, RuntimeObject* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};
struct StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248  : public RuntimeArray
{
	ALIGN_FIELD (8) String_t* m_Items[1];

	inline String_t* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline String_t** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, String_t* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline String_t* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline String_t** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, String_t* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};


IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ExpressionEvaluator_EvaluateTokens_TisDouble_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F_m791767867653D0CCE2BEFF83F336A41B5B3A718E_gshared (StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* ___0_tokens, double* ___1_value, int32_t ___2_index, int32_t ___3_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ExpressionEvaluator_EvaluateTokens_TisInt64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3_m7418F7A8835B2770EF83F1D52F2723897CD76DEB_gshared (StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* ___0_tokens, int64_t* ___1_value, int32_t ___2_index, int32_t ___3_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ExpressionEvaluator_EvaluateTokens_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_mCFCF758DECB276DBCB0A8B83BAE195EF3B974780_gshared (StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* ___0_tokens, uint64_t* ___1_value, int32_t ___2_index, int32_t ___3_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t FieldCodec_1_CalculateSizeWithTag_mAF91F403A614B09B2113343DEFB9F23E37528D79_gshared (FieldCodec_1_t5E5853045CAC4F051697FDB8A12CC79D264D40D7* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_TryGetValue_mD15380A4ED7CDEE99EA45881577D26BA9CE1B849_gshared (Dictionary_2_t14FE4A752A83D53771C584E4C8D14E01F2AFD7BA* __this, RuntimeObject* ___0_key, RuntimeObject** ___1_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RuntimeObject* FieldCodec_1_get_DefaultValue_m1F114731B3660936CE2D9CDCE526CB33FF0169A6_gshared_inline (FieldCodec_1_t5E5853045CAC4F051697FDB8A12CC79D264D40D7* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint32_t FieldCodec_1_get_Tag_mFD9919FD0E0A0E96F3BEC9FE3E6C7DA9194DF07E_gshared_inline (FieldCodec_1_t5E5853045CAC4F051697FDB8A12CC79D264D40D7* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* FieldCodec_1_Read_mE413D0DC82F78AA938FEAA5EBF2BF72862E70DB0_gshared (FieldCodec_1_t5E5853045CAC4F051697FDB8A12CC79D264D40D7* __this, ParseContext_tC04F8D72236E3ED9155AAD861769A3C56AEEB0EF* ___0_ctx, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void FieldCodec_1_WriteTagAndValue_mA4E442BBC368DD9685D6C30C692AD5130E9BAA85_gshared (FieldCodec_1_t5E5853045CAC4F051697FDB8A12CC79D264D40D7* __this, WriteContext_tF80B3959AE2E6F9D5F8D447B35D859DA2ABD226D* ___0_ctx, RuntimeObject* ___1_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* TypeUtility_CreateTypeConstructor_TisBounds_t367E830C64BBF235ED8C3B2F8CF6254FDCAD39C3_m16C827D0F6107B7998F6C99B57F7CC2F181E2198_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* TypeUtility_CreateTypeConstructor_TisBoundsInt_t4E757DE5EFF9FCB42000F173360DDC63B5585485_m8F344250A2F9E6EE6DDBA6BA833BB36D0F272B66_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* TypeUtility_CreateTypeConstructor_TisColor_tD001788D726C3A7F1379BEED0260B9591F440C1F_mBBCB804F367E06EA4D482F1B69165DD2B5BF38FF_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* TypeUtility_CreateTypeConstructor_TisRuntimeObject_m4E17F588B090C1DADAE2D986BDA407DECEAC020F_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* TypeUtility_CreateTypeConstructor_TisRect_tA04E0F8A1830E767F40FB27ECD8D309303571F0D_m2C5F5CF80D13B041768C7845C5AAEEC02BB683BA_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* TypeUtility_CreateTypeConstructor_TisRectInt_t1744D10E1063135DA9D574F95205B98DAC600CB8_mF6949D9EDD480E6666CD975C66487AAD6ABC7D11_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* TypeUtility_CreateTypeConstructor_TisVector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7_mE0C65F4221E48BB07F75856972A0CCDAE284AB9F_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* TypeUtility_CreateTypeConstructor_TisVector2Int_t69B2886EBAB732D9B880565E18E7568F3DE0CE6A_mC8EF710494C8986B279262C6C64947BE2C1DC55C_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* TypeUtility_CreateTypeConstructor_TisVector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2_m1AB8BF0921C24186B3C43FC4341AAD2F6FE87C4D_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* TypeUtility_CreateTypeConstructor_TisVector3Int_t65CB06F557251D18A37BD71F3655BA836A357376_mB00220519A80AA5ACE36B7DBA2E6A6CB796302AF_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* TypeUtility_CreateTypeConstructor_TisVector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3_mED1DC338E5DB62F3E64F6272A9F12150DA5CC1B9_gshared (const RuntimeMethod* method) ;

IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Type_t* Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57 (RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B ___0_handle, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* _AndroidJNIHelper_GetSignature_m414A7A6B98FB5565075E4C51F22C482F2BCEEF5F (RuntimeObject* ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* String_Concat_m9E3155FB84015C823606188F53B47CB44C444991 (String_t* ___0_str0, String_t* ___1_str1, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void StringBuilder__ctor_m1D99713357DE05DAFA296633639DB55F8C30587D (StringBuilder_t* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR StringBuilder_t* StringBuilder_Append_m71228B30F05724CD2CD96D9611DCD61BFB96A6E1 (StringBuilder_t* __this, Il2CppChar ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR StringBuilder_t* StringBuilder_Append_m08904D74E0C78E5F36DCD9C9303BDD07886D9F7D (StringBuilder_t* __this, String_t* ___0_value, const RuntimeMethod* method) ;
inline bool ExpressionEvaluator_EvaluateTokens_TisDouble_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F_m791767867653D0CCE2BEFF83F336A41B5B3A718E (StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* ___0_tokens, double* ___1_value, int32_t ___2_index, int32_t ___3_count, const RuntimeMethod* method)
{
	return ((  bool (*) (StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248*, double*, int32_t, int32_t, const RuntimeMethod*))ExpressionEvaluator_EvaluateTokens_TisDouble_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F_m791767867653D0CCE2BEFF83F336A41B5B3A718E_gshared)(___0_tokens, ___1_value, ___2_index, ___3_count, method);
}
inline bool ExpressionEvaluator_EvaluateTokens_TisInt64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3_m7418F7A8835B2770EF83F1D52F2723897CD76DEB (StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* ___0_tokens, int64_t* ___1_value, int32_t ___2_index, int32_t ___3_count, const RuntimeMethod* method)
{
	return ((  bool (*) (StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248*, int64_t*, int32_t, int32_t, const RuntimeMethod*))ExpressionEvaluator_EvaluateTokens_TisInt64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3_m7418F7A8835B2770EF83F1D52F2723897CD76DEB_gshared)(___0_tokens, ___1_value, ___2_index, ___3_count, method);
}
inline bool ExpressionEvaluator_EvaluateTokens_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_mCFCF758DECB276DBCB0A8B83BAE195EF3B974780 (StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* ___0_tokens, uint64_t* ___1_value, int32_t ___2_index, int32_t ___3_count, const RuntimeMethod* method)
{
	return ((  bool (*) (StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248*, uint64_t*, int32_t, int32_t, const RuntimeMethod*))ExpressionEvaluator_EvaluateTokens_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_mCFCF758DECB276DBCB0A8B83BAE195EF3B974780_gshared)(___0_tokens, ___1_value, ___2_index, ___3_count, method);
}
inline int32_t FieldCodec_1_CalculateSizeWithTag_mAF91F403A614B09B2113343DEFB9F23E37528D79 (FieldCodec_1_t5E5853045CAC4F051697FDB8A12CC79D264D40D7* __this, RuntimeObject* ___0_value, const RuntimeMethod* method)
{
	return ((  int32_t (*) (FieldCodec_1_t5E5853045CAC4F051697FDB8A12CC79D264D40D7*, RuntimeObject*, const RuntimeMethod*))FieldCodec_1_CalculateSizeWithTag_mAF91F403A614B09B2113343DEFB9F23E37528D79_gshared)(__this, ___0_value, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t CodedOutputStream_ComputeLengthSize_mDD8A8B210E918ED0C32B22CB48BE98AA0FE85301 (int32_t ___0_length, const RuntimeMethod* method) ;
inline bool Dictionary_2_TryGetValue_m76D0309695A0582B3E29E97942ACD35DC4EFD128 (Dictionary_2_t954AEC357FE7190582B8255D4ACEF81F5E94A6A5* __this, Type_t* ___0_key, RuntimeObject** ___1_value, const RuntimeMethod* method)
{
	return ((  bool (*) (Dictionary_2_t954AEC357FE7190582B8255D4ACEF81F5E94A6A5*, Type_t*, RuntimeObject**, const RuntimeMethod*))Dictionary_2_TryGetValue_mD15380A4ED7CDEE99EA45881577D26BA9CE1B849_gshared)(__this, ___0_key, ___1_value, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162 (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* __this, String_t* ___0_message, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t ParseContext_ReadLength_m5574397F353C62DA04F0E0E5616C2159787C52E6_inline (ParseContext_tC04F8D72236E3ED9155AAD861769A3C56AEEB0EF* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t SegmentedBufferHelper_PushLimit_m13B57D290C3F6DE8D49B46CDEBA41496A8CC496A (ParserInternalState_t3044183736150999B222F94BFC5A875FA33EB36C* ___0_state, int32_t ___1_byteLimit, const RuntimeMethod* method) ;
inline RuntimeObject* FieldCodec_1_get_DefaultValue_m1F114731B3660936CE2D9CDCE526CB33FF0169A6_inline (FieldCodec_1_t5E5853045CAC4F051697FDB8A12CC79D264D40D7* __this, const RuntimeMethod* method)
{
	return ((  RuntimeObject* (*) (FieldCodec_1_t5E5853045CAC4F051697FDB8A12CC79D264D40D7*, const RuntimeMethod*))FieldCodec_1_get_DefaultValue_m1F114731B3660936CE2D9CDCE526CB33FF0169A6_gshared_inline)(__this, method);
}
inline uint32_t FieldCodec_1_get_Tag_mFD9919FD0E0A0E96F3BEC9FE3E6C7DA9194DF07E_inline (FieldCodec_1_t5E5853045CAC4F051697FDB8A12CC79D264D40D7* __this, const RuntimeMethod* method)
{
	return ((  uint32_t (*) (FieldCodec_1_t5E5853045CAC4F051697FDB8A12CC79D264D40D7*, const RuntimeMethod*))FieldCodec_1_get_Tag_mFD9919FD0E0A0E96F3BEC9FE3E6C7DA9194DF07E_gshared_inline)(__this, method);
}
inline RuntimeObject* FieldCodec_1_Read_mE413D0DC82F78AA938FEAA5EBF2BF72862E70DB0 (FieldCodec_1_t5E5853045CAC4F051697FDB8A12CC79D264D40D7* __this, ParseContext_tC04F8D72236E3ED9155AAD861769A3C56AEEB0EF* ___0_ctx, const RuntimeMethod* method)
{
	return ((  RuntimeObject* (*) (FieldCodec_1_t5E5853045CAC4F051697FDB8A12CC79D264D40D7*, ParseContext_tC04F8D72236E3ED9155AAD861769A3C56AEEB0EF*, const RuntimeMethod*))FieldCodec_1_Read_mE413D0DC82F78AA938FEAA5EBF2BF72862E70DB0_gshared)(__this, ___0_ctx, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ParsingPrimitivesMessages_SkipLastField_m8C3980E28CCE8DFA24D34951FE2248BE0253AE5A (ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D* ___0_buffer, ParserInternalState_t3044183736150999B222F94BFC5A875FA33EB36C* ___1_state, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint32_t ParseContext_ReadTag_m01B263948EC529915711371EE50F8EAEB484E265_inline (ParseContext_tC04F8D72236E3ED9155AAD861769A3C56AEEB0EF* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ParsingPrimitivesMessages_CheckReadEndOfStreamTag_m1A598174A7F6DCBF3E922FED7B5468CE8C4E9EB1 (ParserInternalState_t3044183736150999B222F94BFC5A875FA33EB36C* ___0_state, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SegmentedBufferHelper_PopLimit_m9A9E2621E7721E325174872FBA832F7B5F409CA3 (ParserInternalState_t3044183736150999B222F94BFC5A875FA33EB36C* ___0_state, int32_t ___1_oldLimit, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WriteContext_WriteLength_m5C0E4572780DDDAF32DF37BB7C9D590162FBDCC2 (WriteContext_tF80B3959AE2E6F9D5F8D447B35D859DA2ABD226D* __this, int32_t ___0_length, const RuntimeMethod* method) ;
inline void FieldCodec_1_WriteTagAndValue_mA4E442BBC368DD9685D6C30C692AD5130E9BAA85 (FieldCodec_1_t5E5853045CAC4F051697FDB8A12CC79D264D40D7* __this, WriteContext_tF80B3959AE2E6F9D5F8D447B35D859DA2ABD226D* ___0_ctx, RuntimeObject* ___1_value, const RuntimeMethod* method)
{
	((  void (*) (FieldCodec_1_t5E5853045CAC4F051697FDB8A12CC79D264D40D7*, WriteContext_tF80B3959AE2E6F9D5F8D447B35D859DA2ABD226D*, RuntimeObject*, const RuntimeMethod*))FieldCodec_1_WriteTagAndValue_mA4E442BBC368DD9685D6C30C692AD5130E9BAA85_gshared)(__this, ___0_ctx, ___1_value, method);
}
inline RuntimeObject* TypeUtility_CreateTypeConstructor_TisBounds_t367E830C64BBF235ED8C3B2F8CF6254FDCAD39C3_m16C827D0F6107B7998F6C99B57F7CC2F181E2198 (const RuntimeMethod* method)
{
	return ((  RuntimeObject* (*) (const RuntimeMethod*))TypeUtility_CreateTypeConstructor_TisBounds_t367E830C64BBF235ED8C3B2F8CF6254FDCAD39C3_m16C827D0F6107B7998F6C99B57F7CC2F181E2198_gshared)(method);
}
inline RuntimeObject* TypeUtility_CreateTypeConstructor_TisBoundsInt_t4E757DE5EFF9FCB42000F173360DDC63B5585485_m8F344250A2F9E6EE6DDBA6BA833BB36D0F272B66 (const RuntimeMethod* method)
{
	return ((  RuntimeObject* (*) (const RuntimeMethod*))TypeUtility_CreateTypeConstructor_TisBoundsInt_t4E757DE5EFF9FCB42000F173360DDC63B5585485_m8F344250A2F9E6EE6DDBA6BA833BB36D0F272B66_gshared)(method);
}
inline RuntimeObject* TypeUtility_CreateTypeConstructor_TisColor_tD001788D726C3A7F1379BEED0260B9591F440C1F_mBBCB804F367E06EA4D482F1B69165DD2B5BF38FF (const RuntimeMethod* method)
{
	return ((  RuntimeObject* (*) (const RuntimeMethod*))TypeUtility_CreateTypeConstructor_TisColor_tD001788D726C3A7F1379BEED0260B9591F440C1F_mBBCB804F367E06EA4D482F1B69165DD2B5BF38FF_gshared)(method);
}
inline RuntimeObject* TypeUtility_CreateTypeConstructor_TisRuntimeObject_m4E17F588B090C1DADAE2D986BDA407DECEAC020F (const RuntimeMethod* method)
{
	return ((  RuntimeObject* (*) (const RuntimeMethod*))TypeUtility_CreateTypeConstructor_TisRuntimeObject_m4E17F588B090C1DADAE2D986BDA407DECEAC020F_gshared)(method);
}
inline RuntimeObject* TypeUtility_CreateTypeConstructor_TisRect_tA04E0F8A1830E767F40FB27ECD8D309303571F0D_m2C5F5CF80D13B041768C7845C5AAEEC02BB683BA (const RuntimeMethod* method)
{
	return ((  RuntimeObject* (*) (const RuntimeMethod*))TypeUtility_CreateTypeConstructor_TisRect_tA04E0F8A1830E767F40FB27ECD8D309303571F0D_m2C5F5CF80D13B041768C7845C5AAEEC02BB683BA_gshared)(method);
}
inline RuntimeObject* TypeUtility_CreateTypeConstructor_TisRectInt_t1744D10E1063135DA9D574F95205B98DAC600CB8_mF6949D9EDD480E6666CD975C66487AAD6ABC7D11 (const RuntimeMethod* method)
{
	return ((  RuntimeObject* (*) (const RuntimeMethod*))TypeUtility_CreateTypeConstructor_TisRectInt_t1744D10E1063135DA9D574F95205B98DAC600CB8_mF6949D9EDD480E6666CD975C66487AAD6ABC7D11_gshared)(method);
}
inline RuntimeObject* TypeUtility_CreateTypeConstructor_TisVector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7_mE0C65F4221E48BB07F75856972A0CCDAE284AB9F (const RuntimeMethod* method)
{
	return ((  RuntimeObject* (*) (const RuntimeMethod*))TypeUtility_CreateTypeConstructor_TisVector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7_mE0C65F4221E48BB07F75856972A0CCDAE284AB9F_gshared)(method);
}
inline RuntimeObject* TypeUtility_CreateTypeConstructor_TisVector2Int_t69B2886EBAB732D9B880565E18E7568F3DE0CE6A_mC8EF710494C8986B279262C6C64947BE2C1DC55C (const RuntimeMethod* method)
{
	return ((  RuntimeObject* (*) (const RuntimeMethod*))TypeUtility_CreateTypeConstructor_TisVector2Int_t69B2886EBAB732D9B880565E18E7568F3DE0CE6A_mC8EF710494C8986B279262C6C64947BE2C1DC55C_gshared)(method);
}
inline RuntimeObject* TypeUtility_CreateTypeConstructor_TisVector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2_m1AB8BF0921C24186B3C43FC4341AAD2F6FE87C4D (const RuntimeMethod* method)
{
	return ((  RuntimeObject* (*) (const RuntimeMethod*))TypeUtility_CreateTypeConstructor_TisVector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2_m1AB8BF0921C24186B3C43FC4341AAD2F6FE87C4D_gshared)(method);
}
inline RuntimeObject* TypeUtility_CreateTypeConstructor_TisVector3Int_t65CB06F557251D18A37BD71F3655BA836A357376_mB00220519A80AA5ACE36B7DBA2E6A6CB796302AF (const RuntimeMethod* method)
{
	return ((  RuntimeObject* (*) (const RuntimeMethod*))TypeUtility_CreateTypeConstructor_TisVector3Int_t65CB06F557251D18A37BD71F3655BA836A357376_mB00220519A80AA5ACE36B7DBA2E6A6CB796302AF_gshared)(method);
}
inline RuntimeObject* TypeUtility_CreateTypeConstructor_TisVector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3_mED1DC338E5DB62F3E64F6272A9F12150DA5CC1B9 (const RuntimeMethod* method)
{
	return ((  RuntimeObject* (*) (const RuntimeMethod*))TypeUtility_CreateTypeConstructor_TisVector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3_mED1DC338E5DB62F3E64F6272A9F12150DA5CC1B9_gshared)(method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint32_t ParsingPrimitives_ParseRawVarint32_m12E76CAA773AAED8FDAF192EBFAF830E615798BF (ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D* ___0_buffer, ParserInternalState_t3044183736150999B222F94BFC5A875FA33EB36C* ___1_state, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint32_t ParsingPrimitives_ParseTag_mC3CDF9E540F71AEAB45BC4BAFAE69C8FB097DB64 (ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D* ___0_buffer, ParserInternalState_t3044183736150999B222F94BFC5A875FA33EB36C* ___1_state, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* _AndroidJNIHelper_GetSignature_TisChar_t521A6F19B456D956AF452D926C32709DC03D6B17_mD783834059E75BFC7A7FEB544B6ABA307E91B2C4_gshared (ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* ___0_args, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&StringBuilder_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Type_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral622F5FF68A93093A1D312703FF92713F8BF2C946);
		il2cpp_rgctx_method_init(method);
	}
	StringBuilder_t* V_0 = NULL;
	bool V_1 = false;
	String_t* V_2 = NULL;
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* V_3 = NULL;
	int32_t V_4 = 0;
	RuntimeObject* V_5 = NULL;
	int32_t G_B3_0 = 0;
	{
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_0 = ___0_args;
		if (!L_0)
		{
			goto IL_000b;
		}
	}
	{
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_1 = ___0_args;
		NullCheck(L_1);
		G_B3_0 = ((((int32_t)(((RuntimeArray*)L_1)->max_length)) == ((int32_t)0))? 1 : 0);
		goto IL_000c;
	}

IL_000b:
	{
		G_B3_0 = 1;
	}

IL_000c:
	{
		V_1 = (bool)G_B3_0;
		bool L_2 = V_1;
		if (!L_2)
		{
			goto IL_002c;
		}
	}
	{
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_3 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(method->rgctx_data, 0)) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_4;
		L_4 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_3, NULL);
		String_t* L_5;
		L_5 = _AndroidJNIHelper_GetSignature_m414A7A6B98FB5565075E4C51F22C482F2BCEEF5F((RuntimeObject*)L_4, NULL);
		String_t* L_6;
		L_6 = String_Concat_m9E3155FB84015C823606188F53B47CB44C444991(_stringLiteral622F5FF68A93093A1D312703FF92713F8BF2C946, L_5, NULL);
		V_2 = L_6;
		goto IL_008e;
	}

IL_002c:
	{
		StringBuilder_t* L_7 = (StringBuilder_t*)il2cpp_codegen_object_new(StringBuilder_t_il2cpp_TypeInfo_var);
		StringBuilder__ctor_m1D99713357DE05DAFA296633639DB55F8C30587D(L_7, NULL);
		V_0 = L_7;
		StringBuilder_t* L_8 = V_0;
		NullCheck(L_8);
		StringBuilder_t* L_9;
		L_9 = StringBuilder_Append_m71228B30F05724CD2CD96D9611DCD61BFB96A6E1(L_8, (Il2CppChar)((int32_t)40), NULL);
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_10 = ___0_args;
		V_3 = L_10;
		V_4 = 0;
		goto IL_005f;
	}

IL_0043:
	{
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_11 = V_3;
		int32_t L_12 = V_4;
		NullCheck(L_11);
		int32_t L_13 = L_12;
		RuntimeObject* L_14 = (L_11)->GetAt(static_cast<il2cpp_array_size_t>(L_13));
		V_5 = L_14;
		StringBuilder_t* L_15 = V_0;
		RuntimeObject* L_16 = V_5;
		String_t* L_17;
		L_17 = _AndroidJNIHelper_GetSignature_m414A7A6B98FB5565075E4C51F22C482F2BCEEF5F(L_16, NULL);
		NullCheck(L_15);
		StringBuilder_t* L_18;
		L_18 = StringBuilder_Append_m08904D74E0C78E5F36DCD9C9303BDD07886D9F7D(L_15, L_17, NULL);
		int32_t L_19 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_19, 1));
	}

IL_005f:
	{
		int32_t L_20 = V_4;
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_21 = V_3;
		NullCheck(L_21);
		if ((((int32_t)L_20) < ((int32_t)((int32_t)(((RuntimeArray*)L_21)->max_length)))))
		{
			goto IL_0043;
		}
	}
	{
		StringBuilder_t* L_22 = V_0;
		NullCheck(L_22);
		StringBuilder_t* L_23;
		L_23 = StringBuilder_Append_m71228B30F05724CD2CD96D9611DCD61BFB96A6E1(L_22, (Il2CppChar)((int32_t)41), NULL);
		StringBuilder_t* L_24 = V_0;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_25 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(method->rgctx_data, 0)) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_26;
		L_26 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_25, NULL);
		String_t* L_27;
		L_27 = _AndroidJNIHelper_GetSignature_m414A7A6B98FB5565075E4C51F22C482F2BCEEF5F((RuntimeObject*)L_26, NULL);
		NullCheck(L_24);
		StringBuilder_t* L_28;
		L_28 = StringBuilder_Append_m08904D74E0C78E5F36DCD9C9303BDD07886D9F7D(L_24, L_27, NULL);
		StringBuilder_t* L_29 = V_0;
		NullCheck((RuntimeObject*)L_29);
		String_t* L_30;
		L_30 = VirtualFuncInvoker0< String_t* >::Invoke(3, (RuntimeObject*)L_29);
		V_2 = L_30;
		goto IL_008e;
	}

IL_008e:
	{
		String_t* L_31 = V_2;
		return L_31;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* _AndroidJNIHelper_GetSignature_TisDouble_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F_m74C4D07DCE96BE5E61ED2AAED270DF7469C5F341_gshared (ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* ___0_args, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&StringBuilder_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Type_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral622F5FF68A93093A1D312703FF92713F8BF2C946);
		il2cpp_rgctx_method_init(method);
	}
	StringBuilder_t* V_0 = NULL;
	bool V_1 = false;
	String_t* V_2 = NULL;
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* V_3 = NULL;
	int32_t V_4 = 0;
	RuntimeObject* V_5 = NULL;
	int32_t G_B3_0 = 0;
	{
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_0 = ___0_args;
		if (!L_0)
		{
			goto IL_000b;
		}
	}
	{
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_1 = ___0_args;
		NullCheck(L_1);
		G_B3_0 = ((((int32_t)(((RuntimeArray*)L_1)->max_length)) == ((int32_t)0))? 1 : 0);
		goto IL_000c;
	}

IL_000b:
	{
		G_B3_0 = 1;
	}

IL_000c:
	{
		V_1 = (bool)G_B3_0;
		bool L_2 = V_1;
		if (!L_2)
		{
			goto IL_002c;
		}
	}
	{
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_3 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(method->rgctx_data, 0)) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_4;
		L_4 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_3, NULL);
		String_t* L_5;
		L_5 = _AndroidJNIHelper_GetSignature_m414A7A6B98FB5565075E4C51F22C482F2BCEEF5F((RuntimeObject*)L_4, NULL);
		String_t* L_6;
		L_6 = String_Concat_m9E3155FB84015C823606188F53B47CB44C444991(_stringLiteral622F5FF68A93093A1D312703FF92713F8BF2C946, L_5, NULL);
		V_2 = L_6;
		goto IL_008e;
	}

IL_002c:
	{
		StringBuilder_t* L_7 = (StringBuilder_t*)il2cpp_codegen_object_new(StringBuilder_t_il2cpp_TypeInfo_var);
		StringBuilder__ctor_m1D99713357DE05DAFA296633639DB55F8C30587D(L_7, NULL);
		V_0 = L_7;
		StringBuilder_t* L_8 = V_0;
		NullCheck(L_8);
		StringBuilder_t* L_9;
		L_9 = StringBuilder_Append_m71228B30F05724CD2CD96D9611DCD61BFB96A6E1(L_8, (Il2CppChar)((int32_t)40), NULL);
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_10 = ___0_args;
		V_3 = L_10;
		V_4 = 0;
		goto IL_005f;
	}

IL_0043:
	{
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_11 = V_3;
		int32_t L_12 = V_4;
		NullCheck(L_11);
		int32_t L_13 = L_12;
		RuntimeObject* L_14 = (L_11)->GetAt(static_cast<il2cpp_array_size_t>(L_13));
		V_5 = L_14;
		StringBuilder_t* L_15 = V_0;
		RuntimeObject* L_16 = V_5;
		String_t* L_17;
		L_17 = _AndroidJNIHelper_GetSignature_m414A7A6B98FB5565075E4C51F22C482F2BCEEF5F(L_16, NULL);
		NullCheck(L_15);
		StringBuilder_t* L_18;
		L_18 = StringBuilder_Append_m08904D74E0C78E5F36DCD9C9303BDD07886D9F7D(L_15, L_17, NULL);
		int32_t L_19 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_19, 1));
	}

IL_005f:
	{
		int32_t L_20 = V_4;
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_21 = V_3;
		NullCheck(L_21);
		if ((((int32_t)L_20) < ((int32_t)((int32_t)(((RuntimeArray*)L_21)->max_length)))))
		{
			goto IL_0043;
		}
	}
	{
		StringBuilder_t* L_22 = V_0;
		NullCheck(L_22);
		StringBuilder_t* L_23;
		L_23 = StringBuilder_Append_m71228B30F05724CD2CD96D9611DCD61BFB96A6E1(L_22, (Il2CppChar)((int32_t)41), NULL);
		StringBuilder_t* L_24 = V_0;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_25 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(method->rgctx_data, 0)) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_26;
		L_26 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_25, NULL);
		String_t* L_27;
		L_27 = _AndroidJNIHelper_GetSignature_m414A7A6B98FB5565075E4C51F22C482F2BCEEF5F((RuntimeObject*)L_26, NULL);
		NullCheck(L_24);
		StringBuilder_t* L_28;
		L_28 = StringBuilder_Append_m08904D74E0C78E5F36DCD9C9303BDD07886D9F7D(L_24, L_27, NULL);
		StringBuilder_t* L_29 = V_0;
		NullCheck((RuntimeObject*)L_29);
		String_t* L_30;
		L_30 = VirtualFuncInvoker0< String_t* >::Invoke(3, (RuntimeObject*)L_29);
		V_2 = L_30;
		goto IL_008e;
	}

IL_008e:
	{
		String_t* L_31 = V_2;
		return L_31;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* _AndroidJNIHelper_GetSignature_TisInt16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_m1E079B67FDC93E1BBE5C29D9C2BC09338DA0A5AA_gshared (ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* ___0_args, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&StringBuilder_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Type_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral622F5FF68A93093A1D312703FF92713F8BF2C946);
		il2cpp_rgctx_method_init(method);
	}
	StringBuilder_t* V_0 = NULL;
	bool V_1 = false;
	String_t* V_2 = NULL;
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* V_3 = NULL;
	int32_t V_4 = 0;
	RuntimeObject* V_5 = NULL;
	int32_t G_B3_0 = 0;
	{
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_0 = ___0_args;
		if (!L_0)
		{
			goto IL_000b;
		}
	}
	{
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_1 = ___0_args;
		NullCheck(L_1);
		G_B3_0 = ((((int32_t)(((RuntimeArray*)L_1)->max_length)) == ((int32_t)0))? 1 : 0);
		goto IL_000c;
	}

IL_000b:
	{
		G_B3_0 = 1;
	}

IL_000c:
	{
		V_1 = (bool)G_B3_0;
		bool L_2 = V_1;
		if (!L_2)
		{
			goto IL_002c;
		}
	}
	{
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_3 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(method->rgctx_data, 0)) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_4;
		L_4 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_3, NULL);
		String_t* L_5;
		L_5 = _AndroidJNIHelper_GetSignature_m414A7A6B98FB5565075E4C51F22C482F2BCEEF5F((RuntimeObject*)L_4, NULL);
		String_t* L_6;
		L_6 = String_Concat_m9E3155FB84015C823606188F53B47CB44C444991(_stringLiteral622F5FF68A93093A1D312703FF92713F8BF2C946, L_5, NULL);
		V_2 = L_6;
		goto IL_008e;
	}

IL_002c:
	{
		StringBuilder_t* L_7 = (StringBuilder_t*)il2cpp_codegen_object_new(StringBuilder_t_il2cpp_TypeInfo_var);
		StringBuilder__ctor_m1D99713357DE05DAFA296633639DB55F8C30587D(L_7, NULL);
		V_0 = L_7;
		StringBuilder_t* L_8 = V_0;
		NullCheck(L_8);
		StringBuilder_t* L_9;
		L_9 = StringBuilder_Append_m71228B30F05724CD2CD96D9611DCD61BFB96A6E1(L_8, (Il2CppChar)((int32_t)40), NULL);
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_10 = ___0_args;
		V_3 = L_10;
		V_4 = 0;
		goto IL_005f;
	}

IL_0043:
	{
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_11 = V_3;
		int32_t L_12 = V_4;
		NullCheck(L_11);
		int32_t L_13 = L_12;
		RuntimeObject* L_14 = (L_11)->GetAt(static_cast<il2cpp_array_size_t>(L_13));
		V_5 = L_14;
		StringBuilder_t* L_15 = V_0;
		RuntimeObject* L_16 = V_5;
		String_t* L_17;
		L_17 = _AndroidJNIHelper_GetSignature_m414A7A6B98FB5565075E4C51F22C482F2BCEEF5F(L_16, NULL);
		NullCheck(L_15);
		StringBuilder_t* L_18;
		L_18 = StringBuilder_Append_m08904D74E0C78E5F36DCD9C9303BDD07886D9F7D(L_15, L_17, NULL);
		int32_t L_19 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_19, 1));
	}

IL_005f:
	{
		int32_t L_20 = V_4;
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_21 = V_3;
		NullCheck(L_21);
		if ((((int32_t)L_20) < ((int32_t)((int32_t)(((RuntimeArray*)L_21)->max_length)))))
		{
			goto IL_0043;
		}
	}
	{
		StringBuilder_t* L_22 = V_0;
		NullCheck(L_22);
		StringBuilder_t* L_23;
		L_23 = StringBuilder_Append_m71228B30F05724CD2CD96D9611DCD61BFB96A6E1(L_22, (Il2CppChar)((int32_t)41), NULL);
		StringBuilder_t* L_24 = V_0;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_25 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(method->rgctx_data, 0)) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_26;
		L_26 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_25, NULL);
		String_t* L_27;
		L_27 = _AndroidJNIHelper_GetSignature_m414A7A6B98FB5565075E4C51F22C482F2BCEEF5F((RuntimeObject*)L_26, NULL);
		NullCheck(L_24);
		StringBuilder_t* L_28;
		L_28 = StringBuilder_Append_m08904D74E0C78E5F36DCD9C9303BDD07886D9F7D(L_24, L_27, NULL);
		StringBuilder_t* L_29 = V_0;
		NullCheck((RuntimeObject*)L_29);
		String_t* L_30;
		L_30 = VirtualFuncInvoker0< String_t* >::Invoke(3, (RuntimeObject*)L_29);
		V_2 = L_30;
		goto IL_008e;
	}

IL_008e:
	{
		String_t* L_31 = V_2;
		return L_31;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* _AndroidJNIHelper_GetSignature_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mA85CEF9411BD97B51F86CC460B32C46C2B873B12_gshared (ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* ___0_args, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&StringBuilder_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Type_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral622F5FF68A93093A1D312703FF92713F8BF2C946);
		il2cpp_rgctx_method_init(method);
	}
	StringBuilder_t* V_0 = NULL;
	bool V_1 = false;
	String_t* V_2 = NULL;
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* V_3 = NULL;
	int32_t V_4 = 0;
	RuntimeObject* V_5 = NULL;
	int32_t G_B3_0 = 0;
	{
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_0 = ___0_args;
		if (!L_0)
		{
			goto IL_000b;
		}
	}
	{
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_1 = ___0_args;
		NullCheck(L_1);
		G_B3_0 = ((((int32_t)(((RuntimeArray*)L_1)->max_length)) == ((int32_t)0))? 1 : 0);
		goto IL_000c;
	}

IL_000b:
	{
		G_B3_0 = 1;
	}

IL_000c:
	{
		V_1 = (bool)G_B3_0;
		bool L_2 = V_1;
		if (!L_2)
		{
			goto IL_002c;
		}
	}
	{
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_3 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(method->rgctx_data, 0)) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_4;
		L_4 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_3, NULL);
		String_t* L_5;
		L_5 = _AndroidJNIHelper_GetSignature_m414A7A6B98FB5565075E4C51F22C482F2BCEEF5F((RuntimeObject*)L_4, NULL);
		String_t* L_6;
		L_6 = String_Concat_m9E3155FB84015C823606188F53B47CB44C444991(_stringLiteral622F5FF68A93093A1D312703FF92713F8BF2C946, L_5, NULL);
		V_2 = L_6;
		goto IL_008e;
	}

IL_002c:
	{
		StringBuilder_t* L_7 = (StringBuilder_t*)il2cpp_codegen_object_new(StringBuilder_t_il2cpp_TypeInfo_var);
		StringBuilder__ctor_m1D99713357DE05DAFA296633639DB55F8C30587D(L_7, NULL);
		V_0 = L_7;
		StringBuilder_t* L_8 = V_0;
		NullCheck(L_8);
		StringBuilder_t* L_9;
		L_9 = StringBuilder_Append_m71228B30F05724CD2CD96D9611DCD61BFB96A6E1(L_8, (Il2CppChar)((int32_t)40), NULL);
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_10 = ___0_args;
		V_3 = L_10;
		V_4 = 0;
		goto IL_005f;
	}

IL_0043:
	{
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_11 = V_3;
		int32_t L_12 = V_4;
		NullCheck(L_11);
		int32_t L_13 = L_12;
		RuntimeObject* L_14 = (L_11)->GetAt(static_cast<il2cpp_array_size_t>(L_13));
		V_5 = L_14;
		StringBuilder_t* L_15 = V_0;
		RuntimeObject* L_16 = V_5;
		String_t* L_17;
		L_17 = _AndroidJNIHelper_GetSignature_m414A7A6B98FB5565075E4C51F22C482F2BCEEF5F(L_16, NULL);
		NullCheck(L_15);
		StringBuilder_t* L_18;
		L_18 = StringBuilder_Append_m08904D74E0C78E5F36DCD9C9303BDD07886D9F7D(L_15, L_17, NULL);
		int32_t L_19 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_19, 1));
	}

IL_005f:
	{
		int32_t L_20 = V_4;
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_21 = V_3;
		NullCheck(L_21);
		if ((((int32_t)L_20) < ((int32_t)((int32_t)(((RuntimeArray*)L_21)->max_length)))))
		{
			goto IL_0043;
		}
	}
	{
		StringBuilder_t* L_22 = V_0;
		NullCheck(L_22);
		StringBuilder_t* L_23;
		L_23 = StringBuilder_Append_m71228B30F05724CD2CD96D9611DCD61BFB96A6E1(L_22, (Il2CppChar)((int32_t)41), NULL);
		StringBuilder_t* L_24 = V_0;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_25 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(method->rgctx_data, 0)) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_26;
		L_26 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_25, NULL);
		String_t* L_27;
		L_27 = _AndroidJNIHelper_GetSignature_m414A7A6B98FB5565075E4C51F22C482F2BCEEF5F((RuntimeObject*)L_26, NULL);
		NullCheck(L_24);
		StringBuilder_t* L_28;
		L_28 = StringBuilder_Append_m08904D74E0C78E5F36DCD9C9303BDD07886D9F7D(L_24, L_27, NULL);
		StringBuilder_t* L_29 = V_0;
		NullCheck((RuntimeObject*)L_29);
		String_t* L_30;
		L_30 = VirtualFuncInvoker0< String_t* >::Invoke(3, (RuntimeObject*)L_29);
		V_2 = L_30;
		goto IL_008e;
	}

IL_008e:
	{
		String_t* L_31 = V_2;
		return L_31;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* _AndroidJNIHelper_GetSignature_TisInt64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3_m847042ADF26044DDB60469E1C3477EBBB1B55E11_gshared (ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* ___0_args, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&StringBuilder_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Type_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral622F5FF68A93093A1D312703FF92713F8BF2C946);
		il2cpp_rgctx_method_init(method);
	}
	StringBuilder_t* V_0 = NULL;
	bool V_1 = false;
	String_t* V_2 = NULL;
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* V_3 = NULL;
	int32_t V_4 = 0;
	RuntimeObject* V_5 = NULL;
	int32_t G_B3_0 = 0;
	{
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_0 = ___0_args;
		if (!L_0)
		{
			goto IL_000b;
		}
	}
	{
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_1 = ___0_args;
		NullCheck(L_1);
		G_B3_0 = ((((int32_t)(((RuntimeArray*)L_1)->max_length)) == ((int32_t)0))? 1 : 0);
		goto IL_000c;
	}

IL_000b:
	{
		G_B3_0 = 1;
	}

IL_000c:
	{
		V_1 = (bool)G_B3_0;
		bool L_2 = V_1;
		if (!L_2)
		{
			goto IL_002c;
		}
	}
	{
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_3 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(method->rgctx_data, 0)) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_4;
		L_4 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_3, NULL);
		String_t* L_5;
		L_5 = _AndroidJNIHelper_GetSignature_m414A7A6B98FB5565075E4C51F22C482F2BCEEF5F((RuntimeObject*)L_4, NULL);
		String_t* L_6;
		L_6 = String_Concat_m9E3155FB84015C823606188F53B47CB44C444991(_stringLiteral622F5FF68A93093A1D312703FF92713F8BF2C946, L_5, NULL);
		V_2 = L_6;
		goto IL_008e;
	}

IL_002c:
	{
		StringBuilder_t* L_7 = (StringBuilder_t*)il2cpp_codegen_object_new(StringBuilder_t_il2cpp_TypeInfo_var);
		StringBuilder__ctor_m1D99713357DE05DAFA296633639DB55F8C30587D(L_7, NULL);
		V_0 = L_7;
		StringBuilder_t* L_8 = V_0;
		NullCheck(L_8);
		StringBuilder_t* L_9;
		L_9 = StringBuilder_Append_m71228B30F05724CD2CD96D9611DCD61BFB96A6E1(L_8, (Il2CppChar)((int32_t)40), NULL);
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_10 = ___0_args;
		V_3 = L_10;
		V_4 = 0;
		goto IL_005f;
	}

IL_0043:
	{
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_11 = V_3;
		int32_t L_12 = V_4;
		NullCheck(L_11);
		int32_t L_13 = L_12;
		RuntimeObject* L_14 = (L_11)->GetAt(static_cast<il2cpp_array_size_t>(L_13));
		V_5 = L_14;
		StringBuilder_t* L_15 = V_0;
		RuntimeObject* L_16 = V_5;
		String_t* L_17;
		L_17 = _AndroidJNIHelper_GetSignature_m414A7A6B98FB5565075E4C51F22C482F2BCEEF5F(L_16, NULL);
		NullCheck(L_15);
		StringBuilder_t* L_18;
		L_18 = StringBuilder_Append_m08904D74E0C78E5F36DCD9C9303BDD07886D9F7D(L_15, L_17, NULL);
		int32_t L_19 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_19, 1));
	}

IL_005f:
	{
		int32_t L_20 = V_4;
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_21 = V_3;
		NullCheck(L_21);
		if ((((int32_t)L_20) < ((int32_t)((int32_t)(((RuntimeArray*)L_21)->max_length)))))
		{
			goto IL_0043;
		}
	}
	{
		StringBuilder_t* L_22 = V_0;
		NullCheck(L_22);
		StringBuilder_t* L_23;
		L_23 = StringBuilder_Append_m71228B30F05724CD2CD96D9611DCD61BFB96A6E1(L_22, (Il2CppChar)((int32_t)41), NULL);
		StringBuilder_t* L_24 = V_0;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_25 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(method->rgctx_data, 0)) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_26;
		L_26 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_25, NULL);
		String_t* L_27;
		L_27 = _AndroidJNIHelper_GetSignature_m414A7A6B98FB5565075E4C51F22C482F2BCEEF5F((RuntimeObject*)L_26, NULL);
		NullCheck(L_24);
		StringBuilder_t* L_28;
		L_28 = StringBuilder_Append_m08904D74E0C78E5F36DCD9C9303BDD07886D9F7D(L_24, L_27, NULL);
		StringBuilder_t* L_29 = V_0;
		NullCheck((RuntimeObject*)L_29);
		String_t* L_30;
		L_30 = VirtualFuncInvoker0< String_t* >::Invoke(3, (RuntimeObject*)L_29);
		V_2 = L_30;
		goto IL_008e;
	}

IL_008e:
	{
		String_t* L_31 = V_2;
		return L_31;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* _AndroidJNIHelper_GetSignature_TisRuntimeObject_m7CC50A493D0C6897ECB2692A7CEFB3A2CD3655A5_gshared (ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* ___0_args, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&StringBuilder_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Type_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral622F5FF68A93093A1D312703FF92713F8BF2C946);
		il2cpp_rgctx_method_init(method);
	}
	StringBuilder_t* V_0 = NULL;
	bool V_1 = false;
	String_t* V_2 = NULL;
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* V_3 = NULL;
	int32_t V_4 = 0;
	RuntimeObject* V_5 = NULL;
	int32_t G_B3_0 = 0;
	{
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_0 = ___0_args;
		if (!L_0)
		{
			goto IL_000b;
		}
	}
	{
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_1 = ___0_args;
		NullCheck(L_1);
		G_B3_0 = ((((int32_t)(((RuntimeArray*)L_1)->max_length)) == ((int32_t)0))? 1 : 0);
		goto IL_000c;
	}

IL_000b:
	{
		G_B3_0 = 1;
	}

IL_000c:
	{
		V_1 = (bool)G_B3_0;
		bool L_2 = V_1;
		if (!L_2)
		{
			goto IL_002c;
		}
	}
	{
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_3 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(method->rgctx_data, 0)) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_4;
		L_4 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_3, NULL);
		String_t* L_5;
		L_5 = _AndroidJNIHelper_GetSignature_m414A7A6B98FB5565075E4C51F22C482F2BCEEF5F((RuntimeObject*)L_4, NULL);
		String_t* L_6;
		L_6 = String_Concat_m9E3155FB84015C823606188F53B47CB44C444991(_stringLiteral622F5FF68A93093A1D312703FF92713F8BF2C946, L_5, NULL);
		V_2 = L_6;
		goto IL_008e;
	}

IL_002c:
	{
		StringBuilder_t* L_7 = (StringBuilder_t*)il2cpp_codegen_object_new(StringBuilder_t_il2cpp_TypeInfo_var);
		StringBuilder__ctor_m1D99713357DE05DAFA296633639DB55F8C30587D(L_7, NULL);
		V_0 = L_7;
		StringBuilder_t* L_8 = V_0;
		NullCheck(L_8);
		StringBuilder_t* L_9;
		L_9 = StringBuilder_Append_m71228B30F05724CD2CD96D9611DCD61BFB96A6E1(L_8, (Il2CppChar)((int32_t)40), NULL);
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_10 = ___0_args;
		V_3 = L_10;
		V_4 = 0;
		goto IL_005f;
	}

IL_0043:
	{
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_11 = V_3;
		int32_t L_12 = V_4;
		NullCheck(L_11);
		int32_t L_13 = L_12;
		RuntimeObject* L_14 = (L_11)->GetAt(static_cast<il2cpp_array_size_t>(L_13));
		V_5 = L_14;
		StringBuilder_t* L_15 = V_0;
		RuntimeObject* L_16 = V_5;
		String_t* L_17;
		L_17 = _AndroidJNIHelper_GetSignature_m414A7A6B98FB5565075E4C51F22C482F2BCEEF5F(L_16, NULL);
		NullCheck(L_15);
		StringBuilder_t* L_18;
		L_18 = StringBuilder_Append_m08904D74E0C78E5F36DCD9C9303BDD07886D9F7D(L_15, L_17, NULL);
		int32_t L_19 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_19, 1));
	}

IL_005f:
	{
		int32_t L_20 = V_4;
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_21 = V_3;
		NullCheck(L_21);
		if ((((int32_t)L_20) < ((int32_t)((int32_t)(((RuntimeArray*)L_21)->max_length)))))
		{
			goto IL_0043;
		}
	}
	{
		StringBuilder_t* L_22 = V_0;
		NullCheck(L_22);
		StringBuilder_t* L_23;
		L_23 = StringBuilder_Append_m71228B30F05724CD2CD96D9611DCD61BFB96A6E1(L_22, (Il2CppChar)((int32_t)41), NULL);
		StringBuilder_t* L_24 = V_0;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_25 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(method->rgctx_data, 0)) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_26;
		L_26 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_25, NULL);
		String_t* L_27;
		L_27 = _AndroidJNIHelper_GetSignature_m414A7A6B98FB5565075E4C51F22C482F2BCEEF5F((RuntimeObject*)L_26, NULL);
		NullCheck(L_24);
		StringBuilder_t* L_28;
		L_28 = StringBuilder_Append_m08904D74E0C78E5F36DCD9C9303BDD07886D9F7D(L_24, L_27, NULL);
		StringBuilder_t* L_29 = V_0;
		NullCheck((RuntimeObject*)L_29);
		String_t* L_30;
		L_30 = VirtualFuncInvoker0< String_t* >::Invoke(3, (RuntimeObject*)L_29);
		V_2 = L_30;
		goto IL_008e;
	}

IL_008e:
	{
		String_t* L_31 = V_2;
		return L_31;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* _AndroidJNIHelper_GetSignature_TisSByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_mEAD40CF5E1A04E27AE3991DAB10ABB9EC6F37FBB_gshared (ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* ___0_args, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&StringBuilder_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Type_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral622F5FF68A93093A1D312703FF92713F8BF2C946);
		il2cpp_rgctx_method_init(method);
	}
	StringBuilder_t* V_0 = NULL;
	bool V_1 = false;
	String_t* V_2 = NULL;
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* V_3 = NULL;
	int32_t V_4 = 0;
	RuntimeObject* V_5 = NULL;
	int32_t G_B3_0 = 0;
	{
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_0 = ___0_args;
		if (!L_0)
		{
			goto IL_000b;
		}
	}
	{
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_1 = ___0_args;
		NullCheck(L_1);
		G_B3_0 = ((((int32_t)(((RuntimeArray*)L_1)->max_length)) == ((int32_t)0))? 1 : 0);
		goto IL_000c;
	}

IL_000b:
	{
		G_B3_0 = 1;
	}

IL_000c:
	{
		V_1 = (bool)G_B3_0;
		bool L_2 = V_1;
		if (!L_2)
		{
			goto IL_002c;
		}
	}
	{
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_3 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(method->rgctx_data, 0)) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_4;
		L_4 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_3, NULL);
		String_t* L_5;
		L_5 = _AndroidJNIHelper_GetSignature_m414A7A6B98FB5565075E4C51F22C482F2BCEEF5F((RuntimeObject*)L_4, NULL);
		String_t* L_6;
		L_6 = String_Concat_m9E3155FB84015C823606188F53B47CB44C444991(_stringLiteral622F5FF68A93093A1D312703FF92713F8BF2C946, L_5, NULL);
		V_2 = L_6;
		goto IL_008e;
	}

IL_002c:
	{
		StringBuilder_t* L_7 = (StringBuilder_t*)il2cpp_codegen_object_new(StringBuilder_t_il2cpp_TypeInfo_var);
		StringBuilder__ctor_m1D99713357DE05DAFA296633639DB55F8C30587D(L_7, NULL);
		V_0 = L_7;
		StringBuilder_t* L_8 = V_0;
		NullCheck(L_8);
		StringBuilder_t* L_9;
		L_9 = StringBuilder_Append_m71228B30F05724CD2CD96D9611DCD61BFB96A6E1(L_8, (Il2CppChar)((int32_t)40), NULL);
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_10 = ___0_args;
		V_3 = L_10;
		V_4 = 0;
		goto IL_005f;
	}

IL_0043:
	{
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_11 = V_3;
		int32_t L_12 = V_4;
		NullCheck(L_11);
		int32_t L_13 = L_12;
		RuntimeObject* L_14 = (L_11)->GetAt(static_cast<il2cpp_array_size_t>(L_13));
		V_5 = L_14;
		StringBuilder_t* L_15 = V_0;
		RuntimeObject* L_16 = V_5;
		String_t* L_17;
		L_17 = _AndroidJNIHelper_GetSignature_m414A7A6B98FB5565075E4C51F22C482F2BCEEF5F(L_16, NULL);
		NullCheck(L_15);
		StringBuilder_t* L_18;
		L_18 = StringBuilder_Append_m08904D74E0C78E5F36DCD9C9303BDD07886D9F7D(L_15, L_17, NULL);
		int32_t L_19 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_19, 1));
	}

IL_005f:
	{
		int32_t L_20 = V_4;
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_21 = V_3;
		NullCheck(L_21);
		if ((((int32_t)L_20) < ((int32_t)((int32_t)(((RuntimeArray*)L_21)->max_length)))))
		{
			goto IL_0043;
		}
	}
	{
		StringBuilder_t* L_22 = V_0;
		NullCheck(L_22);
		StringBuilder_t* L_23;
		L_23 = StringBuilder_Append_m71228B30F05724CD2CD96D9611DCD61BFB96A6E1(L_22, (Il2CppChar)((int32_t)41), NULL);
		StringBuilder_t* L_24 = V_0;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_25 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(method->rgctx_data, 0)) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_26;
		L_26 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_25, NULL);
		String_t* L_27;
		L_27 = _AndroidJNIHelper_GetSignature_m414A7A6B98FB5565075E4C51F22C482F2BCEEF5F((RuntimeObject*)L_26, NULL);
		NullCheck(L_24);
		StringBuilder_t* L_28;
		L_28 = StringBuilder_Append_m08904D74E0C78E5F36DCD9C9303BDD07886D9F7D(L_24, L_27, NULL);
		StringBuilder_t* L_29 = V_0;
		NullCheck((RuntimeObject*)L_29);
		String_t* L_30;
		L_30 = VirtualFuncInvoker0< String_t* >::Invoke(3, (RuntimeObject*)L_29);
		V_2 = L_30;
		goto IL_008e;
	}

IL_008e:
	{
		String_t* L_31 = V_2;
		return L_31;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* _AndroidJNIHelper_GetSignature_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_mDD367BE518367698F0093E97FCF201D89B5790CB_gshared (ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* ___0_args, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&StringBuilder_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Type_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral622F5FF68A93093A1D312703FF92713F8BF2C946);
		il2cpp_rgctx_method_init(method);
	}
	StringBuilder_t* V_0 = NULL;
	bool V_1 = false;
	String_t* V_2 = NULL;
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* V_3 = NULL;
	int32_t V_4 = 0;
	RuntimeObject* V_5 = NULL;
	int32_t G_B3_0 = 0;
	{
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_0 = ___0_args;
		if (!L_0)
		{
			goto IL_000b;
		}
	}
	{
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_1 = ___0_args;
		NullCheck(L_1);
		G_B3_0 = ((((int32_t)(((RuntimeArray*)L_1)->max_length)) == ((int32_t)0))? 1 : 0);
		goto IL_000c;
	}

IL_000b:
	{
		G_B3_0 = 1;
	}

IL_000c:
	{
		V_1 = (bool)G_B3_0;
		bool L_2 = V_1;
		if (!L_2)
		{
			goto IL_002c;
		}
	}
	{
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_3 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(method->rgctx_data, 0)) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_4;
		L_4 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_3, NULL);
		String_t* L_5;
		L_5 = _AndroidJNIHelper_GetSignature_m414A7A6B98FB5565075E4C51F22C482F2BCEEF5F((RuntimeObject*)L_4, NULL);
		String_t* L_6;
		L_6 = String_Concat_m9E3155FB84015C823606188F53B47CB44C444991(_stringLiteral622F5FF68A93093A1D312703FF92713F8BF2C946, L_5, NULL);
		V_2 = L_6;
		goto IL_008e;
	}

IL_002c:
	{
		StringBuilder_t* L_7 = (StringBuilder_t*)il2cpp_codegen_object_new(StringBuilder_t_il2cpp_TypeInfo_var);
		StringBuilder__ctor_m1D99713357DE05DAFA296633639DB55F8C30587D(L_7, NULL);
		V_0 = L_7;
		StringBuilder_t* L_8 = V_0;
		NullCheck(L_8);
		StringBuilder_t* L_9;
		L_9 = StringBuilder_Append_m71228B30F05724CD2CD96D9611DCD61BFB96A6E1(L_8, (Il2CppChar)((int32_t)40), NULL);
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_10 = ___0_args;
		V_3 = L_10;
		V_4 = 0;
		goto IL_005f;
	}

IL_0043:
	{
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_11 = V_3;
		int32_t L_12 = V_4;
		NullCheck(L_11);
		int32_t L_13 = L_12;
		RuntimeObject* L_14 = (L_11)->GetAt(static_cast<il2cpp_array_size_t>(L_13));
		V_5 = L_14;
		StringBuilder_t* L_15 = V_0;
		RuntimeObject* L_16 = V_5;
		String_t* L_17;
		L_17 = _AndroidJNIHelper_GetSignature_m414A7A6B98FB5565075E4C51F22C482F2BCEEF5F(L_16, NULL);
		NullCheck(L_15);
		StringBuilder_t* L_18;
		L_18 = StringBuilder_Append_m08904D74E0C78E5F36DCD9C9303BDD07886D9F7D(L_15, L_17, NULL);
		int32_t L_19 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_19, 1));
	}

IL_005f:
	{
		int32_t L_20 = V_4;
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_21 = V_3;
		NullCheck(L_21);
		if ((((int32_t)L_20) < ((int32_t)((int32_t)(((RuntimeArray*)L_21)->max_length)))))
		{
			goto IL_0043;
		}
	}
	{
		StringBuilder_t* L_22 = V_0;
		NullCheck(L_22);
		StringBuilder_t* L_23;
		L_23 = StringBuilder_Append_m71228B30F05724CD2CD96D9611DCD61BFB96A6E1(L_22, (Il2CppChar)((int32_t)41), NULL);
		StringBuilder_t* L_24 = V_0;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_25 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(method->rgctx_data, 0)) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_26;
		L_26 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_25, NULL);
		String_t* L_27;
		L_27 = _AndroidJNIHelper_GetSignature_m414A7A6B98FB5565075E4C51F22C482F2BCEEF5F((RuntimeObject*)L_26, NULL);
		NullCheck(L_24);
		StringBuilder_t* L_28;
		L_28 = StringBuilder_Append_m08904D74E0C78E5F36DCD9C9303BDD07886D9F7D(L_24, L_27, NULL);
		StringBuilder_t* L_29 = V_0;
		NullCheck((RuntimeObject*)L_29);
		String_t* L_30;
		L_30 = VirtualFuncInvoker0< String_t* >::Invoke(3, (RuntimeObject*)L_29);
		V_2 = L_30;
		goto IL_008e;
	}

IL_008e:
	{
		String_t* L_31 = V_2;
		return L_31;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* _AndroidJNIHelper_GetSignature_TisIl2CppFullySharedGenericAny_m5BFF8BF215EBBD2B94DB67B384DAB97E221FA134_gshared (ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* ___0_args, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&StringBuilder_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Type_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral622F5FF68A93093A1D312703FF92713F8BF2C946);
		il2cpp_rgctx_method_init(method);
	}
	StringBuilder_t* V_0 = NULL;
	bool V_1 = false;
	String_t* V_2 = NULL;
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* V_3 = NULL;
	int32_t V_4 = 0;
	RuntimeObject* V_5 = NULL;
	int32_t G_B3_0 = 0;
	{
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_0 = ___0_args;
		if (!L_0)
		{
			goto IL_000b;
		}
	}
	{
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_1 = ___0_args;
		NullCheck(L_1);
		G_B3_0 = ((((int32_t)(((RuntimeArray*)L_1)->max_length)) == ((int32_t)0))? 1 : 0);
		goto IL_000c;
	}

IL_000b:
	{
		G_B3_0 = 1;
	}

IL_000c:
	{
		V_1 = (bool)G_B3_0;
		bool L_2 = V_1;
		if (!L_2)
		{
			goto IL_002c;
		}
	}
	{
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_3 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(method->rgctx_data, 0)) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_4;
		L_4 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_3, NULL);
		String_t* L_5;
		L_5 = _AndroidJNIHelper_GetSignature_m414A7A6B98FB5565075E4C51F22C482F2BCEEF5F((RuntimeObject*)L_4, NULL);
		String_t* L_6;
		L_6 = String_Concat_m9E3155FB84015C823606188F53B47CB44C444991(_stringLiteral622F5FF68A93093A1D312703FF92713F8BF2C946, L_5, NULL);
		V_2 = L_6;
		goto IL_008e;
	}

IL_002c:
	{
		StringBuilder_t* L_7 = (StringBuilder_t*)il2cpp_codegen_object_new(StringBuilder_t_il2cpp_TypeInfo_var);
		StringBuilder__ctor_m1D99713357DE05DAFA296633639DB55F8C30587D(L_7, NULL);
		V_0 = L_7;
		StringBuilder_t* L_8 = V_0;
		NullCheck(L_8);
		StringBuilder_t* L_9;
		L_9 = StringBuilder_Append_m71228B30F05724CD2CD96D9611DCD61BFB96A6E1(L_8, (Il2CppChar)((int32_t)40), NULL);
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_10 = ___0_args;
		V_3 = L_10;
		V_4 = 0;
		goto IL_005f;
	}

IL_0043:
	{
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_11 = V_3;
		int32_t L_12 = V_4;
		NullCheck(L_11);
		int32_t L_13 = L_12;
		RuntimeObject* L_14 = (L_11)->GetAt(static_cast<il2cpp_array_size_t>(L_13));
		V_5 = L_14;
		StringBuilder_t* L_15 = V_0;
		RuntimeObject* L_16 = V_5;
		String_t* L_17;
		L_17 = _AndroidJNIHelper_GetSignature_m414A7A6B98FB5565075E4C51F22C482F2BCEEF5F(L_16, NULL);
		NullCheck(L_15);
		StringBuilder_t* L_18;
		L_18 = StringBuilder_Append_m08904D74E0C78E5F36DCD9C9303BDD07886D9F7D(L_15, L_17, NULL);
		int32_t L_19 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_19, 1));
	}

IL_005f:
	{
		int32_t L_20 = V_4;
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_21 = V_3;
		NullCheck(L_21);
		if ((((int32_t)L_20) < ((int32_t)((int32_t)(((RuntimeArray*)L_21)->max_length)))))
		{
			goto IL_0043;
		}
	}
	{
		StringBuilder_t* L_22 = V_0;
		NullCheck(L_22);
		StringBuilder_t* L_23;
		L_23 = StringBuilder_Append_m71228B30F05724CD2CD96D9611DCD61BFB96A6E1(L_22, (Il2CppChar)((int32_t)41), NULL);
		StringBuilder_t* L_24 = V_0;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_25 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(method->rgctx_data, 0)) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_26;
		L_26 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_25, NULL);
		String_t* L_27;
		L_27 = _AndroidJNIHelper_GetSignature_m414A7A6B98FB5565075E4C51F22C482F2BCEEF5F((RuntimeObject*)L_26, NULL);
		NullCheck(L_24);
		StringBuilder_t* L_28;
		L_28 = StringBuilder_Append_m08904D74E0C78E5F36DCD9C9303BDD07886D9F7D(L_24, L_27, NULL);
		StringBuilder_t* L_29 = V_0;
		NullCheck((RuntimeObject*)L_29);
		String_t* L_30;
		L_30 = VirtualFuncInvoker0< String_t* >::Invoke(3, (RuntimeObject*)L_29);
		V_2 = L_30;
		goto IL_008e;
	}

IL_008e:
	{
		String_t* L_31 = V_2;
		return L_31;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Expression_Evaluate_TisDouble_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F_m078E1EC84AFDC45614AC23E12723A0B785941D40_gshared (Expression_t24E9476A15D0D7F6495CF8292DA48C63C871E4B7* __this, double* ___0_value, int32_t ___1_index, int32_t ___2_count, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ExpressionEvaluator_tF912A1FA6CB7EA697DFA7926E78D808A446B48F0_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	bool V_0 = false;
	{
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_0 = __this->___rpnTokens;
		double* L_1 = ___0_value;
		int32_t L_2 = ___1_index;
		int32_t L_3 = ___2_count;
		il2cpp_codegen_runtime_class_init_inline(ExpressionEvaluator_tF912A1FA6CB7EA697DFA7926E78D808A446B48F0_il2cpp_TypeInfo_var);
		bool L_4;
		L_4 = ExpressionEvaluator_EvaluateTokens_TisDouble_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F_m791767867653D0CCE2BEFF83F336A41B5B3A718E(L_0, L_1, L_2, L_3, il2cpp_rgctx_method(method->rgctx_data, 1));
		V_0 = L_4;
		goto IL_0012;
	}

IL_0012:
	{
		bool L_5 = V_0;
		return L_5;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Expression_Evaluate_TisInt64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3_m838397FA34A03D1C68D150CC95FD210252FEC377_gshared (Expression_t24E9476A15D0D7F6495CF8292DA48C63C871E4B7* __this, int64_t* ___0_value, int32_t ___1_index, int32_t ___2_count, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ExpressionEvaluator_tF912A1FA6CB7EA697DFA7926E78D808A446B48F0_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	bool V_0 = false;
	{
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_0 = __this->___rpnTokens;
		int64_t* L_1 = ___0_value;
		int32_t L_2 = ___1_index;
		int32_t L_3 = ___2_count;
		il2cpp_codegen_runtime_class_init_inline(ExpressionEvaluator_tF912A1FA6CB7EA697DFA7926E78D808A446B48F0_il2cpp_TypeInfo_var);
		bool L_4;
		L_4 = ExpressionEvaluator_EvaluateTokens_TisInt64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3_m7418F7A8835B2770EF83F1D52F2723897CD76DEB(L_0, L_1, L_2, L_3, il2cpp_rgctx_method(method->rgctx_data, 1));
		V_0 = L_4;
		goto IL_0012;
	}

IL_0012:
	{
		bool L_5 = V_0;
		return L_5;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Expression_Evaluate_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_m58D75192AF2281079E2FDE4034707E9883147B2C_gshared (Expression_t24E9476A15D0D7F6495CF8292DA48C63C871E4B7* __this, uint64_t* ___0_value, int32_t ___1_index, int32_t ___2_count, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ExpressionEvaluator_tF912A1FA6CB7EA697DFA7926E78D808A446B48F0_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	bool V_0 = false;
	{
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_0 = __this->___rpnTokens;
		uint64_t* L_1 = ___0_value;
		int32_t L_2 = ___1_index;
		int32_t L_3 = ___2_count;
		il2cpp_codegen_runtime_class_init_inline(ExpressionEvaluator_tF912A1FA6CB7EA697DFA7926E78D808A446B48F0_il2cpp_TypeInfo_var);
		bool L_4;
		L_4 = ExpressionEvaluator_EvaluateTokens_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_mCFCF758DECB276DBCB0A8B83BAE195EF3B974780(L_0, L_1, L_2, L_3, il2cpp_rgctx_method(method->rgctx_data, 1));
		V_0 = L_4;
		goto IL_0012;
	}

IL_0012:
	{
		bool L_5 = V_0;
		return L_5;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Expression_Evaluate_TisIl2CppFullySharedGenericAny_mC962ADA59143EB4298C3AE46F923C4552B01A4CC_gshared (Expression_t24E9476A15D0D7F6495CF8292DA48C63C871E4B7* __this, Il2CppFullySharedGenericAny* ___0_value, int32_t ___1_index, int32_t ___2_count, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ExpressionEvaluator_tF912A1FA6CB7EA697DFA7926E78D808A446B48F0_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	bool V_0 = false;
	{
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_0 = __this->___rpnTokens;
		Il2CppFullySharedGenericAny* L_1 = ___0_value;
		int32_t L_2 = ___1_index;
		int32_t L_3 = ___2_count;
		il2cpp_codegen_runtime_class_init_inline(ExpressionEvaluator_tF912A1FA6CB7EA697DFA7926E78D808A446B48F0_il2cpp_TypeInfo_var);
		bool L_4;
		L_4 = ((  bool (*) (StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248*, Il2CppFullySharedGenericAny*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(L_0, L_1, L_2, L_3, il2cpp_rgctx_method(method->rgctx_data, 1));
		V_0 = L_4;
		goto IL_0012;
	}

IL_0012:
	{
		bool L_5 = V_0;
		return L_5;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t WrapperCodecs_CalculateSize_TisRuntimeObject_m3DBB3CDDAD4C21C07D88D6953B9463AF7B6CE416_gshared (RuntimeObject* ___0_value, FieldCodec_1_t5E5853045CAC4F051697FDB8A12CC79D264D40D7* ___1_codec, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&CodedOutputStream_tEA7C97F94CE101273611192E2A22CD872F584163_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	int32_t V_0 = 0;
	{
		FieldCodec_1_t5E5853045CAC4F051697FDB8A12CC79D264D40D7* L_0 = ___1_codec;
		RuntimeObject* L_1 = ___0_value;
		NullCheck(L_0);
		int32_t L_2;
		L_2 = FieldCodec_1_CalculateSizeWithTag_mAF91F403A614B09B2113343DEFB9F23E37528D79(L_0, L_1, il2cpp_rgctx_method(method->rgctx_data, 2));
		V_0 = L_2;
		int32_t L_3 = V_0;
		il2cpp_codegen_runtime_class_init_inline(CodedOutputStream_tEA7C97F94CE101273611192E2A22CD872F584163_il2cpp_TypeInfo_var);
		int32_t L_4;
		L_4 = CodedOutputStream_ComputeLengthSize_mDD8A8B210E918ED0C32B22CB48BE98AA0FE85301(L_3, NULL);
		int32_t L_5 = V_0;
		return ((int32_t)il2cpp_codegen_add(L_4, L_5));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t WrapperCodecs_CalculateSize_TisIl2CppFullySharedGenericAny_m9049E7EB2C6BDC5BCA87CFC6D655FC4CAD08DEB2_gshared (Il2CppFullySharedGenericAny ___0_value, FieldCodec_1_tB0617798EF40F19054BE58235A7396E95CC2319B* ___1_codec, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&CodedOutputStream_tEA7C97F94CE101273611192E2A22CD872F584163_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	const uint32_t SizeOf_T_tE95032C8C1670861B88A86967B388BCFFE02C31E = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->rgctx_data, 1));
	const Il2CppFullySharedGenericAny L_1 = alloca(SizeOf_T_tE95032C8C1670861B88A86967B388BCFFE02C31E);
	int32_t V_0 = 0;
	{
		FieldCodec_1_tB0617798EF40F19054BE58235A7396E95CC2319B* L_0 = ___1_codec;
		il2cpp_codegen_memcpy(L_1, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(method->rgctx_data, 1)) ? ___0_value : &___0_value), SizeOf_T_tE95032C8C1670861B88A86967B388BCFFE02C31E);
		NullCheck(L_0);
		int32_t L_2;
		L_2 = InvokerFuncInvoker1< int32_t, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 2)), il2cpp_rgctx_method(method->rgctx_data, 2), L_0, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(method->rgctx_data, 1)) ? L_1: *(void**)L_1));
		V_0 = L_2;
		int32_t L_3 = V_0;
		il2cpp_codegen_runtime_class_init_inline(CodedOutputStream_tEA7C97F94CE101273611192E2A22CD872F584163_il2cpp_TypeInfo_var);
		int32_t L_4;
		L_4 = CodedOutputStream_ComputeLengthSize_mDD8A8B210E918ED0C32B22CB48BE98AA0FE85301(L_3, NULL);
		int32_t L_5 = V_0;
		return ((int32_t)il2cpp_codegen_add(L_4, L_5));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR FieldCodec_1_t5E5853045CAC4F051697FDB8A12CC79D264D40D7* WrapperCodecs_GetCodec_TisRuntimeObject_m3878F3061B0CA9FA941C3513A0BB2444E76DE768_gshared (const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_TryGetValue_m76D0309695A0582B3E29E97942ACD35DC4EFD128_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Type_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&WrapperCodecs_tE553F7639B839C368D43033A632BD1D30EC9BCFB_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	RuntimeObject* V_0 = NULL;
	Type_t* G_B3_0 = NULL;
	String_t* G_B3_1 = NULL;
	Type_t* G_B2_0 = NULL;
	String_t* G_B2_1 = NULL;
	String_t* G_B4_0 = NULL;
	String_t* G_B4_1 = NULL;
	{
		il2cpp_codegen_runtime_class_init_inline(WrapperCodecs_tE553F7639B839C368D43033A632BD1D30EC9BCFB_il2cpp_TypeInfo_var);
		Dictionary_2_t954AEC357FE7190582B8255D4ACEF81F5E94A6A5* L_0 = ((WrapperCodecs_tE553F7639B839C368D43033A632BD1D30EC9BCFB_StaticFields*)il2cpp_codegen_static_fields_for(WrapperCodecs_tE553F7639B839C368D43033A632BD1D30EC9BCFB_il2cpp_TypeInfo_var))->___Codecs;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_1 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(method->rgctx_data, 0)) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_2;
		L_2 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_1, NULL);
		NullCheck(L_0);
		bool L_3;
		L_3 = Dictionary_2_TryGetValue_m76D0309695A0582B3E29E97942ACD35DC4EFD128(L_0, L_2, (&V_0), Dictionary_2_TryGetValue_m76D0309695A0582B3E29E97942ACD35DC4EFD128_RuntimeMethod_var);
		if (L_3)
		{
			goto IL_003e;
		}
	}
	{
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_4 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(method->rgctx_data, 0)) };
		il2cpp_codegen_runtime_class_init_inline(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&Type_t_il2cpp_TypeInfo_var)));
		Type_t* L_5;
		L_5 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_4, NULL);
		Type_t* L_6 = L_5;
		if (L_6)
		{
			G_B3_0 = L_6;
			G_B3_1 = ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral7210D872E945C71ACA8CEF51ACA40552C43E8605));
			goto IL_002e;
		}
		G_B2_0 = L_6;
		G_B2_1 = ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral7210D872E945C71ACA8CEF51ACA40552C43E8605));
	}
	{
		G_B4_0 = ((String_t*)(NULL));
		G_B4_1 = G_B2_1;
		goto IL_0033;
	}

IL_002e:
	{
		NullCheck((RuntimeObject*)G_B3_0);
		String_t* L_7;
		L_7 = VirtualFuncInvoker0< String_t* >::Invoke(3, (RuntimeObject*)G_B3_0);
		G_B4_0 = L_7;
		G_B4_1 = G_B3_1;
	}

IL_0033:
	{
		String_t* L_8;
		L_8 = String_Concat_m9E3155FB84015C823606188F53B47CB44C444991(G_B4_1, G_B4_0, NULL);
		InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* L_9 = (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var)));
		InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162(L_9, L_8, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_9, method);
	}

IL_003e:
	{
		RuntimeObject* L_10 = V_0;
		return ((FieldCodec_1_t5E5853045CAC4F051697FDB8A12CC79D264D40D7*)CastclassSealed((RuntimeObject*)L_10, il2cpp_rgctx_data(method->rgctx_data, 1)));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR FieldCodec_1_tB0617798EF40F19054BE58235A7396E95CC2319B* WrapperCodecs_GetCodec_TisIl2CppFullySharedGenericAny_m02162358E26AA3E9B81D2B33D85CF48F01C43C7C_gshared (const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_TryGetValue_m76D0309695A0582B3E29E97942ACD35DC4EFD128_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Type_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&WrapperCodecs_tE553F7639B839C368D43033A632BD1D30EC9BCFB_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	RuntimeObject* V_0 = NULL;
	Type_t* G_B3_0 = NULL;
	String_t* G_B3_1 = NULL;
	Type_t* G_B2_0 = NULL;
	String_t* G_B2_1 = NULL;
	String_t* G_B4_0 = NULL;
	String_t* G_B4_1 = NULL;
	{
		il2cpp_codegen_runtime_class_init_inline(WrapperCodecs_tE553F7639B839C368D43033A632BD1D30EC9BCFB_il2cpp_TypeInfo_var);
		Dictionary_2_t954AEC357FE7190582B8255D4ACEF81F5E94A6A5* L_0 = ((WrapperCodecs_tE553F7639B839C368D43033A632BD1D30EC9BCFB_StaticFields*)il2cpp_codegen_static_fields_for(WrapperCodecs_tE553F7639B839C368D43033A632BD1D30EC9BCFB_il2cpp_TypeInfo_var))->___Codecs;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_1 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(method->rgctx_data, 0)) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_2;
		L_2 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_1, NULL);
		NullCheck(L_0);
		bool L_3;
		L_3 = Dictionary_2_TryGetValue_m76D0309695A0582B3E29E97942ACD35DC4EFD128(L_0, L_2, (&V_0), Dictionary_2_TryGetValue_m76D0309695A0582B3E29E97942ACD35DC4EFD128_RuntimeMethod_var);
		if (L_3)
		{
			goto IL_003e;
		}
	}
	{
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_4 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(method->rgctx_data, 0)) };
		il2cpp_codegen_runtime_class_init_inline(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&Type_t_il2cpp_TypeInfo_var)));
		Type_t* L_5;
		L_5 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_4, NULL);
		Type_t* L_6 = L_5;
		if (L_6)
		{
			G_B3_0 = L_6;
			G_B3_1 = ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral7210D872E945C71ACA8CEF51ACA40552C43E8605));
			goto IL_002e;
		}
		G_B2_0 = L_6;
		G_B2_1 = ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral7210D872E945C71ACA8CEF51ACA40552C43E8605));
	}
	{
		G_B4_0 = ((String_t*)(NULL));
		G_B4_1 = G_B2_1;
		goto IL_0033;
	}

IL_002e:
	{
		NullCheck((RuntimeObject*)G_B3_0);
		String_t* L_7;
		L_7 = VirtualFuncInvoker0< String_t* >::Invoke(3, (RuntimeObject*)G_B3_0);
		G_B4_0 = L_7;
		G_B4_1 = G_B3_1;
	}

IL_0033:
	{
		String_t* L_8;
		L_8 = String_Concat_m9E3155FB84015C823606188F53B47CB44C444991(G_B4_1, G_B4_0, NULL);
		InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* L_9 = (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var)));
		InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162(L_9, L_8, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_9, method);
	}

IL_003e:
	{
		RuntimeObject* L_10 = V_0;
		return ((FieldCodec_1_tB0617798EF40F19054BE58235A7396E95CC2319B*)CastclassSealed((RuntimeObject*)L_10, il2cpp_rgctx_data(method->rgctx_data, 1)));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ValueReader_1_t0E918B17E2768F18588C8D2085E3D4B954C220B5* WrapperCodecs_GetReader_TisIl2CppFullySharedGenericStruct_mF908B3E7D76EAA2511517E9C0C61B3EC0F7C88E7_gshared (const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_TryGetValue_m76D0309695A0582B3E29E97942ACD35DC4EFD128_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Type_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&WrapperCodecs_tE553F7639B839C368D43033A632BD1D30EC9BCFB_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	RuntimeObject* V_0 = NULL;
	Type_t* G_B3_0 = NULL;
	String_t* G_B3_1 = NULL;
	Type_t* G_B2_0 = NULL;
	String_t* G_B2_1 = NULL;
	String_t* G_B4_0 = NULL;
	String_t* G_B4_1 = NULL;
	{
		il2cpp_codegen_runtime_class_init_inline(WrapperCodecs_tE553F7639B839C368D43033A632BD1D30EC9BCFB_il2cpp_TypeInfo_var);
		Dictionary_2_t954AEC357FE7190582B8255D4ACEF81F5E94A6A5* L_0 = ((WrapperCodecs_tE553F7639B839C368D43033A632BD1D30EC9BCFB_StaticFields*)il2cpp_codegen_static_fields_for(WrapperCodecs_tE553F7639B839C368D43033A632BD1D30EC9BCFB_il2cpp_TypeInfo_var))->___Readers;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_1 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(method->rgctx_data, 0)) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_2;
		L_2 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_1, NULL);
		NullCheck(L_0);
		bool L_3;
		L_3 = Dictionary_2_TryGetValue_m76D0309695A0582B3E29E97942ACD35DC4EFD128(L_0, L_2, (&V_0), Dictionary_2_TryGetValue_m76D0309695A0582B3E29E97942ACD35DC4EFD128_RuntimeMethod_var);
		if (L_3)
		{
			goto IL_003e;
		}
	}
	{
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_4 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(method->rgctx_data, 0)) };
		il2cpp_codegen_runtime_class_init_inline(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&Type_t_il2cpp_TypeInfo_var)));
		Type_t* L_5;
		L_5 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_4, NULL);
		Type_t* L_6 = L_5;
		if (L_6)
		{
			G_B3_0 = L_6;
			G_B3_1 = ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralA6A94DCA4A0604385AFC755179D51DDE7BF9BE25));
			goto IL_002e;
		}
		G_B2_0 = L_6;
		G_B2_1 = ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralA6A94DCA4A0604385AFC755179D51DDE7BF9BE25));
	}
	{
		G_B4_0 = ((String_t*)(NULL));
		G_B4_1 = G_B2_1;
		goto IL_0033;
	}

IL_002e:
	{
		NullCheck((RuntimeObject*)G_B3_0);
		String_t* L_7;
		L_7 = VirtualFuncInvoker0< String_t* >::Invoke(3, (RuntimeObject*)G_B3_0);
		G_B4_0 = L_7;
		G_B4_1 = G_B3_1;
	}

IL_0033:
	{
		String_t* L_8;
		L_8 = String_Concat_m9E3155FB84015C823606188F53B47CB44C444991(G_B4_1, G_B4_0, NULL);
		InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* L_9 = (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var)));
		InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162(L_9, L_8, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_9, method);
	}

IL_003e:
	{
		RuntimeObject* L_10 = V_0;
		if (L_10)
		{
			goto IL_005d;
		}
	}
	{
		U3CU3Ec__DisplayClass3_0_1_tF5F0082B732265B8C79EB91362F5070AE725217C* L_11 = (U3CU3Ec__DisplayClass3_0_1_tF5F0082B732265B8C79EB91362F5070AE725217C*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->rgctx_data, 1));
		((  void (*) (U3CU3Ec__DisplayClass3_0_1_tF5F0082B732265B8C79EB91362F5070AE725217C*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 2)))(L_11, il2cpp_rgctx_method(method->rgctx_data, 2));
		U3CU3Ec__DisplayClass3_0_1_tF5F0082B732265B8C79EB91362F5070AE725217C* L_12 = L_11;
		il2cpp_codegen_runtime_class_init_inline(WrapperCodecs_tE553F7639B839C368D43033A632BD1D30EC9BCFB_il2cpp_TypeInfo_var);
		FieldCodec_1_tB1F4F5B504DB6A9556F8A62B1E1A7505CD128658* L_13;
		L_13 = ((  FieldCodec_1_tB1F4F5B504DB6A9556F8A62B1E1A7505CD128658* (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 3)))(il2cpp_rgctx_method(method->rgctx_data, 3));
		NullCheck(L_12);
		L_12->___nestedCoded = L_13;
		Il2CppCodeGenWriteBarrier((void**)(&L_12->___nestedCoded), (void*)L_13);
		ValueReader_1_t0E918B17E2768F18588C8D2085E3D4B954C220B5* L_14 = (ValueReader_1_t0E918B17E2768F18588C8D2085E3D4B954C220B5*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->rgctx_data, 6));
		((  void (*) (ValueReader_1_t0E918B17E2768F18588C8D2085E3D4B954C220B5*, RuntimeObject*, intptr_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 7)))(L_14, (RuntimeObject*)L_12, (intptr_t)((void*)il2cpp_rgctx_method(method->rgctx_data, 5)), il2cpp_rgctx_method(method->rgctx_data, 7));
		return L_14;
	}

IL_005d:
	{
		RuntimeObject* L_15 = V_0;
		return ((ValueReader_1_t0E918B17E2768F18588C8D2085E3D4B954C220B5*)Castclass((RuntimeObject*)L_15, il2cpp_rgctx_data(method->rgctx_data, 6)));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WrapperCodecs_Read_TisRuntimeObject_m81F504EDF3FECE1A8A872886291D30767B2E888E_gshared (ParseContext_tC04F8D72236E3ED9155AAD861769A3C56AEEB0EF* ___0_ctx, FieldCodec_1_t5E5853045CAC4F051697FDB8A12CC79D264D40D7* ___1_codec, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ParsingPrimitivesMessages_t7E329824B6CDE2975470D909F2DB2073F4ACF0F2_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	uint32_t V_2 = 0;
	RuntimeObject* V_3 = NULL;
	{
		ParseContext_tC04F8D72236E3ED9155AAD861769A3C56AEEB0EF* L_0 = ___0_ctx;
		int32_t L_1;
		L_1 = ParseContext_ReadLength_m5574397F353C62DA04F0E0E5616C2159787C52E6_inline(L_0, NULL);
		V_0 = L_1;
		ParseContext_tC04F8D72236E3ED9155AAD861769A3C56AEEB0EF* L_2 = ___0_ctx;
		ParserInternalState_t3044183736150999B222F94BFC5A875FA33EB36C* L_3 = (ParserInternalState_t3044183736150999B222F94BFC5A875FA33EB36C*)(&L_2->___state);
		int32_t L_4 = V_0;
		int32_t L_5;
		L_5 = SegmentedBufferHelper_PushLimit_m13B57D290C3F6DE8D49B46CDEBA41496A8CC496A(L_3, L_4, NULL);
		V_1 = L_5;
		FieldCodec_1_t5E5853045CAC4F051697FDB8A12CC79D264D40D7* L_6 = ___1_codec;
		NullCheck(L_6);
		RuntimeObject* L_7;
		L_7 = FieldCodec_1_get_DefaultValue_m1F114731B3660936CE2D9CDCE526CB33FF0169A6_inline(L_6, il2cpp_rgctx_method(method->rgctx_data, 1));
		V_3 = L_7;
		goto IL_0041;
	}

IL_001d:
	{
		uint32_t L_8 = V_2;
		FieldCodec_1_t5E5853045CAC4F051697FDB8A12CC79D264D40D7* L_9 = ___1_codec;
		NullCheck(L_9);
		uint32_t L_10;
		L_10 = FieldCodec_1_get_Tag_mFD9919FD0E0A0E96F3BEC9FE3E6C7DA9194DF07E_inline(L_9, il2cpp_rgctx_method(method->rgctx_data, 3));
		if ((!(((uint32_t)L_8) == ((uint32_t)L_10))))
		{
			goto IL_0030;
		}
	}
	{
		FieldCodec_1_t5E5853045CAC4F051697FDB8A12CC79D264D40D7* L_11 = ___1_codec;
		ParseContext_tC04F8D72236E3ED9155AAD861769A3C56AEEB0EF* L_12 = ___0_ctx;
		NullCheck(L_11);
		RuntimeObject* L_13;
		L_13 = FieldCodec_1_Read_mE413D0DC82F78AA938FEAA5EBF2BF72862E70DB0(L_11, L_12, il2cpp_rgctx_method(method->rgctx_data, 4));
		V_3 = L_13;
		goto IL_0041;
	}

IL_0030:
	{
		ParseContext_tC04F8D72236E3ED9155AAD861769A3C56AEEB0EF* L_14 = ___0_ctx;
		ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D* L_15 = (ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D*)(&L_14->___buffer);
		ParseContext_tC04F8D72236E3ED9155AAD861769A3C56AEEB0EF* L_16 = ___0_ctx;
		ParserInternalState_t3044183736150999B222F94BFC5A875FA33EB36C* L_17 = (ParserInternalState_t3044183736150999B222F94BFC5A875FA33EB36C*)(&L_16->___state);
		il2cpp_codegen_runtime_class_init_inline(ParsingPrimitivesMessages_t7E329824B6CDE2975470D909F2DB2073F4ACF0F2_il2cpp_TypeInfo_var);
		ParsingPrimitivesMessages_SkipLastField_m8C3980E28CCE8DFA24D34951FE2248BE0253AE5A(L_15, L_17, NULL);
	}

IL_0041:
	{
		ParseContext_tC04F8D72236E3ED9155AAD861769A3C56AEEB0EF* L_18 = ___0_ctx;
		uint32_t L_19;
		L_19 = ParseContext_ReadTag_m01B263948EC529915711371EE50F8EAEB484E265_inline(L_18, NULL);
		uint32_t L_20 = L_19;
		V_2 = L_20;
		if (L_20)
		{
			goto IL_001d;
		}
	}
	{
		ParseContext_tC04F8D72236E3ED9155AAD861769A3C56AEEB0EF* L_21 = ___0_ctx;
		ParserInternalState_t3044183736150999B222F94BFC5A875FA33EB36C* L_22 = (ParserInternalState_t3044183736150999B222F94BFC5A875FA33EB36C*)(&L_21->___state);
		il2cpp_codegen_runtime_class_init_inline(ParsingPrimitivesMessages_t7E329824B6CDE2975470D909F2DB2073F4ACF0F2_il2cpp_TypeInfo_var);
		ParsingPrimitivesMessages_CheckReadEndOfStreamTag_m1A598174A7F6DCBF3E922FED7B5468CE8C4E9EB1(L_22, NULL);
		ParseContext_tC04F8D72236E3ED9155AAD861769A3C56AEEB0EF* L_23 = ___0_ctx;
		ParserInternalState_t3044183736150999B222F94BFC5A875FA33EB36C* L_24 = (ParserInternalState_t3044183736150999B222F94BFC5A875FA33EB36C*)(&L_23->___state);
		int32_t L_25 = V_1;
		SegmentedBufferHelper_PopLimit_m9A9E2621E7721E325174872FBA832F7B5F409CA3(L_24, L_25, NULL);
		RuntimeObject* L_26 = V_3;
		return L_26;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WrapperCodecs_Read_TisIl2CppFullySharedGenericAny_mE19EC2FB2AA069E3886851C420C5FCEC5CFDA79D_gshared (ParseContext_tC04F8D72236E3ED9155AAD861769A3C56AEEB0EF* ___0_ctx, FieldCodec_1_tB0617798EF40F19054BE58235A7396E95CC2319B* ___1_codec, Il2CppFullySharedGenericAny* il2cppRetVal, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ParsingPrimitivesMessages_t7E329824B6CDE2975470D909F2DB2073F4ACF0F2_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	const uint32_t SizeOf_T_t4E371A31CD19824C2123B4B693840F3E26665504 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->rgctx_data, 2));
	const Il2CppFullySharedGenericAny L_7 = alloca(SizeOf_T_t4E371A31CD19824C2123B4B693840F3E26665504);
	const Il2CppFullySharedGenericAny L_13 = L_7;
	const Il2CppFullySharedGenericAny L_26 = L_7;
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	uint32_t V_2 = 0;
	Il2CppFullySharedGenericAny V_3 = alloca(SizeOf_T_t4E371A31CD19824C2123B4B693840F3E26665504);
	memset(V_3, 0, SizeOf_T_t4E371A31CD19824C2123B4B693840F3E26665504);
	{
		ParseContext_tC04F8D72236E3ED9155AAD861769A3C56AEEB0EF* L_0 = ___0_ctx;
		int32_t L_1;
		L_1 = ParseContext_ReadLength_m5574397F353C62DA04F0E0E5616C2159787C52E6_inline(L_0, NULL);
		V_0 = L_1;
		ParseContext_tC04F8D72236E3ED9155AAD861769A3C56AEEB0EF* L_2 = ___0_ctx;
		ParserInternalState_t3044183736150999B222F94BFC5A875FA33EB36C* L_3 = (ParserInternalState_t3044183736150999B222F94BFC5A875FA33EB36C*)(&L_2->___state);
		int32_t L_4 = V_0;
		int32_t L_5;
		L_5 = SegmentedBufferHelper_PushLimit_m13B57D290C3F6DE8D49B46CDEBA41496A8CC496A(L_3, L_4, NULL);
		V_1 = L_5;
		FieldCodec_1_tB0617798EF40F19054BE58235A7396E95CC2319B* L_6 = ___1_codec;
		NullCheck(L_6);
		InvokerActionInvoker1< Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)), il2cpp_rgctx_method(method->rgctx_data, 1), L_6, (Il2CppFullySharedGenericAny*)L_7);
		il2cpp_codegen_memcpy(V_3, L_7, SizeOf_T_t4E371A31CD19824C2123B4B693840F3E26665504);
		goto IL_0041;
	}

IL_001d:
	{
		uint32_t L_8 = V_2;
		FieldCodec_1_tB0617798EF40F19054BE58235A7396E95CC2319B* L_9 = ___1_codec;
		NullCheck(L_9);
		uint32_t L_10;
		L_10 = ((  uint32_t (*) (FieldCodec_1_tB0617798EF40F19054BE58235A7396E95CC2319B*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 3)))(L_9, il2cpp_rgctx_method(method->rgctx_data, 3));
		if ((!(((uint32_t)L_8) == ((uint32_t)L_10))))
		{
			goto IL_0030;
		}
	}
	{
		FieldCodec_1_tB0617798EF40F19054BE58235A7396E95CC2319B* L_11 = ___1_codec;
		ParseContext_tC04F8D72236E3ED9155AAD861769A3C56AEEB0EF* L_12 = ___0_ctx;
		NullCheck(L_11);
		InvokerActionInvoker2< ParseContext_tC04F8D72236E3ED9155AAD861769A3C56AEEB0EF*, Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 4)), il2cpp_rgctx_method(method->rgctx_data, 4), L_11, L_12, (Il2CppFullySharedGenericAny*)L_13);
		il2cpp_codegen_memcpy(V_3, L_13, SizeOf_T_t4E371A31CD19824C2123B4B693840F3E26665504);
		goto IL_0041;
	}

IL_0030:
	{
		ParseContext_tC04F8D72236E3ED9155AAD861769A3C56AEEB0EF* L_14 = ___0_ctx;
		ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D* L_15 = (ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D*)(&L_14->___buffer);
		ParseContext_tC04F8D72236E3ED9155AAD861769A3C56AEEB0EF* L_16 = ___0_ctx;
		ParserInternalState_t3044183736150999B222F94BFC5A875FA33EB36C* L_17 = (ParserInternalState_t3044183736150999B222F94BFC5A875FA33EB36C*)(&L_16->___state);
		il2cpp_codegen_runtime_class_init_inline(ParsingPrimitivesMessages_t7E329824B6CDE2975470D909F2DB2073F4ACF0F2_il2cpp_TypeInfo_var);
		ParsingPrimitivesMessages_SkipLastField_m8C3980E28CCE8DFA24D34951FE2248BE0253AE5A(L_15, L_17, NULL);
	}

IL_0041:
	{
		ParseContext_tC04F8D72236E3ED9155AAD861769A3C56AEEB0EF* L_18 = ___0_ctx;
		uint32_t L_19;
		L_19 = ParseContext_ReadTag_m01B263948EC529915711371EE50F8EAEB484E265_inline(L_18, NULL);
		uint32_t L_20 = L_19;
		V_2 = L_20;
		if (L_20)
		{
			goto IL_001d;
		}
	}
	{
		ParseContext_tC04F8D72236E3ED9155AAD861769A3C56AEEB0EF* L_21 = ___0_ctx;
		ParserInternalState_t3044183736150999B222F94BFC5A875FA33EB36C* L_22 = (ParserInternalState_t3044183736150999B222F94BFC5A875FA33EB36C*)(&L_21->___state);
		il2cpp_codegen_runtime_class_init_inline(ParsingPrimitivesMessages_t7E329824B6CDE2975470D909F2DB2073F4ACF0F2_il2cpp_TypeInfo_var);
		ParsingPrimitivesMessages_CheckReadEndOfStreamTag_m1A598174A7F6DCBF3E922FED7B5468CE8C4E9EB1(L_22, NULL);
		ParseContext_tC04F8D72236E3ED9155AAD861769A3C56AEEB0EF* L_23 = ___0_ctx;
		ParserInternalState_t3044183736150999B222F94BFC5A875FA33EB36C* L_24 = (ParserInternalState_t3044183736150999B222F94BFC5A875FA33EB36C*)(&L_23->___state);
		int32_t L_25 = V_1;
		SegmentedBufferHelper_PopLimit_m9A9E2621E7721E325174872FBA832F7B5F409CA3(L_24, L_25, NULL);
		il2cpp_codegen_memcpy(L_26, V_3, SizeOf_T_t4E371A31CD19824C2123B4B693840F3E26665504);
		il2cpp_codegen_memcpy(il2cppRetVal, L_26, SizeOf_T_t4E371A31CD19824C2123B4B693840F3E26665504);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WrapperCodecs_Write_TisRuntimeObject_m3F38484DCECC0BB1739077883AADB02AB1E156A4_gshared (WriteContext_tF80B3959AE2E6F9D5F8D447B35D859DA2ABD226D* ___0_ctx, RuntimeObject* ___1_value, FieldCodec_1_t5E5853045CAC4F051697FDB8A12CC79D264D40D7* ___2_codec, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		WriteContext_tF80B3959AE2E6F9D5F8D447B35D859DA2ABD226D* L_0 = ___0_ctx;
		FieldCodec_1_t5E5853045CAC4F051697FDB8A12CC79D264D40D7* L_1 = ___2_codec;
		RuntimeObject* L_2 = ___1_value;
		NullCheck(L_1);
		int32_t L_3;
		L_3 = FieldCodec_1_CalculateSizeWithTag_mAF91F403A614B09B2113343DEFB9F23E37528D79(L_1, L_2, il2cpp_rgctx_method(method->rgctx_data, 2));
		WriteContext_WriteLength_m5C0E4572780DDDAF32DF37BB7C9D590162FBDCC2(L_0, L_3, NULL);
		FieldCodec_1_t5E5853045CAC4F051697FDB8A12CC79D264D40D7* L_4 = ___2_codec;
		WriteContext_tF80B3959AE2E6F9D5F8D447B35D859DA2ABD226D* L_5 = ___0_ctx;
		RuntimeObject* L_6 = ___1_value;
		NullCheck(L_4);
		FieldCodec_1_WriteTagAndValue_mA4E442BBC368DD9685D6C30C692AD5130E9BAA85(L_4, L_5, L_6, il2cpp_rgctx_method(method->rgctx_data, 3));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WrapperCodecs_Write_TisIl2CppFullySharedGenericAny_mA2EFD498625E56614E8BCDA73097C4D9DE2B72BD_gshared (WriteContext_tF80B3959AE2E6F9D5F8D447B35D859DA2ABD226D* ___0_ctx, Il2CppFullySharedGenericAny ___1_value, FieldCodec_1_tB0617798EF40F19054BE58235A7396E95CC2319B* ___2_codec, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	const uint32_t SizeOf_T_t9812A36BED9C5C5A934B409C9EBB6F33DD7A04F9 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->rgctx_data, 1));
	const Il2CppFullySharedGenericAny L_2 = alloca(SizeOf_T_t9812A36BED9C5C5A934B409C9EBB6F33DD7A04F9);
	const Il2CppFullySharedGenericAny L_6 = alloca(SizeOf_T_t9812A36BED9C5C5A934B409C9EBB6F33DD7A04F9);
	{
		WriteContext_tF80B3959AE2E6F9D5F8D447B35D859DA2ABD226D* L_0 = ___0_ctx;
		FieldCodec_1_tB0617798EF40F19054BE58235A7396E95CC2319B* L_1 = ___2_codec;
		il2cpp_codegen_memcpy(L_2, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(method->rgctx_data, 1)) ? ___1_value : &___1_value), SizeOf_T_t9812A36BED9C5C5A934B409C9EBB6F33DD7A04F9);
		NullCheck(L_1);
		int32_t L_3;
		L_3 = InvokerFuncInvoker1< int32_t, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 2)), il2cpp_rgctx_method(method->rgctx_data, 2), L_1, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(method->rgctx_data, 1)) ? L_2: *(void**)L_2));
		WriteContext_WriteLength_m5C0E4572780DDDAF32DF37BB7C9D590162FBDCC2(L_0, L_3, NULL);
		FieldCodec_1_tB0617798EF40F19054BE58235A7396E95CC2319B* L_4 = ___2_codec;
		WriteContext_tF80B3959AE2E6F9D5F8D447B35D859DA2ABD226D* L_5 = ___0_ctx;
		il2cpp_codegen_memcpy(L_6, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(method->rgctx_data, 1)) ? ___1_value : &___1_value), SizeOf_T_t9812A36BED9C5C5A934B409C9EBB6F33DD7A04F9);
		NullCheck(L_4);
		InvokerActionInvoker2< WriteContext_tF80B3959AE2E6F9D5F8D447B35D859DA2ABD226D*, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 3)), il2cpp_rgctx_method(method->rgctx_data, 3), L_4, L_5, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(method->rgctx_data, 1)) ? L_6: *(void**)L_6));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TypeConstructorVisitor_Visit_TisBounds_t367E830C64BBF235ED8C3B2F8CF6254FDCAD39C3_m2A21711A3D655B51E421ACBEA3F03A09C8BBC250_gshared (TypeConstructorVisitor_tFC61250F68BF43FE889F5B1002CBFF90648E9C7F* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TypeUtility_t62F146E51B66BB18FA0E1EFA84A564FF2B8AAD03_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	{
		il2cpp_codegen_runtime_class_init_inline(TypeUtility_t62F146E51B66BB18FA0E1EFA84A564FF2B8AAD03_il2cpp_TypeInfo_var);
		RuntimeObject* L_0;
		L_0 = TypeUtility_CreateTypeConstructor_TisBounds_t367E830C64BBF235ED8C3B2F8CF6254FDCAD39C3_m16C827D0F6107B7998F6C99B57F7CC2F181E2198(il2cpp_rgctx_method(method->rgctx_data, 0));
		__this->___TypeConstructor = (RuntimeObject*)L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___TypeConstructor), (void*)(RuntimeObject*)L_0);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TypeConstructorVisitor_Visit_TisBoundsInt_t4E757DE5EFF9FCB42000F173360DDC63B5585485_mA9E7AA6DB293483965B65EEEBF63885DEF084EA2_gshared (TypeConstructorVisitor_tFC61250F68BF43FE889F5B1002CBFF90648E9C7F* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TypeUtility_t62F146E51B66BB18FA0E1EFA84A564FF2B8AAD03_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	{
		il2cpp_codegen_runtime_class_init_inline(TypeUtility_t62F146E51B66BB18FA0E1EFA84A564FF2B8AAD03_il2cpp_TypeInfo_var);
		RuntimeObject* L_0;
		L_0 = TypeUtility_CreateTypeConstructor_TisBoundsInt_t4E757DE5EFF9FCB42000F173360DDC63B5585485_m8F344250A2F9E6EE6DDBA6BA833BB36D0F272B66(il2cpp_rgctx_method(method->rgctx_data, 0));
		__this->___TypeConstructor = (RuntimeObject*)L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___TypeConstructor), (void*)(RuntimeObject*)L_0);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TypeConstructorVisitor_Visit_TisColor_tD001788D726C3A7F1379BEED0260B9591F440C1F_mFE98C0ECD8751FEC86E5F9CD2AFC20794571C81C_gshared (TypeConstructorVisitor_tFC61250F68BF43FE889F5B1002CBFF90648E9C7F* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TypeUtility_t62F146E51B66BB18FA0E1EFA84A564FF2B8AAD03_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	{
		il2cpp_codegen_runtime_class_init_inline(TypeUtility_t62F146E51B66BB18FA0E1EFA84A564FF2B8AAD03_il2cpp_TypeInfo_var);
		RuntimeObject* L_0;
		L_0 = TypeUtility_CreateTypeConstructor_TisColor_tD001788D726C3A7F1379BEED0260B9591F440C1F_mBBCB804F367E06EA4D482F1B69165DD2B5BF38FF(il2cpp_rgctx_method(method->rgctx_data, 0));
		__this->___TypeConstructor = (RuntimeObject*)L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___TypeConstructor), (void*)(RuntimeObject*)L_0);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TypeConstructorVisitor_Visit_TisRuntimeObject_m6C6E2EDC433DCAB90206712FB63993865A9B9305_gshared (TypeConstructorVisitor_tFC61250F68BF43FE889F5B1002CBFF90648E9C7F* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TypeUtility_t62F146E51B66BB18FA0E1EFA84A564FF2B8AAD03_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	{
		il2cpp_codegen_runtime_class_init_inline(TypeUtility_t62F146E51B66BB18FA0E1EFA84A564FF2B8AAD03_il2cpp_TypeInfo_var);
		RuntimeObject* L_0;
		L_0 = TypeUtility_CreateTypeConstructor_TisRuntimeObject_m4E17F588B090C1DADAE2D986BDA407DECEAC020F(il2cpp_rgctx_method(method->rgctx_data, 0));
		__this->___TypeConstructor = (RuntimeObject*)L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___TypeConstructor), (void*)(RuntimeObject*)L_0);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TypeConstructorVisitor_Visit_TisRect_tA04E0F8A1830E767F40FB27ECD8D309303571F0D_m97DBB59374BCA99C98C45F169AF69955608B68AA_gshared (TypeConstructorVisitor_tFC61250F68BF43FE889F5B1002CBFF90648E9C7F* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TypeUtility_t62F146E51B66BB18FA0E1EFA84A564FF2B8AAD03_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	{
		il2cpp_codegen_runtime_class_init_inline(TypeUtility_t62F146E51B66BB18FA0E1EFA84A564FF2B8AAD03_il2cpp_TypeInfo_var);
		RuntimeObject* L_0;
		L_0 = TypeUtility_CreateTypeConstructor_TisRect_tA04E0F8A1830E767F40FB27ECD8D309303571F0D_m2C5F5CF80D13B041768C7845C5AAEEC02BB683BA(il2cpp_rgctx_method(method->rgctx_data, 0));
		__this->___TypeConstructor = (RuntimeObject*)L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___TypeConstructor), (void*)(RuntimeObject*)L_0);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TypeConstructorVisitor_Visit_TisRectInt_t1744D10E1063135DA9D574F95205B98DAC600CB8_m7C42EB46E69BD2515C39AB6013A0763C6479AD66_gshared (TypeConstructorVisitor_tFC61250F68BF43FE889F5B1002CBFF90648E9C7F* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TypeUtility_t62F146E51B66BB18FA0E1EFA84A564FF2B8AAD03_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	{
		il2cpp_codegen_runtime_class_init_inline(TypeUtility_t62F146E51B66BB18FA0E1EFA84A564FF2B8AAD03_il2cpp_TypeInfo_var);
		RuntimeObject* L_0;
		L_0 = TypeUtility_CreateTypeConstructor_TisRectInt_t1744D10E1063135DA9D574F95205B98DAC600CB8_mF6949D9EDD480E6666CD975C66487AAD6ABC7D11(il2cpp_rgctx_method(method->rgctx_data, 0));
		__this->___TypeConstructor = (RuntimeObject*)L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___TypeConstructor), (void*)(RuntimeObject*)L_0);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TypeConstructorVisitor_Visit_TisVector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7_m032CA5A330B4032D164F88B2B40B6A7F2590357F_gshared (TypeConstructorVisitor_tFC61250F68BF43FE889F5B1002CBFF90648E9C7F* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TypeUtility_t62F146E51B66BB18FA0E1EFA84A564FF2B8AAD03_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	{
		il2cpp_codegen_runtime_class_init_inline(TypeUtility_t62F146E51B66BB18FA0E1EFA84A564FF2B8AAD03_il2cpp_TypeInfo_var);
		RuntimeObject* L_0;
		L_0 = TypeUtility_CreateTypeConstructor_TisVector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7_mE0C65F4221E48BB07F75856972A0CCDAE284AB9F(il2cpp_rgctx_method(method->rgctx_data, 0));
		__this->___TypeConstructor = (RuntimeObject*)L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___TypeConstructor), (void*)(RuntimeObject*)L_0);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TypeConstructorVisitor_Visit_TisVector2Int_t69B2886EBAB732D9B880565E18E7568F3DE0CE6A_m0E8E39845CA3F1BFADAC1B15E849E5885D813E6F_gshared (TypeConstructorVisitor_tFC61250F68BF43FE889F5B1002CBFF90648E9C7F* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TypeUtility_t62F146E51B66BB18FA0E1EFA84A564FF2B8AAD03_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	{
		il2cpp_codegen_runtime_class_init_inline(TypeUtility_t62F146E51B66BB18FA0E1EFA84A564FF2B8AAD03_il2cpp_TypeInfo_var);
		RuntimeObject* L_0;
		L_0 = TypeUtility_CreateTypeConstructor_TisVector2Int_t69B2886EBAB732D9B880565E18E7568F3DE0CE6A_mC8EF710494C8986B279262C6C64947BE2C1DC55C(il2cpp_rgctx_method(method->rgctx_data, 0));
		__this->___TypeConstructor = (RuntimeObject*)L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___TypeConstructor), (void*)(RuntimeObject*)L_0);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TypeConstructorVisitor_Visit_TisVector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2_mA88A16DC097E207AD6CE15E89D3B94DBB01BDACE_gshared (TypeConstructorVisitor_tFC61250F68BF43FE889F5B1002CBFF90648E9C7F* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TypeUtility_t62F146E51B66BB18FA0E1EFA84A564FF2B8AAD03_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	{
		il2cpp_codegen_runtime_class_init_inline(TypeUtility_t62F146E51B66BB18FA0E1EFA84A564FF2B8AAD03_il2cpp_TypeInfo_var);
		RuntimeObject* L_0;
		L_0 = TypeUtility_CreateTypeConstructor_TisVector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2_m1AB8BF0921C24186B3C43FC4341AAD2F6FE87C4D(il2cpp_rgctx_method(method->rgctx_data, 0));
		__this->___TypeConstructor = (RuntimeObject*)L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___TypeConstructor), (void*)(RuntimeObject*)L_0);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TypeConstructorVisitor_Visit_TisVector3Int_t65CB06F557251D18A37BD71F3655BA836A357376_m28D19B06528A4614AF9C3E29DC8274DE067868D8_gshared (TypeConstructorVisitor_tFC61250F68BF43FE889F5B1002CBFF90648E9C7F* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TypeUtility_t62F146E51B66BB18FA0E1EFA84A564FF2B8AAD03_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	{
		il2cpp_codegen_runtime_class_init_inline(TypeUtility_t62F146E51B66BB18FA0E1EFA84A564FF2B8AAD03_il2cpp_TypeInfo_var);
		RuntimeObject* L_0;
		L_0 = TypeUtility_CreateTypeConstructor_TisVector3Int_t65CB06F557251D18A37BD71F3655BA836A357376_mB00220519A80AA5ACE36B7DBA2E6A6CB796302AF(il2cpp_rgctx_method(method->rgctx_data, 0));
		__this->___TypeConstructor = (RuntimeObject*)L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___TypeConstructor), (void*)(RuntimeObject*)L_0);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TypeConstructorVisitor_Visit_TisVector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3_m3CD9CD3C768BBCC83DD02B2C76300A03AF1B1AD6_gshared (TypeConstructorVisitor_tFC61250F68BF43FE889F5B1002CBFF90648E9C7F* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TypeUtility_t62F146E51B66BB18FA0E1EFA84A564FF2B8AAD03_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	{
		il2cpp_codegen_runtime_class_init_inline(TypeUtility_t62F146E51B66BB18FA0E1EFA84A564FF2B8AAD03_il2cpp_TypeInfo_var);
		RuntimeObject* L_0;
		L_0 = TypeUtility_CreateTypeConstructor_TisVector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3_mED1DC338E5DB62F3E64F6272A9F12150DA5CC1B9(il2cpp_rgctx_method(method->rgctx_data, 0));
		__this->___TypeConstructor = (RuntimeObject*)L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___TypeConstructor), (void*)(RuntimeObject*)L_0);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TypeConstructorVisitor_Visit_TisIl2CppFullySharedGenericAny_m8B414261A078E3FE7517FAF2F9E944969F6B73E2_gshared (TypeConstructorVisitor_tFC61250F68BF43FE889F5B1002CBFF90648E9C7F* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TypeUtility_t62F146E51B66BB18FA0E1EFA84A564FF2B8AAD03_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	{
		il2cpp_codegen_runtime_class_init_inline(TypeUtility_t62F146E51B66BB18FA0E1EFA84A564FF2B8AAD03_il2cpp_TypeInfo_var);
		RuntimeObject* L_0;
		L_0 = ((  RuntimeObject* (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(il2cpp_rgctx_method(method->rgctx_data, 0));
		__this->___TypeConstructor = (RuntimeObject*)L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___TypeConstructor), (void*)(RuntimeObject*)L_0);
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t ParseContext_ReadLength_m5574397F353C62DA04F0E0E5616C2159787C52E6_inline (ParseContext_tC04F8D72236E3ED9155AAD861769A3C56AEEB0EF* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ParsingPrimitives_t4F870CEF214FECD314006BA436D0866A59B90004_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D* L_0 = (ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D*)(&__this->___buffer);
		ParserInternalState_t3044183736150999B222F94BFC5A875FA33EB36C* L_1 = (ParserInternalState_t3044183736150999B222F94BFC5A875FA33EB36C*)(&__this->___state);
		il2cpp_codegen_runtime_class_init_inline(ParsingPrimitives_t4F870CEF214FECD314006BA436D0866A59B90004_il2cpp_TypeInfo_var);
		uint32_t L_2;
		L_2 = ParsingPrimitives_ParseRawVarint32_m12E76CAA773AAED8FDAF192EBFAF830E615798BF(L_0, L_1, NULL);
		return L_2;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint32_t ParseContext_ReadTag_m01B263948EC529915711371EE50F8EAEB484E265_inline (ParseContext_tC04F8D72236E3ED9155AAD861769A3C56AEEB0EF* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ParsingPrimitives_t4F870CEF214FECD314006BA436D0866A59B90004_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D* L_0 = (ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D*)(&__this->___buffer);
		ParserInternalState_t3044183736150999B222F94BFC5A875FA33EB36C* L_1 = (ParserInternalState_t3044183736150999B222F94BFC5A875FA33EB36C*)(&__this->___state);
		il2cpp_codegen_runtime_class_init_inline(ParsingPrimitives_t4F870CEF214FECD314006BA436D0866A59B90004_il2cpp_TypeInfo_var);
		uint32_t L_2;
		L_2 = ParsingPrimitives_ParseTag_mC3CDF9E540F71AEAB45BC4BAFAE69C8FB097DB64(L_0, L_1, NULL);
		return L_2;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RuntimeObject* FieldCodec_1_get_DefaultValue_m1F114731B3660936CE2D9CDCE526CB33FF0169A6_gshared_inline (FieldCodec_1_t5E5853045CAC4F051697FDB8A12CC79D264D40D7* __this, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = __this->___U3CDefaultValueU3Ek__BackingField;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint32_t FieldCodec_1_get_Tag_mFD9919FD0E0A0E96F3BEC9FE3E6C7DA9194DF07E_gshared_inline (FieldCodec_1_t5E5853045CAC4F051697FDB8A12CC79D264D40D7* __this, const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = __this->___U3CTagU3Ek__BackingField;
		return L_0;
	}
}
