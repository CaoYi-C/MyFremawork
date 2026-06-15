#include "pch-cpp.hpp"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif


#include <limits>


struct VirtualActionInvoker0
{
	typedef void (*Action)(void*, const RuntimeMethod*);

	static inline void Invoke (Il2CppMethodSlot slot, RuntimeObject* obj)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		((Action)invokeData.methodPtr)(obj, invokeData.method);
	}
};
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
struct InterfaceActionInvoker0
{
	typedef void (*Action)(void*, const RuntimeMethod*);

	static inline void Invoke (Il2CppMethodSlot slot, RuntimeClass* declaringInterface, RuntimeObject* obj)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_interface_invoke_data(slot, obj, declaringInterface);
		((Action)invokeData.methodPtr)(obj, invokeData.method);
	}
};
template <typename T1>
struct InterfaceActionInvoker1Invoker;
template <typename T1>
struct InterfaceActionInvoker1Invoker<T1*>
{
	static inline void Invoke (Il2CppMethodSlot slot, RuntimeClass* declaringInterface, RuntimeObject* obj, T1* p1)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_interface_invoke_data(slot, obj, declaringInterface);
		void* params[1] = { p1 };
		invokeData.method->invoker_method(il2cpp_codegen_get_method_pointer(invokeData.method), invokeData.method, obj, params, params[0]);
	}
};
template <typename R>
struct InterfaceFuncInvoker0
{
	typedef R (*Func)(void*, const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeClass* declaringInterface, RuntimeObject* obj)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_interface_invoke_data(slot, obj, declaringInterface);
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
struct InvokerActionInvoker2<T1, T2*>
{
	static inline void Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1 p1, T2* p2)
	{
		void* params[2] = { &p1, p2 };
		method->invoker_method(methodPtr, method, obj, params, params[1]);
	}
};
template <typename T1, typename T2>
struct InvokerActionInvoker2<T1*, T2*>
{
	static inline void Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1* p1, T2* p2)
	{
		void* params[2] = { p1, p2 };
		method->invoker_method(methodPtr, method, obj, params, params[1]);
	}
};
template <typename T1, typename T2, typename T3>
struct InvokerActionInvoker3;
template <typename T1, typename T2, typename T3>
struct InvokerActionInvoker3<T1*, T2*, T3*>
{
	static inline void Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1* p1, T2* p2, T3* p3)
	{
		void* params[3] = { p1, p2, p3 };
		method->invoker_method(methodPtr, method, obj, params, params[2]);
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
template <typename R, typename T1, typename T2>
struct InvokerFuncInvoker2;
template <typename R, typename T1, typename T2>
struct InvokerFuncInvoker2<R, T1*, T2*>
{
	static inline R Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1* p1, T2* p2)
	{
		R ret;
		void* params[2] = { p1, p2 };
		method->invoker_method(methodPtr, method, obj, params, &ret);
		return ret;
	}
};
template <typename R>
struct ConstrainedFuncInvoker0
{
	static inline R Invoke (RuntimeClass* type, const RuntimeMethod* constrainedMethod, void* boxBuffer, void* obj)
	{
		R ret;
		il2cpp_codegen_runtime_constrained_call(type, constrainedMethod, boxBuffer, obj, NULL, &ret);
		return ret;
	}
};

struct Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87;
struct AsyncReactiveProperty_1_t55DCE046DB85F4B8B8BFAD7AE879EE536D5F9733;
struct Channel_1_t54EA6F93BD0DB668227D2390918ED6CFA7C02A80;
struct Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858;
struct Func_2_t696684549FAB37B32A9C38A40F33DB777B757E69;
struct Func_2_tA526681EE526C81F376160E44520BDC21770A705;
struct Func_2_tF42287527472FA89789873F068A87C60A00EC7D3;
struct Func_2_tDBF8C754A8F1FC6DE54BB9904D2D81C266DFF6B4;
struct Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA;
struct Func_2_t2FDA873D8482C79555CFB05233D610E8F1C7C354;
struct Func_2_t1C8F983F9A1AA802D45E89037E2AA7ACD1094821;
struct Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00;
struct Func_2_t9A0D493A82DCC47C9C819A3B045E02D9B5DDCE1B;
struct Func_2_tACBF5A1656250800CE861707354491F0611F6624;
struct Func_2_t92F44173C14E7022E392A8FEA4374C3CD24578EF;
struct Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A;
struct Func_2_t12F902B64E731F36B1BC057F3AF13BF1D833E1DF;
struct Func_2_tFD36EA818BBCBD1EDE1E1540FC3EF156A6ADCCAD;
struct Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B;
struct Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0;
struct IEnumerable_1_t60509816D8966320E2A9660FC756B6C440ADFC50;
struct IEnumerable_1_tC98E76738AF0A72F03879344D977819749AF8DB0;
struct IEnumerable_1_t1EC9EB35B0A130CF2CBCDE9C7A237D8621D4FCC6;
struct IEnumerable_1_tCE758D940790D6D0D56B457E522C195F8C413AF2;
struct IEnumerable_1_t71A46277DBD73BD4009B2B20885D2B7057593A1A;
struct IEnumerable_1_tF95C9E01A913DD50575531C8305932628663D9E9;
struct IEnumerable_1_tD022CDF8A7E4F1F913427E8746221007473EC6F2;
struct IEnumerable_1_tE925592D6CE31E7FA5349FCEE9007F3DF53409FD;
struct IEnumerable_1_t29E7244AE33B71FA0981E50D5BC73B7938F35C66;
struct IEnumerator_1_t327FF232159D9644239A65F54312F684DB7BE375;
struct IEnumerator_1_t8617748A16D15DA9471AA85261839268A6C65BC8;
struct IEnumerator_1_tD6A90A7446DA8E6CF865EDFBBF18C1200BB6D452;
struct IEnumerator_1_t239F6ACD0FC026E7FA70965FDE161517CD367AED;
struct IEnumerator_1_t43D2E4BA9246755F293DFA74F001FB1A70A648FD;
struct IEnumerator_1_t57E9B30295B26EA00AB537E17B3999A81D7C2686;
struct IEnumerator_1_t4CA3732E083480E40018894623B3C184576E5EFD;
struct IEnumerator_1_t75CB2681E18F7F2791528FA2CA60361FDB5DA08D;
struct ITriggerHandler_1_t53BCC826B29B27388A8A63C9E80F17313AB22E2C;
struct IUniTaskAsyncEnumerator_1_t821F594EE7A9A9AD50A4AD8E2BCA1FDC7F4D9FDC;
struct IUniTaskAsyncEnumerator_1_t256C7409E6B13FF3224A57D2DD1A4D52A2C40092;
struct IUniTaskSource_1_tA27C284FF17E3AAB5B5D07A7E4DE207B56F764AB;
struct Iterator_1_t6F8827EED7DB0C845108D7DF969A608714128E05;
struct Iterator_1_t92BE161457BB4186D87644A87E4C1FAC67B8E430;
struct Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07;
struct Iterator_1_tEEF82AE11FFC6DF9B283B2D5E4A87B3E3BFD805E;
struct Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA;
struct Iterator_1_t90E419394494C38051F176EB657B6E351726C1A5;
struct Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0;
struct List_1_t8A1639802238DEF3222B6CBBC0DEF0B4B5F350EB;
struct List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73;
struct List_1_tDA4D291C60B1EFA9EA50BBA3367C657CC9410576;
struct List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D;
struct List_1_tB751FDCEDAE7A97430AD924824F5D0193A720E52;
struct List_1_t85FF16594D5F70EECC5855882558F8E26EF6BAFF;
struct List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A;
struct ReadOnlyAsyncReactiveProperty_1_tB7349A20B00D8047434C5CDE4CB7EC263380B1E9;
struct SparselyPopulatedArrayFragment_1_tB32DA8C2B7461E80CE4C271B76C103629BDFA035;
struct WhenAnyPromise_7_t354ACE057C836122798B0B89EB0956841B40C24F;
struct WhenAnyPromise_8_tB1A18813B231826F7BEE92541715D6266929F072;
struct WhenAnyPromise_9_t2D551F16D8A9A247E0C45E7698A6A7A3CCDB7757;
struct WhenEachEnumerable_1_t4F973EE64B6BC978974DEFBDBB2EF58E117C0899;
struct WhereArrayIterator_1_t61D2F3529A970E9F412291B961056462F17EDDCB;
struct WhereArrayIterator_1_t8CAF996BCF726E82067F30842CD1885CA4F71D0B;
struct WhereArrayIterator_1_t027D2511F9B69346688FE3E5623EF2BEE81E9FAA;
struct WhereArrayIterator_1_t6231D220871B84114C148960F57DC2479C42909F;
struct WhereArrayIterator_1_tA7187088CE8DF4724576F6B7F633203C144505F6;
struct WhereEnumerableIterator_1_t8003EA874EC8867895405A3AB37AFFC5E2B99308;
struct WhereEnumerableIterator_1_t307785595D84CE47B35794516959DED6A6541913;
struct WhereEnumerableIterator_1_t5DBA717695B8C7E60489C86AEB1FF673F50E293A;
struct WhereEnumerableIterator_1_t7F233A4115A2DA7F213075592407137456080374;
struct WhereEnumerableIterator_1_t1E787D13759F5A31C94B3FAED181402B25C278F4;
struct WhereEnumerableIterator_1_tA0D618D4EA7801FF9CD22AE1C91E2DC17F8DC7C8;
struct WhereEnumerableIterator_1_t8B24528558F527941435C4FE1D046216FE4F277B;
struct WhereListIterator_1_t1F690B0B32001794569AD59FAF2DA7A3BD84F4E5;
struct WhereListIterator_1_t519EB7A0906C9C15E2FCF014C1367A494D254C3E;
struct WhereListIterator_1_t1F40F08BAF8586F2C09294085BC605CC2FA432EB;
struct WhereListIterator_1_t758114B160DB8D0A2FAD2AB6D95ABBFFA378664A;
struct WhereListIterator_1_tD37742ECD2F53395BA8B668C2671C4C82E8E85F0;
struct WhereSelectArrayIterator_2_tE62B26B94FCE5CA9F72DF29CD156E5D3147809AB;
struct WhereSelectArrayIterator_2_t9545399CAA4F1FAF69940E5FE8C16D33DDE69BEE;
struct WhereSelectArrayIterator_2_t9CC38AD9D47BA9244379A17890759D5740D5113C;
struct WhereSelectArrayIterator_2_t250814D5FF34B1F8B88A5E8334436BB633B7B29F;
struct WhereSelectArrayIterator_2_t562C68C2C77B3AA5A84BBA4A0B21DB823E66B703;
struct WhereSelectArrayIterator_2_tC80EB6F425911E71B4D4712B7DA01244DF6E7C58;
struct WhereSelectArrayIterator_2_t0565EB3033FAD927C35E0B8525D2ABB0F1FECB40;
struct WhereSelectArrayIterator_2_tF795401649F680CCD3CB35E5CF5B073D7D6B03CB;
struct WhereSelectArrayIterator_2_tBE026CE497BB8F36E31685722BBD7CB567570174;
struct WhereSelectEnumerableIterator_2_tA07904A1CD5E908A2DC6C14712B4B966A86AE0A1;
struct WhereSelectEnumerableIterator_2_t4B528FB254140E926E606C12F0FCC0B34224AD27;
struct WhereSelectEnumerableIterator_2_tB95A85F4BD200CD46FC8E0FF660D1BBC2AA388FF;
struct WhereSelectEnumerableIterator_2_tB03350F7AB4B216F4FAF54A3032ACA3E746AF29D;
struct WhereSelectEnumerableIterator_2_t7BA7CE7768E39319636272B29292281AB152E7D6;
struct WhereSelectEnumerableIterator_2_t585674E4C2106F965D6B51B3B1068924FC97CE0F;
struct WhereSelectEnumerableIterator_2_tDD70C727530B3DBADEB387A0E353F5F829380BF9;
struct WhereSelectEnumerableIterator_2_tE9E39B5B3920248DC542D84A8CFB82C524F6E586;
struct WhereSelectEnumerableIterator_2_t1FBA58379B31F544881FB4C45B2D102F32A71E1C;
struct WhereSelectListIterator_2_t67AC19AA42DBCC5EC6C01ACD9BEE8A2D23A2EEE1;
struct WhereSelectListIterator_2_t984D9217719A2864144A476CBB92FB7754CC788F;
struct WhereSelectListIterator_2_tB5F3E1B3B06A8D74CA5DBD8ACEB44A8F1E549AF6;
struct WhereSelectListIterator_2_t770A927BE7E150C131946093084804F846AF241A;
struct WhereSelectListIterator_2_tFA8E9A90E251C243AA65C041D7421667E9920343;
struct WhereSelectListIterator_2_tC97775A217B6CD43A5FD2A085EE12720F7C3808A;
struct WhereSelectListIterator_2_tB360A4830EF7E0F0829573AE66B167A7996E0E52;
struct WhereSelectListIterator_2_t60681EEE1A6CB8E9C8EE807AA2E2BDA68B9B6989;
struct WhereSelectListIterator_2_t86EE6817E8A1706688C6D82D82C9D44BC99CC336;
struct WithoutCurrentEnumerable_t61691720F7363FB52D0166233D6F1CDEC9A12368;
struct WithoutCurrentEnumerable_tA165573F50CE7FD8626E075AE98BC04DE9B29888;
struct WriteDelegate_t6A0EB21668C92D873ACB875924DE54518D8B7234;
struct WriteDelegate_t737D0DA8D96562AD76BB67D9C5A5199EDB0171E1;
struct WriteDelegate_t907C2DAF3A619B832C6D9441AF1C4CDA7914AF1D;
struct WriteDelegate_tE9F20B5E1A664D239EFDD91143B963A216AAB1C7;
struct WriteDelegate_t023838BBDB83C818E9FDC98ABFA9A9396823E789;
struct WriteDelegate_t98EF2EAAD5827503FF2F0213C32A4961968D75A0;
struct WriteDelegate_t055D02BADD3A5DFA009116D80BC93C235313CAE8;
struct WriteDelegate_tCC7EDE8329D3D4B81ABF643CABCC600B2CC335D7;
struct KeyValuePair_2U5BU5D_t105762EC2DE353037ECAD13437FC19081314CE67;
struct CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB;
struct DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771;
struct Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C;
struct Int32EnumU5BU5D_t87B7DB802810C38016332669039EF42C487A081F;
struct IntPtrU5BU5D_tFD177F8C806A6921AD7150264CCC62FA00CAD832;
struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918;
struct PlayerLoopSystemU5BU5D_t07C04E53AAC3CDA17603E8BA1B41D7E1AC083C6D;
struct StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF;
struct StyleSelectorPartU5BU5D_tBA574FB3E75E94E52874FDB7B05B9048E8A5421B;
struct __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC;
struct ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129;
struct AsyncCallback_t7FEF460CBDCFB9C5FA2EF776984778B9A4145F4C;
struct CancellationCallbackInfo_tC8BE558ED1E173434DD1919D574C9FAFE501E22D;
struct CancellationTokenSource_tAAE1E0033BCFC233801F8CB4CED5C852B350CB7B;
struct Delegate_t;
struct DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E;
struct Exception_t;
struct ExceptionDispatchInfo_tD7AF19E75FEC22F4A8329FD1E9EDF96615CB2757;
struct IAsyncResult_t7B9B5A0ECB35DCEC31B8A8122C37D687369253B5;
struct IDictionary_t6D03155AF1FA9083817AA5B6AD7DEEACC26AB220;
struct MethodInfo_t;
struct SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6;
struct String_t;
struct Type_t;
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915;
struct UpdateFunction_t1C48B7EECBE47AC123A9D9D7D9D2A9EE951C56C4;

IL2CPP_EXTERN_C RuntimeClass* Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Exception_t_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* GC_t920F9CF6EBB7C787E5010A4352E1B587F356DC58_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C String_t* _stringLiteral2ED58924CAB7F8187767CDF1134A1B453FB0EEB0;
IL2CPP_EXTERN_C String_t* _stringLiteral4D8D9C94AC5DA5FCED2EC8A64E10E714A2515C30;
IL2CPP_EXTERN_C String_t* _stringLiteralCF6D423D6F6C1327D40E616C52007CE750F00A62;
IL2CPP_EXTERN_C String_t* _stringLiteralDA39A3EE5E6B4B0D3255BFEF95601890AFD80709;
struct Delegate_t_marshaled_com;
struct Delegate_t_marshaled_pinvoke;
struct Exception_t_marshaled_com;
struct Exception_t_marshaled_pinvoke;
struct PlayerLoopSystem_t8AED6BF1C8A309CAA6FF71AC91DD33BDDFF7CF1F_marshaled_com;
struct PlayerLoopSystem_t8AED6BF1C8A309CAA6FF71AC91DD33BDDFF7CF1F_marshaled_pinvoke;

struct KeyValuePair_2U5BU5D_t105762EC2DE353037ECAD13437FC19081314CE67;
struct DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771;
struct Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C;
struct Int32EnumU5BU5D_t87B7DB802810C38016332669039EF42C487A081F;
struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918;
struct PlayerLoopSystemU5BU5D_t07C04E53AAC3CDA17603E8BA1B41D7E1AC083C6D;
struct StyleSelectorPartU5BU5D_tBA574FB3E75E94E52874FDB7B05B9048E8A5421B;
struct __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC;

IL2CPP_EXTERN_C_BEGIN
IL2CPP_EXTERN_C_END

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
struct U3CU3Ec_t860FEC480E67A73527482CBB87CEC2DA4082C95B  : public RuntimeObject
{
};
struct U3CU3Ec_tCA231E49E5C1E23CB178548188D1AF028B6EA7E5  : public RuntimeObject
{
};
struct U3CU3Ec_t41E2E5F70B53034BC7666F370C8F57BAE82ED004  : public RuntimeObject
{
};
struct Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07  : public RuntimeObject
{
	int32_t ___threadId;
	int32_t ___state;
	int32_t ___current;
};
struct Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA  : public RuntimeObject
{
	int32_t ___threadId;
	int32_t ___state;
	RuntimeObject* ___current;
};
struct Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0 : public RuntimeObject {};
struct List_1_t8A1639802238DEF3222B6CBBC0DEF0B4B5F350EB  : public RuntimeObject
{
	KeyValuePair_2U5BU5D_t105762EC2DE353037ECAD13437FC19081314CE67* ____items;
	int32_t ____size;
	int32_t ____version;
	RuntimeObject* ____syncRoot;
};
struct List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73  : public RuntimeObject
{
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____items;
	int32_t ____size;
	int32_t ____version;
	RuntimeObject* ____syncRoot;
};
struct List_1_tDA4D291C60B1EFA9EA50BBA3367C657CC9410576  : public RuntimeObject
{
	Int32EnumU5BU5D_t87B7DB802810C38016332669039EF42C487A081F* ____items;
	int32_t ____size;
	int32_t ____version;
	RuntimeObject* ____syncRoot;
};
struct List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D  : public RuntimeObject
{
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* ____items;
	int32_t ____size;
	int32_t ____version;
	RuntimeObject* ____syncRoot;
};
struct List_1_tB751FDCEDAE7A97430AD924824F5D0193A720E52  : public RuntimeObject
{
	PlayerLoopSystemU5BU5D_t07C04E53AAC3CDA17603E8BA1B41D7E1AC083C6D* ____items;
	int32_t ____size;
	int32_t ____version;
	RuntimeObject* ____syncRoot;
};
struct List_1_t85FF16594D5F70EECC5855882558F8E26EF6BAFF  : public RuntimeObject
{
	StyleSelectorPartU5BU5D_tBA574FB3E75E94E52874FDB7B05B9048E8A5421B* ____items;
	int32_t ____size;
	int32_t ____version;
	RuntimeObject* ____syncRoot;
};
struct List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A  : public RuntimeObject
{
	__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* ____items;
	int32_t ____size;
	int32_t ____version;
	RuntimeObject* ____syncRoot;
};
struct WhenEachEnumerable_1_t4F973EE64B6BC978974DEFBDBB2EF58E117C0899  : public RuntimeObject
{
	RuntimeObject* ___source;
};
struct WithoutCurrentEnumerable_t61691720F7363FB52D0166233D6F1CDEC9A12368  : public RuntimeObject
{
	AsyncReactiveProperty_1_t55DCE046DB85F4B8B8BFAD7AE879EE536D5F9733* ___parent;
};
struct WithoutCurrentEnumerable_tA165573F50CE7FD8626E075AE98BC04DE9B29888  : public RuntimeObject
{
	ReadOnlyAsyncReactiveProperty_1_tB7349A20B00D8047434C5CDE4CB7EC263380B1E9* ___parent;
};
struct ExceptionDispatchInfo_tD7AF19E75FEC22F4A8329FD1E9EDF96615CB2757  : public RuntimeObject
{
	Exception_t* ___m_Exception;
	RuntimeObject* ___m_stackTrace;
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
struct Enumerator_t9DBCD072C72E44AB8959D9884EF7F528028F20EC 
{
	List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* ____list;
	int32_t ____index;
	int32_t ____version;
	int32_t ____current;
};
struct Enumerator_t9473BAB568A27E2339D48C1F91319E0F6D244D7A 
{
	List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* ____list;
	int32_t ____index;
	int32_t ____version;
	RuntimeObject* ____current;
};
typedef Il2CppFullySharedGenericStruct Enumerator_tF5AC6CD19D283FBD724440520CEE68FE2602F7AF;
struct KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 
{
	RuntimeObject* ___key;
	RuntimeObject* ___value;
};
struct SparselyPopulatedArrayAddInfo_1_t3C73DC53EB2CF8545348E3275C09690FFA1E5359 
{
	SparselyPopulatedArrayFragment_1_tB32DA8C2B7461E80CE4C271B76C103629BDFA035* ____source;
	int32_t ____index;
};
struct TriggerEvent_1_t4D603DB487DB30F0FBD2EE01A6AF71CA4F4476E0 
{
	RuntimeObject* ___head;
	RuntimeObject* ___iteratingHead;
	RuntimeObject* ___iteratingNode;
};
struct UniTaskCompletionSourceCore_1_t9AED094DEF9EF1E050603D158F4FFA169DE3E9D2 
{
	bool ___result;
	RuntimeObject* ___error;
	int16_t ___version;
	bool ___hasUnhandledError;
	int32_t ___completedCount;
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* ___continuation;
	RuntimeObject* ___continuationState;
};
typedef Il2CppFullySharedGenericStruct UniTask_1_t462EA7468BEE3A822B4D759A9930C6DF4DED6483;
typedef Il2CppFullySharedGenericStruct ValueTuple_1_t8587BAAE6DE27A90339279F96A1B89714EE33EAF;
typedef Il2CppFullySharedGenericStruct ValueTuple_2_tBAA1E1D7D97D80E0EBA7FE8773B1FF409AEA3829;
typedef Il2CppFullySharedGenericStruct ValueTuple_3_t182F852EE39DD805E380FD93762C931C933ACE98;
typedef Il2CppFullySharedGenericStruct ValueTuple_8_t9FA0293161A3C9A273444731EEB5DE3CE5186BF0;
typedef Il2CppFullySharedGenericStruct WhenEachResult_1_t56488B449B4BD9DA81B279363A63B1C123605F21;
struct WhereArrayIterator_1_t027D2511F9B69346688FE3E5623EF2BEE81E9FAA  : public Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA
{
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* ___source;
	Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* ___predicate;
	int32_t ___index;
};
struct WhereArrayIterator_1_tA7187088CE8DF4724576F6B7F633203C144505F6 : public RuntimeObject {};
struct WhereEnumerableIterator_1_t5DBA717695B8C7E60489C86AEB1FF673F50E293A  : public Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07
{
	RuntimeObject* ___source;
	Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA* ___predicate;
	RuntimeObject* ___enumerator;
};
struct WhereEnumerableIterator_1_t1E787D13759F5A31C94B3FAED181402B25C278F4  : public Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA
{
	RuntimeObject* ___source;
	Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* ___predicate;
	RuntimeObject* ___enumerator;
};
struct WhereEnumerableIterator_1_t8B24528558F527941435C4FE1D046216FE4F277B : public RuntimeObject {};
struct WhereSelectArrayIterator_2_t9545399CAA4F1FAF69940E5FE8C16D33DDE69BEE  : public Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07
{
	KeyValuePair_2U5BU5D_t105762EC2DE353037ECAD13437FC19081314CE67* ___source;
	Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* ___predicate;
	Func_2_tA526681EE526C81F376160E44520BDC21770A705* ___selector;
	int32_t ___index;
};
struct WhereSelectArrayIterator_2_t9CC38AD9D47BA9244379A17890759D5740D5113C  : public Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA
{
	KeyValuePair_2U5BU5D_t105762EC2DE353037ECAD13437FC19081314CE67* ___source;
	Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* ___predicate;
	Func_2_tF42287527472FA89789873F068A87C60A00EC7D3* ___selector;
	int32_t ___index;
};
struct WhereSelectArrayIterator_2_t250814D5FF34B1F8B88A5E8334436BB633B7B29F  : public Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07
{
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___source;
	Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA* ___predicate;
	Func_2_t2FDA873D8482C79555CFB05233D610E8F1C7C354* ___selector;
	int32_t ___index;
};
struct WhereSelectArrayIterator_2_t562C68C2C77B3AA5A84BBA4A0B21DB823E66B703  : public Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07
{
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* ___source;
	Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* ___predicate;
	Func_2_t9A0D493A82DCC47C9C819A3B045E02D9B5DDCE1B* ___selector;
	int32_t ___index;
};
struct WhereSelectArrayIterator_2_tC80EB6F425911E71B4D4712B7DA01244DF6E7C58  : public Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA
{
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* ___source;
	Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* ___predicate;
	Func_2_tACBF5A1656250800CE861707354491F0611F6624* ___selector;
	int32_t ___index;
};
struct WhereSelectArrayIterator_2_t0565EB3033FAD927C35E0B8525D2ABB0F1FECB40  : public Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07
{
	StyleSelectorPartU5BU5D_tBA574FB3E75E94E52874FDB7B05B9048E8A5421B* ___source;
	Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* ___predicate;
	Func_2_t12F902B64E731F36B1BC057F3AF13BF1D833E1DF* ___selector;
	int32_t ___index;
};
struct WhereSelectArrayIterator_2_tF795401649F680CCD3CB35E5CF5B073D7D6B03CB  : public Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA
{
	StyleSelectorPartU5BU5D_tBA574FB3E75E94E52874FDB7B05B9048E8A5421B* ___source;
	Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* ___predicate;
	Func_2_tFD36EA818BBCBD1EDE1E1540FC3EF156A6ADCCAD* ___selector;
	int32_t ___index;
};
struct WhereSelectArrayIterator_2_tBE026CE497BB8F36E31685722BBD7CB567570174 : public RuntimeObject {};
struct WhereSelectEnumerableIterator_2_t4B528FB254140E926E606C12F0FCC0B34224AD27  : public Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07
{
	RuntimeObject* ___source;
	Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* ___predicate;
	Func_2_tA526681EE526C81F376160E44520BDC21770A705* ___selector;
	RuntimeObject* ___enumerator;
};
struct WhereSelectEnumerableIterator_2_tB95A85F4BD200CD46FC8E0FF660D1BBC2AA388FF  : public Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA
{
	RuntimeObject* ___source;
	Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* ___predicate;
	Func_2_tF42287527472FA89789873F068A87C60A00EC7D3* ___selector;
	RuntimeObject* ___enumerator;
};
struct WhereSelectEnumerableIterator_2_tB03350F7AB4B216F4FAF54A3032ACA3E746AF29D  : public Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07
{
	RuntimeObject* ___source;
	Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA* ___predicate;
	Func_2_t2FDA873D8482C79555CFB05233D610E8F1C7C354* ___selector;
	RuntimeObject* ___enumerator;
};
struct WhereSelectEnumerableIterator_2_t7BA7CE7768E39319636272B29292281AB152E7D6  : public Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07
{
	RuntimeObject* ___source;
	Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* ___predicate;
	Func_2_t9A0D493A82DCC47C9C819A3B045E02D9B5DDCE1B* ___selector;
	RuntimeObject* ___enumerator;
};
struct WhereSelectEnumerableIterator_2_t585674E4C2106F965D6B51B3B1068924FC97CE0F  : public Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA
{
	RuntimeObject* ___source;
	Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* ___predicate;
	Func_2_tACBF5A1656250800CE861707354491F0611F6624* ___selector;
	RuntimeObject* ___enumerator;
};
struct WhereSelectEnumerableIterator_2_tDD70C727530B3DBADEB387A0E353F5F829380BF9  : public Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07
{
	RuntimeObject* ___source;
	Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* ___predicate;
	Func_2_t12F902B64E731F36B1BC057F3AF13BF1D833E1DF* ___selector;
	RuntimeObject* ___enumerator;
};
struct WhereSelectEnumerableIterator_2_tE9E39B5B3920248DC542D84A8CFB82C524F6E586  : public Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA
{
	RuntimeObject* ___source;
	Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* ___predicate;
	Func_2_tFD36EA818BBCBD1EDE1E1540FC3EF156A6ADCCAD* ___selector;
	RuntimeObject* ___enumerator;
};
struct WhereSelectEnumerableIterator_2_t1FBA58379B31F544881FB4C45B2D102F32A71E1C : public RuntimeObject {};
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22 
{
	bool ___m_value;
};
struct CancellationToken_t51142D9C6D7C02D314DA34A6A7988C528992FFED 
{
	CancellationTokenSource_tAAE1E0033BCFC233801F8CB4CED5C852B350CB7B* ____source;
};
struct CancellationToken_t51142D9C6D7C02D314DA34A6A7988C528992FFED_marshaled_pinvoke
{
	CancellationTokenSource_tAAE1E0033BCFC233801F8CB4CED5C852B350CB7B* ____source;
};
struct CancellationToken_t51142D9C6D7C02D314DA34A6A7988C528992FFED_marshaled_com
{
	CancellationTokenSource_tAAE1E0033BCFC233801F8CB4CED5C852B350CB7B* ____source;
};
struct DictionaryEntry_t171080F37B311C25AA9E75888F9C9D703FA721BB 
{
	RuntimeObject* ____key;
	RuntimeObject* ____value;
};
struct DictionaryEntry_t171080F37B311C25AA9E75888F9C9D703FA721BB_marshaled_pinvoke
{
	Il2CppIUnknown* ____key;
	Il2CppIUnknown* ____value;
};
struct DictionaryEntry_t171080F37B311C25AA9E75888F9C9D703FA721BB_marshaled_com
{
	Il2CppIUnknown* ____key;
	Il2CppIUnknown* ____value;
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
struct Int16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175 
{
	int16_t ___m_value;
};
struct Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C 
{
	int32_t ___m_value;
};
struct IntPtr_t 
{
	void* ___m_value;
};
struct Rect_tA04E0F8A1830E767F40FB27ECD8D309303571F0D 
{
	float ___m_XMin;
	float ___m_YMin;
	float ___m_Width;
	float ___m_Height;
};
struct RectInt_t1744D10E1063135DA9D574F95205B98DAC600CB8 
{
	int32_t ___m_XMin;
	int32_t ___m_YMin;
	int32_t ___m_Width;
	int32_t ___m_Height;
};
struct Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C 
{
	float ___m_value;
};
struct Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 
{
	float ___x;
	float ___y;
};
struct Vector2Int_t69B2886EBAB732D9B880565E18E7568F3DE0CE6A 
{
	int32_t ___m_X;
	int32_t ___m_Y;
};
struct Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 
{
	float ___x;
	float ___y;
	float ___z;
};
struct Vector3Int_t65CB06F557251D18A37BD71F3655BA836A357376 
{
	int32_t ___m_X;
	int32_t ___m_Y;
	int32_t ___m_Z;
};
struct Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 
{
	float ___x;
	float ___y;
	float ___z;
	float ___w;
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
struct AsyncReactiveProperty_1_t55DCE046DB85F4B8B8BFAD7AE879EE536D5F9733 : public RuntimeObject {};
typedef Il2CppFullySharedGenericStruct Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C;
struct Enumerator_t81E3046D0BB629D86FAC325CBBF319731C3E36A4 
{
	List_1_t8A1639802238DEF3222B6CBBC0DEF0B4B5F350EB* ____list;
	int32_t ____index;
	int32_t ____version;
	KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 ____current;
};
struct Iterator_1_t6F8827EED7DB0C845108D7DF969A608714128E05  : public RuntimeObject
{
	int32_t ___threadId;
	int32_t ___state;
	KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 ___current;
};
struct Iterator_1_t92BE161457BB4186D87644A87E4C1FAC67B8E430  : public RuntimeObject
{
	int32_t ___threadId;
	int32_t ___state;
	DictionaryEntry_t171080F37B311C25AA9E75888F9C9D703FA721BB ___current;
};
struct ReadOnlyAsyncReactiveProperty_1_tB7349A20B00D8047434C5CDE4CB7EC263380B1E9 : public RuntimeObject {};
typedef Il2CppFullySharedGenericStruct ValueTuple_8_t6754BC4E9DF456199B04B3C66F90A9C6F65C460F;
typedef Il2CppFullySharedGenericStruct ValueTuple_8_tD42E286CF79B463B55FD4A534F1A73E02CAEECC5;
typedef Il2CppFullySharedGenericStruct ValueTuple_8_tF94FE992101922E2A97F08D019A9EBDDA748DCB2;
struct WhereListIterator_1_t1F40F08BAF8586F2C09294085BC605CC2FA432EB  : public Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA
{
	List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* ___source;
	Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* ___predicate;
	Enumerator_t9473BAB568A27E2339D48C1F91319E0F6D244D7A ___enumerator;
};
struct WhereListIterator_1_tD37742ECD2F53395BA8B668C2671C4C82E8E85F0 : public RuntimeObject {};
struct WhereSelectListIterator_2_t770A927BE7E150C131946093084804F846AF241A  : public Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07
{
	List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* ___source;
	Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA* ___predicate;
	Func_2_t2FDA873D8482C79555CFB05233D610E8F1C7C354* ___selector;
	Enumerator_t9DBCD072C72E44AB8959D9884EF7F528028F20EC ___enumerator;
};
struct WhereSelectListIterator_2_tFA8E9A90E251C243AA65C041D7421667E9920343  : public Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07
{
	List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* ___source;
	Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* ___predicate;
	Func_2_t9A0D493A82DCC47C9C819A3B045E02D9B5DDCE1B* ___selector;
	Enumerator_t9473BAB568A27E2339D48C1F91319E0F6D244D7A ___enumerator;
};
struct WhereSelectListIterator_2_tC97775A217B6CD43A5FD2A085EE12720F7C3808A  : public Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA
{
	List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* ___source;
	Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* ___predicate;
	Func_2_tACBF5A1656250800CE861707354491F0611F6624* ___selector;
	Enumerator_t9473BAB568A27E2339D48C1F91319E0F6D244D7A ___enumerator;
};
struct WhereSelectListIterator_2_t86EE6817E8A1706688C6D82D82C9D44BC99CC336 : public RuntimeObject {};
struct CancellationTokenRegistration_tC925A8BC86C629A2A3DA73765FA964A95FC83389 
{
	CancellationCallbackInfo_tC8BE558ED1E173434DD1919D574C9FAFE501E22D* ___m_callbackInfo;
	SparselyPopulatedArrayAddInfo_1_t3C73DC53EB2CF8545348E3275C09690FFA1E5359 ___m_registrationInfo;
};
struct CancellationTokenRegistration_tC925A8BC86C629A2A3DA73765FA964A95FC83389_marshaled_pinvoke
{
	CancellationCallbackInfo_tC8BE558ED1E173434DD1919D574C9FAFE501E22D* ___m_callbackInfo;
	SparselyPopulatedArrayAddInfo_1_t3C73DC53EB2CF8545348E3275C09690FFA1E5359 ___m_registrationInfo;
};
struct CancellationTokenRegistration_tC925A8BC86C629A2A3DA73765FA964A95FC83389_marshaled_com
{
	CancellationCallbackInfo_tC8BE558ED1E173434DD1919D574C9FAFE501E22D* ___m_callbackInfo;
	SparselyPopulatedArrayAddInfo_1_t3C73DC53EB2CF8545348E3275C09690FFA1E5359 ___m_registrationInfo;
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
struct Int32Enum_tCBAC8BA2BFF3A845FA599F303093BBBA374B6F0C 
{
	int32_t ___value__;
};
struct MoveNextSource_tEE80ED59B6626D9814CD4A1DDD53D32F0A9495B5  : public RuntimeObject
{
	UniTaskCompletionSourceCore_1_t9AED094DEF9EF1E050603D158F4FFA169DE3E9D2 ___completionSource;
};
struct PlayerLoopSystem_t8AED6BF1C8A309CAA6FF71AC91DD33BDDFF7CF1F 
{
	Type_t* ___type;
	PlayerLoopSystemU5BU5D_t07C04E53AAC3CDA17603E8BA1B41D7E1AC083C6D* ___subSystemList;
	UpdateFunction_t1C48B7EECBE47AC123A9D9D7D9D2A9EE951C56C4* ___updateDelegate;
	intptr_t ___updateFunction;
	intptr_t ___loopConditionFunction;
};
struct PlayerLoopSystem_t8AED6BF1C8A309CAA6FF71AC91DD33BDDFF7CF1F_marshaled_pinvoke
{
	Type_t* ___type;
	PlayerLoopSystem_t8AED6BF1C8A309CAA6FF71AC91DD33BDDFF7CF1F_marshaled_pinvoke* ___subSystemList;
	Il2CppMethodPointer ___updateDelegate;
	intptr_t ___updateFunction;
	intptr_t ___loopConditionFunction;
};
struct PlayerLoopSystem_t8AED6BF1C8A309CAA6FF71AC91DD33BDDFF7CF1F_marshaled_com
{
	Type_t* ___type;
	PlayerLoopSystem_t8AED6BF1C8A309CAA6FF71AC91DD33BDDFF7CF1F_marshaled_com* ___subSystemList;
	Il2CppMethodPointer ___updateDelegate;
	intptr_t ___updateFunction;
	intptr_t ___loopConditionFunction;
};
struct StyleSelectorType_t425962DE6D175F785FA2B5554D793B71D39430A3 
{
	int32_t ___value__;
};
struct UniTaskStatus_tC898C29839EBB5DB7055C3DF299A2C276237CB70 
{
	int32_t ___value__;
};
struct WhenEachState_t12EBE05811534489FA3C4A357B48C4B423844EAF 
{
	uint8_t ___value__;
};
struct Enumerator_t6209EE23CCD16838DA331AC87789A15508C6C72B 
{
	List_1_tDA4D291C60B1EFA9EA50BBA3367C657CC9410576* ____list;
	int32_t ____index;
	int32_t ____version;
	int32_t ____current;
};
struct Enumerator_tB025B2FCAB9376692902C91754C98265C07AEA9A 
{
	List_1_tB751FDCEDAE7A97430AD924824F5D0193A720E52* ____list;
	int32_t ____index;
	int32_t ____version;
	PlayerLoopSystem_t8AED6BF1C8A309CAA6FF71AC91DD33BDDFF7CF1F ____current;
};
struct Enumerator_t52AB038CB588CDE841350C02AA5D28DAAA6DBA60 : public MoveNextSource_tEE80ED59B6626D9814CD4A1DDD53D32F0A9495B5 {};
struct Enumerator_t2264BA8CF3D7072C596172D20E9E9AB2BF7CF0BE : public MoveNextSource_tEE80ED59B6626D9814CD4A1DDD53D32F0A9495B5 {};
struct Enumerator_t15FA1624E3BE0AC1F3A918185439A63138D413F4  : public RuntimeObject
{
	RuntimeObject* ___source;
	CancellationToken_t51142D9C6D7C02D314DA34A6A7988C528992FFED ___cancellationToken;
	Channel_1_t54EA6F93BD0DB668227D2390918ED6CFA7C02A80* ___channel;
	RuntimeObject* ___channelEnumerator;
	int32_t ___completeCount;
	uint8_t ___state;
};
struct Iterator_1_tEEF82AE11FFC6DF9B283B2D5E4A87B3E3BFD805E  : public RuntimeObject
{
	int32_t ___threadId;
	int32_t ___state;
	int32_t ___current;
};
struct Iterator_1_t90E419394494C38051F176EB657B6E351726C1A5  : public RuntimeObject
{
	int32_t ___threadId;
	int32_t ___state;
	PlayerLoopSystem_t8AED6BF1C8A309CAA6FF71AC91DD33BDDFF7CF1F ___current;
};
struct StateTuple_2_tD239CF0073285A4C6899754787E206EC62F1190E : public RuntimeObject {};
struct StateTuple_2_tC4A9F77640FBC0CC082D17B72B0414FE9A533C0D : public RuntimeObject {};
struct StateTuple_2_tBD3D2F2123018CF69F8DF69AFEC60EC71A57D234 : public RuntimeObject {};
typedef Il2CppFullySharedGenericStruct UniTaskCompletionSourceCore_1_t22222AD93CF9BE9C7488AF5E792E1474E0C9837D;
typedef Il2CppFullySharedGenericStruct UniTaskCompletionSourceCore_1_tA9C7E3CB9001D1F438C1C3BBA224B20995E6A7A2;
typedef Il2CppFullySharedGenericStruct UniTaskCompletionSourceCore_1_t1911EC18C6234A1A4E814CB064F127B40A3F2BD1;
struct WhereArrayIterator_1_t61D2F3529A970E9F412291B961056462F17EDDCB  : public Iterator_1_t6F8827EED7DB0C845108D7DF969A608714128E05
{
	KeyValuePair_2U5BU5D_t105762EC2DE353037ECAD13437FC19081314CE67* ___source;
	Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* ___predicate;
	int32_t ___index;
};
struct WhereEnumerableIterator_1_t8003EA874EC8867895405A3AB37AFFC5E2B99308  : public Iterator_1_t6F8827EED7DB0C845108D7DF969A608714128E05
{
	RuntimeObject* ___source;
	Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* ___predicate;
	RuntimeObject* ___enumerator;
};
struct WhereEnumerableIterator_1_t307785595D84CE47B35794516959DED6A6541913  : public Iterator_1_t92BE161457BB4186D87644A87E4C1FAC67B8E430
{
	RuntimeObject* ___source;
	Func_2_tDBF8C754A8F1FC6DE54BB9904D2D81C266DFF6B4* ___predicate;
	RuntimeObject* ___enumerator;
};
struct WhereListIterator_1_t1F690B0B32001794569AD59FAF2DA7A3BD84F4E5  : public Iterator_1_t6F8827EED7DB0C845108D7DF969A608714128E05
{
	List_1_t8A1639802238DEF3222B6CBBC0DEF0B4B5F350EB* ___source;
	Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* ___predicate;
	Enumerator_t81E3046D0BB629D86FAC325CBBF319731C3E36A4 ___enumerator;
};
struct WhereSelectArrayIterator_2_tE62B26B94FCE5CA9F72DF29CD156E5D3147809AB  : public Iterator_1_t92BE161457BB4186D87644A87E4C1FAC67B8E430
{
	KeyValuePair_2U5BU5D_t105762EC2DE353037ECAD13437FC19081314CE67* ___source;
	Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* ___predicate;
	Func_2_t696684549FAB37B32A9C38A40F33DB777B757E69* ___selector;
	int32_t ___index;
};
struct WhereSelectEnumerableIterator_2_tA07904A1CD5E908A2DC6C14712B4B966A86AE0A1  : public Iterator_1_t92BE161457BB4186D87644A87E4C1FAC67B8E430
{
	RuntimeObject* ___source;
	Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* ___predicate;
	Func_2_t696684549FAB37B32A9C38A40F33DB777B757E69* ___selector;
	RuntimeObject* ___enumerator;
};
struct WhereSelectListIterator_2_t67AC19AA42DBCC5EC6C01ACD9BEE8A2D23A2EEE1  : public Iterator_1_t92BE161457BB4186D87644A87E4C1FAC67B8E430
{
	List_1_t8A1639802238DEF3222B6CBBC0DEF0B4B5F350EB* ___source;
	Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* ___predicate;
	Func_2_t696684549FAB37B32A9C38A40F33DB777B757E69* ___selector;
	Enumerator_t81E3046D0BB629D86FAC325CBBF319731C3E36A4 ___enumerator;
};
struct WhereSelectListIterator_2_t984D9217719A2864144A476CBB92FB7754CC788F  : public Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07
{
	List_1_t8A1639802238DEF3222B6CBBC0DEF0B4B5F350EB* ___source;
	Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* ___predicate;
	Func_2_tA526681EE526C81F376160E44520BDC21770A705* ___selector;
	Enumerator_t81E3046D0BB629D86FAC325CBBF319731C3E36A4 ___enumerator;
};
struct WhereSelectListIterator_2_tB5F3E1B3B06A8D74CA5DBD8ACEB44A8F1E549AF6  : public Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA
{
	List_1_t8A1639802238DEF3222B6CBBC0DEF0B4B5F350EB* ___source;
	Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* ___predicate;
	Func_2_tF42287527472FA89789873F068A87C60A00EC7D3* ___selector;
	Enumerator_t81E3046D0BB629D86FAC325CBBF319731C3E36A4 ___enumerator;
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
struct StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 
{
	String_t* ___m_Value;
	int32_t ___m_Type;
	RuntimeObject* ___tempData;
};
struct StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470_marshaled_pinvoke
{
	char* ___m_Value;
	int32_t ___m_Type;
	Il2CppIUnknown* ___tempData;
};
struct StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470_marshaled_com
{
	Il2CppChar* ___m_Value;
	int32_t ___m_Type;
	Il2CppIUnknown* ___tempData;
};
struct SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295  : public Exception_t
{
};
struct Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87  : public MulticastDelegate_t
{
};
struct Enumerator_t55FB90597665ED8BB37C633F6FD72EFAD48FE20F 
{
	List_1_t85FF16594D5F70EECC5855882558F8E26EF6BAFF* ____list;
	int32_t ____index;
	int32_t ____version;
	StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 ____current;
};
struct Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858  : public MulticastDelegate_t
{
};
struct Func_2_t696684549FAB37B32A9C38A40F33DB777B757E69  : public MulticastDelegate_t
{
};
struct Func_2_tA526681EE526C81F376160E44520BDC21770A705  : public MulticastDelegate_t
{
};
struct Func_2_tF42287527472FA89789873F068A87C60A00EC7D3  : public MulticastDelegate_t
{
};
struct Func_2_tDBF8C754A8F1FC6DE54BB9904D2D81C266DFF6B4  : public MulticastDelegate_t
{
};
struct Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA  : public MulticastDelegate_t
{
};
struct Func_2_t2FDA873D8482C79555CFB05233D610E8F1C7C354  : public MulticastDelegate_t
{
};
struct Func_2_t1C8F983F9A1AA802D45E89037E2AA7ACD1094821  : public MulticastDelegate_t
{
};
struct Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00  : public MulticastDelegate_t
{
};
struct Func_2_t9A0D493A82DCC47C9C819A3B045E02D9B5DDCE1B  : public MulticastDelegate_t
{
};
struct Func_2_tACBF5A1656250800CE861707354491F0611F6624  : public MulticastDelegate_t
{
};
struct Func_2_t92F44173C14E7022E392A8FEA4374C3CD24578EF  : public MulticastDelegate_t
{
};
struct Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A  : public MulticastDelegate_t
{
};
struct Func_2_t12F902B64E731F36B1BC057F3AF13BF1D833E1DF  : public MulticastDelegate_t
{
};
struct Func_2_tFD36EA818BBCBD1EDE1E1540FC3EF156A6ADCCAD  : public MulticastDelegate_t
{
};
struct Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B  : public MulticastDelegate_t
{
};
struct Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0  : public MulticastDelegate_t
{
};
struct WhenAnyPromise_7_t354ACE057C836122798B0B89EB0956841B40C24F : public RuntimeObject {};
struct WhenAnyPromise_8_tB1A18813B231826F7BEE92541715D6266929F072 : public RuntimeObject {};
struct WhenAnyPromise_9_t2D551F16D8A9A247E0C45E7698A6A7A3CCDB7757 : public RuntimeObject {};
struct WhereArrayIterator_1_t8CAF996BCF726E82067F30842CD1885CA4F71D0B  : public Iterator_1_tEEF82AE11FFC6DF9B283B2D5E4A87B3E3BFD805E
{
	Int32EnumU5BU5D_t87B7DB802810C38016332669039EF42C487A081F* ___source;
	Func_2_t1C8F983F9A1AA802D45E89037E2AA7ACD1094821* ___predicate;
	int32_t ___index;
};
struct WhereArrayIterator_1_t6231D220871B84114C148960F57DC2479C42909F  : public Iterator_1_t90E419394494C38051F176EB657B6E351726C1A5
{
	PlayerLoopSystemU5BU5D_t07C04E53AAC3CDA17603E8BA1B41D7E1AC083C6D* ___source;
	Func_2_t92F44173C14E7022E392A8FEA4374C3CD24578EF* ___predicate;
	int32_t ___index;
};
struct WhereEnumerableIterator_1_t7F233A4115A2DA7F213075592407137456080374  : public Iterator_1_tEEF82AE11FFC6DF9B283B2D5E4A87B3E3BFD805E
{
	RuntimeObject* ___source;
	Func_2_t1C8F983F9A1AA802D45E89037E2AA7ACD1094821* ___predicate;
	RuntimeObject* ___enumerator;
};
struct WhereEnumerableIterator_1_tA0D618D4EA7801FF9CD22AE1C91E2DC17F8DC7C8  : public Iterator_1_t90E419394494C38051F176EB657B6E351726C1A5
{
	RuntimeObject* ___source;
	Func_2_t92F44173C14E7022E392A8FEA4374C3CD24578EF* ___predicate;
	RuntimeObject* ___enumerator;
};
struct WhereListIterator_1_t519EB7A0906C9C15E2FCF014C1367A494D254C3E  : public Iterator_1_tEEF82AE11FFC6DF9B283B2D5E4A87B3E3BFD805E
{
	List_1_tDA4D291C60B1EFA9EA50BBA3367C657CC9410576* ___source;
	Func_2_t1C8F983F9A1AA802D45E89037E2AA7ACD1094821* ___predicate;
	Enumerator_t6209EE23CCD16838DA331AC87789A15508C6C72B ___enumerator;
};
struct WhereListIterator_1_t758114B160DB8D0A2FAD2AB6D95ABBFFA378664A  : public Iterator_1_t90E419394494C38051F176EB657B6E351726C1A5
{
	List_1_tB751FDCEDAE7A97430AD924824F5D0193A720E52* ___source;
	Func_2_t92F44173C14E7022E392A8FEA4374C3CD24578EF* ___predicate;
	Enumerator_tB025B2FCAB9376692902C91754C98265C07AEA9A ___enumerator;
};
struct WriteDelegate_t6A0EB21668C92D873ACB875924DE54518D8B7234  : public MulticastDelegate_t
{
};
struct WriteDelegate_t737D0DA8D96562AD76BB67D9C5A5199EDB0171E1  : public MulticastDelegate_t
{
};
struct WriteDelegate_t907C2DAF3A619B832C6D9441AF1C4CDA7914AF1D  : public MulticastDelegate_t
{
};
struct WriteDelegate_tE9F20B5E1A664D239EFDD91143B963A216AAB1C7  : public MulticastDelegate_t
{
};
struct WriteDelegate_t023838BBDB83C818E9FDC98ABFA9A9396823E789  : public MulticastDelegate_t
{
};
struct WriteDelegate_t98EF2EAAD5827503FF2F0213C32A4961968D75A0  : public MulticastDelegate_t
{
};
struct WriteDelegate_t055D02BADD3A5DFA009116D80BC93C235313CAE8  : public MulticastDelegate_t
{
};
struct WriteDelegate_tCC7EDE8329D3D4B81ABF643CABCC600B2CC335D7  : public MulticastDelegate_t
{
};
struct ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263  : public SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295
{
	String_t* ____paramName;
};
struct WhereSelectListIterator_2_tB360A4830EF7E0F0829573AE66B167A7996E0E52  : public Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07
{
	List_1_t85FF16594D5F70EECC5855882558F8E26EF6BAFF* ___source;
	Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* ___predicate;
	Func_2_t12F902B64E731F36B1BC057F3AF13BF1D833E1DF* ___selector;
	Enumerator_t55FB90597665ED8BB37C633F6FD72EFAD48FE20F ___enumerator;
};
struct WhereSelectListIterator_2_t60681EEE1A6CB8E9C8EE807AA2E2BDA68B9B6989  : public Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA
{
	List_1_t85FF16594D5F70EECC5855882558F8E26EF6BAFF* ___source;
	Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* ___predicate;
	Func_2_tFD36EA818BBCBD1EDE1E1540FC3EF156A6ADCCAD* ___selector;
	Enumerator_t55FB90597665ED8BB37C633F6FD72EFAD48FE20F ___enumerator;
};
struct ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129  : public ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263
{
};
struct U3CU3Ec_t860FEC480E67A73527482CBB87CEC2DA4082C95B_StaticFields
{
	U3CU3Ec_t860FEC480E67A73527482CBB87CEC2DA4082C95B* ___U3CU3E9;
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* ___U3CU3E9__2_0;
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* ___U3CU3E9__2_1;
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* ___U3CU3E9__2_2;
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* ___U3CU3E9__2_3;
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* ___U3CU3E9__2_4;
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* ___U3CU3E9__2_5;
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* ___U3CU3E9__2_6;
};
struct U3CU3Ec_tCA231E49E5C1E23CB178548188D1AF028B6EA7E5_StaticFields
{
	U3CU3Ec_tCA231E49E5C1E23CB178548188D1AF028B6EA7E5* ___U3CU3E9;
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* ___U3CU3E9__2_0;
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* ___U3CU3E9__2_1;
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* ___U3CU3E9__2_2;
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* ___U3CU3E9__2_3;
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* ___U3CU3E9__2_4;
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* ___U3CU3E9__2_5;
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* ___U3CU3E9__2_6;
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* ___U3CU3E9__2_7;
};
struct U3CU3Ec_t41E2E5F70B53034BC7666F370C8F57BAE82ED004_StaticFields
{
	U3CU3Ec_t41E2E5F70B53034BC7666F370C8F57BAE82ED004* ___U3CU3E9;
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* ___U3CU3E9__2_0;
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* ___U3CU3E9__2_1;
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* ___U3CU3E9__2_2;
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* ___U3CU3E9__2_3;
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* ___U3CU3E9__2_4;
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* ___U3CU3E9__2_5;
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* ___U3CU3E9__2_6;
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* ___U3CU3E9__2_7;
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* ___U3CU3E9__2_8;
};
struct List_1_t8A1639802238DEF3222B6CBBC0DEF0B4B5F350EB_StaticFields
{
	KeyValuePair_2U5BU5D_t105762EC2DE353037ECAD13437FC19081314CE67* ___s_emptyArray;
};
struct List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73_StaticFields
{
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___s_emptyArray;
};
struct List_1_tDA4D291C60B1EFA9EA50BBA3367C657CC9410576_StaticFields
{
	Int32EnumU5BU5D_t87B7DB802810C38016332669039EF42C487A081F* ___s_emptyArray;
};
struct List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D_StaticFields
{
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* ___s_emptyArray;
};
struct List_1_tB751FDCEDAE7A97430AD924824F5D0193A720E52_StaticFields
{
	PlayerLoopSystemU5BU5D_t07C04E53AAC3CDA17603E8BA1B41D7E1AC083C6D* ___s_emptyArray;
};
struct List_1_t85FF16594D5F70EECC5855882558F8E26EF6BAFF_StaticFields
{
	StyleSelectorPartU5BU5D_tBA574FB3E75E94E52874FDB7B05B9048E8A5421B* ___s_emptyArray;
};
struct List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A_StaticFields
{
	__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* ___s_emptyArray;
};
struct String_t_StaticFields
{
	String_t* ___Empty;
};
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_StaticFields
{
	String_t* ___TrueString;
	String_t* ___FalseString;
};
struct CancellationToken_t51142D9C6D7C02D314DA34A6A7988C528992FFED_StaticFields
{
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* ___s_actionToActionObjShunt;
};
struct IntPtr_t_StaticFields
{
	intptr_t ___Zero;
};
struct Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7_StaticFields
{
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___zeroVector;
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___oneVector;
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___upVector;
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___downVector;
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___leftVector;
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___rightVector;
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___positiveInfinityVector;
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___negativeInfinityVector;
};
struct Vector2Int_t69B2886EBAB732D9B880565E18E7568F3DE0CE6A_StaticFields
{
	Vector2Int_t69B2886EBAB732D9B880565E18E7568F3DE0CE6A ___s_Zero;
	Vector2Int_t69B2886EBAB732D9B880565E18E7568F3DE0CE6A ___s_One;
	Vector2Int_t69B2886EBAB732D9B880565E18E7568F3DE0CE6A ___s_Up;
	Vector2Int_t69B2886EBAB732D9B880565E18E7568F3DE0CE6A ___s_Down;
	Vector2Int_t69B2886EBAB732D9B880565E18E7568F3DE0CE6A ___s_Left;
	Vector2Int_t69B2886EBAB732D9B880565E18E7568F3DE0CE6A ___s_Right;
};
struct Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2_StaticFields
{
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___zeroVector;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___oneVector;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___upVector;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___downVector;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___leftVector;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___rightVector;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___forwardVector;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___backVector;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___positiveInfinityVector;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___negativeInfinityVector;
};
struct Vector3Int_t65CB06F557251D18A37BD71F3655BA836A357376_StaticFields
{
	Vector3Int_t65CB06F557251D18A37BD71F3655BA836A357376 ___s_Zero;
	Vector3Int_t65CB06F557251D18A37BD71F3655BA836A357376 ___s_One;
	Vector3Int_t65CB06F557251D18A37BD71F3655BA836A357376 ___s_Up;
	Vector3Int_t65CB06F557251D18A37BD71F3655BA836A357376 ___s_Down;
	Vector3Int_t65CB06F557251D18A37BD71F3655BA836A357376 ___s_Left;
	Vector3Int_t65CB06F557251D18A37BD71F3655BA836A357376 ___s_Right;
	Vector3Int_t65CB06F557251D18A37BD71F3655BA836A357376 ___s_Forward;
	Vector3Int_t65CB06F557251D18A37BD71F3655BA836A357376 ___s_Back;
};
struct Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3_StaticFields
{
	Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___zeroVector;
	Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___oneVector;
	Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___positiveInfinityVector;
	Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___negativeInfinityVector;
};
struct AsyncReactiveProperty_1_t55DCE046DB85F4B8B8BFAD7AE879EE536D5F9733_StaticFields
{
	bool ___isValueType;
};
struct ReadOnlyAsyncReactiveProperty_1_tB7349A20B00D8047434C5CDE4CB7EC263380B1E9_StaticFields
{
	bool ___isValueType;
};
struct Exception_t_StaticFields
{
	RuntimeObject* ___s_EDILock;
};
struct Enumerator_t52AB038CB588CDE841350C02AA5D28DAAA6DBA60_StaticFields
{
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* ___cancellationCallback;
};
struct Enumerator_t2264BA8CF3D7072C596172D20E9E9AB2BF7CF0BE_StaticFields
{
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* ___cancellationCallback;
};
#ifdef __clang__
#pragma clang diagnostic pop
#endif
struct KeyValuePair_2U5BU5D_t105762EC2DE353037ECAD13437FC19081314CE67  : public RuntimeArray
{
	ALIGN_FIELD (8) KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 m_Items[1];

	inline KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___key), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___value), (void*)NULL);
		#endif
	}
	inline KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___key), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___value), (void*)NULL);
		#endif
	}
};
struct Int32EnumU5BU5D_t87B7DB802810C38016332669039EF42C487A081F  : public RuntimeArray
{
	ALIGN_FIELD (8) int32_t m_Items[1];

	inline int32_t GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline int32_t* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, int32_t value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline int32_t GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline int32_t* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, int32_t value)
	{
		m_Items[index] = value;
	}
};
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
struct PlayerLoopSystemU5BU5D_t07C04E53AAC3CDA17603E8BA1B41D7E1AC083C6D  : public RuntimeArray
{
	ALIGN_FIELD (8) PlayerLoopSystem_t8AED6BF1C8A309CAA6FF71AC91DD33BDDFF7CF1F m_Items[1];

	inline PlayerLoopSystem_t8AED6BF1C8A309CAA6FF71AC91DD33BDDFF7CF1F GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline PlayerLoopSystem_t8AED6BF1C8A309CAA6FF71AC91DD33BDDFF7CF1F* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, PlayerLoopSystem_t8AED6BF1C8A309CAA6FF71AC91DD33BDDFF7CF1F value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___type), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___subSystemList), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___updateDelegate), (void*)NULL);
		#endif
	}
	inline PlayerLoopSystem_t8AED6BF1C8A309CAA6FF71AC91DD33BDDFF7CF1F GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline PlayerLoopSystem_t8AED6BF1C8A309CAA6FF71AC91DD33BDDFF7CF1F* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, PlayerLoopSystem_t8AED6BF1C8A309CAA6FF71AC91DD33BDDFF7CF1F value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___type), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___subSystemList), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___updateDelegate), (void*)NULL);
		#endif
	}
};
struct __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC  : public RuntimeArray
{
	ALIGN_FIELD (8) uint8_t m_Items[1];

	inline uint8_t* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + il2cpp_array_calc_byte_offset(this, index);
	}
	inline uint8_t* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + il2cpp_array_calc_byte_offset(this, index);
	}
};
struct Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C  : public RuntimeArray
{
	ALIGN_FIELD (8) int32_t m_Items[1];

	inline int32_t GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline int32_t* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, int32_t value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline int32_t GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline int32_t* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, int32_t value)
	{
		m_Items[index] = value;
	}
};
struct StyleSelectorPartU5BU5D_tBA574FB3E75E94E52874FDB7B05B9048E8A5421B  : public RuntimeArray
{
	ALIGN_FIELD (8) StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 m_Items[1];

	inline StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___m_Value), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___tempData), (void*)NULL);
		#endif
	}
	inline StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___m_Value), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___tempData), (void*)NULL);
		#endif
	}
};
struct DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771  : public RuntimeArray
{
	ALIGN_FIELD (8) Delegate_t* m_Items[1];

	inline Delegate_t* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline Delegate_t** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, Delegate_t* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline Delegate_t* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline Delegate_t** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, Delegate_t* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};


IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Action_1__ctor_m2E1DFA67718FC1A0B6E5DFEB78831FFE9C059EB4_gshared (Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void ValueTuple_1__ctor_m538A52BFBDA47CC5C05AEE670CAE9D0657D425CB_gshared_inline (ValueTuple_1_t8587BAAE6DE27A90339279F96A1B89714EE33EAF* __this, Il2CppFullySharedGenericAny ___0_item1, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ValueTuple_8__ctor_m456CD331E19E16CE692E636499DF94A47061A7E9_gshared (ValueTuple_8_t9FA0293161A3C9A273444731EEB5DE3CE5186BF0* __this, Il2CppFullySharedGenericAny ___0_item1, Il2CppFullySharedGenericAny ___1_item2, Il2CppFullySharedGenericAny ___2_item3, Il2CppFullySharedGenericAny ___3_item4, Il2CppFullySharedGenericAny ___4_item5, Il2CppFullySharedGenericAny ___5_item6, Il2CppFullySharedGenericAny ___6_item7, Il2CppFullySharedGenericStruct ___7_rest, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ValueTuple_2__ctor_mCAE8E725F680FA6BE2C23B9686C9F6056BB7E5CD_gshared (ValueTuple_2_tBAA1E1D7D97D80E0EBA7FE8773B1FF409AEA3829* __this, Il2CppFullySharedGenericAny ___0_item1, Il2CppFullySharedGenericAny ___1_item2, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ValueTuple_3__ctor_mAB800E7134D8E52646FD55A8B2979AC908028759_gshared (ValueTuple_3_t182F852EE39DD805E380FD93762C931C933ACE98* __this, Il2CppFullySharedGenericAny ___0_item1, Il2CppFullySharedGenericAny ___1_item2, Il2CppFullySharedGenericAny ___2_item3, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void WhenEachResult_1_get_Result_m7C267B764B881AA53B7DFDCF94975161B9022DE8_gshared_inline (WhenEachResult_1_t56488B449B4BD9DA81B279363A63B1C123605F21* __this, Il2CppFullySharedGenericAny* il2cppRetVal, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Exception_t* WhenEachResult_1_get_Exception_m1EC0B9E8E5D8C4AAAD9853628CC5BB8A4EFEF7E2_gshared_inline (WhenEachResult_1_t56488B449B4BD9DA81B279363A63B1C123605F21* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhenEachResult_1_get_IsCompletedSuccessfully_mDAA9246C39928B8BD9E1E452C3683159A50E80C0_gshared (WhenEachResult_1_t56488B449B4BD9DA81B279363A63B1C123605F21* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhenEachResult_1_get_IsFaulted_mB91422296C91DED752CBB5984538F6EEA85D863F_gshared (WhenEachResult_1_t56488B449B4BD9DA81B279363A63B1C123605F21* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhenEachResult_1__ctor_m3E6D66D301C3531A418F5EA4649DD17B2418C8C7_gshared (WhenEachResult_1_t56488B449B4BD9DA81B279363A63B1C123605F21* __this, Il2CppFullySharedGenericAny ___0_result, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhenEachResult_1__ctor_m3A30F2A98DD5A29D5E75F3B406B1C8CC393E816F_gshared (WhenEachResult_1_t56488B449B4BD9DA81B279363A63B1C123605F21* __this, Exception_t* ___0_exception, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhenEachResult_1_TryThrow_mC790F701AFA9FF9F4AF640F26758896F3DD4E794_gshared (WhenEachResult_1_t56488B449B4BD9DA81B279363A63B1C123605F21* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhenEachResult_1_GetResult_m36DB80467A9BC2F26C700CD433F74301BBD77D3E_gshared (WhenEachResult_1_t56488B449B4BD9DA81B279363A63B1C123605F21* __this, Il2CppFullySharedGenericAny* il2cppRetVal, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* WhenEachResult_1_ToString_mA2E309A2B52993DDF9EE78DB72C46233A2FBE84D_gshared (WhenEachResult_1_t56488B449B4BD9DA81B279363A63B1C123605F21* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Iterator_1__ctor_m0D72EABA02C6FB0A61DB8BDD0992DCD58C9C58FC_gshared (Iterator_1_t6F8827EED7DB0C845108D7DF969A608714128E05* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereArrayIterator_1__ctor_m2B8837362AE8ED47437A9B42F6C4DA73311039A9_gshared (WhereArrayIterator_1_t61D2F3529A970E9F412291B961056462F17EDDCB* __this, KeyValuePair_2U5BU5D_t105762EC2DE353037ECAD13437FC19081314CE67* ___0_source, Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* ___1_predicate, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Func_2_Invoke_m18A3A6EDA433C635C66C43DA6B86F7BC746BFDD0_gshared_inline (Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* __this, KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 ___0_arg, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* Enumerable_CombinePredicates_TisKeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230_m9F329AA67F4C35877F54CE7441C4E759BCD33522_gshared (Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* ___0_predicate1, Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* ___1_predicate2, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Iterator_1__ctor_m9788F4EF50A0094F325E620BFC1D32ED3DAE63BB_gshared (Iterator_1_tEEF82AE11FFC6DF9B283B2D5E4A87B3E3BFD805E* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereArrayIterator_1__ctor_m32ED64E416417FA26F29A6AADA0AB6AC46EFAA8E_gshared (WhereArrayIterator_1_t8CAF996BCF726E82067F30842CD1885CA4F71D0B* __this, Int32EnumU5BU5D_t87B7DB802810C38016332669039EF42C487A081F* ___0_source, Func_2_t1C8F983F9A1AA802D45E89037E2AA7ACD1094821* ___1_predicate, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Func_2_Invoke_m095D2006A2DDB336987862DC15A7EFAED53E08EC_gshared_inline (Func_2_t1C8F983F9A1AA802D45E89037E2AA7ACD1094821* __this, int32_t ___0_arg, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Func_2_t1C8F983F9A1AA802D45E89037E2AA7ACD1094821* Enumerable_CombinePredicates_TisInt32Enum_tCBAC8BA2BFF3A845FA599F303093BBBA374B6F0C_m88CBD9562882820B08530454AF5A344C7453C267_gshared (Func_2_t1C8F983F9A1AA802D45E89037E2AA7ACD1094821* ___0_predicate1, Func_2_t1C8F983F9A1AA802D45E89037E2AA7ACD1094821* ___1_predicate2, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Iterator_1__ctor_m3E47867714E05673E54C6B73D9242F5FFADA1F63_gshared (Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereArrayIterator_1__ctor_mC17BAA23BA92C7455512FDA5B1618C6D2B54ACA2_gshared (WhereArrayIterator_1_t027D2511F9B69346688FE3E5623EF2BEE81E9FAA* __this, ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* ___0_source, Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* ___1_predicate, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Func_2_Invoke_m2014423FB900F135C8FF994125604FF9E6AAE829_gshared_inline (Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* __this, RuntimeObject* ___0_arg, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* Enumerable_CombinePredicates_TisRuntimeObject_m613479C29B013E8FC2987E22F42A3BC6CC2C9768_gshared (Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* ___0_predicate1, Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* ___1_predicate2, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Iterator_1__ctor_mF6CD5E26F94CF7F842315D35A872B8C7298BD467_gshared (Iterator_1_t90E419394494C38051F176EB657B6E351726C1A5* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereArrayIterator_1__ctor_m1C57CC91AE53B7ED6FB71FB822B8C1480B667E73_gshared (WhereArrayIterator_1_t6231D220871B84114C148960F57DC2479C42909F* __this, PlayerLoopSystemU5BU5D_t07C04E53AAC3CDA17603E8BA1B41D7E1AC083C6D* ___0_source, Func_2_t92F44173C14E7022E392A8FEA4374C3CD24578EF* ___1_predicate, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Func_2_Invoke_m92C683F52E538828B33BA3E1E37C285A7A73A744_gshared_inline (Func_2_t92F44173C14E7022E392A8FEA4374C3CD24578EF* __this, PlayerLoopSystem_t8AED6BF1C8A309CAA6FF71AC91DD33BDDFF7CF1F ___0_arg, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Func_2_t92F44173C14E7022E392A8FEA4374C3CD24578EF* Enumerable_CombinePredicates_TisPlayerLoopSystem_t8AED6BF1C8A309CAA6FF71AC91DD33BDDFF7CF1F_m5B25B3D43C643FAB7D206EA8F9F4AF8AD600629C_gshared (Func_2_t92F44173C14E7022E392A8FEA4374C3CD24578EF* ___0_predicate1, Func_2_t92F44173C14E7022E392A8FEA4374C3CD24578EF* ___1_predicate2, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereEnumerableIterator_1__ctor_mAC3CB25D22FD92F52FAB86D5A323EFAAD06F1BC1_gshared (WhereEnumerableIterator_1_t8003EA874EC8867895405A3AB37AFFC5E2B99308* __this, RuntimeObject* ___0_source, Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* ___1_predicate, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Iterator_1_Dispose_mB30A8BE0B5B87E0B8FDD55E51D43188B6F238BD1_gshared (Iterator_1_t6F8827EED7DB0C845108D7DF969A608714128E05* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Iterator_1__ctor_m933F57174CB01524F09C26B69041178FE65EE1E2_gshared (Iterator_1_t92BE161457BB4186D87644A87E4C1FAC67B8E430* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereEnumerableIterator_1__ctor_m7A674E2DF8B9F1C27EDB614D6EF6BECFA0B57C1D_gshared (WhereEnumerableIterator_1_t307785595D84CE47B35794516959DED6A6541913* __this, RuntimeObject* ___0_source, Func_2_tDBF8C754A8F1FC6DE54BB9904D2D81C266DFF6B4* ___1_predicate, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Iterator_1_Dispose_m0C3F89201F6D4DCC8782FC7192792E0F19D6A50D_gshared (Iterator_1_t92BE161457BB4186D87644A87E4C1FAC67B8E430* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Func_2_Invoke_mDDB42512D647D9FDCAD0330A12EDB64CAD533A99_gshared_inline (Func_2_tDBF8C754A8F1FC6DE54BB9904D2D81C266DFF6B4* __this, DictionaryEntry_t171080F37B311C25AA9E75888F9C9D703FA721BB ___0_arg, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Func_2_tDBF8C754A8F1FC6DE54BB9904D2D81C266DFF6B4* Enumerable_CombinePredicates_TisDictionaryEntry_t171080F37B311C25AA9E75888F9C9D703FA721BB_mCECAAD107FF8AACD47787010168E5865A658D20C_gshared (Func_2_tDBF8C754A8F1FC6DE54BB9904D2D81C266DFF6B4* ___0_predicate1, Func_2_tDBF8C754A8F1FC6DE54BB9904D2D81C266DFF6B4* ___1_predicate2, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Iterator_1__ctor_m426D8BD95B00FDA5C5E8FAE956FCB74E54BC7CC7_gshared (Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereEnumerableIterator_1__ctor_mA7F4C6508A043D99B8288E43867D576F4697E4EE_gshared (WhereEnumerableIterator_1_t5DBA717695B8C7E60489C86AEB1FF673F50E293A* __this, RuntimeObject* ___0_source, Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA* ___1_predicate, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Iterator_1_Dispose_m93D0EFD9DDA495E64D508A05C5065C6AC5C4A3DB_gshared (Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Func_2_Invoke_m1543D7041BADF87D1F63EBF838B0DDCB40340C7E_gshared_inline (Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA* __this, int32_t ___0_arg, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA* Enumerable_CombinePredicates_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m6E21210FBAD8C39907D331F6A3BE2E5409690ED0_gshared (Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA* ___0_predicate1, Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA* ___1_predicate2, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereEnumerableIterator_1__ctor_m6C929ED5C1A2B964D41834542D001D44C5784AE1_gshared (WhereEnumerableIterator_1_t7F233A4115A2DA7F213075592407137456080374* __this, RuntimeObject* ___0_source, Func_2_t1C8F983F9A1AA802D45E89037E2AA7ACD1094821* ___1_predicate, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Iterator_1_Dispose_m89F7D8F3585BD29529FDA11B1BA731F94A3F1270_gshared (Iterator_1_tEEF82AE11FFC6DF9B283B2D5E4A87B3E3BFD805E* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereEnumerableIterator_1__ctor_m8C0DA4CDA5431C03561F67C4393BB18CDD891F01_gshared (WhereEnumerableIterator_1_t1E787D13759F5A31C94B3FAED181402B25C278F4* __this, RuntimeObject* ___0_source, Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* ___1_predicate, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Iterator_1_Dispose_m953BCF886C8A63456821023DBA45EBD9AC44EB07_gshared (Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereEnumerableIterator_1__ctor_m8B955BCA6F751E2E1C64E3C4C7615E7D55F83C37_gshared (WhereEnumerableIterator_1_tA0D618D4EA7801FF9CD22AE1C91E2DC17F8DC7C8* __this, RuntimeObject* ___0_source, Func_2_t92F44173C14E7022E392A8FEA4374C3CD24578EF* ___1_predicate, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Iterator_1_Dispose_m5E5916CF9E0DA02FA29F58CFA96D30C750292197_gshared (Iterator_1_t90E419394494C38051F176EB657B6E351726C1A5* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereListIterator_1__ctor_m3333DE6CD3476F2462F6D1B996546C42075A6374_gshared (WhereListIterator_1_t1F690B0B32001794569AD59FAF2DA7A3BD84F4E5* __this, List_1_t8A1639802238DEF3222B6CBBC0DEF0B4B5F350EB* ___0_source, Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* ___1_predicate, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_t81E3046D0BB629D86FAC325CBBF319731C3E36A4 List_1_GetEnumerator_mF067420DAFF52D4C46250012FBE1232F35652C7B_gshared (List_1_t8A1639802238DEF3222B6CBBC0DEF0B4B5F350EB* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 Enumerator_get_Current_m2E99DFD369025C91E4B23FA90EE17A41271106A4_gshared_inline (Enumerator_t81E3046D0BB629D86FAC325CBBF319731C3E36A4* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Enumerator_MoveNext_m7303D41C6A0DB6D9A9B9F5923546BF98515E7B39_gshared (Enumerator_t81E3046D0BB629D86FAC325CBBF319731C3E36A4* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereListIterator_1__ctor_m05CE151D6212647A87D227E25199E25869695A13_gshared (WhereListIterator_1_t519EB7A0906C9C15E2FCF014C1367A494D254C3E* __this, List_1_tDA4D291C60B1EFA9EA50BBA3367C657CC9410576* ___0_source, Func_2_t1C8F983F9A1AA802D45E89037E2AA7ACD1094821* ___1_predicate, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_t6209EE23CCD16838DA331AC87789A15508C6C72B List_1_GetEnumerator_m87BBBF3FBB0A4EBF1C2940AA91570D7F1565F60D_gshared (List_1_tDA4D291C60B1EFA9EA50BBA3367C657CC9410576* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Enumerator_get_Current_mB6A201CD563FEF33A6BDA75B83C7BF2AA36CD98C_gshared_inline (Enumerator_t6209EE23CCD16838DA331AC87789A15508C6C72B* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Enumerator_MoveNext_mCAE99D26B8B4D7880B37A70AC8DFD8C7AA4FCCE5_gshared (Enumerator_t6209EE23CCD16838DA331AC87789A15508C6C72B* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereListIterator_1__ctor_mEF8F62B9078E538C1DC46BCB876C2AC5B29EA73B_gshared (WhereListIterator_1_t1F40F08BAF8586F2C09294085BC605CC2FA432EB* __this, List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* ___0_source, Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* ___1_predicate, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_t9473BAB568A27E2339D48C1F91319E0F6D244D7A List_1_GetEnumerator_mD8294A7FA2BEB1929487127D476F8EC1CDC23BFC_gshared (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RuntimeObject* Enumerator_get_Current_m6330F15D18EE4F547C05DF9BF83C5EB710376027_gshared_inline (Enumerator_t9473BAB568A27E2339D48C1F91319E0F6D244D7A* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Enumerator_MoveNext_mE921CC8F29FBBDE7CC3209A0ED0D921D58D00BCB_gshared (Enumerator_t9473BAB568A27E2339D48C1F91319E0F6D244D7A* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereListIterator_1__ctor_mAE63FC161959863AE0A9DACA5FC683E2B8448600_gshared (WhereListIterator_1_t758114B160DB8D0A2FAD2AB6D95ABBFFA378664A* __this, List_1_tB751FDCEDAE7A97430AD924824F5D0193A720E52* ___0_source, Func_2_t92F44173C14E7022E392A8FEA4374C3CD24578EF* ___1_predicate, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_tB025B2FCAB9376692902C91754C98265C07AEA9A List_1_GetEnumerator_mB7A6105C8257C829CB8FE710A42F5C97C70ED72E_gshared (List_1_tB751FDCEDAE7A97430AD924824F5D0193A720E52* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR PlayerLoopSystem_t8AED6BF1C8A309CAA6FF71AC91DD33BDDFF7CF1F Enumerator_get_Current_m0B4ED9AF252261F8FAEF61A9A59B085B4CE88528_gshared_inline (Enumerator_tB025B2FCAB9376692902C91754C98265C07AEA9A* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Enumerator_MoveNext_m8323C42D98FCDA16F05D5351131455C3DD40C66B_gshared (Enumerator_tB025B2FCAB9376692902C91754C98265C07AEA9A* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectArrayIterator_2__ctor_m8296F02CCC8B11B40CCBF3ECD8EBC331A663143E_gshared (WhereSelectArrayIterator_2_tE62B26B94FCE5CA9F72DF29CD156E5D3147809AB* __this, KeyValuePair_2U5BU5D_t105762EC2DE353037ECAD13437FC19081314CE67* ___0_source, Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* ___1_predicate, Func_2_t696684549FAB37B32A9C38A40F33DB777B757E69* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR DictionaryEntry_t171080F37B311C25AA9E75888F9C9D703FA721BB Func_2_Invoke_mFDA9BF3EFEFF70ED1767096A0993BCF4E97414BF_gshared_inline (Func_2_t696684549FAB37B32A9C38A40F33DB777B757E69* __this, KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 ___0_arg, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectArrayIterator_2__ctor_m244B6951BFA16F3362319E9F6233F0D2A1AEEF9B_gshared (WhereSelectArrayIterator_2_t9545399CAA4F1FAF69940E5FE8C16D33DDE69BEE* __this, KeyValuePair_2U5BU5D_t105762EC2DE353037ECAD13437FC19081314CE67* ___0_source, Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* ___1_predicate, Func_2_tA526681EE526C81F376160E44520BDC21770A705* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Func_2_Invoke_m450153F6300275E6112B4346D2EF20A15EB7091E_gshared_inline (Func_2_tA526681EE526C81F376160E44520BDC21770A705* __this, KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 ___0_arg, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectArrayIterator_2__ctor_m383D3735901E9831AC4849D5C0764824A3BAB2D9_gshared (WhereSelectArrayIterator_2_t9CC38AD9D47BA9244379A17890759D5740D5113C* __this, KeyValuePair_2U5BU5D_t105762EC2DE353037ECAD13437FC19081314CE67* ___0_source, Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* ___1_predicate, Func_2_tF42287527472FA89789873F068A87C60A00EC7D3* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RuntimeObject* Func_2_Invoke_m8EC2E5D1BEEA74F624F19C59924823693B9B39A5_gshared_inline (Func_2_tF42287527472FA89789873F068A87C60A00EC7D3* __this, KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 ___0_arg, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectArrayIterator_2__ctor_mA5AF3B283A737C737C53F5DB1B4DA4CA9B682003_gshared (WhereSelectArrayIterator_2_t250814D5FF34B1F8B88A5E8334436BB633B7B29F* __this, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___0_source, Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA* ___1_predicate, Func_2_t2FDA873D8482C79555CFB05233D610E8F1C7C354* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Func_2_Invoke_m1F8EE2DF137BE5132901C0297848BC7A373A676B_gshared_inline (Func_2_t2FDA873D8482C79555CFB05233D610E8F1C7C354* __this, int32_t ___0_arg, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectArrayIterator_2__ctor_m04357D1A96A8C4B96BD7145021AE39DD2C9F2A41_gshared (WhereSelectArrayIterator_2_t562C68C2C77B3AA5A84BBA4A0B21DB823E66B703* __this, ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* ___0_source, Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* ___1_predicate, Func_2_t9A0D493A82DCC47C9C819A3B045E02D9B5DDCE1B* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Func_2_Invoke_m5216F6C7BCECCCED81384876C2968E0D4358618B_gshared_inline (Func_2_t9A0D493A82DCC47C9C819A3B045E02D9B5DDCE1B* __this, RuntimeObject* ___0_arg, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectArrayIterator_2__ctor_m3660F197ECE4BF2A6F8BC99BC8BEF585C9D7BF97_gshared (WhereSelectArrayIterator_2_tC80EB6F425911E71B4D4712B7DA01244DF6E7C58* __this, ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* ___0_source, Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* ___1_predicate, Func_2_tACBF5A1656250800CE861707354491F0611F6624* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RuntimeObject* Func_2_Invoke_mDBA25DA5DA5B7E056FB9B026AF041F1385FB58A9_gshared_inline (Func_2_tACBF5A1656250800CE861707354491F0611F6624* __this, RuntimeObject* ___0_arg, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectArrayIterator_2__ctor_mCFDF5484DEE46045B320C928B40C1DB170ED7221_gshared (WhereSelectArrayIterator_2_t0565EB3033FAD927C35E0B8525D2ABB0F1FECB40* __this, StyleSelectorPartU5BU5D_tBA574FB3E75E94E52874FDB7B05B9048E8A5421B* ___0_source, Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* ___1_predicate, Func_2_t12F902B64E731F36B1BC057F3AF13BF1D833E1DF* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Func_2_Invoke_m7C54973F594216484A4F81A59CDF821AF554339D_gshared_inline (Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* __this, StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 ___0_arg, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Func_2_Invoke_m57961B138A397ADAB0DC71E56519ADBD63327D27_gshared_inline (Func_2_t12F902B64E731F36B1BC057F3AF13BF1D833E1DF* __this, StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 ___0_arg, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectArrayIterator_2__ctor_mC246DFE6E89D80A80900F10D492E7093FF349C47_gshared (WhereSelectArrayIterator_2_tF795401649F680CCD3CB35E5CF5B073D7D6B03CB* __this, StyleSelectorPartU5BU5D_tBA574FB3E75E94E52874FDB7B05B9048E8A5421B* ___0_source, Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* ___1_predicate, Func_2_tFD36EA818BBCBD1EDE1E1540FC3EF156A6ADCCAD* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RuntimeObject* Func_2_Invoke_m1F78C6C79382EA6E74D62E31DD00A9378266A518_gshared_inline (Func_2_tFD36EA818BBCBD1EDE1E1540FC3EF156A6ADCCAD* __this, StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 ___0_arg, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2__ctor_m9B32DF6B14A2CE48A6D0BF78BF9994571F6FC06F_gshared (WhereSelectEnumerableIterator_2_tA07904A1CD5E908A2DC6C14712B4B966A86AE0A1* __this, RuntimeObject* ___0_source, Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* ___1_predicate, Func_2_t696684549FAB37B32A9C38A40F33DB777B757E69* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2__ctor_m3954E3860873975DFAC12A7151C42E9DD36D50B8_gshared (WhereSelectEnumerableIterator_2_t4B528FB254140E926E606C12F0FCC0B34224AD27* __this, RuntimeObject* ___0_source, Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* ___1_predicate, Func_2_tA526681EE526C81F376160E44520BDC21770A705* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2__ctor_m446D9DFA8D6FD6C06663AC92CA2E2E70549BF6DC_gshared (WhereSelectEnumerableIterator_2_tB95A85F4BD200CD46FC8E0FF660D1BBC2AA388FF* __this, RuntimeObject* ___0_source, Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* ___1_predicate, Func_2_tF42287527472FA89789873F068A87C60A00EC7D3* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2__ctor_m96BAED87987DAE93B4E6887AE45943A3E21D4E13_gshared (WhereSelectEnumerableIterator_2_tB03350F7AB4B216F4FAF54A3032ACA3E746AF29D* __this, RuntimeObject* ___0_source, Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA* ___1_predicate, Func_2_t2FDA873D8482C79555CFB05233D610E8F1C7C354* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2__ctor_m7BBD99849FABDA48F6D93BCE742C5B8398B5409F_gshared (WhereSelectEnumerableIterator_2_t7BA7CE7768E39319636272B29292281AB152E7D6* __this, RuntimeObject* ___0_source, Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* ___1_predicate, Func_2_t9A0D493A82DCC47C9C819A3B045E02D9B5DDCE1B* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2__ctor_m2E08505C4CB96CC2AD340B4A2B0D3BF0D6DA01F9_gshared (WhereSelectEnumerableIterator_2_t585674E4C2106F965D6B51B3B1068924FC97CE0F* __this, RuntimeObject* ___0_source, Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* ___1_predicate, Func_2_tACBF5A1656250800CE861707354491F0611F6624* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2__ctor_m646AB1CCB6D9D0F7262BFB41A4D35C6C14C6A4D2_gshared (WhereSelectEnumerableIterator_2_tDD70C727530B3DBADEB387A0E353F5F829380BF9* __this, RuntimeObject* ___0_source, Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* ___1_predicate, Func_2_t12F902B64E731F36B1BC057F3AF13BF1D833E1DF* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2__ctor_m67E0676B846F7D5D13322DFE2366E000F49CCE01_gshared (WhereSelectEnumerableIterator_2_tE9E39B5B3920248DC542D84A8CFB82C524F6E586* __this, RuntimeObject* ___0_source, Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* ___1_predicate, Func_2_tFD36EA818BBCBD1EDE1E1540FC3EF156A6ADCCAD* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectListIterator_2__ctor_m6988AD11F7C5AE41145E6B5A44BEFCB016099702_gshared (WhereSelectListIterator_2_t67AC19AA42DBCC5EC6C01ACD9BEE8A2D23A2EEE1* __this, List_1_t8A1639802238DEF3222B6CBBC0DEF0B4B5F350EB* ___0_source, Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* ___1_predicate, Func_2_t696684549FAB37B32A9C38A40F33DB777B757E69* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectListIterator_2__ctor_m9E7D9C2AC5C4EE62428D630E2153A54CA911CEAF_gshared (WhereSelectListIterator_2_t984D9217719A2864144A476CBB92FB7754CC788F* __this, List_1_t8A1639802238DEF3222B6CBBC0DEF0B4B5F350EB* ___0_source, Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* ___1_predicate, Func_2_tA526681EE526C81F376160E44520BDC21770A705* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectListIterator_2__ctor_m2A8C85666C5A665630499B7FAAF130D59E60BFD1_gshared (WhereSelectListIterator_2_tB5F3E1B3B06A8D74CA5DBD8ACEB44A8F1E549AF6* __this, List_1_t8A1639802238DEF3222B6CBBC0DEF0B4B5F350EB* ___0_source, Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* ___1_predicate, Func_2_tF42287527472FA89789873F068A87C60A00EC7D3* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectListIterator_2__ctor_m42B6E206A0E398E45DA94F8109B58ACE1749F6A4_gshared (WhereSelectListIterator_2_t770A927BE7E150C131946093084804F846AF241A* __this, List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* ___0_source, Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA* ___1_predicate, Func_2_t2FDA873D8482C79555CFB05233D610E8F1C7C354* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_t9DBCD072C72E44AB8959D9884EF7F528028F20EC List_1_GetEnumerator_mCADB185AB483C855873FCD0B1D5AAC909ED7F7BD_gshared (List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Enumerator_get_Current_mB49912FF111A954F2C326BF4FA29A53C1027187B_gshared_inline (Enumerator_t9DBCD072C72E44AB8959D9884EF7F528028F20EC* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Enumerator_MoveNext_m39C71A39758E2B4A04F44F20FCEFAF7009D5F312_gshared (Enumerator_t9DBCD072C72E44AB8959D9884EF7F528028F20EC* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectListIterator_2__ctor_m5658691CD6D5E52B8CB4D7BF7728DF1A36AD99BF_gshared (WhereSelectListIterator_2_tFA8E9A90E251C243AA65C041D7421667E9920343* __this, List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* ___0_source, Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* ___1_predicate, Func_2_t9A0D493A82DCC47C9C819A3B045E02D9B5DDCE1B* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectListIterator_2__ctor_m9CC6A34DCA0012E593221AFBACC4F20664BD876A_gshared (WhereSelectListIterator_2_tC97775A217B6CD43A5FD2A085EE12720F7C3808A* __this, List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* ___0_source, Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* ___1_predicate, Func_2_tACBF5A1656250800CE861707354491F0611F6624* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectListIterator_2__ctor_m6D88E3712F21C182AA3200920A4231559C7E8C64_gshared (WhereSelectListIterator_2_tB360A4830EF7E0F0829573AE66B167A7996E0E52* __this, List_1_t85FF16594D5F70EECC5855882558F8E26EF6BAFF* ___0_source, Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* ___1_predicate, Func_2_t12F902B64E731F36B1BC057F3AF13BF1D833E1DF* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_t55FB90597665ED8BB37C633F6FD72EFAD48FE20F List_1_GetEnumerator_m171CCAFC24F3096494C02B26FB8B10C408952751_gshared (List_1_t85FF16594D5F70EECC5855882558F8E26EF6BAFF* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 Enumerator_get_Current_m4E279E6389EB06C5DBE88A74E3BD3F23FB2B17E4_gshared_inline (Enumerator_t55FB90597665ED8BB37C633F6FD72EFAD48FE20F* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Enumerator_MoveNext_m6A369A40774C06803D46E3D1DBA2874ECFF63E9E_gshared (Enumerator_t55FB90597665ED8BB37C633F6FD72EFAD48FE20F* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectListIterator_2__ctor_m15AA54F3B60B64CEFB048CD88E3A1BD06AC2C62E_gshared (WhereSelectListIterator_2_t60681EEE1A6CB8E9C8EE807AA2E2BDA68B9B6989* __this, List_1_t85FF16594D5F70EECC5855882558F8E26EF6BAFF* ___0_source, Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* ___1_predicate, Func_2_tFD36EA818BBCBD1EDE1E1540FC3EF156A6ADCCAD* ___2_selector, const RuntimeMethod* method) ;

IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2 (RuntimeObject* __this, const RuntimeMethod* method) ;
inline void Action_1__ctor_m2E1DFA67718FC1A0B6E5DFEB78831FFE9C059EB4 (Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method)
{
	((  void (*) (Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87*, RuntimeObject*, intptr_t, const RuntimeMethod*))Action_1__ctor_m2E1DFA67718FC1A0B6E5DFEB78831FFE9C059EB4_gshared)(__this, ___0_object, ___1_method, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Interlocked_Increment_m3C240C32E8D9544EC050B74D4F28EEB58F1F9309 (int32_t* ___0_location, const RuntimeMethod* method) ;
inline void ValueTuple_1__ctor_m538A52BFBDA47CC5C05AEE670CAE9D0657D425CB_inline (ValueTuple_1_t8587BAAE6DE27A90339279F96A1B89714EE33EAF* __this, Il2CppFullySharedGenericAny ___0_item1, const RuntimeMethod* method)
{
	((  void (*) (ValueTuple_1_t8587BAAE6DE27A90339279F96A1B89714EE33EAF*, Il2CppFullySharedGenericAny, const RuntimeMethod*))ValueTuple_1__ctor_m538A52BFBDA47CC5C05AEE670CAE9D0657D425CB_gshared_inline)((ValueTuple_1_t8587BAAE6DE27A90339279F96A1B89714EE33EAF*)__this, ___0_item1, method);
}
inline void ValueTuple_8__ctor_m7A1C59EB1AF84EC5855F92B4C73EC9A96D85BA82 (ValueTuple_8_t6754BC4E9DF456199B04B3C66F90A9C6F65C460F* __this, int32_t ___0_item1, Il2CppFullySharedGenericAny ___1_item2, Il2CppFullySharedGenericAny ___2_item3, Il2CppFullySharedGenericAny ___3_item4, Il2CppFullySharedGenericAny ___4_item5, Il2CppFullySharedGenericAny ___5_item6, Il2CppFullySharedGenericAny ___6_item7, ValueTuple_1_t8587BAAE6DE27A90339279F96A1B89714EE33EAF ___7_rest, const RuntimeMethod* method)
{
	((  void (*) (ValueTuple_8_t9FA0293161A3C9A273444731EEB5DE3CE5186BF0*, Il2CppFullySharedGenericAny, Il2CppFullySharedGenericAny, Il2CppFullySharedGenericAny, Il2CppFullySharedGenericAny, Il2CppFullySharedGenericAny, Il2CppFullySharedGenericAny, Il2CppFullySharedGenericAny, Il2CppFullySharedGenericStruct, const RuntimeMethod*))ValueTuple_8__ctor_m456CD331E19E16CE692E636499DF94A47061A7E9_gshared)((ValueTuple_8_t9FA0293161A3C9A273444731EEB5DE3CE5186BF0*)__this, (Il2CppFullySharedGenericAny)&___0_item1, ___1_item2, ___2_item3, ___3_item4, ___4_item5, ___5_item6, ___6_item7, (Il2CppFullySharedGenericStruct)___7_rest, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GC_SuppressFinalize_m71815DBD5A0CD2EA1BE43317B08B7A14949EDC65 (RuntimeObject* ___0_obj, const RuntimeMethod* method) ;
inline void ValueTuple_2__ctor_mCAE8E725F680FA6BE2C23B9686C9F6056BB7E5CD (ValueTuple_2_tBAA1E1D7D97D80E0EBA7FE8773B1FF409AEA3829* __this, Il2CppFullySharedGenericAny ___0_item1, Il2CppFullySharedGenericAny ___1_item2, const RuntimeMethod* method)
{
	((  void (*) (ValueTuple_2_tBAA1E1D7D97D80E0EBA7FE8773B1FF409AEA3829*, Il2CppFullySharedGenericAny, Il2CppFullySharedGenericAny, const RuntimeMethod*))ValueTuple_2__ctor_mCAE8E725F680FA6BE2C23B9686C9F6056BB7E5CD_gshared)((ValueTuple_2_tBAA1E1D7D97D80E0EBA7FE8773B1FF409AEA3829*)__this, ___0_item1, ___1_item2, method);
}
inline void ValueTuple_8__ctor_m03E5F35F1F6A37FA114EA2D38102DC71B063F122 (ValueTuple_8_tD42E286CF79B463B55FD4A534F1A73E02CAEECC5* __this, int32_t ___0_item1, Il2CppFullySharedGenericAny ___1_item2, Il2CppFullySharedGenericAny ___2_item3, Il2CppFullySharedGenericAny ___3_item4, Il2CppFullySharedGenericAny ___4_item5, Il2CppFullySharedGenericAny ___5_item6, Il2CppFullySharedGenericAny ___6_item7, ValueTuple_2_tBAA1E1D7D97D80E0EBA7FE8773B1FF409AEA3829 ___7_rest, const RuntimeMethod* method)
{
	((  void (*) (ValueTuple_8_t9FA0293161A3C9A273444731EEB5DE3CE5186BF0*, Il2CppFullySharedGenericAny, Il2CppFullySharedGenericAny, Il2CppFullySharedGenericAny, Il2CppFullySharedGenericAny, Il2CppFullySharedGenericAny, Il2CppFullySharedGenericAny, Il2CppFullySharedGenericAny, Il2CppFullySharedGenericStruct, const RuntimeMethod*))ValueTuple_8__ctor_m456CD331E19E16CE692E636499DF94A47061A7E9_gshared)((ValueTuple_8_t9FA0293161A3C9A273444731EEB5DE3CE5186BF0*)__this, (Il2CppFullySharedGenericAny)&___0_item1, ___1_item2, ___2_item3, ___3_item4, ___4_item5, ___5_item6, ___6_item7, (Il2CppFullySharedGenericStruct)___7_rest, method);
}
inline void ValueTuple_3__ctor_mAB800E7134D8E52646FD55A8B2979AC908028759 (ValueTuple_3_t182F852EE39DD805E380FD93762C931C933ACE98* __this, Il2CppFullySharedGenericAny ___0_item1, Il2CppFullySharedGenericAny ___1_item2, Il2CppFullySharedGenericAny ___2_item3, const RuntimeMethod* method)
{
	((  void (*) (ValueTuple_3_t182F852EE39DD805E380FD93762C931C933ACE98*, Il2CppFullySharedGenericAny, Il2CppFullySharedGenericAny, Il2CppFullySharedGenericAny, const RuntimeMethod*))ValueTuple_3__ctor_mAB800E7134D8E52646FD55A8B2979AC908028759_gshared)((ValueTuple_3_t182F852EE39DD805E380FD93762C931C933ACE98*)__this, ___0_item1, ___1_item2, ___2_item3, method);
}
inline void ValueTuple_8__ctor_m5FDE8CF38A97A3D5FC7C364C3467B819664360EE (ValueTuple_8_tF94FE992101922E2A97F08D019A9EBDDA748DCB2* __this, int32_t ___0_item1, Il2CppFullySharedGenericAny ___1_item2, Il2CppFullySharedGenericAny ___2_item3, Il2CppFullySharedGenericAny ___3_item4, Il2CppFullySharedGenericAny ___4_item5, Il2CppFullySharedGenericAny ___5_item6, Il2CppFullySharedGenericAny ___6_item7, ValueTuple_3_t182F852EE39DD805E380FD93762C931C933ACE98 ___7_rest, const RuntimeMethod* method)
{
	((  void (*) (ValueTuple_8_t9FA0293161A3C9A273444731EEB5DE3CE5186BF0*, Il2CppFullySharedGenericAny, Il2CppFullySharedGenericAny, Il2CppFullySharedGenericAny, Il2CppFullySharedGenericAny, Il2CppFullySharedGenericAny, Il2CppFullySharedGenericAny, Il2CppFullySharedGenericAny, Il2CppFullySharedGenericStruct, const RuntimeMethod*))ValueTuple_8__ctor_m456CD331E19E16CE692E636499DF94A47061A7E9_gshared)((ValueTuple_8_t9FA0293161A3C9A273444731EEB5DE3CE5186BF0*)__this, (Il2CppFullySharedGenericAny)&___0_item1, ___1_item2, ___2_item3, ___3_item4, ___4_item5, ___5_item6, ___6_item7, (Il2CppFullySharedGenericStruct)___7_rest, method);
}
inline void WhenEachResult_1_get_Result_m7C267B764B881AA53B7DFDCF94975161B9022DE8_inline (WhenEachResult_1_t56488B449B4BD9DA81B279363A63B1C123605F21* __this, Il2CppFullySharedGenericAny* il2cppRetVal, const RuntimeMethod* method)
{
	((  void (*) (WhenEachResult_1_t56488B449B4BD9DA81B279363A63B1C123605F21*, Il2CppFullySharedGenericAny*, const RuntimeMethod*))WhenEachResult_1_get_Result_m7C267B764B881AA53B7DFDCF94975161B9022DE8_gshared_inline)((WhenEachResult_1_t56488B449B4BD9DA81B279363A63B1C123605F21*)__this, il2cppRetVal, method);
}
inline Exception_t* WhenEachResult_1_get_Exception_m1EC0B9E8E5D8C4AAAD9853628CC5BB8A4EFEF7E2_inline (WhenEachResult_1_t56488B449B4BD9DA81B279363A63B1C123605F21* __this, const RuntimeMethod* method)
{
	return ((  Exception_t* (*) (WhenEachResult_1_t56488B449B4BD9DA81B279363A63B1C123605F21*, const RuntimeMethod*))WhenEachResult_1_get_Exception_m1EC0B9E8E5D8C4AAAD9853628CC5BB8A4EFEF7E2_gshared_inline)(__this, method);
}
inline bool WhenEachResult_1_get_IsCompletedSuccessfully_mDAA9246C39928B8BD9E1E452C3683159A50E80C0 (WhenEachResult_1_t56488B449B4BD9DA81B279363A63B1C123605F21* __this, const RuntimeMethod* method)
{
	return ((  bool (*) (WhenEachResult_1_t56488B449B4BD9DA81B279363A63B1C123605F21*, const RuntimeMethod*))WhenEachResult_1_get_IsCompletedSuccessfully_mDAA9246C39928B8BD9E1E452C3683159A50E80C0_gshared)(__this, method);
}
inline bool WhenEachResult_1_get_IsFaulted_mB91422296C91DED752CBB5984538F6EEA85D863F (WhenEachResult_1_t56488B449B4BD9DA81B279363A63B1C123605F21* __this, const RuntimeMethod* method)
{
	return ((  bool (*) (WhenEachResult_1_t56488B449B4BD9DA81B279363A63B1C123605F21*, const RuntimeMethod*))WhenEachResult_1_get_IsFaulted_mB91422296C91DED752CBB5984538F6EEA85D863F_gshared)(__this, method);
}
inline void WhenEachResult_1__ctor_m3E6D66D301C3531A418F5EA4649DD17B2418C8C7 (WhenEachResult_1_t56488B449B4BD9DA81B279363A63B1C123605F21* __this, Il2CppFullySharedGenericAny ___0_result, const RuntimeMethod* method)
{
	((  void (*) (WhenEachResult_1_t56488B449B4BD9DA81B279363A63B1C123605F21*, Il2CppFullySharedGenericAny, const RuntimeMethod*))WhenEachResult_1__ctor_m3E6D66D301C3531A418F5EA4649DD17B2418C8C7_gshared)((WhenEachResult_1_t56488B449B4BD9DA81B279363A63B1C123605F21*)__this, ___0_result, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* __this, String_t* ___0_paramName, const RuntimeMethod* method) ;
inline void WhenEachResult_1__ctor_m3A30F2A98DD5A29D5E75F3B406B1C8CC393E816F (WhenEachResult_1_t56488B449B4BD9DA81B279363A63B1C123605F21* __this, Exception_t* ___0_exception, const RuntimeMethod* method)
{
	((  void (*) (WhenEachResult_1_t56488B449B4BD9DA81B279363A63B1C123605F21*, Exception_t*, const RuntimeMethod*))WhenEachResult_1__ctor_m3A30F2A98DD5A29D5E75F3B406B1C8CC393E816F_gshared)(__this, ___0_exception, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ExceptionDispatchInfo_tD7AF19E75FEC22F4A8329FD1E9EDF96615CB2757* ExceptionDispatchInfo_Capture_mC1C1C30D83DC04B2B7813DFCB67D07CCD4909803 (Exception_t* ___0_source, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ExceptionDispatchInfo_Throw_m06F398E346AE94C1CCEB636763A8CB26511F6330 (ExceptionDispatchInfo_tD7AF19E75FEC22F4A8329FD1E9EDF96615CB2757* __this, const RuntimeMethod* method) ;
inline void WhenEachResult_1_TryThrow_mC790F701AFA9FF9F4AF640F26758896F3DD4E794 (WhenEachResult_1_t56488B449B4BD9DA81B279363A63B1C123605F21* __this, const RuntimeMethod* method)
{
	((  void (*) (WhenEachResult_1_t56488B449B4BD9DA81B279363A63B1C123605F21*, const RuntimeMethod*))WhenEachResult_1_TryThrow_mC790F701AFA9FF9F4AF640F26758896F3DD4E794_gshared)(__this, method);
}
inline void WhenEachResult_1_GetResult_m36DB80467A9BC2F26C700CD433F74301BBD77D3E (WhenEachResult_1_t56488B449B4BD9DA81B279363A63B1C123605F21* __this, Il2CppFullySharedGenericAny* il2cppRetVal, const RuntimeMethod* method)
{
	((  void (*) (WhenEachResult_1_t56488B449B4BD9DA81B279363A63B1C123605F21*, Il2CppFullySharedGenericAny*, const RuntimeMethod*))WhenEachResult_1_GetResult_m36DB80467A9BC2F26C700CD433F74301BBD77D3E_gshared)((WhenEachResult_1_t56488B449B4BD9DA81B279363A63B1C123605F21*)__this, il2cppRetVal, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* String_Concat_m8855A6DE10F84DA7F4EC113CADDB59873A25573B (String_t* ___0_str0, String_t* ___1_str1, String_t* ___2_str2, const RuntimeMethod* method) ;
inline String_t* WhenEachResult_1_ToString_mA2E309A2B52993DDF9EE78DB72C46233A2FBE84D (WhenEachResult_1_t56488B449B4BD9DA81B279363A63B1C123605F21* __this, const RuntimeMethod* method)
{
	return ((  String_t* (*) (WhenEachResult_1_t56488B449B4BD9DA81B279363A63B1C123605F21*, const RuntimeMethod*))WhenEachResult_1_ToString_mA2E309A2B52993DDF9EE78DB72C46233A2FBE84D_gshared)(__this, method);
}
inline void Iterator_1__ctor_m0D72EABA02C6FB0A61DB8BDD0992DCD58C9C58FC (Iterator_1_t6F8827EED7DB0C845108D7DF969A608714128E05* __this, const RuntimeMethod* method)
{
	((  void (*) (Iterator_1_t6F8827EED7DB0C845108D7DF969A608714128E05*, const RuntimeMethod*))Iterator_1__ctor_m0D72EABA02C6FB0A61DB8BDD0992DCD58C9C58FC_gshared)(__this, method);
}
inline void WhereArrayIterator_1__ctor_m2B8837362AE8ED47437A9B42F6C4DA73311039A9 (WhereArrayIterator_1_t61D2F3529A970E9F412291B961056462F17EDDCB* __this, KeyValuePair_2U5BU5D_t105762EC2DE353037ECAD13437FC19081314CE67* ___0_source, Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* ___1_predicate, const RuntimeMethod* method)
{
	((  void (*) (WhereArrayIterator_1_t61D2F3529A970E9F412291B961056462F17EDDCB*, KeyValuePair_2U5BU5D_t105762EC2DE353037ECAD13437FC19081314CE67*, Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858*, const RuntimeMethod*))WhereArrayIterator_1__ctor_m2B8837362AE8ED47437A9B42F6C4DA73311039A9_gshared)(__this, ___0_source, ___1_predicate, method);
}
inline bool Func_2_Invoke_m18A3A6EDA433C635C66C43DA6B86F7BC746BFDD0_inline (Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* __this, KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 ___0_arg, const RuntimeMethod* method)
{
	return ((  bool (*) (Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858*, KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230, const RuntimeMethod*))Func_2_Invoke_m18A3A6EDA433C635C66C43DA6B86F7BC746BFDD0_gshared_inline)(__this, ___0_arg, method);
}
inline Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* Enumerable_CombinePredicates_TisKeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230_m9F329AA67F4C35877F54CE7441C4E759BCD33522 (Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* ___0_predicate1, Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* ___1_predicate2, const RuntimeMethod* method)
{
	return ((  Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* (*) (Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858*, Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858*, const RuntimeMethod*))Enumerable_CombinePredicates_TisKeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230_m9F329AA67F4C35877F54CE7441C4E759BCD33522_gshared)(___0_predicate1, ___1_predicate2, method);
}
inline void Iterator_1__ctor_m9788F4EF50A0094F325E620BFC1D32ED3DAE63BB (Iterator_1_tEEF82AE11FFC6DF9B283B2D5E4A87B3E3BFD805E* __this, const RuntimeMethod* method)
{
	((  void (*) (Iterator_1_tEEF82AE11FFC6DF9B283B2D5E4A87B3E3BFD805E*, const RuntimeMethod*))Iterator_1__ctor_m9788F4EF50A0094F325E620BFC1D32ED3DAE63BB_gshared)(__this, method);
}
inline void WhereArrayIterator_1__ctor_m32ED64E416417FA26F29A6AADA0AB6AC46EFAA8E (WhereArrayIterator_1_t8CAF996BCF726E82067F30842CD1885CA4F71D0B* __this, Int32EnumU5BU5D_t87B7DB802810C38016332669039EF42C487A081F* ___0_source, Func_2_t1C8F983F9A1AA802D45E89037E2AA7ACD1094821* ___1_predicate, const RuntimeMethod* method)
{
	((  void (*) (WhereArrayIterator_1_t8CAF996BCF726E82067F30842CD1885CA4F71D0B*, Int32EnumU5BU5D_t87B7DB802810C38016332669039EF42C487A081F*, Func_2_t1C8F983F9A1AA802D45E89037E2AA7ACD1094821*, const RuntimeMethod*))WhereArrayIterator_1__ctor_m32ED64E416417FA26F29A6AADA0AB6AC46EFAA8E_gshared)(__this, ___0_source, ___1_predicate, method);
}
inline bool Func_2_Invoke_m095D2006A2DDB336987862DC15A7EFAED53E08EC_inline (Func_2_t1C8F983F9A1AA802D45E89037E2AA7ACD1094821* __this, int32_t ___0_arg, const RuntimeMethod* method)
{
	return ((  bool (*) (Func_2_t1C8F983F9A1AA802D45E89037E2AA7ACD1094821*, int32_t, const RuntimeMethod*))Func_2_Invoke_m095D2006A2DDB336987862DC15A7EFAED53E08EC_gshared_inline)(__this, ___0_arg, method);
}
inline Func_2_t1C8F983F9A1AA802D45E89037E2AA7ACD1094821* Enumerable_CombinePredicates_TisInt32Enum_tCBAC8BA2BFF3A845FA599F303093BBBA374B6F0C_m88CBD9562882820B08530454AF5A344C7453C267 (Func_2_t1C8F983F9A1AA802D45E89037E2AA7ACD1094821* ___0_predicate1, Func_2_t1C8F983F9A1AA802D45E89037E2AA7ACD1094821* ___1_predicate2, const RuntimeMethod* method)
{
	return ((  Func_2_t1C8F983F9A1AA802D45E89037E2AA7ACD1094821* (*) (Func_2_t1C8F983F9A1AA802D45E89037E2AA7ACD1094821*, Func_2_t1C8F983F9A1AA802D45E89037E2AA7ACD1094821*, const RuntimeMethod*))Enumerable_CombinePredicates_TisInt32Enum_tCBAC8BA2BFF3A845FA599F303093BBBA374B6F0C_m88CBD9562882820B08530454AF5A344C7453C267_gshared)(___0_predicate1, ___1_predicate2, method);
}
inline void Iterator_1__ctor_m3E47867714E05673E54C6B73D9242F5FFADA1F63 (Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA* __this, const RuntimeMethod* method)
{
	((  void (*) (Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*, const RuntimeMethod*))Iterator_1__ctor_m3E47867714E05673E54C6B73D9242F5FFADA1F63_gshared)(__this, method);
}
inline void WhereArrayIterator_1__ctor_mC17BAA23BA92C7455512FDA5B1618C6D2B54ACA2 (WhereArrayIterator_1_t027D2511F9B69346688FE3E5623EF2BEE81E9FAA* __this, ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* ___0_source, Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* ___1_predicate, const RuntimeMethod* method)
{
	((  void (*) (WhereArrayIterator_1_t027D2511F9B69346688FE3E5623EF2BEE81E9FAA*, ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*, Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00*, const RuntimeMethod*))WhereArrayIterator_1__ctor_mC17BAA23BA92C7455512FDA5B1618C6D2B54ACA2_gshared)(__this, ___0_source, ___1_predicate, method);
}
inline bool Func_2_Invoke_m2014423FB900F135C8FF994125604FF9E6AAE829_inline (Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* __this, RuntimeObject* ___0_arg, const RuntimeMethod* method)
{
	return ((  bool (*) (Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00*, RuntimeObject*, const RuntimeMethod*))Func_2_Invoke_m2014423FB900F135C8FF994125604FF9E6AAE829_gshared_inline)(__this, ___0_arg, method);
}
inline Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* Enumerable_CombinePredicates_TisRuntimeObject_m613479C29B013E8FC2987E22F42A3BC6CC2C9768 (Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* ___0_predicate1, Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* ___1_predicate2, const RuntimeMethod* method)
{
	return ((  Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* (*) (Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00*, Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00*, const RuntimeMethod*))Enumerable_CombinePredicates_TisRuntimeObject_m613479C29B013E8FC2987E22F42A3BC6CC2C9768_gshared)(___0_predicate1, ___1_predicate2, method);
}
inline void Iterator_1__ctor_mF6CD5E26F94CF7F842315D35A872B8C7298BD467 (Iterator_1_t90E419394494C38051F176EB657B6E351726C1A5* __this, const RuntimeMethod* method)
{
	((  void (*) (Iterator_1_t90E419394494C38051F176EB657B6E351726C1A5*, const RuntimeMethod*))Iterator_1__ctor_mF6CD5E26F94CF7F842315D35A872B8C7298BD467_gshared)(__this, method);
}
inline void WhereArrayIterator_1__ctor_m1C57CC91AE53B7ED6FB71FB822B8C1480B667E73 (WhereArrayIterator_1_t6231D220871B84114C148960F57DC2479C42909F* __this, PlayerLoopSystemU5BU5D_t07C04E53AAC3CDA17603E8BA1B41D7E1AC083C6D* ___0_source, Func_2_t92F44173C14E7022E392A8FEA4374C3CD24578EF* ___1_predicate, const RuntimeMethod* method)
{
	((  void (*) (WhereArrayIterator_1_t6231D220871B84114C148960F57DC2479C42909F*, PlayerLoopSystemU5BU5D_t07C04E53AAC3CDA17603E8BA1B41D7E1AC083C6D*, Func_2_t92F44173C14E7022E392A8FEA4374C3CD24578EF*, const RuntimeMethod*))WhereArrayIterator_1__ctor_m1C57CC91AE53B7ED6FB71FB822B8C1480B667E73_gshared)(__this, ___0_source, ___1_predicate, method);
}
inline bool Func_2_Invoke_m92C683F52E538828B33BA3E1E37C285A7A73A744_inline (Func_2_t92F44173C14E7022E392A8FEA4374C3CD24578EF* __this, PlayerLoopSystem_t8AED6BF1C8A309CAA6FF71AC91DD33BDDFF7CF1F ___0_arg, const RuntimeMethod* method)
{
	return ((  bool (*) (Func_2_t92F44173C14E7022E392A8FEA4374C3CD24578EF*, PlayerLoopSystem_t8AED6BF1C8A309CAA6FF71AC91DD33BDDFF7CF1F, const RuntimeMethod*))Func_2_Invoke_m92C683F52E538828B33BA3E1E37C285A7A73A744_gshared_inline)(__this, ___0_arg, method);
}
inline Func_2_t92F44173C14E7022E392A8FEA4374C3CD24578EF* Enumerable_CombinePredicates_TisPlayerLoopSystem_t8AED6BF1C8A309CAA6FF71AC91DD33BDDFF7CF1F_m5B25B3D43C643FAB7D206EA8F9F4AF8AD600629C (Func_2_t92F44173C14E7022E392A8FEA4374C3CD24578EF* ___0_predicate1, Func_2_t92F44173C14E7022E392A8FEA4374C3CD24578EF* ___1_predicate2, const RuntimeMethod* method)
{
	return ((  Func_2_t92F44173C14E7022E392A8FEA4374C3CD24578EF* (*) (Func_2_t92F44173C14E7022E392A8FEA4374C3CD24578EF*, Func_2_t92F44173C14E7022E392A8FEA4374C3CD24578EF*, const RuntimeMethod*))Enumerable_CombinePredicates_TisPlayerLoopSystem_t8AED6BF1C8A309CAA6FF71AC91DD33BDDFF7CF1F_m5B25B3D43C643FAB7D206EA8F9F4AF8AD600629C_gshared)(___0_predicate1, ___1_predicate2, method);
}
inline void WhereEnumerableIterator_1__ctor_mAC3CB25D22FD92F52FAB86D5A323EFAAD06F1BC1 (WhereEnumerableIterator_1_t8003EA874EC8867895405A3AB37AFFC5E2B99308* __this, RuntimeObject* ___0_source, Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* ___1_predicate, const RuntimeMethod* method)
{
	((  void (*) (WhereEnumerableIterator_1_t8003EA874EC8867895405A3AB37AFFC5E2B99308*, RuntimeObject*, Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858*, const RuntimeMethod*))WhereEnumerableIterator_1__ctor_mAC3CB25D22FD92F52FAB86D5A323EFAAD06F1BC1_gshared)(__this, ___0_source, ___1_predicate, method);
}
inline void Iterator_1_Dispose_mB30A8BE0B5B87E0B8FDD55E51D43188B6F238BD1 (Iterator_1_t6F8827EED7DB0C845108D7DF969A608714128E05* __this, const RuntimeMethod* method)
{
	((  void (*) (Iterator_1_t6F8827EED7DB0C845108D7DF969A608714128E05*, const RuntimeMethod*))Iterator_1_Dispose_mB30A8BE0B5B87E0B8FDD55E51D43188B6F238BD1_gshared)(__this, method);
}
inline void Iterator_1__ctor_m933F57174CB01524F09C26B69041178FE65EE1E2 (Iterator_1_t92BE161457BB4186D87644A87E4C1FAC67B8E430* __this, const RuntimeMethod* method)
{
	((  void (*) (Iterator_1_t92BE161457BB4186D87644A87E4C1FAC67B8E430*, const RuntimeMethod*))Iterator_1__ctor_m933F57174CB01524F09C26B69041178FE65EE1E2_gshared)(__this, method);
}
inline void WhereEnumerableIterator_1__ctor_m7A674E2DF8B9F1C27EDB614D6EF6BECFA0B57C1D (WhereEnumerableIterator_1_t307785595D84CE47B35794516959DED6A6541913* __this, RuntimeObject* ___0_source, Func_2_tDBF8C754A8F1FC6DE54BB9904D2D81C266DFF6B4* ___1_predicate, const RuntimeMethod* method)
{
	((  void (*) (WhereEnumerableIterator_1_t307785595D84CE47B35794516959DED6A6541913*, RuntimeObject*, Func_2_tDBF8C754A8F1FC6DE54BB9904D2D81C266DFF6B4*, const RuntimeMethod*))WhereEnumerableIterator_1__ctor_m7A674E2DF8B9F1C27EDB614D6EF6BECFA0B57C1D_gshared)(__this, ___0_source, ___1_predicate, method);
}
inline void Iterator_1_Dispose_m0C3F89201F6D4DCC8782FC7192792E0F19D6A50D (Iterator_1_t92BE161457BB4186D87644A87E4C1FAC67B8E430* __this, const RuntimeMethod* method)
{
	((  void (*) (Iterator_1_t92BE161457BB4186D87644A87E4C1FAC67B8E430*, const RuntimeMethod*))Iterator_1_Dispose_m0C3F89201F6D4DCC8782FC7192792E0F19D6A50D_gshared)(__this, method);
}
inline bool Func_2_Invoke_mDDB42512D647D9FDCAD0330A12EDB64CAD533A99_inline (Func_2_tDBF8C754A8F1FC6DE54BB9904D2D81C266DFF6B4* __this, DictionaryEntry_t171080F37B311C25AA9E75888F9C9D703FA721BB ___0_arg, const RuntimeMethod* method)
{
	return ((  bool (*) (Func_2_tDBF8C754A8F1FC6DE54BB9904D2D81C266DFF6B4*, DictionaryEntry_t171080F37B311C25AA9E75888F9C9D703FA721BB, const RuntimeMethod*))Func_2_Invoke_mDDB42512D647D9FDCAD0330A12EDB64CAD533A99_gshared_inline)(__this, ___0_arg, method);
}
inline Func_2_tDBF8C754A8F1FC6DE54BB9904D2D81C266DFF6B4* Enumerable_CombinePredicates_TisDictionaryEntry_t171080F37B311C25AA9E75888F9C9D703FA721BB_mCECAAD107FF8AACD47787010168E5865A658D20C (Func_2_tDBF8C754A8F1FC6DE54BB9904D2D81C266DFF6B4* ___0_predicate1, Func_2_tDBF8C754A8F1FC6DE54BB9904D2D81C266DFF6B4* ___1_predicate2, const RuntimeMethod* method)
{
	return ((  Func_2_tDBF8C754A8F1FC6DE54BB9904D2D81C266DFF6B4* (*) (Func_2_tDBF8C754A8F1FC6DE54BB9904D2D81C266DFF6B4*, Func_2_tDBF8C754A8F1FC6DE54BB9904D2D81C266DFF6B4*, const RuntimeMethod*))Enumerable_CombinePredicates_TisDictionaryEntry_t171080F37B311C25AA9E75888F9C9D703FA721BB_mCECAAD107FF8AACD47787010168E5865A658D20C_gshared)(___0_predicate1, ___1_predicate2, method);
}
inline void Iterator_1__ctor_m426D8BD95B00FDA5C5E8FAE956FCB74E54BC7CC7 (Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07* __this, const RuntimeMethod* method)
{
	((  void (*) (Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*, const RuntimeMethod*))Iterator_1__ctor_m426D8BD95B00FDA5C5E8FAE956FCB74E54BC7CC7_gshared)(__this, method);
}
inline void WhereEnumerableIterator_1__ctor_mA7F4C6508A043D99B8288E43867D576F4697E4EE (WhereEnumerableIterator_1_t5DBA717695B8C7E60489C86AEB1FF673F50E293A* __this, RuntimeObject* ___0_source, Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA* ___1_predicate, const RuntimeMethod* method)
{
	((  void (*) (WhereEnumerableIterator_1_t5DBA717695B8C7E60489C86AEB1FF673F50E293A*, RuntimeObject*, Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA*, const RuntimeMethod*))WhereEnumerableIterator_1__ctor_mA7F4C6508A043D99B8288E43867D576F4697E4EE_gshared)(__this, ___0_source, ___1_predicate, method);
}
inline void Iterator_1_Dispose_m93D0EFD9DDA495E64D508A05C5065C6AC5C4A3DB (Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07* __this, const RuntimeMethod* method)
{
	((  void (*) (Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*, const RuntimeMethod*))Iterator_1_Dispose_m93D0EFD9DDA495E64D508A05C5065C6AC5C4A3DB_gshared)(__this, method);
}
inline bool Func_2_Invoke_m1543D7041BADF87D1F63EBF838B0DDCB40340C7E_inline (Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA* __this, int32_t ___0_arg, const RuntimeMethod* method)
{
	return ((  bool (*) (Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA*, int32_t, const RuntimeMethod*))Func_2_Invoke_m1543D7041BADF87D1F63EBF838B0DDCB40340C7E_gshared_inline)(__this, ___0_arg, method);
}
inline Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA* Enumerable_CombinePredicates_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m6E21210FBAD8C39907D331F6A3BE2E5409690ED0 (Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA* ___0_predicate1, Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA* ___1_predicate2, const RuntimeMethod* method)
{
	return ((  Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA* (*) (Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA*, Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA*, const RuntimeMethod*))Enumerable_CombinePredicates_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m6E21210FBAD8C39907D331F6A3BE2E5409690ED0_gshared)(___0_predicate1, ___1_predicate2, method);
}
inline void WhereEnumerableIterator_1__ctor_m6C929ED5C1A2B964D41834542D001D44C5784AE1 (WhereEnumerableIterator_1_t7F233A4115A2DA7F213075592407137456080374* __this, RuntimeObject* ___0_source, Func_2_t1C8F983F9A1AA802D45E89037E2AA7ACD1094821* ___1_predicate, const RuntimeMethod* method)
{
	((  void (*) (WhereEnumerableIterator_1_t7F233A4115A2DA7F213075592407137456080374*, RuntimeObject*, Func_2_t1C8F983F9A1AA802D45E89037E2AA7ACD1094821*, const RuntimeMethod*))WhereEnumerableIterator_1__ctor_m6C929ED5C1A2B964D41834542D001D44C5784AE1_gshared)(__this, ___0_source, ___1_predicate, method);
}
inline void Iterator_1_Dispose_m89F7D8F3585BD29529FDA11B1BA731F94A3F1270 (Iterator_1_tEEF82AE11FFC6DF9B283B2D5E4A87B3E3BFD805E* __this, const RuntimeMethod* method)
{
	((  void (*) (Iterator_1_tEEF82AE11FFC6DF9B283B2D5E4A87B3E3BFD805E*, const RuntimeMethod*))Iterator_1_Dispose_m89F7D8F3585BD29529FDA11B1BA731F94A3F1270_gshared)(__this, method);
}
inline void WhereEnumerableIterator_1__ctor_m8C0DA4CDA5431C03561F67C4393BB18CDD891F01 (WhereEnumerableIterator_1_t1E787D13759F5A31C94B3FAED181402B25C278F4* __this, RuntimeObject* ___0_source, Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* ___1_predicate, const RuntimeMethod* method)
{
	((  void (*) (WhereEnumerableIterator_1_t1E787D13759F5A31C94B3FAED181402B25C278F4*, RuntimeObject*, Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00*, const RuntimeMethod*))WhereEnumerableIterator_1__ctor_m8C0DA4CDA5431C03561F67C4393BB18CDD891F01_gshared)(__this, ___0_source, ___1_predicate, method);
}
inline void Iterator_1_Dispose_m953BCF886C8A63456821023DBA45EBD9AC44EB07 (Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA* __this, const RuntimeMethod* method)
{
	((  void (*) (Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*, const RuntimeMethod*))Iterator_1_Dispose_m953BCF886C8A63456821023DBA45EBD9AC44EB07_gshared)(__this, method);
}
inline void WhereEnumerableIterator_1__ctor_m8B955BCA6F751E2E1C64E3C4C7615E7D55F83C37 (WhereEnumerableIterator_1_tA0D618D4EA7801FF9CD22AE1C91E2DC17F8DC7C8* __this, RuntimeObject* ___0_source, Func_2_t92F44173C14E7022E392A8FEA4374C3CD24578EF* ___1_predicate, const RuntimeMethod* method)
{
	((  void (*) (WhereEnumerableIterator_1_tA0D618D4EA7801FF9CD22AE1C91E2DC17F8DC7C8*, RuntimeObject*, Func_2_t92F44173C14E7022E392A8FEA4374C3CD24578EF*, const RuntimeMethod*))WhereEnumerableIterator_1__ctor_m8B955BCA6F751E2E1C64E3C4C7615E7D55F83C37_gshared)(__this, ___0_source, ___1_predicate, method);
}
inline void Iterator_1_Dispose_m5E5916CF9E0DA02FA29F58CFA96D30C750292197 (Iterator_1_t90E419394494C38051F176EB657B6E351726C1A5* __this, const RuntimeMethod* method)
{
	((  void (*) (Iterator_1_t90E419394494C38051F176EB657B6E351726C1A5*, const RuntimeMethod*))Iterator_1_Dispose_m5E5916CF9E0DA02FA29F58CFA96D30C750292197_gshared)(__this, method);
}
inline void WhereListIterator_1__ctor_m3333DE6CD3476F2462F6D1B996546C42075A6374 (WhereListIterator_1_t1F690B0B32001794569AD59FAF2DA7A3BD84F4E5* __this, List_1_t8A1639802238DEF3222B6CBBC0DEF0B4B5F350EB* ___0_source, Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* ___1_predicate, const RuntimeMethod* method)
{
	((  void (*) (WhereListIterator_1_t1F690B0B32001794569AD59FAF2DA7A3BD84F4E5*, List_1_t8A1639802238DEF3222B6CBBC0DEF0B4B5F350EB*, Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858*, const RuntimeMethod*))WhereListIterator_1__ctor_m3333DE6CD3476F2462F6D1B996546C42075A6374_gshared)(__this, ___0_source, ___1_predicate, method);
}
inline Enumerator_t81E3046D0BB629D86FAC325CBBF319731C3E36A4 List_1_GetEnumerator_mF067420DAFF52D4C46250012FBE1232F35652C7B (List_1_t8A1639802238DEF3222B6CBBC0DEF0B4B5F350EB* __this, const RuntimeMethod* method)
{
	return ((  Enumerator_t81E3046D0BB629D86FAC325CBBF319731C3E36A4 (*) (List_1_t8A1639802238DEF3222B6CBBC0DEF0B4B5F350EB*, const RuntimeMethod*))List_1_GetEnumerator_mF067420DAFF52D4C46250012FBE1232F35652C7B_gshared)(__this, method);
}
inline KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 Enumerator_get_Current_m2E99DFD369025C91E4B23FA90EE17A41271106A4_inline (Enumerator_t81E3046D0BB629D86FAC325CBBF319731C3E36A4* __this, const RuntimeMethod* method)
{
	return ((  KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 (*) (Enumerator_t81E3046D0BB629D86FAC325CBBF319731C3E36A4*, const RuntimeMethod*))Enumerator_get_Current_m2E99DFD369025C91E4B23FA90EE17A41271106A4_gshared_inline)(__this, method);
}
inline bool Enumerator_MoveNext_m7303D41C6A0DB6D9A9B9F5923546BF98515E7B39 (Enumerator_t81E3046D0BB629D86FAC325CBBF319731C3E36A4* __this, const RuntimeMethod* method)
{
	return ((  bool (*) (Enumerator_t81E3046D0BB629D86FAC325CBBF319731C3E36A4*, const RuntimeMethod*))Enumerator_MoveNext_m7303D41C6A0DB6D9A9B9F5923546BF98515E7B39_gshared)(__this, method);
}
inline void WhereListIterator_1__ctor_m05CE151D6212647A87D227E25199E25869695A13 (WhereListIterator_1_t519EB7A0906C9C15E2FCF014C1367A494D254C3E* __this, List_1_tDA4D291C60B1EFA9EA50BBA3367C657CC9410576* ___0_source, Func_2_t1C8F983F9A1AA802D45E89037E2AA7ACD1094821* ___1_predicate, const RuntimeMethod* method)
{
	((  void (*) (WhereListIterator_1_t519EB7A0906C9C15E2FCF014C1367A494D254C3E*, List_1_tDA4D291C60B1EFA9EA50BBA3367C657CC9410576*, Func_2_t1C8F983F9A1AA802D45E89037E2AA7ACD1094821*, const RuntimeMethod*))WhereListIterator_1__ctor_m05CE151D6212647A87D227E25199E25869695A13_gshared)(__this, ___0_source, ___1_predicate, method);
}
inline Enumerator_t6209EE23CCD16838DA331AC87789A15508C6C72B List_1_GetEnumerator_m87BBBF3FBB0A4EBF1C2940AA91570D7F1565F60D (List_1_tDA4D291C60B1EFA9EA50BBA3367C657CC9410576* __this, const RuntimeMethod* method)
{
	return ((  Enumerator_t6209EE23CCD16838DA331AC87789A15508C6C72B (*) (List_1_tDA4D291C60B1EFA9EA50BBA3367C657CC9410576*, const RuntimeMethod*))List_1_GetEnumerator_m87BBBF3FBB0A4EBF1C2940AA91570D7F1565F60D_gshared)(__this, method);
}
inline int32_t Enumerator_get_Current_mB6A201CD563FEF33A6BDA75B83C7BF2AA36CD98C_inline (Enumerator_t6209EE23CCD16838DA331AC87789A15508C6C72B* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (Enumerator_t6209EE23CCD16838DA331AC87789A15508C6C72B*, const RuntimeMethod*))Enumerator_get_Current_mB6A201CD563FEF33A6BDA75B83C7BF2AA36CD98C_gshared_inline)(__this, method);
}
inline bool Enumerator_MoveNext_mCAE99D26B8B4D7880B37A70AC8DFD8C7AA4FCCE5 (Enumerator_t6209EE23CCD16838DA331AC87789A15508C6C72B* __this, const RuntimeMethod* method)
{
	return ((  bool (*) (Enumerator_t6209EE23CCD16838DA331AC87789A15508C6C72B*, const RuntimeMethod*))Enumerator_MoveNext_mCAE99D26B8B4D7880B37A70AC8DFD8C7AA4FCCE5_gshared)(__this, method);
}
inline void WhereListIterator_1__ctor_mEF8F62B9078E538C1DC46BCB876C2AC5B29EA73B (WhereListIterator_1_t1F40F08BAF8586F2C09294085BC605CC2FA432EB* __this, List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* ___0_source, Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* ___1_predicate, const RuntimeMethod* method)
{
	((  void (*) (WhereListIterator_1_t1F40F08BAF8586F2C09294085BC605CC2FA432EB*, List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D*, Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00*, const RuntimeMethod*))WhereListIterator_1__ctor_mEF8F62B9078E538C1DC46BCB876C2AC5B29EA73B_gshared)(__this, ___0_source, ___1_predicate, method);
}
inline Enumerator_t9473BAB568A27E2339D48C1F91319E0F6D244D7A List_1_GetEnumerator_mD8294A7FA2BEB1929487127D476F8EC1CDC23BFC (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, const RuntimeMethod* method)
{
	return ((  Enumerator_t9473BAB568A27E2339D48C1F91319E0F6D244D7A (*) (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D*, const RuntimeMethod*))List_1_GetEnumerator_mD8294A7FA2BEB1929487127D476F8EC1CDC23BFC_gshared)(__this, method);
}
inline RuntimeObject* Enumerator_get_Current_m6330F15D18EE4F547C05DF9BF83C5EB710376027_inline (Enumerator_t9473BAB568A27E2339D48C1F91319E0F6D244D7A* __this, const RuntimeMethod* method)
{
	return ((  RuntimeObject* (*) (Enumerator_t9473BAB568A27E2339D48C1F91319E0F6D244D7A*, const RuntimeMethod*))Enumerator_get_Current_m6330F15D18EE4F547C05DF9BF83C5EB710376027_gshared_inline)(__this, method);
}
inline bool Enumerator_MoveNext_mE921CC8F29FBBDE7CC3209A0ED0D921D58D00BCB (Enumerator_t9473BAB568A27E2339D48C1F91319E0F6D244D7A* __this, const RuntimeMethod* method)
{
	return ((  bool (*) (Enumerator_t9473BAB568A27E2339D48C1F91319E0F6D244D7A*, const RuntimeMethod*))Enumerator_MoveNext_mE921CC8F29FBBDE7CC3209A0ED0D921D58D00BCB_gshared)(__this, method);
}
inline void WhereListIterator_1__ctor_mAE63FC161959863AE0A9DACA5FC683E2B8448600 (WhereListIterator_1_t758114B160DB8D0A2FAD2AB6D95ABBFFA378664A* __this, List_1_tB751FDCEDAE7A97430AD924824F5D0193A720E52* ___0_source, Func_2_t92F44173C14E7022E392A8FEA4374C3CD24578EF* ___1_predicate, const RuntimeMethod* method)
{
	((  void (*) (WhereListIterator_1_t758114B160DB8D0A2FAD2AB6D95ABBFFA378664A*, List_1_tB751FDCEDAE7A97430AD924824F5D0193A720E52*, Func_2_t92F44173C14E7022E392A8FEA4374C3CD24578EF*, const RuntimeMethod*))WhereListIterator_1__ctor_mAE63FC161959863AE0A9DACA5FC683E2B8448600_gshared)(__this, ___0_source, ___1_predicate, method);
}
inline Enumerator_tB025B2FCAB9376692902C91754C98265C07AEA9A List_1_GetEnumerator_mB7A6105C8257C829CB8FE710A42F5C97C70ED72E (List_1_tB751FDCEDAE7A97430AD924824F5D0193A720E52* __this, const RuntimeMethod* method)
{
	return ((  Enumerator_tB025B2FCAB9376692902C91754C98265C07AEA9A (*) (List_1_tB751FDCEDAE7A97430AD924824F5D0193A720E52*, const RuntimeMethod*))List_1_GetEnumerator_mB7A6105C8257C829CB8FE710A42F5C97C70ED72E_gshared)(__this, method);
}
inline PlayerLoopSystem_t8AED6BF1C8A309CAA6FF71AC91DD33BDDFF7CF1F Enumerator_get_Current_m0B4ED9AF252261F8FAEF61A9A59B085B4CE88528_inline (Enumerator_tB025B2FCAB9376692902C91754C98265C07AEA9A* __this, const RuntimeMethod* method)
{
	return ((  PlayerLoopSystem_t8AED6BF1C8A309CAA6FF71AC91DD33BDDFF7CF1F (*) (Enumerator_tB025B2FCAB9376692902C91754C98265C07AEA9A*, const RuntimeMethod*))Enumerator_get_Current_m0B4ED9AF252261F8FAEF61A9A59B085B4CE88528_gshared_inline)(__this, method);
}
inline bool Enumerator_MoveNext_m8323C42D98FCDA16F05D5351131455C3DD40C66B (Enumerator_tB025B2FCAB9376692902C91754C98265C07AEA9A* __this, const RuntimeMethod* method)
{
	return ((  bool (*) (Enumerator_tB025B2FCAB9376692902C91754C98265C07AEA9A*, const RuntimeMethod*))Enumerator_MoveNext_m8323C42D98FCDA16F05D5351131455C3DD40C66B_gshared)(__this, method);
}
inline void WhereSelectArrayIterator_2__ctor_m8296F02CCC8B11B40CCBF3ECD8EBC331A663143E (WhereSelectArrayIterator_2_tE62B26B94FCE5CA9F72DF29CD156E5D3147809AB* __this, KeyValuePair_2U5BU5D_t105762EC2DE353037ECAD13437FC19081314CE67* ___0_source, Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* ___1_predicate, Func_2_t696684549FAB37B32A9C38A40F33DB777B757E69* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectArrayIterator_2_tE62B26B94FCE5CA9F72DF29CD156E5D3147809AB*, KeyValuePair_2U5BU5D_t105762EC2DE353037ECAD13437FC19081314CE67*, Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858*, Func_2_t696684549FAB37B32A9C38A40F33DB777B757E69*, const RuntimeMethod*))WhereSelectArrayIterator_2__ctor_m8296F02CCC8B11B40CCBF3ECD8EBC331A663143E_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline DictionaryEntry_t171080F37B311C25AA9E75888F9C9D703FA721BB Func_2_Invoke_mFDA9BF3EFEFF70ED1767096A0993BCF4E97414BF_inline (Func_2_t696684549FAB37B32A9C38A40F33DB777B757E69* __this, KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 ___0_arg, const RuntimeMethod* method)
{
	return ((  DictionaryEntry_t171080F37B311C25AA9E75888F9C9D703FA721BB (*) (Func_2_t696684549FAB37B32A9C38A40F33DB777B757E69*, KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230, const RuntimeMethod*))Func_2_Invoke_mFDA9BF3EFEFF70ED1767096A0993BCF4E97414BF_gshared_inline)(__this, ___0_arg, method);
}
inline void WhereSelectArrayIterator_2__ctor_m244B6951BFA16F3362319E9F6233F0D2A1AEEF9B (WhereSelectArrayIterator_2_t9545399CAA4F1FAF69940E5FE8C16D33DDE69BEE* __this, KeyValuePair_2U5BU5D_t105762EC2DE353037ECAD13437FC19081314CE67* ___0_source, Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* ___1_predicate, Func_2_tA526681EE526C81F376160E44520BDC21770A705* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectArrayIterator_2_t9545399CAA4F1FAF69940E5FE8C16D33DDE69BEE*, KeyValuePair_2U5BU5D_t105762EC2DE353037ECAD13437FC19081314CE67*, Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858*, Func_2_tA526681EE526C81F376160E44520BDC21770A705*, const RuntimeMethod*))WhereSelectArrayIterator_2__ctor_m244B6951BFA16F3362319E9F6233F0D2A1AEEF9B_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline int32_t Func_2_Invoke_m450153F6300275E6112B4346D2EF20A15EB7091E_inline (Func_2_tA526681EE526C81F376160E44520BDC21770A705* __this, KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 ___0_arg, const RuntimeMethod* method)
{
	return ((  int32_t (*) (Func_2_tA526681EE526C81F376160E44520BDC21770A705*, KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230, const RuntimeMethod*))Func_2_Invoke_m450153F6300275E6112B4346D2EF20A15EB7091E_gshared_inline)(__this, ___0_arg, method);
}
inline void WhereSelectArrayIterator_2__ctor_m383D3735901E9831AC4849D5C0764824A3BAB2D9 (WhereSelectArrayIterator_2_t9CC38AD9D47BA9244379A17890759D5740D5113C* __this, KeyValuePair_2U5BU5D_t105762EC2DE353037ECAD13437FC19081314CE67* ___0_source, Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* ___1_predicate, Func_2_tF42287527472FA89789873F068A87C60A00EC7D3* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectArrayIterator_2_t9CC38AD9D47BA9244379A17890759D5740D5113C*, KeyValuePair_2U5BU5D_t105762EC2DE353037ECAD13437FC19081314CE67*, Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858*, Func_2_tF42287527472FA89789873F068A87C60A00EC7D3*, const RuntimeMethod*))WhereSelectArrayIterator_2__ctor_m383D3735901E9831AC4849D5C0764824A3BAB2D9_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline RuntimeObject* Func_2_Invoke_m8EC2E5D1BEEA74F624F19C59924823693B9B39A5_inline (Func_2_tF42287527472FA89789873F068A87C60A00EC7D3* __this, KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 ___0_arg, const RuntimeMethod* method)
{
	return ((  RuntimeObject* (*) (Func_2_tF42287527472FA89789873F068A87C60A00EC7D3*, KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230, const RuntimeMethod*))Func_2_Invoke_m8EC2E5D1BEEA74F624F19C59924823693B9B39A5_gshared_inline)(__this, ___0_arg, method);
}
inline void WhereSelectArrayIterator_2__ctor_mA5AF3B283A737C737C53F5DB1B4DA4CA9B682003 (WhereSelectArrayIterator_2_t250814D5FF34B1F8B88A5E8334436BB633B7B29F* __this, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___0_source, Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA* ___1_predicate, Func_2_t2FDA873D8482C79555CFB05233D610E8F1C7C354* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectArrayIterator_2_t250814D5FF34B1F8B88A5E8334436BB633B7B29F*, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*, Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA*, Func_2_t2FDA873D8482C79555CFB05233D610E8F1C7C354*, const RuntimeMethod*))WhereSelectArrayIterator_2__ctor_mA5AF3B283A737C737C53F5DB1B4DA4CA9B682003_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline int32_t Func_2_Invoke_m1F8EE2DF137BE5132901C0297848BC7A373A676B_inline (Func_2_t2FDA873D8482C79555CFB05233D610E8F1C7C354* __this, int32_t ___0_arg, const RuntimeMethod* method)
{
	return ((  int32_t (*) (Func_2_t2FDA873D8482C79555CFB05233D610E8F1C7C354*, int32_t, const RuntimeMethod*))Func_2_Invoke_m1F8EE2DF137BE5132901C0297848BC7A373A676B_gshared_inline)(__this, ___0_arg, method);
}
inline void WhereSelectArrayIterator_2__ctor_m04357D1A96A8C4B96BD7145021AE39DD2C9F2A41 (WhereSelectArrayIterator_2_t562C68C2C77B3AA5A84BBA4A0B21DB823E66B703* __this, ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* ___0_source, Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* ___1_predicate, Func_2_t9A0D493A82DCC47C9C819A3B045E02D9B5DDCE1B* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectArrayIterator_2_t562C68C2C77B3AA5A84BBA4A0B21DB823E66B703*, ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*, Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00*, Func_2_t9A0D493A82DCC47C9C819A3B045E02D9B5DDCE1B*, const RuntimeMethod*))WhereSelectArrayIterator_2__ctor_m04357D1A96A8C4B96BD7145021AE39DD2C9F2A41_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline int32_t Func_2_Invoke_m5216F6C7BCECCCED81384876C2968E0D4358618B_inline (Func_2_t9A0D493A82DCC47C9C819A3B045E02D9B5DDCE1B* __this, RuntimeObject* ___0_arg, const RuntimeMethod* method)
{
	return ((  int32_t (*) (Func_2_t9A0D493A82DCC47C9C819A3B045E02D9B5DDCE1B*, RuntimeObject*, const RuntimeMethod*))Func_2_Invoke_m5216F6C7BCECCCED81384876C2968E0D4358618B_gshared_inline)(__this, ___0_arg, method);
}
inline void WhereSelectArrayIterator_2__ctor_m3660F197ECE4BF2A6F8BC99BC8BEF585C9D7BF97 (WhereSelectArrayIterator_2_tC80EB6F425911E71B4D4712B7DA01244DF6E7C58* __this, ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* ___0_source, Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* ___1_predicate, Func_2_tACBF5A1656250800CE861707354491F0611F6624* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectArrayIterator_2_tC80EB6F425911E71B4D4712B7DA01244DF6E7C58*, ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*, Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00*, Func_2_tACBF5A1656250800CE861707354491F0611F6624*, const RuntimeMethod*))WhereSelectArrayIterator_2__ctor_m3660F197ECE4BF2A6F8BC99BC8BEF585C9D7BF97_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline RuntimeObject* Func_2_Invoke_mDBA25DA5DA5B7E056FB9B026AF041F1385FB58A9_inline (Func_2_tACBF5A1656250800CE861707354491F0611F6624* __this, RuntimeObject* ___0_arg, const RuntimeMethod* method)
{
	return ((  RuntimeObject* (*) (Func_2_tACBF5A1656250800CE861707354491F0611F6624*, RuntimeObject*, const RuntimeMethod*))Func_2_Invoke_mDBA25DA5DA5B7E056FB9B026AF041F1385FB58A9_gshared_inline)(__this, ___0_arg, method);
}
inline void WhereSelectArrayIterator_2__ctor_mCFDF5484DEE46045B320C928B40C1DB170ED7221 (WhereSelectArrayIterator_2_t0565EB3033FAD927C35E0B8525D2ABB0F1FECB40* __this, StyleSelectorPartU5BU5D_tBA574FB3E75E94E52874FDB7B05B9048E8A5421B* ___0_source, Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* ___1_predicate, Func_2_t12F902B64E731F36B1BC057F3AF13BF1D833E1DF* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectArrayIterator_2_t0565EB3033FAD927C35E0B8525D2ABB0F1FECB40*, StyleSelectorPartU5BU5D_tBA574FB3E75E94E52874FDB7B05B9048E8A5421B*, Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A*, Func_2_t12F902B64E731F36B1BC057F3AF13BF1D833E1DF*, const RuntimeMethod*))WhereSelectArrayIterator_2__ctor_mCFDF5484DEE46045B320C928B40C1DB170ED7221_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline bool Func_2_Invoke_m7C54973F594216484A4F81A59CDF821AF554339D_inline (Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* __this, StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 ___0_arg, const RuntimeMethod* method)
{
	return ((  bool (*) (Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A*, StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470, const RuntimeMethod*))Func_2_Invoke_m7C54973F594216484A4F81A59CDF821AF554339D_gshared_inline)(__this, ___0_arg, method);
}
inline int32_t Func_2_Invoke_m57961B138A397ADAB0DC71E56519ADBD63327D27_inline (Func_2_t12F902B64E731F36B1BC057F3AF13BF1D833E1DF* __this, StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 ___0_arg, const RuntimeMethod* method)
{
	return ((  int32_t (*) (Func_2_t12F902B64E731F36B1BC057F3AF13BF1D833E1DF*, StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470, const RuntimeMethod*))Func_2_Invoke_m57961B138A397ADAB0DC71E56519ADBD63327D27_gshared_inline)(__this, ___0_arg, method);
}
inline void WhereSelectArrayIterator_2__ctor_mC246DFE6E89D80A80900F10D492E7093FF349C47 (WhereSelectArrayIterator_2_tF795401649F680CCD3CB35E5CF5B073D7D6B03CB* __this, StyleSelectorPartU5BU5D_tBA574FB3E75E94E52874FDB7B05B9048E8A5421B* ___0_source, Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* ___1_predicate, Func_2_tFD36EA818BBCBD1EDE1E1540FC3EF156A6ADCCAD* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectArrayIterator_2_tF795401649F680CCD3CB35E5CF5B073D7D6B03CB*, StyleSelectorPartU5BU5D_tBA574FB3E75E94E52874FDB7B05B9048E8A5421B*, Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A*, Func_2_tFD36EA818BBCBD1EDE1E1540FC3EF156A6ADCCAD*, const RuntimeMethod*))WhereSelectArrayIterator_2__ctor_mC246DFE6E89D80A80900F10D492E7093FF349C47_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline RuntimeObject* Func_2_Invoke_m1F78C6C79382EA6E74D62E31DD00A9378266A518_inline (Func_2_tFD36EA818BBCBD1EDE1E1540FC3EF156A6ADCCAD* __this, StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 ___0_arg, const RuntimeMethod* method)
{
	return ((  RuntimeObject* (*) (Func_2_tFD36EA818BBCBD1EDE1E1540FC3EF156A6ADCCAD*, StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470, const RuntimeMethod*))Func_2_Invoke_m1F78C6C79382EA6E74D62E31DD00A9378266A518_gshared_inline)(__this, ___0_arg, method);
}
inline void WhereSelectEnumerableIterator_2__ctor_m9B32DF6B14A2CE48A6D0BF78BF9994571F6FC06F (WhereSelectEnumerableIterator_2_tA07904A1CD5E908A2DC6C14712B4B966A86AE0A1* __this, RuntimeObject* ___0_source, Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* ___1_predicate, Func_2_t696684549FAB37B32A9C38A40F33DB777B757E69* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectEnumerableIterator_2_tA07904A1CD5E908A2DC6C14712B4B966A86AE0A1*, RuntimeObject*, Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858*, Func_2_t696684549FAB37B32A9C38A40F33DB777B757E69*, const RuntimeMethod*))WhereSelectEnumerableIterator_2__ctor_m9B32DF6B14A2CE48A6D0BF78BF9994571F6FC06F_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline void WhereSelectEnumerableIterator_2__ctor_m3954E3860873975DFAC12A7151C42E9DD36D50B8 (WhereSelectEnumerableIterator_2_t4B528FB254140E926E606C12F0FCC0B34224AD27* __this, RuntimeObject* ___0_source, Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* ___1_predicate, Func_2_tA526681EE526C81F376160E44520BDC21770A705* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectEnumerableIterator_2_t4B528FB254140E926E606C12F0FCC0B34224AD27*, RuntimeObject*, Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858*, Func_2_tA526681EE526C81F376160E44520BDC21770A705*, const RuntimeMethod*))WhereSelectEnumerableIterator_2__ctor_m3954E3860873975DFAC12A7151C42E9DD36D50B8_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline void WhereSelectEnumerableIterator_2__ctor_m446D9DFA8D6FD6C06663AC92CA2E2E70549BF6DC (WhereSelectEnumerableIterator_2_tB95A85F4BD200CD46FC8E0FF660D1BBC2AA388FF* __this, RuntimeObject* ___0_source, Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* ___1_predicate, Func_2_tF42287527472FA89789873F068A87C60A00EC7D3* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectEnumerableIterator_2_tB95A85F4BD200CD46FC8E0FF660D1BBC2AA388FF*, RuntimeObject*, Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858*, Func_2_tF42287527472FA89789873F068A87C60A00EC7D3*, const RuntimeMethod*))WhereSelectEnumerableIterator_2__ctor_m446D9DFA8D6FD6C06663AC92CA2E2E70549BF6DC_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline void WhereSelectEnumerableIterator_2__ctor_m96BAED87987DAE93B4E6887AE45943A3E21D4E13 (WhereSelectEnumerableIterator_2_tB03350F7AB4B216F4FAF54A3032ACA3E746AF29D* __this, RuntimeObject* ___0_source, Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA* ___1_predicate, Func_2_t2FDA873D8482C79555CFB05233D610E8F1C7C354* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectEnumerableIterator_2_tB03350F7AB4B216F4FAF54A3032ACA3E746AF29D*, RuntimeObject*, Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA*, Func_2_t2FDA873D8482C79555CFB05233D610E8F1C7C354*, const RuntimeMethod*))WhereSelectEnumerableIterator_2__ctor_m96BAED87987DAE93B4E6887AE45943A3E21D4E13_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline void WhereSelectEnumerableIterator_2__ctor_m7BBD99849FABDA48F6D93BCE742C5B8398B5409F (WhereSelectEnumerableIterator_2_t7BA7CE7768E39319636272B29292281AB152E7D6* __this, RuntimeObject* ___0_source, Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* ___1_predicate, Func_2_t9A0D493A82DCC47C9C819A3B045E02D9B5DDCE1B* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectEnumerableIterator_2_t7BA7CE7768E39319636272B29292281AB152E7D6*, RuntimeObject*, Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00*, Func_2_t9A0D493A82DCC47C9C819A3B045E02D9B5DDCE1B*, const RuntimeMethod*))WhereSelectEnumerableIterator_2__ctor_m7BBD99849FABDA48F6D93BCE742C5B8398B5409F_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline void WhereSelectEnumerableIterator_2__ctor_m2E08505C4CB96CC2AD340B4A2B0D3BF0D6DA01F9 (WhereSelectEnumerableIterator_2_t585674E4C2106F965D6B51B3B1068924FC97CE0F* __this, RuntimeObject* ___0_source, Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* ___1_predicate, Func_2_tACBF5A1656250800CE861707354491F0611F6624* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectEnumerableIterator_2_t585674E4C2106F965D6B51B3B1068924FC97CE0F*, RuntimeObject*, Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00*, Func_2_tACBF5A1656250800CE861707354491F0611F6624*, const RuntimeMethod*))WhereSelectEnumerableIterator_2__ctor_m2E08505C4CB96CC2AD340B4A2B0D3BF0D6DA01F9_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline void WhereSelectEnumerableIterator_2__ctor_m646AB1CCB6D9D0F7262BFB41A4D35C6C14C6A4D2 (WhereSelectEnumerableIterator_2_tDD70C727530B3DBADEB387A0E353F5F829380BF9* __this, RuntimeObject* ___0_source, Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* ___1_predicate, Func_2_t12F902B64E731F36B1BC057F3AF13BF1D833E1DF* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectEnumerableIterator_2_tDD70C727530B3DBADEB387A0E353F5F829380BF9*, RuntimeObject*, Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A*, Func_2_t12F902B64E731F36B1BC057F3AF13BF1D833E1DF*, const RuntimeMethod*))WhereSelectEnumerableIterator_2__ctor_m646AB1CCB6D9D0F7262BFB41A4D35C6C14C6A4D2_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline void WhereSelectEnumerableIterator_2__ctor_m67E0676B846F7D5D13322DFE2366E000F49CCE01 (WhereSelectEnumerableIterator_2_tE9E39B5B3920248DC542D84A8CFB82C524F6E586* __this, RuntimeObject* ___0_source, Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* ___1_predicate, Func_2_tFD36EA818BBCBD1EDE1E1540FC3EF156A6ADCCAD* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectEnumerableIterator_2_tE9E39B5B3920248DC542D84A8CFB82C524F6E586*, RuntimeObject*, Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A*, Func_2_tFD36EA818BBCBD1EDE1E1540FC3EF156A6ADCCAD*, const RuntimeMethod*))WhereSelectEnumerableIterator_2__ctor_m67E0676B846F7D5D13322DFE2366E000F49CCE01_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline void WhereSelectListIterator_2__ctor_m6988AD11F7C5AE41145E6B5A44BEFCB016099702 (WhereSelectListIterator_2_t67AC19AA42DBCC5EC6C01ACD9BEE8A2D23A2EEE1* __this, List_1_t8A1639802238DEF3222B6CBBC0DEF0B4B5F350EB* ___0_source, Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* ___1_predicate, Func_2_t696684549FAB37B32A9C38A40F33DB777B757E69* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectListIterator_2_t67AC19AA42DBCC5EC6C01ACD9BEE8A2D23A2EEE1*, List_1_t8A1639802238DEF3222B6CBBC0DEF0B4B5F350EB*, Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858*, Func_2_t696684549FAB37B32A9C38A40F33DB777B757E69*, const RuntimeMethod*))WhereSelectListIterator_2__ctor_m6988AD11F7C5AE41145E6B5A44BEFCB016099702_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline void WhereSelectListIterator_2__ctor_m9E7D9C2AC5C4EE62428D630E2153A54CA911CEAF (WhereSelectListIterator_2_t984D9217719A2864144A476CBB92FB7754CC788F* __this, List_1_t8A1639802238DEF3222B6CBBC0DEF0B4B5F350EB* ___0_source, Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* ___1_predicate, Func_2_tA526681EE526C81F376160E44520BDC21770A705* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectListIterator_2_t984D9217719A2864144A476CBB92FB7754CC788F*, List_1_t8A1639802238DEF3222B6CBBC0DEF0B4B5F350EB*, Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858*, Func_2_tA526681EE526C81F376160E44520BDC21770A705*, const RuntimeMethod*))WhereSelectListIterator_2__ctor_m9E7D9C2AC5C4EE62428D630E2153A54CA911CEAF_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline void WhereSelectListIterator_2__ctor_m2A8C85666C5A665630499B7FAAF130D59E60BFD1 (WhereSelectListIterator_2_tB5F3E1B3B06A8D74CA5DBD8ACEB44A8F1E549AF6* __this, List_1_t8A1639802238DEF3222B6CBBC0DEF0B4B5F350EB* ___0_source, Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* ___1_predicate, Func_2_tF42287527472FA89789873F068A87C60A00EC7D3* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectListIterator_2_tB5F3E1B3B06A8D74CA5DBD8ACEB44A8F1E549AF6*, List_1_t8A1639802238DEF3222B6CBBC0DEF0B4B5F350EB*, Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858*, Func_2_tF42287527472FA89789873F068A87C60A00EC7D3*, const RuntimeMethod*))WhereSelectListIterator_2__ctor_m2A8C85666C5A665630499B7FAAF130D59E60BFD1_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline void WhereSelectListIterator_2__ctor_m42B6E206A0E398E45DA94F8109B58ACE1749F6A4 (WhereSelectListIterator_2_t770A927BE7E150C131946093084804F846AF241A* __this, List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* ___0_source, Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA* ___1_predicate, Func_2_t2FDA873D8482C79555CFB05233D610E8F1C7C354* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectListIterator_2_t770A927BE7E150C131946093084804F846AF241A*, List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73*, Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA*, Func_2_t2FDA873D8482C79555CFB05233D610E8F1C7C354*, const RuntimeMethod*))WhereSelectListIterator_2__ctor_m42B6E206A0E398E45DA94F8109B58ACE1749F6A4_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline Enumerator_t9DBCD072C72E44AB8959D9884EF7F528028F20EC List_1_GetEnumerator_mCADB185AB483C855873FCD0B1D5AAC909ED7F7BD (List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* __this, const RuntimeMethod* method)
{
	return ((  Enumerator_t9DBCD072C72E44AB8959D9884EF7F528028F20EC (*) (List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73*, const RuntimeMethod*))List_1_GetEnumerator_mCADB185AB483C855873FCD0B1D5AAC909ED7F7BD_gshared)(__this, method);
}
inline int32_t Enumerator_get_Current_mB49912FF111A954F2C326BF4FA29A53C1027187B_inline (Enumerator_t9DBCD072C72E44AB8959D9884EF7F528028F20EC* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (Enumerator_t9DBCD072C72E44AB8959D9884EF7F528028F20EC*, const RuntimeMethod*))Enumerator_get_Current_mB49912FF111A954F2C326BF4FA29A53C1027187B_gshared_inline)(__this, method);
}
inline bool Enumerator_MoveNext_m39C71A39758E2B4A04F44F20FCEFAF7009D5F312 (Enumerator_t9DBCD072C72E44AB8959D9884EF7F528028F20EC* __this, const RuntimeMethod* method)
{
	return ((  bool (*) (Enumerator_t9DBCD072C72E44AB8959D9884EF7F528028F20EC*, const RuntimeMethod*))Enumerator_MoveNext_m39C71A39758E2B4A04F44F20FCEFAF7009D5F312_gshared)(__this, method);
}
inline void WhereSelectListIterator_2__ctor_m5658691CD6D5E52B8CB4D7BF7728DF1A36AD99BF (WhereSelectListIterator_2_tFA8E9A90E251C243AA65C041D7421667E9920343* __this, List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* ___0_source, Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* ___1_predicate, Func_2_t9A0D493A82DCC47C9C819A3B045E02D9B5DDCE1B* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectListIterator_2_tFA8E9A90E251C243AA65C041D7421667E9920343*, List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D*, Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00*, Func_2_t9A0D493A82DCC47C9C819A3B045E02D9B5DDCE1B*, const RuntimeMethod*))WhereSelectListIterator_2__ctor_m5658691CD6D5E52B8CB4D7BF7728DF1A36AD99BF_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline void WhereSelectListIterator_2__ctor_m9CC6A34DCA0012E593221AFBACC4F20664BD876A (WhereSelectListIterator_2_tC97775A217B6CD43A5FD2A085EE12720F7C3808A* __this, List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* ___0_source, Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* ___1_predicate, Func_2_tACBF5A1656250800CE861707354491F0611F6624* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectListIterator_2_tC97775A217B6CD43A5FD2A085EE12720F7C3808A*, List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D*, Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00*, Func_2_tACBF5A1656250800CE861707354491F0611F6624*, const RuntimeMethod*))WhereSelectListIterator_2__ctor_m9CC6A34DCA0012E593221AFBACC4F20664BD876A_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline void WhereSelectListIterator_2__ctor_m6D88E3712F21C182AA3200920A4231559C7E8C64 (WhereSelectListIterator_2_tB360A4830EF7E0F0829573AE66B167A7996E0E52* __this, List_1_t85FF16594D5F70EECC5855882558F8E26EF6BAFF* ___0_source, Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* ___1_predicate, Func_2_t12F902B64E731F36B1BC057F3AF13BF1D833E1DF* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectListIterator_2_tB360A4830EF7E0F0829573AE66B167A7996E0E52*, List_1_t85FF16594D5F70EECC5855882558F8E26EF6BAFF*, Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A*, Func_2_t12F902B64E731F36B1BC057F3AF13BF1D833E1DF*, const RuntimeMethod*))WhereSelectListIterator_2__ctor_m6D88E3712F21C182AA3200920A4231559C7E8C64_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline Enumerator_t55FB90597665ED8BB37C633F6FD72EFAD48FE20F List_1_GetEnumerator_m171CCAFC24F3096494C02B26FB8B10C408952751 (List_1_t85FF16594D5F70EECC5855882558F8E26EF6BAFF* __this, const RuntimeMethod* method)
{
	return ((  Enumerator_t55FB90597665ED8BB37C633F6FD72EFAD48FE20F (*) (List_1_t85FF16594D5F70EECC5855882558F8E26EF6BAFF*, const RuntimeMethod*))List_1_GetEnumerator_m171CCAFC24F3096494C02B26FB8B10C408952751_gshared)(__this, method);
}
inline StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 Enumerator_get_Current_m4E279E6389EB06C5DBE88A74E3BD3F23FB2B17E4_inline (Enumerator_t55FB90597665ED8BB37C633F6FD72EFAD48FE20F* __this, const RuntimeMethod* method)
{
	return ((  StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 (*) (Enumerator_t55FB90597665ED8BB37C633F6FD72EFAD48FE20F*, const RuntimeMethod*))Enumerator_get_Current_m4E279E6389EB06C5DBE88A74E3BD3F23FB2B17E4_gshared_inline)(__this, method);
}
inline bool Enumerator_MoveNext_m6A369A40774C06803D46E3D1DBA2874ECFF63E9E (Enumerator_t55FB90597665ED8BB37C633F6FD72EFAD48FE20F* __this, const RuntimeMethod* method)
{
	return ((  bool (*) (Enumerator_t55FB90597665ED8BB37C633F6FD72EFAD48FE20F*, const RuntimeMethod*))Enumerator_MoveNext_m6A369A40774C06803D46E3D1DBA2874ECFF63E9E_gshared)(__this, method);
}
inline void WhereSelectListIterator_2__ctor_m15AA54F3B60B64CEFB048CD88E3A1BD06AC2C62E (WhereSelectListIterator_2_t60681EEE1A6CB8E9C8EE807AA2E2BDA68B9B6989* __this, List_1_t85FF16594D5F70EECC5855882558F8E26EF6BAFF* ___0_source, Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* ___1_predicate, Func_2_tFD36EA818BBCBD1EDE1E1540FC3EF156A6ADCCAD* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectListIterator_2_t60681EEE1A6CB8E9C8EE807AA2E2BDA68B9B6989*, List_1_t85FF16594D5F70EECC5855882558F8E26EF6BAFF*, Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A*, Func_2_tFD36EA818BBCBD1EDE1E1540FC3EF156A6ADCCAD*, const RuntimeMethod*))WhereSelectListIterator_2__ctor_m15AA54F3B60B64CEFB048CD88E3A1BD06AC2C62E_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhenAnyPromise_7__ctor_m3ACDE0767E6D4818B814193CE0FEEAF0A341AE02_gshared (WhenAnyPromise_7_t354ACE057C836122798B0B89EB0956841B40C24F* __this, UniTask_1_t462EA7468BEE3A822B4D759A9930C6DF4DED6483 ___0_task1, UniTask_1_t462EA7468BEE3A822B4D759A9930C6DF4DED6483 ___1_task2, UniTask_1_t462EA7468BEE3A822B4D759A9930C6DF4DED6483 ___2_task3, UniTask_1_t462EA7468BEE3A822B4D759A9930C6DF4DED6483 ___3_task4, UniTask_1_t462EA7468BEE3A822B4D759A9930C6DF4DED6483 ___4_task5, UniTask_1_t462EA7468BEE3A822B4D759A9930C6DF4DED6483 ___5_task6, UniTask_1_t462EA7468BEE3A822B4D759A9930C6DF4DED6483 ___6_task7, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	const uint32_t SizeOf_Awaiter_tDBAA5B07F0B862812E44572BF651A8F29F3CE2C3 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 4));
	const uint32_t SizeOf_Awaiter_t843A5D7D728C20D15287743F138A882F846C141C = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 19));
	const uint32_t SizeOf_Awaiter_t349B02E6536E760D503FC1C70C646ED80988F893 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 31));
	const uint32_t SizeOf_Awaiter_t5F3A8B33D927AEB0454E16B05140A8EAE6E1D02D = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 43));
	const uint32_t SizeOf_Awaiter_t1669B7957B5723BB08C7FD87186BDFB644A75A55 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 55));
	const uint32_t SizeOf_Awaiter_tF516DC90789B273E29C24909B6248B35E0C4060F = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 67));
	const uint32_t SizeOf_Awaiter_tCD559881F58A9D240F85415F775B1797BBBCAD81 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 79));
	const Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C L_0 = alloca(SizeOf_Awaiter_tDBAA5B07F0B862812E44572BF651A8F29F3CE2C3);
	const Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C L_8 = L_0;
	const Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C L_10 = alloca(SizeOf_Awaiter_t843A5D7D728C20D15287743F138A882F846C141C);
	const Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C L_18 = L_10;
	const Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C L_20 = alloca(SizeOf_Awaiter_t349B02E6536E760D503FC1C70C646ED80988F893);
	const Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C L_28 = L_20;
	const Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C L_30 = alloca(SizeOf_Awaiter_t5F3A8B33D927AEB0454E16B05140A8EAE6E1D02D);
	const Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C L_38 = L_30;
	const Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C L_40 = alloca(SizeOf_Awaiter_t1669B7957B5723BB08C7FD87186BDFB644A75A55);
	const Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C L_48 = L_40;
	const Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C L_50 = alloca(SizeOf_Awaiter_tF516DC90789B273E29C24909B6248B35E0C4060F);
	const Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C L_58 = L_50;
	const Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C L_60 = alloca(SizeOf_Awaiter_tCD559881F58A9D240F85415F775B1797BBBCAD81);
	const Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C L_68 = L_60;
	Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C V_0 = alloca(SizeOf_Awaiter_tDBAA5B07F0B862812E44572BF651A8F29F3CE2C3);
	memset(V_0, 0, SizeOf_Awaiter_tDBAA5B07F0B862812E44572BF651A8F29F3CE2C3);
	bool V_1 = false;
	Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C V_2 = alloca(SizeOf_Awaiter_t843A5D7D728C20D15287743F138A882F846C141C);
	memset(V_2, 0, SizeOf_Awaiter_t843A5D7D728C20D15287743F138A882F846C141C);
	bool V_3 = false;
	Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C V_4 = alloca(SizeOf_Awaiter_t349B02E6536E760D503FC1C70C646ED80988F893);
	memset(V_4, 0, SizeOf_Awaiter_t349B02E6536E760D503FC1C70C646ED80988F893);
	bool V_5 = false;
	Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C V_6 = alloca(SizeOf_Awaiter_t5F3A8B33D927AEB0454E16B05140A8EAE6E1D02D);
	memset(V_6, 0, SizeOf_Awaiter_t5F3A8B33D927AEB0454E16B05140A8EAE6E1D02D);
	bool V_7 = false;
	Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C V_8 = alloca(SizeOf_Awaiter_t1669B7957B5723BB08C7FD87186BDFB644A75A55);
	memset(V_8, 0, SizeOf_Awaiter_t1669B7957B5723BB08C7FD87186BDFB644A75A55);
	bool V_9 = false;
	Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C V_10 = alloca(SizeOf_Awaiter_tF516DC90789B273E29C24909B6248B35E0C4060F);
	memset(V_10, 0, SizeOf_Awaiter_tF516DC90789B273E29C24909B6248B35E0C4060F);
	bool V_11 = false;
	Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C V_12 = alloca(SizeOf_Awaiter_tCD559881F58A9D240F85415F775B1797BBBCAD81);
	memset(V_12, 0, SizeOf_Awaiter_tCD559881F58A9D240F85415F775B1797BBBCAD81);
	bool V_13 = false;
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* G_B4_0 = NULL;
	Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* G_B4_1 = NULL;
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* G_B3_0 = NULL;
	Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* G_B3_1 = NULL;
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* G_B9_0 = NULL;
	Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* G_B9_1 = NULL;
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* G_B8_0 = NULL;
	Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* G_B8_1 = NULL;
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* G_B14_0 = NULL;
	Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* G_B14_1 = NULL;
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* G_B13_0 = NULL;
	Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* G_B13_1 = NULL;
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* G_B19_0 = NULL;
	Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* G_B19_1 = NULL;
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* G_B18_0 = NULL;
	Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* G_B18_1 = NULL;
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* G_B24_0 = NULL;
	Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* G_B24_1 = NULL;
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* G_B23_0 = NULL;
	Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* G_B23_1 = NULL;
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* G_B29_0 = NULL;
	Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* G_B29_1 = NULL;
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* G_B28_0 = NULL;
	Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* G_B28_1 = NULL;
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* G_B34_0 = NULL;
	Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* G_B34_1 = NULL;
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* G_B33_0 = NULL;
	Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* G_B33_1 = NULL;
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2((RuntimeObject*)__this, NULL);
		il2cpp_codegen_write_instance_field_data<int32_t>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 0),0), 0);
		InvokerActionInvoker1< Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 2)), il2cpp_rgctx_method(method->klass->rgctx_data, 2), (UniTask_1_t462EA7468BEE3A822B4D759A9930C6DF4DED6483*)___0_task1, (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)L_0);
		il2cpp_codegen_memcpy(V_0, L_0, SizeOf_Awaiter_tDBAA5B07F0B862812E44572BF651A8F29F3CE2C3);
		bool L_1;
		L_1 = ((  bool (*) (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 5)))((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_0, il2cpp_rgctx_method(method->klass->rgctx_data, 5));
		V_1 = L_1;
		bool L_2 = V_1;
		if (!L_2)
		{
			goto IL_0030;
		}
	}
	{
		((  void (*) (WhenAnyPromise_7_t354ACE057C836122798B0B89EB0956841B40C24F*, Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 7)))(__this, (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_0, il2cpp_rgctx_method(method->klass->rgctx_data, 7));
		goto IL_0060;
	}

IL_0030:
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->klass->rgctx_data, 11));
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_3 = ((U3CU3Ec_t860FEC480E67A73527482CBB87CEC2DA4082C95B_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9__2_0;
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_4 = L_3;
		if (L_4)
		{
			G_B4_0 = L_4;
			G_B4_1 = ((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)(Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_0);
			goto IL_0052;
		}
		G_B3_0 = L_4;
		G_B3_1 = ((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)(Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_0);
	}
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->klass->rgctx_data, 11));
		U3CU3Ec_t860FEC480E67A73527482CBB87CEC2DA4082C95B* L_5 = ((U3CU3Ec_t860FEC480E67A73527482CBB87CEC2DA4082C95B_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9;
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_6 = (Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87*)il2cpp_codegen_object_new(Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87_il2cpp_TypeInfo_var);
		Action_1__ctor_m2E1DFA67718FC1A0B6E5DFEB78831FFE9C059EB4(L_6, (RuntimeObject*)L_5, (intptr_t)((void*)il2cpp_rgctx_method(method->klass->rgctx_data, 12)), NULL);
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_7 = L_6;
		((U3CU3Ec_t860FEC480E67A73527482CBB87CEC2DA4082C95B_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9__2_0 = L_7;
		Il2CppCodeGenWriteBarrier((void**)(&((U3CU3Ec_t860FEC480E67A73527482CBB87CEC2DA4082C95B_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9__2_0), (void*)L_7);
		G_B4_0 = L_7;
		G_B4_1 = ((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)G_B3_1);
	}

IL_0052:
	{
		il2cpp_codegen_memcpy(L_8, V_0, SizeOf_Awaiter_tDBAA5B07F0B862812E44572BF651A8F29F3CE2C3);
		StateTuple_2_tD239CF0073285A4C6899754787E206EC62F1190E* L_9;
		L_9 = InvokerFuncInvoker2< StateTuple_2_tD239CF0073285A4C6899754787E206EC62F1190E*, WhenAnyPromise_7_t354ACE057C836122798B0B89EB0956841B40C24F*, Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 13)), il2cpp_rgctx_method(method->klass->rgctx_data, 13), NULL, __this, L_8);
		((  void (*) (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*, Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87*, RuntimeObject*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 15)))(G_B4_1, G_B4_0, (RuntimeObject*)L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 15));
	}

IL_0060:
	{
		InvokerActionInvoker1< Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 17)), il2cpp_rgctx_method(method->klass->rgctx_data, 17), (UniTask_1_t462EA7468BEE3A822B4D759A9930C6DF4DED6483*)___1_task2, (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)L_10);
		il2cpp_codegen_memcpy(V_2, L_10, SizeOf_Awaiter_t843A5D7D728C20D15287743F138A882F846C141C);
		bool L_11;
		L_11 = ((  bool (*) (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 20)))((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_2, il2cpp_rgctx_method(method->klass->rgctx_data, 20));
		V_3 = L_11;
		bool L_12 = V_3;
		if (!L_12)
		{
			goto IL_0082;
		}
	}
	{
		((  void (*) (WhenAnyPromise_7_t354ACE057C836122798B0B89EB0956841B40C24F*, Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 22)))(__this, (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_2, il2cpp_rgctx_method(method->klass->rgctx_data, 22));
		goto IL_00b2;
	}

IL_0082:
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->klass->rgctx_data, 11));
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_13 = ((U3CU3Ec_t860FEC480E67A73527482CBB87CEC2DA4082C95B_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9__2_1;
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_14 = L_13;
		if (L_14)
		{
			G_B9_0 = L_14;
			G_B9_1 = ((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)(Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_2);
			goto IL_00a4;
		}
		G_B8_0 = L_14;
		G_B8_1 = ((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)(Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_2);
	}
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->klass->rgctx_data, 11));
		U3CU3Ec_t860FEC480E67A73527482CBB87CEC2DA4082C95B* L_15 = ((U3CU3Ec_t860FEC480E67A73527482CBB87CEC2DA4082C95B_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9;
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_16 = (Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87*)il2cpp_codegen_object_new(Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87_il2cpp_TypeInfo_var);
		Action_1__ctor_m2E1DFA67718FC1A0B6E5DFEB78831FFE9C059EB4(L_16, (RuntimeObject*)L_15, (intptr_t)((void*)il2cpp_rgctx_method(method->klass->rgctx_data, 24)), NULL);
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_17 = L_16;
		((U3CU3Ec_t860FEC480E67A73527482CBB87CEC2DA4082C95B_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9__2_1 = L_17;
		Il2CppCodeGenWriteBarrier((void**)(&((U3CU3Ec_t860FEC480E67A73527482CBB87CEC2DA4082C95B_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9__2_1), (void*)L_17);
		G_B9_0 = L_17;
		G_B9_1 = ((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)G_B8_1);
	}

IL_00a4:
	{
		il2cpp_codegen_memcpy(L_18, V_2, SizeOf_Awaiter_t843A5D7D728C20D15287743F138A882F846C141C);
		StateTuple_2_tD239CF0073285A4C6899754787E206EC62F1190E* L_19;
		L_19 = InvokerFuncInvoker2< StateTuple_2_tD239CF0073285A4C6899754787E206EC62F1190E*, WhenAnyPromise_7_t354ACE057C836122798B0B89EB0956841B40C24F*, Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 25)), il2cpp_rgctx_method(method->klass->rgctx_data, 25), NULL, __this, L_18);
		((  void (*) (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*, Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87*, RuntimeObject*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 27)))(G_B9_1, G_B9_0, (RuntimeObject*)L_19, il2cpp_rgctx_method(method->klass->rgctx_data, 27));
	}

IL_00b2:
	{
		InvokerActionInvoker1< Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 29)), il2cpp_rgctx_method(method->klass->rgctx_data, 29), (UniTask_1_t462EA7468BEE3A822B4D759A9930C6DF4DED6483*)___2_task3, (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)L_20);
		il2cpp_codegen_memcpy(V_4, L_20, SizeOf_Awaiter_t349B02E6536E760D503FC1C70C646ED80988F893);
		bool L_21;
		L_21 = ((  bool (*) (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 32)))((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_4, il2cpp_rgctx_method(method->klass->rgctx_data, 32));
		V_5 = L_21;
		bool L_22 = V_5;
		if (!L_22)
		{
			goto IL_00d7;
		}
	}
	{
		((  void (*) (WhenAnyPromise_7_t354ACE057C836122798B0B89EB0956841B40C24F*, Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 34)))(__this, (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_4, il2cpp_rgctx_method(method->klass->rgctx_data, 34));
		goto IL_0108;
	}

IL_00d7:
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->klass->rgctx_data, 11));
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_23 = ((U3CU3Ec_t860FEC480E67A73527482CBB87CEC2DA4082C95B_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9__2_2;
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_24 = L_23;
		if (L_24)
		{
			G_B14_0 = L_24;
			G_B14_1 = ((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)(Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_4);
			goto IL_00f9;
		}
		G_B13_0 = L_24;
		G_B13_1 = ((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)(Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_4);
	}
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->klass->rgctx_data, 11));
		U3CU3Ec_t860FEC480E67A73527482CBB87CEC2DA4082C95B* L_25 = ((U3CU3Ec_t860FEC480E67A73527482CBB87CEC2DA4082C95B_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9;
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_26 = (Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87*)il2cpp_codegen_object_new(Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87_il2cpp_TypeInfo_var);
		Action_1__ctor_m2E1DFA67718FC1A0B6E5DFEB78831FFE9C059EB4(L_26, (RuntimeObject*)L_25, (intptr_t)((void*)il2cpp_rgctx_method(method->klass->rgctx_data, 36)), NULL);
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_27 = L_26;
		((U3CU3Ec_t860FEC480E67A73527482CBB87CEC2DA4082C95B_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9__2_2 = L_27;
		Il2CppCodeGenWriteBarrier((void**)(&((U3CU3Ec_t860FEC480E67A73527482CBB87CEC2DA4082C95B_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9__2_2), (void*)L_27);
		G_B14_0 = L_27;
		G_B14_1 = ((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)G_B13_1);
	}

IL_00f9:
	{
		il2cpp_codegen_memcpy(L_28, V_4, SizeOf_Awaiter_t349B02E6536E760D503FC1C70C646ED80988F893);
		StateTuple_2_tD239CF0073285A4C6899754787E206EC62F1190E* L_29;
		L_29 = InvokerFuncInvoker2< StateTuple_2_tD239CF0073285A4C6899754787E206EC62F1190E*, WhenAnyPromise_7_t354ACE057C836122798B0B89EB0956841B40C24F*, Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 37)), il2cpp_rgctx_method(method->klass->rgctx_data, 37), NULL, __this, L_28);
		((  void (*) (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*, Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87*, RuntimeObject*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 39)))(G_B14_1, G_B14_0, (RuntimeObject*)L_29, il2cpp_rgctx_method(method->klass->rgctx_data, 39));
	}

IL_0108:
	{
		InvokerActionInvoker1< Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 41)), il2cpp_rgctx_method(method->klass->rgctx_data, 41), (UniTask_1_t462EA7468BEE3A822B4D759A9930C6DF4DED6483*)___3_task4, (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)L_30);
		il2cpp_codegen_memcpy(V_6, L_30, SizeOf_Awaiter_t5F3A8B33D927AEB0454E16B05140A8EAE6E1D02D);
		bool L_31;
		L_31 = ((  bool (*) (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 44)))((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_6, il2cpp_rgctx_method(method->klass->rgctx_data, 44));
		V_7 = L_31;
		bool L_32 = V_7;
		if (!L_32)
		{
			goto IL_012d;
		}
	}
	{
		((  void (*) (WhenAnyPromise_7_t354ACE057C836122798B0B89EB0956841B40C24F*, Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 46)))(__this, (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_6, il2cpp_rgctx_method(method->klass->rgctx_data, 46));
		goto IL_015e;
	}

IL_012d:
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->klass->rgctx_data, 11));
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_33 = ((U3CU3Ec_t860FEC480E67A73527482CBB87CEC2DA4082C95B_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9__2_3;
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_34 = L_33;
		if (L_34)
		{
			G_B19_0 = L_34;
			G_B19_1 = ((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)(Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_6);
			goto IL_014f;
		}
		G_B18_0 = L_34;
		G_B18_1 = ((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)(Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_6);
	}
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->klass->rgctx_data, 11));
		U3CU3Ec_t860FEC480E67A73527482CBB87CEC2DA4082C95B* L_35 = ((U3CU3Ec_t860FEC480E67A73527482CBB87CEC2DA4082C95B_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9;
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_36 = (Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87*)il2cpp_codegen_object_new(Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87_il2cpp_TypeInfo_var);
		Action_1__ctor_m2E1DFA67718FC1A0B6E5DFEB78831FFE9C059EB4(L_36, (RuntimeObject*)L_35, (intptr_t)((void*)il2cpp_rgctx_method(method->klass->rgctx_data, 48)), NULL);
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_37 = L_36;
		((U3CU3Ec_t860FEC480E67A73527482CBB87CEC2DA4082C95B_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9__2_3 = L_37;
		Il2CppCodeGenWriteBarrier((void**)(&((U3CU3Ec_t860FEC480E67A73527482CBB87CEC2DA4082C95B_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9__2_3), (void*)L_37);
		G_B19_0 = L_37;
		G_B19_1 = ((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)G_B18_1);
	}

IL_014f:
	{
		il2cpp_codegen_memcpy(L_38, V_6, SizeOf_Awaiter_t5F3A8B33D927AEB0454E16B05140A8EAE6E1D02D);
		StateTuple_2_tD239CF0073285A4C6899754787E206EC62F1190E* L_39;
		L_39 = InvokerFuncInvoker2< StateTuple_2_tD239CF0073285A4C6899754787E206EC62F1190E*, WhenAnyPromise_7_t354ACE057C836122798B0B89EB0956841B40C24F*, Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 49)), il2cpp_rgctx_method(method->klass->rgctx_data, 49), NULL, __this, L_38);
		((  void (*) (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*, Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87*, RuntimeObject*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 51)))(G_B19_1, G_B19_0, (RuntimeObject*)L_39, il2cpp_rgctx_method(method->klass->rgctx_data, 51));
	}

IL_015e:
	{
		InvokerActionInvoker1< Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 53)), il2cpp_rgctx_method(method->klass->rgctx_data, 53), (UniTask_1_t462EA7468BEE3A822B4D759A9930C6DF4DED6483*)___4_task5, (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)L_40);
		il2cpp_codegen_memcpy(V_8, L_40, SizeOf_Awaiter_t1669B7957B5723BB08C7FD87186BDFB644A75A55);
		bool L_41;
		L_41 = ((  bool (*) (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 56)))((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_8, il2cpp_rgctx_method(method->klass->rgctx_data, 56));
		V_9 = L_41;
		bool L_42 = V_9;
		if (!L_42)
		{
			goto IL_0183;
		}
	}
	{
		((  void (*) (WhenAnyPromise_7_t354ACE057C836122798B0B89EB0956841B40C24F*, Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 58)))(__this, (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_8, il2cpp_rgctx_method(method->klass->rgctx_data, 58));
		goto IL_01b4;
	}

IL_0183:
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->klass->rgctx_data, 11));
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_43 = ((U3CU3Ec_t860FEC480E67A73527482CBB87CEC2DA4082C95B_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9__2_4;
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_44 = L_43;
		if (L_44)
		{
			G_B24_0 = L_44;
			G_B24_1 = ((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)(Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_8);
			goto IL_01a5;
		}
		G_B23_0 = L_44;
		G_B23_1 = ((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)(Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_8);
	}
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->klass->rgctx_data, 11));
		U3CU3Ec_t860FEC480E67A73527482CBB87CEC2DA4082C95B* L_45 = ((U3CU3Ec_t860FEC480E67A73527482CBB87CEC2DA4082C95B_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9;
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_46 = (Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87*)il2cpp_codegen_object_new(Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87_il2cpp_TypeInfo_var);
		Action_1__ctor_m2E1DFA67718FC1A0B6E5DFEB78831FFE9C059EB4(L_46, (RuntimeObject*)L_45, (intptr_t)((void*)il2cpp_rgctx_method(method->klass->rgctx_data, 60)), NULL);
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_47 = L_46;
		((U3CU3Ec_t860FEC480E67A73527482CBB87CEC2DA4082C95B_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9__2_4 = L_47;
		Il2CppCodeGenWriteBarrier((void**)(&((U3CU3Ec_t860FEC480E67A73527482CBB87CEC2DA4082C95B_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9__2_4), (void*)L_47);
		G_B24_0 = L_47;
		G_B24_1 = ((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)G_B23_1);
	}

IL_01a5:
	{
		il2cpp_codegen_memcpy(L_48, V_8, SizeOf_Awaiter_t1669B7957B5723BB08C7FD87186BDFB644A75A55);
		StateTuple_2_tD239CF0073285A4C6899754787E206EC62F1190E* L_49;
		L_49 = InvokerFuncInvoker2< StateTuple_2_tD239CF0073285A4C6899754787E206EC62F1190E*, WhenAnyPromise_7_t354ACE057C836122798B0B89EB0956841B40C24F*, Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 61)), il2cpp_rgctx_method(method->klass->rgctx_data, 61), NULL, __this, L_48);
		((  void (*) (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*, Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87*, RuntimeObject*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 63)))(G_B24_1, G_B24_0, (RuntimeObject*)L_49, il2cpp_rgctx_method(method->klass->rgctx_data, 63));
	}

IL_01b4:
	{
		InvokerActionInvoker1< Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 65)), il2cpp_rgctx_method(method->klass->rgctx_data, 65), (UniTask_1_t462EA7468BEE3A822B4D759A9930C6DF4DED6483*)___5_task6, (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)L_50);
		il2cpp_codegen_memcpy(V_10, L_50, SizeOf_Awaiter_tF516DC90789B273E29C24909B6248B35E0C4060F);
		bool L_51;
		L_51 = ((  bool (*) (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 68)))((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_10, il2cpp_rgctx_method(method->klass->rgctx_data, 68));
		V_11 = L_51;
		bool L_52 = V_11;
		if (!L_52)
		{
			goto IL_01d9;
		}
	}
	{
		((  void (*) (WhenAnyPromise_7_t354ACE057C836122798B0B89EB0956841B40C24F*, Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 70)))(__this, (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_10, il2cpp_rgctx_method(method->klass->rgctx_data, 70));
		goto IL_020a;
	}

IL_01d9:
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->klass->rgctx_data, 11));
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_53 = ((U3CU3Ec_t860FEC480E67A73527482CBB87CEC2DA4082C95B_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9__2_5;
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_54 = L_53;
		if (L_54)
		{
			G_B29_0 = L_54;
			G_B29_1 = ((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)(Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_10);
			goto IL_01fb;
		}
		G_B28_0 = L_54;
		G_B28_1 = ((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)(Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_10);
	}
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->klass->rgctx_data, 11));
		U3CU3Ec_t860FEC480E67A73527482CBB87CEC2DA4082C95B* L_55 = ((U3CU3Ec_t860FEC480E67A73527482CBB87CEC2DA4082C95B_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9;
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_56 = (Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87*)il2cpp_codegen_object_new(Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87_il2cpp_TypeInfo_var);
		Action_1__ctor_m2E1DFA67718FC1A0B6E5DFEB78831FFE9C059EB4(L_56, (RuntimeObject*)L_55, (intptr_t)((void*)il2cpp_rgctx_method(method->klass->rgctx_data, 72)), NULL);
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_57 = L_56;
		((U3CU3Ec_t860FEC480E67A73527482CBB87CEC2DA4082C95B_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9__2_5 = L_57;
		Il2CppCodeGenWriteBarrier((void**)(&((U3CU3Ec_t860FEC480E67A73527482CBB87CEC2DA4082C95B_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9__2_5), (void*)L_57);
		G_B29_0 = L_57;
		G_B29_1 = ((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)G_B28_1);
	}

IL_01fb:
	{
		il2cpp_codegen_memcpy(L_58, V_10, SizeOf_Awaiter_tF516DC90789B273E29C24909B6248B35E0C4060F);
		StateTuple_2_tD239CF0073285A4C6899754787E206EC62F1190E* L_59;
		L_59 = InvokerFuncInvoker2< StateTuple_2_tD239CF0073285A4C6899754787E206EC62F1190E*, WhenAnyPromise_7_t354ACE057C836122798B0B89EB0956841B40C24F*, Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 73)), il2cpp_rgctx_method(method->klass->rgctx_data, 73), NULL, __this, L_58);
		((  void (*) (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*, Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87*, RuntimeObject*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 75)))(G_B29_1, G_B29_0, (RuntimeObject*)L_59, il2cpp_rgctx_method(method->klass->rgctx_data, 75));
	}

IL_020a:
	{
		InvokerActionInvoker1< Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 77)), il2cpp_rgctx_method(method->klass->rgctx_data, 77), (UniTask_1_t462EA7468BEE3A822B4D759A9930C6DF4DED6483*)___6_task7, (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)L_60);
		il2cpp_codegen_memcpy(V_12, L_60, SizeOf_Awaiter_tCD559881F58A9D240F85415F775B1797BBBCAD81);
		bool L_61;
		L_61 = ((  bool (*) (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 80)))((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_12, il2cpp_rgctx_method(method->klass->rgctx_data, 80));
		V_13 = L_61;
		bool L_62 = V_13;
		if (!L_62)
		{
			goto IL_022f;
		}
	}
	{
		((  void (*) (WhenAnyPromise_7_t354ACE057C836122798B0B89EB0956841B40C24F*, Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 82)))(__this, (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_12, il2cpp_rgctx_method(method->klass->rgctx_data, 82));
		goto IL_0260;
	}

IL_022f:
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->klass->rgctx_data, 11));
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_63 = ((U3CU3Ec_t860FEC480E67A73527482CBB87CEC2DA4082C95B_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9__2_6;
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_64 = L_63;
		if (L_64)
		{
			G_B34_0 = L_64;
			G_B34_1 = ((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)(Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_12);
			goto IL_0251;
		}
		G_B33_0 = L_64;
		G_B33_1 = ((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)(Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_12);
	}
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->klass->rgctx_data, 11));
		U3CU3Ec_t860FEC480E67A73527482CBB87CEC2DA4082C95B* L_65 = ((U3CU3Ec_t860FEC480E67A73527482CBB87CEC2DA4082C95B_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9;
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_66 = (Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87*)il2cpp_codegen_object_new(Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87_il2cpp_TypeInfo_var);
		Action_1__ctor_m2E1DFA67718FC1A0B6E5DFEB78831FFE9C059EB4(L_66, (RuntimeObject*)L_65, (intptr_t)((void*)il2cpp_rgctx_method(method->klass->rgctx_data, 84)), NULL);
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_67 = L_66;
		((U3CU3Ec_t860FEC480E67A73527482CBB87CEC2DA4082C95B_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9__2_6 = L_67;
		Il2CppCodeGenWriteBarrier((void**)(&((U3CU3Ec_t860FEC480E67A73527482CBB87CEC2DA4082C95B_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9__2_6), (void*)L_67);
		G_B34_0 = L_67;
		G_B34_1 = ((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)G_B33_1);
	}

IL_0251:
	{
		il2cpp_codegen_memcpy(L_68, V_12, SizeOf_Awaiter_tCD559881F58A9D240F85415F775B1797BBBCAD81);
		StateTuple_2_tD239CF0073285A4C6899754787E206EC62F1190E* L_69;
		L_69 = InvokerFuncInvoker2< StateTuple_2_tD239CF0073285A4C6899754787E206EC62F1190E*, WhenAnyPromise_7_t354ACE057C836122798B0B89EB0956841B40C24F*, Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 85)), il2cpp_rgctx_method(method->klass->rgctx_data, 85), NULL, __this, L_68);
		((  void (*) (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*, Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87*, RuntimeObject*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 87)))(G_B34_1, G_B34_0, (RuntimeObject*)L_69, il2cpp_rgctx_method(method->klass->rgctx_data, 87));
	}

IL_0260:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhenAnyPromise_7_TryInvokeContinuationT1_m3D3D0D1055954373E75F2F0923DA99CE7B91F533_gshared (WhenAnyPromise_7_t354ACE057C836122798B0B89EB0956841B40C24F* ___0_self, Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* ___1_awaiter, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T1_t2C49F537F825A71517E00C8D78B7FF94D50ADB20 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 89));
	const uint32_t SizeOf_T2_t83180294508942547EEF8069848B4DCA60BDBD41 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 93));
	const uint32_t SizeOf_T3_t42F497744C9D56600164CF5D3F6F2E08A972E31F = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 94));
	const uint32_t SizeOf_T4_t5AB0B28249F882088367F1906593511196788455 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 95));
	const uint32_t SizeOf_T5_t837F9104EC47E2AFC243B8366A57E8A5B7A4ABFB = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 96));
	const uint32_t SizeOf_T6_t0F54DDBD033B901D74DDDA28FACD7E9577C68552 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 97));
	const uint32_t SizeOf_T7_t9093750511783139499C77585E45017975B8CABA = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 98));
	const uint32_t SizeOf_ValueTuple_1_tC98081C9F442B604FF32F19F1BDF90B6383D5AD9 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 99));
	const uint32_t SizeOf_ValueTuple_8_t1A5B5ECDA8CA5D6B152EE3CB2EF3B9CEFDA4127E = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 101));
	const Il2CppFullySharedGenericAny L_1 = alloca(SizeOf_T1_t2C49F537F825A71517E00C8D78B7FF94D50ADB20);
	const Il2CppFullySharedGenericAny L_10 = L_1;
	const Il2CppFullySharedGenericAny L_19 = alloca(SizeOf_T1_t2C49F537F825A71517E00C8D78B7FF94D50ADB20);
	const Il2CppFullySharedGenericAny L_11 = alloca(SizeOf_T2_t83180294508942547EEF8069848B4DCA60BDBD41);
	const Il2CppFullySharedGenericAny L_20 = alloca(SizeOf_T2_t83180294508942547EEF8069848B4DCA60BDBD41);
	const Il2CppFullySharedGenericAny L_12 = alloca(SizeOf_T3_t42F497744C9D56600164CF5D3F6F2E08A972E31F);
	const Il2CppFullySharedGenericAny L_21 = alloca(SizeOf_T3_t42F497744C9D56600164CF5D3F6F2E08A972E31F);
	const Il2CppFullySharedGenericAny L_13 = alloca(SizeOf_T4_t5AB0B28249F882088367F1906593511196788455);
	const Il2CppFullySharedGenericAny L_22 = alloca(SizeOf_T4_t5AB0B28249F882088367F1906593511196788455);
	const Il2CppFullySharedGenericAny L_14 = alloca(SizeOf_T5_t837F9104EC47E2AFC243B8366A57E8A5B7A4ABFB);
	const Il2CppFullySharedGenericAny L_23 = alloca(SizeOf_T5_t837F9104EC47E2AFC243B8366A57E8A5B7A4ABFB);
	const Il2CppFullySharedGenericAny L_15 = alloca(SizeOf_T6_t0F54DDBD033B901D74DDDA28FACD7E9577C68552);
	const Il2CppFullySharedGenericAny L_24 = alloca(SizeOf_T6_t0F54DDBD033B901D74DDDA28FACD7E9577C68552);
	const Il2CppFullySharedGenericAny L_16 = alloca(SizeOf_T7_t9093750511783139499C77585E45017975B8CABA);
	const Il2CppFullySharedGenericAny L_17 = alloca(SizeOf_T7_t9093750511783139499C77585E45017975B8CABA);
	const ValueTuple_1_t8587BAAE6DE27A90339279F96A1B89714EE33EAF L_18 = alloca(SizeOf_ValueTuple_1_tC98081C9F442B604FF32F19F1BDF90B6383D5AD9);
	const ValueTuple_1_t8587BAAE6DE27A90339279F96A1B89714EE33EAF L_25 = alloca(SizeOf_ValueTuple_1_tC98081C9F442B604FF32F19F1BDF90B6383D5AD9);
	const ValueTuple_8_t6754BC4E9DF456199B04B3C66F90A9C6F65C460F L_26 = alloca(SizeOf_ValueTuple_8_t1A5B5ECDA8CA5D6B152EE3CB2EF3B9CEFDA4127E);
	Il2CppFullySharedGenericAny V_0 = alloca(SizeOf_T1_t2C49F537F825A71517E00C8D78B7FF94D50ADB20);
	memset(V_0, 0, SizeOf_T1_t2C49F537F825A71517E00C8D78B7FF94D50ADB20);
	Exception_t* V_1 = NULL;
	bool V_2 = false;
	Il2CppFullySharedGenericAny V_3 = alloca(SizeOf_T2_t83180294508942547EEF8069848B4DCA60BDBD41);
	memset(V_3, 0, SizeOf_T2_t83180294508942547EEF8069848B4DCA60BDBD41);
	Il2CppFullySharedGenericAny V_4 = alloca(SizeOf_T3_t42F497744C9D56600164CF5D3F6F2E08A972E31F);
	memset(V_4, 0, SizeOf_T3_t42F497744C9D56600164CF5D3F6F2E08A972E31F);
	Il2CppFullySharedGenericAny V_5 = alloca(SizeOf_T4_t5AB0B28249F882088367F1906593511196788455);
	memset(V_5, 0, SizeOf_T4_t5AB0B28249F882088367F1906593511196788455);
	Il2CppFullySharedGenericAny V_6 = alloca(SizeOf_T5_t837F9104EC47E2AFC243B8366A57E8A5B7A4ABFB);
	memset(V_6, 0, SizeOf_T5_t837F9104EC47E2AFC243B8366A57E8A5B7A4ABFB);
	Il2CppFullySharedGenericAny V_7 = alloca(SizeOf_T6_t0F54DDBD033B901D74DDDA28FACD7E9577C68552);
	memset(V_7, 0, SizeOf_T6_t0F54DDBD033B901D74DDDA28FACD7E9577C68552);
	Il2CppFullySharedGenericAny V_8 = alloca(SizeOf_T7_t9093750511783139499C77585E45017975B8CABA);
	memset(V_8, 0, SizeOf_T7_t9093750511783139499C77585E45017975B8CABA);
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
	}
	try
	{
		Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* L_0 = ___1_awaiter;
		InvokerActionInvoker1< Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 88)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 88), L_0, (Il2CppFullySharedGenericAny*)L_1);
		il2cpp_codegen_memcpy(V_0, L_1, SizeOf_T1_t2C49F537F825A71517E00C8D78B7FF94D50ADB20);
		goto IL_001d;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&Exception_t_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_000c;
		}
		throw e;
	}

CATCH_000c:
	{
		Exception_t* L_2 = ((Exception_t*)IL2CPP_GET_ACTIVE_EXCEPTION(Exception_t*));;
		V_1 = L_2;
		WhenAnyPromise_7_t354ACE057C836122798B0B89EB0956841B40C24F* L_3 = ___0_self;
		Exception_t* L_4 = V_1;
		bool L_5;
		L_5 = ((  bool (*) (UniTaskCompletionSourceCore_1_t22222AD93CF9BE9C7488AF5E792E1474E0C9837D*, Exception_t*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 91)))((((UniTaskCompletionSourceCore_1_t22222AD93CF9BE9C7488AF5E792E1474E0C9837D*)il2cpp_codegen_get_instance_field_data_pointer(L_3, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),1)))), L_4, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 91));
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_0084;
	}

IL_001d:
	{
		WhenAnyPromise_7_t354ACE057C836122798B0B89EB0956841B40C24F* L_6 = ___0_self;
		int32_t L_7;
		L_7 = Interlocked_Increment_m3C240C32E8D9544EC050B74D4F28EEB58F1F9309((((int32_t*)il2cpp_codegen_get_instance_field_data_pointer(L_6, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),0)))), NULL);
		V_2 = (bool)((((int32_t)L_7) == ((int32_t)1))? 1 : 0);
		bool L_8 = V_2;
		if (!L_8)
		{
			goto IL_0084;
		}
	}
	{
		WhenAnyPromise_7_t354ACE057C836122798B0B89EB0956841B40C24F* L_9 = ___0_self;
		il2cpp_codegen_memcpy(L_10, V_0, SizeOf_T1_t2C49F537F825A71517E00C8D78B7FF94D50ADB20);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_3, SizeOf_T2_t83180294508942547EEF8069848B4DCA60BDBD41);
		il2cpp_codegen_memcpy(L_11, V_3, SizeOf_T2_t83180294508942547EEF8069848B4DCA60BDBD41);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_4, SizeOf_T3_t42F497744C9D56600164CF5D3F6F2E08A972E31F);
		il2cpp_codegen_memcpy(L_12, V_4, SizeOf_T3_t42F497744C9D56600164CF5D3F6F2E08A972E31F);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_5, SizeOf_T4_t5AB0B28249F882088367F1906593511196788455);
		il2cpp_codegen_memcpy(L_13, V_5, SizeOf_T4_t5AB0B28249F882088367F1906593511196788455);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_6, SizeOf_T5_t837F9104EC47E2AFC243B8366A57E8A5B7A4ABFB);
		il2cpp_codegen_memcpy(L_14, V_6, SizeOf_T5_t837F9104EC47E2AFC243B8366A57E8A5B7A4ABFB);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_7, SizeOf_T6_t0F54DDBD033B901D74DDDA28FACD7E9577C68552);
		il2cpp_codegen_memcpy(L_15, V_7, SizeOf_T6_t0F54DDBD033B901D74DDDA28FACD7E9577C68552);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_8, SizeOf_T7_t9093750511783139499C77585E45017975B8CABA);
		il2cpp_codegen_memcpy(L_16, V_8, SizeOf_T7_t9093750511783139499C77585E45017975B8CABA);
		memset(L_18, 0, SizeOf_ValueTuple_1_tC98081C9F442B604FF32F19F1BDF90B6383D5AD9);
		ValueTuple_1__ctor_m538A52BFBDA47CC5C05AEE670CAE9D0657D425CB_inline((ValueTuple_1_t8587BAAE6DE27A90339279F96A1B89714EE33EAF*)L_18, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 98)) ? il2cpp_codegen_memcpy(L_17, L_16, SizeOf_T7_t9093750511783139499C77585E45017975B8CABA): *(void**)L_16), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 100));
		memset(L_26, 0, SizeOf_ValueTuple_8_t1A5B5ECDA8CA5D6B152EE3CB2EF3B9CEFDA4127E);
		ValueTuple_8__ctor_m7A1C59EB1AF84EC5855F92B4C73EC9A96D85BA82((ValueTuple_8_t6754BC4E9DF456199B04B3C66F90A9C6F65C460F*)L_26, 0, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 89)) ? il2cpp_codegen_memcpy(L_19, L_10, SizeOf_T1_t2C49F537F825A71517E00C8D78B7FF94D50ADB20): *(void**)L_10), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 93)) ? il2cpp_codegen_memcpy(L_20, L_11, SizeOf_T2_t83180294508942547EEF8069848B4DCA60BDBD41): *(void**)L_11), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 94)) ? il2cpp_codegen_memcpy(L_21, L_12, SizeOf_T3_t42F497744C9D56600164CF5D3F6F2E08A972E31F): *(void**)L_12), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 95)) ? il2cpp_codegen_memcpy(L_22, L_13, SizeOf_T4_t5AB0B28249F882088367F1906593511196788455): *(void**)L_13), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 96)) ? il2cpp_codegen_memcpy(L_23, L_14, SizeOf_T5_t837F9104EC47E2AFC243B8366A57E8A5B7A4ABFB): *(void**)L_14), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 97)) ? il2cpp_codegen_memcpy(L_24, L_15, SizeOf_T6_t0F54DDBD033B901D74DDDA28FACD7E9577C68552): *(void**)L_15), il2cpp_codegen_memcpy(L_25, L_18, SizeOf_ValueTuple_1_tC98081C9F442B604FF32F19F1BDF90B6383D5AD9), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 102));
		bool L_27;
		L_27 = InvokerFuncInvoker1< bool, ValueTuple_8_t6754BC4E9DF456199B04B3C66F90A9C6F65C460F >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 103)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 103), (((UniTaskCompletionSourceCore_1_t22222AD93CF9BE9C7488AF5E792E1474E0C9837D*)il2cpp_codegen_get_instance_field_data_pointer(L_9, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),1)))), L_26);
	}

IL_0084:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhenAnyPromise_7_TryInvokeContinuationT2_mE63B7FB7E3A49428F1EBA3F879A82CD4037BEBCC_gshared (WhenAnyPromise_7_t354ACE057C836122798B0B89EB0956841B40C24F* ___0_self, Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* ___1_awaiter, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T2_t83180294508942547EEF8069848B4DCA60BDBD41 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 93));
	const uint32_t SizeOf_T1_t2C49F537F825A71517E00C8D78B7FF94D50ADB20 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 89));
	const uint32_t SizeOf_T3_t42F497744C9D56600164CF5D3F6F2E08A972E31F = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 94));
	const uint32_t SizeOf_T4_t5AB0B28249F882088367F1906593511196788455 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 95));
	const uint32_t SizeOf_T5_t837F9104EC47E2AFC243B8366A57E8A5B7A4ABFB = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 96));
	const uint32_t SizeOf_T6_t0F54DDBD033B901D74DDDA28FACD7E9577C68552 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 97));
	const uint32_t SizeOf_T7_t9093750511783139499C77585E45017975B8CABA = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 98));
	const uint32_t SizeOf_ValueTuple_1_tC98081C9F442B604FF32F19F1BDF90B6383D5AD9 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 99));
	const uint32_t SizeOf_ValueTuple_8_t1A5B5ECDA8CA5D6B152EE3CB2EF3B9CEFDA4127E = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 101));
	const Il2CppFullySharedGenericAny L_10 = alloca(SizeOf_T1_t2C49F537F825A71517E00C8D78B7FF94D50ADB20);
	const Il2CppFullySharedGenericAny L_19 = alloca(SizeOf_T1_t2C49F537F825A71517E00C8D78B7FF94D50ADB20);
	const Il2CppFullySharedGenericAny L_1 = alloca(SizeOf_T2_t83180294508942547EEF8069848B4DCA60BDBD41);
	const Il2CppFullySharedGenericAny L_11 = L_1;
	const Il2CppFullySharedGenericAny L_20 = alloca(SizeOf_T2_t83180294508942547EEF8069848B4DCA60BDBD41);
	const Il2CppFullySharedGenericAny L_12 = alloca(SizeOf_T3_t42F497744C9D56600164CF5D3F6F2E08A972E31F);
	const Il2CppFullySharedGenericAny L_21 = alloca(SizeOf_T3_t42F497744C9D56600164CF5D3F6F2E08A972E31F);
	const Il2CppFullySharedGenericAny L_13 = alloca(SizeOf_T4_t5AB0B28249F882088367F1906593511196788455);
	const Il2CppFullySharedGenericAny L_22 = alloca(SizeOf_T4_t5AB0B28249F882088367F1906593511196788455);
	const Il2CppFullySharedGenericAny L_14 = alloca(SizeOf_T5_t837F9104EC47E2AFC243B8366A57E8A5B7A4ABFB);
	const Il2CppFullySharedGenericAny L_23 = alloca(SizeOf_T5_t837F9104EC47E2AFC243B8366A57E8A5B7A4ABFB);
	const Il2CppFullySharedGenericAny L_15 = alloca(SizeOf_T6_t0F54DDBD033B901D74DDDA28FACD7E9577C68552);
	const Il2CppFullySharedGenericAny L_24 = alloca(SizeOf_T6_t0F54DDBD033B901D74DDDA28FACD7E9577C68552);
	const Il2CppFullySharedGenericAny L_16 = alloca(SizeOf_T7_t9093750511783139499C77585E45017975B8CABA);
	const Il2CppFullySharedGenericAny L_17 = alloca(SizeOf_T7_t9093750511783139499C77585E45017975B8CABA);
	const ValueTuple_1_t8587BAAE6DE27A90339279F96A1B89714EE33EAF L_18 = alloca(SizeOf_ValueTuple_1_tC98081C9F442B604FF32F19F1BDF90B6383D5AD9);
	const ValueTuple_1_t8587BAAE6DE27A90339279F96A1B89714EE33EAF L_25 = alloca(SizeOf_ValueTuple_1_tC98081C9F442B604FF32F19F1BDF90B6383D5AD9);
	const ValueTuple_8_t6754BC4E9DF456199B04B3C66F90A9C6F65C460F L_26 = alloca(SizeOf_ValueTuple_8_t1A5B5ECDA8CA5D6B152EE3CB2EF3B9CEFDA4127E);
	Il2CppFullySharedGenericAny V_0 = alloca(SizeOf_T2_t83180294508942547EEF8069848B4DCA60BDBD41);
	memset(V_0, 0, SizeOf_T2_t83180294508942547EEF8069848B4DCA60BDBD41);
	Exception_t* V_1 = NULL;
	bool V_2 = false;
	Il2CppFullySharedGenericAny V_3 = alloca(SizeOf_T1_t2C49F537F825A71517E00C8D78B7FF94D50ADB20);
	memset(V_3, 0, SizeOf_T1_t2C49F537F825A71517E00C8D78B7FF94D50ADB20);
	Il2CppFullySharedGenericAny V_4 = alloca(SizeOf_T3_t42F497744C9D56600164CF5D3F6F2E08A972E31F);
	memset(V_4, 0, SizeOf_T3_t42F497744C9D56600164CF5D3F6F2E08A972E31F);
	Il2CppFullySharedGenericAny V_5 = alloca(SizeOf_T4_t5AB0B28249F882088367F1906593511196788455);
	memset(V_5, 0, SizeOf_T4_t5AB0B28249F882088367F1906593511196788455);
	Il2CppFullySharedGenericAny V_6 = alloca(SizeOf_T5_t837F9104EC47E2AFC243B8366A57E8A5B7A4ABFB);
	memset(V_6, 0, SizeOf_T5_t837F9104EC47E2AFC243B8366A57E8A5B7A4ABFB);
	Il2CppFullySharedGenericAny V_7 = alloca(SizeOf_T6_t0F54DDBD033B901D74DDDA28FACD7E9577C68552);
	memset(V_7, 0, SizeOf_T6_t0F54DDBD033B901D74DDDA28FACD7E9577C68552);
	Il2CppFullySharedGenericAny V_8 = alloca(SizeOf_T7_t9093750511783139499C77585E45017975B8CABA);
	memset(V_8, 0, SizeOf_T7_t9093750511783139499C77585E45017975B8CABA);
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
	}
	try
	{
		Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* L_0 = ___1_awaiter;
		InvokerActionInvoker1< Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 104)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 104), L_0, (Il2CppFullySharedGenericAny*)L_1);
		il2cpp_codegen_memcpy(V_0, L_1, SizeOf_T2_t83180294508942547EEF8069848B4DCA60BDBD41);
		goto IL_001d;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&Exception_t_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_000c;
		}
		throw e;
	}

CATCH_000c:
	{
		Exception_t* L_2 = ((Exception_t*)IL2CPP_GET_ACTIVE_EXCEPTION(Exception_t*));;
		V_1 = L_2;
		WhenAnyPromise_7_t354ACE057C836122798B0B89EB0956841B40C24F* L_3 = ___0_self;
		Exception_t* L_4 = V_1;
		bool L_5;
		L_5 = ((  bool (*) (UniTaskCompletionSourceCore_1_t22222AD93CF9BE9C7488AF5E792E1474E0C9837D*, Exception_t*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 91)))((((UniTaskCompletionSourceCore_1_t22222AD93CF9BE9C7488AF5E792E1474E0C9837D*)il2cpp_codegen_get_instance_field_data_pointer(L_3, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),1)))), L_4, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 91));
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_0084;
	}

IL_001d:
	{
		WhenAnyPromise_7_t354ACE057C836122798B0B89EB0956841B40C24F* L_6 = ___0_self;
		int32_t L_7;
		L_7 = Interlocked_Increment_m3C240C32E8D9544EC050B74D4F28EEB58F1F9309((((int32_t*)il2cpp_codegen_get_instance_field_data_pointer(L_6, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),0)))), NULL);
		V_2 = (bool)((((int32_t)L_7) == ((int32_t)1))? 1 : 0);
		bool L_8 = V_2;
		if (!L_8)
		{
			goto IL_0084;
		}
	}
	{
		WhenAnyPromise_7_t354ACE057C836122798B0B89EB0956841B40C24F* L_9 = ___0_self;
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_3, SizeOf_T1_t2C49F537F825A71517E00C8D78B7FF94D50ADB20);
		il2cpp_codegen_memcpy(L_10, V_3, SizeOf_T1_t2C49F537F825A71517E00C8D78B7FF94D50ADB20);
		il2cpp_codegen_memcpy(L_11, V_0, SizeOf_T2_t83180294508942547EEF8069848B4DCA60BDBD41);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_4, SizeOf_T3_t42F497744C9D56600164CF5D3F6F2E08A972E31F);
		il2cpp_codegen_memcpy(L_12, V_4, SizeOf_T3_t42F497744C9D56600164CF5D3F6F2E08A972E31F);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_5, SizeOf_T4_t5AB0B28249F882088367F1906593511196788455);
		il2cpp_codegen_memcpy(L_13, V_5, SizeOf_T4_t5AB0B28249F882088367F1906593511196788455);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_6, SizeOf_T5_t837F9104EC47E2AFC243B8366A57E8A5B7A4ABFB);
		il2cpp_codegen_memcpy(L_14, V_6, SizeOf_T5_t837F9104EC47E2AFC243B8366A57E8A5B7A4ABFB);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_7, SizeOf_T6_t0F54DDBD033B901D74DDDA28FACD7E9577C68552);
		il2cpp_codegen_memcpy(L_15, V_7, SizeOf_T6_t0F54DDBD033B901D74DDDA28FACD7E9577C68552);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_8, SizeOf_T7_t9093750511783139499C77585E45017975B8CABA);
		il2cpp_codegen_memcpy(L_16, V_8, SizeOf_T7_t9093750511783139499C77585E45017975B8CABA);
		memset(L_18, 0, SizeOf_ValueTuple_1_tC98081C9F442B604FF32F19F1BDF90B6383D5AD9);
		ValueTuple_1__ctor_m538A52BFBDA47CC5C05AEE670CAE9D0657D425CB_inline((ValueTuple_1_t8587BAAE6DE27A90339279F96A1B89714EE33EAF*)L_18, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 98)) ? il2cpp_codegen_memcpy(L_17, L_16, SizeOf_T7_t9093750511783139499C77585E45017975B8CABA): *(void**)L_16), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 100));
		memset(L_26, 0, SizeOf_ValueTuple_8_t1A5B5ECDA8CA5D6B152EE3CB2EF3B9CEFDA4127E);
		ValueTuple_8__ctor_m7A1C59EB1AF84EC5855F92B4C73EC9A96D85BA82((ValueTuple_8_t6754BC4E9DF456199B04B3C66F90A9C6F65C460F*)L_26, 1, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 89)) ? il2cpp_codegen_memcpy(L_19, L_10, SizeOf_T1_t2C49F537F825A71517E00C8D78B7FF94D50ADB20): *(void**)L_10), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 93)) ? il2cpp_codegen_memcpy(L_20, L_11, SizeOf_T2_t83180294508942547EEF8069848B4DCA60BDBD41): *(void**)L_11), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 94)) ? il2cpp_codegen_memcpy(L_21, L_12, SizeOf_T3_t42F497744C9D56600164CF5D3F6F2E08A972E31F): *(void**)L_12), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 95)) ? il2cpp_codegen_memcpy(L_22, L_13, SizeOf_T4_t5AB0B28249F882088367F1906593511196788455): *(void**)L_13), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 96)) ? il2cpp_codegen_memcpy(L_23, L_14, SizeOf_T5_t837F9104EC47E2AFC243B8366A57E8A5B7A4ABFB): *(void**)L_14), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 97)) ? il2cpp_codegen_memcpy(L_24, L_15, SizeOf_T6_t0F54DDBD033B901D74DDDA28FACD7E9577C68552): *(void**)L_15), il2cpp_codegen_memcpy(L_25, L_18, SizeOf_ValueTuple_1_tC98081C9F442B604FF32F19F1BDF90B6383D5AD9), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 102));
		bool L_27;
		L_27 = InvokerFuncInvoker1< bool, ValueTuple_8_t6754BC4E9DF456199B04B3C66F90A9C6F65C460F >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 103)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 103), (((UniTaskCompletionSourceCore_1_t22222AD93CF9BE9C7488AF5E792E1474E0C9837D*)il2cpp_codegen_get_instance_field_data_pointer(L_9, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),1)))), L_26);
	}

IL_0084:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhenAnyPromise_7_TryInvokeContinuationT3_mC0029021A8B2734D973BC5238372C3F8187A671D_gshared (WhenAnyPromise_7_t354ACE057C836122798B0B89EB0956841B40C24F* ___0_self, Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* ___1_awaiter, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T3_t42F497744C9D56600164CF5D3F6F2E08A972E31F = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 94));
	const uint32_t SizeOf_T1_t2C49F537F825A71517E00C8D78B7FF94D50ADB20 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 89));
	const uint32_t SizeOf_T2_t83180294508942547EEF8069848B4DCA60BDBD41 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 93));
	const uint32_t SizeOf_T4_t5AB0B28249F882088367F1906593511196788455 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 95));
	const uint32_t SizeOf_T5_t837F9104EC47E2AFC243B8366A57E8A5B7A4ABFB = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 96));
	const uint32_t SizeOf_T6_t0F54DDBD033B901D74DDDA28FACD7E9577C68552 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 97));
	const uint32_t SizeOf_T7_t9093750511783139499C77585E45017975B8CABA = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 98));
	const uint32_t SizeOf_ValueTuple_1_tC98081C9F442B604FF32F19F1BDF90B6383D5AD9 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 99));
	const uint32_t SizeOf_ValueTuple_8_t1A5B5ECDA8CA5D6B152EE3CB2EF3B9CEFDA4127E = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 101));
	const Il2CppFullySharedGenericAny L_10 = alloca(SizeOf_T1_t2C49F537F825A71517E00C8D78B7FF94D50ADB20);
	const Il2CppFullySharedGenericAny L_19 = alloca(SizeOf_T1_t2C49F537F825A71517E00C8D78B7FF94D50ADB20);
	const Il2CppFullySharedGenericAny L_11 = alloca(SizeOf_T2_t83180294508942547EEF8069848B4DCA60BDBD41);
	const Il2CppFullySharedGenericAny L_20 = alloca(SizeOf_T2_t83180294508942547EEF8069848B4DCA60BDBD41);
	const Il2CppFullySharedGenericAny L_1 = alloca(SizeOf_T3_t42F497744C9D56600164CF5D3F6F2E08A972E31F);
	const Il2CppFullySharedGenericAny L_12 = L_1;
	const Il2CppFullySharedGenericAny L_21 = alloca(SizeOf_T3_t42F497744C9D56600164CF5D3F6F2E08A972E31F);
	const Il2CppFullySharedGenericAny L_13 = alloca(SizeOf_T4_t5AB0B28249F882088367F1906593511196788455);
	const Il2CppFullySharedGenericAny L_22 = alloca(SizeOf_T4_t5AB0B28249F882088367F1906593511196788455);
	const Il2CppFullySharedGenericAny L_14 = alloca(SizeOf_T5_t837F9104EC47E2AFC243B8366A57E8A5B7A4ABFB);
	const Il2CppFullySharedGenericAny L_23 = alloca(SizeOf_T5_t837F9104EC47E2AFC243B8366A57E8A5B7A4ABFB);
	const Il2CppFullySharedGenericAny L_15 = alloca(SizeOf_T6_t0F54DDBD033B901D74DDDA28FACD7E9577C68552);
	const Il2CppFullySharedGenericAny L_24 = alloca(SizeOf_T6_t0F54DDBD033B901D74DDDA28FACD7E9577C68552);
	const Il2CppFullySharedGenericAny L_16 = alloca(SizeOf_T7_t9093750511783139499C77585E45017975B8CABA);
	const Il2CppFullySharedGenericAny L_17 = alloca(SizeOf_T7_t9093750511783139499C77585E45017975B8CABA);
	const ValueTuple_1_t8587BAAE6DE27A90339279F96A1B89714EE33EAF L_18 = alloca(SizeOf_ValueTuple_1_tC98081C9F442B604FF32F19F1BDF90B6383D5AD9);
	const ValueTuple_1_t8587BAAE6DE27A90339279F96A1B89714EE33EAF L_25 = alloca(SizeOf_ValueTuple_1_tC98081C9F442B604FF32F19F1BDF90B6383D5AD9);
	const ValueTuple_8_t6754BC4E9DF456199B04B3C66F90A9C6F65C460F L_26 = alloca(SizeOf_ValueTuple_8_t1A5B5ECDA8CA5D6B152EE3CB2EF3B9CEFDA4127E);
	Il2CppFullySharedGenericAny V_0 = alloca(SizeOf_T3_t42F497744C9D56600164CF5D3F6F2E08A972E31F);
	memset(V_0, 0, SizeOf_T3_t42F497744C9D56600164CF5D3F6F2E08A972E31F);
	Exception_t* V_1 = NULL;
	bool V_2 = false;
	Il2CppFullySharedGenericAny V_3 = alloca(SizeOf_T1_t2C49F537F825A71517E00C8D78B7FF94D50ADB20);
	memset(V_3, 0, SizeOf_T1_t2C49F537F825A71517E00C8D78B7FF94D50ADB20);
	Il2CppFullySharedGenericAny V_4 = alloca(SizeOf_T2_t83180294508942547EEF8069848B4DCA60BDBD41);
	memset(V_4, 0, SizeOf_T2_t83180294508942547EEF8069848B4DCA60BDBD41);
	Il2CppFullySharedGenericAny V_5 = alloca(SizeOf_T4_t5AB0B28249F882088367F1906593511196788455);
	memset(V_5, 0, SizeOf_T4_t5AB0B28249F882088367F1906593511196788455);
	Il2CppFullySharedGenericAny V_6 = alloca(SizeOf_T5_t837F9104EC47E2AFC243B8366A57E8A5B7A4ABFB);
	memset(V_6, 0, SizeOf_T5_t837F9104EC47E2AFC243B8366A57E8A5B7A4ABFB);
	Il2CppFullySharedGenericAny V_7 = alloca(SizeOf_T6_t0F54DDBD033B901D74DDDA28FACD7E9577C68552);
	memset(V_7, 0, SizeOf_T6_t0F54DDBD033B901D74DDDA28FACD7E9577C68552);
	Il2CppFullySharedGenericAny V_8 = alloca(SizeOf_T7_t9093750511783139499C77585E45017975B8CABA);
	memset(V_8, 0, SizeOf_T7_t9093750511783139499C77585E45017975B8CABA);
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
	}
	try
	{
		Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* L_0 = ___1_awaiter;
		InvokerActionInvoker1< Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 105)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 105), L_0, (Il2CppFullySharedGenericAny*)L_1);
		il2cpp_codegen_memcpy(V_0, L_1, SizeOf_T3_t42F497744C9D56600164CF5D3F6F2E08A972E31F);
		goto IL_001d;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&Exception_t_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_000c;
		}
		throw e;
	}

CATCH_000c:
	{
		Exception_t* L_2 = ((Exception_t*)IL2CPP_GET_ACTIVE_EXCEPTION(Exception_t*));;
		V_1 = L_2;
		WhenAnyPromise_7_t354ACE057C836122798B0B89EB0956841B40C24F* L_3 = ___0_self;
		Exception_t* L_4 = V_1;
		bool L_5;
		L_5 = ((  bool (*) (UniTaskCompletionSourceCore_1_t22222AD93CF9BE9C7488AF5E792E1474E0C9837D*, Exception_t*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 91)))((((UniTaskCompletionSourceCore_1_t22222AD93CF9BE9C7488AF5E792E1474E0C9837D*)il2cpp_codegen_get_instance_field_data_pointer(L_3, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),1)))), L_4, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 91));
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_0084;
	}

IL_001d:
	{
		WhenAnyPromise_7_t354ACE057C836122798B0B89EB0956841B40C24F* L_6 = ___0_self;
		int32_t L_7;
		L_7 = Interlocked_Increment_m3C240C32E8D9544EC050B74D4F28EEB58F1F9309((((int32_t*)il2cpp_codegen_get_instance_field_data_pointer(L_6, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),0)))), NULL);
		V_2 = (bool)((((int32_t)L_7) == ((int32_t)1))? 1 : 0);
		bool L_8 = V_2;
		if (!L_8)
		{
			goto IL_0084;
		}
	}
	{
		WhenAnyPromise_7_t354ACE057C836122798B0B89EB0956841B40C24F* L_9 = ___0_self;
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_3, SizeOf_T1_t2C49F537F825A71517E00C8D78B7FF94D50ADB20);
		il2cpp_codegen_memcpy(L_10, V_3, SizeOf_T1_t2C49F537F825A71517E00C8D78B7FF94D50ADB20);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_4, SizeOf_T2_t83180294508942547EEF8069848B4DCA60BDBD41);
		il2cpp_codegen_memcpy(L_11, V_4, SizeOf_T2_t83180294508942547EEF8069848B4DCA60BDBD41);
		il2cpp_codegen_memcpy(L_12, V_0, SizeOf_T3_t42F497744C9D56600164CF5D3F6F2E08A972E31F);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_5, SizeOf_T4_t5AB0B28249F882088367F1906593511196788455);
		il2cpp_codegen_memcpy(L_13, V_5, SizeOf_T4_t5AB0B28249F882088367F1906593511196788455);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_6, SizeOf_T5_t837F9104EC47E2AFC243B8366A57E8A5B7A4ABFB);
		il2cpp_codegen_memcpy(L_14, V_6, SizeOf_T5_t837F9104EC47E2AFC243B8366A57E8A5B7A4ABFB);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_7, SizeOf_T6_t0F54DDBD033B901D74DDDA28FACD7E9577C68552);
		il2cpp_codegen_memcpy(L_15, V_7, SizeOf_T6_t0F54DDBD033B901D74DDDA28FACD7E9577C68552);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_8, SizeOf_T7_t9093750511783139499C77585E45017975B8CABA);
		il2cpp_codegen_memcpy(L_16, V_8, SizeOf_T7_t9093750511783139499C77585E45017975B8CABA);
		memset(L_18, 0, SizeOf_ValueTuple_1_tC98081C9F442B604FF32F19F1BDF90B6383D5AD9);
		ValueTuple_1__ctor_m538A52BFBDA47CC5C05AEE670CAE9D0657D425CB_inline((ValueTuple_1_t8587BAAE6DE27A90339279F96A1B89714EE33EAF*)L_18, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 98)) ? il2cpp_codegen_memcpy(L_17, L_16, SizeOf_T7_t9093750511783139499C77585E45017975B8CABA): *(void**)L_16), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 100));
		memset(L_26, 0, SizeOf_ValueTuple_8_t1A5B5ECDA8CA5D6B152EE3CB2EF3B9CEFDA4127E);
		ValueTuple_8__ctor_m7A1C59EB1AF84EC5855F92B4C73EC9A96D85BA82((ValueTuple_8_t6754BC4E9DF456199B04B3C66F90A9C6F65C460F*)L_26, 2, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 89)) ? il2cpp_codegen_memcpy(L_19, L_10, SizeOf_T1_t2C49F537F825A71517E00C8D78B7FF94D50ADB20): *(void**)L_10), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 93)) ? il2cpp_codegen_memcpy(L_20, L_11, SizeOf_T2_t83180294508942547EEF8069848B4DCA60BDBD41): *(void**)L_11), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 94)) ? il2cpp_codegen_memcpy(L_21, L_12, SizeOf_T3_t42F497744C9D56600164CF5D3F6F2E08A972E31F): *(void**)L_12), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 95)) ? il2cpp_codegen_memcpy(L_22, L_13, SizeOf_T4_t5AB0B28249F882088367F1906593511196788455): *(void**)L_13), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 96)) ? il2cpp_codegen_memcpy(L_23, L_14, SizeOf_T5_t837F9104EC47E2AFC243B8366A57E8A5B7A4ABFB): *(void**)L_14), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 97)) ? il2cpp_codegen_memcpy(L_24, L_15, SizeOf_T6_t0F54DDBD033B901D74DDDA28FACD7E9577C68552): *(void**)L_15), il2cpp_codegen_memcpy(L_25, L_18, SizeOf_ValueTuple_1_tC98081C9F442B604FF32F19F1BDF90B6383D5AD9), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 102));
		bool L_27;
		L_27 = InvokerFuncInvoker1< bool, ValueTuple_8_t6754BC4E9DF456199B04B3C66F90A9C6F65C460F >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 103)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 103), (((UniTaskCompletionSourceCore_1_t22222AD93CF9BE9C7488AF5E792E1474E0C9837D*)il2cpp_codegen_get_instance_field_data_pointer(L_9, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),1)))), L_26);
	}

IL_0084:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhenAnyPromise_7_TryInvokeContinuationT4_m85E8044451CAA64CB143D5FED6939C0B0020655D_gshared (WhenAnyPromise_7_t354ACE057C836122798B0B89EB0956841B40C24F* ___0_self, Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* ___1_awaiter, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T4_t5AB0B28249F882088367F1906593511196788455 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 95));
	const uint32_t SizeOf_T1_t2C49F537F825A71517E00C8D78B7FF94D50ADB20 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 89));
	const uint32_t SizeOf_T2_t83180294508942547EEF8069848B4DCA60BDBD41 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 93));
	const uint32_t SizeOf_T3_t42F497744C9D56600164CF5D3F6F2E08A972E31F = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 94));
	const uint32_t SizeOf_T5_t837F9104EC47E2AFC243B8366A57E8A5B7A4ABFB = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 96));
	const uint32_t SizeOf_T6_t0F54DDBD033B901D74DDDA28FACD7E9577C68552 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 97));
	const uint32_t SizeOf_T7_t9093750511783139499C77585E45017975B8CABA = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 98));
	const uint32_t SizeOf_ValueTuple_1_tC98081C9F442B604FF32F19F1BDF90B6383D5AD9 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 99));
	const uint32_t SizeOf_ValueTuple_8_t1A5B5ECDA8CA5D6B152EE3CB2EF3B9CEFDA4127E = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 101));
	const Il2CppFullySharedGenericAny L_10 = alloca(SizeOf_T1_t2C49F537F825A71517E00C8D78B7FF94D50ADB20);
	const Il2CppFullySharedGenericAny L_19 = alloca(SizeOf_T1_t2C49F537F825A71517E00C8D78B7FF94D50ADB20);
	const Il2CppFullySharedGenericAny L_11 = alloca(SizeOf_T2_t83180294508942547EEF8069848B4DCA60BDBD41);
	const Il2CppFullySharedGenericAny L_20 = alloca(SizeOf_T2_t83180294508942547EEF8069848B4DCA60BDBD41);
	const Il2CppFullySharedGenericAny L_12 = alloca(SizeOf_T3_t42F497744C9D56600164CF5D3F6F2E08A972E31F);
	const Il2CppFullySharedGenericAny L_21 = alloca(SizeOf_T3_t42F497744C9D56600164CF5D3F6F2E08A972E31F);
	const Il2CppFullySharedGenericAny L_1 = alloca(SizeOf_T4_t5AB0B28249F882088367F1906593511196788455);
	const Il2CppFullySharedGenericAny L_13 = L_1;
	const Il2CppFullySharedGenericAny L_22 = alloca(SizeOf_T4_t5AB0B28249F882088367F1906593511196788455);
	const Il2CppFullySharedGenericAny L_14 = alloca(SizeOf_T5_t837F9104EC47E2AFC243B8366A57E8A5B7A4ABFB);
	const Il2CppFullySharedGenericAny L_23 = alloca(SizeOf_T5_t837F9104EC47E2AFC243B8366A57E8A5B7A4ABFB);
	const Il2CppFullySharedGenericAny L_15 = alloca(SizeOf_T6_t0F54DDBD033B901D74DDDA28FACD7E9577C68552);
	const Il2CppFullySharedGenericAny L_24 = alloca(SizeOf_T6_t0F54DDBD033B901D74DDDA28FACD7E9577C68552);
	const Il2CppFullySharedGenericAny L_16 = alloca(SizeOf_T7_t9093750511783139499C77585E45017975B8CABA);
	const Il2CppFullySharedGenericAny L_17 = alloca(SizeOf_T7_t9093750511783139499C77585E45017975B8CABA);
	const ValueTuple_1_t8587BAAE6DE27A90339279F96A1B89714EE33EAF L_18 = alloca(SizeOf_ValueTuple_1_tC98081C9F442B604FF32F19F1BDF90B6383D5AD9);
	const ValueTuple_1_t8587BAAE6DE27A90339279F96A1B89714EE33EAF L_25 = alloca(SizeOf_ValueTuple_1_tC98081C9F442B604FF32F19F1BDF90B6383D5AD9);
	const ValueTuple_8_t6754BC4E9DF456199B04B3C66F90A9C6F65C460F L_26 = alloca(SizeOf_ValueTuple_8_t1A5B5ECDA8CA5D6B152EE3CB2EF3B9CEFDA4127E);
	Il2CppFullySharedGenericAny V_0 = alloca(SizeOf_T4_t5AB0B28249F882088367F1906593511196788455);
	memset(V_0, 0, SizeOf_T4_t5AB0B28249F882088367F1906593511196788455);
	Exception_t* V_1 = NULL;
	bool V_2 = false;
	Il2CppFullySharedGenericAny V_3 = alloca(SizeOf_T1_t2C49F537F825A71517E00C8D78B7FF94D50ADB20);
	memset(V_3, 0, SizeOf_T1_t2C49F537F825A71517E00C8D78B7FF94D50ADB20);
	Il2CppFullySharedGenericAny V_4 = alloca(SizeOf_T2_t83180294508942547EEF8069848B4DCA60BDBD41);
	memset(V_4, 0, SizeOf_T2_t83180294508942547EEF8069848B4DCA60BDBD41);
	Il2CppFullySharedGenericAny V_5 = alloca(SizeOf_T3_t42F497744C9D56600164CF5D3F6F2E08A972E31F);
	memset(V_5, 0, SizeOf_T3_t42F497744C9D56600164CF5D3F6F2E08A972E31F);
	Il2CppFullySharedGenericAny V_6 = alloca(SizeOf_T5_t837F9104EC47E2AFC243B8366A57E8A5B7A4ABFB);
	memset(V_6, 0, SizeOf_T5_t837F9104EC47E2AFC243B8366A57E8A5B7A4ABFB);
	Il2CppFullySharedGenericAny V_7 = alloca(SizeOf_T6_t0F54DDBD033B901D74DDDA28FACD7E9577C68552);
	memset(V_7, 0, SizeOf_T6_t0F54DDBD033B901D74DDDA28FACD7E9577C68552);
	Il2CppFullySharedGenericAny V_8 = alloca(SizeOf_T7_t9093750511783139499C77585E45017975B8CABA);
	memset(V_8, 0, SizeOf_T7_t9093750511783139499C77585E45017975B8CABA);
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
	}
	try
	{
		Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* L_0 = ___1_awaiter;
		InvokerActionInvoker1< Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 106)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 106), L_0, (Il2CppFullySharedGenericAny*)L_1);
		il2cpp_codegen_memcpy(V_0, L_1, SizeOf_T4_t5AB0B28249F882088367F1906593511196788455);
		goto IL_001d;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&Exception_t_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_000c;
		}
		throw e;
	}

CATCH_000c:
	{
		Exception_t* L_2 = ((Exception_t*)IL2CPP_GET_ACTIVE_EXCEPTION(Exception_t*));;
		V_1 = L_2;
		WhenAnyPromise_7_t354ACE057C836122798B0B89EB0956841B40C24F* L_3 = ___0_self;
		Exception_t* L_4 = V_1;
		bool L_5;
		L_5 = ((  bool (*) (UniTaskCompletionSourceCore_1_t22222AD93CF9BE9C7488AF5E792E1474E0C9837D*, Exception_t*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 91)))((((UniTaskCompletionSourceCore_1_t22222AD93CF9BE9C7488AF5E792E1474E0C9837D*)il2cpp_codegen_get_instance_field_data_pointer(L_3, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),1)))), L_4, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 91));
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_0084;
	}

IL_001d:
	{
		WhenAnyPromise_7_t354ACE057C836122798B0B89EB0956841B40C24F* L_6 = ___0_self;
		int32_t L_7;
		L_7 = Interlocked_Increment_m3C240C32E8D9544EC050B74D4F28EEB58F1F9309((((int32_t*)il2cpp_codegen_get_instance_field_data_pointer(L_6, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),0)))), NULL);
		V_2 = (bool)((((int32_t)L_7) == ((int32_t)1))? 1 : 0);
		bool L_8 = V_2;
		if (!L_8)
		{
			goto IL_0084;
		}
	}
	{
		WhenAnyPromise_7_t354ACE057C836122798B0B89EB0956841B40C24F* L_9 = ___0_self;
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_3, SizeOf_T1_t2C49F537F825A71517E00C8D78B7FF94D50ADB20);
		il2cpp_codegen_memcpy(L_10, V_3, SizeOf_T1_t2C49F537F825A71517E00C8D78B7FF94D50ADB20);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_4, SizeOf_T2_t83180294508942547EEF8069848B4DCA60BDBD41);
		il2cpp_codegen_memcpy(L_11, V_4, SizeOf_T2_t83180294508942547EEF8069848B4DCA60BDBD41);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_5, SizeOf_T3_t42F497744C9D56600164CF5D3F6F2E08A972E31F);
		il2cpp_codegen_memcpy(L_12, V_5, SizeOf_T3_t42F497744C9D56600164CF5D3F6F2E08A972E31F);
		il2cpp_codegen_memcpy(L_13, V_0, SizeOf_T4_t5AB0B28249F882088367F1906593511196788455);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_6, SizeOf_T5_t837F9104EC47E2AFC243B8366A57E8A5B7A4ABFB);
		il2cpp_codegen_memcpy(L_14, V_6, SizeOf_T5_t837F9104EC47E2AFC243B8366A57E8A5B7A4ABFB);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_7, SizeOf_T6_t0F54DDBD033B901D74DDDA28FACD7E9577C68552);
		il2cpp_codegen_memcpy(L_15, V_7, SizeOf_T6_t0F54DDBD033B901D74DDDA28FACD7E9577C68552);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_8, SizeOf_T7_t9093750511783139499C77585E45017975B8CABA);
		il2cpp_codegen_memcpy(L_16, V_8, SizeOf_T7_t9093750511783139499C77585E45017975B8CABA);
		memset(L_18, 0, SizeOf_ValueTuple_1_tC98081C9F442B604FF32F19F1BDF90B6383D5AD9);
		ValueTuple_1__ctor_m538A52BFBDA47CC5C05AEE670CAE9D0657D425CB_inline((ValueTuple_1_t8587BAAE6DE27A90339279F96A1B89714EE33EAF*)L_18, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 98)) ? il2cpp_codegen_memcpy(L_17, L_16, SizeOf_T7_t9093750511783139499C77585E45017975B8CABA): *(void**)L_16), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 100));
		memset(L_26, 0, SizeOf_ValueTuple_8_t1A5B5ECDA8CA5D6B152EE3CB2EF3B9CEFDA4127E);
		ValueTuple_8__ctor_m7A1C59EB1AF84EC5855F92B4C73EC9A96D85BA82((ValueTuple_8_t6754BC4E9DF456199B04B3C66F90A9C6F65C460F*)L_26, 3, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 89)) ? il2cpp_codegen_memcpy(L_19, L_10, SizeOf_T1_t2C49F537F825A71517E00C8D78B7FF94D50ADB20): *(void**)L_10), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 93)) ? il2cpp_codegen_memcpy(L_20, L_11, SizeOf_T2_t83180294508942547EEF8069848B4DCA60BDBD41): *(void**)L_11), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 94)) ? il2cpp_codegen_memcpy(L_21, L_12, SizeOf_T3_t42F497744C9D56600164CF5D3F6F2E08A972E31F): *(void**)L_12), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 95)) ? il2cpp_codegen_memcpy(L_22, L_13, SizeOf_T4_t5AB0B28249F882088367F1906593511196788455): *(void**)L_13), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 96)) ? il2cpp_codegen_memcpy(L_23, L_14, SizeOf_T5_t837F9104EC47E2AFC243B8366A57E8A5B7A4ABFB): *(void**)L_14), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 97)) ? il2cpp_codegen_memcpy(L_24, L_15, SizeOf_T6_t0F54DDBD033B901D74DDDA28FACD7E9577C68552): *(void**)L_15), il2cpp_codegen_memcpy(L_25, L_18, SizeOf_ValueTuple_1_tC98081C9F442B604FF32F19F1BDF90B6383D5AD9), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 102));
		bool L_27;
		L_27 = InvokerFuncInvoker1< bool, ValueTuple_8_t6754BC4E9DF456199B04B3C66F90A9C6F65C460F >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 103)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 103), (((UniTaskCompletionSourceCore_1_t22222AD93CF9BE9C7488AF5E792E1474E0C9837D*)il2cpp_codegen_get_instance_field_data_pointer(L_9, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),1)))), L_26);
	}

IL_0084:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhenAnyPromise_7_TryInvokeContinuationT5_m29D69529657EBF40FEEFD39FCF7808ED179F68C9_gshared (WhenAnyPromise_7_t354ACE057C836122798B0B89EB0956841B40C24F* ___0_self, Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* ___1_awaiter, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T5_t837F9104EC47E2AFC243B8366A57E8A5B7A4ABFB = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 96));
	const uint32_t SizeOf_T1_t2C49F537F825A71517E00C8D78B7FF94D50ADB20 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 89));
	const uint32_t SizeOf_T2_t83180294508942547EEF8069848B4DCA60BDBD41 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 93));
	const uint32_t SizeOf_T3_t42F497744C9D56600164CF5D3F6F2E08A972E31F = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 94));
	const uint32_t SizeOf_T4_t5AB0B28249F882088367F1906593511196788455 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 95));
	const uint32_t SizeOf_T6_t0F54DDBD033B901D74DDDA28FACD7E9577C68552 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 97));
	const uint32_t SizeOf_T7_t9093750511783139499C77585E45017975B8CABA = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 98));
	const uint32_t SizeOf_ValueTuple_1_tC98081C9F442B604FF32F19F1BDF90B6383D5AD9 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 99));
	const uint32_t SizeOf_ValueTuple_8_t1A5B5ECDA8CA5D6B152EE3CB2EF3B9CEFDA4127E = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 101));
	const Il2CppFullySharedGenericAny L_10 = alloca(SizeOf_T1_t2C49F537F825A71517E00C8D78B7FF94D50ADB20);
	const Il2CppFullySharedGenericAny L_19 = alloca(SizeOf_T1_t2C49F537F825A71517E00C8D78B7FF94D50ADB20);
	const Il2CppFullySharedGenericAny L_11 = alloca(SizeOf_T2_t83180294508942547EEF8069848B4DCA60BDBD41);
	const Il2CppFullySharedGenericAny L_20 = alloca(SizeOf_T2_t83180294508942547EEF8069848B4DCA60BDBD41);
	const Il2CppFullySharedGenericAny L_12 = alloca(SizeOf_T3_t42F497744C9D56600164CF5D3F6F2E08A972E31F);
	const Il2CppFullySharedGenericAny L_21 = alloca(SizeOf_T3_t42F497744C9D56600164CF5D3F6F2E08A972E31F);
	const Il2CppFullySharedGenericAny L_13 = alloca(SizeOf_T4_t5AB0B28249F882088367F1906593511196788455);
	const Il2CppFullySharedGenericAny L_22 = alloca(SizeOf_T4_t5AB0B28249F882088367F1906593511196788455);
	const Il2CppFullySharedGenericAny L_1 = alloca(SizeOf_T5_t837F9104EC47E2AFC243B8366A57E8A5B7A4ABFB);
	const Il2CppFullySharedGenericAny L_14 = L_1;
	const Il2CppFullySharedGenericAny L_23 = alloca(SizeOf_T5_t837F9104EC47E2AFC243B8366A57E8A5B7A4ABFB);
	const Il2CppFullySharedGenericAny L_15 = alloca(SizeOf_T6_t0F54DDBD033B901D74DDDA28FACD7E9577C68552);
	const Il2CppFullySharedGenericAny L_24 = alloca(SizeOf_T6_t0F54DDBD033B901D74DDDA28FACD7E9577C68552);
	const Il2CppFullySharedGenericAny L_16 = alloca(SizeOf_T7_t9093750511783139499C77585E45017975B8CABA);
	const Il2CppFullySharedGenericAny L_17 = alloca(SizeOf_T7_t9093750511783139499C77585E45017975B8CABA);
	const ValueTuple_1_t8587BAAE6DE27A90339279F96A1B89714EE33EAF L_18 = alloca(SizeOf_ValueTuple_1_tC98081C9F442B604FF32F19F1BDF90B6383D5AD9);
	const ValueTuple_1_t8587BAAE6DE27A90339279F96A1B89714EE33EAF L_25 = alloca(SizeOf_ValueTuple_1_tC98081C9F442B604FF32F19F1BDF90B6383D5AD9);
	const ValueTuple_8_t6754BC4E9DF456199B04B3C66F90A9C6F65C460F L_26 = alloca(SizeOf_ValueTuple_8_t1A5B5ECDA8CA5D6B152EE3CB2EF3B9CEFDA4127E);
	Il2CppFullySharedGenericAny V_0 = alloca(SizeOf_T5_t837F9104EC47E2AFC243B8366A57E8A5B7A4ABFB);
	memset(V_0, 0, SizeOf_T5_t837F9104EC47E2AFC243B8366A57E8A5B7A4ABFB);
	Exception_t* V_1 = NULL;
	bool V_2 = false;
	Il2CppFullySharedGenericAny V_3 = alloca(SizeOf_T1_t2C49F537F825A71517E00C8D78B7FF94D50ADB20);
	memset(V_3, 0, SizeOf_T1_t2C49F537F825A71517E00C8D78B7FF94D50ADB20);
	Il2CppFullySharedGenericAny V_4 = alloca(SizeOf_T2_t83180294508942547EEF8069848B4DCA60BDBD41);
	memset(V_4, 0, SizeOf_T2_t83180294508942547EEF8069848B4DCA60BDBD41);
	Il2CppFullySharedGenericAny V_5 = alloca(SizeOf_T3_t42F497744C9D56600164CF5D3F6F2E08A972E31F);
	memset(V_5, 0, SizeOf_T3_t42F497744C9D56600164CF5D3F6F2E08A972E31F);
	Il2CppFullySharedGenericAny V_6 = alloca(SizeOf_T4_t5AB0B28249F882088367F1906593511196788455);
	memset(V_6, 0, SizeOf_T4_t5AB0B28249F882088367F1906593511196788455);
	Il2CppFullySharedGenericAny V_7 = alloca(SizeOf_T6_t0F54DDBD033B901D74DDDA28FACD7E9577C68552);
	memset(V_7, 0, SizeOf_T6_t0F54DDBD033B901D74DDDA28FACD7E9577C68552);
	Il2CppFullySharedGenericAny V_8 = alloca(SizeOf_T7_t9093750511783139499C77585E45017975B8CABA);
	memset(V_8, 0, SizeOf_T7_t9093750511783139499C77585E45017975B8CABA);
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
	}
	try
	{
		Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* L_0 = ___1_awaiter;
		InvokerActionInvoker1< Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 107)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 107), L_0, (Il2CppFullySharedGenericAny*)L_1);
		il2cpp_codegen_memcpy(V_0, L_1, SizeOf_T5_t837F9104EC47E2AFC243B8366A57E8A5B7A4ABFB);
		goto IL_001d;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&Exception_t_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_000c;
		}
		throw e;
	}

CATCH_000c:
	{
		Exception_t* L_2 = ((Exception_t*)IL2CPP_GET_ACTIVE_EXCEPTION(Exception_t*));;
		V_1 = L_2;
		WhenAnyPromise_7_t354ACE057C836122798B0B89EB0956841B40C24F* L_3 = ___0_self;
		Exception_t* L_4 = V_1;
		bool L_5;
		L_5 = ((  bool (*) (UniTaskCompletionSourceCore_1_t22222AD93CF9BE9C7488AF5E792E1474E0C9837D*, Exception_t*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 91)))((((UniTaskCompletionSourceCore_1_t22222AD93CF9BE9C7488AF5E792E1474E0C9837D*)il2cpp_codegen_get_instance_field_data_pointer(L_3, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),1)))), L_4, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 91));
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_0084;
	}

IL_001d:
	{
		WhenAnyPromise_7_t354ACE057C836122798B0B89EB0956841B40C24F* L_6 = ___0_self;
		int32_t L_7;
		L_7 = Interlocked_Increment_m3C240C32E8D9544EC050B74D4F28EEB58F1F9309((((int32_t*)il2cpp_codegen_get_instance_field_data_pointer(L_6, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),0)))), NULL);
		V_2 = (bool)((((int32_t)L_7) == ((int32_t)1))? 1 : 0);
		bool L_8 = V_2;
		if (!L_8)
		{
			goto IL_0084;
		}
	}
	{
		WhenAnyPromise_7_t354ACE057C836122798B0B89EB0956841B40C24F* L_9 = ___0_self;
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_3, SizeOf_T1_t2C49F537F825A71517E00C8D78B7FF94D50ADB20);
		il2cpp_codegen_memcpy(L_10, V_3, SizeOf_T1_t2C49F537F825A71517E00C8D78B7FF94D50ADB20);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_4, SizeOf_T2_t83180294508942547EEF8069848B4DCA60BDBD41);
		il2cpp_codegen_memcpy(L_11, V_4, SizeOf_T2_t83180294508942547EEF8069848B4DCA60BDBD41);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_5, SizeOf_T3_t42F497744C9D56600164CF5D3F6F2E08A972E31F);
		il2cpp_codegen_memcpy(L_12, V_5, SizeOf_T3_t42F497744C9D56600164CF5D3F6F2E08A972E31F);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_6, SizeOf_T4_t5AB0B28249F882088367F1906593511196788455);
		il2cpp_codegen_memcpy(L_13, V_6, SizeOf_T4_t5AB0B28249F882088367F1906593511196788455);
		il2cpp_codegen_memcpy(L_14, V_0, SizeOf_T5_t837F9104EC47E2AFC243B8366A57E8A5B7A4ABFB);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_7, SizeOf_T6_t0F54DDBD033B901D74DDDA28FACD7E9577C68552);
		il2cpp_codegen_memcpy(L_15, V_7, SizeOf_T6_t0F54DDBD033B901D74DDDA28FACD7E9577C68552);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_8, SizeOf_T7_t9093750511783139499C77585E45017975B8CABA);
		il2cpp_codegen_memcpy(L_16, V_8, SizeOf_T7_t9093750511783139499C77585E45017975B8CABA);
		memset(L_18, 0, SizeOf_ValueTuple_1_tC98081C9F442B604FF32F19F1BDF90B6383D5AD9);
		ValueTuple_1__ctor_m538A52BFBDA47CC5C05AEE670CAE9D0657D425CB_inline((ValueTuple_1_t8587BAAE6DE27A90339279F96A1B89714EE33EAF*)L_18, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 98)) ? il2cpp_codegen_memcpy(L_17, L_16, SizeOf_T7_t9093750511783139499C77585E45017975B8CABA): *(void**)L_16), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 100));
		memset(L_26, 0, SizeOf_ValueTuple_8_t1A5B5ECDA8CA5D6B152EE3CB2EF3B9CEFDA4127E);
		ValueTuple_8__ctor_m7A1C59EB1AF84EC5855F92B4C73EC9A96D85BA82((ValueTuple_8_t6754BC4E9DF456199B04B3C66F90A9C6F65C460F*)L_26, 4, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 89)) ? il2cpp_codegen_memcpy(L_19, L_10, SizeOf_T1_t2C49F537F825A71517E00C8D78B7FF94D50ADB20): *(void**)L_10), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 93)) ? il2cpp_codegen_memcpy(L_20, L_11, SizeOf_T2_t83180294508942547EEF8069848B4DCA60BDBD41): *(void**)L_11), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 94)) ? il2cpp_codegen_memcpy(L_21, L_12, SizeOf_T3_t42F497744C9D56600164CF5D3F6F2E08A972E31F): *(void**)L_12), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 95)) ? il2cpp_codegen_memcpy(L_22, L_13, SizeOf_T4_t5AB0B28249F882088367F1906593511196788455): *(void**)L_13), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 96)) ? il2cpp_codegen_memcpy(L_23, L_14, SizeOf_T5_t837F9104EC47E2AFC243B8366A57E8A5B7A4ABFB): *(void**)L_14), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 97)) ? il2cpp_codegen_memcpy(L_24, L_15, SizeOf_T6_t0F54DDBD033B901D74DDDA28FACD7E9577C68552): *(void**)L_15), il2cpp_codegen_memcpy(L_25, L_18, SizeOf_ValueTuple_1_tC98081C9F442B604FF32F19F1BDF90B6383D5AD9), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 102));
		bool L_27;
		L_27 = InvokerFuncInvoker1< bool, ValueTuple_8_t6754BC4E9DF456199B04B3C66F90A9C6F65C460F >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 103)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 103), (((UniTaskCompletionSourceCore_1_t22222AD93CF9BE9C7488AF5E792E1474E0C9837D*)il2cpp_codegen_get_instance_field_data_pointer(L_9, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),1)))), L_26);
	}

IL_0084:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhenAnyPromise_7_TryInvokeContinuationT6_m86512FD9C36896CB02F2C12EADFEB1F4A14FA916_gshared (WhenAnyPromise_7_t354ACE057C836122798B0B89EB0956841B40C24F* ___0_self, Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* ___1_awaiter, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T6_t0F54DDBD033B901D74DDDA28FACD7E9577C68552 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 97));
	const uint32_t SizeOf_T1_t2C49F537F825A71517E00C8D78B7FF94D50ADB20 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 89));
	const uint32_t SizeOf_T2_t83180294508942547EEF8069848B4DCA60BDBD41 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 93));
	const uint32_t SizeOf_T3_t42F497744C9D56600164CF5D3F6F2E08A972E31F = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 94));
	const uint32_t SizeOf_T4_t5AB0B28249F882088367F1906593511196788455 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 95));
	const uint32_t SizeOf_T5_t837F9104EC47E2AFC243B8366A57E8A5B7A4ABFB = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 96));
	const uint32_t SizeOf_T7_t9093750511783139499C77585E45017975B8CABA = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 98));
	const uint32_t SizeOf_ValueTuple_1_tC98081C9F442B604FF32F19F1BDF90B6383D5AD9 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 99));
	const uint32_t SizeOf_ValueTuple_8_t1A5B5ECDA8CA5D6B152EE3CB2EF3B9CEFDA4127E = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 101));
	const Il2CppFullySharedGenericAny L_10 = alloca(SizeOf_T1_t2C49F537F825A71517E00C8D78B7FF94D50ADB20);
	const Il2CppFullySharedGenericAny L_19 = alloca(SizeOf_T1_t2C49F537F825A71517E00C8D78B7FF94D50ADB20);
	const Il2CppFullySharedGenericAny L_11 = alloca(SizeOf_T2_t83180294508942547EEF8069848B4DCA60BDBD41);
	const Il2CppFullySharedGenericAny L_20 = alloca(SizeOf_T2_t83180294508942547EEF8069848B4DCA60BDBD41);
	const Il2CppFullySharedGenericAny L_12 = alloca(SizeOf_T3_t42F497744C9D56600164CF5D3F6F2E08A972E31F);
	const Il2CppFullySharedGenericAny L_21 = alloca(SizeOf_T3_t42F497744C9D56600164CF5D3F6F2E08A972E31F);
	const Il2CppFullySharedGenericAny L_13 = alloca(SizeOf_T4_t5AB0B28249F882088367F1906593511196788455);
	const Il2CppFullySharedGenericAny L_22 = alloca(SizeOf_T4_t5AB0B28249F882088367F1906593511196788455);
	const Il2CppFullySharedGenericAny L_14 = alloca(SizeOf_T5_t837F9104EC47E2AFC243B8366A57E8A5B7A4ABFB);
	const Il2CppFullySharedGenericAny L_23 = alloca(SizeOf_T5_t837F9104EC47E2AFC243B8366A57E8A5B7A4ABFB);
	const Il2CppFullySharedGenericAny L_1 = alloca(SizeOf_T6_t0F54DDBD033B901D74DDDA28FACD7E9577C68552);
	const Il2CppFullySharedGenericAny L_15 = L_1;
	const Il2CppFullySharedGenericAny L_24 = alloca(SizeOf_T6_t0F54DDBD033B901D74DDDA28FACD7E9577C68552);
	const Il2CppFullySharedGenericAny L_16 = alloca(SizeOf_T7_t9093750511783139499C77585E45017975B8CABA);
	const Il2CppFullySharedGenericAny L_17 = alloca(SizeOf_T7_t9093750511783139499C77585E45017975B8CABA);
	const ValueTuple_1_t8587BAAE6DE27A90339279F96A1B89714EE33EAF L_18 = alloca(SizeOf_ValueTuple_1_tC98081C9F442B604FF32F19F1BDF90B6383D5AD9);
	const ValueTuple_1_t8587BAAE6DE27A90339279F96A1B89714EE33EAF L_25 = alloca(SizeOf_ValueTuple_1_tC98081C9F442B604FF32F19F1BDF90B6383D5AD9);
	const ValueTuple_8_t6754BC4E9DF456199B04B3C66F90A9C6F65C460F L_26 = alloca(SizeOf_ValueTuple_8_t1A5B5ECDA8CA5D6B152EE3CB2EF3B9CEFDA4127E);
	Il2CppFullySharedGenericAny V_0 = alloca(SizeOf_T6_t0F54DDBD033B901D74DDDA28FACD7E9577C68552);
	memset(V_0, 0, SizeOf_T6_t0F54DDBD033B901D74DDDA28FACD7E9577C68552);
	Exception_t* V_1 = NULL;
	bool V_2 = false;
	Il2CppFullySharedGenericAny V_3 = alloca(SizeOf_T1_t2C49F537F825A71517E00C8D78B7FF94D50ADB20);
	memset(V_3, 0, SizeOf_T1_t2C49F537F825A71517E00C8D78B7FF94D50ADB20);
	Il2CppFullySharedGenericAny V_4 = alloca(SizeOf_T2_t83180294508942547EEF8069848B4DCA60BDBD41);
	memset(V_4, 0, SizeOf_T2_t83180294508942547EEF8069848B4DCA60BDBD41);
	Il2CppFullySharedGenericAny V_5 = alloca(SizeOf_T3_t42F497744C9D56600164CF5D3F6F2E08A972E31F);
	memset(V_5, 0, SizeOf_T3_t42F497744C9D56600164CF5D3F6F2E08A972E31F);
	Il2CppFullySharedGenericAny V_6 = alloca(SizeOf_T4_t5AB0B28249F882088367F1906593511196788455);
	memset(V_6, 0, SizeOf_T4_t5AB0B28249F882088367F1906593511196788455);
	Il2CppFullySharedGenericAny V_7 = alloca(SizeOf_T5_t837F9104EC47E2AFC243B8366A57E8A5B7A4ABFB);
	memset(V_7, 0, SizeOf_T5_t837F9104EC47E2AFC243B8366A57E8A5B7A4ABFB);
	Il2CppFullySharedGenericAny V_8 = alloca(SizeOf_T7_t9093750511783139499C77585E45017975B8CABA);
	memset(V_8, 0, SizeOf_T7_t9093750511783139499C77585E45017975B8CABA);
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
	}
	try
	{
		Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* L_0 = ___1_awaiter;
		InvokerActionInvoker1< Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 108)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 108), L_0, (Il2CppFullySharedGenericAny*)L_1);
		il2cpp_codegen_memcpy(V_0, L_1, SizeOf_T6_t0F54DDBD033B901D74DDDA28FACD7E9577C68552);
		goto IL_001d;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&Exception_t_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_000c;
		}
		throw e;
	}

CATCH_000c:
	{
		Exception_t* L_2 = ((Exception_t*)IL2CPP_GET_ACTIVE_EXCEPTION(Exception_t*));;
		V_1 = L_2;
		WhenAnyPromise_7_t354ACE057C836122798B0B89EB0956841B40C24F* L_3 = ___0_self;
		Exception_t* L_4 = V_1;
		bool L_5;
		L_5 = ((  bool (*) (UniTaskCompletionSourceCore_1_t22222AD93CF9BE9C7488AF5E792E1474E0C9837D*, Exception_t*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 91)))((((UniTaskCompletionSourceCore_1_t22222AD93CF9BE9C7488AF5E792E1474E0C9837D*)il2cpp_codegen_get_instance_field_data_pointer(L_3, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),1)))), L_4, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 91));
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_0084;
	}

IL_001d:
	{
		WhenAnyPromise_7_t354ACE057C836122798B0B89EB0956841B40C24F* L_6 = ___0_self;
		int32_t L_7;
		L_7 = Interlocked_Increment_m3C240C32E8D9544EC050B74D4F28EEB58F1F9309((((int32_t*)il2cpp_codegen_get_instance_field_data_pointer(L_6, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),0)))), NULL);
		V_2 = (bool)((((int32_t)L_7) == ((int32_t)1))? 1 : 0);
		bool L_8 = V_2;
		if (!L_8)
		{
			goto IL_0084;
		}
	}
	{
		WhenAnyPromise_7_t354ACE057C836122798B0B89EB0956841B40C24F* L_9 = ___0_self;
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_3, SizeOf_T1_t2C49F537F825A71517E00C8D78B7FF94D50ADB20);
		il2cpp_codegen_memcpy(L_10, V_3, SizeOf_T1_t2C49F537F825A71517E00C8D78B7FF94D50ADB20);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_4, SizeOf_T2_t83180294508942547EEF8069848B4DCA60BDBD41);
		il2cpp_codegen_memcpy(L_11, V_4, SizeOf_T2_t83180294508942547EEF8069848B4DCA60BDBD41);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_5, SizeOf_T3_t42F497744C9D56600164CF5D3F6F2E08A972E31F);
		il2cpp_codegen_memcpy(L_12, V_5, SizeOf_T3_t42F497744C9D56600164CF5D3F6F2E08A972E31F);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_6, SizeOf_T4_t5AB0B28249F882088367F1906593511196788455);
		il2cpp_codegen_memcpy(L_13, V_6, SizeOf_T4_t5AB0B28249F882088367F1906593511196788455);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_7, SizeOf_T5_t837F9104EC47E2AFC243B8366A57E8A5B7A4ABFB);
		il2cpp_codegen_memcpy(L_14, V_7, SizeOf_T5_t837F9104EC47E2AFC243B8366A57E8A5B7A4ABFB);
		il2cpp_codegen_memcpy(L_15, V_0, SizeOf_T6_t0F54DDBD033B901D74DDDA28FACD7E9577C68552);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_8, SizeOf_T7_t9093750511783139499C77585E45017975B8CABA);
		il2cpp_codegen_memcpy(L_16, V_8, SizeOf_T7_t9093750511783139499C77585E45017975B8CABA);
		memset(L_18, 0, SizeOf_ValueTuple_1_tC98081C9F442B604FF32F19F1BDF90B6383D5AD9);
		ValueTuple_1__ctor_m538A52BFBDA47CC5C05AEE670CAE9D0657D425CB_inline((ValueTuple_1_t8587BAAE6DE27A90339279F96A1B89714EE33EAF*)L_18, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 98)) ? il2cpp_codegen_memcpy(L_17, L_16, SizeOf_T7_t9093750511783139499C77585E45017975B8CABA): *(void**)L_16), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 100));
		memset(L_26, 0, SizeOf_ValueTuple_8_t1A5B5ECDA8CA5D6B152EE3CB2EF3B9CEFDA4127E);
		ValueTuple_8__ctor_m7A1C59EB1AF84EC5855F92B4C73EC9A96D85BA82((ValueTuple_8_t6754BC4E9DF456199B04B3C66F90A9C6F65C460F*)L_26, 5, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 89)) ? il2cpp_codegen_memcpy(L_19, L_10, SizeOf_T1_t2C49F537F825A71517E00C8D78B7FF94D50ADB20): *(void**)L_10), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 93)) ? il2cpp_codegen_memcpy(L_20, L_11, SizeOf_T2_t83180294508942547EEF8069848B4DCA60BDBD41): *(void**)L_11), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 94)) ? il2cpp_codegen_memcpy(L_21, L_12, SizeOf_T3_t42F497744C9D56600164CF5D3F6F2E08A972E31F): *(void**)L_12), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 95)) ? il2cpp_codegen_memcpy(L_22, L_13, SizeOf_T4_t5AB0B28249F882088367F1906593511196788455): *(void**)L_13), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 96)) ? il2cpp_codegen_memcpy(L_23, L_14, SizeOf_T5_t837F9104EC47E2AFC243B8366A57E8A5B7A4ABFB): *(void**)L_14), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 97)) ? il2cpp_codegen_memcpy(L_24, L_15, SizeOf_T6_t0F54DDBD033B901D74DDDA28FACD7E9577C68552): *(void**)L_15), il2cpp_codegen_memcpy(L_25, L_18, SizeOf_ValueTuple_1_tC98081C9F442B604FF32F19F1BDF90B6383D5AD9), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 102));
		bool L_27;
		L_27 = InvokerFuncInvoker1< bool, ValueTuple_8_t6754BC4E9DF456199B04B3C66F90A9C6F65C460F >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 103)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 103), (((UniTaskCompletionSourceCore_1_t22222AD93CF9BE9C7488AF5E792E1474E0C9837D*)il2cpp_codegen_get_instance_field_data_pointer(L_9, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),1)))), L_26);
	}

IL_0084:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhenAnyPromise_7_TryInvokeContinuationT7_mC352B55AD33E9598679F25DE08A1A63883E91D68_gshared (WhenAnyPromise_7_t354ACE057C836122798B0B89EB0956841B40C24F* ___0_self, Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* ___1_awaiter, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T7_t9093750511783139499C77585E45017975B8CABA = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 98));
	const uint32_t SizeOf_T1_t2C49F537F825A71517E00C8D78B7FF94D50ADB20 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 89));
	const uint32_t SizeOf_T2_t83180294508942547EEF8069848B4DCA60BDBD41 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 93));
	const uint32_t SizeOf_T3_t42F497744C9D56600164CF5D3F6F2E08A972E31F = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 94));
	const uint32_t SizeOf_T4_t5AB0B28249F882088367F1906593511196788455 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 95));
	const uint32_t SizeOf_T5_t837F9104EC47E2AFC243B8366A57E8A5B7A4ABFB = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 96));
	const uint32_t SizeOf_T6_t0F54DDBD033B901D74DDDA28FACD7E9577C68552 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 97));
	const uint32_t SizeOf_ValueTuple_1_tC98081C9F442B604FF32F19F1BDF90B6383D5AD9 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 99));
	const uint32_t SizeOf_ValueTuple_8_t1A5B5ECDA8CA5D6B152EE3CB2EF3B9CEFDA4127E = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 101));
	const Il2CppFullySharedGenericAny L_10 = alloca(SizeOf_T1_t2C49F537F825A71517E00C8D78B7FF94D50ADB20);
	const Il2CppFullySharedGenericAny L_19 = alloca(SizeOf_T1_t2C49F537F825A71517E00C8D78B7FF94D50ADB20);
	const Il2CppFullySharedGenericAny L_11 = alloca(SizeOf_T2_t83180294508942547EEF8069848B4DCA60BDBD41);
	const Il2CppFullySharedGenericAny L_20 = alloca(SizeOf_T2_t83180294508942547EEF8069848B4DCA60BDBD41);
	const Il2CppFullySharedGenericAny L_12 = alloca(SizeOf_T3_t42F497744C9D56600164CF5D3F6F2E08A972E31F);
	const Il2CppFullySharedGenericAny L_21 = alloca(SizeOf_T3_t42F497744C9D56600164CF5D3F6F2E08A972E31F);
	const Il2CppFullySharedGenericAny L_13 = alloca(SizeOf_T4_t5AB0B28249F882088367F1906593511196788455);
	const Il2CppFullySharedGenericAny L_22 = alloca(SizeOf_T4_t5AB0B28249F882088367F1906593511196788455);
	const Il2CppFullySharedGenericAny L_14 = alloca(SizeOf_T5_t837F9104EC47E2AFC243B8366A57E8A5B7A4ABFB);
	const Il2CppFullySharedGenericAny L_23 = alloca(SizeOf_T5_t837F9104EC47E2AFC243B8366A57E8A5B7A4ABFB);
	const Il2CppFullySharedGenericAny L_15 = alloca(SizeOf_T6_t0F54DDBD033B901D74DDDA28FACD7E9577C68552);
	const Il2CppFullySharedGenericAny L_24 = alloca(SizeOf_T6_t0F54DDBD033B901D74DDDA28FACD7E9577C68552);
	const Il2CppFullySharedGenericAny L_1 = alloca(SizeOf_T7_t9093750511783139499C77585E45017975B8CABA);
	const Il2CppFullySharedGenericAny L_16 = L_1;
	const Il2CppFullySharedGenericAny L_17 = alloca(SizeOf_T7_t9093750511783139499C77585E45017975B8CABA);
	const ValueTuple_1_t8587BAAE6DE27A90339279F96A1B89714EE33EAF L_18 = alloca(SizeOf_ValueTuple_1_tC98081C9F442B604FF32F19F1BDF90B6383D5AD9);
	const ValueTuple_1_t8587BAAE6DE27A90339279F96A1B89714EE33EAF L_25 = alloca(SizeOf_ValueTuple_1_tC98081C9F442B604FF32F19F1BDF90B6383D5AD9);
	const ValueTuple_8_t6754BC4E9DF456199B04B3C66F90A9C6F65C460F L_26 = alloca(SizeOf_ValueTuple_8_t1A5B5ECDA8CA5D6B152EE3CB2EF3B9CEFDA4127E);
	Il2CppFullySharedGenericAny V_0 = alloca(SizeOf_T7_t9093750511783139499C77585E45017975B8CABA);
	memset(V_0, 0, SizeOf_T7_t9093750511783139499C77585E45017975B8CABA);
	Exception_t* V_1 = NULL;
	bool V_2 = false;
	Il2CppFullySharedGenericAny V_3 = alloca(SizeOf_T1_t2C49F537F825A71517E00C8D78B7FF94D50ADB20);
	memset(V_3, 0, SizeOf_T1_t2C49F537F825A71517E00C8D78B7FF94D50ADB20);
	Il2CppFullySharedGenericAny V_4 = alloca(SizeOf_T2_t83180294508942547EEF8069848B4DCA60BDBD41);
	memset(V_4, 0, SizeOf_T2_t83180294508942547EEF8069848B4DCA60BDBD41);
	Il2CppFullySharedGenericAny V_5 = alloca(SizeOf_T3_t42F497744C9D56600164CF5D3F6F2E08A972E31F);
	memset(V_5, 0, SizeOf_T3_t42F497744C9D56600164CF5D3F6F2E08A972E31F);
	Il2CppFullySharedGenericAny V_6 = alloca(SizeOf_T4_t5AB0B28249F882088367F1906593511196788455);
	memset(V_6, 0, SizeOf_T4_t5AB0B28249F882088367F1906593511196788455);
	Il2CppFullySharedGenericAny V_7 = alloca(SizeOf_T5_t837F9104EC47E2AFC243B8366A57E8A5B7A4ABFB);
	memset(V_7, 0, SizeOf_T5_t837F9104EC47E2AFC243B8366A57E8A5B7A4ABFB);
	Il2CppFullySharedGenericAny V_8 = alloca(SizeOf_T6_t0F54DDBD033B901D74DDDA28FACD7E9577C68552);
	memset(V_8, 0, SizeOf_T6_t0F54DDBD033B901D74DDDA28FACD7E9577C68552);
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
	}
	try
	{
		Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* L_0 = ___1_awaiter;
		InvokerActionInvoker1< Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 109)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 109), L_0, (Il2CppFullySharedGenericAny*)L_1);
		il2cpp_codegen_memcpy(V_0, L_1, SizeOf_T7_t9093750511783139499C77585E45017975B8CABA);
		goto IL_001d;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&Exception_t_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_000c;
		}
		throw e;
	}

CATCH_000c:
	{
		Exception_t* L_2 = ((Exception_t*)IL2CPP_GET_ACTIVE_EXCEPTION(Exception_t*));;
		V_1 = L_2;
		WhenAnyPromise_7_t354ACE057C836122798B0B89EB0956841B40C24F* L_3 = ___0_self;
		Exception_t* L_4 = V_1;
		bool L_5;
		L_5 = ((  bool (*) (UniTaskCompletionSourceCore_1_t22222AD93CF9BE9C7488AF5E792E1474E0C9837D*, Exception_t*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 91)))((((UniTaskCompletionSourceCore_1_t22222AD93CF9BE9C7488AF5E792E1474E0C9837D*)il2cpp_codegen_get_instance_field_data_pointer(L_3, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),1)))), L_4, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 91));
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_0084;
	}

IL_001d:
	{
		WhenAnyPromise_7_t354ACE057C836122798B0B89EB0956841B40C24F* L_6 = ___0_self;
		int32_t L_7;
		L_7 = Interlocked_Increment_m3C240C32E8D9544EC050B74D4F28EEB58F1F9309((((int32_t*)il2cpp_codegen_get_instance_field_data_pointer(L_6, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),0)))), NULL);
		V_2 = (bool)((((int32_t)L_7) == ((int32_t)1))? 1 : 0);
		bool L_8 = V_2;
		if (!L_8)
		{
			goto IL_0084;
		}
	}
	{
		WhenAnyPromise_7_t354ACE057C836122798B0B89EB0956841B40C24F* L_9 = ___0_self;
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_3, SizeOf_T1_t2C49F537F825A71517E00C8D78B7FF94D50ADB20);
		il2cpp_codegen_memcpy(L_10, V_3, SizeOf_T1_t2C49F537F825A71517E00C8D78B7FF94D50ADB20);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_4, SizeOf_T2_t83180294508942547EEF8069848B4DCA60BDBD41);
		il2cpp_codegen_memcpy(L_11, V_4, SizeOf_T2_t83180294508942547EEF8069848B4DCA60BDBD41);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_5, SizeOf_T3_t42F497744C9D56600164CF5D3F6F2E08A972E31F);
		il2cpp_codegen_memcpy(L_12, V_5, SizeOf_T3_t42F497744C9D56600164CF5D3F6F2E08A972E31F);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_6, SizeOf_T4_t5AB0B28249F882088367F1906593511196788455);
		il2cpp_codegen_memcpy(L_13, V_6, SizeOf_T4_t5AB0B28249F882088367F1906593511196788455);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_7, SizeOf_T5_t837F9104EC47E2AFC243B8366A57E8A5B7A4ABFB);
		il2cpp_codegen_memcpy(L_14, V_7, SizeOf_T5_t837F9104EC47E2AFC243B8366A57E8A5B7A4ABFB);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_8, SizeOf_T6_t0F54DDBD033B901D74DDDA28FACD7E9577C68552);
		il2cpp_codegen_memcpy(L_15, V_8, SizeOf_T6_t0F54DDBD033B901D74DDDA28FACD7E9577C68552);
		il2cpp_codegen_memcpy(L_16, V_0, SizeOf_T7_t9093750511783139499C77585E45017975B8CABA);
		memset(L_18, 0, SizeOf_ValueTuple_1_tC98081C9F442B604FF32F19F1BDF90B6383D5AD9);
		ValueTuple_1__ctor_m538A52BFBDA47CC5C05AEE670CAE9D0657D425CB_inline((ValueTuple_1_t8587BAAE6DE27A90339279F96A1B89714EE33EAF*)L_18, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 98)) ? il2cpp_codegen_memcpy(L_17, L_16, SizeOf_T7_t9093750511783139499C77585E45017975B8CABA): *(void**)L_16), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 100));
		memset(L_26, 0, SizeOf_ValueTuple_8_t1A5B5ECDA8CA5D6B152EE3CB2EF3B9CEFDA4127E);
		ValueTuple_8__ctor_m7A1C59EB1AF84EC5855F92B4C73EC9A96D85BA82((ValueTuple_8_t6754BC4E9DF456199B04B3C66F90A9C6F65C460F*)L_26, 6, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 89)) ? il2cpp_codegen_memcpy(L_19, L_10, SizeOf_T1_t2C49F537F825A71517E00C8D78B7FF94D50ADB20): *(void**)L_10), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 93)) ? il2cpp_codegen_memcpy(L_20, L_11, SizeOf_T2_t83180294508942547EEF8069848B4DCA60BDBD41): *(void**)L_11), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 94)) ? il2cpp_codegen_memcpy(L_21, L_12, SizeOf_T3_t42F497744C9D56600164CF5D3F6F2E08A972E31F): *(void**)L_12), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 95)) ? il2cpp_codegen_memcpy(L_22, L_13, SizeOf_T4_t5AB0B28249F882088367F1906593511196788455): *(void**)L_13), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 96)) ? il2cpp_codegen_memcpy(L_23, L_14, SizeOf_T5_t837F9104EC47E2AFC243B8366A57E8A5B7A4ABFB): *(void**)L_14), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 97)) ? il2cpp_codegen_memcpy(L_24, L_15, SizeOf_T6_t0F54DDBD033B901D74DDDA28FACD7E9577C68552): *(void**)L_15), il2cpp_codegen_memcpy(L_25, L_18, SizeOf_ValueTuple_1_tC98081C9F442B604FF32F19F1BDF90B6383D5AD9), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 102));
		bool L_27;
		L_27 = InvokerFuncInvoker1< bool, ValueTuple_8_t6754BC4E9DF456199B04B3C66F90A9C6F65C460F >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 103)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 103), (((UniTaskCompletionSourceCore_1_t22222AD93CF9BE9C7488AF5E792E1474E0C9837D*)il2cpp_codegen_get_instance_field_data_pointer(L_9, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),1)))), L_26);
	}

IL_0084:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhenAnyPromise_7_GetResult_mC1652044AF9DCB05AADEF06E8E8A1886D17D53F8_gshared (WhenAnyPromise_7_t354ACE057C836122798B0B89EB0956841B40C24F* __this, int16_t ___0_token, ValueTuple_8_t6754BC4E9DF456199B04B3C66F90A9C6F65C460F* il2cppRetVal, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GC_t920F9CF6EBB7C787E5010A4352E1B587F356DC58_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	const uint32_t SizeOf_ValueTuple_8_t1A5B5ECDA8CA5D6B152EE3CB2EF3B9CEFDA4127E = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 101));
	const ValueTuple_8_t6754BC4E9DF456199B04B3C66F90A9C6F65C460F L_1 = alloca(SizeOf_ValueTuple_8_t1A5B5ECDA8CA5D6B152EE3CB2EF3B9CEFDA4127E);
	const ValueTuple_8_t6754BC4E9DF456199B04B3C66F90A9C6F65C460F L_2 = L_1;
	ValueTuple_8_t6754BC4E9DF456199B04B3C66F90A9C6F65C460F V_0 = alloca(SizeOf_ValueTuple_8_t1A5B5ECDA8CA5D6B152EE3CB2EF3B9CEFDA4127E);
	memset(V_0, 0, SizeOf_ValueTuple_8_t1A5B5ECDA8CA5D6B152EE3CB2EF3B9CEFDA4127E);
	{
		il2cpp_codegen_runtime_class_init_inline(GC_t920F9CF6EBB7C787E5010A4352E1B587F356DC58_il2cpp_TypeInfo_var);
		GC_SuppressFinalize_m71815DBD5A0CD2EA1BE43317B08B7A14949EDC65((RuntimeObject*)__this, NULL);
		int16_t L_0 = ___0_token;
		InvokerActionInvoker2< int16_t, ValueTuple_8_t6754BC4E9DF456199B04B3C66F90A9C6F65C460F* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 110)), il2cpp_rgctx_method(method->klass->rgctx_data, 110), (((UniTaskCompletionSourceCore_1_t22222AD93CF9BE9C7488AF5E792E1474E0C9837D*)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 0),1)))), L_0, (ValueTuple_8_t6754BC4E9DF456199B04B3C66F90A9C6F65C460F*)L_1);
		il2cpp_codegen_memcpy(V_0, L_1, SizeOf_ValueTuple_8_t1A5B5ECDA8CA5D6B152EE3CB2EF3B9CEFDA4127E);
		goto IL_0017;
	}

IL_0017:
	{
		il2cpp_codegen_memcpy(L_2, V_0, SizeOf_ValueTuple_8_t1A5B5ECDA8CA5D6B152EE3CB2EF3B9CEFDA4127E);
		il2cpp_codegen_memcpy(il2cppRetVal, L_2, SizeOf_ValueTuple_8_t1A5B5ECDA8CA5D6B152EE3CB2EF3B9CEFDA4127E);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t WhenAnyPromise_7_GetStatus_m17530EA20A22A4E366B94ECCC7CE6DA52DABEEF1_gshared (WhenAnyPromise_7_t354ACE057C836122798B0B89EB0956841B40C24F* __this, int16_t ___0_token, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		int16_t L_0 = ___0_token;
		int32_t L_1;
		L_1 = ((  int32_t (*) (UniTaskCompletionSourceCore_1_t22222AD93CF9BE9C7488AF5E792E1474E0C9837D*, int16_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 111)))((((UniTaskCompletionSourceCore_1_t22222AD93CF9BE9C7488AF5E792E1474E0C9837D*)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 0),1)))), L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 111));
		V_0 = L_1;
		goto IL_0010;
	}

IL_0010:
	{
		int32_t L_2 = V_0;
		return L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhenAnyPromise_7_OnCompleted_mBB4D6472B573C1AEC89CA8676B43A846B45A392C_gshared (WhenAnyPromise_7_t354ACE057C836122798B0B89EB0956841B40C24F* __this, Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* ___0_continuation, RuntimeObject* ___1_state, int16_t ___2_token, const RuntimeMethod* method) 
{
	{
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_0 = ___0_continuation;
		RuntimeObject* L_1 = ___1_state;
		int16_t L_2 = ___2_token;
		((  void (*) (UniTaskCompletionSourceCore_1_t22222AD93CF9BE9C7488AF5E792E1474E0C9837D*, Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87*, RuntimeObject*, int16_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 112)))((((UniTaskCompletionSourceCore_1_t22222AD93CF9BE9C7488AF5E792E1474E0C9837D*)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 0),1)))), L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 112));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t WhenAnyPromise_7_UnsafeGetStatus_m8F625CC004BDD29F351190C76429EFBB0172EB2F_gshared (WhenAnyPromise_7_t354ACE057C836122798B0B89EB0956841B40C24F* __this, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		int32_t L_0;
		L_0 = ((  int32_t (*) (UniTaskCompletionSourceCore_1_t22222AD93CF9BE9C7488AF5E792E1474E0C9837D*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 113)))((((UniTaskCompletionSourceCore_1_t22222AD93CF9BE9C7488AF5E792E1474E0C9837D*)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 0),1)))), il2cpp_rgctx_method(method->klass->rgctx_data, 113));
		V_0 = L_0;
		goto IL_000f;
	}

IL_000f:
	{
		int32_t L_1 = V_0;
		return L_1;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhenAnyPromise_7_Cysharp_Threading_Tasks_IUniTaskSource_GetResult_m5093C2E24C2E3A0806A2FDADB6F6D1EA9AE6B282_gshared (WhenAnyPromise_7_t354ACE057C836122798B0B89EB0956841B40C24F* __this, int16_t ___0_token, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_ValueTuple_8_t1A5B5ECDA8CA5D6B152EE3CB2EF3B9CEFDA4127E = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 101));
	const ValueTuple_8_t6754BC4E9DF456199B04B3C66F90A9C6F65C460F L_1 = alloca(SizeOf_ValueTuple_8_t1A5B5ECDA8CA5D6B152EE3CB2EF3B9CEFDA4127E);
	{
		int16_t L_0 = ___0_token;
		InvokerActionInvoker2< int16_t, ValueTuple_8_t6754BC4E9DF456199B04B3C66F90A9C6F65C460F* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 114)), il2cpp_rgctx_method(method->klass->rgctx_data, 114), __this, L_0, (ValueTuple_8_t6754BC4E9DF456199B04B3C66F90A9C6F65C460F*)L_1);
		return;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhenAnyPromise_8__ctor_m18F44290BFEE1A49901914016EF42864F572D2C9_gshared (WhenAnyPromise_8_tB1A18813B231826F7BEE92541715D6266929F072* __this, UniTask_1_t462EA7468BEE3A822B4D759A9930C6DF4DED6483 ___0_task1, UniTask_1_t462EA7468BEE3A822B4D759A9930C6DF4DED6483 ___1_task2, UniTask_1_t462EA7468BEE3A822B4D759A9930C6DF4DED6483 ___2_task3, UniTask_1_t462EA7468BEE3A822B4D759A9930C6DF4DED6483 ___3_task4, UniTask_1_t462EA7468BEE3A822B4D759A9930C6DF4DED6483 ___4_task5, UniTask_1_t462EA7468BEE3A822B4D759A9930C6DF4DED6483 ___5_task6, UniTask_1_t462EA7468BEE3A822B4D759A9930C6DF4DED6483 ___6_task7, UniTask_1_t462EA7468BEE3A822B4D759A9930C6DF4DED6483 ___7_task8, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	const uint32_t SizeOf_Awaiter_t9A9C7894E67F92F62269992EF29FED74910CA8ED = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 4));
	const uint32_t SizeOf_Awaiter_t9550C174597C16586743A13FEF52613D8322DF94 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 19));
	const uint32_t SizeOf_Awaiter_t02688AF530BDE672EC936A6BAD803EEF1559F7AB = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 31));
	const uint32_t SizeOf_Awaiter_t7A81FFE0864F0EE80543D75C2BC11C55564435EC = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 43));
	const uint32_t SizeOf_Awaiter_t01E8F3A2EE7D051AE259071153960F5E026AEB07 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 55));
	const uint32_t SizeOf_Awaiter_t08DB486D320DE1EBF3F9FB652F567E70C353DE6B = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 67));
	const uint32_t SizeOf_Awaiter_tF4210D9DFBF825189111E59C53A746AC4672E5CF = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 79));
	const uint32_t SizeOf_Awaiter_tEF5C3968A5F16BAFA7F93AD302BB4FDBDF8CA948 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 91));
	const Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C L_0 = alloca(SizeOf_Awaiter_t9A9C7894E67F92F62269992EF29FED74910CA8ED);
	const Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C L_8 = L_0;
	const Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C L_10 = alloca(SizeOf_Awaiter_t9550C174597C16586743A13FEF52613D8322DF94);
	const Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C L_18 = L_10;
	const Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C L_20 = alloca(SizeOf_Awaiter_t02688AF530BDE672EC936A6BAD803EEF1559F7AB);
	const Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C L_28 = L_20;
	const Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C L_30 = alloca(SizeOf_Awaiter_t7A81FFE0864F0EE80543D75C2BC11C55564435EC);
	const Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C L_38 = L_30;
	const Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C L_40 = alloca(SizeOf_Awaiter_t01E8F3A2EE7D051AE259071153960F5E026AEB07);
	const Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C L_48 = L_40;
	const Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C L_50 = alloca(SizeOf_Awaiter_t08DB486D320DE1EBF3F9FB652F567E70C353DE6B);
	const Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C L_58 = L_50;
	const Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C L_60 = alloca(SizeOf_Awaiter_tF4210D9DFBF825189111E59C53A746AC4672E5CF);
	const Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C L_68 = L_60;
	const Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C L_70 = alloca(SizeOf_Awaiter_tEF5C3968A5F16BAFA7F93AD302BB4FDBDF8CA948);
	const Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C L_78 = L_70;
	Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C V_0 = alloca(SizeOf_Awaiter_t9A9C7894E67F92F62269992EF29FED74910CA8ED);
	memset(V_0, 0, SizeOf_Awaiter_t9A9C7894E67F92F62269992EF29FED74910CA8ED);
	bool V_1 = false;
	Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C V_2 = alloca(SizeOf_Awaiter_t9550C174597C16586743A13FEF52613D8322DF94);
	memset(V_2, 0, SizeOf_Awaiter_t9550C174597C16586743A13FEF52613D8322DF94);
	bool V_3 = false;
	Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C V_4 = alloca(SizeOf_Awaiter_t02688AF530BDE672EC936A6BAD803EEF1559F7AB);
	memset(V_4, 0, SizeOf_Awaiter_t02688AF530BDE672EC936A6BAD803EEF1559F7AB);
	bool V_5 = false;
	Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C V_6 = alloca(SizeOf_Awaiter_t7A81FFE0864F0EE80543D75C2BC11C55564435EC);
	memset(V_6, 0, SizeOf_Awaiter_t7A81FFE0864F0EE80543D75C2BC11C55564435EC);
	bool V_7 = false;
	Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C V_8 = alloca(SizeOf_Awaiter_t01E8F3A2EE7D051AE259071153960F5E026AEB07);
	memset(V_8, 0, SizeOf_Awaiter_t01E8F3A2EE7D051AE259071153960F5E026AEB07);
	bool V_9 = false;
	Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C V_10 = alloca(SizeOf_Awaiter_t08DB486D320DE1EBF3F9FB652F567E70C353DE6B);
	memset(V_10, 0, SizeOf_Awaiter_t08DB486D320DE1EBF3F9FB652F567E70C353DE6B);
	bool V_11 = false;
	Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C V_12 = alloca(SizeOf_Awaiter_tF4210D9DFBF825189111E59C53A746AC4672E5CF);
	memset(V_12, 0, SizeOf_Awaiter_tF4210D9DFBF825189111E59C53A746AC4672E5CF);
	bool V_13 = false;
	Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C V_14 = alloca(SizeOf_Awaiter_tEF5C3968A5F16BAFA7F93AD302BB4FDBDF8CA948);
	memset(V_14, 0, SizeOf_Awaiter_tEF5C3968A5F16BAFA7F93AD302BB4FDBDF8CA948);
	bool V_15 = false;
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* G_B4_0 = NULL;
	Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* G_B4_1 = NULL;
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* G_B3_0 = NULL;
	Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* G_B3_1 = NULL;
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* G_B9_0 = NULL;
	Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* G_B9_1 = NULL;
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* G_B8_0 = NULL;
	Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* G_B8_1 = NULL;
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* G_B14_0 = NULL;
	Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* G_B14_1 = NULL;
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* G_B13_0 = NULL;
	Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* G_B13_1 = NULL;
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* G_B19_0 = NULL;
	Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* G_B19_1 = NULL;
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* G_B18_0 = NULL;
	Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* G_B18_1 = NULL;
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* G_B24_0 = NULL;
	Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* G_B24_1 = NULL;
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* G_B23_0 = NULL;
	Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* G_B23_1 = NULL;
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* G_B29_0 = NULL;
	Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* G_B29_1 = NULL;
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* G_B28_0 = NULL;
	Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* G_B28_1 = NULL;
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* G_B34_0 = NULL;
	Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* G_B34_1 = NULL;
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* G_B33_0 = NULL;
	Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* G_B33_1 = NULL;
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* G_B39_0 = NULL;
	Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* G_B39_1 = NULL;
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* G_B38_0 = NULL;
	Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* G_B38_1 = NULL;
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2((RuntimeObject*)__this, NULL);
		il2cpp_codegen_write_instance_field_data<int32_t>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 0),0), 0);
		InvokerActionInvoker1< Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 2)), il2cpp_rgctx_method(method->klass->rgctx_data, 2), (UniTask_1_t462EA7468BEE3A822B4D759A9930C6DF4DED6483*)___0_task1, (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)L_0);
		il2cpp_codegen_memcpy(V_0, L_0, SizeOf_Awaiter_t9A9C7894E67F92F62269992EF29FED74910CA8ED);
		bool L_1;
		L_1 = ((  bool (*) (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 5)))((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_0, il2cpp_rgctx_method(method->klass->rgctx_data, 5));
		V_1 = L_1;
		bool L_2 = V_1;
		if (!L_2)
		{
			goto IL_0030;
		}
	}
	{
		((  void (*) (WhenAnyPromise_8_tB1A18813B231826F7BEE92541715D6266929F072*, Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 7)))(__this, (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_0, il2cpp_rgctx_method(method->klass->rgctx_data, 7));
		goto IL_0060;
	}

IL_0030:
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->klass->rgctx_data, 11));
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_3 = ((U3CU3Ec_tCA231E49E5C1E23CB178548188D1AF028B6EA7E5_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9__2_0;
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_4 = L_3;
		if (L_4)
		{
			G_B4_0 = L_4;
			G_B4_1 = ((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)(Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_0);
			goto IL_0052;
		}
		G_B3_0 = L_4;
		G_B3_1 = ((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)(Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_0);
	}
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->klass->rgctx_data, 11));
		U3CU3Ec_tCA231E49E5C1E23CB178548188D1AF028B6EA7E5* L_5 = ((U3CU3Ec_tCA231E49E5C1E23CB178548188D1AF028B6EA7E5_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9;
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_6 = (Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87*)il2cpp_codegen_object_new(Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87_il2cpp_TypeInfo_var);
		Action_1__ctor_m2E1DFA67718FC1A0B6E5DFEB78831FFE9C059EB4(L_6, (RuntimeObject*)L_5, (intptr_t)((void*)il2cpp_rgctx_method(method->klass->rgctx_data, 12)), NULL);
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_7 = L_6;
		((U3CU3Ec_tCA231E49E5C1E23CB178548188D1AF028B6EA7E5_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9__2_0 = L_7;
		Il2CppCodeGenWriteBarrier((void**)(&((U3CU3Ec_tCA231E49E5C1E23CB178548188D1AF028B6EA7E5_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9__2_0), (void*)L_7);
		G_B4_0 = L_7;
		G_B4_1 = ((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)G_B3_1);
	}

IL_0052:
	{
		il2cpp_codegen_memcpy(L_8, V_0, SizeOf_Awaiter_t9A9C7894E67F92F62269992EF29FED74910CA8ED);
		StateTuple_2_tC4A9F77640FBC0CC082D17B72B0414FE9A533C0D* L_9;
		L_9 = InvokerFuncInvoker2< StateTuple_2_tC4A9F77640FBC0CC082D17B72B0414FE9A533C0D*, WhenAnyPromise_8_tB1A18813B231826F7BEE92541715D6266929F072*, Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 13)), il2cpp_rgctx_method(method->klass->rgctx_data, 13), NULL, __this, L_8);
		((  void (*) (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*, Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87*, RuntimeObject*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 15)))(G_B4_1, G_B4_0, (RuntimeObject*)L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 15));
	}

IL_0060:
	{
		InvokerActionInvoker1< Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 17)), il2cpp_rgctx_method(method->klass->rgctx_data, 17), (UniTask_1_t462EA7468BEE3A822B4D759A9930C6DF4DED6483*)___1_task2, (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)L_10);
		il2cpp_codegen_memcpy(V_2, L_10, SizeOf_Awaiter_t9550C174597C16586743A13FEF52613D8322DF94);
		bool L_11;
		L_11 = ((  bool (*) (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 20)))((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_2, il2cpp_rgctx_method(method->klass->rgctx_data, 20));
		V_3 = L_11;
		bool L_12 = V_3;
		if (!L_12)
		{
			goto IL_0082;
		}
	}
	{
		((  void (*) (WhenAnyPromise_8_tB1A18813B231826F7BEE92541715D6266929F072*, Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 22)))(__this, (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_2, il2cpp_rgctx_method(method->klass->rgctx_data, 22));
		goto IL_00b2;
	}

IL_0082:
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->klass->rgctx_data, 11));
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_13 = ((U3CU3Ec_tCA231E49E5C1E23CB178548188D1AF028B6EA7E5_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9__2_1;
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_14 = L_13;
		if (L_14)
		{
			G_B9_0 = L_14;
			G_B9_1 = ((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)(Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_2);
			goto IL_00a4;
		}
		G_B8_0 = L_14;
		G_B8_1 = ((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)(Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_2);
	}
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->klass->rgctx_data, 11));
		U3CU3Ec_tCA231E49E5C1E23CB178548188D1AF028B6EA7E5* L_15 = ((U3CU3Ec_tCA231E49E5C1E23CB178548188D1AF028B6EA7E5_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9;
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_16 = (Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87*)il2cpp_codegen_object_new(Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87_il2cpp_TypeInfo_var);
		Action_1__ctor_m2E1DFA67718FC1A0B6E5DFEB78831FFE9C059EB4(L_16, (RuntimeObject*)L_15, (intptr_t)((void*)il2cpp_rgctx_method(method->klass->rgctx_data, 24)), NULL);
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_17 = L_16;
		((U3CU3Ec_tCA231E49E5C1E23CB178548188D1AF028B6EA7E5_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9__2_1 = L_17;
		Il2CppCodeGenWriteBarrier((void**)(&((U3CU3Ec_tCA231E49E5C1E23CB178548188D1AF028B6EA7E5_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9__2_1), (void*)L_17);
		G_B9_0 = L_17;
		G_B9_1 = ((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)G_B8_1);
	}

IL_00a4:
	{
		il2cpp_codegen_memcpy(L_18, V_2, SizeOf_Awaiter_t9550C174597C16586743A13FEF52613D8322DF94);
		StateTuple_2_tC4A9F77640FBC0CC082D17B72B0414FE9A533C0D* L_19;
		L_19 = InvokerFuncInvoker2< StateTuple_2_tC4A9F77640FBC0CC082D17B72B0414FE9A533C0D*, WhenAnyPromise_8_tB1A18813B231826F7BEE92541715D6266929F072*, Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 25)), il2cpp_rgctx_method(method->klass->rgctx_data, 25), NULL, __this, L_18);
		((  void (*) (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*, Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87*, RuntimeObject*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 27)))(G_B9_1, G_B9_0, (RuntimeObject*)L_19, il2cpp_rgctx_method(method->klass->rgctx_data, 27));
	}

IL_00b2:
	{
		InvokerActionInvoker1< Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 29)), il2cpp_rgctx_method(method->klass->rgctx_data, 29), (UniTask_1_t462EA7468BEE3A822B4D759A9930C6DF4DED6483*)___2_task3, (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)L_20);
		il2cpp_codegen_memcpy(V_4, L_20, SizeOf_Awaiter_t02688AF530BDE672EC936A6BAD803EEF1559F7AB);
		bool L_21;
		L_21 = ((  bool (*) (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 32)))((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_4, il2cpp_rgctx_method(method->klass->rgctx_data, 32));
		V_5 = L_21;
		bool L_22 = V_5;
		if (!L_22)
		{
			goto IL_00d7;
		}
	}
	{
		((  void (*) (WhenAnyPromise_8_tB1A18813B231826F7BEE92541715D6266929F072*, Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 34)))(__this, (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_4, il2cpp_rgctx_method(method->klass->rgctx_data, 34));
		goto IL_0108;
	}

IL_00d7:
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->klass->rgctx_data, 11));
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_23 = ((U3CU3Ec_tCA231E49E5C1E23CB178548188D1AF028B6EA7E5_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9__2_2;
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_24 = L_23;
		if (L_24)
		{
			G_B14_0 = L_24;
			G_B14_1 = ((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)(Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_4);
			goto IL_00f9;
		}
		G_B13_0 = L_24;
		G_B13_1 = ((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)(Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_4);
	}
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->klass->rgctx_data, 11));
		U3CU3Ec_tCA231E49E5C1E23CB178548188D1AF028B6EA7E5* L_25 = ((U3CU3Ec_tCA231E49E5C1E23CB178548188D1AF028B6EA7E5_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9;
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_26 = (Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87*)il2cpp_codegen_object_new(Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87_il2cpp_TypeInfo_var);
		Action_1__ctor_m2E1DFA67718FC1A0B6E5DFEB78831FFE9C059EB4(L_26, (RuntimeObject*)L_25, (intptr_t)((void*)il2cpp_rgctx_method(method->klass->rgctx_data, 36)), NULL);
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_27 = L_26;
		((U3CU3Ec_tCA231E49E5C1E23CB178548188D1AF028B6EA7E5_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9__2_2 = L_27;
		Il2CppCodeGenWriteBarrier((void**)(&((U3CU3Ec_tCA231E49E5C1E23CB178548188D1AF028B6EA7E5_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9__2_2), (void*)L_27);
		G_B14_0 = L_27;
		G_B14_1 = ((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)G_B13_1);
	}

IL_00f9:
	{
		il2cpp_codegen_memcpy(L_28, V_4, SizeOf_Awaiter_t02688AF530BDE672EC936A6BAD803EEF1559F7AB);
		StateTuple_2_tC4A9F77640FBC0CC082D17B72B0414FE9A533C0D* L_29;
		L_29 = InvokerFuncInvoker2< StateTuple_2_tC4A9F77640FBC0CC082D17B72B0414FE9A533C0D*, WhenAnyPromise_8_tB1A18813B231826F7BEE92541715D6266929F072*, Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 37)), il2cpp_rgctx_method(method->klass->rgctx_data, 37), NULL, __this, L_28);
		((  void (*) (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*, Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87*, RuntimeObject*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 39)))(G_B14_1, G_B14_0, (RuntimeObject*)L_29, il2cpp_rgctx_method(method->klass->rgctx_data, 39));
	}

IL_0108:
	{
		InvokerActionInvoker1< Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 41)), il2cpp_rgctx_method(method->klass->rgctx_data, 41), (UniTask_1_t462EA7468BEE3A822B4D759A9930C6DF4DED6483*)___3_task4, (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)L_30);
		il2cpp_codegen_memcpy(V_6, L_30, SizeOf_Awaiter_t7A81FFE0864F0EE80543D75C2BC11C55564435EC);
		bool L_31;
		L_31 = ((  bool (*) (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 44)))((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_6, il2cpp_rgctx_method(method->klass->rgctx_data, 44));
		V_7 = L_31;
		bool L_32 = V_7;
		if (!L_32)
		{
			goto IL_012d;
		}
	}
	{
		((  void (*) (WhenAnyPromise_8_tB1A18813B231826F7BEE92541715D6266929F072*, Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 46)))(__this, (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_6, il2cpp_rgctx_method(method->klass->rgctx_data, 46));
		goto IL_015e;
	}

IL_012d:
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->klass->rgctx_data, 11));
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_33 = ((U3CU3Ec_tCA231E49E5C1E23CB178548188D1AF028B6EA7E5_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9__2_3;
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_34 = L_33;
		if (L_34)
		{
			G_B19_0 = L_34;
			G_B19_1 = ((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)(Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_6);
			goto IL_014f;
		}
		G_B18_0 = L_34;
		G_B18_1 = ((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)(Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_6);
	}
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->klass->rgctx_data, 11));
		U3CU3Ec_tCA231E49E5C1E23CB178548188D1AF028B6EA7E5* L_35 = ((U3CU3Ec_tCA231E49E5C1E23CB178548188D1AF028B6EA7E5_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9;
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_36 = (Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87*)il2cpp_codegen_object_new(Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87_il2cpp_TypeInfo_var);
		Action_1__ctor_m2E1DFA67718FC1A0B6E5DFEB78831FFE9C059EB4(L_36, (RuntimeObject*)L_35, (intptr_t)((void*)il2cpp_rgctx_method(method->klass->rgctx_data, 48)), NULL);
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_37 = L_36;
		((U3CU3Ec_tCA231E49E5C1E23CB178548188D1AF028B6EA7E5_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9__2_3 = L_37;
		Il2CppCodeGenWriteBarrier((void**)(&((U3CU3Ec_tCA231E49E5C1E23CB178548188D1AF028B6EA7E5_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9__2_3), (void*)L_37);
		G_B19_0 = L_37;
		G_B19_1 = ((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)G_B18_1);
	}

IL_014f:
	{
		il2cpp_codegen_memcpy(L_38, V_6, SizeOf_Awaiter_t7A81FFE0864F0EE80543D75C2BC11C55564435EC);
		StateTuple_2_tC4A9F77640FBC0CC082D17B72B0414FE9A533C0D* L_39;
		L_39 = InvokerFuncInvoker2< StateTuple_2_tC4A9F77640FBC0CC082D17B72B0414FE9A533C0D*, WhenAnyPromise_8_tB1A18813B231826F7BEE92541715D6266929F072*, Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 49)), il2cpp_rgctx_method(method->klass->rgctx_data, 49), NULL, __this, L_38);
		((  void (*) (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*, Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87*, RuntimeObject*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 51)))(G_B19_1, G_B19_0, (RuntimeObject*)L_39, il2cpp_rgctx_method(method->klass->rgctx_data, 51));
	}

IL_015e:
	{
		InvokerActionInvoker1< Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 53)), il2cpp_rgctx_method(method->klass->rgctx_data, 53), (UniTask_1_t462EA7468BEE3A822B4D759A9930C6DF4DED6483*)___4_task5, (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)L_40);
		il2cpp_codegen_memcpy(V_8, L_40, SizeOf_Awaiter_t01E8F3A2EE7D051AE259071153960F5E026AEB07);
		bool L_41;
		L_41 = ((  bool (*) (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 56)))((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_8, il2cpp_rgctx_method(method->klass->rgctx_data, 56));
		V_9 = L_41;
		bool L_42 = V_9;
		if (!L_42)
		{
			goto IL_0183;
		}
	}
	{
		((  void (*) (WhenAnyPromise_8_tB1A18813B231826F7BEE92541715D6266929F072*, Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 58)))(__this, (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_8, il2cpp_rgctx_method(method->klass->rgctx_data, 58));
		goto IL_01b4;
	}

IL_0183:
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->klass->rgctx_data, 11));
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_43 = ((U3CU3Ec_tCA231E49E5C1E23CB178548188D1AF028B6EA7E5_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9__2_4;
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_44 = L_43;
		if (L_44)
		{
			G_B24_0 = L_44;
			G_B24_1 = ((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)(Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_8);
			goto IL_01a5;
		}
		G_B23_0 = L_44;
		G_B23_1 = ((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)(Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_8);
	}
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->klass->rgctx_data, 11));
		U3CU3Ec_tCA231E49E5C1E23CB178548188D1AF028B6EA7E5* L_45 = ((U3CU3Ec_tCA231E49E5C1E23CB178548188D1AF028B6EA7E5_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9;
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_46 = (Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87*)il2cpp_codegen_object_new(Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87_il2cpp_TypeInfo_var);
		Action_1__ctor_m2E1DFA67718FC1A0B6E5DFEB78831FFE9C059EB4(L_46, (RuntimeObject*)L_45, (intptr_t)((void*)il2cpp_rgctx_method(method->klass->rgctx_data, 60)), NULL);
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_47 = L_46;
		((U3CU3Ec_tCA231E49E5C1E23CB178548188D1AF028B6EA7E5_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9__2_4 = L_47;
		Il2CppCodeGenWriteBarrier((void**)(&((U3CU3Ec_tCA231E49E5C1E23CB178548188D1AF028B6EA7E5_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9__2_4), (void*)L_47);
		G_B24_0 = L_47;
		G_B24_1 = ((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)G_B23_1);
	}

IL_01a5:
	{
		il2cpp_codegen_memcpy(L_48, V_8, SizeOf_Awaiter_t01E8F3A2EE7D051AE259071153960F5E026AEB07);
		StateTuple_2_tC4A9F77640FBC0CC082D17B72B0414FE9A533C0D* L_49;
		L_49 = InvokerFuncInvoker2< StateTuple_2_tC4A9F77640FBC0CC082D17B72B0414FE9A533C0D*, WhenAnyPromise_8_tB1A18813B231826F7BEE92541715D6266929F072*, Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 61)), il2cpp_rgctx_method(method->klass->rgctx_data, 61), NULL, __this, L_48);
		((  void (*) (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*, Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87*, RuntimeObject*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 63)))(G_B24_1, G_B24_0, (RuntimeObject*)L_49, il2cpp_rgctx_method(method->klass->rgctx_data, 63));
	}

IL_01b4:
	{
		InvokerActionInvoker1< Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 65)), il2cpp_rgctx_method(method->klass->rgctx_data, 65), (UniTask_1_t462EA7468BEE3A822B4D759A9930C6DF4DED6483*)___5_task6, (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)L_50);
		il2cpp_codegen_memcpy(V_10, L_50, SizeOf_Awaiter_t08DB486D320DE1EBF3F9FB652F567E70C353DE6B);
		bool L_51;
		L_51 = ((  bool (*) (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 68)))((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_10, il2cpp_rgctx_method(method->klass->rgctx_data, 68));
		V_11 = L_51;
		bool L_52 = V_11;
		if (!L_52)
		{
			goto IL_01d9;
		}
	}
	{
		((  void (*) (WhenAnyPromise_8_tB1A18813B231826F7BEE92541715D6266929F072*, Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 70)))(__this, (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_10, il2cpp_rgctx_method(method->klass->rgctx_data, 70));
		goto IL_020a;
	}

IL_01d9:
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->klass->rgctx_data, 11));
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_53 = ((U3CU3Ec_tCA231E49E5C1E23CB178548188D1AF028B6EA7E5_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9__2_5;
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_54 = L_53;
		if (L_54)
		{
			G_B29_0 = L_54;
			G_B29_1 = ((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)(Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_10);
			goto IL_01fb;
		}
		G_B28_0 = L_54;
		G_B28_1 = ((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)(Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_10);
	}
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->klass->rgctx_data, 11));
		U3CU3Ec_tCA231E49E5C1E23CB178548188D1AF028B6EA7E5* L_55 = ((U3CU3Ec_tCA231E49E5C1E23CB178548188D1AF028B6EA7E5_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9;
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_56 = (Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87*)il2cpp_codegen_object_new(Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87_il2cpp_TypeInfo_var);
		Action_1__ctor_m2E1DFA67718FC1A0B6E5DFEB78831FFE9C059EB4(L_56, (RuntimeObject*)L_55, (intptr_t)((void*)il2cpp_rgctx_method(method->klass->rgctx_data, 72)), NULL);
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_57 = L_56;
		((U3CU3Ec_tCA231E49E5C1E23CB178548188D1AF028B6EA7E5_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9__2_5 = L_57;
		Il2CppCodeGenWriteBarrier((void**)(&((U3CU3Ec_tCA231E49E5C1E23CB178548188D1AF028B6EA7E5_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9__2_5), (void*)L_57);
		G_B29_0 = L_57;
		G_B29_1 = ((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)G_B28_1);
	}

IL_01fb:
	{
		il2cpp_codegen_memcpy(L_58, V_10, SizeOf_Awaiter_t08DB486D320DE1EBF3F9FB652F567E70C353DE6B);
		StateTuple_2_tC4A9F77640FBC0CC082D17B72B0414FE9A533C0D* L_59;
		L_59 = InvokerFuncInvoker2< StateTuple_2_tC4A9F77640FBC0CC082D17B72B0414FE9A533C0D*, WhenAnyPromise_8_tB1A18813B231826F7BEE92541715D6266929F072*, Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 73)), il2cpp_rgctx_method(method->klass->rgctx_data, 73), NULL, __this, L_58);
		((  void (*) (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*, Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87*, RuntimeObject*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 75)))(G_B29_1, G_B29_0, (RuntimeObject*)L_59, il2cpp_rgctx_method(method->klass->rgctx_data, 75));
	}

IL_020a:
	{
		InvokerActionInvoker1< Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 77)), il2cpp_rgctx_method(method->klass->rgctx_data, 77), (UniTask_1_t462EA7468BEE3A822B4D759A9930C6DF4DED6483*)___6_task7, (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)L_60);
		il2cpp_codegen_memcpy(V_12, L_60, SizeOf_Awaiter_tF4210D9DFBF825189111E59C53A746AC4672E5CF);
		bool L_61;
		L_61 = ((  bool (*) (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 80)))((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_12, il2cpp_rgctx_method(method->klass->rgctx_data, 80));
		V_13 = L_61;
		bool L_62 = V_13;
		if (!L_62)
		{
			goto IL_022f;
		}
	}
	{
		((  void (*) (WhenAnyPromise_8_tB1A18813B231826F7BEE92541715D6266929F072*, Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 82)))(__this, (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_12, il2cpp_rgctx_method(method->klass->rgctx_data, 82));
		goto IL_0260;
	}

IL_022f:
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->klass->rgctx_data, 11));
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_63 = ((U3CU3Ec_tCA231E49E5C1E23CB178548188D1AF028B6EA7E5_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9__2_6;
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_64 = L_63;
		if (L_64)
		{
			G_B34_0 = L_64;
			G_B34_1 = ((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)(Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_12);
			goto IL_0251;
		}
		G_B33_0 = L_64;
		G_B33_1 = ((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)(Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_12);
	}
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->klass->rgctx_data, 11));
		U3CU3Ec_tCA231E49E5C1E23CB178548188D1AF028B6EA7E5* L_65 = ((U3CU3Ec_tCA231E49E5C1E23CB178548188D1AF028B6EA7E5_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9;
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_66 = (Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87*)il2cpp_codegen_object_new(Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87_il2cpp_TypeInfo_var);
		Action_1__ctor_m2E1DFA67718FC1A0B6E5DFEB78831FFE9C059EB4(L_66, (RuntimeObject*)L_65, (intptr_t)((void*)il2cpp_rgctx_method(method->klass->rgctx_data, 84)), NULL);
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_67 = L_66;
		((U3CU3Ec_tCA231E49E5C1E23CB178548188D1AF028B6EA7E5_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9__2_6 = L_67;
		Il2CppCodeGenWriteBarrier((void**)(&((U3CU3Ec_tCA231E49E5C1E23CB178548188D1AF028B6EA7E5_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9__2_6), (void*)L_67);
		G_B34_0 = L_67;
		G_B34_1 = ((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)G_B33_1);
	}

IL_0251:
	{
		il2cpp_codegen_memcpy(L_68, V_12, SizeOf_Awaiter_tF4210D9DFBF825189111E59C53A746AC4672E5CF);
		StateTuple_2_tC4A9F77640FBC0CC082D17B72B0414FE9A533C0D* L_69;
		L_69 = InvokerFuncInvoker2< StateTuple_2_tC4A9F77640FBC0CC082D17B72B0414FE9A533C0D*, WhenAnyPromise_8_tB1A18813B231826F7BEE92541715D6266929F072*, Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 85)), il2cpp_rgctx_method(method->klass->rgctx_data, 85), NULL, __this, L_68);
		((  void (*) (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*, Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87*, RuntimeObject*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 87)))(G_B34_1, G_B34_0, (RuntimeObject*)L_69, il2cpp_rgctx_method(method->klass->rgctx_data, 87));
	}

IL_0260:
	{
		InvokerActionInvoker1< Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 89)), il2cpp_rgctx_method(method->klass->rgctx_data, 89), (UniTask_1_t462EA7468BEE3A822B4D759A9930C6DF4DED6483*)___7_task8, (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)L_70);
		il2cpp_codegen_memcpy(V_14, L_70, SizeOf_Awaiter_tEF5C3968A5F16BAFA7F93AD302BB4FDBDF8CA948);
		bool L_71;
		L_71 = ((  bool (*) (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 92)))((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_14, il2cpp_rgctx_method(method->klass->rgctx_data, 92));
		V_15 = L_71;
		bool L_72 = V_15;
		if (!L_72)
		{
			goto IL_0285;
		}
	}
	{
		((  void (*) (WhenAnyPromise_8_tB1A18813B231826F7BEE92541715D6266929F072*, Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 94)))(__this, (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_14, il2cpp_rgctx_method(method->klass->rgctx_data, 94));
		goto IL_02b6;
	}

IL_0285:
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->klass->rgctx_data, 11));
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_73 = ((U3CU3Ec_tCA231E49E5C1E23CB178548188D1AF028B6EA7E5_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9__2_7;
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_74 = L_73;
		if (L_74)
		{
			G_B39_0 = L_74;
			G_B39_1 = ((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)(Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_14);
			goto IL_02a7;
		}
		G_B38_0 = L_74;
		G_B38_1 = ((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)(Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_14);
	}
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->klass->rgctx_data, 11));
		U3CU3Ec_tCA231E49E5C1E23CB178548188D1AF028B6EA7E5* L_75 = ((U3CU3Ec_tCA231E49E5C1E23CB178548188D1AF028B6EA7E5_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9;
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_76 = (Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87*)il2cpp_codegen_object_new(Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87_il2cpp_TypeInfo_var);
		Action_1__ctor_m2E1DFA67718FC1A0B6E5DFEB78831FFE9C059EB4(L_76, (RuntimeObject*)L_75, (intptr_t)((void*)il2cpp_rgctx_method(method->klass->rgctx_data, 96)), NULL);
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_77 = L_76;
		((U3CU3Ec_tCA231E49E5C1E23CB178548188D1AF028B6EA7E5_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9__2_7 = L_77;
		Il2CppCodeGenWriteBarrier((void**)(&((U3CU3Ec_tCA231E49E5C1E23CB178548188D1AF028B6EA7E5_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9__2_7), (void*)L_77);
		G_B39_0 = L_77;
		G_B39_1 = ((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)G_B38_1);
	}

IL_02a7:
	{
		il2cpp_codegen_memcpy(L_78, V_14, SizeOf_Awaiter_tEF5C3968A5F16BAFA7F93AD302BB4FDBDF8CA948);
		StateTuple_2_tC4A9F77640FBC0CC082D17B72B0414FE9A533C0D* L_79;
		L_79 = InvokerFuncInvoker2< StateTuple_2_tC4A9F77640FBC0CC082D17B72B0414FE9A533C0D*, WhenAnyPromise_8_tB1A18813B231826F7BEE92541715D6266929F072*, Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 97)), il2cpp_rgctx_method(method->klass->rgctx_data, 97), NULL, __this, L_78);
		((  void (*) (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*, Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87*, RuntimeObject*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 99)))(G_B39_1, G_B39_0, (RuntimeObject*)L_79, il2cpp_rgctx_method(method->klass->rgctx_data, 99));
	}

IL_02b6:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhenAnyPromise_8_TryInvokeContinuationT1_m74BD369380F9A340D7205EEAF599C4F26BBB4818_gshared (WhenAnyPromise_8_tB1A18813B231826F7BEE92541715D6266929F072* ___0_self, Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* ___1_awaiter, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T1_t9561033C9FAB66A59515AC513C37865C3B8B1C18 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 101));
	const uint32_t SizeOf_T2_t60A74597284FB13F39BBDE70DD68794BD9BAC16D = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 105));
	const uint32_t SizeOf_T3_t17D6D15FA58A3752AECA204EA2A27CF117C6BD27 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 106));
	const uint32_t SizeOf_T4_tA6EA1FDA558CFF527D8E1C6FD66E4BCF5A863863 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 107));
	const uint32_t SizeOf_T5_tB849E0E76BE46D68793D81D57EA80E4C07ED9C11 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 108));
	const uint32_t SizeOf_T6_t2C03AD7AA0DA698E7086E9F7DC38F179995C5D0C = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 109));
	const uint32_t SizeOf_T7_t12AF7525E88D4361083E6F50DD71ECC32E6985A7 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 110));
	const uint32_t SizeOf_T8_t2EB77468546390559127DE1F112A1E7F29F79F90 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 111));
	const uint32_t SizeOf_ValueTuple_2_tEFD44100BF6E84A07E01EE4796B1C6D5293D34EB = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 112));
	const uint32_t SizeOf_ValueTuple_8_t5A4F9798F00844711054552CC2AA9D1C017B186C = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 114));
	const Il2CppFullySharedGenericAny L_1 = alloca(SizeOf_T1_t9561033C9FAB66A59515AC513C37865C3B8B1C18);
	const Il2CppFullySharedGenericAny L_10 = L_1;
	const Il2CppFullySharedGenericAny L_21 = alloca(SizeOf_T1_t9561033C9FAB66A59515AC513C37865C3B8B1C18);
	const Il2CppFullySharedGenericAny L_11 = alloca(SizeOf_T2_t60A74597284FB13F39BBDE70DD68794BD9BAC16D);
	const Il2CppFullySharedGenericAny L_22 = alloca(SizeOf_T2_t60A74597284FB13F39BBDE70DD68794BD9BAC16D);
	const Il2CppFullySharedGenericAny L_12 = alloca(SizeOf_T3_t17D6D15FA58A3752AECA204EA2A27CF117C6BD27);
	const Il2CppFullySharedGenericAny L_23 = alloca(SizeOf_T3_t17D6D15FA58A3752AECA204EA2A27CF117C6BD27);
	const Il2CppFullySharedGenericAny L_13 = alloca(SizeOf_T4_tA6EA1FDA558CFF527D8E1C6FD66E4BCF5A863863);
	const Il2CppFullySharedGenericAny L_24 = alloca(SizeOf_T4_tA6EA1FDA558CFF527D8E1C6FD66E4BCF5A863863);
	const Il2CppFullySharedGenericAny L_14 = alloca(SizeOf_T5_tB849E0E76BE46D68793D81D57EA80E4C07ED9C11);
	const Il2CppFullySharedGenericAny L_25 = alloca(SizeOf_T5_tB849E0E76BE46D68793D81D57EA80E4C07ED9C11);
	const Il2CppFullySharedGenericAny L_15 = alloca(SizeOf_T6_t2C03AD7AA0DA698E7086E9F7DC38F179995C5D0C);
	const Il2CppFullySharedGenericAny L_26 = alloca(SizeOf_T6_t2C03AD7AA0DA698E7086E9F7DC38F179995C5D0C);
	const Il2CppFullySharedGenericAny L_16 = alloca(SizeOf_T7_t12AF7525E88D4361083E6F50DD71ECC32E6985A7);
	const Il2CppFullySharedGenericAny L_18 = alloca(SizeOf_T7_t12AF7525E88D4361083E6F50DD71ECC32E6985A7);
	const Il2CppFullySharedGenericAny L_17 = alloca(SizeOf_T8_t2EB77468546390559127DE1F112A1E7F29F79F90);
	const Il2CppFullySharedGenericAny L_19 = alloca(SizeOf_T8_t2EB77468546390559127DE1F112A1E7F29F79F90);
	const ValueTuple_2_tBAA1E1D7D97D80E0EBA7FE8773B1FF409AEA3829 L_20 = alloca(SizeOf_ValueTuple_2_tEFD44100BF6E84A07E01EE4796B1C6D5293D34EB);
	const ValueTuple_2_tBAA1E1D7D97D80E0EBA7FE8773B1FF409AEA3829 L_27 = alloca(SizeOf_ValueTuple_2_tEFD44100BF6E84A07E01EE4796B1C6D5293D34EB);
	const ValueTuple_8_tD42E286CF79B463B55FD4A534F1A73E02CAEECC5 L_28 = alloca(SizeOf_ValueTuple_8_t5A4F9798F00844711054552CC2AA9D1C017B186C);
	Il2CppFullySharedGenericAny V_0 = alloca(SizeOf_T1_t9561033C9FAB66A59515AC513C37865C3B8B1C18);
	memset(V_0, 0, SizeOf_T1_t9561033C9FAB66A59515AC513C37865C3B8B1C18);
	Exception_t* V_1 = NULL;
	bool V_2 = false;
	Il2CppFullySharedGenericAny V_3 = alloca(SizeOf_T2_t60A74597284FB13F39BBDE70DD68794BD9BAC16D);
	memset(V_3, 0, SizeOf_T2_t60A74597284FB13F39BBDE70DD68794BD9BAC16D);
	Il2CppFullySharedGenericAny V_4 = alloca(SizeOf_T3_t17D6D15FA58A3752AECA204EA2A27CF117C6BD27);
	memset(V_4, 0, SizeOf_T3_t17D6D15FA58A3752AECA204EA2A27CF117C6BD27);
	Il2CppFullySharedGenericAny V_5 = alloca(SizeOf_T4_tA6EA1FDA558CFF527D8E1C6FD66E4BCF5A863863);
	memset(V_5, 0, SizeOf_T4_tA6EA1FDA558CFF527D8E1C6FD66E4BCF5A863863);
	Il2CppFullySharedGenericAny V_6 = alloca(SizeOf_T5_tB849E0E76BE46D68793D81D57EA80E4C07ED9C11);
	memset(V_6, 0, SizeOf_T5_tB849E0E76BE46D68793D81D57EA80E4C07ED9C11);
	Il2CppFullySharedGenericAny V_7 = alloca(SizeOf_T6_t2C03AD7AA0DA698E7086E9F7DC38F179995C5D0C);
	memset(V_7, 0, SizeOf_T6_t2C03AD7AA0DA698E7086E9F7DC38F179995C5D0C);
	Il2CppFullySharedGenericAny V_8 = alloca(SizeOf_T7_t12AF7525E88D4361083E6F50DD71ECC32E6985A7);
	memset(V_8, 0, SizeOf_T7_t12AF7525E88D4361083E6F50DD71ECC32E6985A7);
	Il2CppFullySharedGenericAny V_9 = alloca(SizeOf_T8_t2EB77468546390559127DE1F112A1E7F29F79F90);
	memset(V_9, 0, SizeOf_T8_t2EB77468546390559127DE1F112A1E7F29F79F90);
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
	}
	try
	{
		Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* L_0 = ___1_awaiter;
		InvokerActionInvoker1< Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 100)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 100), L_0, (Il2CppFullySharedGenericAny*)L_1);
		il2cpp_codegen_memcpy(V_0, L_1, SizeOf_T1_t9561033C9FAB66A59515AC513C37865C3B8B1C18);
		goto IL_001d;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&Exception_t_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_000c;
		}
		throw e;
	}

CATCH_000c:
	{
		Exception_t* L_2 = ((Exception_t*)IL2CPP_GET_ACTIVE_EXCEPTION(Exception_t*));;
		V_1 = L_2;
		WhenAnyPromise_8_tB1A18813B231826F7BEE92541715D6266929F072* L_3 = ___0_self;
		Exception_t* L_4 = V_1;
		bool L_5;
		L_5 = ((  bool (*) (UniTaskCompletionSourceCore_1_tA9C7E3CB9001D1F438C1C3BBA224B20995E6A7A2*, Exception_t*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 103)))((((UniTaskCompletionSourceCore_1_tA9C7E3CB9001D1F438C1C3BBA224B20995E6A7A2*)il2cpp_codegen_get_instance_field_data_pointer(L_3, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),1)))), L_4, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 103));
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_008e;
	}

IL_001d:
	{
		WhenAnyPromise_8_tB1A18813B231826F7BEE92541715D6266929F072* L_6 = ___0_self;
		int32_t L_7;
		L_7 = Interlocked_Increment_m3C240C32E8D9544EC050B74D4F28EEB58F1F9309((((int32_t*)il2cpp_codegen_get_instance_field_data_pointer(L_6, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),0)))), NULL);
		V_2 = (bool)((((int32_t)L_7) == ((int32_t)1))? 1 : 0);
		bool L_8 = V_2;
		if (!L_8)
		{
			goto IL_008e;
		}
	}
	{
		WhenAnyPromise_8_tB1A18813B231826F7BEE92541715D6266929F072* L_9 = ___0_self;
		il2cpp_codegen_memcpy(L_10, V_0, SizeOf_T1_t9561033C9FAB66A59515AC513C37865C3B8B1C18);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_3, SizeOf_T2_t60A74597284FB13F39BBDE70DD68794BD9BAC16D);
		il2cpp_codegen_memcpy(L_11, V_3, SizeOf_T2_t60A74597284FB13F39BBDE70DD68794BD9BAC16D);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_4, SizeOf_T3_t17D6D15FA58A3752AECA204EA2A27CF117C6BD27);
		il2cpp_codegen_memcpy(L_12, V_4, SizeOf_T3_t17D6D15FA58A3752AECA204EA2A27CF117C6BD27);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_5, SizeOf_T4_tA6EA1FDA558CFF527D8E1C6FD66E4BCF5A863863);
		il2cpp_codegen_memcpy(L_13, V_5, SizeOf_T4_tA6EA1FDA558CFF527D8E1C6FD66E4BCF5A863863);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_6, SizeOf_T5_tB849E0E76BE46D68793D81D57EA80E4C07ED9C11);
		il2cpp_codegen_memcpy(L_14, V_6, SizeOf_T5_tB849E0E76BE46D68793D81D57EA80E4C07ED9C11);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_7, SizeOf_T6_t2C03AD7AA0DA698E7086E9F7DC38F179995C5D0C);
		il2cpp_codegen_memcpy(L_15, V_7, SizeOf_T6_t2C03AD7AA0DA698E7086E9F7DC38F179995C5D0C);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_8, SizeOf_T7_t12AF7525E88D4361083E6F50DD71ECC32E6985A7);
		il2cpp_codegen_memcpy(L_16, V_8, SizeOf_T7_t12AF7525E88D4361083E6F50DD71ECC32E6985A7);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_9, SizeOf_T8_t2EB77468546390559127DE1F112A1E7F29F79F90);
		il2cpp_codegen_memcpy(L_17, V_9, SizeOf_T8_t2EB77468546390559127DE1F112A1E7F29F79F90);
		memset(L_20, 0, SizeOf_ValueTuple_2_tEFD44100BF6E84A07E01EE4796B1C6D5293D34EB);
		ValueTuple_2__ctor_mCAE8E725F680FA6BE2C23B9686C9F6056BB7E5CD((ValueTuple_2_tBAA1E1D7D97D80E0EBA7FE8773B1FF409AEA3829*)L_20, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 110)) ? il2cpp_codegen_memcpy(L_18, L_16, SizeOf_T7_t12AF7525E88D4361083E6F50DD71ECC32E6985A7): *(void**)L_16), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 111)) ? il2cpp_codegen_memcpy(L_19, L_17, SizeOf_T8_t2EB77468546390559127DE1F112A1E7F29F79F90): *(void**)L_17), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 113));
		memset(L_28, 0, SizeOf_ValueTuple_8_t5A4F9798F00844711054552CC2AA9D1C017B186C);
		ValueTuple_8__ctor_m03E5F35F1F6A37FA114EA2D38102DC71B063F122((ValueTuple_8_tD42E286CF79B463B55FD4A534F1A73E02CAEECC5*)L_28, 0, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 101)) ? il2cpp_codegen_memcpy(L_21, L_10, SizeOf_T1_t9561033C9FAB66A59515AC513C37865C3B8B1C18): *(void**)L_10), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 105)) ? il2cpp_codegen_memcpy(L_22, L_11, SizeOf_T2_t60A74597284FB13F39BBDE70DD68794BD9BAC16D): *(void**)L_11), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 106)) ? il2cpp_codegen_memcpy(L_23, L_12, SizeOf_T3_t17D6D15FA58A3752AECA204EA2A27CF117C6BD27): *(void**)L_12), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 107)) ? il2cpp_codegen_memcpy(L_24, L_13, SizeOf_T4_tA6EA1FDA558CFF527D8E1C6FD66E4BCF5A863863): *(void**)L_13), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 108)) ? il2cpp_codegen_memcpy(L_25, L_14, SizeOf_T5_tB849E0E76BE46D68793D81D57EA80E4C07ED9C11): *(void**)L_14), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 109)) ? il2cpp_codegen_memcpy(L_26, L_15, SizeOf_T6_t2C03AD7AA0DA698E7086E9F7DC38F179995C5D0C): *(void**)L_15), il2cpp_codegen_memcpy(L_27, L_20, SizeOf_ValueTuple_2_tEFD44100BF6E84A07E01EE4796B1C6D5293D34EB), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 115));
		bool L_29;
		L_29 = InvokerFuncInvoker1< bool, ValueTuple_8_tD42E286CF79B463B55FD4A534F1A73E02CAEECC5 >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 116)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 116), (((UniTaskCompletionSourceCore_1_tA9C7E3CB9001D1F438C1C3BBA224B20995E6A7A2*)il2cpp_codegen_get_instance_field_data_pointer(L_9, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),1)))), L_28);
	}

IL_008e:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhenAnyPromise_8_TryInvokeContinuationT2_m54BE10B1D7BD6627B69A9B4BA60B635349E9D526_gshared (WhenAnyPromise_8_tB1A18813B231826F7BEE92541715D6266929F072* ___0_self, Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* ___1_awaiter, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T2_t60A74597284FB13F39BBDE70DD68794BD9BAC16D = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 105));
	const uint32_t SizeOf_T1_t9561033C9FAB66A59515AC513C37865C3B8B1C18 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 101));
	const uint32_t SizeOf_T3_t17D6D15FA58A3752AECA204EA2A27CF117C6BD27 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 106));
	const uint32_t SizeOf_T4_tA6EA1FDA558CFF527D8E1C6FD66E4BCF5A863863 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 107));
	const uint32_t SizeOf_T5_tB849E0E76BE46D68793D81D57EA80E4C07ED9C11 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 108));
	const uint32_t SizeOf_T6_t2C03AD7AA0DA698E7086E9F7DC38F179995C5D0C = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 109));
	const uint32_t SizeOf_T7_t12AF7525E88D4361083E6F50DD71ECC32E6985A7 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 110));
	const uint32_t SizeOf_T8_t2EB77468546390559127DE1F112A1E7F29F79F90 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 111));
	const uint32_t SizeOf_ValueTuple_2_tEFD44100BF6E84A07E01EE4796B1C6D5293D34EB = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 112));
	const uint32_t SizeOf_ValueTuple_8_t5A4F9798F00844711054552CC2AA9D1C017B186C = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 114));
	const Il2CppFullySharedGenericAny L_10 = alloca(SizeOf_T1_t9561033C9FAB66A59515AC513C37865C3B8B1C18);
	const Il2CppFullySharedGenericAny L_21 = alloca(SizeOf_T1_t9561033C9FAB66A59515AC513C37865C3B8B1C18);
	const Il2CppFullySharedGenericAny L_1 = alloca(SizeOf_T2_t60A74597284FB13F39BBDE70DD68794BD9BAC16D);
	const Il2CppFullySharedGenericAny L_11 = L_1;
	const Il2CppFullySharedGenericAny L_22 = alloca(SizeOf_T2_t60A74597284FB13F39BBDE70DD68794BD9BAC16D);
	const Il2CppFullySharedGenericAny L_12 = alloca(SizeOf_T3_t17D6D15FA58A3752AECA204EA2A27CF117C6BD27);
	const Il2CppFullySharedGenericAny L_23 = alloca(SizeOf_T3_t17D6D15FA58A3752AECA204EA2A27CF117C6BD27);
	const Il2CppFullySharedGenericAny L_13 = alloca(SizeOf_T4_tA6EA1FDA558CFF527D8E1C6FD66E4BCF5A863863);
	const Il2CppFullySharedGenericAny L_24 = alloca(SizeOf_T4_tA6EA1FDA558CFF527D8E1C6FD66E4BCF5A863863);
	const Il2CppFullySharedGenericAny L_14 = alloca(SizeOf_T5_tB849E0E76BE46D68793D81D57EA80E4C07ED9C11);
	const Il2CppFullySharedGenericAny L_25 = alloca(SizeOf_T5_tB849E0E76BE46D68793D81D57EA80E4C07ED9C11);
	const Il2CppFullySharedGenericAny L_15 = alloca(SizeOf_T6_t2C03AD7AA0DA698E7086E9F7DC38F179995C5D0C);
	const Il2CppFullySharedGenericAny L_26 = alloca(SizeOf_T6_t2C03AD7AA0DA698E7086E9F7DC38F179995C5D0C);
	const Il2CppFullySharedGenericAny L_16 = alloca(SizeOf_T7_t12AF7525E88D4361083E6F50DD71ECC32E6985A7);
	const Il2CppFullySharedGenericAny L_18 = alloca(SizeOf_T7_t12AF7525E88D4361083E6F50DD71ECC32E6985A7);
	const Il2CppFullySharedGenericAny L_17 = alloca(SizeOf_T8_t2EB77468546390559127DE1F112A1E7F29F79F90);
	const Il2CppFullySharedGenericAny L_19 = alloca(SizeOf_T8_t2EB77468546390559127DE1F112A1E7F29F79F90);
	const ValueTuple_2_tBAA1E1D7D97D80E0EBA7FE8773B1FF409AEA3829 L_20 = alloca(SizeOf_ValueTuple_2_tEFD44100BF6E84A07E01EE4796B1C6D5293D34EB);
	const ValueTuple_2_tBAA1E1D7D97D80E0EBA7FE8773B1FF409AEA3829 L_27 = alloca(SizeOf_ValueTuple_2_tEFD44100BF6E84A07E01EE4796B1C6D5293D34EB);
	const ValueTuple_8_tD42E286CF79B463B55FD4A534F1A73E02CAEECC5 L_28 = alloca(SizeOf_ValueTuple_8_t5A4F9798F00844711054552CC2AA9D1C017B186C);
	Il2CppFullySharedGenericAny V_0 = alloca(SizeOf_T2_t60A74597284FB13F39BBDE70DD68794BD9BAC16D);
	memset(V_0, 0, SizeOf_T2_t60A74597284FB13F39BBDE70DD68794BD9BAC16D);
	Exception_t* V_1 = NULL;
	bool V_2 = false;
	Il2CppFullySharedGenericAny V_3 = alloca(SizeOf_T1_t9561033C9FAB66A59515AC513C37865C3B8B1C18);
	memset(V_3, 0, SizeOf_T1_t9561033C9FAB66A59515AC513C37865C3B8B1C18);
	Il2CppFullySharedGenericAny V_4 = alloca(SizeOf_T3_t17D6D15FA58A3752AECA204EA2A27CF117C6BD27);
	memset(V_4, 0, SizeOf_T3_t17D6D15FA58A3752AECA204EA2A27CF117C6BD27);
	Il2CppFullySharedGenericAny V_5 = alloca(SizeOf_T4_tA6EA1FDA558CFF527D8E1C6FD66E4BCF5A863863);
	memset(V_5, 0, SizeOf_T4_tA6EA1FDA558CFF527D8E1C6FD66E4BCF5A863863);
	Il2CppFullySharedGenericAny V_6 = alloca(SizeOf_T5_tB849E0E76BE46D68793D81D57EA80E4C07ED9C11);
	memset(V_6, 0, SizeOf_T5_tB849E0E76BE46D68793D81D57EA80E4C07ED9C11);
	Il2CppFullySharedGenericAny V_7 = alloca(SizeOf_T6_t2C03AD7AA0DA698E7086E9F7DC38F179995C5D0C);
	memset(V_7, 0, SizeOf_T6_t2C03AD7AA0DA698E7086E9F7DC38F179995C5D0C);
	Il2CppFullySharedGenericAny V_8 = alloca(SizeOf_T7_t12AF7525E88D4361083E6F50DD71ECC32E6985A7);
	memset(V_8, 0, SizeOf_T7_t12AF7525E88D4361083E6F50DD71ECC32E6985A7);
	Il2CppFullySharedGenericAny V_9 = alloca(SizeOf_T8_t2EB77468546390559127DE1F112A1E7F29F79F90);
	memset(V_9, 0, SizeOf_T8_t2EB77468546390559127DE1F112A1E7F29F79F90);
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
	}
	try
	{
		Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* L_0 = ___1_awaiter;
		InvokerActionInvoker1< Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 117)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 117), L_0, (Il2CppFullySharedGenericAny*)L_1);
		il2cpp_codegen_memcpy(V_0, L_1, SizeOf_T2_t60A74597284FB13F39BBDE70DD68794BD9BAC16D);
		goto IL_001d;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&Exception_t_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_000c;
		}
		throw e;
	}

CATCH_000c:
	{
		Exception_t* L_2 = ((Exception_t*)IL2CPP_GET_ACTIVE_EXCEPTION(Exception_t*));;
		V_1 = L_2;
		WhenAnyPromise_8_tB1A18813B231826F7BEE92541715D6266929F072* L_3 = ___0_self;
		Exception_t* L_4 = V_1;
		bool L_5;
		L_5 = ((  bool (*) (UniTaskCompletionSourceCore_1_tA9C7E3CB9001D1F438C1C3BBA224B20995E6A7A2*, Exception_t*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 103)))((((UniTaskCompletionSourceCore_1_tA9C7E3CB9001D1F438C1C3BBA224B20995E6A7A2*)il2cpp_codegen_get_instance_field_data_pointer(L_3, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),1)))), L_4, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 103));
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_008e;
	}

IL_001d:
	{
		WhenAnyPromise_8_tB1A18813B231826F7BEE92541715D6266929F072* L_6 = ___0_self;
		int32_t L_7;
		L_7 = Interlocked_Increment_m3C240C32E8D9544EC050B74D4F28EEB58F1F9309((((int32_t*)il2cpp_codegen_get_instance_field_data_pointer(L_6, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),0)))), NULL);
		V_2 = (bool)((((int32_t)L_7) == ((int32_t)1))? 1 : 0);
		bool L_8 = V_2;
		if (!L_8)
		{
			goto IL_008e;
		}
	}
	{
		WhenAnyPromise_8_tB1A18813B231826F7BEE92541715D6266929F072* L_9 = ___0_self;
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_3, SizeOf_T1_t9561033C9FAB66A59515AC513C37865C3B8B1C18);
		il2cpp_codegen_memcpy(L_10, V_3, SizeOf_T1_t9561033C9FAB66A59515AC513C37865C3B8B1C18);
		il2cpp_codegen_memcpy(L_11, V_0, SizeOf_T2_t60A74597284FB13F39BBDE70DD68794BD9BAC16D);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_4, SizeOf_T3_t17D6D15FA58A3752AECA204EA2A27CF117C6BD27);
		il2cpp_codegen_memcpy(L_12, V_4, SizeOf_T3_t17D6D15FA58A3752AECA204EA2A27CF117C6BD27);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_5, SizeOf_T4_tA6EA1FDA558CFF527D8E1C6FD66E4BCF5A863863);
		il2cpp_codegen_memcpy(L_13, V_5, SizeOf_T4_tA6EA1FDA558CFF527D8E1C6FD66E4BCF5A863863);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_6, SizeOf_T5_tB849E0E76BE46D68793D81D57EA80E4C07ED9C11);
		il2cpp_codegen_memcpy(L_14, V_6, SizeOf_T5_tB849E0E76BE46D68793D81D57EA80E4C07ED9C11);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_7, SizeOf_T6_t2C03AD7AA0DA698E7086E9F7DC38F179995C5D0C);
		il2cpp_codegen_memcpy(L_15, V_7, SizeOf_T6_t2C03AD7AA0DA698E7086E9F7DC38F179995C5D0C);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_8, SizeOf_T7_t12AF7525E88D4361083E6F50DD71ECC32E6985A7);
		il2cpp_codegen_memcpy(L_16, V_8, SizeOf_T7_t12AF7525E88D4361083E6F50DD71ECC32E6985A7);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_9, SizeOf_T8_t2EB77468546390559127DE1F112A1E7F29F79F90);
		il2cpp_codegen_memcpy(L_17, V_9, SizeOf_T8_t2EB77468546390559127DE1F112A1E7F29F79F90);
		memset(L_20, 0, SizeOf_ValueTuple_2_tEFD44100BF6E84A07E01EE4796B1C6D5293D34EB);
		ValueTuple_2__ctor_mCAE8E725F680FA6BE2C23B9686C9F6056BB7E5CD((ValueTuple_2_tBAA1E1D7D97D80E0EBA7FE8773B1FF409AEA3829*)L_20, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 110)) ? il2cpp_codegen_memcpy(L_18, L_16, SizeOf_T7_t12AF7525E88D4361083E6F50DD71ECC32E6985A7): *(void**)L_16), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 111)) ? il2cpp_codegen_memcpy(L_19, L_17, SizeOf_T8_t2EB77468546390559127DE1F112A1E7F29F79F90): *(void**)L_17), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 113));
		memset(L_28, 0, SizeOf_ValueTuple_8_t5A4F9798F00844711054552CC2AA9D1C017B186C);
		ValueTuple_8__ctor_m03E5F35F1F6A37FA114EA2D38102DC71B063F122((ValueTuple_8_tD42E286CF79B463B55FD4A534F1A73E02CAEECC5*)L_28, 1, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 101)) ? il2cpp_codegen_memcpy(L_21, L_10, SizeOf_T1_t9561033C9FAB66A59515AC513C37865C3B8B1C18): *(void**)L_10), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 105)) ? il2cpp_codegen_memcpy(L_22, L_11, SizeOf_T2_t60A74597284FB13F39BBDE70DD68794BD9BAC16D): *(void**)L_11), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 106)) ? il2cpp_codegen_memcpy(L_23, L_12, SizeOf_T3_t17D6D15FA58A3752AECA204EA2A27CF117C6BD27): *(void**)L_12), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 107)) ? il2cpp_codegen_memcpy(L_24, L_13, SizeOf_T4_tA6EA1FDA558CFF527D8E1C6FD66E4BCF5A863863): *(void**)L_13), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 108)) ? il2cpp_codegen_memcpy(L_25, L_14, SizeOf_T5_tB849E0E76BE46D68793D81D57EA80E4C07ED9C11): *(void**)L_14), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 109)) ? il2cpp_codegen_memcpy(L_26, L_15, SizeOf_T6_t2C03AD7AA0DA698E7086E9F7DC38F179995C5D0C): *(void**)L_15), il2cpp_codegen_memcpy(L_27, L_20, SizeOf_ValueTuple_2_tEFD44100BF6E84A07E01EE4796B1C6D5293D34EB), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 115));
		bool L_29;
		L_29 = InvokerFuncInvoker1< bool, ValueTuple_8_tD42E286CF79B463B55FD4A534F1A73E02CAEECC5 >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 116)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 116), (((UniTaskCompletionSourceCore_1_tA9C7E3CB9001D1F438C1C3BBA224B20995E6A7A2*)il2cpp_codegen_get_instance_field_data_pointer(L_9, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),1)))), L_28);
	}

IL_008e:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhenAnyPromise_8_TryInvokeContinuationT3_m58445FFF0FC130E509D0E4E4A2B4E7EBF61F246B_gshared (WhenAnyPromise_8_tB1A18813B231826F7BEE92541715D6266929F072* ___0_self, Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* ___1_awaiter, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T3_t17D6D15FA58A3752AECA204EA2A27CF117C6BD27 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 106));
	const uint32_t SizeOf_T1_t9561033C9FAB66A59515AC513C37865C3B8B1C18 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 101));
	const uint32_t SizeOf_T2_t60A74597284FB13F39BBDE70DD68794BD9BAC16D = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 105));
	const uint32_t SizeOf_T4_tA6EA1FDA558CFF527D8E1C6FD66E4BCF5A863863 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 107));
	const uint32_t SizeOf_T5_tB849E0E76BE46D68793D81D57EA80E4C07ED9C11 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 108));
	const uint32_t SizeOf_T6_t2C03AD7AA0DA698E7086E9F7DC38F179995C5D0C = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 109));
	const uint32_t SizeOf_T7_t12AF7525E88D4361083E6F50DD71ECC32E6985A7 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 110));
	const uint32_t SizeOf_T8_t2EB77468546390559127DE1F112A1E7F29F79F90 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 111));
	const uint32_t SizeOf_ValueTuple_2_tEFD44100BF6E84A07E01EE4796B1C6D5293D34EB = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 112));
	const uint32_t SizeOf_ValueTuple_8_t5A4F9798F00844711054552CC2AA9D1C017B186C = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 114));
	const Il2CppFullySharedGenericAny L_10 = alloca(SizeOf_T1_t9561033C9FAB66A59515AC513C37865C3B8B1C18);
	const Il2CppFullySharedGenericAny L_21 = alloca(SizeOf_T1_t9561033C9FAB66A59515AC513C37865C3B8B1C18);
	const Il2CppFullySharedGenericAny L_11 = alloca(SizeOf_T2_t60A74597284FB13F39BBDE70DD68794BD9BAC16D);
	const Il2CppFullySharedGenericAny L_22 = alloca(SizeOf_T2_t60A74597284FB13F39BBDE70DD68794BD9BAC16D);
	const Il2CppFullySharedGenericAny L_1 = alloca(SizeOf_T3_t17D6D15FA58A3752AECA204EA2A27CF117C6BD27);
	const Il2CppFullySharedGenericAny L_12 = L_1;
	const Il2CppFullySharedGenericAny L_23 = alloca(SizeOf_T3_t17D6D15FA58A3752AECA204EA2A27CF117C6BD27);
	const Il2CppFullySharedGenericAny L_13 = alloca(SizeOf_T4_tA6EA1FDA558CFF527D8E1C6FD66E4BCF5A863863);
	const Il2CppFullySharedGenericAny L_24 = alloca(SizeOf_T4_tA6EA1FDA558CFF527D8E1C6FD66E4BCF5A863863);
	const Il2CppFullySharedGenericAny L_14 = alloca(SizeOf_T5_tB849E0E76BE46D68793D81D57EA80E4C07ED9C11);
	const Il2CppFullySharedGenericAny L_25 = alloca(SizeOf_T5_tB849E0E76BE46D68793D81D57EA80E4C07ED9C11);
	const Il2CppFullySharedGenericAny L_15 = alloca(SizeOf_T6_t2C03AD7AA0DA698E7086E9F7DC38F179995C5D0C);
	const Il2CppFullySharedGenericAny L_26 = alloca(SizeOf_T6_t2C03AD7AA0DA698E7086E9F7DC38F179995C5D0C);
	const Il2CppFullySharedGenericAny L_16 = alloca(SizeOf_T7_t12AF7525E88D4361083E6F50DD71ECC32E6985A7);
	const Il2CppFullySharedGenericAny L_18 = alloca(SizeOf_T7_t12AF7525E88D4361083E6F50DD71ECC32E6985A7);
	const Il2CppFullySharedGenericAny L_17 = alloca(SizeOf_T8_t2EB77468546390559127DE1F112A1E7F29F79F90);
	const Il2CppFullySharedGenericAny L_19 = alloca(SizeOf_T8_t2EB77468546390559127DE1F112A1E7F29F79F90);
	const ValueTuple_2_tBAA1E1D7D97D80E0EBA7FE8773B1FF409AEA3829 L_20 = alloca(SizeOf_ValueTuple_2_tEFD44100BF6E84A07E01EE4796B1C6D5293D34EB);
	const ValueTuple_2_tBAA1E1D7D97D80E0EBA7FE8773B1FF409AEA3829 L_27 = alloca(SizeOf_ValueTuple_2_tEFD44100BF6E84A07E01EE4796B1C6D5293D34EB);
	const ValueTuple_8_tD42E286CF79B463B55FD4A534F1A73E02CAEECC5 L_28 = alloca(SizeOf_ValueTuple_8_t5A4F9798F00844711054552CC2AA9D1C017B186C);
	Il2CppFullySharedGenericAny V_0 = alloca(SizeOf_T3_t17D6D15FA58A3752AECA204EA2A27CF117C6BD27);
	memset(V_0, 0, SizeOf_T3_t17D6D15FA58A3752AECA204EA2A27CF117C6BD27);
	Exception_t* V_1 = NULL;
	bool V_2 = false;
	Il2CppFullySharedGenericAny V_3 = alloca(SizeOf_T1_t9561033C9FAB66A59515AC513C37865C3B8B1C18);
	memset(V_3, 0, SizeOf_T1_t9561033C9FAB66A59515AC513C37865C3B8B1C18);
	Il2CppFullySharedGenericAny V_4 = alloca(SizeOf_T2_t60A74597284FB13F39BBDE70DD68794BD9BAC16D);
	memset(V_4, 0, SizeOf_T2_t60A74597284FB13F39BBDE70DD68794BD9BAC16D);
	Il2CppFullySharedGenericAny V_5 = alloca(SizeOf_T4_tA6EA1FDA558CFF527D8E1C6FD66E4BCF5A863863);
	memset(V_5, 0, SizeOf_T4_tA6EA1FDA558CFF527D8E1C6FD66E4BCF5A863863);
	Il2CppFullySharedGenericAny V_6 = alloca(SizeOf_T5_tB849E0E76BE46D68793D81D57EA80E4C07ED9C11);
	memset(V_6, 0, SizeOf_T5_tB849E0E76BE46D68793D81D57EA80E4C07ED9C11);
	Il2CppFullySharedGenericAny V_7 = alloca(SizeOf_T6_t2C03AD7AA0DA698E7086E9F7DC38F179995C5D0C);
	memset(V_7, 0, SizeOf_T6_t2C03AD7AA0DA698E7086E9F7DC38F179995C5D0C);
	Il2CppFullySharedGenericAny V_8 = alloca(SizeOf_T7_t12AF7525E88D4361083E6F50DD71ECC32E6985A7);
	memset(V_8, 0, SizeOf_T7_t12AF7525E88D4361083E6F50DD71ECC32E6985A7);
	Il2CppFullySharedGenericAny V_9 = alloca(SizeOf_T8_t2EB77468546390559127DE1F112A1E7F29F79F90);
	memset(V_9, 0, SizeOf_T8_t2EB77468546390559127DE1F112A1E7F29F79F90);
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
	}
	try
	{
		Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* L_0 = ___1_awaiter;
		InvokerActionInvoker1< Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 118)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 118), L_0, (Il2CppFullySharedGenericAny*)L_1);
		il2cpp_codegen_memcpy(V_0, L_1, SizeOf_T3_t17D6D15FA58A3752AECA204EA2A27CF117C6BD27);
		goto IL_001d;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&Exception_t_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_000c;
		}
		throw e;
	}

CATCH_000c:
	{
		Exception_t* L_2 = ((Exception_t*)IL2CPP_GET_ACTIVE_EXCEPTION(Exception_t*));;
		V_1 = L_2;
		WhenAnyPromise_8_tB1A18813B231826F7BEE92541715D6266929F072* L_3 = ___0_self;
		Exception_t* L_4 = V_1;
		bool L_5;
		L_5 = ((  bool (*) (UniTaskCompletionSourceCore_1_tA9C7E3CB9001D1F438C1C3BBA224B20995E6A7A2*, Exception_t*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 103)))((((UniTaskCompletionSourceCore_1_tA9C7E3CB9001D1F438C1C3BBA224B20995E6A7A2*)il2cpp_codegen_get_instance_field_data_pointer(L_3, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),1)))), L_4, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 103));
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_008e;
	}

IL_001d:
	{
		WhenAnyPromise_8_tB1A18813B231826F7BEE92541715D6266929F072* L_6 = ___0_self;
		int32_t L_7;
		L_7 = Interlocked_Increment_m3C240C32E8D9544EC050B74D4F28EEB58F1F9309((((int32_t*)il2cpp_codegen_get_instance_field_data_pointer(L_6, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),0)))), NULL);
		V_2 = (bool)((((int32_t)L_7) == ((int32_t)1))? 1 : 0);
		bool L_8 = V_2;
		if (!L_8)
		{
			goto IL_008e;
		}
	}
	{
		WhenAnyPromise_8_tB1A18813B231826F7BEE92541715D6266929F072* L_9 = ___0_self;
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_3, SizeOf_T1_t9561033C9FAB66A59515AC513C37865C3B8B1C18);
		il2cpp_codegen_memcpy(L_10, V_3, SizeOf_T1_t9561033C9FAB66A59515AC513C37865C3B8B1C18);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_4, SizeOf_T2_t60A74597284FB13F39BBDE70DD68794BD9BAC16D);
		il2cpp_codegen_memcpy(L_11, V_4, SizeOf_T2_t60A74597284FB13F39BBDE70DD68794BD9BAC16D);
		il2cpp_codegen_memcpy(L_12, V_0, SizeOf_T3_t17D6D15FA58A3752AECA204EA2A27CF117C6BD27);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_5, SizeOf_T4_tA6EA1FDA558CFF527D8E1C6FD66E4BCF5A863863);
		il2cpp_codegen_memcpy(L_13, V_5, SizeOf_T4_tA6EA1FDA558CFF527D8E1C6FD66E4BCF5A863863);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_6, SizeOf_T5_tB849E0E76BE46D68793D81D57EA80E4C07ED9C11);
		il2cpp_codegen_memcpy(L_14, V_6, SizeOf_T5_tB849E0E76BE46D68793D81D57EA80E4C07ED9C11);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_7, SizeOf_T6_t2C03AD7AA0DA698E7086E9F7DC38F179995C5D0C);
		il2cpp_codegen_memcpy(L_15, V_7, SizeOf_T6_t2C03AD7AA0DA698E7086E9F7DC38F179995C5D0C);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_8, SizeOf_T7_t12AF7525E88D4361083E6F50DD71ECC32E6985A7);
		il2cpp_codegen_memcpy(L_16, V_8, SizeOf_T7_t12AF7525E88D4361083E6F50DD71ECC32E6985A7);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_9, SizeOf_T8_t2EB77468546390559127DE1F112A1E7F29F79F90);
		il2cpp_codegen_memcpy(L_17, V_9, SizeOf_T8_t2EB77468546390559127DE1F112A1E7F29F79F90);
		memset(L_20, 0, SizeOf_ValueTuple_2_tEFD44100BF6E84A07E01EE4796B1C6D5293D34EB);
		ValueTuple_2__ctor_mCAE8E725F680FA6BE2C23B9686C9F6056BB7E5CD((ValueTuple_2_tBAA1E1D7D97D80E0EBA7FE8773B1FF409AEA3829*)L_20, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 110)) ? il2cpp_codegen_memcpy(L_18, L_16, SizeOf_T7_t12AF7525E88D4361083E6F50DD71ECC32E6985A7): *(void**)L_16), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 111)) ? il2cpp_codegen_memcpy(L_19, L_17, SizeOf_T8_t2EB77468546390559127DE1F112A1E7F29F79F90): *(void**)L_17), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 113));
		memset(L_28, 0, SizeOf_ValueTuple_8_t5A4F9798F00844711054552CC2AA9D1C017B186C);
		ValueTuple_8__ctor_m03E5F35F1F6A37FA114EA2D38102DC71B063F122((ValueTuple_8_tD42E286CF79B463B55FD4A534F1A73E02CAEECC5*)L_28, 2, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 101)) ? il2cpp_codegen_memcpy(L_21, L_10, SizeOf_T1_t9561033C9FAB66A59515AC513C37865C3B8B1C18): *(void**)L_10), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 105)) ? il2cpp_codegen_memcpy(L_22, L_11, SizeOf_T2_t60A74597284FB13F39BBDE70DD68794BD9BAC16D): *(void**)L_11), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 106)) ? il2cpp_codegen_memcpy(L_23, L_12, SizeOf_T3_t17D6D15FA58A3752AECA204EA2A27CF117C6BD27): *(void**)L_12), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 107)) ? il2cpp_codegen_memcpy(L_24, L_13, SizeOf_T4_tA6EA1FDA558CFF527D8E1C6FD66E4BCF5A863863): *(void**)L_13), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 108)) ? il2cpp_codegen_memcpy(L_25, L_14, SizeOf_T5_tB849E0E76BE46D68793D81D57EA80E4C07ED9C11): *(void**)L_14), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 109)) ? il2cpp_codegen_memcpy(L_26, L_15, SizeOf_T6_t2C03AD7AA0DA698E7086E9F7DC38F179995C5D0C): *(void**)L_15), il2cpp_codegen_memcpy(L_27, L_20, SizeOf_ValueTuple_2_tEFD44100BF6E84A07E01EE4796B1C6D5293D34EB), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 115));
		bool L_29;
		L_29 = InvokerFuncInvoker1< bool, ValueTuple_8_tD42E286CF79B463B55FD4A534F1A73E02CAEECC5 >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 116)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 116), (((UniTaskCompletionSourceCore_1_tA9C7E3CB9001D1F438C1C3BBA224B20995E6A7A2*)il2cpp_codegen_get_instance_field_data_pointer(L_9, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),1)))), L_28);
	}

IL_008e:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhenAnyPromise_8_TryInvokeContinuationT4_m302B67798FFEC117F70C31EE79F813136E78C99C_gshared (WhenAnyPromise_8_tB1A18813B231826F7BEE92541715D6266929F072* ___0_self, Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* ___1_awaiter, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T4_tA6EA1FDA558CFF527D8E1C6FD66E4BCF5A863863 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 107));
	const uint32_t SizeOf_T1_t9561033C9FAB66A59515AC513C37865C3B8B1C18 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 101));
	const uint32_t SizeOf_T2_t60A74597284FB13F39BBDE70DD68794BD9BAC16D = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 105));
	const uint32_t SizeOf_T3_t17D6D15FA58A3752AECA204EA2A27CF117C6BD27 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 106));
	const uint32_t SizeOf_T5_tB849E0E76BE46D68793D81D57EA80E4C07ED9C11 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 108));
	const uint32_t SizeOf_T6_t2C03AD7AA0DA698E7086E9F7DC38F179995C5D0C = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 109));
	const uint32_t SizeOf_T7_t12AF7525E88D4361083E6F50DD71ECC32E6985A7 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 110));
	const uint32_t SizeOf_T8_t2EB77468546390559127DE1F112A1E7F29F79F90 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 111));
	const uint32_t SizeOf_ValueTuple_2_tEFD44100BF6E84A07E01EE4796B1C6D5293D34EB = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 112));
	const uint32_t SizeOf_ValueTuple_8_t5A4F9798F00844711054552CC2AA9D1C017B186C = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 114));
	const Il2CppFullySharedGenericAny L_10 = alloca(SizeOf_T1_t9561033C9FAB66A59515AC513C37865C3B8B1C18);
	const Il2CppFullySharedGenericAny L_21 = alloca(SizeOf_T1_t9561033C9FAB66A59515AC513C37865C3B8B1C18);
	const Il2CppFullySharedGenericAny L_11 = alloca(SizeOf_T2_t60A74597284FB13F39BBDE70DD68794BD9BAC16D);
	const Il2CppFullySharedGenericAny L_22 = alloca(SizeOf_T2_t60A74597284FB13F39BBDE70DD68794BD9BAC16D);
	const Il2CppFullySharedGenericAny L_12 = alloca(SizeOf_T3_t17D6D15FA58A3752AECA204EA2A27CF117C6BD27);
	const Il2CppFullySharedGenericAny L_23 = alloca(SizeOf_T3_t17D6D15FA58A3752AECA204EA2A27CF117C6BD27);
	const Il2CppFullySharedGenericAny L_1 = alloca(SizeOf_T4_tA6EA1FDA558CFF527D8E1C6FD66E4BCF5A863863);
	const Il2CppFullySharedGenericAny L_13 = L_1;
	const Il2CppFullySharedGenericAny L_24 = alloca(SizeOf_T4_tA6EA1FDA558CFF527D8E1C6FD66E4BCF5A863863);
	const Il2CppFullySharedGenericAny L_14 = alloca(SizeOf_T5_tB849E0E76BE46D68793D81D57EA80E4C07ED9C11);
	const Il2CppFullySharedGenericAny L_25 = alloca(SizeOf_T5_tB849E0E76BE46D68793D81D57EA80E4C07ED9C11);
	const Il2CppFullySharedGenericAny L_15 = alloca(SizeOf_T6_t2C03AD7AA0DA698E7086E9F7DC38F179995C5D0C);
	const Il2CppFullySharedGenericAny L_26 = alloca(SizeOf_T6_t2C03AD7AA0DA698E7086E9F7DC38F179995C5D0C);
	const Il2CppFullySharedGenericAny L_16 = alloca(SizeOf_T7_t12AF7525E88D4361083E6F50DD71ECC32E6985A7);
	const Il2CppFullySharedGenericAny L_18 = alloca(SizeOf_T7_t12AF7525E88D4361083E6F50DD71ECC32E6985A7);
	const Il2CppFullySharedGenericAny L_17 = alloca(SizeOf_T8_t2EB77468546390559127DE1F112A1E7F29F79F90);
	const Il2CppFullySharedGenericAny L_19 = alloca(SizeOf_T8_t2EB77468546390559127DE1F112A1E7F29F79F90);
	const ValueTuple_2_tBAA1E1D7D97D80E0EBA7FE8773B1FF409AEA3829 L_20 = alloca(SizeOf_ValueTuple_2_tEFD44100BF6E84A07E01EE4796B1C6D5293D34EB);
	const ValueTuple_2_tBAA1E1D7D97D80E0EBA7FE8773B1FF409AEA3829 L_27 = alloca(SizeOf_ValueTuple_2_tEFD44100BF6E84A07E01EE4796B1C6D5293D34EB);
	const ValueTuple_8_tD42E286CF79B463B55FD4A534F1A73E02CAEECC5 L_28 = alloca(SizeOf_ValueTuple_8_t5A4F9798F00844711054552CC2AA9D1C017B186C);
	Il2CppFullySharedGenericAny V_0 = alloca(SizeOf_T4_tA6EA1FDA558CFF527D8E1C6FD66E4BCF5A863863);
	memset(V_0, 0, SizeOf_T4_tA6EA1FDA558CFF527D8E1C6FD66E4BCF5A863863);
	Exception_t* V_1 = NULL;
	bool V_2 = false;
	Il2CppFullySharedGenericAny V_3 = alloca(SizeOf_T1_t9561033C9FAB66A59515AC513C37865C3B8B1C18);
	memset(V_3, 0, SizeOf_T1_t9561033C9FAB66A59515AC513C37865C3B8B1C18);
	Il2CppFullySharedGenericAny V_4 = alloca(SizeOf_T2_t60A74597284FB13F39BBDE70DD68794BD9BAC16D);
	memset(V_4, 0, SizeOf_T2_t60A74597284FB13F39BBDE70DD68794BD9BAC16D);
	Il2CppFullySharedGenericAny V_5 = alloca(SizeOf_T3_t17D6D15FA58A3752AECA204EA2A27CF117C6BD27);
	memset(V_5, 0, SizeOf_T3_t17D6D15FA58A3752AECA204EA2A27CF117C6BD27);
	Il2CppFullySharedGenericAny V_6 = alloca(SizeOf_T5_tB849E0E76BE46D68793D81D57EA80E4C07ED9C11);
	memset(V_6, 0, SizeOf_T5_tB849E0E76BE46D68793D81D57EA80E4C07ED9C11);
	Il2CppFullySharedGenericAny V_7 = alloca(SizeOf_T6_t2C03AD7AA0DA698E7086E9F7DC38F179995C5D0C);
	memset(V_7, 0, SizeOf_T6_t2C03AD7AA0DA698E7086E9F7DC38F179995C5D0C);
	Il2CppFullySharedGenericAny V_8 = alloca(SizeOf_T7_t12AF7525E88D4361083E6F50DD71ECC32E6985A7);
	memset(V_8, 0, SizeOf_T7_t12AF7525E88D4361083E6F50DD71ECC32E6985A7);
	Il2CppFullySharedGenericAny V_9 = alloca(SizeOf_T8_t2EB77468546390559127DE1F112A1E7F29F79F90);
	memset(V_9, 0, SizeOf_T8_t2EB77468546390559127DE1F112A1E7F29F79F90);
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
	}
	try
	{
		Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* L_0 = ___1_awaiter;
		InvokerActionInvoker1< Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 119)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 119), L_0, (Il2CppFullySharedGenericAny*)L_1);
		il2cpp_codegen_memcpy(V_0, L_1, SizeOf_T4_tA6EA1FDA558CFF527D8E1C6FD66E4BCF5A863863);
		goto IL_001d;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&Exception_t_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_000c;
		}
		throw e;
	}

CATCH_000c:
	{
		Exception_t* L_2 = ((Exception_t*)IL2CPP_GET_ACTIVE_EXCEPTION(Exception_t*));;
		V_1 = L_2;
		WhenAnyPromise_8_tB1A18813B231826F7BEE92541715D6266929F072* L_3 = ___0_self;
		Exception_t* L_4 = V_1;
		bool L_5;
		L_5 = ((  bool (*) (UniTaskCompletionSourceCore_1_tA9C7E3CB9001D1F438C1C3BBA224B20995E6A7A2*, Exception_t*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 103)))((((UniTaskCompletionSourceCore_1_tA9C7E3CB9001D1F438C1C3BBA224B20995E6A7A2*)il2cpp_codegen_get_instance_field_data_pointer(L_3, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),1)))), L_4, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 103));
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_008e;
	}

IL_001d:
	{
		WhenAnyPromise_8_tB1A18813B231826F7BEE92541715D6266929F072* L_6 = ___0_self;
		int32_t L_7;
		L_7 = Interlocked_Increment_m3C240C32E8D9544EC050B74D4F28EEB58F1F9309((((int32_t*)il2cpp_codegen_get_instance_field_data_pointer(L_6, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),0)))), NULL);
		V_2 = (bool)((((int32_t)L_7) == ((int32_t)1))? 1 : 0);
		bool L_8 = V_2;
		if (!L_8)
		{
			goto IL_008e;
		}
	}
	{
		WhenAnyPromise_8_tB1A18813B231826F7BEE92541715D6266929F072* L_9 = ___0_self;
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_3, SizeOf_T1_t9561033C9FAB66A59515AC513C37865C3B8B1C18);
		il2cpp_codegen_memcpy(L_10, V_3, SizeOf_T1_t9561033C9FAB66A59515AC513C37865C3B8B1C18);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_4, SizeOf_T2_t60A74597284FB13F39BBDE70DD68794BD9BAC16D);
		il2cpp_codegen_memcpy(L_11, V_4, SizeOf_T2_t60A74597284FB13F39BBDE70DD68794BD9BAC16D);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_5, SizeOf_T3_t17D6D15FA58A3752AECA204EA2A27CF117C6BD27);
		il2cpp_codegen_memcpy(L_12, V_5, SizeOf_T3_t17D6D15FA58A3752AECA204EA2A27CF117C6BD27);
		il2cpp_codegen_memcpy(L_13, V_0, SizeOf_T4_tA6EA1FDA558CFF527D8E1C6FD66E4BCF5A863863);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_6, SizeOf_T5_tB849E0E76BE46D68793D81D57EA80E4C07ED9C11);
		il2cpp_codegen_memcpy(L_14, V_6, SizeOf_T5_tB849E0E76BE46D68793D81D57EA80E4C07ED9C11);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_7, SizeOf_T6_t2C03AD7AA0DA698E7086E9F7DC38F179995C5D0C);
		il2cpp_codegen_memcpy(L_15, V_7, SizeOf_T6_t2C03AD7AA0DA698E7086E9F7DC38F179995C5D0C);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_8, SizeOf_T7_t12AF7525E88D4361083E6F50DD71ECC32E6985A7);
		il2cpp_codegen_memcpy(L_16, V_8, SizeOf_T7_t12AF7525E88D4361083E6F50DD71ECC32E6985A7);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_9, SizeOf_T8_t2EB77468546390559127DE1F112A1E7F29F79F90);
		il2cpp_codegen_memcpy(L_17, V_9, SizeOf_T8_t2EB77468546390559127DE1F112A1E7F29F79F90);
		memset(L_20, 0, SizeOf_ValueTuple_2_tEFD44100BF6E84A07E01EE4796B1C6D5293D34EB);
		ValueTuple_2__ctor_mCAE8E725F680FA6BE2C23B9686C9F6056BB7E5CD((ValueTuple_2_tBAA1E1D7D97D80E0EBA7FE8773B1FF409AEA3829*)L_20, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 110)) ? il2cpp_codegen_memcpy(L_18, L_16, SizeOf_T7_t12AF7525E88D4361083E6F50DD71ECC32E6985A7): *(void**)L_16), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 111)) ? il2cpp_codegen_memcpy(L_19, L_17, SizeOf_T8_t2EB77468546390559127DE1F112A1E7F29F79F90): *(void**)L_17), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 113));
		memset(L_28, 0, SizeOf_ValueTuple_8_t5A4F9798F00844711054552CC2AA9D1C017B186C);
		ValueTuple_8__ctor_m03E5F35F1F6A37FA114EA2D38102DC71B063F122((ValueTuple_8_tD42E286CF79B463B55FD4A534F1A73E02CAEECC5*)L_28, 3, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 101)) ? il2cpp_codegen_memcpy(L_21, L_10, SizeOf_T1_t9561033C9FAB66A59515AC513C37865C3B8B1C18): *(void**)L_10), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 105)) ? il2cpp_codegen_memcpy(L_22, L_11, SizeOf_T2_t60A74597284FB13F39BBDE70DD68794BD9BAC16D): *(void**)L_11), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 106)) ? il2cpp_codegen_memcpy(L_23, L_12, SizeOf_T3_t17D6D15FA58A3752AECA204EA2A27CF117C6BD27): *(void**)L_12), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 107)) ? il2cpp_codegen_memcpy(L_24, L_13, SizeOf_T4_tA6EA1FDA558CFF527D8E1C6FD66E4BCF5A863863): *(void**)L_13), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 108)) ? il2cpp_codegen_memcpy(L_25, L_14, SizeOf_T5_tB849E0E76BE46D68793D81D57EA80E4C07ED9C11): *(void**)L_14), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 109)) ? il2cpp_codegen_memcpy(L_26, L_15, SizeOf_T6_t2C03AD7AA0DA698E7086E9F7DC38F179995C5D0C): *(void**)L_15), il2cpp_codegen_memcpy(L_27, L_20, SizeOf_ValueTuple_2_tEFD44100BF6E84A07E01EE4796B1C6D5293D34EB), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 115));
		bool L_29;
		L_29 = InvokerFuncInvoker1< bool, ValueTuple_8_tD42E286CF79B463B55FD4A534F1A73E02CAEECC5 >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 116)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 116), (((UniTaskCompletionSourceCore_1_tA9C7E3CB9001D1F438C1C3BBA224B20995E6A7A2*)il2cpp_codegen_get_instance_field_data_pointer(L_9, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),1)))), L_28);
	}

IL_008e:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhenAnyPromise_8_TryInvokeContinuationT5_m669FA2A85F02AB504E6D21EAF27D70C352DD4FD9_gshared (WhenAnyPromise_8_tB1A18813B231826F7BEE92541715D6266929F072* ___0_self, Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* ___1_awaiter, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T5_tB849E0E76BE46D68793D81D57EA80E4C07ED9C11 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 108));
	const uint32_t SizeOf_T1_t9561033C9FAB66A59515AC513C37865C3B8B1C18 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 101));
	const uint32_t SizeOf_T2_t60A74597284FB13F39BBDE70DD68794BD9BAC16D = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 105));
	const uint32_t SizeOf_T3_t17D6D15FA58A3752AECA204EA2A27CF117C6BD27 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 106));
	const uint32_t SizeOf_T4_tA6EA1FDA558CFF527D8E1C6FD66E4BCF5A863863 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 107));
	const uint32_t SizeOf_T6_t2C03AD7AA0DA698E7086E9F7DC38F179995C5D0C = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 109));
	const uint32_t SizeOf_T7_t12AF7525E88D4361083E6F50DD71ECC32E6985A7 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 110));
	const uint32_t SizeOf_T8_t2EB77468546390559127DE1F112A1E7F29F79F90 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 111));
	const uint32_t SizeOf_ValueTuple_2_tEFD44100BF6E84A07E01EE4796B1C6D5293D34EB = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 112));
	const uint32_t SizeOf_ValueTuple_8_t5A4F9798F00844711054552CC2AA9D1C017B186C = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 114));
	const Il2CppFullySharedGenericAny L_10 = alloca(SizeOf_T1_t9561033C9FAB66A59515AC513C37865C3B8B1C18);
	const Il2CppFullySharedGenericAny L_21 = alloca(SizeOf_T1_t9561033C9FAB66A59515AC513C37865C3B8B1C18);
	const Il2CppFullySharedGenericAny L_11 = alloca(SizeOf_T2_t60A74597284FB13F39BBDE70DD68794BD9BAC16D);
	const Il2CppFullySharedGenericAny L_22 = alloca(SizeOf_T2_t60A74597284FB13F39BBDE70DD68794BD9BAC16D);
	const Il2CppFullySharedGenericAny L_12 = alloca(SizeOf_T3_t17D6D15FA58A3752AECA204EA2A27CF117C6BD27);
	const Il2CppFullySharedGenericAny L_23 = alloca(SizeOf_T3_t17D6D15FA58A3752AECA204EA2A27CF117C6BD27);
	const Il2CppFullySharedGenericAny L_13 = alloca(SizeOf_T4_tA6EA1FDA558CFF527D8E1C6FD66E4BCF5A863863);
	const Il2CppFullySharedGenericAny L_24 = alloca(SizeOf_T4_tA6EA1FDA558CFF527D8E1C6FD66E4BCF5A863863);
	const Il2CppFullySharedGenericAny L_1 = alloca(SizeOf_T5_tB849E0E76BE46D68793D81D57EA80E4C07ED9C11);
	const Il2CppFullySharedGenericAny L_14 = L_1;
	const Il2CppFullySharedGenericAny L_25 = alloca(SizeOf_T5_tB849E0E76BE46D68793D81D57EA80E4C07ED9C11);
	const Il2CppFullySharedGenericAny L_15 = alloca(SizeOf_T6_t2C03AD7AA0DA698E7086E9F7DC38F179995C5D0C);
	const Il2CppFullySharedGenericAny L_26 = alloca(SizeOf_T6_t2C03AD7AA0DA698E7086E9F7DC38F179995C5D0C);
	const Il2CppFullySharedGenericAny L_16 = alloca(SizeOf_T7_t12AF7525E88D4361083E6F50DD71ECC32E6985A7);
	const Il2CppFullySharedGenericAny L_18 = alloca(SizeOf_T7_t12AF7525E88D4361083E6F50DD71ECC32E6985A7);
	const Il2CppFullySharedGenericAny L_17 = alloca(SizeOf_T8_t2EB77468546390559127DE1F112A1E7F29F79F90);
	const Il2CppFullySharedGenericAny L_19 = alloca(SizeOf_T8_t2EB77468546390559127DE1F112A1E7F29F79F90);
	const ValueTuple_2_tBAA1E1D7D97D80E0EBA7FE8773B1FF409AEA3829 L_20 = alloca(SizeOf_ValueTuple_2_tEFD44100BF6E84A07E01EE4796B1C6D5293D34EB);
	const ValueTuple_2_tBAA1E1D7D97D80E0EBA7FE8773B1FF409AEA3829 L_27 = alloca(SizeOf_ValueTuple_2_tEFD44100BF6E84A07E01EE4796B1C6D5293D34EB);
	const ValueTuple_8_tD42E286CF79B463B55FD4A534F1A73E02CAEECC5 L_28 = alloca(SizeOf_ValueTuple_8_t5A4F9798F00844711054552CC2AA9D1C017B186C);
	Il2CppFullySharedGenericAny V_0 = alloca(SizeOf_T5_tB849E0E76BE46D68793D81D57EA80E4C07ED9C11);
	memset(V_0, 0, SizeOf_T5_tB849E0E76BE46D68793D81D57EA80E4C07ED9C11);
	Exception_t* V_1 = NULL;
	bool V_2 = false;
	Il2CppFullySharedGenericAny V_3 = alloca(SizeOf_T1_t9561033C9FAB66A59515AC513C37865C3B8B1C18);
	memset(V_3, 0, SizeOf_T1_t9561033C9FAB66A59515AC513C37865C3B8B1C18);
	Il2CppFullySharedGenericAny V_4 = alloca(SizeOf_T2_t60A74597284FB13F39BBDE70DD68794BD9BAC16D);
	memset(V_4, 0, SizeOf_T2_t60A74597284FB13F39BBDE70DD68794BD9BAC16D);
	Il2CppFullySharedGenericAny V_5 = alloca(SizeOf_T3_t17D6D15FA58A3752AECA204EA2A27CF117C6BD27);
	memset(V_5, 0, SizeOf_T3_t17D6D15FA58A3752AECA204EA2A27CF117C6BD27);
	Il2CppFullySharedGenericAny V_6 = alloca(SizeOf_T4_tA6EA1FDA558CFF527D8E1C6FD66E4BCF5A863863);
	memset(V_6, 0, SizeOf_T4_tA6EA1FDA558CFF527D8E1C6FD66E4BCF5A863863);
	Il2CppFullySharedGenericAny V_7 = alloca(SizeOf_T6_t2C03AD7AA0DA698E7086E9F7DC38F179995C5D0C);
	memset(V_7, 0, SizeOf_T6_t2C03AD7AA0DA698E7086E9F7DC38F179995C5D0C);
	Il2CppFullySharedGenericAny V_8 = alloca(SizeOf_T7_t12AF7525E88D4361083E6F50DD71ECC32E6985A7);
	memset(V_8, 0, SizeOf_T7_t12AF7525E88D4361083E6F50DD71ECC32E6985A7);
	Il2CppFullySharedGenericAny V_9 = alloca(SizeOf_T8_t2EB77468546390559127DE1F112A1E7F29F79F90);
	memset(V_9, 0, SizeOf_T8_t2EB77468546390559127DE1F112A1E7F29F79F90);
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
	}
	try
	{
		Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* L_0 = ___1_awaiter;
		InvokerActionInvoker1< Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 120)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 120), L_0, (Il2CppFullySharedGenericAny*)L_1);
		il2cpp_codegen_memcpy(V_0, L_1, SizeOf_T5_tB849E0E76BE46D68793D81D57EA80E4C07ED9C11);
		goto IL_001d;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&Exception_t_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_000c;
		}
		throw e;
	}

CATCH_000c:
	{
		Exception_t* L_2 = ((Exception_t*)IL2CPP_GET_ACTIVE_EXCEPTION(Exception_t*));;
		V_1 = L_2;
		WhenAnyPromise_8_tB1A18813B231826F7BEE92541715D6266929F072* L_3 = ___0_self;
		Exception_t* L_4 = V_1;
		bool L_5;
		L_5 = ((  bool (*) (UniTaskCompletionSourceCore_1_tA9C7E3CB9001D1F438C1C3BBA224B20995E6A7A2*, Exception_t*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 103)))((((UniTaskCompletionSourceCore_1_tA9C7E3CB9001D1F438C1C3BBA224B20995E6A7A2*)il2cpp_codegen_get_instance_field_data_pointer(L_3, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),1)))), L_4, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 103));
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_008e;
	}

IL_001d:
	{
		WhenAnyPromise_8_tB1A18813B231826F7BEE92541715D6266929F072* L_6 = ___0_self;
		int32_t L_7;
		L_7 = Interlocked_Increment_m3C240C32E8D9544EC050B74D4F28EEB58F1F9309((((int32_t*)il2cpp_codegen_get_instance_field_data_pointer(L_6, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),0)))), NULL);
		V_2 = (bool)((((int32_t)L_7) == ((int32_t)1))? 1 : 0);
		bool L_8 = V_2;
		if (!L_8)
		{
			goto IL_008e;
		}
	}
	{
		WhenAnyPromise_8_tB1A18813B231826F7BEE92541715D6266929F072* L_9 = ___0_self;
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_3, SizeOf_T1_t9561033C9FAB66A59515AC513C37865C3B8B1C18);
		il2cpp_codegen_memcpy(L_10, V_3, SizeOf_T1_t9561033C9FAB66A59515AC513C37865C3B8B1C18);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_4, SizeOf_T2_t60A74597284FB13F39BBDE70DD68794BD9BAC16D);
		il2cpp_codegen_memcpy(L_11, V_4, SizeOf_T2_t60A74597284FB13F39BBDE70DD68794BD9BAC16D);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_5, SizeOf_T3_t17D6D15FA58A3752AECA204EA2A27CF117C6BD27);
		il2cpp_codegen_memcpy(L_12, V_5, SizeOf_T3_t17D6D15FA58A3752AECA204EA2A27CF117C6BD27);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_6, SizeOf_T4_tA6EA1FDA558CFF527D8E1C6FD66E4BCF5A863863);
		il2cpp_codegen_memcpy(L_13, V_6, SizeOf_T4_tA6EA1FDA558CFF527D8E1C6FD66E4BCF5A863863);
		il2cpp_codegen_memcpy(L_14, V_0, SizeOf_T5_tB849E0E76BE46D68793D81D57EA80E4C07ED9C11);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_7, SizeOf_T6_t2C03AD7AA0DA698E7086E9F7DC38F179995C5D0C);
		il2cpp_codegen_memcpy(L_15, V_7, SizeOf_T6_t2C03AD7AA0DA698E7086E9F7DC38F179995C5D0C);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_8, SizeOf_T7_t12AF7525E88D4361083E6F50DD71ECC32E6985A7);
		il2cpp_codegen_memcpy(L_16, V_8, SizeOf_T7_t12AF7525E88D4361083E6F50DD71ECC32E6985A7);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_9, SizeOf_T8_t2EB77468546390559127DE1F112A1E7F29F79F90);
		il2cpp_codegen_memcpy(L_17, V_9, SizeOf_T8_t2EB77468546390559127DE1F112A1E7F29F79F90);
		memset(L_20, 0, SizeOf_ValueTuple_2_tEFD44100BF6E84A07E01EE4796B1C6D5293D34EB);
		ValueTuple_2__ctor_mCAE8E725F680FA6BE2C23B9686C9F6056BB7E5CD((ValueTuple_2_tBAA1E1D7D97D80E0EBA7FE8773B1FF409AEA3829*)L_20, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 110)) ? il2cpp_codegen_memcpy(L_18, L_16, SizeOf_T7_t12AF7525E88D4361083E6F50DD71ECC32E6985A7): *(void**)L_16), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 111)) ? il2cpp_codegen_memcpy(L_19, L_17, SizeOf_T8_t2EB77468546390559127DE1F112A1E7F29F79F90): *(void**)L_17), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 113));
		memset(L_28, 0, SizeOf_ValueTuple_8_t5A4F9798F00844711054552CC2AA9D1C017B186C);
		ValueTuple_8__ctor_m03E5F35F1F6A37FA114EA2D38102DC71B063F122((ValueTuple_8_tD42E286CF79B463B55FD4A534F1A73E02CAEECC5*)L_28, 4, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 101)) ? il2cpp_codegen_memcpy(L_21, L_10, SizeOf_T1_t9561033C9FAB66A59515AC513C37865C3B8B1C18): *(void**)L_10), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 105)) ? il2cpp_codegen_memcpy(L_22, L_11, SizeOf_T2_t60A74597284FB13F39BBDE70DD68794BD9BAC16D): *(void**)L_11), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 106)) ? il2cpp_codegen_memcpy(L_23, L_12, SizeOf_T3_t17D6D15FA58A3752AECA204EA2A27CF117C6BD27): *(void**)L_12), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 107)) ? il2cpp_codegen_memcpy(L_24, L_13, SizeOf_T4_tA6EA1FDA558CFF527D8E1C6FD66E4BCF5A863863): *(void**)L_13), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 108)) ? il2cpp_codegen_memcpy(L_25, L_14, SizeOf_T5_tB849E0E76BE46D68793D81D57EA80E4C07ED9C11): *(void**)L_14), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 109)) ? il2cpp_codegen_memcpy(L_26, L_15, SizeOf_T6_t2C03AD7AA0DA698E7086E9F7DC38F179995C5D0C): *(void**)L_15), il2cpp_codegen_memcpy(L_27, L_20, SizeOf_ValueTuple_2_tEFD44100BF6E84A07E01EE4796B1C6D5293D34EB), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 115));
		bool L_29;
		L_29 = InvokerFuncInvoker1< bool, ValueTuple_8_tD42E286CF79B463B55FD4A534F1A73E02CAEECC5 >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 116)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 116), (((UniTaskCompletionSourceCore_1_tA9C7E3CB9001D1F438C1C3BBA224B20995E6A7A2*)il2cpp_codegen_get_instance_field_data_pointer(L_9, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),1)))), L_28);
	}

IL_008e:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhenAnyPromise_8_TryInvokeContinuationT6_m28050B75E4A0BAC5853C6222D8BFAD446B4BD4E6_gshared (WhenAnyPromise_8_tB1A18813B231826F7BEE92541715D6266929F072* ___0_self, Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* ___1_awaiter, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T6_t2C03AD7AA0DA698E7086E9F7DC38F179995C5D0C = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 109));
	const uint32_t SizeOf_T1_t9561033C9FAB66A59515AC513C37865C3B8B1C18 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 101));
	const uint32_t SizeOf_T2_t60A74597284FB13F39BBDE70DD68794BD9BAC16D = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 105));
	const uint32_t SizeOf_T3_t17D6D15FA58A3752AECA204EA2A27CF117C6BD27 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 106));
	const uint32_t SizeOf_T4_tA6EA1FDA558CFF527D8E1C6FD66E4BCF5A863863 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 107));
	const uint32_t SizeOf_T5_tB849E0E76BE46D68793D81D57EA80E4C07ED9C11 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 108));
	const uint32_t SizeOf_T7_t12AF7525E88D4361083E6F50DD71ECC32E6985A7 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 110));
	const uint32_t SizeOf_T8_t2EB77468546390559127DE1F112A1E7F29F79F90 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 111));
	const uint32_t SizeOf_ValueTuple_2_tEFD44100BF6E84A07E01EE4796B1C6D5293D34EB = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 112));
	const uint32_t SizeOf_ValueTuple_8_t5A4F9798F00844711054552CC2AA9D1C017B186C = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 114));
	const Il2CppFullySharedGenericAny L_10 = alloca(SizeOf_T1_t9561033C9FAB66A59515AC513C37865C3B8B1C18);
	const Il2CppFullySharedGenericAny L_21 = alloca(SizeOf_T1_t9561033C9FAB66A59515AC513C37865C3B8B1C18);
	const Il2CppFullySharedGenericAny L_11 = alloca(SizeOf_T2_t60A74597284FB13F39BBDE70DD68794BD9BAC16D);
	const Il2CppFullySharedGenericAny L_22 = alloca(SizeOf_T2_t60A74597284FB13F39BBDE70DD68794BD9BAC16D);
	const Il2CppFullySharedGenericAny L_12 = alloca(SizeOf_T3_t17D6D15FA58A3752AECA204EA2A27CF117C6BD27);
	const Il2CppFullySharedGenericAny L_23 = alloca(SizeOf_T3_t17D6D15FA58A3752AECA204EA2A27CF117C6BD27);
	const Il2CppFullySharedGenericAny L_13 = alloca(SizeOf_T4_tA6EA1FDA558CFF527D8E1C6FD66E4BCF5A863863);
	const Il2CppFullySharedGenericAny L_24 = alloca(SizeOf_T4_tA6EA1FDA558CFF527D8E1C6FD66E4BCF5A863863);
	const Il2CppFullySharedGenericAny L_14 = alloca(SizeOf_T5_tB849E0E76BE46D68793D81D57EA80E4C07ED9C11);
	const Il2CppFullySharedGenericAny L_25 = alloca(SizeOf_T5_tB849E0E76BE46D68793D81D57EA80E4C07ED9C11);
	const Il2CppFullySharedGenericAny L_1 = alloca(SizeOf_T6_t2C03AD7AA0DA698E7086E9F7DC38F179995C5D0C);
	const Il2CppFullySharedGenericAny L_15 = L_1;
	const Il2CppFullySharedGenericAny L_26 = alloca(SizeOf_T6_t2C03AD7AA0DA698E7086E9F7DC38F179995C5D0C);
	const Il2CppFullySharedGenericAny L_16 = alloca(SizeOf_T7_t12AF7525E88D4361083E6F50DD71ECC32E6985A7);
	const Il2CppFullySharedGenericAny L_18 = alloca(SizeOf_T7_t12AF7525E88D4361083E6F50DD71ECC32E6985A7);
	const Il2CppFullySharedGenericAny L_17 = alloca(SizeOf_T8_t2EB77468546390559127DE1F112A1E7F29F79F90);
	const Il2CppFullySharedGenericAny L_19 = alloca(SizeOf_T8_t2EB77468546390559127DE1F112A1E7F29F79F90);
	const ValueTuple_2_tBAA1E1D7D97D80E0EBA7FE8773B1FF409AEA3829 L_20 = alloca(SizeOf_ValueTuple_2_tEFD44100BF6E84A07E01EE4796B1C6D5293D34EB);
	const ValueTuple_2_tBAA1E1D7D97D80E0EBA7FE8773B1FF409AEA3829 L_27 = alloca(SizeOf_ValueTuple_2_tEFD44100BF6E84A07E01EE4796B1C6D5293D34EB);
	const ValueTuple_8_tD42E286CF79B463B55FD4A534F1A73E02CAEECC5 L_28 = alloca(SizeOf_ValueTuple_8_t5A4F9798F00844711054552CC2AA9D1C017B186C);
	Il2CppFullySharedGenericAny V_0 = alloca(SizeOf_T6_t2C03AD7AA0DA698E7086E9F7DC38F179995C5D0C);
	memset(V_0, 0, SizeOf_T6_t2C03AD7AA0DA698E7086E9F7DC38F179995C5D0C);
	Exception_t* V_1 = NULL;
	bool V_2 = false;
	Il2CppFullySharedGenericAny V_3 = alloca(SizeOf_T1_t9561033C9FAB66A59515AC513C37865C3B8B1C18);
	memset(V_3, 0, SizeOf_T1_t9561033C9FAB66A59515AC513C37865C3B8B1C18);
	Il2CppFullySharedGenericAny V_4 = alloca(SizeOf_T2_t60A74597284FB13F39BBDE70DD68794BD9BAC16D);
	memset(V_4, 0, SizeOf_T2_t60A74597284FB13F39BBDE70DD68794BD9BAC16D);
	Il2CppFullySharedGenericAny V_5 = alloca(SizeOf_T3_t17D6D15FA58A3752AECA204EA2A27CF117C6BD27);
	memset(V_5, 0, SizeOf_T3_t17D6D15FA58A3752AECA204EA2A27CF117C6BD27);
	Il2CppFullySharedGenericAny V_6 = alloca(SizeOf_T4_tA6EA1FDA558CFF527D8E1C6FD66E4BCF5A863863);
	memset(V_6, 0, SizeOf_T4_tA6EA1FDA558CFF527D8E1C6FD66E4BCF5A863863);
	Il2CppFullySharedGenericAny V_7 = alloca(SizeOf_T5_tB849E0E76BE46D68793D81D57EA80E4C07ED9C11);
	memset(V_7, 0, SizeOf_T5_tB849E0E76BE46D68793D81D57EA80E4C07ED9C11);
	Il2CppFullySharedGenericAny V_8 = alloca(SizeOf_T7_t12AF7525E88D4361083E6F50DD71ECC32E6985A7);
	memset(V_8, 0, SizeOf_T7_t12AF7525E88D4361083E6F50DD71ECC32E6985A7);
	Il2CppFullySharedGenericAny V_9 = alloca(SizeOf_T8_t2EB77468546390559127DE1F112A1E7F29F79F90);
	memset(V_9, 0, SizeOf_T8_t2EB77468546390559127DE1F112A1E7F29F79F90);
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
	}
	try
	{
		Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* L_0 = ___1_awaiter;
		InvokerActionInvoker1< Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 121)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 121), L_0, (Il2CppFullySharedGenericAny*)L_1);
		il2cpp_codegen_memcpy(V_0, L_1, SizeOf_T6_t2C03AD7AA0DA698E7086E9F7DC38F179995C5D0C);
		goto IL_001d;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&Exception_t_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_000c;
		}
		throw e;
	}

CATCH_000c:
	{
		Exception_t* L_2 = ((Exception_t*)IL2CPP_GET_ACTIVE_EXCEPTION(Exception_t*));;
		V_1 = L_2;
		WhenAnyPromise_8_tB1A18813B231826F7BEE92541715D6266929F072* L_3 = ___0_self;
		Exception_t* L_4 = V_1;
		bool L_5;
		L_5 = ((  bool (*) (UniTaskCompletionSourceCore_1_tA9C7E3CB9001D1F438C1C3BBA224B20995E6A7A2*, Exception_t*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 103)))((((UniTaskCompletionSourceCore_1_tA9C7E3CB9001D1F438C1C3BBA224B20995E6A7A2*)il2cpp_codegen_get_instance_field_data_pointer(L_3, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),1)))), L_4, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 103));
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_008e;
	}

IL_001d:
	{
		WhenAnyPromise_8_tB1A18813B231826F7BEE92541715D6266929F072* L_6 = ___0_self;
		int32_t L_7;
		L_7 = Interlocked_Increment_m3C240C32E8D9544EC050B74D4F28EEB58F1F9309((((int32_t*)il2cpp_codegen_get_instance_field_data_pointer(L_6, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),0)))), NULL);
		V_2 = (bool)((((int32_t)L_7) == ((int32_t)1))? 1 : 0);
		bool L_8 = V_2;
		if (!L_8)
		{
			goto IL_008e;
		}
	}
	{
		WhenAnyPromise_8_tB1A18813B231826F7BEE92541715D6266929F072* L_9 = ___0_self;
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_3, SizeOf_T1_t9561033C9FAB66A59515AC513C37865C3B8B1C18);
		il2cpp_codegen_memcpy(L_10, V_3, SizeOf_T1_t9561033C9FAB66A59515AC513C37865C3B8B1C18);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_4, SizeOf_T2_t60A74597284FB13F39BBDE70DD68794BD9BAC16D);
		il2cpp_codegen_memcpy(L_11, V_4, SizeOf_T2_t60A74597284FB13F39BBDE70DD68794BD9BAC16D);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_5, SizeOf_T3_t17D6D15FA58A3752AECA204EA2A27CF117C6BD27);
		il2cpp_codegen_memcpy(L_12, V_5, SizeOf_T3_t17D6D15FA58A3752AECA204EA2A27CF117C6BD27);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_6, SizeOf_T4_tA6EA1FDA558CFF527D8E1C6FD66E4BCF5A863863);
		il2cpp_codegen_memcpy(L_13, V_6, SizeOf_T4_tA6EA1FDA558CFF527D8E1C6FD66E4BCF5A863863);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_7, SizeOf_T5_tB849E0E76BE46D68793D81D57EA80E4C07ED9C11);
		il2cpp_codegen_memcpy(L_14, V_7, SizeOf_T5_tB849E0E76BE46D68793D81D57EA80E4C07ED9C11);
		il2cpp_codegen_memcpy(L_15, V_0, SizeOf_T6_t2C03AD7AA0DA698E7086E9F7DC38F179995C5D0C);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_8, SizeOf_T7_t12AF7525E88D4361083E6F50DD71ECC32E6985A7);
		il2cpp_codegen_memcpy(L_16, V_8, SizeOf_T7_t12AF7525E88D4361083E6F50DD71ECC32E6985A7);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_9, SizeOf_T8_t2EB77468546390559127DE1F112A1E7F29F79F90);
		il2cpp_codegen_memcpy(L_17, V_9, SizeOf_T8_t2EB77468546390559127DE1F112A1E7F29F79F90);
		memset(L_20, 0, SizeOf_ValueTuple_2_tEFD44100BF6E84A07E01EE4796B1C6D5293D34EB);
		ValueTuple_2__ctor_mCAE8E725F680FA6BE2C23B9686C9F6056BB7E5CD((ValueTuple_2_tBAA1E1D7D97D80E0EBA7FE8773B1FF409AEA3829*)L_20, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 110)) ? il2cpp_codegen_memcpy(L_18, L_16, SizeOf_T7_t12AF7525E88D4361083E6F50DD71ECC32E6985A7): *(void**)L_16), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 111)) ? il2cpp_codegen_memcpy(L_19, L_17, SizeOf_T8_t2EB77468546390559127DE1F112A1E7F29F79F90): *(void**)L_17), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 113));
		memset(L_28, 0, SizeOf_ValueTuple_8_t5A4F9798F00844711054552CC2AA9D1C017B186C);
		ValueTuple_8__ctor_m03E5F35F1F6A37FA114EA2D38102DC71B063F122((ValueTuple_8_tD42E286CF79B463B55FD4A534F1A73E02CAEECC5*)L_28, 5, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 101)) ? il2cpp_codegen_memcpy(L_21, L_10, SizeOf_T1_t9561033C9FAB66A59515AC513C37865C3B8B1C18): *(void**)L_10), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 105)) ? il2cpp_codegen_memcpy(L_22, L_11, SizeOf_T2_t60A74597284FB13F39BBDE70DD68794BD9BAC16D): *(void**)L_11), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 106)) ? il2cpp_codegen_memcpy(L_23, L_12, SizeOf_T3_t17D6D15FA58A3752AECA204EA2A27CF117C6BD27): *(void**)L_12), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 107)) ? il2cpp_codegen_memcpy(L_24, L_13, SizeOf_T4_tA6EA1FDA558CFF527D8E1C6FD66E4BCF5A863863): *(void**)L_13), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 108)) ? il2cpp_codegen_memcpy(L_25, L_14, SizeOf_T5_tB849E0E76BE46D68793D81D57EA80E4C07ED9C11): *(void**)L_14), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 109)) ? il2cpp_codegen_memcpy(L_26, L_15, SizeOf_T6_t2C03AD7AA0DA698E7086E9F7DC38F179995C5D0C): *(void**)L_15), il2cpp_codegen_memcpy(L_27, L_20, SizeOf_ValueTuple_2_tEFD44100BF6E84A07E01EE4796B1C6D5293D34EB), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 115));
		bool L_29;
		L_29 = InvokerFuncInvoker1< bool, ValueTuple_8_tD42E286CF79B463B55FD4A534F1A73E02CAEECC5 >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 116)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 116), (((UniTaskCompletionSourceCore_1_tA9C7E3CB9001D1F438C1C3BBA224B20995E6A7A2*)il2cpp_codegen_get_instance_field_data_pointer(L_9, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),1)))), L_28);
	}

IL_008e:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhenAnyPromise_8_TryInvokeContinuationT7_m0131E161FB88451A4BCAC0D07F744A79D63D63C6_gshared (WhenAnyPromise_8_tB1A18813B231826F7BEE92541715D6266929F072* ___0_self, Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* ___1_awaiter, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T7_t12AF7525E88D4361083E6F50DD71ECC32E6985A7 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 110));
	const uint32_t SizeOf_T1_t9561033C9FAB66A59515AC513C37865C3B8B1C18 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 101));
	const uint32_t SizeOf_T2_t60A74597284FB13F39BBDE70DD68794BD9BAC16D = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 105));
	const uint32_t SizeOf_T3_t17D6D15FA58A3752AECA204EA2A27CF117C6BD27 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 106));
	const uint32_t SizeOf_T4_tA6EA1FDA558CFF527D8E1C6FD66E4BCF5A863863 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 107));
	const uint32_t SizeOf_T5_tB849E0E76BE46D68793D81D57EA80E4C07ED9C11 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 108));
	const uint32_t SizeOf_T6_t2C03AD7AA0DA698E7086E9F7DC38F179995C5D0C = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 109));
	const uint32_t SizeOf_T8_t2EB77468546390559127DE1F112A1E7F29F79F90 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 111));
	const uint32_t SizeOf_ValueTuple_2_tEFD44100BF6E84A07E01EE4796B1C6D5293D34EB = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 112));
	const uint32_t SizeOf_ValueTuple_8_t5A4F9798F00844711054552CC2AA9D1C017B186C = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 114));
	const Il2CppFullySharedGenericAny L_10 = alloca(SizeOf_T1_t9561033C9FAB66A59515AC513C37865C3B8B1C18);
	const Il2CppFullySharedGenericAny L_21 = alloca(SizeOf_T1_t9561033C9FAB66A59515AC513C37865C3B8B1C18);
	const Il2CppFullySharedGenericAny L_11 = alloca(SizeOf_T2_t60A74597284FB13F39BBDE70DD68794BD9BAC16D);
	const Il2CppFullySharedGenericAny L_22 = alloca(SizeOf_T2_t60A74597284FB13F39BBDE70DD68794BD9BAC16D);
	const Il2CppFullySharedGenericAny L_12 = alloca(SizeOf_T3_t17D6D15FA58A3752AECA204EA2A27CF117C6BD27);
	const Il2CppFullySharedGenericAny L_23 = alloca(SizeOf_T3_t17D6D15FA58A3752AECA204EA2A27CF117C6BD27);
	const Il2CppFullySharedGenericAny L_13 = alloca(SizeOf_T4_tA6EA1FDA558CFF527D8E1C6FD66E4BCF5A863863);
	const Il2CppFullySharedGenericAny L_24 = alloca(SizeOf_T4_tA6EA1FDA558CFF527D8E1C6FD66E4BCF5A863863);
	const Il2CppFullySharedGenericAny L_14 = alloca(SizeOf_T5_tB849E0E76BE46D68793D81D57EA80E4C07ED9C11);
	const Il2CppFullySharedGenericAny L_25 = alloca(SizeOf_T5_tB849E0E76BE46D68793D81D57EA80E4C07ED9C11);
	const Il2CppFullySharedGenericAny L_15 = alloca(SizeOf_T6_t2C03AD7AA0DA698E7086E9F7DC38F179995C5D0C);
	const Il2CppFullySharedGenericAny L_26 = alloca(SizeOf_T6_t2C03AD7AA0DA698E7086E9F7DC38F179995C5D0C);
	const Il2CppFullySharedGenericAny L_1 = alloca(SizeOf_T7_t12AF7525E88D4361083E6F50DD71ECC32E6985A7);
	const Il2CppFullySharedGenericAny L_16 = L_1;
	const Il2CppFullySharedGenericAny L_18 = alloca(SizeOf_T7_t12AF7525E88D4361083E6F50DD71ECC32E6985A7);
	const Il2CppFullySharedGenericAny L_17 = alloca(SizeOf_T8_t2EB77468546390559127DE1F112A1E7F29F79F90);
	const Il2CppFullySharedGenericAny L_19 = alloca(SizeOf_T8_t2EB77468546390559127DE1F112A1E7F29F79F90);
	const ValueTuple_2_tBAA1E1D7D97D80E0EBA7FE8773B1FF409AEA3829 L_20 = alloca(SizeOf_ValueTuple_2_tEFD44100BF6E84A07E01EE4796B1C6D5293D34EB);
	const ValueTuple_2_tBAA1E1D7D97D80E0EBA7FE8773B1FF409AEA3829 L_27 = alloca(SizeOf_ValueTuple_2_tEFD44100BF6E84A07E01EE4796B1C6D5293D34EB);
	const ValueTuple_8_tD42E286CF79B463B55FD4A534F1A73E02CAEECC5 L_28 = alloca(SizeOf_ValueTuple_8_t5A4F9798F00844711054552CC2AA9D1C017B186C);
	Il2CppFullySharedGenericAny V_0 = alloca(SizeOf_T7_t12AF7525E88D4361083E6F50DD71ECC32E6985A7);
	memset(V_0, 0, SizeOf_T7_t12AF7525E88D4361083E6F50DD71ECC32E6985A7);
	Exception_t* V_1 = NULL;
	bool V_2 = false;
	Il2CppFullySharedGenericAny V_3 = alloca(SizeOf_T1_t9561033C9FAB66A59515AC513C37865C3B8B1C18);
	memset(V_3, 0, SizeOf_T1_t9561033C9FAB66A59515AC513C37865C3B8B1C18);
	Il2CppFullySharedGenericAny V_4 = alloca(SizeOf_T2_t60A74597284FB13F39BBDE70DD68794BD9BAC16D);
	memset(V_4, 0, SizeOf_T2_t60A74597284FB13F39BBDE70DD68794BD9BAC16D);
	Il2CppFullySharedGenericAny V_5 = alloca(SizeOf_T3_t17D6D15FA58A3752AECA204EA2A27CF117C6BD27);
	memset(V_5, 0, SizeOf_T3_t17D6D15FA58A3752AECA204EA2A27CF117C6BD27);
	Il2CppFullySharedGenericAny V_6 = alloca(SizeOf_T4_tA6EA1FDA558CFF527D8E1C6FD66E4BCF5A863863);
	memset(V_6, 0, SizeOf_T4_tA6EA1FDA558CFF527D8E1C6FD66E4BCF5A863863);
	Il2CppFullySharedGenericAny V_7 = alloca(SizeOf_T5_tB849E0E76BE46D68793D81D57EA80E4C07ED9C11);
	memset(V_7, 0, SizeOf_T5_tB849E0E76BE46D68793D81D57EA80E4C07ED9C11);
	Il2CppFullySharedGenericAny V_8 = alloca(SizeOf_T6_t2C03AD7AA0DA698E7086E9F7DC38F179995C5D0C);
	memset(V_8, 0, SizeOf_T6_t2C03AD7AA0DA698E7086E9F7DC38F179995C5D0C);
	Il2CppFullySharedGenericAny V_9 = alloca(SizeOf_T8_t2EB77468546390559127DE1F112A1E7F29F79F90);
	memset(V_9, 0, SizeOf_T8_t2EB77468546390559127DE1F112A1E7F29F79F90);
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
	}
	try
	{
		Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* L_0 = ___1_awaiter;
		InvokerActionInvoker1< Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 122)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 122), L_0, (Il2CppFullySharedGenericAny*)L_1);
		il2cpp_codegen_memcpy(V_0, L_1, SizeOf_T7_t12AF7525E88D4361083E6F50DD71ECC32E6985A7);
		goto IL_001d;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&Exception_t_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_000c;
		}
		throw e;
	}

CATCH_000c:
	{
		Exception_t* L_2 = ((Exception_t*)IL2CPP_GET_ACTIVE_EXCEPTION(Exception_t*));;
		V_1 = L_2;
		WhenAnyPromise_8_tB1A18813B231826F7BEE92541715D6266929F072* L_3 = ___0_self;
		Exception_t* L_4 = V_1;
		bool L_5;
		L_5 = ((  bool (*) (UniTaskCompletionSourceCore_1_tA9C7E3CB9001D1F438C1C3BBA224B20995E6A7A2*, Exception_t*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 103)))((((UniTaskCompletionSourceCore_1_tA9C7E3CB9001D1F438C1C3BBA224B20995E6A7A2*)il2cpp_codegen_get_instance_field_data_pointer(L_3, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),1)))), L_4, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 103));
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_008e;
	}

IL_001d:
	{
		WhenAnyPromise_8_tB1A18813B231826F7BEE92541715D6266929F072* L_6 = ___0_self;
		int32_t L_7;
		L_7 = Interlocked_Increment_m3C240C32E8D9544EC050B74D4F28EEB58F1F9309((((int32_t*)il2cpp_codegen_get_instance_field_data_pointer(L_6, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),0)))), NULL);
		V_2 = (bool)((((int32_t)L_7) == ((int32_t)1))? 1 : 0);
		bool L_8 = V_2;
		if (!L_8)
		{
			goto IL_008e;
		}
	}
	{
		WhenAnyPromise_8_tB1A18813B231826F7BEE92541715D6266929F072* L_9 = ___0_self;
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_3, SizeOf_T1_t9561033C9FAB66A59515AC513C37865C3B8B1C18);
		il2cpp_codegen_memcpy(L_10, V_3, SizeOf_T1_t9561033C9FAB66A59515AC513C37865C3B8B1C18);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_4, SizeOf_T2_t60A74597284FB13F39BBDE70DD68794BD9BAC16D);
		il2cpp_codegen_memcpy(L_11, V_4, SizeOf_T2_t60A74597284FB13F39BBDE70DD68794BD9BAC16D);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_5, SizeOf_T3_t17D6D15FA58A3752AECA204EA2A27CF117C6BD27);
		il2cpp_codegen_memcpy(L_12, V_5, SizeOf_T3_t17D6D15FA58A3752AECA204EA2A27CF117C6BD27);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_6, SizeOf_T4_tA6EA1FDA558CFF527D8E1C6FD66E4BCF5A863863);
		il2cpp_codegen_memcpy(L_13, V_6, SizeOf_T4_tA6EA1FDA558CFF527D8E1C6FD66E4BCF5A863863);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_7, SizeOf_T5_tB849E0E76BE46D68793D81D57EA80E4C07ED9C11);
		il2cpp_codegen_memcpy(L_14, V_7, SizeOf_T5_tB849E0E76BE46D68793D81D57EA80E4C07ED9C11);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_8, SizeOf_T6_t2C03AD7AA0DA698E7086E9F7DC38F179995C5D0C);
		il2cpp_codegen_memcpy(L_15, V_8, SizeOf_T6_t2C03AD7AA0DA698E7086E9F7DC38F179995C5D0C);
		il2cpp_codegen_memcpy(L_16, V_0, SizeOf_T7_t12AF7525E88D4361083E6F50DD71ECC32E6985A7);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_9, SizeOf_T8_t2EB77468546390559127DE1F112A1E7F29F79F90);
		il2cpp_codegen_memcpy(L_17, V_9, SizeOf_T8_t2EB77468546390559127DE1F112A1E7F29F79F90);
		memset(L_20, 0, SizeOf_ValueTuple_2_tEFD44100BF6E84A07E01EE4796B1C6D5293D34EB);
		ValueTuple_2__ctor_mCAE8E725F680FA6BE2C23B9686C9F6056BB7E5CD((ValueTuple_2_tBAA1E1D7D97D80E0EBA7FE8773B1FF409AEA3829*)L_20, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 110)) ? il2cpp_codegen_memcpy(L_18, L_16, SizeOf_T7_t12AF7525E88D4361083E6F50DD71ECC32E6985A7): *(void**)L_16), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 111)) ? il2cpp_codegen_memcpy(L_19, L_17, SizeOf_T8_t2EB77468546390559127DE1F112A1E7F29F79F90): *(void**)L_17), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 113));
		memset(L_28, 0, SizeOf_ValueTuple_8_t5A4F9798F00844711054552CC2AA9D1C017B186C);
		ValueTuple_8__ctor_m03E5F35F1F6A37FA114EA2D38102DC71B063F122((ValueTuple_8_tD42E286CF79B463B55FD4A534F1A73E02CAEECC5*)L_28, 6, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 101)) ? il2cpp_codegen_memcpy(L_21, L_10, SizeOf_T1_t9561033C9FAB66A59515AC513C37865C3B8B1C18): *(void**)L_10), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 105)) ? il2cpp_codegen_memcpy(L_22, L_11, SizeOf_T2_t60A74597284FB13F39BBDE70DD68794BD9BAC16D): *(void**)L_11), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 106)) ? il2cpp_codegen_memcpy(L_23, L_12, SizeOf_T3_t17D6D15FA58A3752AECA204EA2A27CF117C6BD27): *(void**)L_12), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 107)) ? il2cpp_codegen_memcpy(L_24, L_13, SizeOf_T4_tA6EA1FDA558CFF527D8E1C6FD66E4BCF5A863863): *(void**)L_13), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 108)) ? il2cpp_codegen_memcpy(L_25, L_14, SizeOf_T5_tB849E0E76BE46D68793D81D57EA80E4C07ED9C11): *(void**)L_14), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 109)) ? il2cpp_codegen_memcpy(L_26, L_15, SizeOf_T6_t2C03AD7AA0DA698E7086E9F7DC38F179995C5D0C): *(void**)L_15), il2cpp_codegen_memcpy(L_27, L_20, SizeOf_ValueTuple_2_tEFD44100BF6E84A07E01EE4796B1C6D5293D34EB), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 115));
		bool L_29;
		L_29 = InvokerFuncInvoker1< bool, ValueTuple_8_tD42E286CF79B463B55FD4A534F1A73E02CAEECC5 >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 116)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 116), (((UniTaskCompletionSourceCore_1_tA9C7E3CB9001D1F438C1C3BBA224B20995E6A7A2*)il2cpp_codegen_get_instance_field_data_pointer(L_9, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),1)))), L_28);
	}

IL_008e:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhenAnyPromise_8_TryInvokeContinuationT8_mD35DBE8A9AB85FF1423A6B87EEA5E5B05E035078_gshared (WhenAnyPromise_8_tB1A18813B231826F7BEE92541715D6266929F072* ___0_self, Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* ___1_awaiter, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T8_t2EB77468546390559127DE1F112A1E7F29F79F90 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 111));
	const uint32_t SizeOf_T1_t9561033C9FAB66A59515AC513C37865C3B8B1C18 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 101));
	const uint32_t SizeOf_T2_t60A74597284FB13F39BBDE70DD68794BD9BAC16D = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 105));
	const uint32_t SizeOf_T3_t17D6D15FA58A3752AECA204EA2A27CF117C6BD27 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 106));
	const uint32_t SizeOf_T4_tA6EA1FDA558CFF527D8E1C6FD66E4BCF5A863863 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 107));
	const uint32_t SizeOf_T5_tB849E0E76BE46D68793D81D57EA80E4C07ED9C11 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 108));
	const uint32_t SizeOf_T6_t2C03AD7AA0DA698E7086E9F7DC38F179995C5D0C = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 109));
	const uint32_t SizeOf_T7_t12AF7525E88D4361083E6F50DD71ECC32E6985A7 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 110));
	const uint32_t SizeOf_ValueTuple_2_tEFD44100BF6E84A07E01EE4796B1C6D5293D34EB = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 112));
	const uint32_t SizeOf_ValueTuple_8_t5A4F9798F00844711054552CC2AA9D1C017B186C = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 114));
	const Il2CppFullySharedGenericAny L_10 = alloca(SizeOf_T1_t9561033C9FAB66A59515AC513C37865C3B8B1C18);
	const Il2CppFullySharedGenericAny L_21 = alloca(SizeOf_T1_t9561033C9FAB66A59515AC513C37865C3B8B1C18);
	const Il2CppFullySharedGenericAny L_11 = alloca(SizeOf_T2_t60A74597284FB13F39BBDE70DD68794BD9BAC16D);
	const Il2CppFullySharedGenericAny L_22 = alloca(SizeOf_T2_t60A74597284FB13F39BBDE70DD68794BD9BAC16D);
	const Il2CppFullySharedGenericAny L_12 = alloca(SizeOf_T3_t17D6D15FA58A3752AECA204EA2A27CF117C6BD27);
	const Il2CppFullySharedGenericAny L_23 = alloca(SizeOf_T3_t17D6D15FA58A3752AECA204EA2A27CF117C6BD27);
	const Il2CppFullySharedGenericAny L_13 = alloca(SizeOf_T4_tA6EA1FDA558CFF527D8E1C6FD66E4BCF5A863863);
	const Il2CppFullySharedGenericAny L_24 = alloca(SizeOf_T4_tA6EA1FDA558CFF527D8E1C6FD66E4BCF5A863863);
	const Il2CppFullySharedGenericAny L_14 = alloca(SizeOf_T5_tB849E0E76BE46D68793D81D57EA80E4C07ED9C11);
	const Il2CppFullySharedGenericAny L_25 = alloca(SizeOf_T5_tB849E0E76BE46D68793D81D57EA80E4C07ED9C11);
	const Il2CppFullySharedGenericAny L_15 = alloca(SizeOf_T6_t2C03AD7AA0DA698E7086E9F7DC38F179995C5D0C);
	const Il2CppFullySharedGenericAny L_26 = alloca(SizeOf_T6_t2C03AD7AA0DA698E7086E9F7DC38F179995C5D0C);
	const Il2CppFullySharedGenericAny L_16 = alloca(SizeOf_T7_t12AF7525E88D4361083E6F50DD71ECC32E6985A7);
	const Il2CppFullySharedGenericAny L_18 = alloca(SizeOf_T7_t12AF7525E88D4361083E6F50DD71ECC32E6985A7);
	const Il2CppFullySharedGenericAny L_1 = alloca(SizeOf_T8_t2EB77468546390559127DE1F112A1E7F29F79F90);
	const Il2CppFullySharedGenericAny L_17 = L_1;
	const Il2CppFullySharedGenericAny L_19 = alloca(SizeOf_T8_t2EB77468546390559127DE1F112A1E7F29F79F90);
	const ValueTuple_2_tBAA1E1D7D97D80E0EBA7FE8773B1FF409AEA3829 L_20 = alloca(SizeOf_ValueTuple_2_tEFD44100BF6E84A07E01EE4796B1C6D5293D34EB);
	const ValueTuple_2_tBAA1E1D7D97D80E0EBA7FE8773B1FF409AEA3829 L_27 = alloca(SizeOf_ValueTuple_2_tEFD44100BF6E84A07E01EE4796B1C6D5293D34EB);
	const ValueTuple_8_tD42E286CF79B463B55FD4A534F1A73E02CAEECC5 L_28 = alloca(SizeOf_ValueTuple_8_t5A4F9798F00844711054552CC2AA9D1C017B186C);
	Il2CppFullySharedGenericAny V_0 = alloca(SizeOf_T8_t2EB77468546390559127DE1F112A1E7F29F79F90);
	memset(V_0, 0, SizeOf_T8_t2EB77468546390559127DE1F112A1E7F29F79F90);
	Exception_t* V_1 = NULL;
	bool V_2 = false;
	Il2CppFullySharedGenericAny V_3 = alloca(SizeOf_T1_t9561033C9FAB66A59515AC513C37865C3B8B1C18);
	memset(V_3, 0, SizeOf_T1_t9561033C9FAB66A59515AC513C37865C3B8B1C18);
	Il2CppFullySharedGenericAny V_4 = alloca(SizeOf_T2_t60A74597284FB13F39BBDE70DD68794BD9BAC16D);
	memset(V_4, 0, SizeOf_T2_t60A74597284FB13F39BBDE70DD68794BD9BAC16D);
	Il2CppFullySharedGenericAny V_5 = alloca(SizeOf_T3_t17D6D15FA58A3752AECA204EA2A27CF117C6BD27);
	memset(V_5, 0, SizeOf_T3_t17D6D15FA58A3752AECA204EA2A27CF117C6BD27);
	Il2CppFullySharedGenericAny V_6 = alloca(SizeOf_T4_tA6EA1FDA558CFF527D8E1C6FD66E4BCF5A863863);
	memset(V_6, 0, SizeOf_T4_tA6EA1FDA558CFF527D8E1C6FD66E4BCF5A863863);
	Il2CppFullySharedGenericAny V_7 = alloca(SizeOf_T5_tB849E0E76BE46D68793D81D57EA80E4C07ED9C11);
	memset(V_7, 0, SizeOf_T5_tB849E0E76BE46D68793D81D57EA80E4C07ED9C11);
	Il2CppFullySharedGenericAny V_8 = alloca(SizeOf_T6_t2C03AD7AA0DA698E7086E9F7DC38F179995C5D0C);
	memset(V_8, 0, SizeOf_T6_t2C03AD7AA0DA698E7086E9F7DC38F179995C5D0C);
	Il2CppFullySharedGenericAny V_9 = alloca(SizeOf_T7_t12AF7525E88D4361083E6F50DD71ECC32E6985A7);
	memset(V_9, 0, SizeOf_T7_t12AF7525E88D4361083E6F50DD71ECC32E6985A7);
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
	}
	try
	{
		Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* L_0 = ___1_awaiter;
		InvokerActionInvoker1< Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 123)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 123), L_0, (Il2CppFullySharedGenericAny*)L_1);
		il2cpp_codegen_memcpy(V_0, L_1, SizeOf_T8_t2EB77468546390559127DE1F112A1E7F29F79F90);
		goto IL_001d;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&Exception_t_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_000c;
		}
		throw e;
	}

CATCH_000c:
	{
		Exception_t* L_2 = ((Exception_t*)IL2CPP_GET_ACTIVE_EXCEPTION(Exception_t*));;
		V_1 = L_2;
		WhenAnyPromise_8_tB1A18813B231826F7BEE92541715D6266929F072* L_3 = ___0_self;
		Exception_t* L_4 = V_1;
		bool L_5;
		L_5 = ((  bool (*) (UniTaskCompletionSourceCore_1_tA9C7E3CB9001D1F438C1C3BBA224B20995E6A7A2*, Exception_t*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 103)))((((UniTaskCompletionSourceCore_1_tA9C7E3CB9001D1F438C1C3BBA224B20995E6A7A2*)il2cpp_codegen_get_instance_field_data_pointer(L_3, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),1)))), L_4, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 103));
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_008e;
	}

IL_001d:
	{
		WhenAnyPromise_8_tB1A18813B231826F7BEE92541715D6266929F072* L_6 = ___0_self;
		int32_t L_7;
		L_7 = Interlocked_Increment_m3C240C32E8D9544EC050B74D4F28EEB58F1F9309((((int32_t*)il2cpp_codegen_get_instance_field_data_pointer(L_6, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),0)))), NULL);
		V_2 = (bool)((((int32_t)L_7) == ((int32_t)1))? 1 : 0);
		bool L_8 = V_2;
		if (!L_8)
		{
			goto IL_008e;
		}
	}
	{
		WhenAnyPromise_8_tB1A18813B231826F7BEE92541715D6266929F072* L_9 = ___0_self;
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_3, SizeOf_T1_t9561033C9FAB66A59515AC513C37865C3B8B1C18);
		il2cpp_codegen_memcpy(L_10, V_3, SizeOf_T1_t9561033C9FAB66A59515AC513C37865C3B8B1C18);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_4, SizeOf_T2_t60A74597284FB13F39BBDE70DD68794BD9BAC16D);
		il2cpp_codegen_memcpy(L_11, V_4, SizeOf_T2_t60A74597284FB13F39BBDE70DD68794BD9BAC16D);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_5, SizeOf_T3_t17D6D15FA58A3752AECA204EA2A27CF117C6BD27);
		il2cpp_codegen_memcpy(L_12, V_5, SizeOf_T3_t17D6D15FA58A3752AECA204EA2A27CF117C6BD27);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_6, SizeOf_T4_tA6EA1FDA558CFF527D8E1C6FD66E4BCF5A863863);
		il2cpp_codegen_memcpy(L_13, V_6, SizeOf_T4_tA6EA1FDA558CFF527D8E1C6FD66E4BCF5A863863);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_7, SizeOf_T5_tB849E0E76BE46D68793D81D57EA80E4C07ED9C11);
		il2cpp_codegen_memcpy(L_14, V_7, SizeOf_T5_tB849E0E76BE46D68793D81D57EA80E4C07ED9C11);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_8, SizeOf_T6_t2C03AD7AA0DA698E7086E9F7DC38F179995C5D0C);
		il2cpp_codegen_memcpy(L_15, V_8, SizeOf_T6_t2C03AD7AA0DA698E7086E9F7DC38F179995C5D0C);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_9, SizeOf_T7_t12AF7525E88D4361083E6F50DD71ECC32E6985A7);
		il2cpp_codegen_memcpy(L_16, V_9, SizeOf_T7_t12AF7525E88D4361083E6F50DD71ECC32E6985A7);
		il2cpp_codegen_memcpy(L_17, V_0, SizeOf_T8_t2EB77468546390559127DE1F112A1E7F29F79F90);
		memset(L_20, 0, SizeOf_ValueTuple_2_tEFD44100BF6E84A07E01EE4796B1C6D5293D34EB);
		ValueTuple_2__ctor_mCAE8E725F680FA6BE2C23B9686C9F6056BB7E5CD((ValueTuple_2_tBAA1E1D7D97D80E0EBA7FE8773B1FF409AEA3829*)L_20, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 110)) ? il2cpp_codegen_memcpy(L_18, L_16, SizeOf_T7_t12AF7525E88D4361083E6F50DD71ECC32E6985A7): *(void**)L_16), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 111)) ? il2cpp_codegen_memcpy(L_19, L_17, SizeOf_T8_t2EB77468546390559127DE1F112A1E7F29F79F90): *(void**)L_17), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 113));
		memset(L_28, 0, SizeOf_ValueTuple_8_t5A4F9798F00844711054552CC2AA9D1C017B186C);
		ValueTuple_8__ctor_m03E5F35F1F6A37FA114EA2D38102DC71B063F122((ValueTuple_8_tD42E286CF79B463B55FD4A534F1A73E02CAEECC5*)L_28, 7, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 101)) ? il2cpp_codegen_memcpy(L_21, L_10, SizeOf_T1_t9561033C9FAB66A59515AC513C37865C3B8B1C18): *(void**)L_10), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 105)) ? il2cpp_codegen_memcpy(L_22, L_11, SizeOf_T2_t60A74597284FB13F39BBDE70DD68794BD9BAC16D): *(void**)L_11), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 106)) ? il2cpp_codegen_memcpy(L_23, L_12, SizeOf_T3_t17D6D15FA58A3752AECA204EA2A27CF117C6BD27): *(void**)L_12), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 107)) ? il2cpp_codegen_memcpy(L_24, L_13, SizeOf_T4_tA6EA1FDA558CFF527D8E1C6FD66E4BCF5A863863): *(void**)L_13), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 108)) ? il2cpp_codegen_memcpy(L_25, L_14, SizeOf_T5_tB849E0E76BE46D68793D81D57EA80E4C07ED9C11): *(void**)L_14), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 109)) ? il2cpp_codegen_memcpy(L_26, L_15, SizeOf_T6_t2C03AD7AA0DA698E7086E9F7DC38F179995C5D0C): *(void**)L_15), il2cpp_codegen_memcpy(L_27, L_20, SizeOf_ValueTuple_2_tEFD44100BF6E84A07E01EE4796B1C6D5293D34EB), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 115));
		bool L_29;
		L_29 = InvokerFuncInvoker1< bool, ValueTuple_8_tD42E286CF79B463B55FD4A534F1A73E02CAEECC5 >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 116)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 116), (((UniTaskCompletionSourceCore_1_tA9C7E3CB9001D1F438C1C3BBA224B20995E6A7A2*)il2cpp_codegen_get_instance_field_data_pointer(L_9, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),1)))), L_28);
	}

IL_008e:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhenAnyPromise_8_GetResult_m8179773EAF240657A037D86BD41AEE69F6243B01_gshared (WhenAnyPromise_8_tB1A18813B231826F7BEE92541715D6266929F072* __this, int16_t ___0_token, ValueTuple_8_tD42E286CF79B463B55FD4A534F1A73E02CAEECC5* il2cppRetVal, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GC_t920F9CF6EBB7C787E5010A4352E1B587F356DC58_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	const uint32_t SizeOf_ValueTuple_8_t5A4F9798F00844711054552CC2AA9D1C017B186C = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 114));
	const ValueTuple_8_tD42E286CF79B463B55FD4A534F1A73E02CAEECC5 L_1 = alloca(SizeOf_ValueTuple_8_t5A4F9798F00844711054552CC2AA9D1C017B186C);
	const ValueTuple_8_tD42E286CF79B463B55FD4A534F1A73E02CAEECC5 L_2 = L_1;
	ValueTuple_8_tD42E286CF79B463B55FD4A534F1A73E02CAEECC5 V_0 = alloca(SizeOf_ValueTuple_8_t5A4F9798F00844711054552CC2AA9D1C017B186C);
	memset(V_0, 0, SizeOf_ValueTuple_8_t5A4F9798F00844711054552CC2AA9D1C017B186C);
	{
		il2cpp_codegen_runtime_class_init_inline(GC_t920F9CF6EBB7C787E5010A4352E1B587F356DC58_il2cpp_TypeInfo_var);
		GC_SuppressFinalize_m71815DBD5A0CD2EA1BE43317B08B7A14949EDC65((RuntimeObject*)__this, NULL);
		int16_t L_0 = ___0_token;
		InvokerActionInvoker2< int16_t, ValueTuple_8_tD42E286CF79B463B55FD4A534F1A73E02CAEECC5* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 124)), il2cpp_rgctx_method(method->klass->rgctx_data, 124), (((UniTaskCompletionSourceCore_1_tA9C7E3CB9001D1F438C1C3BBA224B20995E6A7A2*)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 0),1)))), L_0, (ValueTuple_8_tD42E286CF79B463B55FD4A534F1A73E02CAEECC5*)L_1);
		il2cpp_codegen_memcpy(V_0, L_1, SizeOf_ValueTuple_8_t5A4F9798F00844711054552CC2AA9D1C017B186C);
		goto IL_0017;
	}

IL_0017:
	{
		il2cpp_codegen_memcpy(L_2, V_0, SizeOf_ValueTuple_8_t5A4F9798F00844711054552CC2AA9D1C017B186C);
		il2cpp_codegen_memcpy(il2cppRetVal, L_2, SizeOf_ValueTuple_8_t5A4F9798F00844711054552CC2AA9D1C017B186C);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t WhenAnyPromise_8_GetStatus_m120327589A6911025F26EA21963516518FA3D8A6_gshared (WhenAnyPromise_8_tB1A18813B231826F7BEE92541715D6266929F072* __this, int16_t ___0_token, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		int16_t L_0 = ___0_token;
		int32_t L_1;
		L_1 = ((  int32_t (*) (UniTaskCompletionSourceCore_1_tA9C7E3CB9001D1F438C1C3BBA224B20995E6A7A2*, int16_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 125)))((((UniTaskCompletionSourceCore_1_tA9C7E3CB9001D1F438C1C3BBA224B20995E6A7A2*)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 0),1)))), L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 125));
		V_0 = L_1;
		goto IL_0010;
	}

IL_0010:
	{
		int32_t L_2 = V_0;
		return L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhenAnyPromise_8_OnCompleted_m296EED481119D3E0F40E167836FBE3C7AA67B812_gshared (WhenAnyPromise_8_tB1A18813B231826F7BEE92541715D6266929F072* __this, Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* ___0_continuation, RuntimeObject* ___1_state, int16_t ___2_token, const RuntimeMethod* method) 
{
	{
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_0 = ___0_continuation;
		RuntimeObject* L_1 = ___1_state;
		int16_t L_2 = ___2_token;
		((  void (*) (UniTaskCompletionSourceCore_1_tA9C7E3CB9001D1F438C1C3BBA224B20995E6A7A2*, Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87*, RuntimeObject*, int16_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 126)))((((UniTaskCompletionSourceCore_1_tA9C7E3CB9001D1F438C1C3BBA224B20995E6A7A2*)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 0),1)))), L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 126));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t WhenAnyPromise_8_UnsafeGetStatus_m0EC308A6F2E9D6D42B9F657DE69B75434F23C8FB_gshared (WhenAnyPromise_8_tB1A18813B231826F7BEE92541715D6266929F072* __this, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		int32_t L_0;
		L_0 = ((  int32_t (*) (UniTaskCompletionSourceCore_1_tA9C7E3CB9001D1F438C1C3BBA224B20995E6A7A2*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 127)))((((UniTaskCompletionSourceCore_1_tA9C7E3CB9001D1F438C1C3BBA224B20995E6A7A2*)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 0),1)))), il2cpp_rgctx_method(method->klass->rgctx_data, 127));
		V_0 = L_0;
		goto IL_000f;
	}

IL_000f:
	{
		int32_t L_1 = V_0;
		return L_1;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhenAnyPromise_8_Cysharp_Threading_Tasks_IUniTaskSource_GetResult_m11C051AEC60F84D7B662AA2CA5F7BB8FCA9982E8_gshared (WhenAnyPromise_8_tB1A18813B231826F7BEE92541715D6266929F072* __this, int16_t ___0_token, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_ValueTuple_8_t5A4F9798F00844711054552CC2AA9D1C017B186C = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 114));
	const ValueTuple_8_tD42E286CF79B463B55FD4A534F1A73E02CAEECC5 L_1 = alloca(SizeOf_ValueTuple_8_t5A4F9798F00844711054552CC2AA9D1C017B186C);
	{
		int16_t L_0 = ___0_token;
		InvokerActionInvoker2< int16_t, ValueTuple_8_tD42E286CF79B463B55FD4A534F1A73E02CAEECC5* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 128)), il2cpp_rgctx_method(method->klass->rgctx_data, 128), __this, L_0, (ValueTuple_8_tD42E286CF79B463B55FD4A534F1A73E02CAEECC5*)L_1);
		return;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhenAnyPromise_9__ctor_mCDAB8EA16CD8CDA71DE9E63EE51DD247D9070294_gshared (WhenAnyPromise_9_t2D551F16D8A9A247E0C45E7698A6A7A3CCDB7757* __this, UniTask_1_t462EA7468BEE3A822B4D759A9930C6DF4DED6483 ___0_task1, UniTask_1_t462EA7468BEE3A822B4D759A9930C6DF4DED6483 ___1_task2, UniTask_1_t462EA7468BEE3A822B4D759A9930C6DF4DED6483 ___2_task3, UniTask_1_t462EA7468BEE3A822B4D759A9930C6DF4DED6483 ___3_task4, UniTask_1_t462EA7468BEE3A822B4D759A9930C6DF4DED6483 ___4_task5, UniTask_1_t462EA7468BEE3A822B4D759A9930C6DF4DED6483 ___5_task6, UniTask_1_t462EA7468BEE3A822B4D759A9930C6DF4DED6483 ___6_task7, UniTask_1_t462EA7468BEE3A822B4D759A9930C6DF4DED6483 ___7_task8, UniTask_1_t462EA7468BEE3A822B4D759A9930C6DF4DED6483 ___8_task9, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	const uint32_t SizeOf_Awaiter_t1CB335AE21BA160B0696B13493AFAA6006408052 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 4));
	const uint32_t SizeOf_Awaiter_t7285A84B788050EB2963579444EEE0D82AA2776F = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 19));
	const uint32_t SizeOf_Awaiter_t8E7332A0B3890D89A55DD086A9B18D6DD097EB4A = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 31));
	const uint32_t SizeOf_Awaiter_t2BE5DFCDDF1E1769B74EA8B9D1F1AE8AC5C6B550 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 43));
	const uint32_t SizeOf_Awaiter_tCCA67F4A21F8DC391E99818FBBE3F4C47FD52AF7 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 55));
	const uint32_t SizeOf_Awaiter_t51D8578ADFDB9DDED327CC3488B7EAEF664DB387 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 67));
	const uint32_t SizeOf_Awaiter_tF45E6AA0F09CC1C94B66E16FB5ED0D7C231BCDC2 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 79));
	const uint32_t SizeOf_Awaiter_t9A2F748C83EE5745F31F629DBC0C26AE0B45F342 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 91));
	const uint32_t SizeOf_Awaiter_t2BEBEFE73CAAEF9B13D5D3047C346979ED99C61E = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 103));
	const Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C L_0 = alloca(SizeOf_Awaiter_t1CB335AE21BA160B0696B13493AFAA6006408052);
	const Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C L_8 = L_0;
	const Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C L_10 = alloca(SizeOf_Awaiter_t7285A84B788050EB2963579444EEE0D82AA2776F);
	const Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C L_18 = L_10;
	const Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C L_20 = alloca(SizeOf_Awaiter_t8E7332A0B3890D89A55DD086A9B18D6DD097EB4A);
	const Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C L_28 = L_20;
	const Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C L_30 = alloca(SizeOf_Awaiter_t2BE5DFCDDF1E1769B74EA8B9D1F1AE8AC5C6B550);
	const Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C L_38 = L_30;
	const Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C L_40 = alloca(SizeOf_Awaiter_tCCA67F4A21F8DC391E99818FBBE3F4C47FD52AF7);
	const Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C L_48 = L_40;
	const Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C L_50 = alloca(SizeOf_Awaiter_t51D8578ADFDB9DDED327CC3488B7EAEF664DB387);
	const Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C L_58 = L_50;
	const Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C L_60 = alloca(SizeOf_Awaiter_tF45E6AA0F09CC1C94B66E16FB5ED0D7C231BCDC2);
	const Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C L_68 = L_60;
	const Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C L_70 = alloca(SizeOf_Awaiter_t9A2F748C83EE5745F31F629DBC0C26AE0B45F342);
	const Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C L_78 = L_70;
	const Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C L_80 = alloca(SizeOf_Awaiter_t2BEBEFE73CAAEF9B13D5D3047C346979ED99C61E);
	const Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C L_88 = L_80;
	Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C V_0 = alloca(SizeOf_Awaiter_t1CB335AE21BA160B0696B13493AFAA6006408052);
	memset(V_0, 0, SizeOf_Awaiter_t1CB335AE21BA160B0696B13493AFAA6006408052);
	bool V_1 = false;
	Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C V_2 = alloca(SizeOf_Awaiter_t7285A84B788050EB2963579444EEE0D82AA2776F);
	memset(V_2, 0, SizeOf_Awaiter_t7285A84B788050EB2963579444EEE0D82AA2776F);
	bool V_3 = false;
	Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C V_4 = alloca(SizeOf_Awaiter_t8E7332A0B3890D89A55DD086A9B18D6DD097EB4A);
	memset(V_4, 0, SizeOf_Awaiter_t8E7332A0B3890D89A55DD086A9B18D6DD097EB4A);
	bool V_5 = false;
	Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C V_6 = alloca(SizeOf_Awaiter_t2BE5DFCDDF1E1769B74EA8B9D1F1AE8AC5C6B550);
	memset(V_6, 0, SizeOf_Awaiter_t2BE5DFCDDF1E1769B74EA8B9D1F1AE8AC5C6B550);
	bool V_7 = false;
	Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C V_8 = alloca(SizeOf_Awaiter_tCCA67F4A21F8DC391E99818FBBE3F4C47FD52AF7);
	memset(V_8, 0, SizeOf_Awaiter_tCCA67F4A21F8DC391E99818FBBE3F4C47FD52AF7);
	bool V_9 = false;
	Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C V_10 = alloca(SizeOf_Awaiter_t51D8578ADFDB9DDED327CC3488B7EAEF664DB387);
	memset(V_10, 0, SizeOf_Awaiter_t51D8578ADFDB9DDED327CC3488B7EAEF664DB387);
	bool V_11 = false;
	Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C V_12 = alloca(SizeOf_Awaiter_tF45E6AA0F09CC1C94B66E16FB5ED0D7C231BCDC2);
	memset(V_12, 0, SizeOf_Awaiter_tF45E6AA0F09CC1C94B66E16FB5ED0D7C231BCDC2);
	bool V_13 = false;
	Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C V_14 = alloca(SizeOf_Awaiter_t9A2F748C83EE5745F31F629DBC0C26AE0B45F342);
	memset(V_14, 0, SizeOf_Awaiter_t9A2F748C83EE5745F31F629DBC0C26AE0B45F342);
	bool V_15 = false;
	Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C V_16 = alloca(SizeOf_Awaiter_t2BEBEFE73CAAEF9B13D5D3047C346979ED99C61E);
	memset(V_16, 0, SizeOf_Awaiter_t2BEBEFE73CAAEF9B13D5D3047C346979ED99C61E);
	bool V_17 = false;
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* G_B4_0 = NULL;
	Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* G_B4_1 = NULL;
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* G_B3_0 = NULL;
	Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* G_B3_1 = NULL;
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* G_B9_0 = NULL;
	Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* G_B9_1 = NULL;
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* G_B8_0 = NULL;
	Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* G_B8_1 = NULL;
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* G_B14_0 = NULL;
	Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* G_B14_1 = NULL;
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* G_B13_0 = NULL;
	Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* G_B13_1 = NULL;
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* G_B19_0 = NULL;
	Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* G_B19_1 = NULL;
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* G_B18_0 = NULL;
	Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* G_B18_1 = NULL;
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* G_B24_0 = NULL;
	Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* G_B24_1 = NULL;
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* G_B23_0 = NULL;
	Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* G_B23_1 = NULL;
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* G_B29_0 = NULL;
	Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* G_B29_1 = NULL;
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* G_B28_0 = NULL;
	Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* G_B28_1 = NULL;
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* G_B34_0 = NULL;
	Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* G_B34_1 = NULL;
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* G_B33_0 = NULL;
	Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* G_B33_1 = NULL;
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* G_B39_0 = NULL;
	Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* G_B39_1 = NULL;
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* G_B38_0 = NULL;
	Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* G_B38_1 = NULL;
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* G_B44_0 = NULL;
	Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* G_B44_1 = NULL;
	Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* G_B43_0 = NULL;
	Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* G_B43_1 = NULL;
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2((RuntimeObject*)__this, NULL);
		il2cpp_codegen_write_instance_field_data<int32_t>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 0),0), 0);
		InvokerActionInvoker1< Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 2)), il2cpp_rgctx_method(method->klass->rgctx_data, 2), (UniTask_1_t462EA7468BEE3A822B4D759A9930C6DF4DED6483*)___0_task1, (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)L_0);
		il2cpp_codegen_memcpy(V_0, L_0, SizeOf_Awaiter_t1CB335AE21BA160B0696B13493AFAA6006408052);
		bool L_1;
		L_1 = ((  bool (*) (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 5)))((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_0, il2cpp_rgctx_method(method->klass->rgctx_data, 5));
		V_1 = L_1;
		bool L_2 = V_1;
		if (!L_2)
		{
			goto IL_0030;
		}
	}
	{
		((  void (*) (WhenAnyPromise_9_t2D551F16D8A9A247E0C45E7698A6A7A3CCDB7757*, Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 7)))(__this, (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_0, il2cpp_rgctx_method(method->klass->rgctx_data, 7));
		goto IL_0060;
	}

IL_0030:
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->klass->rgctx_data, 11));
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_3 = ((U3CU3Ec_t41E2E5F70B53034BC7666F370C8F57BAE82ED004_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9__2_0;
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_4 = L_3;
		if (L_4)
		{
			G_B4_0 = L_4;
			G_B4_1 = ((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)(Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_0);
			goto IL_0052;
		}
		G_B3_0 = L_4;
		G_B3_1 = ((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)(Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_0);
	}
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->klass->rgctx_data, 11));
		U3CU3Ec_t41E2E5F70B53034BC7666F370C8F57BAE82ED004* L_5 = ((U3CU3Ec_t41E2E5F70B53034BC7666F370C8F57BAE82ED004_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9;
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_6 = (Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87*)il2cpp_codegen_object_new(Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87_il2cpp_TypeInfo_var);
		Action_1__ctor_m2E1DFA67718FC1A0B6E5DFEB78831FFE9C059EB4(L_6, (RuntimeObject*)L_5, (intptr_t)((void*)il2cpp_rgctx_method(method->klass->rgctx_data, 12)), NULL);
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_7 = L_6;
		((U3CU3Ec_t41E2E5F70B53034BC7666F370C8F57BAE82ED004_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9__2_0 = L_7;
		Il2CppCodeGenWriteBarrier((void**)(&((U3CU3Ec_t41E2E5F70B53034BC7666F370C8F57BAE82ED004_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9__2_0), (void*)L_7);
		G_B4_0 = L_7;
		G_B4_1 = ((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)G_B3_1);
	}

IL_0052:
	{
		il2cpp_codegen_memcpy(L_8, V_0, SizeOf_Awaiter_t1CB335AE21BA160B0696B13493AFAA6006408052);
		StateTuple_2_tBD3D2F2123018CF69F8DF69AFEC60EC71A57D234* L_9;
		L_9 = InvokerFuncInvoker2< StateTuple_2_tBD3D2F2123018CF69F8DF69AFEC60EC71A57D234*, WhenAnyPromise_9_t2D551F16D8A9A247E0C45E7698A6A7A3CCDB7757*, Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 13)), il2cpp_rgctx_method(method->klass->rgctx_data, 13), NULL, __this, L_8);
		((  void (*) (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*, Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87*, RuntimeObject*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 15)))(G_B4_1, G_B4_0, (RuntimeObject*)L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 15));
	}

IL_0060:
	{
		InvokerActionInvoker1< Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 17)), il2cpp_rgctx_method(method->klass->rgctx_data, 17), (UniTask_1_t462EA7468BEE3A822B4D759A9930C6DF4DED6483*)___1_task2, (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)L_10);
		il2cpp_codegen_memcpy(V_2, L_10, SizeOf_Awaiter_t7285A84B788050EB2963579444EEE0D82AA2776F);
		bool L_11;
		L_11 = ((  bool (*) (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 20)))((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_2, il2cpp_rgctx_method(method->klass->rgctx_data, 20));
		V_3 = L_11;
		bool L_12 = V_3;
		if (!L_12)
		{
			goto IL_0082;
		}
	}
	{
		((  void (*) (WhenAnyPromise_9_t2D551F16D8A9A247E0C45E7698A6A7A3CCDB7757*, Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 22)))(__this, (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_2, il2cpp_rgctx_method(method->klass->rgctx_data, 22));
		goto IL_00b2;
	}

IL_0082:
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->klass->rgctx_data, 11));
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_13 = ((U3CU3Ec_t41E2E5F70B53034BC7666F370C8F57BAE82ED004_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9__2_1;
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_14 = L_13;
		if (L_14)
		{
			G_B9_0 = L_14;
			G_B9_1 = ((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)(Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_2);
			goto IL_00a4;
		}
		G_B8_0 = L_14;
		G_B8_1 = ((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)(Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_2);
	}
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->klass->rgctx_data, 11));
		U3CU3Ec_t41E2E5F70B53034BC7666F370C8F57BAE82ED004* L_15 = ((U3CU3Ec_t41E2E5F70B53034BC7666F370C8F57BAE82ED004_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9;
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_16 = (Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87*)il2cpp_codegen_object_new(Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87_il2cpp_TypeInfo_var);
		Action_1__ctor_m2E1DFA67718FC1A0B6E5DFEB78831FFE9C059EB4(L_16, (RuntimeObject*)L_15, (intptr_t)((void*)il2cpp_rgctx_method(method->klass->rgctx_data, 24)), NULL);
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_17 = L_16;
		((U3CU3Ec_t41E2E5F70B53034BC7666F370C8F57BAE82ED004_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9__2_1 = L_17;
		Il2CppCodeGenWriteBarrier((void**)(&((U3CU3Ec_t41E2E5F70B53034BC7666F370C8F57BAE82ED004_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9__2_1), (void*)L_17);
		G_B9_0 = L_17;
		G_B9_1 = ((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)G_B8_1);
	}

IL_00a4:
	{
		il2cpp_codegen_memcpy(L_18, V_2, SizeOf_Awaiter_t7285A84B788050EB2963579444EEE0D82AA2776F);
		StateTuple_2_tBD3D2F2123018CF69F8DF69AFEC60EC71A57D234* L_19;
		L_19 = InvokerFuncInvoker2< StateTuple_2_tBD3D2F2123018CF69F8DF69AFEC60EC71A57D234*, WhenAnyPromise_9_t2D551F16D8A9A247E0C45E7698A6A7A3CCDB7757*, Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 25)), il2cpp_rgctx_method(method->klass->rgctx_data, 25), NULL, __this, L_18);
		((  void (*) (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*, Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87*, RuntimeObject*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 27)))(G_B9_1, G_B9_0, (RuntimeObject*)L_19, il2cpp_rgctx_method(method->klass->rgctx_data, 27));
	}

IL_00b2:
	{
		InvokerActionInvoker1< Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 29)), il2cpp_rgctx_method(method->klass->rgctx_data, 29), (UniTask_1_t462EA7468BEE3A822B4D759A9930C6DF4DED6483*)___2_task3, (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)L_20);
		il2cpp_codegen_memcpy(V_4, L_20, SizeOf_Awaiter_t8E7332A0B3890D89A55DD086A9B18D6DD097EB4A);
		bool L_21;
		L_21 = ((  bool (*) (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 32)))((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_4, il2cpp_rgctx_method(method->klass->rgctx_data, 32));
		V_5 = L_21;
		bool L_22 = V_5;
		if (!L_22)
		{
			goto IL_00d7;
		}
	}
	{
		((  void (*) (WhenAnyPromise_9_t2D551F16D8A9A247E0C45E7698A6A7A3CCDB7757*, Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 34)))(__this, (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_4, il2cpp_rgctx_method(method->klass->rgctx_data, 34));
		goto IL_0108;
	}

IL_00d7:
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->klass->rgctx_data, 11));
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_23 = ((U3CU3Ec_t41E2E5F70B53034BC7666F370C8F57BAE82ED004_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9__2_2;
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_24 = L_23;
		if (L_24)
		{
			G_B14_0 = L_24;
			G_B14_1 = ((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)(Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_4);
			goto IL_00f9;
		}
		G_B13_0 = L_24;
		G_B13_1 = ((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)(Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_4);
	}
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->klass->rgctx_data, 11));
		U3CU3Ec_t41E2E5F70B53034BC7666F370C8F57BAE82ED004* L_25 = ((U3CU3Ec_t41E2E5F70B53034BC7666F370C8F57BAE82ED004_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9;
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_26 = (Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87*)il2cpp_codegen_object_new(Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87_il2cpp_TypeInfo_var);
		Action_1__ctor_m2E1DFA67718FC1A0B6E5DFEB78831FFE9C059EB4(L_26, (RuntimeObject*)L_25, (intptr_t)((void*)il2cpp_rgctx_method(method->klass->rgctx_data, 36)), NULL);
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_27 = L_26;
		((U3CU3Ec_t41E2E5F70B53034BC7666F370C8F57BAE82ED004_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9__2_2 = L_27;
		Il2CppCodeGenWriteBarrier((void**)(&((U3CU3Ec_t41E2E5F70B53034BC7666F370C8F57BAE82ED004_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9__2_2), (void*)L_27);
		G_B14_0 = L_27;
		G_B14_1 = ((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)G_B13_1);
	}

IL_00f9:
	{
		il2cpp_codegen_memcpy(L_28, V_4, SizeOf_Awaiter_t8E7332A0B3890D89A55DD086A9B18D6DD097EB4A);
		StateTuple_2_tBD3D2F2123018CF69F8DF69AFEC60EC71A57D234* L_29;
		L_29 = InvokerFuncInvoker2< StateTuple_2_tBD3D2F2123018CF69F8DF69AFEC60EC71A57D234*, WhenAnyPromise_9_t2D551F16D8A9A247E0C45E7698A6A7A3CCDB7757*, Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 37)), il2cpp_rgctx_method(method->klass->rgctx_data, 37), NULL, __this, L_28);
		((  void (*) (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*, Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87*, RuntimeObject*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 39)))(G_B14_1, G_B14_0, (RuntimeObject*)L_29, il2cpp_rgctx_method(method->klass->rgctx_data, 39));
	}

IL_0108:
	{
		InvokerActionInvoker1< Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 41)), il2cpp_rgctx_method(method->klass->rgctx_data, 41), (UniTask_1_t462EA7468BEE3A822B4D759A9930C6DF4DED6483*)___3_task4, (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)L_30);
		il2cpp_codegen_memcpy(V_6, L_30, SizeOf_Awaiter_t2BE5DFCDDF1E1769B74EA8B9D1F1AE8AC5C6B550);
		bool L_31;
		L_31 = ((  bool (*) (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 44)))((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_6, il2cpp_rgctx_method(method->klass->rgctx_data, 44));
		V_7 = L_31;
		bool L_32 = V_7;
		if (!L_32)
		{
			goto IL_012d;
		}
	}
	{
		((  void (*) (WhenAnyPromise_9_t2D551F16D8A9A247E0C45E7698A6A7A3CCDB7757*, Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 46)))(__this, (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_6, il2cpp_rgctx_method(method->klass->rgctx_data, 46));
		goto IL_015e;
	}

IL_012d:
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->klass->rgctx_data, 11));
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_33 = ((U3CU3Ec_t41E2E5F70B53034BC7666F370C8F57BAE82ED004_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9__2_3;
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_34 = L_33;
		if (L_34)
		{
			G_B19_0 = L_34;
			G_B19_1 = ((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)(Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_6);
			goto IL_014f;
		}
		G_B18_0 = L_34;
		G_B18_1 = ((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)(Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_6);
	}
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->klass->rgctx_data, 11));
		U3CU3Ec_t41E2E5F70B53034BC7666F370C8F57BAE82ED004* L_35 = ((U3CU3Ec_t41E2E5F70B53034BC7666F370C8F57BAE82ED004_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9;
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_36 = (Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87*)il2cpp_codegen_object_new(Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87_il2cpp_TypeInfo_var);
		Action_1__ctor_m2E1DFA67718FC1A0B6E5DFEB78831FFE9C059EB4(L_36, (RuntimeObject*)L_35, (intptr_t)((void*)il2cpp_rgctx_method(method->klass->rgctx_data, 48)), NULL);
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_37 = L_36;
		((U3CU3Ec_t41E2E5F70B53034BC7666F370C8F57BAE82ED004_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9__2_3 = L_37;
		Il2CppCodeGenWriteBarrier((void**)(&((U3CU3Ec_t41E2E5F70B53034BC7666F370C8F57BAE82ED004_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9__2_3), (void*)L_37);
		G_B19_0 = L_37;
		G_B19_1 = ((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)G_B18_1);
	}

IL_014f:
	{
		il2cpp_codegen_memcpy(L_38, V_6, SizeOf_Awaiter_t2BE5DFCDDF1E1769B74EA8B9D1F1AE8AC5C6B550);
		StateTuple_2_tBD3D2F2123018CF69F8DF69AFEC60EC71A57D234* L_39;
		L_39 = InvokerFuncInvoker2< StateTuple_2_tBD3D2F2123018CF69F8DF69AFEC60EC71A57D234*, WhenAnyPromise_9_t2D551F16D8A9A247E0C45E7698A6A7A3CCDB7757*, Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 49)), il2cpp_rgctx_method(method->klass->rgctx_data, 49), NULL, __this, L_38);
		((  void (*) (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*, Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87*, RuntimeObject*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 51)))(G_B19_1, G_B19_0, (RuntimeObject*)L_39, il2cpp_rgctx_method(method->klass->rgctx_data, 51));
	}

IL_015e:
	{
		InvokerActionInvoker1< Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 53)), il2cpp_rgctx_method(method->klass->rgctx_data, 53), (UniTask_1_t462EA7468BEE3A822B4D759A9930C6DF4DED6483*)___4_task5, (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)L_40);
		il2cpp_codegen_memcpy(V_8, L_40, SizeOf_Awaiter_tCCA67F4A21F8DC391E99818FBBE3F4C47FD52AF7);
		bool L_41;
		L_41 = ((  bool (*) (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 56)))((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_8, il2cpp_rgctx_method(method->klass->rgctx_data, 56));
		V_9 = L_41;
		bool L_42 = V_9;
		if (!L_42)
		{
			goto IL_0183;
		}
	}
	{
		((  void (*) (WhenAnyPromise_9_t2D551F16D8A9A247E0C45E7698A6A7A3CCDB7757*, Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 58)))(__this, (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_8, il2cpp_rgctx_method(method->klass->rgctx_data, 58));
		goto IL_01b4;
	}

IL_0183:
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->klass->rgctx_data, 11));
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_43 = ((U3CU3Ec_t41E2E5F70B53034BC7666F370C8F57BAE82ED004_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9__2_4;
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_44 = L_43;
		if (L_44)
		{
			G_B24_0 = L_44;
			G_B24_1 = ((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)(Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_8);
			goto IL_01a5;
		}
		G_B23_0 = L_44;
		G_B23_1 = ((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)(Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_8);
	}
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->klass->rgctx_data, 11));
		U3CU3Ec_t41E2E5F70B53034BC7666F370C8F57BAE82ED004* L_45 = ((U3CU3Ec_t41E2E5F70B53034BC7666F370C8F57BAE82ED004_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9;
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_46 = (Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87*)il2cpp_codegen_object_new(Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87_il2cpp_TypeInfo_var);
		Action_1__ctor_m2E1DFA67718FC1A0B6E5DFEB78831FFE9C059EB4(L_46, (RuntimeObject*)L_45, (intptr_t)((void*)il2cpp_rgctx_method(method->klass->rgctx_data, 60)), NULL);
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_47 = L_46;
		((U3CU3Ec_t41E2E5F70B53034BC7666F370C8F57BAE82ED004_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9__2_4 = L_47;
		Il2CppCodeGenWriteBarrier((void**)(&((U3CU3Ec_t41E2E5F70B53034BC7666F370C8F57BAE82ED004_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9__2_4), (void*)L_47);
		G_B24_0 = L_47;
		G_B24_1 = ((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)G_B23_1);
	}

IL_01a5:
	{
		il2cpp_codegen_memcpy(L_48, V_8, SizeOf_Awaiter_tCCA67F4A21F8DC391E99818FBBE3F4C47FD52AF7);
		StateTuple_2_tBD3D2F2123018CF69F8DF69AFEC60EC71A57D234* L_49;
		L_49 = InvokerFuncInvoker2< StateTuple_2_tBD3D2F2123018CF69F8DF69AFEC60EC71A57D234*, WhenAnyPromise_9_t2D551F16D8A9A247E0C45E7698A6A7A3CCDB7757*, Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 61)), il2cpp_rgctx_method(method->klass->rgctx_data, 61), NULL, __this, L_48);
		((  void (*) (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*, Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87*, RuntimeObject*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 63)))(G_B24_1, G_B24_0, (RuntimeObject*)L_49, il2cpp_rgctx_method(method->klass->rgctx_data, 63));
	}

IL_01b4:
	{
		InvokerActionInvoker1< Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 65)), il2cpp_rgctx_method(method->klass->rgctx_data, 65), (UniTask_1_t462EA7468BEE3A822B4D759A9930C6DF4DED6483*)___5_task6, (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)L_50);
		il2cpp_codegen_memcpy(V_10, L_50, SizeOf_Awaiter_t51D8578ADFDB9DDED327CC3488B7EAEF664DB387);
		bool L_51;
		L_51 = ((  bool (*) (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 68)))((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_10, il2cpp_rgctx_method(method->klass->rgctx_data, 68));
		V_11 = L_51;
		bool L_52 = V_11;
		if (!L_52)
		{
			goto IL_01d9;
		}
	}
	{
		((  void (*) (WhenAnyPromise_9_t2D551F16D8A9A247E0C45E7698A6A7A3CCDB7757*, Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 70)))(__this, (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_10, il2cpp_rgctx_method(method->klass->rgctx_data, 70));
		goto IL_020a;
	}

IL_01d9:
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->klass->rgctx_data, 11));
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_53 = ((U3CU3Ec_t41E2E5F70B53034BC7666F370C8F57BAE82ED004_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9__2_5;
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_54 = L_53;
		if (L_54)
		{
			G_B29_0 = L_54;
			G_B29_1 = ((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)(Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_10);
			goto IL_01fb;
		}
		G_B28_0 = L_54;
		G_B28_1 = ((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)(Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_10);
	}
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->klass->rgctx_data, 11));
		U3CU3Ec_t41E2E5F70B53034BC7666F370C8F57BAE82ED004* L_55 = ((U3CU3Ec_t41E2E5F70B53034BC7666F370C8F57BAE82ED004_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9;
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_56 = (Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87*)il2cpp_codegen_object_new(Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87_il2cpp_TypeInfo_var);
		Action_1__ctor_m2E1DFA67718FC1A0B6E5DFEB78831FFE9C059EB4(L_56, (RuntimeObject*)L_55, (intptr_t)((void*)il2cpp_rgctx_method(method->klass->rgctx_data, 72)), NULL);
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_57 = L_56;
		((U3CU3Ec_t41E2E5F70B53034BC7666F370C8F57BAE82ED004_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9__2_5 = L_57;
		Il2CppCodeGenWriteBarrier((void**)(&((U3CU3Ec_t41E2E5F70B53034BC7666F370C8F57BAE82ED004_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9__2_5), (void*)L_57);
		G_B29_0 = L_57;
		G_B29_1 = ((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)G_B28_1);
	}

IL_01fb:
	{
		il2cpp_codegen_memcpy(L_58, V_10, SizeOf_Awaiter_t51D8578ADFDB9DDED327CC3488B7EAEF664DB387);
		StateTuple_2_tBD3D2F2123018CF69F8DF69AFEC60EC71A57D234* L_59;
		L_59 = InvokerFuncInvoker2< StateTuple_2_tBD3D2F2123018CF69F8DF69AFEC60EC71A57D234*, WhenAnyPromise_9_t2D551F16D8A9A247E0C45E7698A6A7A3CCDB7757*, Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 73)), il2cpp_rgctx_method(method->klass->rgctx_data, 73), NULL, __this, L_58);
		((  void (*) (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*, Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87*, RuntimeObject*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 75)))(G_B29_1, G_B29_0, (RuntimeObject*)L_59, il2cpp_rgctx_method(method->klass->rgctx_data, 75));
	}

IL_020a:
	{
		InvokerActionInvoker1< Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 77)), il2cpp_rgctx_method(method->klass->rgctx_data, 77), (UniTask_1_t462EA7468BEE3A822B4D759A9930C6DF4DED6483*)___6_task7, (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)L_60);
		il2cpp_codegen_memcpy(V_12, L_60, SizeOf_Awaiter_tF45E6AA0F09CC1C94B66E16FB5ED0D7C231BCDC2);
		bool L_61;
		L_61 = ((  bool (*) (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 80)))((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_12, il2cpp_rgctx_method(method->klass->rgctx_data, 80));
		V_13 = L_61;
		bool L_62 = V_13;
		if (!L_62)
		{
			goto IL_022f;
		}
	}
	{
		((  void (*) (WhenAnyPromise_9_t2D551F16D8A9A247E0C45E7698A6A7A3CCDB7757*, Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 82)))(__this, (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_12, il2cpp_rgctx_method(method->klass->rgctx_data, 82));
		goto IL_0260;
	}

IL_022f:
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->klass->rgctx_data, 11));
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_63 = ((U3CU3Ec_t41E2E5F70B53034BC7666F370C8F57BAE82ED004_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9__2_6;
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_64 = L_63;
		if (L_64)
		{
			G_B34_0 = L_64;
			G_B34_1 = ((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)(Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_12);
			goto IL_0251;
		}
		G_B33_0 = L_64;
		G_B33_1 = ((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)(Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_12);
	}
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->klass->rgctx_data, 11));
		U3CU3Ec_t41E2E5F70B53034BC7666F370C8F57BAE82ED004* L_65 = ((U3CU3Ec_t41E2E5F70B53034BC7666F370C8F57BAE82ED004_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9;
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_66 = (Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87*)il2cpp_codegen_object_new(Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87_il2cpp_TypeInfo_var);
		Action_1__ctor_m2E1DFA67718FC1A0B6E5DFEB78831FFE9C059EB4(L_66, (RuntimeObject*)L_65, (intptr_t)((void*)il2cpp_rgctx_method(method->klass->rgctx_data, 84)), NULL);
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_67 = L_66;
		((U3CU3Ec_t41E2E5F70B53034BC7666F370C8F57BAE82ED004_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9__2_6 = L_67;
		Il2CppCodeGenWriteBarrier((void**)(&((U3CU3Ec_t41E2E5F70B53034BC7666F370C8F57BAE82ED004_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9__2_6), (void*)L_67);
		G_B34_0 = L_67;
		G_B34_1 = ((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)G_B33_1);
	}

IL_0251:
	{
		il2cpp_codegen_memcpy(L_68, V_12, SizeOf_Awaiter_tF45E6AA0F09CC1C94B66E16FB5ED0D7C231BCDC2);
		StateTuple_2_tBD3D2F2123018CF69F8DF69AFEC60EC71A57D234* L_69;
		L_69 = InvokerFuncInvoker2< StateTuple_2_tBD3D2F2123018CF69F8DF69AFEC60EC71A57D234*, WhenAnyPromise_9_t2D551F16D8A9A247E0C45E7698A6A7A3CCDB7757*, Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 85)), il2cpp_rgctx_method(method->klass->rgctx_data, 85), NULL, __this, L_68);
		((  void (*) (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*, Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87*, RuntimeObject*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 87)))(G_B34_1, G_B34_0, (RuntimeObject*)L_69, il2cpp_rgctx_method(method->klass->rgctx_data, 87));
	}

IL_0260:
	{
		InvokerActionInvoker1< Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 89)), il2cpp_rgctx_method(method->klass->rgctx_data, 89), (UniTask_1_t462EA7468BEE3A822B4D759A9930C6DF4DED6483*)___7_task8, (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)L_70);
		il2cpp_codegen_memcpy(V_14, L_70, SizeOf_Awaiter_t9A2F748C83EE5745F31F629DBC0C26AE0B45F342);
		bool L_71;
		L_71 = ((  bool (*) (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 92)))((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_14, il2cpp_rgctx_method(method->klass->rgctx_data, 92));
		V_15 = L_71;
		bool L_72 = V_15;
		if (!L_72)
		{
			goto IL_0285;
		}
	}
	{
		((  void (*) (WhenAnyPromise_9_t2D551F16D8A9A247E0C45E7698A6A7A3CCDB7757*, Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 94)))(__this, (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_14, il2cpp_rgctx_method(method->klass->rgctx_data, 94));
		goto IL_02b6;
	}

IL_0285:
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->klass->rgctx_data, 11));
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_73 = ((U3CU3Ec_t41E2E5F70B53034BC7666F370C8F57BAE82ED004_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9__2_7;
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_74 = L_73;
		if (L_74)
		{
			G_B39_0 = L_74;
			G_B39_1 = ((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)(Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_14);
			goto IL_02a7;
		}
		G_B38_0 = L_74;
		G_B38_1 = ((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)(Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_14);
	}
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->klass->rgctx_data, 11));
		U3CU3Ec_t41E2E5F70B53034BC7666F370C8F57BAE82ED004* L_75 = ((U3CU3Ec_t41E2E5F70B53034BC7666F370C8F57BAE82ED004_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9;
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_76 = (Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87*)il2cpp_codegen_object_new(Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87_il2cpp_TypeInfo_var);
		Action_1__ctor_m2E1DFA67718FC1A0B6E5DFEB78831FFE9C059EB4(L_76, (RuntimeObject*)L_75, (intptr_t)((void*)il2cpp_rgctx_method(method->klass->rgctx_data, 96)), NULL);
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_77 = L_76;
		((U3CU3Ec_t41E2E5F70B53034BC7666F370C8F57BAE82ED004_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9__2_7 = L_77;
		Il2CppCodeGenWriteBarrier((void**)(&((U3CU3Ec_t41E2E5F70B53034BC7666F370C8F57BAE82ED004_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9__2_7), (void*)L_77);
		G_B39_0 = L_77;
		G_B39_1 = ((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)G_B38_1);
	}

IL_02a7:
	{
		il2cpp_codegen_memcpy(L_78, V_14, SizeOf_Awaiter_t9A2F748C83EE5745F31F629DBC0C26AE0B45F342);
		StateTuple_2_tBD3D2F2123018CF69F8DF69AFEC60EC71A57D234* L_79;
		L_79 = InvokerFuncInvoker2< StateTuple_2_tBD3D2F2123018CF69F8DF69AFEC60EC71A57D234*, WhenAnyPromise_9_t2D551F16D8A9A247E0C45E7698A6A7A3CCDB7757*, Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 97)), il2cpp_rgctx_method(method->klass->rgctx_data, 97), NULL, __this, L_78);
		((  void (*) (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*, Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87*, RuntimeObject*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 99)))(G_B39_1, G_B39_0, (RuntimeObject*)L_79, il2cpp_rgctx_method(method->klass->rgctx_data, 99));
	}

IL_02b6:
	{
		InvokerActionInvoker1< Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 101)), il2cpp_rgctx_method(method->klass->rgctx_data, 101), (UniTask_1_t462EA7468BEE3A822B4D759A9930C6DF4DED6483*)___8_task9, (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)L_80);
		il2cpp_codegen_memcpy(V_16, L_80, SizeOf_Awaiter_t2BEBEFE73CAAEF9B13D5D3047C346979ED99C61E);
		bool L_81;
		L_81 = ((  bool (*) (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 104)))((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_16, il2cpp_rgctx_method(method->klass->rgctx_data, 104));
		V_17 = L_81;
		bool L_82 = V_17;
		if (!L_82)
		{
			goto IL_02db;
		}
	}
	{
		((  void (*) (WhenAnyPromise_9_t2D551F16D8A9A247E0C45E7698A6A7A3CCDB7757*, Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 106)))(__this, (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_16, il2cpp_rgctx_method(method->klass->rgctx_data, 106));
		goto IL_030c;
	}

IL_02db:
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->klass->rgctx_data, 11));
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_83 = ((U3CU3Ec_t41E2E5F70B53034BC7666F370C8F57BAE82ED004_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9__2_8;
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_84 = L_83;
		if (L_84)
		{
			G_B44_0 = L_84;
			G_B44_1 = ((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)(Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_16);
			goto IL_02fd;
		}
		G_B43_0 = L_84;
		G_B43_1 = ((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)(Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)V_16);
	}
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->klass->rgctx_data, 11));
		U3CU3Ec_t41E2E5F70B53034BC7666F370C8F57BAE82ED004* L_85 = ((U3CU3Ec_t41E2E5F70B53034BC7666F370C8F57BAE82ED004_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9;
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_86 = (Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87*)il2cpp_codegen_object_new(Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87_il2cpp_TypeInfo_var);
		Action_1__ctor_m2E1DFA67718FC1A0B6E5DFEB78831FFE9C059EB4(L_86, (RuntimeObject*)L_85, (intptr_t)((void*)il2cpp_rgctx_method(method->klass->rgctx_data, 108)), NULL);
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_87 = L_86;
		((U3CU3Ec_t41E2E5F70B53034BC7666F370C8F57BAE82ED004_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9__2_8 = L_87;
		Il2CppCodeGenWriteBarrier((void**)(&((U3CU3Ec_t41E2E5F70B53034BC7666F370C8F57BAE82ED004_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->klass->rgctx_data, 11)))->___U3CU3E9__2_8), (void*)L_87);
		G_B44_0 = L_87;
		G_B44_1 = ((Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*)G_B43_1);
	}

IL_02fd:
	{
		il2cpp_codegen_memcpy(L_88, V_16, SizeOf_Awaiter_t2BEBEFE73CAAEF9B13D5D3047C346979ED99C61E);
		StateTuple_2_tBD3D2F2123018CF69F8DF69AFEC60EC71A57D234* L_89;
		L_89 = InvokerFuncInvoker2< StateTuple_2_tBD3D2F2123018CF69F8DF69AFEC60EC71A57D234*, WhenAnyPromise_9_t2D551F16D8A9A247E0C45E7698A6A7A3CCDB7757*, Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 109)), il2cpp_rgctx_method(method->klass->rgctx_data, 109), NULL, __this, L_88);
		((  void (*) (Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C*, Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87*, RuntimeObject*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 111)))(G_B44_1, G_B44_0, (RuntimeObject*)L_89, il2cpp_rgctx_method(method->klass->rgctx_data, 111));
	}

IL_030c:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhenAnyPromise_9_TryInvokeContinuationT1_m057E8851EC36E71467FBB33A797A57F7D1333531_gshared (WhenAnyPromise_9_t2D551F16D8A9A247E0C45E7698A6A7A3CCDB7757* ___0_self, Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* ___1_awaiter, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T1_t12224CDB8CF3A7A9B85AE3735573C8F4E483F5C8 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 113));
	const uint32_t SizeOf_T2_tAD4D518AD8F8B278644DA50484CBC022467C03C8 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 117));
	const uint32_t SizeOf_T3_t66D9D606A6E8AE1FFD2214BAC540BA2C6A05F30E = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 118));
	const uint32_t SizeOf_T4_t72EE5E3145D8FF5738B17FFF6A56CD3596448171 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 119));
	const uint32_t SizeOf_T5_tBAA81B6ABC55C264673BFAB9E6595906EACF4385 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 120));
	const uint32_t SizeOf_T6_tDBE701EEE385225ABD2D5FE3A33BBB44DAB77FA1 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 121));
	const uint32_t SizeOf_T7_tB1C7E0C236178B74109F4EF31E447F56A86DBA34 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 122));
	const uint32_t SizeOf_T8_tAF9A0784F75559C808ECBC453336127EB8DA3A7A = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 123));
	const uint32_t SizeOf_T9_tB9C3488598121213AB36E222281D28C99542EDB2 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 124));
	const uint32_t SizeOf_ValueTuple_3_t296AC28BABFD66CC8A156720B3F2B3437143A60F = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 125));
	const uint32_t SizeOf_ValueTuple_8_t8393F807A09311AE5C3F77F38D87FF98B57A7A47 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 127));
	const Il2CppFullySharedGenericAny L_1 = alloca(SizeOf_T1_t12224CDB8CF3A7A9B85AE3735573C8F4E483F5C8);
	const Il2CppFullySharedGenericAny L_10 = L_1;
	const Il2CppFullySharedGenericAny L_23 = alloca(SizeOf_T1_t12224CDB8CF3A7A9B85AE3735573C8F4E483F5C8);
	const Il2CppFullySharedGenericAny L_11 = alloca(SizeOf_T2_tAD4D518AD8F8B278644DA50484CBC022467C03C8);
	const Il2CppFullySharedGenericAny L_24 = alloca(SizeOf_T2_tAD4D518AD8F8B278644DA50484CBC022467C03C8);
	const Il2CppFullySharedGenericAny L_12 = alloca(SizeOf_T3_t66D9D606A6E8AE1FFD2214BAC540BA2C6A05F30E);
	const Il2CppFullySharedGenericAny L_25 = alloca(SizeOf_T3_t66D9D606A6E8AE1FFD2214BAC540BA2C6A05F30E);
	const Il2CppFullySharedGenericAny L_13 = alloca(SizeOf_T4_t72EE5E3145D8FF5738B17FFF6A56CD3596448171);
	const Il2CppFullySharedGenericAny L_26 = alloca(SizeOf_T4_t72EE5E3145D8FF5738B17FFF6A56CD3596448171);
	const Il2CppFullySharedGenericAny L_14 = alloca(SizeOf_T5_tBAA81B6ABC55C264673BFAB9E6595906EACF4385);
	const Il2CppFullySharedGenericAny L_27 = alloca(SizeOf_T5_tBAA81B6ABC55C264673BFAB9E6595906EACF4385);
	const Il2CppFullySharedGenericAny L_15 = alloca(SizeOf_T6_tDBE701EEE385225ABD2D5FE3A33BBB44DAB77FA1);
	const Il2CppFullySharedGenericAny L_28 = alloca(SizeOf_T6_tDBE701EEE385225ABD2D5FE3A33BBB44DAB77FA1);
	const Il2CppFullySharedGenericAny L_16 = alloca(SizeOf_T7_tB1C7E0C236178B74109F4EF31E447F56A86DBA34);
	const Il2CppFullySharedGenericAny L_19 = alloca(SizeOf_T7_tB1C7E0C236178B74109F4EF31E447F56A86DBA34);
	const Il2CppFullySharedGenericAny L_17 = alloca(SizeOf_T8_tAF9A0784F75559C808ECBC453336127EB8DA3A7A);
	const Il2CppFullySharedGenericAny L_20 = alloca(SizeOf_T8_tAF9A0784F75559C808ECBC453336127EB8DA3A7A);
	const Il2CppFullySharedGenericAny L_18 = alloca(SizeOf_T9_tB9C3488598121213AB36E222281D28C99542EDB2);
	const Il2CppFullySharedGenericAny L_21 = alloca(SizeOf_T9_tB9C3488598121213AB36E222281D28C99542EDB2);
	const ValueTuple_3_t182F852EE39DD805E380FD93762C931C933ACE98 L_22 = alloca(SizeOf_ValueTuple_3_t296AC28BABFD66CC8A156720B3F2B3437143A60F);
	const ValueTuple_3_t182F852EE39DD805E380FD93762C931C933ACE98 L_29 = alloca(SizeOf_ValueTuple_3_t296AC28BABFD66CC8A156720B3F2B3437143A60F);
	const ValueTuple_8_tF94FE992101922E2A97F08D019A9EBDDA748DCB2 L_30 = alloca(SizeOf_ValueTuple_8_t8393F807A09311AE5C3F77F38D87FF98B57A7A47);
	Il2CppFullySharedGenericAny V_0 = alloca(SizeOf_T1_t12224CDB8CF3A7A9B85AE3735573C8F4E483F5C8);
	memset(V_0, 0, SizeOf_T1_t12224CDB8CF3A7A9B85AE3735573C8F4E483F5C8);
	Exception_t* V_1 = NULL;
	bool V_2 = false;
	Il2CppFullySharedGenericAny V_3 = alloca(SizeOf_T2_tAD4D518AD8F8B278644DA50484CBC022467C03C8);
	memset(V_3, 0, SizeOf_T2_tAD4D518AD8F8B278644DA50484CBC022467C03C8);
	Il2CppFullySharedGenericAny V_4 = alloca(SizeOf_T3_t66D9D606A6E8AE1FFD2214BAC540BA2C6A05F30E);
	memset(V_4, 0, SizeOf_T3_t66D9D606A6E8AE1FFD2214BAC540BA2C6A05F30E);
	Il2CppFullySharedGenericAny V_5 = alloca(SizeOf_T4_t72EE5E3145D8FF5738B17FFF6A56CD3596448171);
	memset(V_5, 0, SizeOf_T4_t72EE5E3145D8FF5738B17FFF6A56CD3596448171);
	Il2CppFullySharedGenericAny V_6 = alloca(SizeOf_T5_tBAA81B6ABC55C264673BFAB9E6595906EACF4385);
	memset(V_6, 0, SizeOf_T5_tBAA81B6ABC55C264673BFAB9E6595906EACF4385);
	Il2CppFullySharedGenericAny V_7 = alloca(SizeOf_T6_tDBE701EEE385225ABD2D5FE3A33BBB44DAB77FA1);
	memset(V_7, 0, SizeOf_T6_tDBE701EEE385225ABD2D5FE3A33BBB44DAB77FA1);
	Il2CppFullySharedGenericAny V_8 = alloca(SizeOf_T7_tB1C7E0C236178B74109F4EF31E447F56A86DBA34);
	memset(V_8, 0, SizeOf_T7_tB1C7E0C236178B74109F4EF31E447F56A86DBA34);
	Il2CppFullySharedGenericAny V_9 = alloca(SizeOf_T8_tAF9A0784F75559C808ECBC453336127EB8DA3A7A);
	memset(V_9, 0, SizeOf_T8_tAF9A0784F75559C808ECBC453336127EB8DA3A7A);
	Il2CppFullySharedGenericAny V_10 = alloca(SizeOf_T9_tB9C3488598121213AB36E222281D28C99542EDB2);
	memset(V_10, 0, SizeOf_T9_tB9C3488598121213AB36E222281D28C99542EDB2);
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
	}
	try
	{
		Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* L_0 = ___1_awaiter;
		InvokerActionInvoker1< Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 112)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 112), L_0, (Il2CppFullySharedGenericAny*)L_1);
		il2cpp_codegen_memcpy(V_0, L_1, SizeOf_T1_t12224CDB8CF3A7A9B85AE3735573C8F4E483F5C8);
		goto IL_001d;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&Exception_t_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_000c;
		}
		throw e;
	}

CATCH_000c:
	{
		Exception_t* L_2 = ((Exception_t*)IL2CPP_GET_ACTIVE_EXCEPTION(Exception_t*));;
		V_1 = L_2;
		WhenAnyPromise_9_t2D551F16D8A9A247E0C45E7698A6A7A3CCDB7757* L_3 = ___0_self;
		Exception_t* L_4 = V_1;
		bool L_5;
		L_5 = ((  bool (*) (UniTaskCompletionSourceCore_1_t1911EC18C6234A1A4E814CB064F127B40A3F2BD1*, Exception_t*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 115)))((((UniTaskCompletionSourceCore_1_t1911EC18C6234A1A4E814CB064F127B40A3F2BD1*)il2cpp_codegen_get_instance_field_data_pointer(L_3, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),1)))), L_4, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 115));
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_0098;
	}

IL_001d:
	{
		WhenAnyPromise_9_t2D551F16D8A9A247E0C45E7698A6A7A3CCDB7757* L_6 = ___0_self;
		int32_t L_7;
		L_7 = Interlocked_Increment_m3C240C32E8D9544EC050B74D4F28EEB58F1F9309((((int32_t*)il2cpp_codegen_get_instance_field_data_pointer(L_6, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),0)))), NULL);
		V_2 = (bool)((((int32_t)L_7) == ((int32_t)1))? 1 : 0);
		bool L_8 = V_2;
		if (!L_8)
		{
			goto IL_0098;
		}
	}
	{
		WhenAnyPromise_9_t2D551F16D8A9A247E0C45E7698A6A7A3CCDB7757* L_9 = ___0_self;
		il2cpp_codegen_memcpy(L_10, V_0, SizeOf_T1_t12224CDB8CF3A7A9B85AE3735573C8F4E483F5C8);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_3, SizeOf_T2_tAD4D518AD8F8B278644DA50484CBC022467C03C8);
		il2cpp_codegen_memcpy(L_11, V_3, SizeOf_T2_tAD4D518AD8F8B278644DA50484CBC022467C03C8);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_4, SizeOf_T3_t66D9D606A6E8AE1FFD2214BAC540BA2C6A05F30E);
		il2cpp_codegen_memcpy(L_12, V_4, SizeOf_T3_t66D9D606A6E8AE1FFD2214BAC540BA2C6A05F30E);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_5, SizeOf_T4_t72EE5E3145D8FF5738B17FFF6A56CD3596448171);
		il2cpp_codegen_memcpy(L_13, V_5, SizeOf_T4_t72EE5E3145D8FF5738B17FFF6A56CD3596448171);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_6, SizeOf_T5_tBAA81B6ABC55C264673BFAB9E6595906EACF4385);
		il2cpp_codegen_memcpy(L_14, V_6, SizeOf_T5_tBAA81B6ABC55C264673BFAB9E6595906EACF4385);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_7, SizeOf_T6_tDBE701EEE385225ABD2D5FE3A33BBB44DAB77FA1);
		il2cpp_codegen_memcpy(L_15, V_7, SizeOf_T6_tDBE701EEE385225ABD2D5FE3A33BBB44DAB77FA1);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_8, SizeOf_T7_tB1C7E0C236178B74109F4EF31E447F56A86DBA34);
		il2cpp_codegen_memcpy(L_16, V_8, SizeOf_T7_tB1C7E0C236178B74109F4EF31E447F56A86DBA34);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_9, SizeOf_T8_tAF9A0784F75559C808ECBC453336127EB8DA3A7A);
		il2cpp_codegen_memcpy(L_17, V_9, SizeOf_T8_tAF9A0784F75559C808ECBC453336127EB8DA3A7A);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_10, SizeOf_T9_tB9C3488598121213AB36E222281D28C99542EDB2);
		il2cpp_codegen_memcpy(L_18, V_10, SizeOf_T9_tB9C3488598121213AB36E222281D28C99542EDB2);
		memset(L_22, 0, SizeOf_ValueTuple_3_t296AC28BABFD66CC8A156720B3F2B3437143A60F);
		ValueTuple_3__ctor_mAB800E7134D8E52646FD55A8B2979AC908028759((ValueTuple_3_t182F852EE39DD805E380FD93762C931C933ACE98*)L_22, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 122)) ? il2cpp_codegen_memcpy(L_19, L_16, SizeOf_T7_tB1C7E0C236178B74109F4EF31E447F56A86DBA34): *(void**)L_16), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 123)) ? il2cpp_codegen_memcpy(L_20, L_17, SizeOf_T8_tAF9A0784F75559C808ECBC453336127EB8DA3A7A): *(void**)L_17), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 124)) ? il2cpp_codegen_memcpy(L_21, L_18, SizeOf_T9_tB9C3488598121213AB36E222281D28C99542EDB2): *(void**)L_18), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 126));
		memset(L_30, 0, SizeOf_ValueTuple_8_t8393F807A09311AE5C3F77F38D87FF98B57A7A47);
		ValueTuple_8__ctor_m5FDE8CF38A97A3D5FC7C364C3467B819664360EE((ValueTuple_8_tF94FE992101922E2A97F08D019A9EBDDA748DCB2*)L_30, 0, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 113)) ? il2cpp_codegen_memcpy(L_23, L_10, SizeOf_T1_t12224CDB8CF3A7A9B85AE3735573C8F4E483F5C8): *(void**)L_10), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 117)) ? il2cpp_codegen_memcpy(L_24, L_11, SizeOf_T2_tAD4D518AD8F8B278644DA50484CBC022467C03C8): *(void**)L_11), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 118)) ? il2cpp_codegen_memcpy(L_25, L_12, SizeOf_T3_t66D9D606A6E8AE1FFD2214BAC540BA2C6A05F30E): *(void**)L_12), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 119)) ? il2cpp_codegen_memcpy(L_26, L_13, SizeOf_T4_t72EE5E3145D8FF5738B17FFF6A56CD3596448171): *(void**)L_13), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 120)) ? il2cpp_codegen_memcpy(L_27, L_14, SizeOf_T5_tBAA81B6ABC55C264673BFAB9E6595906EACF4385): *(void**)L_14), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 121)) ? il2cpp_codegen_memcpy(L_28, L_15, SizeOf_T6_tDBE701EEE385225ABD2D5FE3A33BBB44DAB77FA1): *(void**)L_15), il2cpp_codegen_memcpy(L_29, L_22, SizeOf_ValueTuple_3_t296AC28BABFD66CC8A156720B3F2B3437143A60F), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 128));
		bool L_31;
		L_31 = InvokerFuncInvoker1< bool, ValueTuple_8_tF94FE992101922E2A97F08D019A9EBDDA748DCB2 >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 129)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 129), (((UniTaskCompletionSourceCore_1_t1911EC18C6234A1A4E814CB064F127B40A3F2BD1*)il2cpp_codegen_get_instance_field_data_pointer(L_9, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),1)))), L_30);
	}

IL_0098:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhenAnyPromise_9_TryInvokeContinuationT2_mFA8CDBC833AB4DE9119E70BBA8E9E16888DB8E44_gshared (WhenAnyPromise_9_t2D551F16D8A9A247E0C45E7698A6A7A3CCDB7757* ___0_self, Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* ___1_awaiter, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T2_tAD4D518AD8F8B278644DA50484CBC022467C03C8 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 117));
	const uint32_t SizeOf_T1_t12224CDB8CF3A7A9B85AE3735573C8F4E483F5C8 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 113));
	const uint32_t SizeOf_T3_t66D9D606A6E8AE1FFD2214BAC540BA2C6A05F30E = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 118));
	const uint32_t SizeOf_T4_t72EE5E3145D8FF5738B17FFF6A56CD3596448171 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 119));
	const uint32_t SizeOf_T5_tBAA81B6ABC55C264673BFAB9E6595906EACF4385 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 120));
	const uint32_t SizeOf_T6_tDBE701EEE385225ABD2D5FE3A33BBB44DAB77FA1 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 121));
	const uint32_t SizeOf_T7_tB1C7E0C236178B74109F4EF31E447F56A86DBA34 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 122));
	const uint32_t SizeOf_T8_tAF9A0784F75559C808ECBC453336127EB8DA3A7A = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 123));
	const uint32_t SizeOf_T9_tB9C3488598121213AB36E222281D28C99542EDB2 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 124));
	const uint32_t SizeOf_ValueTuple_3_t296AC28BABFD66CC8A156720B3F2B3437143A60F = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 125));
	const uint32_t SizeOf_ValueTuple_8_t8393F807A09311AE5C3F77F38D87FF98B57A7A47 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 127));
	const Il2CppFullySharedGenericAny L_10 = alloca(SizeOf_T1_t12224CDB8CF3A7A9B85AE3735573C8F4E483F5C8);
	const Il2CppFullySharedGenericAny L_23 = alloca(SizeOf_T1_t12224CDB8CF3A7A9B85AE3735573C8F4E483F5C8);
	const Il2CppFullySharedGenericAny L_1 = alloca(SizeOf_T2_tAD4D518AD8F8B278644DA50484CBC022467C03C8);
	const Il2CppFullySharedGenericAny L_11 = L_1;
	const Il2CppFullySharedGenericAny L_24 = alloca(SizeOf_T2_tAD4D518AD8F8B278644DA50484CBC022467C03C8);
	const Il2CppFullySharedGenericAny L_12 = alloca(SizeOf_T3_t66D9D606A6E8AE1FFD2214BAC540BA2C6A05F30E);
	const Il2CppFullySharedGenericAny L_25 = alloca(SizeOf_T3_t66D9D606A6E8AE1FFD2214BAC540BA2C6A05F30E);
	const Il2CppFullySharedGenericAny L_13 = alloca(SizeOf_T4_t72EE5E3145D8FF5738B17FFF6A56CD3596448171);
	const Il2CppFullySharedGenericAny L_26 = alloca(SizeOf_T4_t72EE5E3145D8FF5738B17FFF6A56CD3596448171);
	const Il2CppFullySharedGenericAny L_14 = alloca(SizeOf_T5_tBAA81B6ABC55C264673BFAB9E6595906EACF4385);
	const Il2CppFullySharedGenericAny L_27 = alloca(SizeOf_T5_tBAA81B6ABC55C264673BFAB9E6595906EACF4385);
	const Il2CppFullySharedGenericAny L_15 = alloca(SizeOf_T6_tDBE701EEE385225ABD2D5FE3A33BBB44DAB77FA1);
	const Il2CppFullySharedGenericAny L_28 = alloca(SizeOf_T6_tDBE701EEE385225ABD2D5FE3A33BBB44DAB77FA1);
	const Il2CppFullySharedGenericAny L_16 = alloca(SizeOf_T7_tB1C7E0C236178B74109F4EF31E447F56A86DBA34);
	const Il2CppFullySharedGenericAny L_19 = alloca(SizeOf_T7_tB1C7E0C236178B74109F4EF31E447F56A86DBA34);
	const Il2CppFullySharedGenericAny L_17 = alloca(SizeOf_T8_tAF9A0784F75559C808ECBC453336127EB8DA3A7A);
	const Il2CppFullySharedGenericAny L_20 = alloca(SizeOf_T8_tAF9A0784F75559C808ECBC453336127EB8DA3A7A);
	const Il2CppFullySharedGenericAny L_18 = alloca(SizeOf_T9_tB9C3488598121213AB36E222281D28C99542EDB2);
	const Il2CppFullySharedGenericAny L_21 = alloca(SizeOf_T9_tB9C3488598121213AB36E222281D28C99542EDB2);
	const ValueTuple_3_t182F852EE39DD805E380FD93762C931C933ACE98 L_22 = alloca(SizeOf_ValueTuple_3_t296AC28BABFD66CC8A156720B3F2B3437143A60F);
	const ValueTuple_3_t182F852EE39DD805E380FD93762C931C933ACE98 L_29 = alloca(SizeOf_ValueTuple_3_t296AC28BABFD66CC8A156720B3F2B3437143A60F);
	const ValueTuple_8_tF94FE992101922E2A97F08D019A9EBDDA748DCB2 L_30 = alloca(SizeOf_ValueTuple_8_t8393F807A09311AE5C3F77F38D87FF98B57A7A47);
	Il2CppFullySharedGenericAny V_0 = alloca(SizeOf_T2_tAD4D518AD8F8B278644DA50484CBC022467C03C8);
	memset(V_0, 0, SizeOf_T2_tAD4D518AD8F8B278644DA50484CBC022467C03C8);
	Exception_t* V_1 = NULL;
	bool V_2 = false;
	Il2CppFullySharedGenericAny V_3 = alloca(SizeOf_T1_t12224CDB8CF3A7A9B85AE3735573C8F4E483F5C8);
	memset(V_3, 0, SizeOf_T1_t12224CDB8CF3A7A9B85AE3735573C8F4E483F5C8);
	Il2CppFullySharedGenericAny V_4 = alloca(SizeOf_T3_t66D9D606A6E8AE1FFD2214BAC540BA2C6A05F30E);
	memset(V_4, 0, SizeOf_T3_t66D9D606A6E8AE1FFD2214BAC540BA2C6A05F30E);
	Il2CppFullySharedGenericAny V_5 = alloca(SizeOf_T4_t72EE5E3145D8FF5738B17FFF6A56CD3596448171);
	memset(V_5, 0, SizeOf_T4_t72EE5E3145D8FF5738B17FFF6A56CD3596448171);
	Il2CppFullySharedGenericAny V_6 = alloca(SizeOf_T5_tBAA81B6ABC55C264673BFAB9E6595906EACF4385);
	memset(V_6, 0, SizeOf_T5_tBAA81B6ABC55C264673BFAB9E6595906EACF4385);
	Il2CppFullySharedGenericAny V_7 = alloca(SizeOf_T6_tDBE701EEE385225ABD2D5FE3A33BBB44DAB77FA1);
	memset(V_7, 0, SizeOf_T6_tDBE701EEE385225ABD2D5FE3A33BBB44DAB77FA1);
	Il2CppFullySharedGenericAny V_8 = alloca(SizeOf_T7_tB1C7E0C236178B74109F4EF31E447F56A86DBA34);
	memset(V_8, 0, SizeOf_T7_tB1C7E0C236178B74109F4EF31E447F56A86DBA34);
	Il2CppFullySharedGenericAny V_9 = alloca(SizeOf_T8_tAF9A0784F75559C808ECBC453336127EB8DA3A7A);
	memset(V_9, 0, SizeOf_T8_tAF9A0784F75559C808ECBC453336127EB8DA3A7A);
	Il2CppFullySharedGenericAny V_10 = alloca(SizeOf_T9_tB9C3488598121213AB36E222281D28C99542EDB2);
	memset(V_10, 0, SizeOf_T9_tB9C3488598121213AB36E222281D28C99542EDB2);
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
	}
	try
	{
		Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* L_0 = ___1_awaiter;
		InvokerActionInvoker1< Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 130)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 130), L_0, (Il2CppFullySharedGenericAny*)L_1);
		il2cpp_codegen_memcpy(V_0, L_1, SizeOf_T2_tAD4D518AD8F8B278644DA50484CBC022467C03C8);
		goto IL_001d;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&Exception_t_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_000c;
		}
		throw e;
	}

CATCH_000c:
	{
		Exception_t* L_2 = ((Exception_t*)IL2CPP_GET_ACTIVE_EXCEPTION(Exception_t*));;
		V_1 = L_2;
		WhenAnyPromise_9_t2D551F16D8A9A247E0C45E7698A6A7A3CCDB7757* L_3 = ___0_self;
		Exception_t* L_4 = V_1;
		bool L_5;
		L_5 = ((  bool (*) (UniTaskCompletionSourceCore_1_t1911EC18C6234A1A4E814CB064F127B40A3F2BD1*, Exception_t*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 115)))((((UniTaskCompletionSourceCore_1_t1911EC18C6234A1A4E814CB064F127B40A3F2BD1*)il2cpp_codegen_get_instance_field_data_pointer(L_3, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),1)))), L_4, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 115));
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_0098;
	}

IL_001d:
	{
		WhenAnyPromise_9_t2D551F16D8A9A247E0C45E7698A6A7A3CCDB7757* L_6 = ___0_self;
		int32_t L_7;
		L_7 = Interlocked_Increment_m3C240C32E8D9544EC050B74D4F28EEB58F1F9309((((int32_t*)il2cpp_codegen_get_instance_field_data_pointer(L_6, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),0)))), NULL);
		V_2 = (bool)((((int32_t)L_7) == ((int32_t)1))? 1 : 0);
		bool L_8 = V_2;
		if (!L_8)
		{
			goto IL_0098;
		}
	}
	{
		WhenAnyPromise_9_t2D551F16D8A9A247E0C45E7698A6A7A3CCDB7757* L_9 = ___0_self;
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_3, SizeOf_T1_t12224CDB8CF3A7A9B85AE3735573C8F4E483F5C8);
		il2cpp_codegen_memcpy(L_10, V_3, SizeOf_T1_t12224CDB8CF3A7A9B85AE3735573C8F4E483F5C8);
		il2cpp_codegen_memcpy(L_11, V_0, SizeOf_T2_tAD4D518AD8F8B278644DA50484CBC022467C03C8);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_4, SizeOf_T3_t66D9D606A6E8AE1FFD2214BAC540BA2C6A05F30E);
		il2cpp_codegen_memcpy(L_12, V_4, SizeOf_T3_t66D9D606A6E8AE1FFD2214BAC540BA2C6A05F30E);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_5, SizeOf_T4_t72EE5E3145D8FF5738B17FFF6A56CD3596448171);
		il2cpp_codegen_memcpy(L_13, V_5, SizeOf_T4_t72EE5E3145D8FF5738B17FFF6A56CD3596448171);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_6, SizeOf_T5_tBAA81B6ABC55C264673BFAB9E6595906EACF4385);
		il2cpp_codegen_memcpy(L_14, V_6, SizeOf_T5_tBAA81B6ABC55C264673BFAB9E6595906EACF4385);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_7, SizeOf_T6_tDBE701EEE385225ABD2D5FE3A33BBB44DAB77FA1);
		il2cpp_codegen_memcpy(L_15, V_7, SizeOf_T6_tDBE701EEE385225ABD2D5FE3A33BBB44DAB77FA1);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_8, SizeOf_T7_tB1C7E0C236178B74109F4EF31E447F56A86DBA34);
		il2cpp_codegen_memcpy(L_16, V_8, SizeOf_T7_tB1C7E0C236178B74109F4EF31E447F56A86DBA34);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_9, SizeOf_T8_tAF9A0784F75559C808ECBC453336127EB8DA3A7A);
		il2cpp_codegen_memcpy(L_17, V_9, SizeOf_T8_tAF9A0784F75559C808ECBC453336127EB8DA3A7A);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_10, SizeOf_T9_tB9C3488598121213AB36E222281D28C99542EDB2);
		il2cpp_codegen_memcpy(L_18, V_10, SizeOf_T9_tB9C3488598121213AB36E222281D28C99542EDB2);
		memset(L_22, 0, SizeOf_ValueTuple_3_t296AC28BABFD66CC8A156720B3F2B3437143A60F);
		ValueTuple_3__ctor_mAB800E7134D8E52646FD55A8B2979AC908028759((ValueTuple_3_t182F852EE39DD805E380FD93762C931C933ACE98*)L_22, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 122)) ? il2cpp_codegen_memcpy(L_19, L_16, SizeOf_T7_tB1C7E0C236178B74109F4EF31E447F56A86DBA34): *(void**)L_16), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 123)) ? il2cpp_codegen_memcpy(L_20, L_17, SizeOf_T8_tAF9A0784F75559C808ECBC453336127EB8DA3A7A): *(void**)L_17), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 124)) ? il2cpp_codegen_memcpy(L_21, L_18, SizeOf_T9_tB9C3488598121213AB36E222281D28C99542EDB2): *(void**)L_18), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 126));
		memset(L_30, 0, SizeOf_ValueTuple_8_t8393F807A09311AE5C3F77F38D87FF98B57A7A47);
		ValueTuple_8__ctor_m5FDE8CF38A97A3D5FC7C364C3467B819664360EE((ValueTuple_8_tF94FE992101922E2A97F08D019A9EBDDA748DCB2*)L_30, 1, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 113)) ? il2cpp_codegen_memcpy(L_23, L_10, SizeOf_T1_t12224CDB8CF3A7A9B85AE3735573C8F4E483F5C8): *(void**)L_10), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 117)) ? il2cpp_codegen_memcpy(L_24, L_11, SizeOf_T2_tAD4D518AD8F8B278644DA50484CBC022467C03C8): *(void**)L_11), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 118)) ? il2cpp_codegen_memcpy(L_25, L_12, SizeOf_T3_t66D9D606A6E8AE1FFD2214BAC540BA2C6A05F30E): *(void**)L_12), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 119)) ? il2cpp_codegen_memcpy(L_26, L_13, SizeOf_T4_t72EE5E3145D8FF5738B17FFF6A56CD3596448171): *(void**)L_13), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 120)) ? il2cpp_codegen_memcpy(L_27, L_14, SizeOf_T5_tBAA81B6ABC55C264673BFAB9E6595906EACF4385): *(void**)L_14), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 121)) ? il2cpp_codegen_memcpy(L_28, L_15, SizeOf_T6_tDBE701EEE385225ABD2D5FE3A33BBB44DAB77FA1): *(void**)L_15), il2cpp_codegen_memcpy(L_29, L_22, SizeOf_ValueTuple_3_t296AC28BABFD66CC8A156720B3F2B3437143A60F), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 128));
		bool L_31;
		L_31 = InvokerFuncInvoker1< bool, ValueTuple_8_tF94FE992101922E2A97F08D019A9EBDDA748DCB2 >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 129)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 129), (((UniTaskCompletionSourceCore_1_t1911EC18C6234A1A4E814CB064F127B40A3F2BD1*)il2cpp_codegen_get_instance_field_data_pointer(L_9, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),1)))), L_30);
	}

IL_0098:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhenAnyPromise_9_TryInvokeContinuationT3_m1942E7C0A32C2F8807BA581D2DC517D5CDD3488F_gshared (WhenAnyPromise_9_t2D551F16D8A9A247E0C45E7698A6A7A3CCDB7757* ___0_self, Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* ___1_awaiter, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T3_t66D9D606A6E8AE1FFD2214BAC540BA2C6A05F30E = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 118));
	const uint32_t SizeOf_T1_t12224CDB8CF3A7A9B85AE3735573C8F4E483F5C8 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 113));
	const uint32_t SizeOf_T2_tAD4D518AD8F8B278644DA50484CBC022467C03C8 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 117));
	const uint32_t SizeOf_T4_t72EE5E3145D8FF5738B17FFF6A56CD3596448171 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 119));
	const uint32_t SizeOf_T5_tBAA81B6ABC55C264673BFAB9E6595906EACF4385 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 120));
	const uint32_t SizeOf_T6_tDBE701EEE385225ABD2D5FE3A33BBB44DAB77FA1 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 121));
	const uint32_t SizeOf_T7_tB1C7E0C236178B74109F4EF31E447F56A86DBA34 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 122));
	const uint32_t SizeOf_T8_tAF9A0784F75559C808ECBC453336127EB8DA3A7A = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 123));
	const uint32_t SizeOf_T9_tB9C3488598121213AB36E222281D28C99542EDB2 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 124));
	const uint32_t SizeOf_ValueTuple_3_t296AC28BABFD66CC8A156720B3F2B3437143A60F = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 125));
	const uint32_t SizeOf_ValueTuple_8_t8393F807A09311AE5C3F77F38D87FF98B57A7A47 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 127));
	const Il2CppFullySharedGenericAny L_10 = alloca(SizeOf_T1_t12224CDB8CF3A7A9B85AE3735573C8F4E483F5C8);
	const Il2CppFullySharedGenericAny L_23 = alloca(SizeOf_T1_t12224CDB8CF3A7A9B85AE3735573C8F4E483F5C8);
	const Il2CppFullySharedGenericAny L_11 = alloca(SizeOf_T2_tAD4D518AD8F8B278644DA50484CBC022467C03C8);
	const Il2CppFullySharedGenericAny L_24 = alloca(SizeOf_T2_tAD4D518AD8F8B278644DA50484CBC022467C03C8);
	const Il2CppFullySharedGenericAny L_1 = alloca(SizeOf_T3_t66D9D606A6E8AE1FFD2214BAC540BA2C6A05F30E);
	const Il2CppFullySharedGenericAny L_12 = L_1;
	const Il2CppFullySharedGenericAny L_25 = alloca(SizeOf_T3_t66D9D606A6E8AE1FFD2214BAC540BA2C6A05F30E);
	const Il2CppFullySharedGenericAny L_13 = alloca(SizeOf_T4_t72EE5E3145D8FF5738B17FFF6A56CD3596448171);
	const Il2CppFullySharedGenericAny L_26 = alloca(SizeOf_T4_t72EE5E3145D8FF5738B17FFF6A56CD3596448171);
	const Il2CppFullySharedGenericAny L_14 = alloca(SizeOf_T5_tBAA81B6ABC55C264673BFAB9E6595906EACF4385);
	const Il2CppFullySharedGenericAny L_27 = alloca(SizeOf_T5_tBAA81B6ABC55C264673BFAB9E6595906EACF4385);
	const Il2CppFullySharedGenericAny L_15 = alloca(SizeOf_T6_tDBE701EEE385225ABD2D5FE3A33BBB44DAB77FA1);
	const Il2CppFullySharedGenericAny L_28 = alloca(SizeOf_T6_tDBE701EEE385225ABD2D5FE3A33BBB44DAB77FA1);
	const Il2CppFullySharedGenericAny L_16 = alloca(SizeOf_T7_tB1C7E0C236178B74109F4EF31E447F56A86DBA34);
	const Il2CppFullySharedGenericAny L_19 = alloca(SizeOf_T7_tB1C7E0C236178B74109F4EF31E447F56A86DBA34);
	const Il2CppFullySharedGenericAny L_17 = alloca(SizeOf_T8_tAF9A0784F75559C808ECBC453336127EB8DA3A7A);
	const Il2CppFullySharedGenericAny L_20 = alloca(SizeOf_T8_tAF9A0784F75559C808ECBC453336127EB8DA3A7A);
	const Il2CppFullySharedGenericAny L_18 = alloca(SizeOf_T9_tB9C3488598121213AB36E222281D28C99542EDB2);
	const Il2CppFullySharedGenericAny L_21 = alloca(SizeOf_T9_tB9C3488598121213AB36E222281D28C99542EDB2);
	const ValueTuple_3_t182F852EE39DD805E380FD93762C931C933ACE98 L_22 = alloca(SizeOf_ValueTuple_3_t296AC28BABFD66CC8A156720B3F2B3437143A60F);
	const ValueTuple_3_t182F852EE39DD805E380FD93762C931C933ACE98 L_29 = alloca(SizeOf_ValueTuple_3_t296AC28BABFD66CC8A156720B3F2B3437143A60F);
	const ValueTuple_8_tF94FE992101922E2A97F08D019A9EBDDA748DCB2 L_30 = alloca(SizeOf_ValueTuple_8_t8393F807A09311AE5C3F77F38D87FF98B57A7A47);
	Il2CppFullySharedGenericAny V_0 = alloca(SizeOf_T3_t66D9D606A6E8AE1FFD2214BAC540BA2C6A05F30E);
	memset(V_0, 0, SizeOf_T3_t66D9D606A6E8AE1FFD2214BAC540BA2C6A05F30E);
	Exception_t* V_1 = NULL;
	bool V_2 = false;
	Il2CppFullySharedGenericAny V_3 = alloca(SizeOf_T1_t12224CDB8CF3A7A9B85AE3735573C8F4E483F5C8);
	memset(V_3, 0, SizeOf_T1_t12224CDB8CF3A7A9B85AE3735573C8F4E483F5C8);
	Il2CppFullySharedGenericAny V_4 = alloca(SizeOf_T2_tAD4D518AD8F8B278644DA50484CBC022467C03C8);
	memset(V_4, 0, SizeOf_T2_tAD4D518AD8F8B278644DA50484CBC022467C03C8);
	Il2CppFullySharedGenericAny V_5 = alloca(SizeOf_T4_t72EE5E3145D8FF5738B17FFF6A56CD3596448171);
	memset(V_5, 0, SizeOf_T4_t72EE5E3145D8FF5738B17FFF6A56CD3596448171);
	Il2CppFullySharedGenericAny V_6 = alloca(SizeOf_T5_tBAA81B6ABC55C264673BFAB9E6595906EACF4385);
	memset(V_6, 0, SizeOf_T5_tBAA81B6ABC55C264673BFAB9E6595906EACF4385);
	Il2CppFullySharedGenericAny V_7 = alloca(SizeOf_T6_tDBE701EEE385225ABD2D5FE3A33BBB44DAB77FA1);
	memset(V_7, 0, SizeOf_T6_tDBE701EEE385225ABD2D5FE3A33BBB44DAB77FA1);
	Il2CppFullySharedGenericAny V_8 = alloca(SizeOf_T7_tB1C7E0C236178B74109F4EF31E447F56A86DBA34);
	memset(V_8, 0, SizeOf_T7_tB1C7E0C236178B74109F4EF31E447F56A86DBA34);
	Il2CppFullySharedGenericAny V_9 = alloca(SizeOf_T8_tAF9A0784F75559C808ECBC453336127EB8DA3A7A);
	memset(V_9, 0, SizeOf_T8_tAF9A0784F75559C808ECBC453336127EB8DA3A7A);
	Il2CppFullySharedGenericAny V_10 = alloca(SizeOf_T9_tB9C3488598121213AB36E222281D28C99542EDB2);
	memset(V_10, 0, SizeOf_T9_tB9C3488598121213AB36E222281D28C99542EDB2);
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
	}
	try
	{
		Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* L_0 = ___1_awaiter;
		InvokerActionInvoker1< Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 131)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 131), L_0, (Il2CppFullySharedGenericAny*)L_1);
		il2cpp_codegen_memcpy(V_0, L_1, SizeOf_T3_t66D9D606A6E8AE1FFD2214BAC540BA2C6A05F30E);
		goto IL_001d;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&Exception_t_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_000c;
		}
		throw e;
	}

CATCH_000c:
	{
		Exception_t* L_2 = ((Exception_t*)IL2CPP_GET_ACTIVE_EXCEPTION(Exception_t*));;
		V_1 = L_2;
		WhenAnyPromise_9_t2D551F16D8A9A247E0C45E7698A6A7A3CCDB7757* L_3 = ___0_self;
		Exception_t* L_4 = V_1;
		bool L_5;
		L_5 = ((  bool (*) (UniTaskCompletionSourceCore_1_t1911EC18C6234A1A4E814CB064F127B40A3F2BD1*, Exception_t*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 115)))((((UniTaskCompletionSourceCore_1_t1911EC18C6234A1A4E814CB064F127B40A3F2BD1*)il2cpp_codegen_get_instance_field_data_pointer(L_3, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),1)))), L_4, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 115));
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_0098;
	}

IL_001d:
	{
		WhenAnyPromise_9_t2D551F16D8A9A247E0C45E7698A6A7A3CCDB7757* L_6 = ___0_self;
		int32_t L_7;
		L_7 = Interlocked_Increment_m3C240C32E8D9544EC050B74D4F28EEB58F1F9309((((int32_t*)il2cpp_codegen_get_instance_field_data_pointer(L_6, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),0)))), NULL);
		V_2 = (bool)((((int32_t)L_7) == ((int32_t)1))? 1 : 0);
		bool L_8 = V_2;
		if (!L_8)
		{
			goto IL_0098;
		}
	}
	{
		WhenAnyPromise_9_t2D551F16D8A9A247E0C45E7698A6A7A3CCDB7757* L_9 = ___0_self;
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_3, SizeOf_T1_t12224CDB8CF3A7A9B85AE3735573C8F4E483F5C8);
		il2cpp_codegen_memcpy(L_10, V_3, SizeOf_T1_t12224CDB8CF3A7A9B85AE3735573C8F4E483F5C8);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_4, SizeOf_T2_tAD4D518AD8F8B278644DA50484CBC022467C03C8);
		il2cpp_codegen_memcpy(L_11, V_4, SizeOf_T2_tAD4D518AD8F8B278644DA50484CBC022467C03C8);
		il2cpp_codegen_memcpy(L_12, V_0, SizeOf_T3_t66D9D606A6E8AE1FFD2214BAC540BA2C6A05F30E);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_5, SizeOf_T4_t72EE5E3145D8FF5738B17FFF6A56CD3596448171);
		il2cpp_codegen_memcpy(L_13, V_5, SizeOf_T4_t72EE5E3145D8FF5738B17FFF6A56CD3596448171);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_6, SizeOf_T5_tBAA81B6ABC55C264673BFAB9E6595906EACF4385);
		il2cpp_codegen_memcpy(L_14, V_6, SizeOf_T5_tBAA81B6ABC55C264673BFAB9E6595906EACF4385);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_7, SizeOf_T6_tDBE701EEE385225ABD2D5FE3A33BBB44DAB77FA1);
		il2cpp_codegen_memcpy(L_15, V_7, SizeOf_T6_tDBE701EEE385225ABD2D5FE3A33BBB44DAB77FA1);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_8, SizeOf_T7_tB1C7E0C236178B74109F4EF31E447F56A86DBA34);
		il2cpp_codegen_memcpy(L_16, V_8, SizeOf_T7_tB1C7E0C236178B74109F4EF31E447F56A86DBA34);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_9, SizeOf_T8_tAF9A0784F75559C808ECBC453336127EB8DA3A7A);
		il2cpp_codegen_memcpy(L_17, V_9, SizeOf_T8_tAF9A0784F75559C808ECBC453336127EB8DA3A7A);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_10, SizeOf_T9_tB9C3488598121213AB36E222281D28C99542EDB2);
		il2cpp_codegen_memcpy(L_18, V_10, SizeOf_T9_tB9C3488598121213AB36E222281D28C99542EDB2);
		memset(L_22, 0, SizeOf_ValueTuple_3_t296AC28BABFD66CC8A156720B3F2B3437143A60F);
		ValueTuple_3__ctor_mAB800E7134D8E52646FD55A8B2979AC908028759((ValueTuple_3_t182F852EE39DD805E380FD93762C931C933ACE98*)L_22, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 122)) ? il2cpp_codegen_memcpy(L_19, L_16, SizeOf_T7_tB1C7E0C236178B74109F4EF31E447F56A86DBA34): *(void**)L_16), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 123)) ? il2cpp_codegen_memcpy(L_20, L_17, SizeOf_T8_tAF9A0784F75559C808ECBC453336127EB8DA3A7A): *(void**)L_17), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 124)) ? il2cpp_codegen_memcpy(L_21, L_18, SizeOf_T9_tB9C3488598121213AB36E222281D28C99542EDB2): *(void**)L_18), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 126));
		memset(L_30, 0, SizeOf_ValueTuple_8_t8393F807A09311AE5C3F77F38D87FF98B57A7A47);
		ValueTuple_8__ctor_m5FDE8CF38A97A3D5FC7C364C3467B819664360EE((ValueTuple_8_tF94FE992101922E2A97F08D019A9EBDDA748DCB2*)L_30, 2, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 113)) ? il2cpp_codegen_memcpy(L_23, L_10, SizeOf_T1_t12224CDB8CF3A7A9B85AE3735573C8F4E483F5C8): *(void**)L_10), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 117)) ? il2cpp_codegen_memcpy(L_24, L_11, SizeOf_T2_tAD4D518AD8F8B278644DA50484CBC022467C03C8): *(void**)L_11), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 118)) ? il2cpp_codegen_memcpy(L_25, L_12, SizeOf_T3_t66D9D606A6E8AE1FFD2214BAC540BA2C6A05F30E): *(void**)L_12), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 119)) ? il2cpp_codegen_memcpy(L_26, L_13, SizeOf_T4_t72EE5E3145D8FF5738B17FFF6A56CD3596448171): *(void**)L_13), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 120)) ? il2cpp_codegen_memcpy(L_27, L_14, SizeOf_T5_tBAA81B6ABC55C264673BFAB9E6595906EACF4385): *(void**)L_14), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 121)) ? il2cpp_codegen_memcpy(L_28, L_15, SizeOf_T6_tDBE701EEE385225ABD2D5FE3A33BBB44DAB77FA1): *(void**)L_15), il2cpp_codegen_memcpy(L_29, L_22, SizeOf_ValueTuple_3_t296AC28BABFD66CC8A156720B3F2B3437143A60F), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 128));
		bool L_31;
		L_31 = InvokerFuncInvoker1< bool, ValueTuple_8_tF94FE992101922E2A97F08D019A9EBDDA748DCB2 >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 129)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 129), (((UniTaskCompletionSourceCore_1_t1911EC18C6234A1A4E814CB064F127B40A3F2BD1*)il2cpp_codegen_get_instance_field_data_pointer(L_9, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),1)))), L_30);
	}

IL_0098:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhenAnyPromise_9_TryInvokeContinuationT4_m2DDCE23CB6D75CF15B8A369F4C707CCAE28FCBA2_gshared (WhenAnyPromise_9_t2D551F16D8A9A247E0C45E7698A6A7A3CCDB7757* ___0_self, Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* ___1_awaiter, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T4_t72EE5E3145D8FF5738B17FFF6A56CD3596448171 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 119));
	const uint32_t SizeOf_T1_t12224CDB8CF3A7A9B85AE3735573C8F4E483F5C8 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 113));
	const uint32_t SizeOf_T2_tAD4D518AD8F8B278644DA50484CBC022467C03C8 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 117));
	const uint32_t SizeOf_T3_t66D9D606A6E8AE1FFD2214BAC540BA2C6A05F30E = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 118));
	const uint32_t SizeOf_T5_tBAA81B6ABC55C264673BFAB9E6595906EACF4385 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 120));
	const uint32_t SizeOf_T6_tDBE701EEE385225ABD2D5FE3A33BBB44DAB77FA1 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 121));
	const uint32_t SizeOf_T7_tB1C7E0C236178B74109F4EF31E447F56A86DBA34 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 122));
	const uint32_t SizeOf_T8_tAF9A0784F75559C808ECBC453336127EB8DA3A7A = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 123));
	const uint32_t SizeOf_T9_tB9C3488598121213AB36E222281D28C99542EDB2 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 124));
	const uint32_t SizeOf_ValueTuple_3_t296AC28BABFD66CC8A156720B3F2B3437143A60F = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 125));
	const uint32_t SizeOf_ValueTuple_8_t8393F807A09311AE5C3F77F38D87FF98B57A7A47 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 127));
	const Il2CppFullySharedGenericAny L_10 = alloca(SizeOf_T1_t12224CDB8CF3A7A9B85AE3735573C8F4E483F5C8);
	const Il2CppFullySharedGenericAny L_23 = alloca(SizeOf_T1_t12224CDB8CF3A7A9B85AE3735573C8F4E483F5C8);
	const Il2CppFullySharedGenericAny L_11 = alloca(SizeOf_T2_tAD4D518AD8F8B278644DA50484CBC022467C03C8);
	const Il2CppFullySharedGenericAny L_24 = alloca(SizeOf_T2_tAD4D518AD8F8B278644DA50484CBC022467C03C8);
	const Il2CppFullySharedGenericAny L_12 = alloca(SizeOf_T3_t66D9D606A6E8AE1FFD2214BAC540BA2C6A05F30E);
	const Il2CppFullySharedGenericAny L_25 = alloca(SizeOf_T3_t66D9D606A6E8AE1FFD2214BAC540BA2C6A05F30E);
	const Il2CppFullySharedGenericAny L_1 = alloca(SizeOf_T4_t72EE5E3145D8FF5738B17FFF6A56CD3596448171);
	const Il2CppFullySharedGenericAny L_13 = L_1;
	const Il2CppFullySharedGenericAny L_26 = alloca(SizeOf_T4_t72EE5E3145D8FF5738B17FFF6A56CD3596448171);
	const Il2CppFullySharedGenericAny L_14 = alloca(SizeOf_T5_tBAA81B6ABC55C264673BFAB9E6595906EACF4385);
	const Il2CppFullySharedGenericAny L_27 = alloca(SizeOf_T5_tBAA81B6ABC55C264673BFAB9E6595906EACF4385);
	const Il2CppFullySharedGenericAny L_15 = alloca(SizeOf_T6_tDBE701EEE385225ABD2D5FE3A33BBB44DAB77FA1);
	const Il2CppFullySharedGenericAny L_28 = alloca(SizeOf_T6_tDBE701EEE385225ABD2D5FE3A33BBB44DAB77FA1);
	const Il2CppFullySharedGenericAny L_16 = alloca(SizeOf_T7_tB1C7E0C236178B74109F4EF31E447F56A86DBA34);
	const Il2CppFullySharedGenericAny L_19 = alloca(SizeOf_T7_tB1C7E0C236178B74109F4EF31E447F56A86DBA34);
	const Il2CppFullySharedGenericAny L_17 = alloca(SizeOf_T8_tAF9A0784F75559C808ECBC453336127EB8DA3A7A);
	const Il2CppFullySharedGenericAny L_20 = alloca(SizeOf_T8_tAF9A0784F75559C808ECBC453336127EB8DA3A7A);
	const Il2CppFullySharedGenericAny L_18 = alloca(SizeOf_T9_tB9C3488598121213AB36E222281D28C99542EDB2);
	const Il2CppFullySharedGenericAny L_21 = alloca(SizeOf_T9_tB9C3488598121213AB36E222281D28C99542EDB2);
	const ValueTuple_3_t182F852EE39DD805E380FD93762C931C933ACE98 L_22 = alloca(SizeOf_ValueTuple_3_t296AC28BABFD66CC8A156720B3F2B3437143A60F);
	const ValueTuple_3_t182F852EE39DD805E380FD93762C931C933ACE98 L_29 = alloca(SizeOf_ValueTuple_3_t296AC28BABFD66CC8A156720B3F2B3437143A60F);
	const ValueTuple_8_tF94FE992101922E2A97F08D019A9EBDDA748DCB2 L_30 = alloca(SizeOf_ValueTuple_8_t8393F807A09311AE5C3F77F38D87FF98B57A7A47);
	Il2CppFullySharedGenericAny V_0 = alloca(SizeOf_T4_t72EE5E3145D8FF5738B17FFF6A56CD3596448171);
	memset(V_0, 0, SizeOf_T4_t72EE5E3145D8FF5738B17FFF6A56CD3596448171);
	Exception_t* V_1 = NULL;
	bool V_2 = false;
	Il2CppFullySharedGenericAny V_3 = alloca(SizeOf_T1_t12224CDB8CF3A7A9B85AE3735573C8F4E483F5C8);
	memset(V_3, 0, SizeOf_T1_t12224CDB8CF3A7A9B85AE3735573C8F4E483F5C8);
	Il2CppFullySharedGenericAny V_4 = alloca(SizeOf_T2_tAD4D518AD8F8B278644DA50484CBC022467C03C8);
	memset(V_4, 0, SizeOf_T2_tAD4D518AD8F8B278644DA50484CBC022467C03C8);
	Il2CppFullySharedGenericAny V_5 = alloca(SizeOf_T3_t66D9D606A6E8AE1FFD2214BAC540BA2C6A05F30E);
	memset(V_5, 0, SizeOf_T3_t66D9D606A6E8AE1FFD2214BAC540BA2C6A05F30E);
	Il2CppFullySharedGenericAny V_6 = alloca(SizeOf_T5_tBAA81B6ABC55C264673BFAB9E6595906EACF4385);
	memset(V_6, 0, SizeOf_T5_tBAA81B6ABC55C264673BFAB9E6595906EACF4385);
	Il2CppFullySharedGenericAny V_7 = alloca(SizeOf_T6_tDBE701EEE385225ABD2D5FE3A33BBB44DAB77FA1);
	memset(V_7, 0, SizeOf_T6_tDBE701EEE385225ABD2D5FE3A33BBB44DAB77FA1);
	Il2CppFullySharedGenericAny V_8 = alloca(SizeOf_T7_tB1C7E0C236178B74109F4EF31E447F56A86DBA34);
	memset(V_8, 0, SizeOf_T7_tB1C7E0C236178B74109F4EF31E447F56A86DBA34);
	Il2CppFullySharedGenericAny V_9 = alloca(SizeOf_T8_tAF9A0784F75559C808ECBC453336127EB8DA3A7A);
	memset(V_9, 0, SizeOf_T8_tAF9A0784F75559C808ECBC453336127EB8DA3A7A);
	Il2CppFullySharedGenericAny V_10 = alloca(SizeOf_T9_tB9C3488598121213AB36E222281D28C99542EDB2);
	memset(V_10, 0, SizeOf_T9_tB9C3488598121213AB36E222281D28C99542EDB2);
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
	}
	try
	{
		Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* L_0 = ___1_awaiter;
		InvokerActionInvoker1< Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 132)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 132), L_0, (Il2CppFullySharedGenericAny*)L_1);
		il2cpp_codegen_memcpy(V_0, L_1, SizeOf_T4_t72EE5E3145D8FF5738B17FFF6A56CD3596448171);
		goto IL_001d;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&Exception_t_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_000c;
		}
		throw e;
	}

CATCH_000c:
	{
		Exception_t* L_2 = ((Exception_t*)IL2CPP_GET_ACTIVE_EXCEPTION(Exception_t*));;
		V_1 = L_2;
		WhenAnyPromise_9_t2D551F16D8A9A247E0C45E7698A6A7A3CCDB7757* L_3 = ___0_self;
		Exception_t* L_4 = V_1;
		bool L_5;
		L_5 = ((  bool (*) (UniTaskCompletionSourceCore_1_t1911EC18C6234A1A4E814CB064F127B40A3F2BD1*, Exception_t*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 115)))((((UniTaskCompletionSourceCore_1_t1911EC18C6234A1A4E814CB064F127B40A3F2BD1*)il2cpp_codegen_get_instance_field_data_pointer(L_3, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),1)))), L_4, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 115));
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_0098;
	}

IL_001d:
	{
		WhenAnyPromise_9_t2D551F16D8A9A247E0C45E7698A6A7A3CCDB7757* L_6 = ___0_self;
		int32_t L_7;
		L_7 = Interlocked_Increment_m3C240C32E8D9544EC050B74D4F28EEB58F1F9309((((int32_t*)il2cpp_codegen_get_instance_field_data_pointer(L_6, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),0)))), NULL);
		V_2 = (bool)((((int32_t)L_7) == ((int32_t)1))? 1 : 0);
		bool L_8 = V_2;
		if (!L_8)
		{
			goto IL_0098;
		}
	}
	{
		WhenAnyPromise_9_t2D551F16D8A9A247E0C45E7698A6A7A3CCDB7757* L_9 = ___0_self;
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_3, SizeOf_T1_t12224CDB8CF3A7A9B85AE3735573C8F4E483F5C8);
		il2cpp_codegen_memcpy(L_10, V_3, SizeOf_T1_t12224CDB8CF3A7A9B85AE3735573C8F4E483F5C8);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_4, SizeOf_T2_tAD4D518AD8F8B278644DA50484CBC022467C03C8);
		il2cpp_codegen_memcpy(L_11, V_4, SizeOf_T2_tAD4D518AD8F8B278644DA50484CBC022467C03C8);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_5, SizeOf_T3_t66D9D606A6E8AE1FFD2214BAC540BA2C6A05F30E);
		il2cpp_codegen_memcpy(L_12, V_5, SizeOf_T3_t66D9D606A6E8AE1FFD2214BAC540BA2C6A05F30E);
		il2cpp_codegen_memcpy(L_13, V_0, SizeOf_T4_t72EE5E3145D8FF5738B17FFF6A56CD3596448171);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_6, SizeOf_T5_tBAA81B6ABC55C264673BFAB9E6595906EACF4385);
		il2cpp_codegen_memcpy(L_14, V_6, SizeOf_T5_tBAA81B6ABC55C264673BFAB9E6595906EACF4385);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_7, SizeOf_T6_tDBE701EEE385225ABD2D5FE3A33BBB44DAB77FA1);
		il2cpp_codegen_memcpy(L_15, V_7, SizeOf_T6_tDBE701EEE385225ABD2D5FE3A33BBB44DAB77FA1);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_8, SizeOf_T7_tB1C7E0C236178B74109F4EF31E447F56A86DBA34);
		il2cpp_codegen_memcpy(L_16, V_8, SizeOf_T7_tB1C7E0C236178B74109F4EF31E447F56A86DBA34);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_9, SizeOf_T8_tAF9A0784F75559C808ECBC453336127EB8DA3A7A);
		il2cpp_codegen_memcpy(L_17, V_9, SizeOf_T8_tAF9A0784F75559C808ECBC453336127EB8DA3A7A);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_10, SizeOf_T9_tB9C3488598121213AB36E222281D28C99542EDB2);
		il2cpp_codegen_memcpy(L_18, V_10, SizeOf_T9_tB9C3488598121213AB36E222281D28C99542EDB2);
		memset(L_22, 0, SizeOf_ValueTuple_3_t296AC28BABFD66CC8A156720B3F2B3437143A60F);
		ValueTuple_3__ctor_mAB800E7134D8E52646FD55A8B2979AC908028759((ValueTuple_3_t182F852EE39DD805E380FD93762C931C933ACE98*)L_22, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 122)) ? il2cpp_codegen_memcpy(L_19, L_16, SizeOf_T7_tB1C7E0C236178B74109F4EF31E447F56A86DBA34): *(void**)L_16), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 123)) ? il2cpp_codegen_memcpy(L_20, L_17, SizeOf_T8_tAF9A0784F75559C808ECBC453336127EB8DA3A7A): *(void**)L_17), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 124)) ? il2cpp_codegen_memcpy(L_21, L_18, SizeOf_T9_tB9C3488598121213AB36E222281D28C99542EDB2): *(void**)L_18), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 126));
		memset(L_30, 0, SizeOf_ValueTuple_8_t8393F807A09311AE5C3F77F38D87FF98B57A7A47);
		ValueTuple_8__ctor_m5FDE8CF38A97A3D5FC7C364C3467B819664360EE((ValueTuple_8_tF94FE992101922E2A97F08D019A9EBDDA748DCB2*)L_30, 3, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 113)) ? il2cpp_codegen_memcpy(L_23, L_10, SizeOf_T1_t12224CDB8CF3A7A9B85AE3735573C8F4E483F5C8): *(void**)L_10), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 117)) ? il2cpp_codegen_memcpy(L_24, L_11, SizeOf_T2_tAD4D518AD8F8B278644DA50484CBC022467C03C8): *(void**)L_11), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 118)) ? il2cpp_codegen_memcpy(L_25, L_12, SizeOf_T3_t66D9D606A6E8AE1FFD2214BAC540BA2C6A05F30E): *(void**)L_12), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 119)) ? il2cpp_codegen_memcpy(L_26, L_13, SizeOf_T4_t72EE5E3145D8FF5738B17FFF6A56CD3596448171): *(void**)L_13), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 120)) ? il2cpp_codegen_memcpy(L_27, L_14, SizeOf_T5_tBAA81B6ABC55C264673BFAB9E6595906EACF4385): *(void**)L_14), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 121)) ? il2cpp_codegen_memcpy(L_28, L_15, SizeOf_T6_tDBE701EEE385225ABD2D5FE3A33BBB44DAB77FA1): *(void**)L_15), il2cpp_codegen_memcpy(L_29, L_22, SizeOf_ValueTuple_3_t296AC28BABFD66CC8A156720B3F2B3437143A60F), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 128));
		bool L_31;
		L_31 = InvokerFuncInvoker1< bool, ValueTuple_8_tF94FE992101922E2A97F08D019A9EBDDA748DCB2 >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 129)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 129), (((UniTaskCompletionSourceCore_1_t1911EC18C6234A1A4E814CB064F127B40A3F2BD1*)il2cpp_codegen_get_instance_field_data_pointer(L_9, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),1)))), L_30);
	}

IL_0098:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhenAnyPromise_9_TryInvokeContinuationT5_mA9245F2F16F02627801F7BF5204EC59DBFAF99F5_gshared (WhenAnyPromise_9_t2D551F16D8A9A247E0C45E7698A6A7A3CCDB7757* ___0_self, Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* ___1_awaiter, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T5_tBAA81B6ABC55C264673BFAB9E6595906EACF4385 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 120));
	const uint32_t SizeOf_T1_t12224CDB8CF3A7A9B85AE3735573C8F4E483F5C8 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 113));
	const uint32_t SizeOf_T2_tAD4D518AD8F8B278644DA50484CBC022467C03C8 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 117));
	const uint32_t SizeOf_T3_t66D9D606A6E8AE1FFD2214BAC540BA2C6A05F30E = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 118));
	const uint32_t SizeOf_T4_t72EE5E3145D8FF5738B17FFF6A56CD3596448171 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 119));
	const uint32_t SizeOf_T6_tDBE701EEE385225ABD2D5FE3A33BBB44DAB77FA1 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 121));
	const uint32_t SizeOf_T7_tB1C7E0C236178B74109F4EF31E447F56A86DBA34 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 122));
	const uint32_t SizeOf_T8_tAF9A0784F75559C808ECBC453336127EB8DA3A7A = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 123));
	const uint32_t SizeOf_T9_tB9C3488598121213AB36E222281D28C99542EDB2 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 124));
	const uint32_t SizeOf_ValueTuple_3_t296AC28BABFD66CC8A156720B3F2B3437143A60F = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 125));
	const uint32_t SizeOf_ValueTuple_8_t8393F807A09311AE5C3F77F38D87FF98B57A7A47 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 127));
	const Il2CppFullySharedGenericAny L_10 = alloca(SizeOf_T1_t12224CDB8CF3A7A9B85AE3735573C8F4E483F5C8);
	const Il2CppFullySharedGenericAny L_23 = alloca(SizeOf_T1_t12224CDB8CF3A7A9B85AE3735573C8F4E483F5C8);
	const Il2CppFullySharedGenericAny L_11 = alloca(SizeOf_T2_tAD4D518AD8F8B278644DA50484CBC022467C03C8);
	const Il2CppFullySharedGenericAny L_24 = alloca(SizeOf_T2_tAD4D518AD8F8B278644DA50484CBC022467C03C8);
	const Il2CppFullySharedGenericAny L_12 = alloca(SizeOf_T3_t66D9D606A6E8AE1FFD2214BAC540BA2C6A05F30E);
	const Il2CppFullySharedGenericAny L_25 = alloca(SizeOf_T3_t66D9D606A6E8AE1FFD2214BAC540BA2C6A05F30E);
	const Il2CppFullySharedGenericAny L_13 = alloca(SizeOf_T4_t72EE5E3145D8FF5738B17FFF6A56CD3596448171);
	const Il2CppFullySharedGenericAny L_26 = alloca(SizeOf_T4_t72EE5E3145D8FF5738B17FFF6A56CD3596448171);
	const Il2CppFullySharedGenericAny L_1 = alloca(SizeOf_T5_tBAA81B6ABC55C264673BFAB9E6595906EACF4385);
	const Il2CppFullySharedGenericAny L_14 = L_1;
	const Il2CppFullySharedGenericAny L_27 = alloca(SizeOf_T5_tBAA81B6ABC55C264673BFAB9E6595906EACF4385);
	const Il2CppFullySharedGenericAny L_15 = alloca(SizeOf_T6_tDBE701EEE385225ABD2D5FE3A33BBB44DAB77FA1);
	const Il2CppFullySharedGenericAny L_28 = alloca(SizeOf_T6_tDBE701EEE385225ABD2D5FE3A33BBB44DAB77FA1);
	const Il2CppFullySharedGenericAny L_16 = alloca(SizeOf_T7_tB1C7E0C236178B74109F4EF31E447F56A86DBA34);
	const Il2CppFullySharedGenericAny L_19 = alloca(SizeOf_T7_tB1C7E0C236178B74109F4EF31E447F56A86DBA34);
	const Il2CppFullySharedGenericAny L_17 = alloca(SizeOf_T8_tAF9A0784F75559C808ECBC453336127EB8DA3A7A);
	const Il2CppFullySharedGenericAny L_20 = alloca(SizeOf_T8_tAF9A0784F75559C808ECBC453336127EB8DA3A7A);
	const Il2CppFullySharedGenericAny L_18 = alloca(SizeOf_T9_tB9C3488598121213AB36E222281D28C99542EDB2);
	const Il2CppFullySharedGenericAny L_21 = alloca(SizeOf_T9_tB9C3488598121213AB36E222281D28C99542EDB2);
	const ValueTuple_3_t182F852EE39DD805E380FD93762C931C933ACE98 L_22 = alloca(SizeOf_ValueTuple_3_t296AC28BABFD66CC8A156720B3F2B3437143A60F);
	const ValueTuple_3_t182F852EE39DD805E380FD93762C931C933ACE98 L_29 = alloca(SizeOf_ValueTuple_3_t296AC28BABFD66CC8A156720B3F2B3437143A60F);
	const ValueTuple_8_tF94FE992101922E2A97F08D019A9EBDDA748DCB2 L_30 = alloca(SizeOf_ValueTuple_8_t8393F807A09311AE5C3F77F38D87FF98B57A7A47);
	Il2CppFullySharedGenericAny V_0 = alloca(SizeOf_T5_tBAA81B6ABC55C264673BFAB9E6595906EACF4385);
	memset(V_0, 0, SizeOf_T5_tBAA81B6ABC55C264673BFAB9E6595906EACF4385);
	Exception_t* V_1 = NULL;
	bool V_2 = false;
	Il2CppFullySharedGenericAny V_3 = alloca(SizeOf_T1_t12224CDB8CF3A7A9B85AE3735573C8F4E483F5C8);
	memset(V_3, 0, SizeOf_T1_t12224CDB8CF3A7A9B85AE3735573C8F4E483F5C8);
	Il2CppFullySharedGenericAny V_4 = alloca(SizeOf_T2_tAD4D518AD8F8B278644DA50484CBC022467C03C8);
	memset(V_4, 0, SizeOf_T2_tAD4D518AD8F8B278644DA50484CBC022467C03C8);
	Il2CppFullySharedGenericAny V_5 = alloca(SizeOf_T3_t66D9D606A6E8AE1FFD2214BAC540BA2C6A05F30E);
	memset(V_5, 0, SizeOf_T3_t66D9D606A6E8AE1FFD2214BAC540BA2C6A05F30E);
	Il2CppFullySharedGenericAny V_6 = alloca(SizeOf_T4_t72EE5E3145D8FF5738B17FFF6A56CD3596448171);
	memset(V_6, 0, SizeOf_T4_t72EE5E3145D8FF5738B17FFF6A56CD3596448171);
	Il2CppFullySharedGenericAny V_7 = alloca(SizeOf_T6_tDBE701EEE385225ABD2D5FE3A33BBB44DAB77FA1);
	memset(V_7, 0, SizeOf_T6_tDBE701EEE385225ABD2D5FE3A33BBB44DAB77FA1);
	Il2CppFullySharedGenericAny V_8 = alloca(SizeOf_T7_tB1C7E0C236178B74109F4EF31E447F56A86DBA34);
	memset(V_8, 0, SizeOf_T7_tB1C7E0C236178B74109F4EF31E447F56A86DBA34);
	Il2CppFullySharedGenericAny V_9 = alloca(SizeOf_T8_tAF9A0784F75559C808ECBC453336127EB8DA3A7A);
	memset(V_9, 0, SizeOf_T8_tAF9A0784F75559C808ECBC453336127EB8DA3A7A);
	Il2CppFullySharedGenericAny V_10 = alloca(SizeOf_T9_tB9C3488598121213AB36E222281D28C99542EDB2);
	memset(V_10, 0, SizeOf_T9_tB9C3488598121213AB36E222281D28C99542EDB2);
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
	}
	try
	{
		Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* L_0 = ___1_awaiter;
		InvokerActionInvoker1< Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 133)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 133), L_0, (Il2CppFullySharedGenericAny*)L_1);
		il2cpp_codegen_memcpy(V_0, L_1, SizeOf_T5_tBAA81B6ABC55C264673BFAB9E6595906EACF4385);
		goto IL_001d;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&Exception_t_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_000c;
		}
		throw e;
	}

CATCH_000c:
	{
		Exception_t* L_2 = ((Exception_t*)IL2CPP_GET_ACTIVE_EXCEPTION(Exception_t*));;
		V_1 = L_2;
		WhenAnyPromise_9_t2D551F16D8A9A247E0C45E7698A6A7A3CCDB7757* L_3 = ___0_self;
		Exception_t* L_4 = V_1;
		bool L_5;
		L_5 = ((  bool (*) (UniTaskCompletionSourceCore_1_t1911EC18C6234A1A4E814CB064F127B40A3F2BD1*, Exception_t*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 115)))((((UniTaskCompletionSourceCore_1_t1911EC18C6234A1A4E814CB064F127B40A3F2BD1*)il2cpp_codegen_get_instance_field_data_pointer(L_3, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),1)))), L_4, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 115));
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_0098;
	}

IL_001d:
	{
		WhenAnyPromise_9_t2D551F16D8A9A247E0C45E7698A6A7A3CCDB7757* L_6 = ___0_self;
		int32_t L_7;
		L_7 = Interlocked_Increment_m3C240C32E8D9544EC050B74D4F28EEB58F1F9309((((int32_t*)il2cpp_codegen_get_instance_field_data_pointer(L_6, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),0)))), NULL);
		V_2 = (bool)((((int32_t)L_7) == ((int32_t)1))? 1 : 0);
		bool L_8 = V_2;
		if (!L_8)
		{
			goto IL_0098;
		}
	}
	{
		WhenAnyPromise_9_t2D551F16D8A9A247E0C45E7698A6A7A3CCDB7757* L_9 = ___0_self;
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_3, SizeOf_T1_t12224CDB8CF3A7A9B85AE3735573C8F4E483F5C8);
		il2cpp_codegen_memcpy(L_10, V_3, SizeOf_T1_t12224CDB8CF3A7A9B85AE3735573C8F4E483F5C8);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_4, SizeOf_T2_tAD4D518AD8F8B278644DA50484CBC022467C03C8);
		il2cpp_codegen_memcpy(L_11, V_4, SizeOf_T2_tAD4D518AD8F8B278644DA50484CBC022467C03C8);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_5, SizeOf_T3_t66D9D606A6E8AE1FFD2214BAC540BA2C6A05F30E);
		il2cpp_codegen_memcpy(L_12, V_5, SizeOf_T3_t66D9D606A6E8AE1FFD2214BAC540BA2C6A05F30E);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_6, SizeOf_T4_t72EE5E3145D8FF5738B17FFF6A56CD3596448171);
		il2cpp_codegen_memcpy(L_13, V_6, SizeOf_T4_t72EE5E3145D8FF5738B17FFF6A56CD3596448171);
		il2cpp_codegen_memcpy(L_14, V_0, SizeOf_T5_tBAA81B6ABC55C264673BFAB9E6595906EACF4385);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_7, SizeOf_T6_tDBE701EEE385225ABD2D5FE3A33BBB44DAB77FA1);
		il2cpp_codegen_memcpy(L_15, V_7, SizeOf_T6_tDBE701EEE385225ABD2D5FE3A33BBB44DAB77FA1);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_8, SizeOf_T7_tB1C7E0C236178B74109F4EF31E447F56A86DBA34);
		il2cpp_codegen_memcpy(L_16, V_8, SizeOf_T7_tB1C7E0C236178B74109F4EF31E447F56A86DBA34);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_9, SizeOf_T8_tAF9A0784F75559C808ECBC453336127EB8DA3A7A);
		il2cpp_codegen_memcpy(L_17, V_9, SizeOf_T8_tAF9A0784F75559C808ECBC453336127EB8DA3A7A);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_10, SizeOf_T9_tB9C3488598121213AB36E222281D28C99542EDB2);
		il2cpp_codegen_memcpy(L_18, V_10, SizeOf_T9_tB9C3488598121213AB36E222281D28C99542EDB2);
		memset(L_22, 0, SizeOf_ValueTuple_3_t296AC28BABFD66CC8A156720B3F2B3437143A60F);
		ValueTuple_3__ctor_mAB800E7134D8E52646FD55A8B2979AC908028759((ValueTuple_3_t182F852EE39DD805E380FD93762C931C933ACE98*)L_22, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 122)) ? il2cpp_codegen_memcpy(L_19, L_16, SizeOf_T7_tB1C7E0C236178B74109F4EF31E447F56A86DBA34): *(void**)L_16), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 123)) ? il2cpp_codegen_memcpy(L_20, L_17, SizeOf_T8_tAF9A0784F75559C808ECBC453336127EB8DA3A7A): *(void**)L_17), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 124)) ? il2cpp_codegen_memcpy(L_21, L_18, SizeOf_T9_tB9C3488598121213AB36E222281D28C99542EDB2): *(void**)L_18), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 126));
		memset(L_30, 0, SizeOf_ValueTuple_8_t8393F807A09311AE5C3F77F38D87FF98B57A7A47);
		ValueTuple_8__ctor_m5FDE8CF38A97A3D5FC7C364C3467B819664360EE((ValueTuple_8_tF94FE992101922E2A97F08D019A9EBDDA748DCB2*)L_30, 4, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 113)) ? il2cpp_codegen_memcpy(L_23, L_10, SizeOf_T1_t12224CDB8CF3A7A9B85AE3735573C8F4E483F5C8): *(void**)L_10), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 117)) ? il2cpp_codegen_memcpy(L_24, L_11, SizeOf_T2_tAD4D518AD8F8B278644DA50484CBC022467C03C8): *(void**)L_11), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 118)) ? il2cpp_codegen_memcpy(L_25, L_12, SizeOf_T3_t66D9D606A6E8AE1FFD2214BAC540BA2C6A05F30E): *(void**)L_12), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 119)) ? il2cpp_codegen_memcpy(L_26, L_13, SizeOf_T4_t72EE5E3145D8FF5738B17FFF6A56CD3596448171): *(void**)L_13), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 120)) ? il2cpp_codegen_memcpy(L_27, L_14, SizeOf_T5_tBAA81B6ABC55C264673BFAB9E6595906EACF4385): *(void**)L_14), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 121)) ? il2cpp_codegen_memcpy(L_28, L_15, SizeOf_T6_tDBE701EEE385225ABD2D5FE3A33BBB44DAB77FA1): *(void**)L_15), il2cpp_codegen_memcpy(L_29, L_22, SizeOf_ValueTuple_3_t296AC28BABFD66CC8A156720B3F2B3437143A60F), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 128));
		bool L_31;
		L_31 = InvokerFuncInvoker1< bool, ValueTuple_8_tF94FE992101922E2A97F08D019A9EBDDA748DCB2 >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 129)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 129), (((UniTaskCompletionSourceCore_1_t1911EC18C6234A1A4E814CB064F127B40A3F2BD1*)il2cpp_codegen_get_instance_field_data_pointer(L_9, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),1)))), L_30);
	}

IL_0098:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhenAnyPromise_9_TryInvokeContinuationT6_m1E268A14435A676642142013F00FA0DC43D45CB1_gshared (WhenAnyPromise_9_t2D551F16D8A9A247E0C45E7698A6A7A3CCDB7757* ___0_self, Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* ___1_awaiter, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T6_tDBE701EEE385225ABD2D5FE3A33BBB44DAB77FA1 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 121));
	const uint32_t SizeOf_T1_t12224CDB8CF3A7A9B85AE3735573C8F4E483F5C8 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 113));
	const uint32_t SizeOf_T2_tAD4D518AD8F8B278644DA50484CBC022467C03C8 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 117));
	const uint32_t SizeOf_T3_t66D9D606A6E8AE1FFD2214BAC540BA2C6A05F30E = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 118));
	const uint32_t SizeOf_T4_t72EE5E3145D8FF5738B17FFF6A56CD3596448171 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 119));
	const uint32_t SizeOf_T5_tBAA81B6ABC55C264673BFAB9E6595906EACF4385 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 120));
	const uint32_t SizeOf_T7_tB1C7E0C236178B74109F4EF31E447F56A86DBA34 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 122));
	const uint32_t SizeOf_T8_tAF9A0784F75559C808ECBC453336127EB8DA3A7A = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 123));
	const uint32_t SizeOf_T9_tB9C3488598121213AB36E222281D28C99542EDB2 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 124));
	const uint32_t SizeOf_ValueTuple_3_t296AC28BABFD66CC8A156720B3F2B3437143A60F = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 125));
	const uint32_t SizeOf_ValueTuple_8_t8393F807A09311AE5C3F77F38D87FF98B57A7A47 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 127));
	const Il2CppFullySharedGenericAny L_10 = alloca(SizeOf_T1_t12224CDB8CF3A7A9B85AE3735573C8F4E483F5C8);
	const Il2CppFullySharedGenericAny L_23 = alloca(SizeOf_T1_t12224CDB8CF3A7A9B85AE3735573C8F4E483F5C8);
	const Il2CppFullySharedGenericAny L_11 = alloca(SizeOf_T2_tAD4D518AD8F8B278644DA50484CBC022467C03C8);
	const Il2CppFullySharedGenericAny L_24 = alloca(SizeOf_T2_tAD4D518AD8F8B278644DA50484CBC022467C03C8);
	const Il2CppFullySharedGenericAny L_12 = alloca(SizeOf_T3_t66D9D606A6E8AE1FFD2214BAC540BA2C6A05F30E);
	const Il2CppFullySharedGenericAny L_25 = alloca(SizeOf_T3_t66D9D606A6E8AE1FFD2214BAC540BA2C6A05F30E);
	const Il2CppFullySharedGenericAny L_13 = alloca(SizeOf_T4_t72EE5E3145D8FF5738B17FFF6A56CD3596448171);
	const Il2CppFullySharedGenericAny L_26 = alloca(SizeOf_T4_t72EE5E3145D8FF5738B17FFF6A56CD3596448171);
	const Il2CppFullySharedGenericAny L_14 = alloca(SizeOf_T5_tBAA81B6ABC55C264673BFAB9E6595906EACF4385);
	const Il2CppFullySharedGenericAny L_27 = alloca(SizeOf_T5_tBAA81B6ABC55C264673BFAB9E6595906EACF4385);
	const Il2CppFullySharedGenericAny L_1 = alloca(SizeOf_T6_tDBE701EEE385225ABD2D5FE3A33BBB44DAB77FA1);
	const Il2CppFullySharedGenericAny L_15 = L_1;
	const Il2CppFullySharedGenericAny L_28 = alloca(SizeOf_T6_tDBE701EEE385225ABD2D5FE3A33BBB44DAB77FA1);
	const Il2CppFullySharedGenericAny L_16 = alloca(SizeOf_T7_tB1C7E0C236178B74109F4EF31E447F56A86DBA34);
	const Il2CppFullySharedGenericAny L_19 = alloca(SizeOf_T7_tB1C7E0C236178B74109F4EF31E447F56A86DBA34);
	const Il2CppFullySharedGenericAny L_17 = alloca(SizeOf_T8_tAF9A0784F75559C808ECBC453336127EB8DA3A7A);
	const Il2CppFullySharedGenericAny L_20 = alloca(SizeOf_T8_tAF9A0784F75559C808ECBC453336127EB8DA3A7A);
	const Il2CppFullySharedGenericAny L_18 = alloca(SizeOf_T9_tB9C3488598121213AB36E222281D28C99542EDB2);
	const Il2CppFullySharedGenericAny L_21 = alloca(SizeOf_T9_tB9C3488598121213AB36E222281D28C99542EDB2);
	const ValueTuple_3_t182F852EE39DD805E380FD93762C931C933ACE98 L_22 = alloca(SizeOf_ValueTuple_3_t296AC28BABFD66CC8A156720B3F2B3437143A60F);
	const ValueTuple_3_t182F852EE39DD805E380FD93762C931C933ACE98 L_29 = alloca(SizeOf_ValueTuple_3_t296AC28BABFD66CC8A156720B3F2B3437143A60F);
	const ValueTuple_8_tF94FE992101922E2A97F08D019A9EBDDA748DCB2 L_30 = alloca(SizeOf_ValueTuple_8_t8393F807A09311AE5C3F77F38D87FF98B57A7A47);
	Il2CppFullySharedGenericAny V_0 = alloca(SizeOf_T6_tDBE701EEE385225ABD2D5FE3A33BBB44DAB77FA1);
	memset(V_0, 0, SizeOf_T6_tDBE701EEE385225ABD2D5FE3A33BBB44DAB77FA1);
	Exception_t* V_1 = NULL;
	bool V_2 = false;
	Il2CppFullySharedGenericAny V_3 = alloca(SizeOf_T1_t12224CDB8CF3A7A9B85AE3735573C8F4E483F5C8);
	memset(V_3, 0, SizeOf_T1_t12224CDB8CF3A7A9B85AE3735573C8F4E483F5C8);
	Il2CppFullySharedGenericAny V_4 = alloca(SizeOf_T2_tAD4D518AD8F8B278644DA50484CBC022467C03C8);
	memset(V_4, 0, SizeOf_T2_tAD4D518AD8F8B278644DA50484CBC022467C03C8);
	Il2CppFullySharedGenericAny V_5 = alloca(SizeOf_T3_t66D9D606A6E8AE1FFD2214BAC540BA2C6A05F30E);
	memset(V_5, 0, SizeOf_T3_t66D9D606A6E8AE1FFD2214BAC540BA2C6A05F30E);
	Il2CppFullySharedGenericAny V_6 = alloca(SizeOf_T4_t72EE5E3145D8FF5738B17FFF6A56CD3596448171);
	memset(V_6, 0, SizeOf_T4_t72EE5E3145D8FF5738B17FFF6A56CD3596448171);
	Il2CppFullySharedGenericAny V_7 = alloca(SizeOf_T5_tBAA81B6ABC55C264673BFAB9E6595906EACF4385);
	memset(V_7, 0, SizeOf_T5_tBAA81B6ABC55C264673BFAB9E6595906EACF4385);
	Il2CppFullySharedGenericAny V_8 = alloca(SizeOf_T7_tB1C7E0C236178B74109F4EF31E447F56A86DBA34);
	memset(V_8, 0, SizeOf_T7_tB1C7E0C236178B74109F4EF31E447F56A86DBA34);
	Il2CppFullySharedGenericAny V_9 = alloca(SizeOf_T8_tAF9A0784F75559C808ECBC453336127EB8DA3A7A);
	memset(V_9, 0, SizeOf_T8_tAF9A0784F75559C808ECBC453336127EB8DA3A7A);
	Il2CppFullySharedGenericAny V_10 = alloca(SizeOf_T9_tB9C3488598121213AB36E222281D28C99542EDB2);
	memset(V_10, 0, SizeOf_T9_tB9C3488598121213AB36E222281D28C99542EDB2);
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
	}
	try
	{
		Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* L_0 = ___1_awaiter;
		InvokerActionInvoker1< Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 134)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 134), L_0, (Il2CppFullySharedGenericAny*)L_1);
		il2cpp_codegen_memcpy(V_0, L_1, SizeOf_T6_tDBE701EEE385225ABD2D5FE3A33BBB44DAB77FA1);
		goto IL_001d;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&Exception_t_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_000c;
		}
		throw e;
	}

CATCH_000c:
	{
		Exception_t* L_2 = ((Exception_t*)IL2CPP_GET_ACTIVE_EXCEPTION(Exception_t*));;
		V_1 = L_2;
		WhenAnyPromise_9_t2D551F16D8A9A247E0C45E7698A6A7A3CCDB7757* L_3 = ___0_self;
		Exception_t* L_4 = V_1;
		bool L_5;
		L_5 = ((  bool (*) (UniTaskCompletionSourceCore_1_t1911EC18C6234A1A4E814CB064F127B40A3F2BD1*, Exception_t*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 115)))((((UniTaskCompletionSourceCore_1_t1911EC18C6234A1A4E814CB064F127B40A3F2BD1*)il2cpp_codegen_get_instance_field_data_pointer(L_3, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),1)))), L_4, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 115));
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_0098;
	}

IL_001d:
	{
		WhenAnyPromise_9_t2D551F16D8A9A247E0C45E7698A6A7A3CCDB7757* L_6 = ___0_self;
		int32_t L_7;
		L_7 = Interlocked_Increment_m3C240C32E8D9544EC050B74D4F28EEB58F1F9309((((int32_t*)il2cpp_codegen_get_instance_field_data_pointer(L_6, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),0)))), NULL);
		V_2 = (bool)((((int32_t)L_7) == ((int32_t)1))? 1 : 0);
		bool L_8 = V_2;
		if (!L_8)
		{
			goto IL_0098;
		}
	}
	{
		WhenAnyPromise_9_t2D551F16D8A9A247E0C45E7698A6A7A3CCDB7757* L_9 = ___0_self;
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_3, SizeOf_T1_t12224CDB8CF3A7A9B85AE3735573C8F4E483F5C8);
		il2cpp_codegen_memcpy(L_10, V_3, SizeOf_T1_t12224CDB8CF3A7A9B85AE3735573C8F4E483F5C8);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_4, SizeOf_T2_tAD4D518AD8F8B278644DA50484CBC022467C03C8);
		il2cpp_codegen_memcpy(L_11, V_4, SizeOf_T2_tAD4D518AD8F8B278644DA50484CBC022467C03C8);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_5, SizeOf_T3_t66D9D606A6E8AE1FFD2214BAC540BA2C6A05F30E);
		il2cpp_codegen_memcpy(L_12, V_5, SizeOf_T3_t66D9D606A6E8AE1FFD2214BAC540BA2C6A05F30E);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_6, SizeOf_T4_t72EE5E3145D8FF5738B17FFF6A56CD3596448171);
		il2cpp_codegen_memcpy(L_13, V_6, SizeOf_T4_t72EE5E3145D8FF5738B17FFF6A56CD3596448171);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_7, SizeOf_T5_tBAA81B6ABC55C264673BFAB9E6595906EACF4385);
		il2cpp_codegen_memcpy(L_14, V_7, SizeOf_T5_tBAA81B6ABC55C264673BFAB9E6595906EACF4385);
		il2cpp_codegen_memcpy(L_15, V_0, SizeOf_T6_tDBE701EEE385225ABD2D5FE3A33BBB44DAB77FA1);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_8, SizeOf_T7_tB1C7E0C236178B74109F4EF31E447F56A86DBA34);
		il2cpp_codegen_memcpy(L_16, V_8, SizeOf_T7_tB1C7E0C236178B74109F4EF31E447F56A86DBA34);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_9, SizeOf_T8_tAF9A0784F75559C808ECBC453336127EB8DA3A7A);
		il2cpp_codegen_memcpy(L_17, V_9, SizeOf_T8_tAF9A0784F75559C808ECBC453336127EB8DA3A7A);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_10, SizeOf_T9_tB9C3488598121213AB36E222281D28C99542EDB2);
		il2cpp_codegen_memcpy(L_18, V_10, SizeOf_T9_tB9C3488598121213AB36E222281D28C99542EDB2);
		memset(L_22, 0, SizeOf_ValueTuple_3_t296AC28BABFD66CC8A156720B3F2B3437143A60F);
		ValueTuple_3__ctor_mAB800E7134D8E52646FD55A8B2979AC908028759((ValueTuple_3_t182F852EE39DD805E380FD93762C931C933ACE98*)L_22, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 122)) ? il2cpp_codegen_memcpy(L_19, L_16, SizeOf_T7_tB1C7E0C236178B74109F4EF31E447F56A86DBA34): *(void**)L_16), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 123)) ? il2cpp_codegen_memcpy(L_20, L_17, SizeOf_T8_tAF9A0784F75559C808ECBC453336127EB8DA3A7A): *(void**)L_17), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 124)) ? il2cpp_codegen_memcpy(L_21, L_18, SizeOf_T9_tB9C3488598121213AB36E222281D28C99542EDB2): *(void**)L_18), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 126));
		memset(L_30, 0, SizeOf_ValueTuple_8_t8393F807A09311AE5C3F77F38D87FF98B57A7A47);
		ValueTuple_8__ctor_m5FDE8CF38A97A3D5FC7C364C3467B819664360EE((ValueTuple_8_tF94FE992101922E2A97F08D019A9EBDDA748DCB2*)L_30, 5, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 113)) ? il2cpp_codegen_memcpy(L_23, L_10, SizeOf_T1_t12224CDB8CF3A7A9B85AE3735573C8F4E483F5C8): *(void**)L_10), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 117)) ? il2cpp_codegen_memcpy(L_24, L_11, SizeOf_T2_tAD4D518AD8F8B278644DA50484CBC022467C03C8): *(void**)L_11), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 118)) ? il2cpp_codegen_memcpy(L_25, L_12, SizeOf_T3_t66D9D606A6E8AE1FFD2214BAC540BA2C6A05F30E): *(void**)L_12), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 119)) ? il2cpp_codegen_memcpy(L_26, L_13, SizeOf_T4_t72EE5E3145D8FF5738B17FFF6A56CD3596448171): *(void**)L_13), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 120)) ? il2cpp_codegen_memcpy(L_27, L_14, SizeOf_T5_tBAA81B6ABC55C264673BFAB9E6595906EACF4385): *(void**)L_14), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 121)) ? il2cpp_codegen_memcpy(L_28, L_15, SizeOf_T6_tDBE701EEE385225ABD2D5FE3A33BBB44DAB77FA1): *(void**)L_15), il2cpp_codegen_memcpy(L_29, L_22, SizeOf_ValueTuple_3_t296AC28BABFD66CC8A156720B3F2B3437143A60F), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 128));
		bool L_31;
		L_31 = InvokerFuncInvoker1< bool, ValueTuple_8_tF94FE992101922E2A97F08D019A9EBDDA748DCB2 >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 129)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 129), (((UniTaskCompletionSourceCore_1_t1911EC18C6234A1A4E814CB064F127B40A3F2BD1*)il2cpp_codegen_get_instance_field_data_pointer(L_9, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),1)))), L_30);
	}

IL_0098:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhenAnyPromise_9_TryInvokeContinuationT7_mE0EF0E9A9E0CA04B64E3E8E5AE1ED3F00D3B16ED_gshared (WhenAnyPromise_9_t2D551F16D8A9A247E0C45E7698A6A7A3CCDB7757* ___0_self, Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* ___1_awaiter, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T7_tB1C7E0C236178B74109F4EF31E447F56A86DBA34 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 122));
	const uint32_t SizeOf_T1_t12224CDB8CF3A7A9B85AE3735573C8F4E483F5C8 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 113));
	const uint32_t SizeOf_T2_tAD4D518AD8F8B278644DA50484CBC022467C03C8 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 117));
	const uint32_t SizeOf_T3_t66D9D606A6E8AE1FFD2214BAC540BA2C6A05F30E = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 118));
	const uint32_t SizeOf_T4_t72EE5E3145D8FF5738B17FFF6A56CD3596448171 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 119));
	const uint32_t SizeOf_T5_tBAA81B6ABC55C264673BFAB9E6595906EACF4385 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 120));
	const uint32_t SizeOf_T6_tDBE701EEE385225ABD2D5FE3A33BBB44DAB77FA1 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 121));
	const uint32_t SizeOf_T8_tAF9A0784F75559C808ECBC453336127EB8DA3A7A = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 123));
	const uint32_t SizeOf_T9_tB9C3488598121213AB36E222281D28C99542EDB2 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 124));
	const uint32_t SizeOf_ValueTuple_3_t296AC28BABFD66CC8A156720B3F2B3437143A60F = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 125));
	const uint32_t SizeOf_ValueTuple_8_t8393F807A09311AE5C3F77F38D87FF98B57A7A47 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 127));
	const Il2CppFullySharedGenericAny L_10 = alloca(SizeOf_T1_t12224CDB8CF3A7A9B85AE3735573C8F4E483F5C8);
	const Il2CppFullySharedGenericAny L_23 = alloca(SizeOf_T1_t12224CDB8CF3A7A9B85AE3735573C8F4E483F5C8);
	const Il2CppFullySharedGenericAny L_11 = alloca(SizeOf_T2_tAD4D518AD8F8B278644DA50484CBC022467C03C8);
	const Il2CppFullySharedGenericAny L_24 = alloca(SizeOf_T2_tAD4D518AD8F8B278644DA50484CBC022467C03C8);
	const Il2CppFullySharedGenericAny L_12 = alloca(SizeOf_T3_t66D9D606A6E8AE1FFD2214BAC540BA2C6A05F30E);
	const Il2CppFullySharedGenericAny L_25 = alloca(SizeOf_T3_t66D9D606A6E8AE1FFD2214BAC540BA2C6A05F30E);
	const Il2CppFullySharedGenericAny L_13 = alloca(SizeOf_T4_t72EE5E3145D8FF5738B17FFF6A56CD3596448171);
	const Il2CppFullySharedGenericAny L_26 = alloca(SizeOf_T4_t72EE5E3145D8FF5738B17FFF6A56CD3596448171);
	const Il2CppFullySharedGenericAny L_14 = alloca(SizeOf_T5_tBAA81B6ABC55C264673BFAB9E6595906EACF4385);
	const Il2CppFullySharedGenericAny L_27 = alloca(SizeOf_T5_tBAA81B6ABC55C264673BFAB9E6595906EACF4385);
	const Il2CppFullySharedGenericAny L_15 = alloca(SizeOf_T6_tDBE701EEE385225ABD2D5FE3A33BBB44DAB77FA1);
	const Il2CppFullySharedGenericAny L_28 = alloca(SizeOf_T6_tDBE701EEE385225ABD2D5FE3A33BBB44DAB77FA1);
	const Il2CppFullySharedGenericAny L_1 = alloca(SizeOf_T7_tB1C7E0C236178B74109F4EF31E447F56A86DBA34);
	const Il2CppFullySharedGenericAny L_16 = L_1;
	const Il2CppFullySharedGenericAny L_19 = alloca(SizeOf_T7_tB1C7E0C236178B74109F4EF31E447F56A86DBA34);
	const Il2CppFullySharedGenericAny L_17 = alloca(SizeOf_T8_tAF9A0784F75559C808ECBC453336127EB8DA3A7A);
	const Il2CppFullySharedGenericAny L_20 = alloca(SizeOf_T8_tAF9A0784F75559C808ECBC453336127EB8DA3A7A);
	const Il2CppFullySharedGenericAny L_18 = alloca(SizeOf_T9_tB9C3488598121213AB36E222281D28C99542EDB2);
	const Il2CppFullySharedGenericAny L_21 = alloca(SizeOf_T9_tB9C3488598121213AB36E222281D28C99542EDB2);
	const ValueTuple_3_t182F852EE39DD805E380FD93762C931C933ACE98 L_22 = alloca(SizeOf_ValueTuple_3_t296AC28BABFD66CC8A156720B3F2B3437143A60F);
	const ValueTuple_3_t182F852EE39DD805E380FD93762C931C933ACE98 L_29 = alloca(SizeOf_ValueTuple_3_t296AC28BABFD66CC8A156720B3F2B3437143A60F);
	const ValueTuple_8_tF94FE992101922E2A97F08D019A9EBDDA748DCB2 L_30 = alloca(SizeOf_ValueTuple_8_t8393F807A09311AE5C3F77F38D87FF98B57A7A47);
	Il2CppFullySharedGenericAny V_0 = alloca(SizeOf_T7_tB1C7E0C236178B74109F4EF31E447F56A86DBA34);
	memset(V_0, 0, SizeOf_T7_tB1C7E0C236178B74109F4EF31E447F56A86DBA34);
	Exception_t* V_1 = NULL;
	bool V_2 = false;
	Il2CppFullySharedGenericAny V_3 = alloca(SizeOf_T1_t12224CDB8CF3A7A9B85AE3735573C8F4E483F5C8);
	memset(V_3, 0, SizeOf_T1_t12224CDB8CF3A7A9B85AE3735573C8F4E483F5C8);
	Il2CppFullySharedGenericAny V_4 = alloca(SizeOf_T2_tAD4D518AD8F8B278644DA50484CBC022467C03C8);
	memset(V_4, 0, SizeOf_T2_tAD4D518AD8F8B278644DA50484CBC022467C03C8);
	Il2CppFullySharedGenericAny V_5 = alloca(SizeOf_T3_t66D9D606A6E8AE1FFD2214BAC540BA2C6A05F30E);
	memset(V_5, 0, SizeOf_T3_t66D9D606A6E8AE1FFD2214BAC540BA2C6A05F30E);
	Il2CppFullySharedGenericAny V_6 = alloca(SizeOf_T4_t72EE5E3145D8FF5738B17FFF6A56CD3596448171);
	memset(V_6, 0, SizeOf_T4_t72EE5E3145D8FF5738B17FFF6A56CD3596448171);
	Il2CppFullySharedGenericAny V_7 = alloca(SizeOf_T5_tBAA81B6ABC55C264673BFAB9E6595906EACF4385);
	memset(V_7, 0, SizeOf_T5_tBAA81B6ABC55C264673BFAB9E6595906EACF4385);
	Il2CppFullySharedGenericAny V_8 = alloca(SizeOf_T6_tDBE701EEE385225ABD2D5FE3A33BBB44DAB77FA1);
	memset(V_8, 0, SizeOf_T6_tDBE701EEE385225ABD2D5FE3A33BBB44DAB77FA1);
	Il2CppFullySharedGenericAny V_9 = alloca(SizeOf_T8_tAF9A0784F75559C808ECBC453336127EB8DA3A7A);
	memset(V_9, 0, SizeOf_T8_tAF9A0784F75559C808ECBC453336127EB8DA3A7A);
	Il2CppFullySharedGenericAny V_10 = alloca(SizeOf_T9_tB9C3488598121213AB36E222281D28C99542EDB2);
	memset(V_10, 0, SizeOf_T9_tB9C3488598121213AB36E222281D28C99542EDB2);
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
	}
	try
	{
		Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* L_0 = ___1_awaiter;
		InvokerActionInvoker1< Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 135)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 135), L_0, (Il2CppFullySharedGenericAny*)L_1);
		il2cpp_codegen_memcpy(V_0, L_1, SizeOf_T7_tB1C7E0C236178B74109F4EF31E447F56A86DBA34);
		goto IL_001d;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&Exception_t_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_000c;
		}
		throw e;
	}

CATCH_000c:
	{
		Exception_t* L_2 = ((Exception_t*)IL2CPP_GET_ACTIVE_EXCEPTION(Exception_t*));;
		V_1 = L_2;
		WhenAnyPromise_9_t2D551F16D8A9A247E0C45E7698A6A7A3CCDB7757* L_3 = ___0_self;
		Exception_t* L_4 = V_1;
		bool L_5;
		L_5 = ((  bool (*) (UniTaskCompletionSourceCore_1_t1911EC18C6234A1A4E814CB064F127B40A3F2BD1*, Exception_t*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 115)))((((UniTaskCompletionSourceCore_1_t1911EC18C6234A1A4E814CB064F127B40A3F2BD1*)il2cpp_codegen_get_instance_field_data_pointer(L_3, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),1)))), L_4, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 115));
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_0098;
	}

IL_001d:
	{
		WhenAnyPromise_9_t2D551F16D8A9A247E0C45E7698A6A7A3CCDB7757* L_6 = ___0_self;
		int32_t L_7;
		L_7 = Interlocked_Increment_m3C240C32E8D9544EC050B74D4F28EEB58F1F9309((((int32_t*)il2cpp_codegen_get_instance_field_data_pointer(L_6, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),0)))), NULL);
		V_2 = (bool)((((int32_t)L_7) == ((int32_t)1))? 1 : 0);
		bool L_8 = V_2;
		if (!L_8)
		{
			goto IL_0098;
		}
	}
	{
		WhenAnyPromise_9_t2D551F16D8A9A247E0C45E7698A6A7A3CCDB7757* L_9 = ___0_self;
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_3, SizeOf_T1_t12224CDB8CF3A7A9B85AE3735573C8F4E483F5C8);
		il2cpp_codegen_memcpy(L_10, V_3, SizeOf_T1_t12224CDB8CF3A7A9B85AE3735573C8F4E483F5C8);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_4, SizeOf_T2_tAD4D518AD8F8B278644DA50484CBC022467C03C8);
		il2cpp_codegen_memcpy(L_11, V_4, SizeOf_T2_tAD4D518AD8F8B278644DA50484CBC022467C03C8);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_5, SizeOf_T3_t66D9D606A6E8AE1FFD2214BAC540BA2C6A05F30E);
		il2cpp_codegen_memcpy(L_12, V_5, SizeOf_T3_t66D9D606A6E8AE1FFD2214BAC540BA2C6A05F30E);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_6, SizeOf_T4_t72EE5E3145D8FF5738B17FFF6A56CD3596448171);
		il2cpp_codegen_memcpy(L_13, V_6, SizeOf_T4_t72EE5E3145D8FF5738B17FFF6A56CD3596448171);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_7, SizeOf_T5_tBAA81B6ABC55C264673BFAB9E6595906EACF4385);
		il2cpp_codegen_memcpy(L_14, V_7, SizeOf_T5_tBAA81B6ABC55C264673BFAB9E6595906EACF4385);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_8, SizeOf_T6_tDBE701EEE385225ABD2D5FE3A33BBB44DAB77FA1);
		il2cpp_codegen_memcpy(L_15, V_8, SizeOf_T6_tDBE701EEE385225ABD2D5FE3A33BBB44DAB77FA1);
		il2cpp_codegen_memcpy(L_16, V_0, SizeOf_T7_tB1C7E0C236178B74109F4EF31E447F56A86DBA34);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_9, SizeOf_T8_tAF9A0784F75559C808ECBC453336127EB8DA3A7A);
		il2cpp_codegen_memcpy(L_17, V_9, SizeOf_T8_tAF9A0784F75559C808ECBC453336127EB8DA3A7A);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_10, SizeOf_T9_tB9C3488598121213AB36E222281D28C99542EDB2);
		il2cpp_codegen_memcpy(L_18, V_10, SizeOf_T9_tB9C3488598121213AB36E222281D28C99542EDB2);
		memset(L_22, 0, SizeOf_ValueTuple_3_t296AC28BABFD66CC8A156720B3F2B3437143A60F);
		ValueTuple_3__ctor_mAB800E7134D8E52646FD55A8B2979AC908028759((ValueTuple_3_t182F852EE39DD805E380FD93762C931C933ACE98*)L_22, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 122)) ? il2cpp_codegen_memcpy(L_19, L_16, SizeOf_T7_tB1C7E0C236178B74109F4EF31E447F56A86DBA34): *(void**)L_16), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 123)) ? il2cpp_codegen_memcpy(L_20, L_17, SizeOf_T8_tAF9A0784F75559C808ECBC453336127EB8DA3A7A): *(void**)L_17), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 124)) ? il2cpp_codegen_memcpy(L_21, L_18, SizeOf_T9_tB9C3488598121213AB36E222281D28C99542EDB2): *(void**)L_18), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 126));
		memset(L_30, 0, SizeOf_ValueTuple_8_t8393F807A09311AE5C3F77F38D87FF98B57A7A47);
		ValueTuple_8__ctor_m5FDE8CF38A97A3D5FC7C364C3467B819664360EE((ValueTuple_8_tF94FE992101922E2A97F08D019A9EBDDA748DCB2*)L_30, 6, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 113)) ? il2cpp_codegen_memcpy(L_23, L_10, SizeOf_T1_t12224CDB8CF3A7A9B85AE3735573C8F4E483F5C8): *(void**)L_10), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 117)) ? il2cpp_codegen_memcpy(L_24, L_11, SizeOf_T2_tAD4D518AD8F8B278644DA50484CBC022467C03C8): *(void**)L_11), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 118)) ? il2cpp_codegen_memcpy(L_25, L_12, SizeOf_T3_t66D9D606A6E8AE1FFD2214BAC540BA2C6A05F30E): *(void**)L_12), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 119)) ? il2cpp_codegen_memcpy(L_26, L_13, SizeOf_T4_t72EE5E3145D8FF5738B17FFF6A56CD3596448171): *(void**)L_13), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 120)) ? il2cpp_codegen_memcpy(L_27, L_14, SizeOf_T5_tBAA81B6ABC55C264673BFAB9E6595906EACF4385): *(void**)L_14), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 121)) ? il2cpp_codegen_memcpy(L_28, L_15, SizeOf_T6_tDBE701EEE385225ABD2D5FE3A33BBB44DAB77FA1): *(void**)L_15), il2cpp_codegen_memcpy(L_29, L_22, SizeOf_ValueTuple_3_t296AC28BABFD66CC8A156720B3F2B3437143A60F), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 128));
		bool L_31;
		L_31 = InvokerFuncInvoker1< bool, ValueTuple_8_tF94FE992101922E2A97F08D019A9EBDDA748DCB2 >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 129)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 129), (((UniTaskCompletionSourceCore_1_t1911EC18C6234A1A4E814CB064F127B40A3F2BD1*)il2cpp_codegen_get_instance_field_data_pointer(L_9, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),1)))), L_30);
	}

IL_0098:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhenAnyPromise_9_TryInvokeContinuationT8_m5FC1B728069A4CDC86ED96AE614CB436DEA8A921_gshared (WhenAnyPromise_9_t2D551F16D8A9A247E0C45E7698A6A7A3CCDB7757* ___0_self, Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* ___1_awaiter, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T8_tAF9A0784F75559C808ECBC453336127EB8DA3A7A = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 123));
	const uint32_t SizeOf_T1_t12224CDB8CF3A7A9B85AE3735573C8F4E483F5C8 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 113));
	const uint32_t SizeOf_T2_tAD4D518AD8F8B278644DA50484CBC022467C03C8 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 117));
	const uint32_t SizeOf_T3_t66D9D606A6E8AE1FFD2214BAC540BA2C6A05F30E = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 118));
	const uint32_t SizeOf_T4_t72EE5E3145D8FF5738B17FFF6A56CD3596448171 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 119));
	const uint32_t SizeOf_T5_tBAA81B6ABC55C264673BFAB9E6595906EACF4385 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 120));
	const uint32_t SizeOf_T6_tDBE701EEE385225ABD2D5FE3A33BBB44DAB77FA1 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 121));
	const uint32_t SizeOf_T7_tB1C7E0C236178B74109F4EF31E447F56A86DBA34 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 122));
	const uint32_t SizeOf_T9_tB9C3488598121213AB36E222281D28C99542EDB2 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 124));
	const uint32_t SizeOf_ValueTuple_3_t296AC28BABFD66CC8A156720B3F2B3437143A60F = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 125));
	const uint32_t SizeOf_ValueTuple_8_t8393F807A09311AE5C3F77F38D87FF98B57A7A47 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 127));
	const Il2CppFullySharedGenericAny L_10 = alloca(SizeOf_T1_t12224CDB8CF3A7A9B85AE3735573C8F4E483F5C8);
	const Il2CppFullySharedGenericAny L_23 = alloca(SizeOf_T1_t12224CDB8CF3A7A9B85AE3735573C8F4E483F5C8);
	const Il2CppFullySharedGenericAny L_11 = alloca(SizeOf_T2_tAD4D518AD8F8B278644DA50484CBC022467C03C8);
	const Il2CppFullySharedGenericAny L_24 = alloca(SizeOf_T2_tAD4D518AD8F8B278644DA50484CBC022467C03C8);
	const Il2CppFullySharedGenericAny L_12 = alloca(SizeOf_T3_t66D9D606A6E8AE1FFD2214BAC540BA2C6A05F30E);
	const Il2CppFullySharedGenericAny L_25 = alloca(SizeOf_T3_t66D9D606A6E8AE1FFD2214BAC540BA2C6A05F30E);
	const Il2CppFullySharedGenericAny L_13 = alloca(SizeOf_T4_t72EE5E3145D8FF5738B17FFF6A56CD3596448171);
	const Il2CppFullySharedGenericAny L_26 = alloca(SizeOf_T4_t72EE5E3145D8FF5738B17FFF6A56CD3596448171);
	const Il2CppFullySharedGenericAny L_14 = alloca(SizeOf_T5_tBAA81B6ABC55C264673BFAB9E6595906EACF4385);
	const Il2CppFullySharedGenericAny L_27 = alloca(SizeOf_T5_tBAA81B6ABC55C264673BFAB9E6595906EACF4385);
	const Il2CppFullySharedGenericAny L_15 = alloca(SizeOf_T6_tDBE701EEE385225ABD2D5FE3A33BBB44DAB77FA1);
	const Il2CppFullySharedGenericAny L_28 = alloca(SizeOf_T6_tDBE701EEE385225ABD2D5FE3A33BBB44DAB77FA1);
	const Il2CppFullySharedGenericAny L_16 = alloca(SizeOf_T7_tB1C7E0C236178B74109F4EF31E447F56A86DBA34);
	const Il2CppFullySharedGenericAny L_19 = alloca(SizeOf_T7_tB1C7E0C236178B74109F4EF31E447F56A86DBA34);
	const Il2CppFullySharedGenericAny L_1 = alloca(SizeOf_T8_tAF9A0784F75559C808ECBC453336127EB8DA3A7A);
	const Il2CppFullySharedGenericAny L_17 = L_1;
	const Il2CppFullySharedGenericAny L_20 = alloca(SizeOf_T8_tAF9A0784F75559C808ECBC453336127EB8DA3A7A);
	const Il2CppFullySharedGenericAny L_18 = alloca(SizeOf_T9_tB9C3488598121213AB36E222281D28C99542EDB2);
	const Il2CppFullySharedGenericAny L_21 = alloca(SizeOf_T9_tB9C3488598121213AB36E222281D28C99542EDB2);
	const ValueTuple_3_t182F852EE39DD805E380FD93762C931C933ACE98 L_22 = alloca(SizeOf_ValueTuple_3_t296AC28BABFD66CC8A156720B3F2B3437143A60F);
	const ValueTuple_3_t182F852EE39DD805E380FD93762C931C933ACE98 L_29 = alloca(SizeOf_ValueTuple_3_t296AC28BABFD66CC8A156720B3F2B3437143A60F);
	const ValueTuple_8_tF94FE992101922E2A97F08D019A9EBDDA748DCB2 L_30 = alloca(SizeOf_ValueTuple_8_t8393F807A09311AE5C3F77F38D87FF98B57A7A47);
	Il2CppFullySharedGenericAny V_0 = alloca(SizeOf_T8_tAF9A0784F75559C808ECBC453336127EB8DA3A7A);
	memset(V_0, 0, SizeOf_T8_tAF9A0784F75559C808ECBC453336127EB8DA3A7A);
	Exception_t* V_1 = NULL;
	bool V_2 = false;
	Il2CppFullySharedGenericAny V_3 = alloca(SizeOf_T1_t12224CDB8CF3A7A9B85AE3735573C8F4E483F5C8);
	memset(V_3, 0, SizeOf_T1_t12224CDB8CF3A7A9B85AE3735573C8F4E483F5C8);
	Il2CppFullySharedGenericAny V_4 = alloca(SizeOf_T2_tAD4D518AD8F8B278644DA50484CBC022467C03C8);
	memset(V_4, 0, SizeOf_T2_tAD4D518AD8F8B278644DA50484CBC022467C03C8);
	Il2CppFullySharedGenericAny V_5 = alloca(SizeOf_T3_t66D9D606A6E8AE1FFD2214BAC540BA2C6A05F30E);
	memset(V_5, 0, SizeOf_T3_t66D9D606A6E8AE1FFD2214BAC540BA2C6A05F30E);
	Il2CppFullySharedGenericAny V_6 = alloca(SizeOf_T4_t72EE5E3145D8FF5738B17FFF6A56CD3596448171);
	memset(V_6, 0, SizeOf_T4_t72EE5E3145D8FF5738B17FFF6A56CD3596448171);
	Il2CppFullySharedGenericAny V_7 = alloca(SizeOf_T5_tBAA81B6ABC55C264673BFAB9E6595906EACF4385);
	memset(V_7, 0, SizeOf_T5_tBAA81B6ABC55C264673BFAB9E6595906EACF4385);
	Il2CppFullySharedGenericAny V_8 = alloca(SizeOf_T6_tDBE701EEE385225ABD2D5FE3A33BBB44DAB77FA1);
	memset(V_8, 0, SizeOf_T6_tDBE701EEE385225ABD2D5FE3A33BBB44DAB77FA1);
	Il2CppFullySharedGenericAny V_9 = alloca(SizeOf_T7_tB1C7E0C236178B74109F4EF31E447F56A86DBA34);
	memset(V_9, 0, SizeOf_T7_tB1C7E0C236178B74109F4EF31E447F56A86DBA34);
	Il2CppFullySharedGenericAny V_10 = alloca(SizeOf_T9_tB9C3488598121213AB36E222281D28C99542EDB2);
	memset(V_10, 0, SizeOf_T9_tB9C3488598121213AB36E222281D28C99542EDB2);
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
	}
	try
	{
		Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* L_0 = ___1_awaiter;
		InvokerActionInvoker1< Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 136)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 136), L_0, (Il2CppFullySharedGenericAny*)L_1);
		il2cpp_codegen_memcpy(V_0, L_1, SizeOf_T8_tAF9A0784F75559C808ECBC453336127EB8DA3A7A);
		goto IL_001d;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&Exception_t_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_000c;
		}
		throw e;
	}

CATCH_000c:
	{
		Exception_t* L_2 = ((Exception_t*)IL2CPP_GET_ACTIVE_EXCEPTION(Exception_t*));;
		V_1 = L_2;
		WhenAnyPromise_9_t2D551F16D8A9A247E0C45E7698A6A7A3CCDB7757* L_3 = ___0_self;
		Exception_t* L_4 = V_1;
		bool L_5;
		L_5 = ((  bool (*) (UniTaskCompletionSourceCore_1_t1911EC18C6234A1A4E814CB064F127B40A3F2BD1*, Exception_t*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 115)))((((UniTaskCompletionSourceCore_1_t1911EC18C6234A1A4E814CB064F127B40A3F2BD1*)il2cpp_codegen_get_instance_field_data_pointer(L_3, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),1)))), L_4, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 115));
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_0098;
	}

IL_001d:
	{
		WhenAnyPromise_9_t2D551F16D8A9A247E0C45E7698A6A7A3CCDB7757* L_6 = ___0_self;
		int32_t L_7;
		L_7 = Interlocked_Increment_m3C240C32E8D9544EC050B74D4F28EEB58F1F9309((((int32_t*)il2cpp_codegen_get_instance_field_data_pointer(L_6, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),0)))), NULL);
		V_2 = (bool)((((int32_t)L_7) == ((int32_t)1))? 1 : 0);
		bool L_8 = V_2;
		if (!L_8)
		{
			goto IL_0098;
		}
	}
	{
		WhenAnyPromise_9_t2D551F16D8A9A247E0C45E7698A6A7A3CCDB7757* L_9 = ___0_self;
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_3, SizeOf_T1_t12224CDB8CF3A7A9B85AE3735573C8F4E483F5C8);
		il2cpp_codegen_memcpy(L_10, V_3, SizeOf_T1_t12224CDB8CF3A7A9B85AE3735573C8F4E483F5C8);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_4, SizeOf_T2_tAD4D518AD8F8B278644DA50484CBC022467C03C8);
		il2cpp_codegen_memcpy(L_11, V_4, SizeOf_T2_tAD4D518AD8F8B278644DA50484CBC022467C03C8);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_5, SizeOf_T3_t66D9D606A6E8AE1FFD2214BAC540BA2C6A05F30E);
		il2cpp_codegen_memcpy(L_12, V_5, SizeOf_T3_t66D9D606A6E8AE1FFD2214BAC540BA2C6A05F30E);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_6, SizeOf_T4_t72EE5E3145D8FF5738B17FFF6A56CD3596448171);
		il2cpp_codegen_memcpy(L_13, V_6, SizeOf_T4_t72EE5E3145D8FF5738B17FFF6A56CD3596448171);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_7, SizeOf_T5_tBAA81B6ABC55C264673BFAB9E6595906EACF4385);
		il2cpp_codegen_memcpy(L_14, V_7, SizeOf_T5_tBAA81B6ABC55C264673BFAB9E6595906EACF4385);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_8, SizeOf_T6_tDBE701EEE385225ABD2D5FE3A33BBB44DAB77FA1);
		il2cpp_codegen_memcpy(L_15, V_8, SizeOf_T6_tDBE701EEE385225ABD2D5FE3A33BBB44DAB77FA1);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_9, SizeOf_T7_tB1C7E0C236178B74109F4EF31E447F56A86DBA34);
		il2cpp_codegen_memcpy(L_16, V_9, SizeOf_T7_tB1C7E0C236178B74109F4EF31E447F56A86DBA34);
		il2cpp_codegen_memcpy(L_17, V_0, SizeOf_T8_tAF9A0784F75559C808ECBC453336127EB8DA3A7A);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_10, SizeOf_T9_tB9C3488598121213AB36E222281D28C99542EDB2);
		il2cpp_codegen_memcpy(L_18, V_10, SizeOf_T9_tB9C3488598121213AB36E222281D28C99542EDB2);
		memset(L_22, 0, SizeOf_ValueTuple_3_t296AC28BABFD66CC8A156720B3F2B3437143A60F);
		ValueTuple_3__ctor_mAB800E7134D8E52646FD55A8B2979AC908028759((ValueTuple_3_t182F852EE39DD805E380FD93762C931C933ACE98*)L_22, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 122)) ? il2cpp_codegen_memcpy(L_19, L_16, SizeOf_T7_tB1C7E0C236178B74109F4EF31E447F56A86DBA34): *(void**)L_16), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 123)) ? il2cpp_codegen_memcpy(L_20, L_17, SizeOf_T8_tAF9A0784F75559C808ECBC453336127EB8DA3A7A): *(void**)L_17), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 124)) ? il2cpp_codegen_memcpy(L_21, L_18, SizeOf_T9_tB9C3488598121213AB36E222281D28C99542EDB2): *(void**)L_18), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 126));
		memset(L_30, 0, SizeOf_ValueTuple_8_t8393F807A09311AE5C3F77F38D87FF98B57A7A47);
		ValueTuple_8__ctor_m5FDE8CF38A97A3D5FC7C364C3467B819664360EE((ValueTuple_8_tF94FE992101922E2A97F08D019A9EBDDA748DCB2*)L_30, 7, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 113)) ? il2cpp_codegen_memcpy(L_23, L_10, SizeOf_T1_t12224CDB8CF3A7A9B85AE3735573C8F4E483F5C8): *(void**)L_10), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 117)) ? il2cpp_codegen_memcpy(L_24, L_11, SizeOf_T2_tAD4D518AD8F8B278644DA50484CBC022467C03C8): *(void**)L_11), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 118)) ? il2cpp_codegen_memcpy(L_25, L_12, SizeOf_T3_t66D9D606A6E8AE1FFD2214BAC540BA2C6A05F30E): *(void**)L_12), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 119)) ? il2cpp_codegen_memcpy(L_26, L_13, SizeOf_T4_t72EE5E3145D8FF5738B17FFF6A56CD3596448171): *(void**)L_13), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 120)) ? il2cpp_codegen_memcpy(L_27, L_14, SizeOf_T5_tBAA81B6ABC55C264673BFAB9E6595906EACF4385): *(void**)L_14), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 121)) ? il2cpp_codegen_memcpy(L_28, L_15, SizeOf_T6_tDBE701EEE385225ABD2D5FE3A33BBB44DAB77FA1): *(void**)L_15), il2cpp_codegen_memcpy(L_29, L_22, SizeOf_ValueTuple_3_t296AC28BABFD66CC8A156720B3F2B3437143A60F), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 128));
		bool L_31;
		L_31 = InvokerFuncInvoker1< bool, ValueTuple_8_tF94FE992101922E2A97F08D019A9EBDDA748DCB2 >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 129)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 129), (((UniTaskCompletionSourceCore_1_t1911EC18C6234A1A4E814CB064F127B40A3F2BD1*)il2cpp_codegen_get_instance_field_data_pointer(L_9, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),1)))), L_30);
	}

IL_0098:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhenAnyPromise_9_TryInvokeContinuationT9_m9427B13779F5AA9462D0E2AE63D5A5F5E69332AC_gshared (WhenAnyPromise_9_t2D551F16D8A9A247E0C45E7698A6A7A3CCDB7757* ___0_self, Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* ___1_awaiter, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T9_tB9C3488598121213AB36E222281D28C99542EDB2 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 124));
	const uint32_t SizeOf_T1_t12224CDB8CF3A7A9B85AE3735573C8F4E483F5C8 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 113));
	const uint32_t SizeOf_T2_tAD4D518AD8F8B278644DA50484CBC022467C03C8 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 117));
	const uint32_t SizeOf_T3_t66D9D606A6E8AE1FFD2214BAC540BA2C6A05F30E = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 118));
	const uint32_t SizeOf_T4_t72EE5E3145D8FF5738B17FFF6A56CD3596448171 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 119));
	const uint32_t SizeOf_T5_tBAA81B6ABC55C264673BFAB9E6595906EACF4385 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 120));
	const uint32_t SizeOf_T6_tDBE701EEE385225ABD2D5FE3A33BBB44DAB77FA1 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 121));
	const uint32_t SizeOf_T7_tB1C7E0C236178B74109F4EF31E447F56A86DBA34 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 122));
	const uint32_t SizeOf_T8_tAF9A0784F75559C808ECBC453336127EB8DA3A7A = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 123));
	const uint32_t SizeOf_ValueTuple_3_t296AC28BABFD66CC8A156720B3F2B3437143A60F = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 125));
	const uint32_t SizeOf_ValueTuple_8_t8393F807A09311AE5C3F77F38D87FF98B57A7A47 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 127));
	const Il2CppFullySharedGenericAny L_10 = alloca(SizeOf_T1_t12224CDB8CF3A7A9B85AE3735573C8F4E483F5C8);
	const Il2CppFullySharedGenericAny L_23 = alloca(SizeOf_T1_t12224CDB8CF3A7A9B85AE3735573C8F4E483F5C8);
	const Il2CppFullySharedGenericAny L_11 = alloca(SizeOf_T2_tAD4D518AD8F8B278644DA50484CBC022467C03C8);
	const Il2CppFullySharedGenericAny L_24 = alloca(SizeOf_T2_tAD4D518AD8F8B278644DA50484CBC022467C03C8);
	const Il2CppFullySharedGenericAny L_12 = alloca(SizeOf_T3_t66D9D606A6E8AE1FFD2214BAC540BA2C6A05F30E);
	const Il2CppFullySharedGenericAny L_25 = alloca(SizeOf_T3_t66D9D606A6E8AE1FFD2214BAC540BA2C6A05F30E);
	const Il2CppFullySharedGenericAny L_13 = alloca(SizeOf_T4_t72EE5E3145D8FF5738B17FFF6A56CD3596448171);
	const Il2CppFullySharedGenericAny L_26 = alloca(SizeOf_T4_t72EE5E3145D8FF5738B17FFF6A56CD3596448171);
	const Il2CppFullySharedGenericAny L_14 = alloca(SizeOf_T5_tBAA81B6ABC55C264673BFAB9E6595906EACF4385);
	const Il2CppFullySharedGenericAny L_27 = alloca(SizeOf_T5_tBAA81B6ABC55C264673BFAB9E6595906EACF4385);
	const Il2CppFullySharedGenericAny L_15 = alloca(SizeOf_T6_tDBE701EEE385225ABD2D5FE3A33BBB44DAB77FA1);
	const Il2CppFullySharedGenericAny L_28 = alloca(SizeOf_T6_tDBE701EEE385225ABD2D5FE3A33BBB44DAB77FA1);
	const Il2CppFullySharedGenericAny L_16 = alloca(SizeOf_T7_tB1C7E0C236178B74109F4EF31E447F56A86DBA34);
	const Il2CppFullySharedGenericAny L_19 = alloca(SizeOf_T7_tB1C7E0C236178B74109F4EF31E447F56A86DBA34);
	const Il2CppFullySharedGenericAny L_17 = alloca(SizeOf_T8_tAF9A0784F75559C808ECBC453336127EB8DA3A7A);
	const Il2CppFullySharedGenericAny L_20 = alloca(SizeOf_T8_tAF9A0784F75559C808ECBC453336127EB8DA3A7A);
	const Il2CppFullySharedGenericAny L_1 = alloca(SizeOf_T9_tB9C3488598121213AB36E222281D28C99542EDB2);
	const Il2CppFullySharedGenericAny L_18 = L_1;
	const Il2CppFullySharedGenericAny L_21 = alloca(SizeOf_T9_tB9C3488598121213AB36E222281D28C99542EDB2);
	const ValueTuple_3_t182F852EE39DD805E380FD93762C931C933ACE98 L_22 = alloca(SizeOf_ValueTuple_3_t296AC28BABFD66CC8A156720B3F2B3437143A60F);
	const ValueTuple_3_t182F852EE39DD805E380FD93762C931C933ACE98 L_29 = alloca(SizeOf_ValueTuple_3_t296AC28BABFD66CC8A156720B3F2B3437143A60F);
	const ValueTuple_8_tF94FE992101922E2A97F08D019A9EBDDA748DCB2 L_30 = alloca(SizeOf_ValueTuple_8_t8393F807A09311AE5C3F77F38D87FF98B57A7A47);
	Il2CppFullySharedGenericAny V_0 = alloca(SizeOf_T9_tB9C3488598121213AB36E222281D28C99542EDB2);
	memset(V_0, 0, SizeOf_T9_tB9C3488598121213AB36E222281D28C99542EDB2);
	Exception_t* V_1 = NULL;
	bool V_2 = false;
	Il2CppFullySharedGenericAny V_3 = alloca(SizeOf_T1_t12224CDB8CF3A7A9B85AE3735573C8F4E483F5C8);
	memset(V_3, 0, SizeOf_T1_t12224CDB8CF3A7A9B85AE3735573C8F4E483F5C8);
	Il2CppFullySharedGenericAny V_4 = alloca(SizeOf_T2_tAD4D518AD8F8B278644DA50484CBC022467C03C8);
	memset(V_4, 0, SizeOf_T2_tAD4D518AD8F8B278644DA50484CBC022467C03C8);
	Il2CppFullySharedGenericAny V_5 = alloca(SizeOf_T3_t66D9D606A6E8AE1FFD2214BAC540BA2C6A05F30E);
	memset(V_5, 0, SizeOf_T3_t66D9D606A6E8AE1FFD2214BAC540BA2C6A05F30E);
	Il2CppFullySharedGenericAny V_6 = alloca(SizeOf_T4_t72EE5E3145D8FF5738B17FFF6A56CD3596448171);
	memset(V_6, 0, SizeOf_T4_t72EE5E3145D8FF5738B17FFF6A56CD3596448171);
	Il2CppFullySharedGenericAny V_7 = alloca(SizeOf_T5_tBAA81B6ABC55C264673BFAB9E6595906EACF4385);
	memset(V_7, 0, SizeOf_T5_tBAA81B6ABC55C264673BFAB9E6595906EACF4385);
	Il2CppFullySharedGenericAny V_8 = alloca(SizeOf_T6_tDBE701EEE385225ABD2D5FE3A33BBB44DAB77FA1);
	memset(V_8, 0, SizeOf_T6_tDBE701EEE385225ABD2D5FE3A33BBB44DAB77FA1);
	Il2CppFullySharedGenericAny V_9 = alloca(SizeOf_T7_tB1C7E0C236178B74109F4EF31E447F56A86DBA34);
	memset(V_9, 0, SizeOf_T7_tB1C7E0C236178B74109F4EF31E447F56A86DBA34);
	Il2CppFullySharedGenericAny V_10 = alloca(SizeOf_T8_tAF9A0784F75559C808ECBC453336127EB8DA3A7A);
	memset(V_10, 0, SizeOf_T8_tAF9A0784F75559C808ECBC453336127EB8DA3A7A);
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
	}
	try
	{
		Awaiter_t51A888D9DD960130FBB265D4B9F9949ED674764C* L_0 = ___1_awaiter;
		InvokerActionInvoker1< Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 137)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 137), L_0, (Il2CppFullySharedGenericAny*)L_1);
		il2cpp_codegen_memcpy(V_0, L_1, SizeOf_T9_tB9C3488598121213AB36E222281D28C99542EDB2);
		goto IL_001d;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&Exception_t_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_000c;
		}
		throw e;
	}

CATCH_000c:
	{
		Exception_t* L_2 = ((Exception_t*)IL2CPP_GET_ACTIVE_EXCEPTION(Exception_t*));;
		V_1 = L_2;
		WhenAnyPromise_9_t2D551F16D8A9A247E0C45E7698A6A7A3CCDB7757* L_3 = ___0_self;
		Exception_t* L_4 = V_1;
		bool L_5;
		L_5 = ((  bool (*) (UniTaskCompletionSourceCore_1_t1911EC18C6234A1A4E814CB064F127B40A3F2BD1*, Exception_t*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 115)))((((UniTaskCompletionSourceCore_1_t1911EC18C6234A1A4E814CB064F127B40A3F2BD1*)il2cpp_codegen_get_instance_field_data_pointer(L_3, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),1)))), L_4, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 115));
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_0098;
	}

IL_001d:
	{
		WhenAnyPromise_9_t2D551F16D8A9A247E0C45E7698A6A7A3CCDB7757* L_6 = ___0_self;
		int32_t L_7;
		L_7 = Interlocked_Increment_m3C240C32E8D9544EC050B74D4F28EEB58F1F9309((((int32_t*)il2cpp_codegen_get_instance_field_data_pointer(L_6, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),0)))), NULL);
		V_2 = (bool)((((int32_t)L_7) == ((int32_t)1))? 1 : 0);
		bool L_8 = V_2;
		if (!L_8)
		{
			goto IL_0098;
		}
	}
	{
		WhenAnyPromise_9_t2D551F16D8A9A247E0C45E7698A6A7A3CCDB7757* L_9 = ___0_self;
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_3, SizeOf_T1_t12224CDB8CF3A7A9B85AE3735573C8F4E483F5C8);
		il2cpp_codegen_memcpy(L_10, V_3, SizeOf_T1_t12224CDB8CF3A7A9B85AE3735573C8F4E483F5C8);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_4, SizeOf_T2_tAD4D518AD8F8B278644DA50484CBC022467C03C8);
		il2cpp_codegen_memcpy(L_11, V_4, SizeOf_T2_tAD4D518AD8F8B278644DA50484CBC022467C03C8);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_5, SizeOf_T3_t66D9D606A6E8AE1FFD2214BAC540BA2C6A05F30E);
		il2cpp_codegen_memcpy(L_12, V_5, SizeOf_T3_t66D9D606A6E8AE1FFD2214BAC540BA2C6A05F30E);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_6, SizeOf_T4_t72EE5E3145D8FF5738B17FFF6A56CD3596448171);
		il2cpp_codegen_memcpy(L_13, V_6, SizeOf_T4_t72EE5E3145D8FF5738B17FFF6A56CD3596448171);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_7, SizeOf_T5_tBAA81B6ABC55C264673BFAB9E6595906EACF4385);
		il2cpp_codegen_memcpy(L_14, V_7, SizeOf_T5_tBAA81B6ABC55C264673BFAB9E6595906EACF4385);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_8, SizeOf_T6_tDBE701EEE385225ABD2D5FE3A33BBB44DAB77FA1);
		il2cpp_codegen_memcpy(L_15, V_8, SizeOf_T6_tDBE701EEE385225ABD2D5FE3A33BBB44DAB77FA1);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_9, SizeOf_T7_tB1C7E0C236178B74109F4EF31E447F56A86DBA34);
		il2cpp_codegen_memcpy(L_16, V_9, SizeOf_T7_tB1C7E0C236178B74109F4EF31E447F56A86DBA34);
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_10, SizeOf_T8_tAF9A0784F75559C808ECBC453336127EB8DA3A7A);
		il2cpp_codegen_memcpy(L_17, V_10, SizeOf_T8_tAF9A0784F75559C808ECBC453336127EB8DA3A7A);
		il2cpp_codegen_memcpy(L_18, V_0, SizeOf_T9_tB9C3488598121213AB36E222281D28C99542EDB2);
		memset(L_22, 0, SizeOf_ValueTuple_3_t296AC28BABFD66CC8A156720B3F2B3437143A60F);
		ValueTuple_3__ctor_mAB800E7134D8E52646FD55A8B2979AC908028759((ValueTuple_3_t182F852EE39DD805E380FD93762C931C933ACE98*)L_22, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 122)) ? il2cpp_codegen_memcpy(L_19, L_16, SizeOf_T7_tB1C7E0C236178B74109F4EF31E447F56A86DBA34): *(void**)L_16), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 123)) ? il2cpp_codegen_memcpy(L_20, L_17, SizeOf_T8_tAF9A0784F75559C808ECBC453336127EB8DA3A7A): *(void**)L_17), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 124)) ? il2cpp_codegen_memcpy(L_21, L_18, SizeOf_T9_tB9C3488598121213AB36E222281D28C99542EDB2): *(void**)L_18), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 126));
		memset(L_30, 0, SizeOf_ValueTuple_8_t8393F807A09311AE5C3F77F38D87FF98B57A7A47);
		ValueTuple_8__ctor_m5FDE8CF38A97A3D5FC7C364C3467B819664360EE((ValueTuple_8_tF94FE992101922E2A97F08D019A9EBDDA748DCB2*)L_30, 8, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 113)) ? il2cpp_codegen_memcpy(L_23, L_10, SizeOf_T1_t12224CDB8CF3A7A9B85AE3735573C8F4E483F5C8): *(void**)L_10), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 117)) ? il2cpp_codegen_memcpy(L_24, L_11, SizeOf_T2_tAD4D518AD8F8B278644DA50484CBC022467C03C8): *(void**)L_11), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 118)) ? il2cpp_codegen_memcpy(L_25, L_12, SizeOf_T3_t66D9D606A6E8AE1FFD2214BAC540BA2C6A05F30E): *(void**)L_12), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 119)) ? il2cpp_codegen_memcpy(L_26, L_13, SizeOf_T4_t72EE5E3145D8FF5738B17FFF6A56CD3596448171): *(void**)L_13), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 120)) ? il2cpp_codegen_memcpy(L_27, L_14, SizeOf_T5_tBAA81B6ABC55C264673BFAB9E6595906EACF4385): *(void**)L_14), (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 121)) ? il2cpp_codegen_memcpy(L_28, L_15, SizeOf_T6_tDBE701EEE385225ABD2D5FE3A33BBB44DAB77FA1): *(void**)L_15), il2cpp_codegen_memcpy(L_29, L_22, SizeOf_ValueTuple_3_t296AC28BABFD66CC8A156720B3F2B3437143A60F), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 128));
		bool L_31;
		L_31 = InvokerFuncInvoker1< bool, ValueTuple_8_tF94FE992101922E2A97F08D019A9EBDDA748DCB2 >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 129)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 129), (((UniTaskCompletionSourceCore_1_t1911EC18C6234A1A4E814CB064F127B40A3F2BD1*)il2cpp_codegen_get_instance_field_data_pointer(L_9, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),1)))), L_30);
	}

IL_0098:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhenAnyPromise_9_GetResult_mCCC68AC3809E9B9FD0B5C8888E60252635A131CF_gshared (WhenAnyPromise_9_t2D551F16D8A9A247E0C45E7698A6A7A3CCDB7757* __this, int16_t ___0_token, ValueTuple_8_tF94FE992101922E2A97F08D019A9EBDDA748DCB2* il2cppRetVal, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GC_t920F9CF6EBB7C787E5010A4352E1B587F356DC58_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	const uint32_t SizeOf_ValueTuple_8_t8393F807A09311AE5C3F77F38D87FF98B57A7A47 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 127));
	const ValueTuple_8_tF94FE992101922E2A97F08D019A9EBDDA748DCB2 L_1 = alloca(SizeOf_ValueTuple_8_t8393F807A09311AE5C3F77F38D87FF98B57A7A47);
	const ValueTuple_8_tF94FE992101922E2A97F08D019A9EBDDA748DCB2 L_2 = L_1;
	ValueTuple_8_tF94FE992101922E2A97F08D019A9EBDDA748DCB2 V_0 = alloca(SizeOf_ValueTuple_8_t8393F807A09311AE5C3F77F38D87FF98B57A7A47);
	memset(V_0, 0, SizeOf_ValueTuple_8_t8393F807A09311AE5C3F77F38D87FF98B57A7A47);
	{
		il2cpp_codegen_runtime_class_init_inline(GC_t920F9CF6EBB7C787E5010A4352E1B587F356DC58_il2cpp_TypeInfo_var);
		GC_SuppressFinalize_m71815DBD5A0CD2EA1BE43317B08B7A14949EDC65((RuntimeObject*)__this, NULL);
		int16_t L_0 = ___0_token;
		InvokerActionInvoker2< int16_t, ValueTuple_8_tF94FE992101922E2A97F08D019A9EBDDA748DCB2* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 138)), il2cpp_rgctx_method(method->klass->rgctx_data, 138), (((UniTaskCompletionSourceCore_1_t1911EC18C6234A1A4E814CB064F127B40A3F2BD1*)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 0),1)))), L_0, (ValueTuple_8_tF94FE992101922E2A97F08D019A9EBDDA748DCB2*)L_1);
		il2cpp_codegen_memcpy(V_0, L_1, SizeOf_ValueTuple_8_t8393F807A09311AE5C3F77F38D87FF98B57A7A47);
		goto IL_0017;
	}

IL_0017:
	{
		il2cpp_codegen_memcpy(L_2, V_0, SizeOf_ValueTuple_8_t8393F807A09311AE5C3F77F38D87FF98B57A7A47);
		il2cpp_codegen_memcpy(il2cppRetVal, L_2, SizeOf_ValueTuple_8_t8393F807A09311AE5C3F77F38D87FF98B57A7A47);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t WhenAnyPromise_9_GetStatus_m9AF4F3EFADAE1D5FBD672D4EC5859BD5D9E35C25_gshared (WhenAnyPromise_9_t2D551F16D8A9A247E0C45E7698A6A7A3CCDB7757* __this, int16_t ___0_token, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		int16_t L_0 = ___0_token;
		int32_t L_1;
		L_1 = ((  int32_t (*) (UniTaskCompletionSourceCore_1_t1911EC18C6234A1A4E814CB064F127B40A3F2BD1*, int16_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 139)))((((UniTaskCompletionSourceCore_1_t1911EC18C6234A1A4E814CB064F127B40A3F2BD1*)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 0),1)))), L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 139));
		V_0 = L_1;
		goto IL_0010;
	}

IL_0010:
	{
		int32_t L_2 = V_0;
		return L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhenAnyPromise_9_OnCompleted_m89DBDCA38D47A9F190DDFFA8AD2AA0FFEF2DFDC7_gshared (WhenAnyPromise_9_t2D551F16D8A9A247E0C45E7698A6A7A3CCDB7757* __this, Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* ___0_continuation, RuntimeObject* ___1_state, int16_t ___2_token, const RuntimeMethod* method) 
{
	{
		Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* L_0 = ___0_continuation;
		RuntimeObject* L_1 = ___1_state;
		int16_t L_2 = ___2_token;
		((  void (*) (UniTaskCompletionSourceCore_1_t1911EC18C6234A1A4E814CB064F127B40A3F2BD1*, Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87*, RuntimeObject*, int16_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 140)))((((UniTaskCompletionSourceCore_1_t1911EC18C6234A1A4E814CB064F127B40A3F2BD1*)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 0),1)))), L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 140));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t WhenAnyPromise_9_UnsafeGetStatus_m28CC9A1F714C8C5CEF54BB2438875999E843CC26_gshared (WhenAnyPromise_9_t2D551F16D8A9A247E0C45E7698A6A7A3CCDB7757* __this, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		int32_t L_0;
		L_0 = ((  int32_t (*) (UniTaskCompletionSourceCore_1_t1911EC18C6234A1A4E814CB064F127B40A3F2BD1*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 141)))((((UniTaskCompletionSourceCore_1_t1911EC18C6234A1A4E814CB064F127B40A3F2BD1*)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 0),1)))), il2cpp_rgctx_method(method->klass->rgctx_data, 141));
		V_0 = L_0;
		goto IL_000f;
	}

IL_000f:
	{
		int32_t L_1 = V_0;
		return L_1;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhenAnyPromise_9_Cysharp_Threading_Tasks_IUniTaskSource_GetResult_m4E565561F1211B9F8E105F3F1BE90E4F55368ADD_gshared (WhenAnyPromise_9_t2D551F16D8A9A247E0C45E7698A6A7A3CCDB7757* __this, int16_t ___0_token, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_ValueTuple_8_t8393F807A09311AE5C3F77F38D87FF98B57A7A47 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 127));
	const ValueTuple_8_tF94FE992101922E2A97F08D019A9EBDDA748DCB2 L_1 = alloca(SizeOf_ValueTuple_8_t8393F807A09311AE5C3F77F38D87FF98B57A7A47);
	{
		int16_t L_0 = ___0_token;
		InvokerActionInvoker2< int16_t, ValueTuple_8_tF94FE992101922E2A97F08D019A9EBDDA748DCB2* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 142)), il2cpp_rgctx_method(method->klass->rgctx_data, 142), __this, L_0, (ValueTuple_8_tF94FE992101922E2A97F08D019A9EBDDA748DCB2*)L_1);
		return;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhenEachEnumerable_1__ctor_m433EF15F9736115444681E6F5824B2C2E992140A_gshared (WhenEachEnumerable_1_t4F973EE64B6BC978974DEFBDBB2EF58E117C0899* __this, RuntimeObject* ___0_source, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2((RuntimeObject*)__this, NULL);
		RuntimeObject* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhenEachEnumerable_1_GetAsyncEnumerator_m4F5014B9E9A5956535BC3EA89A88A92FF15F7DBA_gshared (WhenEachEnumerable_1_t4F973EE64B6BC978974DEFBDBB2EF58E117C0899* __this, CancellationToken_t51142D9C6D7C02D314DA34A6A7988C528992FFED ___0_cancellationToken, const RuntimeMethod* method) 
{
	RuntimeObject* V_0 = NULL;
	{
		RuntimeObject* L_0 = __this->___source;
		CancellationToken_t51142D9C6D7C02D314DA34A6A7988C528992FFED L_1 = ___0_cancellationToken;
		Enumerator_t15FA1624E3BE0AC1F3A918185439A63138D413F4* L_2 = (Enumerator_t15FA1624E3BE0AC1F3A918185439A63138D413F4*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 2));
		((  void (*) (Enumerator_t15FA1624E3BE0AC1F3A918185439A63138D413F4*, RuntimeObject*, CancellationToken_t51142D9C6D7C02D314DA34A6A7988C528992FFED, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 3)))(L_2, L_0, L_1, il2cpp_rgctx_method(method->klass->rgctx_data, 3));
		V_0 = (RuntimeObject*)L_2;
		goto IL_0010;
	}

IL_0010:
	{
		RuntimeObject* L_3 = V_0;
		return L_3;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhenEachResult_1_get_Result_m7C267B764B881AA53B7DFDCF94975161B9022DE8_gshared (WhenEachResult_1_t56488B449B4BD9DA81B279363A63B1C123605F21* __this, Il2CppFullySharedGenericAny* il2cppRetVal, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T_tF8C17784C5288E922C2784A100DEEAD36B1E4619 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 1));
	const Il2CppFullySharedGenericAny L_0 = alloca(SizeOf_T_tF8C17784C5288E922C2784A100DEEAD36B1E4619);
	{
		il2cpp_codegen_memcpy(L_0, il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),0)), SizeOf_T_tF8C17784C5288E922C2784A100DEEAD36B1E4619);
		il2cpp_codegen_memcpy(il2cppRetVal, L_0, SizeOf_T_tF8C17784C5288E922C2784A100DEEAD36B1E4619);
		return;
	}
}
IL2CPP_EXTERN_C  void WhenEachResult_1_get_Result_m7C267B764B881AA53B7DFDCF94975161B9022DE8_AdjustorThunk (RuntimeObject* __this, Il2CppFullySharedGenericAny* il2cppRetVal, const RuntimeMethod* method)
{
	WhenEachResult_1_t56488B449B4BD9DA81B279363A63B1C123605F21* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<WhenEachResult_1_t56488B449B4BD9DA81B279363A63B1C123605F21*>(__this + _offset);
	WhenEachResult_1_get_Result_m7C267B764B881AA53B7DFDCF94975161B9022DE8_inline(_thisAdjusted, il2cppRetVal, method);
	return;
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Exception_t* WhenEachResult_1_get_Exception_m1EC0B9E8E5D8C4AAAD9853628CC5BB8A4EFEF7E2_gshared (WhenEachResult_1_t56488B449B4BD9DA81B279363A63B1C123605F21* __this, const RuntimeMethod* method) 
{
	{
		Exception_t* L_0 = *(Exception_t**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),1));
		return L_0;
	}
}
IL2CPP_EXTERN_C  Exception_t* WhenEachResult_1_get_Exception_m1EC0B9E8E5D8C4AAAD9853628CC5BB8A4EFEF7E2_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	WhenEachResult_1_t56488B449B4BD9DA81B279363A63B1C123605F21* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<WhenEachResult_1_t56488B449B4BD9DA81B279363A63B1C123605F21*>(__this + _offset);
	Exception_t* _returnValue;
	_returnValue = WhenEachResult_1_get_Exception_m1EC0B9E8E5D8C4AAAD9853628CC5BB8A4EFEF7E2_inline(_thisAdjusted, method);
	return _returnValue;
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhenEachResult_1_get_IsCompletedSuccessfully_mDAA9246C39928B8BD9E1E452C3683159A50E80C0_gshared (WhenEachResult_1_t56488B449B4BD9DA81B279363A63B1C123605F21* __this, const RuntimeMethod* method) 
{
	{
		Exception_t* L_0;
		L_0 = ((  Exception_t* (*) (WhenEachResult_1_t56488B449B4BD9DA81B279363A63B1C123605F21*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 2)))(__this, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 2));
		return (bool)((((RuntimeObject*)(Exception_t*)L_0) == ((RuntimeObject*)(RuntimeObject*)NULL))? 1 : 0);
	}
}
IL2CPP_EXTERN_C  bool WhenEachResult_1_get_IsCompletedSuccessfully_mDAA9246C39928B8BD9E1E452C3683159A50E80C0_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	WhenEachResult_1_t56488B449B4BD9DA81B279363A63B1C123605F21* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<WhenEachResult_1_t56488B449B4BD9DA81B279363A63B1C123605F21*>(__this + _offset);
	bool _returnValue;
	_returnValue = WhenEachResult_1_get_IsCompletedSuccessfully_mDAA9246C39928B8BD9E1E452C3683159A50E80C0(_thisAdjusted, method);
	return _returnValue;
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhenEachResult_1_get_IsFaulted_mB91422296C91DED752CBB5984538F6EEA85D863F_gshared (WhenEachResult_1_t56488B449B4BD9DA81B279363A63B1C123605F21* __this, const RuntimeMethod* method) 
{
	{
		Exception_t* L_0;
		L_0 = ((  Exception_t* (*) (WhenEachResult_1_t56488B449B4BD9DA81B279363A63B1C123605F21*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 2)))(__this, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 2));
		return (bool)((!(((RuntimeObject*)(Exception_t*)L_0) <= ((RuntimeObject*)(RuntimeObject*)NULL)))? 1 : 0);
	}
}
IL2CPP_EXTERN_C  bool WhenEachResult_1_get_IsFaulted_mB91422296C91DED752CBB5984538F6EEA85D863F_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	WhenEachResult_1_t56488B449B4BD9DA81B279363A63B1C123605F21* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<WhenEachResult_1_t56488B449B4BD9DA81B279363A63B1C123605F21*>(__this + _offset);
	bool _returnValue;
	_returnValue = WhenEachResult_1_get_IsFaulted_mB91422296C91DED752CBB5984538F6EEA85D863F(_thisAdjusted, method);
	return _returnValue;
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhenEachResult_1__ctor_m3E6D66D301C3531A418F5EA4649DD17B2418C8C7_gshared (WhenEachResult_1_t56488B449B4BD9DA81B279363A63B1C123605F21* __this, Il2CppFullySharedGenericAny ___0_result, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T_tF8C17784C5288E922C2784A100DEEAD36B1E4619 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 1));
	const Il2CppFullySharedGenericAny L_0 = alloca(SizeOf_T_tF8C17784C5288E922C2784A100DEEAD36B1E4619);
	{
		il2cpp_codegen_memcpy(L_0, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 1)) ? ___0_result : &___0_result), SizeOf_T_tF8C17784C5288E922C2784A100DEEAD36B1E4619);
		il2cpp_codegen_write_instance_field_data(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),0), L_0, SizeOf_T_tF8C17784C5288E922C2784A100DEEAD36B1E4619);
		il2cpp_codegen_write_instance_field_data<Exception_t*>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),1), (Exception_t*)NULL);
		return;
	}
}
IL2CPP_EXTERN_C  void WhenEachResult_1__ctor_m3E6D66D301C3531A418F5EA4649DD17B2418C8C7_AdjustorThunk (RuntimeObject* __this, Il2CppFullySharedGenericAny ___0_result, const RuntimeMethod* method)
{
	WhenEachResult_1_t56488B449B4BD9DA81B279363A63B1C123605F21* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<WhenEachResult_1_t56488B449B4BD9DA81B279363A63B1C123605F21*>(__this + _offset);
	WhenEachResult_1__ctor_m3E6D66D301C3531A418F5EA4649DD17B2418C8C7(_thisAdjusted, ___0_result, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhenEachResult_1__ctor_m3A30F2A98DD5A29D5E75F3B406B1C8CC393E816F_gshared (WhenEachResult_1_t56488B449B4BD9DA81B279363A63B1C123605F21* __this, Exception_t* ___0_exception, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T_tF8C17784C5288E922C2784A100DEEAD36B1E4619 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 1));
	bool V_0 = false;
	{
		Exception_t* L_0 = ___0_exception;
		V_0 = (bool)((((RuntimeObject*)(Exception_t*)L_0) == ((RuntimeObject*)(RuntimeObject*)NULL))? 1 : 0);
		bool L_1 = V_0;
		if (!L_1)
		{
			goto IL_0014;
		}
	}
	{
		ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* L_2 = (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var)));
		ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B(L_2, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralCF6D423D6F6C1327D40E616C52007CE750F00A62)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_2, method);
	}

IL_0014:
	{
		il2cpp_codegen_initobj((((Il2CppFullySharedGenericAny*)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),0)))), SizeOf_T_tF8C17784C5288E922C2784A100DEEAD36B1E4619);
		Exception_t* L_3 = ___0_exception;
		il2cpp_codegen_write_instance_field_data<Exception_t*>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),1), L_3);
		return;
	}
}
IL2CPP_EXTERN_C  void WhenEachResult_1__ctor_m3A30F2A98DD5A29D5E75F3B406B1C8CC393E816F_AdjustorThunk (RuntimeObject* __this, Exception_t* ___0_exception, const RuntimeMethod* method)
{
	WhenEachResult_1_t56488B449B4BD9DA81B279363A63B1C123605F21* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<WhenEachResult_1_t56488B449B4BD9DA81B279363A63B1C123605F21*>(__this + _offset);
	WhenEachResult_1__ctor_m3A30F2A98DD5A29D5E75F3B406B1C8CC393E816F(_thisAdjusted, ___0_exception, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhenEachResult_1_TryThrow_mC790F701AFA9FF9F4AF640F26758896F3DD4E794_gshared (WhenEachResult_1_t56488B449B4BD9DA81B279363A63B1C123605F21* __this, const RuntimeMethod* method) 
{
	bool V_0 = false;
	{
		bool L_0;
		L_0 = ((  bool (*) (WhenEachResult_1_t56488B449B4BD9DA81B279363A63B1C123605F21*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 4)))(__this, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 4));
		V_0 = L_0;
		bool L_1 = V_0;
		if (!L_1)
		{
			goto IL_001e;
		}
	}
	{
		Exception_t* L_2;
		L_2 = ((  Exception_t* (*) (WhenEachResult_1_t56488B449B4BD9DA81B279363A63B1C123605F21*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 2)))(__this, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 2));
		ExceptionDispatchInfo_tD7AF19E75FEC22F4A8329FD1E9EDF96615CB2757* L_3;
		L_3 = ExceptionDispatchInfo_Capture_mC1C1C30D83DC04B2B7813DFCB67D07CCD4909803(L_2, NULL);
		NullCheck(L_3);
		ExceptionDispatchInfo_Throw_m06F398E346AE94C1CCEB636763A8CB26511F6330(L_3, NULL);
	}

IL_001e:
	{
		return;
	}
}
IL2CPP_EXTERN_C  void WhenEachResult_1_TryThrow_mC790F701AFA9FF9F4AF640F26758896F3DD4E794_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	WhenEachResult_1_t56488B449B4BD9DA81B279363A63B1C123605F21* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<WhenEachResult_1_t56488B449B4BD9DA81B279363A63B1C123605F21*>(__this + _offset);
	WhenEachResult_1_TryThrow_mC790F701AFA9FF9F4AF640F26758896F3DD4E794(_thisAdjusted, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhenEachResult_1_GetResult_m36DB80467A9BC2F26C700CD433F74301BBD77D3E_gshared (WhenEachResult_1_t56488B449B4BD9DA81B279363A63B1C123605F21* __this, Il2CppFullySharedGenericAny* il2cppRetVal, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T_tF8C17784C5288E922C2784A100DEEAD36B1E4619 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 1));
	const Il2CppFullySharedGenericAny L_4 = alloca(SizeOf_T_tF8C17784C5288E922C2784A100DEEAD36B1E4619);
	const Il2CppFullySharedGenericAny L_5 = L_4;
	bool V_0 = false;
	Il2CppFullySharedGenericAny V_1 = alloca(SizeOf_T_tF8C17784C5288E922C2784A100DEEAD36B1E4619);
	memset(V_1, 0, SizeOf_T_tF8C17784C5288E922C2784A100DEEAD36B1E4619);
	{
		bool L_0;
		L_0 = ((  bool (*) (WhenEachResult_1_t56488B449B4BD9DA81B279363A63B1C123605F21*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 4)))(__this, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 4));
		V_0 = L_0;
		bool L_1 = V_0;
		if (!L_1)
		{
			goto IL_001e;
		}
	}
	{
		Exception_t* L_2;
		L_2 = ((  Exception_t* (*) (WhenEachResult_1_t56488B449B4BD9DA81B279363A63B1C123605F21*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 2)))(__this, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 2));
		ExceptionDispatchInfo_tD7AF19E75FEC22F4A8329FD1E9EDF96615CB2757* L_3;
		L_3 = ExceptionDispatchInfo_Capture_mC1C1C30D83DC04B2B7813DFCB67D07CCD4909803(L_2, NULL);
		NullCheck(L_3);
		ExceptionDispatchInfo_Throw_m06F398E346AE94C1CCEB636763A8CB26511F6330(L_3, NULL);
	}

IL_001e:
	{
		InvokerActionInvoker1< Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 5)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 5), __this, (Il2CppFullySharedGenericAny*)L_4);
		il2cpp_codegen_memcpy(V_1, L_4, SizeOf_T_tF8C17784C5288E922C2784A100DEEAD36B1E4619);
		goto IL_0027;
	}

IL_0027:
	{
		il2cpp_codegen_memcpy(L_5, V_1, SizeOf_T_tF8C17784C5288E922C2784A100DEEAD36B1E4619);
		il2cpp_codegen_memcpy(il2cppRetVal, L_5, SizeOf_T_tF8C17784C5288E922C2784A100DEEAD36B1E4619);
		return;
	}
}
IL2CPP_EXTERN_C  void WhenEachResult_1_GetResult_m36DB80467A9BC2F26C700CD433F74301BBD77D3E_AdjustorThunk (RuntimeObject* __this, Il2CppFullySharedGenericAny* il2cppRetVal, const RuntimeMethod* method)
{
	WhenEachResult_1_t56488B449B4BD9DA81B279363A63B1C123605F21* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<WhenEachResult_1_t56488B449B4BD9DA81B279363A63B1C123605F21*>(__this + _offset);
	WhenEachResult_1_GetResult_m36DB80467A9BC2F26C700CD433F74301BBD77D3E(_thisAdjusted, il2cppRetVal, method);
	return;
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* WhenEachResult_1_ToString_mA2E309A2B52993DDF9EE78DB72C46233A2FBE84D_gshared (WhenEachResult_1_t56488B449B4BD9DA81B279363A63B1C123605F21* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral2ED58924CAB7F8187767CDF1134A1B453FB0EEB0);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral4D8D9C94AC5DA5FCED2EC8A64E10E714A2515C30);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralDA39A3EE5E6B4B0D3255BFEF95601890AFD80709);
		s_Il2CppMethodInitialized = true;
	}
	const uint32_t SizeOf_T_tF8C17784C5288E922C2784A100DEEAD36B1E4619 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 1));
	void* L_6 = alloca(Il2CppFakeBoxBuffer::SizeNeededFor(il2cpp_rgctx_data(InitializedTypeInfo(method->klass)->rgctx_data, 1)));
	const Il2CppFullySharedGenericAny L_2 = alloca(SizeOf_T_tF8C17784C5288E922C2784A100DEEAD36B1E4619);
	const Il2CppFullySharedGenericAny L_4 = alloca(SizeOf_T_tF8C17784C5288E922C2784A100DEEAD36B1E4619);
	bool V_0 = false;
	Il2CppFullySharedGenericAny V_1 = alloca(SizeOf_T_tF8C17784C5288E922C2784A100DEEAD36B1E4619);
	memset(V_1, 0, SizeOf_T_tF8C17784C5288E922C2784A100DEEAD36B1E4619);
	String_t* V_2 = NULL;
	Il2CppFullySharedGenericAny G_B3_0 = alloca(SizeOf_T_tF8C17784C5288E922C2784A100DEEAD36B1E4619);
	memset(G_B3_0, 0, SizeOf_T_tF8C17784C5288E922C2784A100DEEAD36B1E4619);
	Il2CppFullySharedGenericAny G_B2_0 = alloca(SizeOf_T_tF8C17784C5288E922C2784A100DEEAD36B1E4619);
	memset(G_B2_0, 0, SizeOf_T_tF8C17784C5288E922C2784A100DEEAD36B1E4619);
	String_t* G_B4_0 = NULL;
	String_t* G_B6_0 = NULL;
	String_t* G_B5_0 = NULL;
	{
		bool L_0;
		L_0 = ((  bool (*) (WhenEachResult_1_t56488B449B4BD9DA81B279363A63B1C123605F21*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 6)))(__this, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 6));
		V_0 = L_0;
		bool L_1 = V_0;
		if (!L_1)
		{
			goto IL_003d;
		}
	}
	{
		InvokerActionInvoker1< Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 5)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 5), __this, (Il2CppFullySharedGenericAny*)L_2);
		il2cpp_codegen_memcpy(V_1, L_2, SizeOf_T_tF8C17784C5288E922C2784A100DEEAD36B1E4619);
		Il2CppFullySharedGenericAny* L_3 = (Il2CppFullySharedGenericAny*)V_1;
		il2cpp_codegen_memcpy(L_4, L_3, SizeOf_T_tF8C17784C5288E922C2784A100DEEAD36B1E4619);
		bool L_5 = il2cpp_codegen_would_box_to_non_null(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 1), L_4);
		if (L_5)
		{
			il2cpp_codegen_memcpy(G_B3_0, L_3, SizeOf_T_tF8C17784C5288E922C2784A100DEEAD36B1E4619);
			goto IL_0026;
		}
		il2cpp_codegen_memcpy(G_B2_0, L_3, SizeOf_T_tF8C17784C5288E922C2784A100DEEAD36B1E4619);
	}
	{
		G_B4_0 = ((String_t*)(NULL));
		goto IL_0031;
	}

IL_0026:
	{
		String_t* L_7;
		L_7 = ConstrainedFuncInvoker0< String_t* >::Invoke(il2cpp_rgctx_data(InitializedTypeInfo(method->klass)->rgctx_data, 1), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 7), L_6, (void*)G_B3_0);
		G_B4_0 = L_7;
	}

IL_0031:
	{
		String_t* L_8 = G_B4_0;
		if (L_8)
		{
			G_B6_0 = L_8;
			goto IL_003a;
		}
		G_B5_0 = L_8;
	}
	{
		G_B6_0 = _stringLiteralDA39A3EE5E6B4B0D3255BFEF95601890AFD80709;
	}

IL_003a:
	{
		V_2 = G_B6_0;
		goto IL_005b;
	}

IL_003d:
	{
		Exception_t* L_9;
		L_9 = ((  Exception_t* (*) (WhenEachResult_1_t56488B449B4BD9DA81B279363A63B1C123605F21*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 2)))(__this, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 2));
		NullCheck(L_9);
		String_t* L_10;
		L_10 = VirtualFuncInvoker0< String_t* >::Invoke(5, L_9);
		String_t* L_11;
		L_11 = String_Concat_m8855A6DE10F84DA7F4EC113CADDB59873A25573B(_stringLiteral2ED58924CAB7F8187767CDF1134A1B453FB0EEB0, L_10, _stringLiteral4D8D9C94AC5DA5FCED2EC8A64E10E714A2515C30, NULL);
		V_2 = L_11;
		goto IL_005b;
	}

IL_005b:
	{
		String_t* L_12 = V_2;
		return L_12;
	}
}
IL2CPP_EXTERN_C  String_t* WhenEachResult_1_ToString_mA2E309A2B52993DDF9EE78DB72C46233A2FBE84D_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	WhenEachResult_1_t56488B449B4BD9DA81B279363A63B1C123605F21* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<WhenEachResult_1_t56488B449B4BD9DA81B279363A63B1C123605F21*>(__this + _offset);
	String_t* _returnValue;
	_returnValue = WhenEachResult_1_ToString_mA2E309A2B52993DDF9EE78DB72C46233A2FBE84D(_thisAdjusted, method);
	return _returnValue;
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereArrayIterator_1__ctor_m2B8837362AE8ED47437A9B42F6C4DA73311039A9_gshared (WhereArrayIterator_1_t61D2F3529A970E9F412291B961056462F17EDDCB* __this, KeyValuePair_2U5BU5D_t105762EC2DE353037ECAD13437FC19081314CE67* ___0_source, Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* ___1_predicate, const RuntimeMethod* method) 
{
	{
		Iterator_1__ctor_m0D72EABA02C6FB0A61DB8BDD0992DCD58C9C58FC((Iterator_1_t6F8827EED7DB0C845108D7DF969A608714128E05*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		KeyValuePair_2U5BU5D_t105762EC2DE353037ECAD13437FC19081314CE67* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t6F8827EED7DB0C845108D7DF969A608714128E05* WhereArrayIterator_1_Clone_m4F4BBEED1938F9E3B4DD10E75AE10F14A78010F9_gshared (WhereArrayIterator_1_t61D2F3529A970E9F412291B961056462F17EDDCB* __this, const RuntimeMethod* method) 
{
	{
		KeyValuePair_2U5BU5D_t105762EC2DE353037ECAD13437FC19081314CE67* L_0 = __this->___source;
		Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* L_1 = __this->___predicate;
		WhereArrayIterator_1_t61D2F3529A970E9F412291B961056462F17EDDCB* L_2 = (WhereArrayIterator_1_t61D2F3529A970E9F412291B961056462F17EDDCB*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 3));
		WhereArrayIterator_1__ctor_m2B8837362AE8ED47437A9B42F6C4DA73311039A9(L_2, L_0, L_1, il2cpp_rgctx_method(method->klass->rgctx_data, 5));
		return (Iterator_1_t6F8827EED7DB0C845108D7DF969A608714128E05*)L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereArrayIterator_1_MoveNext_mDFC41A94F28DBFC762FEB22BFA61D68268FC7D31_gshared (WhereArrayIterator_1_t61D2F3529A970E9F412291B961056462F17EDDCB* __this, const RuntimeMethod* method) 
{
	KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ((Iterator_1_t6F8827EED7DB0C845108D7DF969A608714128E05*)__this)->___state;
		if ((!(((uint32_t)L_0) == ((uint32_t)1))))
		{
			goto IL_0058;
		}
	}
	{
		goto IL_0042;
	}

IL_000b:
	{
		KeyValuePair_2U5BU5D_t105762EC2DE353037ECAD13437FC19081314CE67* L_1 = __this->___source;
		int32_t L_2 = __this->___index;
		NullCheck(L_1);
		int32_t L_3 = L_2;
		KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 L_4 = (L_1)->GetAt(static_cast<il2cpp_array_size_t>(L_3));
		V_0 = L_4;
		int32_t L_5 = __this->___index;
		__this->___index = ((int32_t)il2cpp_codegen_add(L_5, 1));
		Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* L_6 = __this->___predicate;
		KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 L_7 = V_0;
		NullCheck(L_6);
		bool L_8;
		L_8 = Func_2_Invoke_m18A3A6EDA433C635C66C43DA6B86F7BC746BFDD0_inline(L_6, L_7, il2cpp_rgctx_method(method->klass->rgctx_data, 8));
		if (!L_8)
		{
			goto IL_0042;
		}
	}
	{
		KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 L_9 = V_0;
		((Iterator_1_t6F8827EED7DB0C845108D7DF969A608714128E05*)__this)->___current = L_9;
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_t6F8827EED7DB0C845108D7DF969A608714128E05*)__this)->___current))->___key), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_t6F8827EED7DB0C845108D7DF969A608714128E05*)__this)->___current))->___value), (void*)NULL);
		#endif
		return (bool)1;
	}

IL_0042:
	{
		int32_t L_10 = __this->___index;
		KeyValuePair_2U5BU5D_t105762EC2DE353037ECAD13437FC19081314CE67* L_11 = __this->___source;
		NullCheck(L_11);
		if ((((int32_t)L_10) < ((int32_t)((int32_t)(((RuntimeArray*)L_11)->max_length)))))
		{
			goto IL_000b;
		}
	}
	{
		NullCheck((Iterator_1_t6F8827EED7DB0C845108D7DF969A608714128E05*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t6F8827EED7DB0C845108D7DF969A608714128E05*)__this);
	}

IL_0058:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereArrayIterator_1_Where_mEE8012F7C900E47F2E18DE9EE5D2FACB08F6F34C_gshared (WhereArrayIterator_1_t61D2F3529A970E9F412291B961056462F17EDDCB* __this, Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* ___0_predicate, const RuntimeMethod* method) 
{
	{
		KeyValuePair_2U5BU5D_t105762EC2DE353037ECAD13437FC19081314CE67* L_0 = __this->___source;
		Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* L_1 = __this->___predicate;
		Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* L_2 = ___0_predicate;
		Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* L_3;
		L_3 = Enumerable_CombinePredicates_TisKeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230_m9F329AA67F4C35877F54CE7441C4E759BCD33522(L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 10));
		WhereArrayIterator_1_t61D2F3529A970E9F412291B961056462F17EDDCB* L_4 = (WhereArrayIterator_1_t61D2F3529A970E9F412291B961056462F17EDDCB*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 3));
		WhereArrayIterator_1__ctor_m2B8837362AE8ED47437A9B42F6C4DA73311039A9(L_4, L_0, L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 5));
		return (RuntimeObject*)L_4;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereArrayIterator_1__ctor_m32ED64E416417FA26F29A6AADA0AB6AC46EFAA8E_gshared (WhereArrayIterator_1_t8CAF996BCF726E82067F30842CD1885CA4F71D0B* __this, Int32EnumU5BU5D_t87B7DB802810C38016332669039EF42C487A081F* ___0_source, Func_2_t1C8F983F9A1AA802D45E89037E2AA7ACD1094821* ___1_predicate, const RuntimeMethod* method) 
{
	{
		Iterator_1__ctor_m9788F4EF50A0094F325E620BFC1D32ED3DAE63BB((Iterator_1_tEEF82AE11FFC6DF9B283B2D5E4A87B3E3BFD805E*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		Int32EnumU5BU5D_t87B7DB802810C38016332669039EF42C487A081F* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t1C8F983F9A1AA802D45E89037E2AA7ACD1094821* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_tEEF82AE11FFC6DF9B283B2D5E4A87B3E3BFD805E* WhereArrayIterator_1_Clone_m71A3A124080D8073B12D406DC5AC696E1DD91D61_gshared (WhereArrayIterator_1_t8CAF996BCF726E82067F30842CD1885CA4F71D0B* __this, const RuntimeMethod* method) 
{
	{
		Int32EnumU5BU5D_t87B7DB802810C38016332669039EF42C487A081F* L_0 = __this->___source;
		Func_2_t1C8F983F9A1AA802D45E89037E2AA7ACD1094821* L_1 = __this->___predicate;
		WhereArrayIterator_1_t8CAF996BCF726E82067F30842CD1885CA4F71D0B* L_2 = (WhereArrayIterator_1_t8CAF996BCF726E82067F30842CD1885CA4F71D0B*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 3));
		WhereArrayIterator_1__ctor_m32ED64E416417FA26F29A6AADA0AB6AC46EFAA8E(L_2, L_0, L_1, il2cpp_rgctx_method(method->klass->rgctx_data, 5));
		return (Iterator_1_tEEF82AE11FFC6DF9B283B2D5E4A87B3E3BFD805E*)L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereArrayIterator_1_MoveNext_m33E8CD7E8D6EA39F49026247C3AE655585171468_gshared (WhereArrayIterator_1_t8CAF996BCF726E82067F30842CD1885CA4F71D0B* __this, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		int32_t L_0 = ((Iterator_1_tEEF82AE11FFC6DF9B283B2D5E4A87B3E3BFD805E*)__this)->___state;
		if ((!(((uint32_t)L_0) == ((uint32_t)1))))
		{
			goto IL_0058;
		}
	}
	{
		goto IL_0042;
	}

IL_000b:
	{
		Int32EnumU5BU5D_t87B7DB802810C38016332669039EF42C487A081F* L_1 = __this->___source;
		int32_t L_2 = __this->___index;
		NullCheck(L_1);
		int32_t L_3 = L_2;
		int32_t L_4 = (L_1)->GetAt(static_cast<il2cpp_array_size_t>(L_3));
		V_0 = L_4;
		int32_t L_5 = __this->___index;
		__this->___index = ((int32_t)il2cpp_codegen_add(L_5, 1));
		Func_2_t1C8F983F9A1AA802D45E89037E2AA7ACD1094821* L_6 = __this->___predicate;
		int32_t L_7 = V_0;
		NullCheck(L_6);
		bool L_8;
		L_8 = Func_2_Invoke_m095D2006A2DDB336987862DC15A7EFAED53E08EC_inline(L_6, L_7, il2cpp_rgctx_method(method->klass->rgctx_data, 8));
		if (!L_8)
		{
			goto IL_0042;
		}
	}
	{
		int32_t L_9 = V_0;
		((Iterator_1_tEEF82AE11FFC6DF9B283B2D5E4A87B3E3BFD805E*)__this)->___current = L_9;
		return (bool)1;
	}

IL_0042:
	{
		int32_t L_10 = __this->___index;
		Int32EnumU5BU5D_t87B7DB802810C38016332669039EF42C487A081F* L_11 = __this->___source;
		NullCheck(L_11);
		if ((((int32_t)L_10) < ((int32_t)((int32_t)(((RuntimeArray*)L_11)->max_length)))))
		{
			goto IL_000b;
		}
	}
	{
		NullCheck((Iterator_1_tEEF82AE11FFC6DF9B283B2D5E4A87B3E3BFD805E*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_tEEF82AE11FFC6DF9B283B2D5E4A87B3E3BFD805E*)__this);
	}

IL_0058:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereArrayIterator_1_Where_mB9EEA8180D1AF0DEEBEE49F35AD127B8B168FB01_gshared (WhereArrayIterator_1_t8CAF996BCF726E82067F30842CD1885CA4F71D0B* __this, Func_2_t1C8F983F9A1AA802D45E89037E2AA7ACD1094821* ___0_predicate, const RuntimeMethod* method) 
{
	{
		Int32EnumU5BU5D_t87B7DB802810C38016332669039EF42C487A081F* L_0 = __this->___source;
		Func_2_t1C8F983F9A1AA802D45E89037E2AA7ACD1094821* L_1 = __this->___predicate;
		Func_2_t1C8F983F9A1AA802D45E89037E2AA7ACD1094821* L_2 = ___0_predicate;
		Func_2_t1C8F983F9A1AA802D45E89037E2AA7ACD1094821* L_3;
		L_3 = Enumerable_CombinePredicates_TisInt32Enum_tCBAC8BA2BFF3A845FA599F303093BBBA374B6F0C_m88CBD9562882820B08530454AF5A344C7453C267(L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 10));
		WhereArrayIterator_1_t8CAF996BCF726E82067F30842CD1885CA4F71D0B* L_4 = (WhereArrayIterator_1_t8CAF996BCF726E82067F30842CD1885CA4F71D0B*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 3));
		WhereArrayIterator_1__ctor_m32ED64E416417FA26F29A6AADA0AB6AC46EFAA8E(L_4, L_0, L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 5));
		return (RuntimeObject*)L_4;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereArrayIterator_1__ctor_mC17BAA23BA92C7455512FDA5B1618C6D2B54ACA2_gshared (WhereArrayIterator_1_t027D2511F9B69346688FE3E5623EF2BEE81E9FAA* __this, ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* ___0_source, Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* ___1_predicate, const RuntimeMethod* method) 
{
	{
		Iterator_1__ctor_m3E47867714E05673E54C6B73D9242F5FFADA1F63((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA* WhereArrayIterator_1_Clone_m23B21F0E17F85746DFAF09C90772262DF3B707AF_gshared (WhereArrayIterator_1_t027D2511F9B69346688FE3E5623EF2BEE81E9FAA* __this, const RuntimeMethod* method) 
{
	{
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_0 = __this->___source;
		Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* L_1 = __this->___predicate;
		WhereArrayIterator_1_t027D2511F9B69346688FE3E5623EF2BEE81E9FAA* L_2 = (WhereArrayIterator_1_t027D2511F9B69346688FE3E5623EF2BEE81E9FAA*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 3));
		WhereArrayIterator_1__ctor_mC17BAA23BA92C7455512FDA5B1618C6D2B54ACA2(L_2, L_0, L_1, il2cpp_rgctx_method(method->klass->rgctx_data, 5));
		return (Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereArrayIterator_1_MoveNext_m205D669337F73902F61F7BBFD6165B9005890564_gshared (WhereArrayIterator_1_t027D2511F9B69346688FE3E5623EF2BEE81E9FAA* __this, const RuntimeMethod* method) 
{
	RuntimeObject* V_0 = NULL;
	{
		int32_t L_0 = ((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this)->___state;
		if ((!(((uint32_t)L_0) == ((uint32_t)1))))
		{
			goto IL_0058;
		}
	}
	{
		goto IL_0042;
	}

IL_000b:
	{
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_1 = __this->___source;
		int32_t L_2 = __this->___index;
		NullCheck(L_1);
		int32_t L_3 = L_2;
		RuntimeObject* L_4 = (L_1)->GetAt(static_cast<il2cpp_array_size_t>(L_3));
		V_0 = L_4;
		int32_t L_5 = __this->___index;
		__this->___index = ((int32_t)il2cpp_codegen_add(L_5, 1));
		Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* L_6 = __this->___predicate;
		RuntimeObject* L_7 = V_0;
		NullCheck(L_6);
		bool L_8;
		L_8 = Func_2_Invoke_m2014423FB900F135C8FF994125604FF9E6AAE829_inline(L_6, L_7, il2cpp_rgctx_method(method->klass->rgctx_data, 8));
		if (!L_8)
		{
			goto IL_0042;
		}
	}
	{
		RuntimeObject* L_9 = V_0;
		((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this)->___current = L_9;
		Il2CppCodeGenWriteBarrier((void**)(&((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this)->___current), (void*)L_9);
		return (bool)1;
	}

IL_0042:
	{
		int32_t L_10 = __this->___index;
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_11 = __this->___source;
		NullCheck(L_11);
		if ((((int32_t)L_10) < ((int32_t)((int32_t)(((RuntimeArray*)L_11)->max_length)))))
		{
			goto IL_000b;
		}
	}
	{
		NullCheck((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this);
	}

IL_0058:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereArrayIterator_1_Where_m00D679C5996A876F2AF50976C1F93D89F8F42C62_gshared (WhereArrayIterator_1_t027D2511F9B69346688FE3E5623EF2BEE81E9FAA* __this, Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* ___0_predicate, const RuntimeMethod* method) 
{
	{
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_0 = __this->___source;
		Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* L_1 = __this->___predicate;
		Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* L_2 = ___0_predicate;
		Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* L_3;
		L_3 = Enumerable_CombinePredicates_TisRuntimeObject_m613479C29B013E8FC2987E22F42A3BC6CC2C9768(L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 10));
		WhereArrayIterator_1_t027D2511F9B69346688FE3E5623EF2BEE81E9FAA* L_4 = (WhereArrayIterator_1_t027D2511F9B69346688FE3E5623EF2BEE81E9FAA*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 3));
		WhereArrayIterator_1__ctor_mC17BAA23BA92C7455512FDA5B1618C6D2B54ACA2(L_4, L_0, L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 5));
		return (RuntimeObject*)L_4;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereArrayIterator_1__ctor_m1C57CC91AE53B7ED6FB71FB822B8C1480B667E73_gshared (WhereArrayIterator_1_t6231D220871B84114C148960F57DC2479C42909F* __this, PlayerLoopSystemU5BU5D_t07C04E53AAC3CDA17603E8BA1B41D7E1AC083C6D* ___0_source, Func_2_t92F44173C14E7022E392A8FEA4374C3CD24578EF* ___1_predicate, const RuntimeMethod* method) 
{
	{
		Iterator_1__ctor_mF6CD5E26F94CF7F842315D35A872B8C7298BD467((Iterator_1_t90E419394494C38051F176EB657B6E351726C1A5*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		PlayerLoopSystemU5BU5D_t07C04E53AAC3CDA17603E8BA1B41D7E1AC083C6D* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t92F44173C14E7022E392A8FEA4374C3CD24578EF* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t90E419394494C38051F176EB657B6E351726C1A5* WhereArrayIterator_1_Clone_m8216C67382F93688B62AAAEC68CFB5B0F9224793_gshared (WhereArrayIterator_1_t6231D220871B84114C148960F57DC2479C42909F* __this, const RuntimeMethod* method) 
{
	{
		PlayerLoopSystemU5BU5D_t07C04E53AAC3CDA17603E8BA1B41D7E1AC083C6D* L_0 = __this->___source;
		Func_2_t92F44173C14E7022E392A8FEA4374C3CD24578EF* L_1 = __this->___predicate;
		WhereArrayIterator_1_t6231D220871B84114C148960F57DC2479C42909F* L_2 = (WhereArrayIterator_1_t6231D220871B84114C148960F57DC2479C42909F*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 3));
		WhereArrayIterator_1__ctor_m1C57CC91AE53B7ED6FB71FB822B8C1480B667E73(L_2, L_0, L_1, il2cpp_rgctx_method(method->klass->rgctx_data, 5));
		return (Iterator_1_t90E419394494C38051F176EB657B6E351726C1A5*)L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereArrayIterator_1_MoveNext_m4E5BBC61C72AC4A76900293E5FB7F2D7B39F8B47_gshared (WhereArrayIterator_1_t6231D220871B84114C148960F57DC2479C42909F* __this, const RuntimeMethod* method) 
{
	PlayerLoopSystem_t8AED6BF1C8A309CAA6FF71AC91DD33BDDFF7CF1F V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ((Iterator_1_t90E419394494C38051F176EB657B6E351726C1A5*)__this)->___state;
		if ((!(((uint32_t)L_0) == ((uint32_t)1))))
		{
			goto IL_0058;
		}
	}
	{
		goto IL_0042;
	}

IL_000b:
	{
		PlayerLoopSystemU5BU5D_t07C04E53AAC3CDA17603E8BA1B41D7E1AC083C6D* L_1 = __this->___source;
		int32_t L_2 = __this->___index;
		NullCheck(L_1);
		int32_t L_3 = L_2;
		PlayerLoopSystem_t8AED6BF1C8A309CAA6FF71AC91DD33BDDFF7CF1F L_4 = (L_1)->GetAt(static_cast<il2cpp_array_size_t>(L_3));
		V_0 = L_4;
		int32_t L_5 = __this->___index;
		__this->___index = ((int32_t)il2cpp_codegen_add(L_5, 1));
		Func_2_t92F44173C14E7022E392A8FEA4374C3CD24578EF* L_6 = __this->___predicate;
		PlayerLoopSystem_t8AED6BF1C8A309CAA6FF71AC91DD33BDDFF7CF1F L_7 = V_0;
		NullCheck(L_6);
		bool L_8;
		L_8 = Func_2_Invoke_m92C683F52E538828B33BA3E1E37C285A7A73A744_inline(L_6, L_7, il2cpp_rgctx_method(method->klass->rgctx_data, 8));
		if (!L_8)
		{
			goto IL_0042;
		}
	}
	{
		PlayerLoopSystem_t8AED6BF1C8A309CAA6FF71AC91DD33BDDFF7CF1F L_9 = V_0;
		((Iterator_1_t90E419394494C38051F176EB657B6E351726C1A5*)__this)->___current = L_9;
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_t90E419394494C38051F176EB657B6E351726C1A5*)__this)->___current))->___type), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_t90E419394494C38051F176EB657B6E351726C1A5*)__this)->___current))->___subSystemList), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_t90E419394494C38051F176EB657B6E351726C1A5*)__this)->___current))->___updateDelegate), (void*)NULL);
		#endif
		return (bool)1;
	}

IL_0042:
	{
		int32_t L_10 = __this->___index;
		PlayerLoopSystemU5BU5D_t07C04E53AAC3CDA17603E8BA1B41D7E1AC083C6D* L_11 = __this->___source;
		NullCheck(L_11);
		if ((((int32_t)L_10) < ((int32_t)((int32_t)(((RuntimeArray*)L_11)->max_length)))))
		{
			goto IL_000b;
		}
	}
	{
		NullCheck((Iterator_1_t90E419394494C38051F176EB657B6E351726C1A5*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t90E419394494C38051F176EB657B6E351726C1A5*)__this);
	}

IL_0058:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereArrayIterator_1_Where_mDCA1B75D2B23CF4D8EFFBCCD52B55777B979B459_gshared (WhereArrayIterator_1_t6231D220871B84114C148960F57DC2479C42909F* __this, Func_2_t92F44173C14E7022E392A8FEA4374C3CD24578EF* ___0_predicate, const RuntimeMethod* method) 
{
	{
		PlayerLoopSystemU5BU5D_t07C04E53AAC3CDA17603E8BA1B41D7E1AC083C6D* L_0 = __this->___source;
		Func_2_t92F44173C14E7022E392A8FEA4374C3CD24578EF* L_1 = __this->___predicate;
		Func_2_t92F44173C14E7022E392A8FEA4374C3CD24578EF* L_2 = ___0_predicate;
		Func_2_t92F44173C14E7022E392A8FEA4374C3CD24578EF* L_3;
		L_3 = Enumerable_CombinePredicates_TisPlayerLoopSystem_t8AED6BF1C8A309CAA6FF71AC91DD33BDDFF7CF1F_m5B25B3D43C643FAB7D206EA8F9F4AF8AD600629C(L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 10));
		WhereArrayIterator_1_t6231D220871B84114C148960F57DC2479C42909F* L_4 = (WhereArrayIterator_1_t6231D220871B84114C148960F57DC2479C42909F*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 3));
		WhereArrayIterator_1__ctor_m1C57CC91AE53B7ED6FB71FB822B8C1480B667E73(L_4, L_0, L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 5));
		return (RuntimeObject*)L_4;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereArrayIterator_1__ctor_mD8BDE04F9897AAED299EE4DC32BF3879F2CBB668_gshared (WhereArrayIterator_1_tA7187088CE8DF4724576F6B7F633203C144505F6* __this, __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* ___0_source, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* ___1_predicate, const RuntimeMethod* method) 
{
	{
		((  void (*) (Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 0)))((Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_0 = ___0_source;
		il2cpp_codegen_write_instance_field_data<__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC*>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),0), L_0);
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_1 = ___1_predicate;
		il2cpp_codegen_write_instance_field_data<Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B*>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),1), L_1);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0* WhereArrayIterator_1_Clone_m1D80001794E47D2DF00A77273FD71D61987E8A44_gshared (WhereArrayIterator_1_tA7187088CE8DF4724576F6B7F633203C144505F6* __this, const RuntimeMethod* method) 
{
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_0 = *(__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),0));
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_1 = *(Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),1));
		WhereArrayIterator_1_tA7187088CE8DF4724576F6B7F633203C144505F6* L_2 = (WhereArrayIterator_1_tA7187088CE8DF4724576F6B7F633203C144505F6*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 3));
		((  void (*) (WhereArrayIterator_1_tA7187088CE8DF4724576F6B7F633203C144505F6*, __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC*, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 5)))(L_2, L_0, L_1, il2cpp_rgctx_method(method->klass->rgctx_data, 5));
		return (Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereArrayIterator_1_MoveNext_m42FC055181A1CDD12BBB46A9EE9ED76C6048BA07_gshared (WhereArrayIterator_1_tA7187088CE8DF4724576F6B7F633203C144505F6* __this, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_TSource_tA44A3A99F6F77148305A3C32D2C4DE1D4226338A = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 7));
	const Il2CppFullySharedGenericAny L_4 = alloca(SizeOf_TSource_tA44A3A99F6F77148305A3C32D2C4DE1D4226338A);
	const Il2CppFullySharedGenericAny L_9 = L_4;
	const Il2CppFullySharedGenericAny L_7 = alloca(SizeOf_TSource_tA44A3A99F6F77148305A3C32D2C4DE1D4226338A);
	Il2CppFullySharedGenericAny V_0 = alloca(SizeOf_TSource_tA44A3A99F6F77148305A3C32D2C4DE1D4226338A);
	memset(V_0, 0, SizeOf_TSource_tA44A3A99F6F77148305A3C32D2C4DE1D4226338A);
	{
		int32_t L_0 = *(int32_t*)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 6),1));
		if ((!(((uint32_t)L_0) == ((uint32_t)1))))
		{
			goto IL_0058;
		}
	}
	{
		goto IL_0042;
	}

IL_000b:
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_1 = *(__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),0));
		int32_t L_2 = *(int32_t*)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),2));
		NullCheck(L_1);
		int32_t L_3 = L_2;
		il2cpp_codegen_memcpy(L_4, (L_1)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_3)), SizeOf_TSource_tA44A3A99F6F77148305A3C32D2C4DE1D4226338A);
		il2cpp_codegen_memcpy(V_0, L_4, SizeOf_TSource_tA44A3A99F6F77148305A3C32D2C4DE1D4226338A);
		int32_t L_5 = *(int32_t*)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),2));
		il2cpp_codegen_write_instance_field_data<int32_t>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),2), ((int32_t)il2cpp_codegen_add(L_5, 1)));
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_6 = *(Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),1));
		il2cpp_codegen_memcpy(L_7, V_0, SizeOf_TSource_tA44A3A99F6F77148305A3C32D2C4DE1D4226338A);
		NullCheck(L_6);
		bool L_8;
		L_8 = InvokerFuncInvoker1< bool, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 8)), il2cpp_rgctx_method(method->klass->rgctx_data, 8), L_6, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 7)) ? L_7: *(void**)L_7));
		if (!L_8)
		{
			goto IL_0042;
		}
	}
	{
		il2cpp_codegen_memcpy(L_9, V_0, SizeOf_TSource_tA44A3A99F6F77148305A3C32D2C4DE1D4226338A);
		il2cpp_codegen_write_instance_field_data(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 6),2), L_9, SizeOf_TSource_tA44A3A99F6F77148305A3C32D2C4DE1D4226338A);
		return (bool)1;
	}

IL_0042:
	{
		int32_t L_10 = *(int32_t*)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),2));
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_11 = *(__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),0));
		NullCheck(L_11);
		if ((((int32_t)L_10) < ((int32_t)((int32_t)(((RuntimeArray*)L_11)->max_length)))))
		{
			goto IL_000b;
		}
	}
	{
		NullCheck((Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)__this);
	}

IL_0058:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereArrayIterator_1_Where_mB2C59E78355E518D359A6D5035BCD6254337B84E_gshared (WhereArrayIterator_1_tA7187088CE8DF4724576F6B7F633203C144505F6* __this, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* ___0_predicate, const RuntimeMethod* method) 
{
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_0 = *(__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),0));
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_1 = *(Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),1));
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_2 = ___0_predicate;
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_3;
		L_3 = ((  Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* (*) (Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B*, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 10)))(L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 10));
		WhereArrayIterator_1_tA7187088CE8DF4724576F6B7F633203C144505F6* L_4 = (WhereArrayIterator_1_tA7187088CE8DF4724576F6B7F633203C144505F6*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 3));
		((  void (*) (WhereArrayIterator_1_tA7187088CE8DF4724576F6B7F633203C144505F6*, __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC*, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 5)))(L_4, L_0, L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 5));
		return (RuntimeObject*)L_4;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereEnumerableIterator_1__ctor_mAC3CB25D22FD92F52FAB86D5A323EFAAD06F1BC1_gshared (WhereEnumerableIterator_1_t8003EA874EC8867895405A3AB37AFFC5E2B99308* __this, RuntimeObject* ___0_source, Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* ___1_predicate, const RuntimeMethod* method) 
{
	{
		Iterator_1__ctor_m0D72EABA02C6FB0A61DB8BDD0992DCD58C9C58FC((Iterator_1_t6F8827EED7DB0C845108D7DF969A608714128E05*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		RuntimeObject* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t6F8827EED7DB0C845108D7DF969A608714128E05* WhereEnumerableIterator_1_Clone_m9FDBCF564497D38A41568FA49D204AA6F3D63CCA_gshared (WhereEnumerableIterator_1_t8003EA874EC8867895405A3AB37AFFC5E2B99308* __this, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = __this->___source;
		Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* L_1 = __this->___predicate;
		WhereEnumerableIterator_1_t8003EA874EC8867895405A3AB37AFFC5E2B99308* L_2 = (WhereEnumerableIterator_1_t8003EA874EC8867895405A3AB37AFFC5E2B99308*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 3));
		WhereEnumerableIterator_1__ctor_mAC3CB25D22FD92F52FAB86D5A323EFAAD06F1BC1(L_2, L_0, L_1, il2cpp_rgctx_method(method->klass->rgctx_data, 5));
		return (Iterator_1_t6F8827EED7DB0C845108D7DF969A608714128E05*)L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereEnumerableIterator_1_Dispose_m8D9DC93D97417B3FE53AC4E1257959BB9DE19044_gshared (WhereEnumerableIterator_1_t8003EA874EC8867895405A3AB37AFFC5E2B99308* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		RuntimeObject* L_0 = __this->___enumerator;
		if (!L_0)
		{
			goto IL_0013;
		}
	}
	{
		RuntimeObject* L_1 = __this->___enumerator;
		NullCheck((RuntimeObject*)L_1);
		InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, (RuntimeObject*)L_1);
	}

IL_0013:
	{
		__this->___enumerator = (RuntimeObject*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___enumerator), (void*)(RuntimeObject*)NULL);
		NullCheck((Iterator_1_t6F8827EED7DB0C845108D7DF969A608714128E05*)__this);
		Iterator_1_Dispose_mB30A8BE0B5B87E0B8FDD55E51D43188B6F238BD1((Iterator_1_t6F8827EED7DB0C845108D7DF969A608714128E05*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 8));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereEnumerableIterator_1_MoveNext_m44E554EB39D2A51401AD404B7B236EA7E669EF74_gshared (WhereEnumerableIterator_1_t8003EA874EC8867895405A3AB37AFFC5E2B99308* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		int32_t L_0 = ((Iterator_1_t6F8827EED7DB0C845108D7DF969A608714128E05*)__this)->___state;
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_004e;
		}
	}
	{
		goto IL_0061;
	}

IL_0011:
	{
		RuntimeObject* L_3 = __this->___source;
		NullCheck(L_3);
		RuntimeObject* L_4;
		L_4 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 2), L_3);
		__this->___enumerator = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___enumerator), (void*)L_4);
		((Iterator_1_t6F8827EED7DB0C845108D7DF969A608714128E05*)__this)->___state = 2;
		goto IL_004e;
	}

IL_002b:
	{
		RuntimeObject* L_5 = __this->___enumerator;
		NullCheck(L_5);
		KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 L_6;
		L_6 = InterfaceFuncInvoker0< KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 7), L_5);
		V_1 = L_6;
		Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* L_7 = __this->___predicate;
		KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 L_8 = V_1;
		NullCheck(L_7);
		bool L_9;
		L_9 = Func_2_Invoke_m18A3A6EDA433C635C66C43DA6B86F7BC746BFDD0_inline(L_7, L_8, il2cpp_rgctx_method(method->klass->rgctx_data, 12));
		if (!L_9)
		{
			goto IL_004e;
		}
	}
	{
		KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 L_10 = V_1;
		((Iterator_1_t6F8827EED7DB0C845108D7DF969A608714128E05*)__this)->___current = L_10;
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_t6F8827EED7DB0C845108D7DF969A608714128E05*)__this)->___current))->___key), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_t6F8827EED7DB0C845108D7DF969A608714128E05*)__this)->___current))->___value), (void*)NULL);
		#endif
		return (bool)1;
	}

IL_004e:
	{
		RuntimeObject* L_11 = __this->___enumerator;
		NullCheck((RuntimeObject*)L_11);
		bool L_12;
		L_12 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, (RuntimeObject*)L_11);
		if (L_12)
		{
			goto IL_002b;
		}
	}
	{
		NullCheck((Iterator_1_t6F8827EED7DB0C845108D7DF969A608714128E05*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t6F8827EED7DB0C845108D7DF969A608714128E05*)__this);
	}

IL_0061:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereEnumerableIterator_1_Where_mF32E34B5368B0C805641DA58558AC6AA08C67983_gshared (WhereEnumerableIterator_1_t8003EA874EC8867895405A3AB37AFFC5E2B99308* __this, Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* ___0_predicate, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = __this->___source;
		Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* L_1 = __this->___predicate;
		Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* L_2 = ___0_predicate;
		Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* L_3;
		L_3 = Enumerable_CombinePredicates_TisKeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230_m9F329AA67F4C35877F54CE7441C4E759BCD33522(L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		WhereEnumerableIterator_1_t8003EA874EC8867895405A3AB37AFFC5E2B99308* L_4 = (WhereEnumerableIterator_1_t8003EA874EC8867895405A3AB37AFFC5E2B99308*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 3));
		WhereEnumerableIterator_1__ctor_mAC3CB25D22FD92F52FAB86D5A323EFAAD06F1BC1(L_4, L_0, L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 5));
		return (RuntimeObject*)L_4;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereEnumerableIterator_1__ctor_m7A674E2DF8B9F1C27EDB614D6EF6BECFA0B57C1D_gshared (WhereEnumerableIterator_1_t307785595D84CE47B35794516959DED6A6541913* __this, RuntimeObject* ___0_source, Func_2_tDBF8C754A8F1FC6DE54BB9904D2D81C266DFF6B4* ___1_predicate, const RuntimeMethod* method) 
{
	{
		Iterator_1__ctor_m933F57174CB01524F09C26B69041178FE65EE1E2((Iterator_1_t92BE161457BB4186D87644A87E4C1FAC67B8E430*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		RuntimeObject* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_tDBF8C754A8F1FC6DE54BB9904D2D81C266DFF6B4* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t92BE161457BB4186D87644A87E4C1FAC67B8E430* WhereEnumerableIterator_1_Clone_mE5EBBF003B428B1CC333B7C34FF10ED113D9EBDA_gshared (WhereEnumerableIterator_1_t307785595D84CE47B35794516959DED6A6541913* __this, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = __this->___source;
		Func_2_tDBF8C754A8F1FC6DE54BB9904D2D81C266DFF6B4* L_1 = __this->___predicate;
		WhereEnumerableIterator_1_t307785595D84CE47B35794516959DED6A6541913* L_2 = (WhereEnumerableIterator_1_t307785595D84CE47B35794516959DED6A6541913*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 3));
		WhereEnumerableIterator_1__ctor_m7A674E2DF8B9F1C27EDB614D6EF6BECFA0B57C1D(L_2, L_0, L_1, il2cpp_rgctx_method(method->klass->rgctx_data, 5));
		return (Iterator_1_t92BE161457BB4186D87644A87E4C1FAC67B8E430*)L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereEnumerableIterator_1_Dispose_m7EF10848D0B7D2E3659F7FB1C32DB1B5BDB27BAC_gshared (WhereEnumerableIterator_1_t307785595D84CE47B35794516959DED6A6541913* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		RuntimeObject* L_0 = __this->___enumerator;
		if (!L_0)
		{
			goto IL_0013;
		}
	}
	{
		RuntimeObject* L_1 = __this->___enumerator;
		NullCheck((RuntimeObject*)L_1);
		InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, (RuntimeObject*)L_1);
	}

IL_0013:
	{
		__this->___enumerator = (RuntimeObject*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___enumerator), (void*)(RuntimeObject*)NULL);
		NullCheck((Iterator_1_t92BE161457BB4186D87644A87E4C1FAC67B8E430*)__this);
		Iterator_1_Dispose_m0C3F89201F6D4DCC8782FC7192792E0F19D6A50D((Iterator_1_t92BE161457BB4186D87644A87E4C1FAC67B8E430*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 8));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereEnumerableIterator_1_MoveNext_m01E45A658EA9D51A014453018F5D7405B4E4A344_gshared (WhereEnumerableIterator_1_t307785595D84CE47B35794516959DED6A6541913* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	DictionaryEntry_t171080F37B311C25AA9E75888F9C9D703FA721BB V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		int32_t L_0 = ((Iterator_1_t92BE161457BB4186D87644A87E4C1FAC67B8E430*)__this)->___state;
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_004e;
		}
	}
	{
		goto IL_0061;
	}

IL_0011:
	{
		RuntimeObject* L_3 = __this->___source;
		NullCheck(L_3);
		RuntimeObject* L_4;
		L_4 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 2), L_3);
		__this->___enumerator = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___enumerator), (void*)L_4);
		((Iterator_1_t92BE161457BB4186D87644A87E4C1FAC67B8E430*)__this)->___state = 2;
		goto IL_004e;
	}

IL_002b:
	{
		RuntimeObject* L_5 = __this->___enumerator;
		NullCheck(L_5);
		DictionaryEntry_t171080F37B311C25AA9E75888F9C9D703FA721BB L_6;
		L_6 = InterfaceFuncInvoker0< DictionaryEntry_t171080F37B311C25AA9E75888F9C9D703FA721BB >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 7), L_5);
		V_1 = L_6;
		Func_2_tDBF8C754A8F1FC6DE54BB9904D2D81C266DFF6B4* L_7 = __this->___predicate;
		DictionaryEntry_t171080F37B311C25AA9E75888F9C9D703FA721BB L_8 = V_1;
		NullCheck(L_7);
		bool L_9;
		L_9 = Func_2_Invoke_mDDB42512D647D9FDCAD0330A12EDB64CAD533A99_inline(L_7, L_8, il2cpp_rgctx_method(method->klass->rgctx_data, 12));
		if (!L_9)
		{
			goto IL_004e;
		}
	}
	{
		DictionaryEntry_t171080F37B311C25AA9E75888F9C9D703FA721BB L_10 = V_1;
		((Iterator_1_t92BE161457BB4186D87644A87E4C1FAC67B8E430*)__this)->___current = L_10;
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_t92BE161457BB4186D87644A87E4C1FAC67B8E430*)__this)->___current))->____key), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_t92BE161457BB4186D87644A87E4C1FAC67B8E430*)__this)->___current))->____value), (void*)NULL);
		#endif
		return (bool)1;
	}

IL_004e:
	{
		RuntimeObject* L_11 = __this->___enumerator;
		NullCheck((RuntimeObject*)L_11);
		bool L_12;
		L_12 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, (RuntimeObject*)L_11);
		if (L_12)
		{
			goto IL_002b;
		}
	}
	{
		NullCheck((Iterator_1_t92BE161457BB4186D87644A87E4C1FAC67B8E430*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t92BE161457BB4186D87644A87E4C1FAC67B8E430*)__this);
	}

IL_0061:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereEnumerableIterator_1_Where_mBEE94B454865699DAABFF942BB2B529F103D7FC9_gshared (WhereEnumerableIterator_1_t307785595D84CE47B35794516959DED6A6541913* __this, Func_2_tDBF8C754A8F1FC6DE54BB9904D2D81C266DFF6B4* ___0_predicate, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = __this->___source;
		Func_2_tDBF8C754A8F1FC6DE54BB9904D2D81C266DFF6B4* L_1 = __this->___predicate;
		Func_2_tDBF8C754A8F1FC6DE54BB9904D2D81C266DFF6B4* L_2 = ___0_predicate;
		Func_2_tDBF8C754A8F1FC6DE54BB9904D2D81C266DFF6B4* L_3;
		L_3 = Enumerable_CombinePredicates_TisDictionaryEntry_t171080F37B311C25AA9E75888F9C9D703FA721BB_mCECAAD107FF8AACD47787010168E5865A658D20C(L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		WhereEnumerableIterator_1_t307785595D84CE47B35794516959DED6A6541913* L_4 = (WhereEnumerableIterator_1_t307785595D84CE47B35794516959DED6A6541913*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 3));
		WhereEnumerableIterator_1__ctor_m7A674E2DF8B9F1C27EDB614D6EF6BECFA0B57C1D(L_4, L_0, L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 5));
		return (RuntimeObject*)L_4;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereEnumerableIterator_1__ctor_mA7F4C6508A043D99B8288E43867D576F4697E4EE_gshared (WhereEnumerableIterator_1_t5DBA717695B8C7E60489C86AEB1FF673F50E293A* __this, RuntimeObject* ___0_source, Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA* ___1_predicate, const RuntimeMethod* method) 
{
	{
		Iterator_1__ctor_m426D8BD95B00FDA5C5E8FAE956FCB74E54BC7CC7((Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		RuntimeObject* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07* WhereEnumerableIterator_1_Clone_mAFEC8AC144406F3887B35086067C91941529099D_gshared (WhereEnumerableIterator_1_t5DBA717695B8C7E60489C86AEB1FF673F50E293A* __this, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = __this->___source;
		Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA* L_1 = __this->___predicate;
		WhereEnumerableIterator_1_t5DBA717695B8C7E60489C86AEB1FF673F50E293A* L_2 = (WhereEnumerableIterator_1_t5DBA717695B8C7E60489C86AEB1FF673F50E293A*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 3));
		WhereEnumerableIterator_1__ctor_mA7F4C6508A043D99B8288E43867D576F4697E4EE(L_2, L_0, L_1, il2cpp_rgctx_method(method->klass->rgctx_data, 5));
		return (Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereEnumerableIterator_1_Dispose_m046EF6284565F4F5AF409A4B5E0B1FB2C7804928_gshared (WhereEnumerableIterator_1_t5DBA717695B8C7E60489C86AEB1FF673F50E293A* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		RuntimeObject* L_0 = __this->___enumerator;
		if (!L_0)
		{
			goto IL_0013;
		}
	}
	{
		RuntimeObject* L_1 = __this->___enumerator;
		NullCheck((RuntimeObject*)L_1);
		InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, (RuntimeObject*)L_1);
	}

IL_0013:
	{
		__this->___enumerator = (RuntimeObject*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___enumerator), (void*)(RuntimeObject*)NULL);
		NullCheck((Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this);
		Iterator_1_Dispose_m93D0EFD9DDA495E64D508A05C5065C6AC5C4A3DB((Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 8));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereEnumerableIterator_1_MoveNext_m2649D49B9944BB42677F9293529BB274537F69C2_gshared (WhereEnumerableIterator_1_t5DBA717695B8C7E60489C86AEB1FF673F50E293A* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		int32_t L_0 = ((Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this)->___state;
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_004e;
		}
	}
	{
		goto IL_0061;
	}

IL_0011:
	{
		RuntimeObject* L_3 = __this->___source;
		NullCheck(L_3);
		RuntimeObject* L_4;
		L_4 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 2), L_3);
		__this->___enumerator = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___enumerator), (void*)L_4);
		((Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this)->___state = 2;
		goto IL_004e;
	}

IL_002b:
	{
		RuntimeObject* L_5 = __this->___enumerator;
		NullCheck(L_5);
		int32_t L_6;
		L_6 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 7), L_5);
		V_1 = L_6;
		Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA* L_7 = __this->___predicate;
		int32_t L_8 = V_1;
		NullCheck(L_7);
		bool L_9;
		L_9 = Func_2_Invoke_m1543D7041BADF87D1F63EBF838B0DDCB40340C7E_inline(L_7, L_8, il2cpp_rgctx_method(method->klass->rgctx_data, 12));
		if (!L_9)
		{
			goto IL_004e;
		}
	}
	{
		int32_t L_10 = V_1;
		((Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this)->___current = L_10;
		return (bool)1;
	}

IL_004e:
	{
		RuntimeObject* L_11 = __this->___enumerator;
		NullCheck((RuntimeObject*)L_11);
		bool L_12;
		L_12 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, (RuntimeObject*)L_11);
		if (L_12)
		{
			goto IL_002b;
		}
	}
	{
		NullCheck((Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this);
	}

IL_0061:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereEnumerableIterator_1_Where_m778E7EFD3E0BB0A2A0BE3B4898FB24EAA000FDC1_gshared (WhereEnumerableIterator_1_t5DBA717695B8C7E60489C86AEB1FF673F50E293A* __this, Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA* ___0_predicate, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = __this->___source;
		Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA* L_1 = __this->___predicate;
		Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA* L_2 = ___0_predicate;
		Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA* L_3;
		L_3 = Enumerable_CombinePredicates_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m6E21210FBAD8C39907D331F6A3BE2E5409690ED0(L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		WhereEnumerableIterator_1_t5DBA717695B8C7E60489C86AEB1FF673F50E293A* L_4 = (WhereEnumerableIterator_1_t5DBA717695B8C7E60489C86AEB1FF673F50E293A*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 3));
		WhereEnumerableIterator_1__ctor_mA7F4C6508A043D99B8288E43867D576F4697E4EE(L_4, L_0, L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 5));
		return (RuntimeObject*)L_4;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereEnumerableIterator_1__ctor_m6C929ED5C1A2B964D41834542D001D44C5784AE1_gshared (WhereEnumerableIterator_1_t7F233A4115A2DA7F213075592407137456080374* __this, RuntimeObject* ___0_source, Func_2_t1C8F983F9A1AA802D45E89037E2AA7ACD1094821* ___1_predicate, const RuntimeMethod* method) 
{
	{
		Iterator_1__ctor_m9788F4EF50A0094F325E620BFC1D32ED3DAE63BB((Iterator_1_tEEF82AE11FFC6DF9B283B2D5E4A87B3E3BFD805E*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		RuntimeObject* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t1C8F983F9A1AA802D45E89037E2AA7ACD1094821* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_tEEF82AE11FFC6DF9B283B2D5E4A87B3E3BFD805E* WhereEnumerableIterator_1_Clone_m7A60F3759CC49AAA54B380B5F4A3648E8AC9C447_gshared (WhereEnumerableIterator_1_t7F233A4115A2DA7F213075592407137456080374* __this, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = __this->___source;
		Func_2_t1C8F983F9A1AA802D45E89037E2AA7ACD1094821* L_1 = __this->___predicate;
		WhereEnumerableIterator_1_t7F233A4115A2DA7F213075592407137456080374* L_2 = (WhereEnumerableIterator_1_t7F233A4115A2DA7F213075592407137456080374*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 3));
		WhereEnumerableIterator_1__ctor_m6C929ED5C1A2B964D41834542D001D44C5784AE1(L_2, L_0, L_1, il2cpp_rgctx_method(method->klass->rgctx_data, 5));
		return (Iterator_1_tEEF82AE11FFC6DF9B283B2D5E4A87B3E3BFD805E*)L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereEnumerableIterator_1_Dispose_mECDD6AB7D8CB9C55637DF27E09D7D8E9F6387D1E_gshared (WhereEnumerableIterator_1_t7F233A4115A2DA7F213075592407137456080374* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		RuntimeObject* L_0 = __this->___enumerator;
		if (!L_0)
		{
			goto IL_0013;
		}
	}
	{
		RuntimeObject* L_1 = __this->___enumerator;
		NullCheck((RuntimeObject*)L_1);
		InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, (RuntimeObject*)L_1);
	}

IL_0013:
	{
		__this->___enumerator = (RuntimeObject*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___enumerator), (void*)(RuntimeObject*)NULL);
		NullCheck((Iterator_1_tEEF82AE11FFC6DF9B283B2D5E4A87B3E3BFD805E*)__this);
		Iterator_1_Dispose_m89F7D8F3585BD29529FDA11B1BA731F94A3F1270((Iterator_1_tEEF82AE11FFC6DF9B283B2D5E4A87B3E3BFD805E*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 8));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereEnumerableIterator_1_MoveNext_m7F33119EB0749CED31E2268F7B58070E3B3111A3_gshared (WhereEnumerableIterator_1_t7F233A4115A2DA7F213075592407137456080374* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		int32_t L_0 = ((Iterator_1_tEEF82AE11FFC6DF9B283B2D5E4A87B3E3BFD805E*)__this)->___state;
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_004e;
		}
	}
	{
		goto IL_0061;
	}

IL_0011:
	{
		RuntimeObject* L_3 = __this->___source;
		NullCheck(L_3);
		RuntimeObject* L_4;
		L_4 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 2), L_3);
		__this->___enumerator = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___enumerator), (void*)L_4);
		((Iterator_1_tEEF82AE11FFC6DF9B283B2D5E4A87B3E3BFD805E*)__this)->___state = 2;
		goto IL_004e;
	}

IL_002b:
	{
		RuntimeObject* L_5 = __this->___enumerator;
		NullCheck(L_5);
		int32_t L_6;
		L_6 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 7), L_5);
		V_1 = L_6;
		Func_2_t1C8F983F9A1AA802D45E89037E2AA7ACD1094821* L_7 = __this->___predicate;
		int32_t L_8 = V_1;
		NullCheck(L_7);
		bool L_9;
		L_9 = Func_2_Invoke_m095D2006A2DDB336987862DC15A7EFAED53E08EC_inline(L_7, L_8, il2cpp_rgctx_method(method->klass->rgctx_data, 12));
		if (!L_9)
		{
			goto IL_004e;
		}
	}
	{
		int32_t L_10 = V_1;
		((Iterator_1_tEEF82AE11FFC6DF9B283B2D5E4A87B3E3BFD805E*)__this)->___current = L_10;
		return (bool)1;
	}

IL_004e:
	{
		RuntimeObject* L_11 = __this->___enumerator;
		NullCheck((RuntimeObject*)L_11);
		bool L_12;
		L_12 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, (RuntimeObject*)L_11);
		if (L_12)
		{
			goto IL_002b;
		}
	}
	{
		NullCheck((Iterator_1_tEEF82AE11FFC6DF9B283B2D5E4A87B3E3BFD805E*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_tEEF82AE11FFC6DF9B283B2D5E4A87B3E3BFD805E*)__this);
	}

IL_0061:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereEnumerableIterator_1_Where_m0B71F8FE04C96B283FBE3C4C5A7833E4A672330E_gshared (WhereEnumerableIterator_1_t7F233A4115A2DA7F213075592407137456080374* __this, Func_2_t1C8F983F9A1AA802D45E89037E2AA7ACD1094821* ___0_predicate, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = __this->___source;
		Func_2_t1C8F983F9A1AA802D45E89037E2AA7ACD1094821* L_1 = __this->___predicate;
		Func_2_t1C8F983F9A1AA802D45E89037E2AA7ACD1094821* L_2 = ___0_predicate;
		Func_2_t1C8F983F9A1AA802D45E89037E2AA7ACD1094821* L_3;
		L_3 = Enumerable_CombinePredicates_TisInt32Enum_tCBAC8BA2BFF3A845FA599F303093BBBA374B6F0C_m88CBD9562882820B08530454AF5A344C7453C267(L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		WhereEnumerableIterator_1_t7F233A4115A2DA7F213075592407137456080374* L_4 = (WhereEnumerableIterator_1_t7F233A4115A2DA7F213075592407137456080374*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 3));
		WhereEnumerableIterator_1__ctor_m6C929ED5C1A2B964D41834542D001D44C5784AE1(L_4, L_0, L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 5));
		return (RuntimeObject*)L_4;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereEnumerableIterator_1__ctor_m8C0DA4CDA5431C03561F67C4393BB18CDD891F01_gshared (WhereEnumerableIterator_1_t1E787D13759F5A31C94B3FAED181402B25C278F4* __this, RuntimeObject* ___0_source, Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* ___1_predicate, const RuntimeMethod* method) 
{
	{
		Iterator_1__ctor_m3E47867714E05673E54C6B73D9242F5FFADA1F63((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		RuntimeObject* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA* WhereEnumerableIterator_1_Clone_m25DBF44FABBFE76AB4314BD7F62334FE2A74F5CA_gshared (WhereEnumerableIterator_1_t1E787D13759F5A31C94B3FAED181402B25C278F4* __this, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = __this->___source;
		Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* L_1 = __this->___predicate;
		WhereEnumerableIterator_1_t1E787D13759F5A31C94B3FAED181402B25C278F4* L_2 = (WhereEnumerableIterator_1_t1E787D13759F5A31C94B3FAED181402B25C278F4*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 3));
		WhereEnumerableIterator_1__ctor_m8C0DA4CDA5431C03561F67C4393BB18CDD891F01(L_2, L_0, L_1, il2cpp_rgctx_method(method->klass->rgctx_data, 5));
		return (Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereEnumerableIterator_1_Dispose_m7EB3C00CC0ED06056CF70FE322BF44A93F0C4136_gshared (WhereEnumerableIterator_1_t1E787D13759F5A31C94B3FAED181402B25C278F4* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		RuntimeObject* L_0 = __this->___enumerator;
		if (!L_0)
		{
			goto IL_0013;
		}
	}
	{
		RuntimeObject* L_1 = __this->___enumerator;
		NullCheck((RuntimeObject*)L_1);
		InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, (RuntimeObject*)L_1);
	}

IL_0013:
	{
		__this->___enumerator = (RuntimeObject*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___enumerator), (void*)(RuntimeObject*)NULL);
		NullCheck((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this);
		Iterator_1_Dispose_m953BCF886C8A63456821023DBA45EBD9AC44EB07((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 8));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereEnumerableIterator_1_MoveNext_m7F8C3A8E4FC2835971FF35C1F4C51A061483BEDD_gshared (WhereEnumerableIterator_1_t1E787D13759F5A31C94B3FAED181402B25C278F4* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	RuntimeObject* V_1 = NULL;
	{
		int32_t L_0 = ((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this)->___state;
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_004e;
		}
	}
	{
		goto IL_0061;
	}

IL_0011:
	{
		RuntimeObject* L_3 = __this->___source;
		NullCheck(L_3);
		RuntimeObject* L_4;
		L_4 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 2), L_3);
		__this->___enumerator = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___enumerator), (void*)L_4);
		((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this)->___state = 2;
		goto IL_004e;
	}

IL_002b:
	{
		RuntimeObject* L_5 = __this->___enumerator;
		NullCheck(L_5);
		RuntimeObject* L_6;
		L_6 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 7), L_5);
		V_1 = L_6;
		Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* L_7 = __this->___predicate;
		RuntimeObject* L_8 = V_1;
		NullCheck(L_7);
		bool L_9;
		L_9 = Func_2_Invoke_m2014423FB900F135C8FF994125604FF9E6AAE829_inline(L_7, L_8, il2cpp_rgctx_method(method->klass->rgctx_data, 12));
		if (!L_9)
		{
			goto IL_004e;
		}
	}
	{
		RuntimeObject* L_10 = V_1;
		((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this)->___current = L_10;
		Il2CppCodeGenWriteBarrier((void**)(&((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this)->___current), (void*)L_10);
		return (bool)1;
	}

IL_004e:
	{
		RuntimeObject* L_11 = __this->___enumerator;
		NullCheck((RuntimeObject*)L_11);
		bool L_12;
		L_12 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, (RuntimeObject*)L_11);
		if (L_12)
		{
			goto IL_002b;
		}
	}
	{
		NullCheck((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this);
	}

IL_0061:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereEnumerableIterator_1_Where_m48ED4EDDA686615E779F1400A17479B243C85100_gshared (WhereEnumerableIterator_1_t1E787D13759F5A31C94B3FAED181402B25C278F4* __this, Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* ___0_predicate, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = __this->___source;
		Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* L_1 = __this->___predicate;
		Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* L_2 = ___0_predicate;
		Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* L_3;
		L_3 = Enumerable_CombinePredicates_TisRuntimeObject_m613479C29B013E8FC2987E22F42A3BC6CC2C9768(L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		WhereEnumerableIterator_1_t1E787D13759F5A31C94B3FAED181402B25C278F4* L_4 = (WhereEnumerableIterator_1_t1E787D13759F5A31C94B3FAED181402B25C278F4*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 3));
		WhereEnumerableIterator_1__ctor_m8C0DA4CDA5431C03561F67C4393BB18CDD891F01(L_4, L_0, L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 5));
		return (RuntimeObject*)L_4;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereEnumerableIterator_1__ctor_m8B955BCA6F751E2E1C64E3C4C7615E7D55F83C37_gshared (WhereEnumerableIterator_1_tA0D618D4EA7801FF9CD22AE1C91E2DC17F8DC7C8* __this, RuntimeObject* ___0_source, Func_2_t92F44173C14E7022E392A8FEA4374C3CD24578EF* ___1_predicate, const RuntimeMethod* method) 
{
	{
		Iterator_1__ctor_mF6CD5E26F94CF7F842315D35A872B8C7298BD467((Iterator_1_t90E419394494C38051F176EB657B6E351726C1A5*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		RuntimeObject* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t92F44173C14E7022E392A8FEA4374C3CD24578EF* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t90E419394494C38051F176EB657B6E351726C1A5* WhereEnumerableIterator_1_Clone_m1A2F1D30894C4C8AE083AA3A2EC1388556C8C286_gshared (WhereEnumerableIterator_1_tA0D618D4EA7801FF9CD22AE1C91E2DC17F8DC7C8* __this, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = __this->___source;
		Func_2_t92F44173C14E7022E392A8FEA4374C3CD24578EF* L_1 = __this->___predicate;
		WhereEnumerableIterator_1_tA0D618D4EA7801FF9CD22AE1C91E2DC17F8DC7C8* L_2 = (WhereEnumerableIterator_1_tA0D618D4EA7801FF9CD22AE1C91E2DC17F8DC7C8*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 3));
		WhereEnumerableIterator_1__ctor_m8B955BCA6F751E2E1C64E3C4C7615E7D55F83C37(L_2, L_0, L_1, il2cpp_rgctx_method(method->klass->rgctx_data, 5));
		return (Iterator_1_t90E419394494C38051F176EB657B6E351726C1A5*)L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereEnumerableIterator_1_Dispose_m12FEACE38B967751E2B2CCF1B3B38C953204CCDA_gshared (WhereEnumerableIterator_1_tA0D618D4EA7801FF9CD22AE1C91E2DC17F8DC7C8* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		RuntimeObject* L_0 = __this->___enumerator;
		if (!L_0)
		{
			goto IL_0013;
		}
	}
	{
		RuntimeObject* L_1 = __this->___enumerator;
		NullCheck((RuntimeObject*)L_1);
		InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, (RuntimeObject*)L_1);
	}

IL_0013:
	{
		__this->___enumerator = (RuntimeObject*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___enumerator), (void*)(RuntimeObject*)NULL);
		NullCheck((Iterator_1_t90E419394494C38051F176EB657B6E351726C1A5*)__this);
		Iterator_1_Dispose_m5E5916CF9E0DA02FA29F58CFA96D30C750292197((Iterator_1_t90E419394494C38051F176EB657B6E351726C1A5*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 8));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereEnumerableIterator_1_MoveNext_m3B24DBC1C5DEA3149816D046AD8E708AA915D729_gshared (WhereEnumerableIterator_1_tA0D618D4EA7801FF9CD22AE1C91E2DC17F8DC7C8* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	PlayerLoopSystem_t8AED6BF1C8A309CAA6FF71AC91DD33BDDFF7CF1F V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		int32_t L_0 = ((Iterator_1_t90E419394494C38051F176EB657B6E351726C1A5*)__this)->___state;
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_004e;
		}
	}
	{
		goto IL_0061;
	}

IL_0011:
	{
		RuntimeObject* L_3 = __this->___source;
		NullCheck(L_3);
		RuntimeObject* L_4;
		L_4 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 2), L_3);
		__this->___enumerator = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___enumerator), (void*)L_4);
		((Iterator_1_t90E419394494C38051F176EB657B6E351726C1A5*)__this)->___state = 2;
		goto IL_004e;
	}

IL_002b:
	{
		RuntimeObject* L_5 = __this->___enumerator;
		NullCheck(L_5);
		PlayerLoopSystem_t8AED6BF1C8A309CAA6FF71AC91DD33BDDFF7CF1F L_6;
		L_6 = InterfaceFuncInvoker0< PlayerLoopSystem_t8AED6BF1C8A309CAA6FF71AC91DD33BDDFF7CF1F >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 7), L_5);
		V_1 = L_6;
		Func_2_t92F44173C14E7022E392A8FEA4374C3CD24578EF* L_7 = __this->___predicate;
		PlayerLoopSystem_t8AED6BF1C8A309CAA6FF71AC91DD33BDDFF7CF1F L_8 = V_1;
		NullCheck(L_7);
		bool L_9;
		L_9 = Func_2_Invoke_m92C683F52E538828B33BA3E1E37C285A7A73A744_inline(L_7, L_8, il2cpp_rgctx_method(method->klass->rgctx_data, 12));
		if (!L_9)
		{
			goto IL_004e;
		}
	}
	{
		PlayerLoopSystem_t8AED6BF1C8A309CAA6FF71AC91DD33BDDFF7CF1F L_10 = V_1;
		((Iterator_1_t90E419394494C38051F176EB657B6E351726C1A5*)__this)->___current = L_10;
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_t90E419394494C38051F176EB657B6E351726C1A5*)__this)->___current))->___type), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_t90E419394494C38051F176EB657B6E351726C1A5*)__this)->___current))->___subSystemList), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_t90E419394494C38051F176EB657B6E351726C1A5*)__this)->___current))->___updateDelegate), (void*)NULL);
		#endif
		return (bool)1;
	}

IL_004e:
	{
		RuntimeObject* L_11 = __this->___enumerator;
		NullCheck((RuntimeObject*)L_11);
		bool L_12;
		L_12 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, (RuntimeObject*)L_11);
		if (L_12)
		{
			goto IL_002b;
		}
	}
	{
		NullCheck((Iterator_1_t90E419394494C38051F176EB657B6E351726C1A5*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t90E419394494C38051F176EB657B6E351726C1A5*)__this);
	}

IL_0061:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereEnumerableIterator_1_Where_m17BC9A963B8CDE24E0750302057B949B873946D0_gshared (WhereEnumerableIterator_1_tA0D618D4EA7801FF9CD22AE1C91E2DC17F8DC7C8* __this, Func_2_t92F44173C14E7022E392A8FEA4374C3CD24578EF* ___0_predicate, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = __this->___source;
		Func_2_t92F44173C14E7022E392A8FEA4374C3CD24578EF* L_1 = __this->___predicate;
		Func_2_t92F44173C14E7022E392A8FEA4374C3CD24578EF* L_2 = ___0_predicate;
		Func_2_t92F44173C14E7022E392A8FEA4374C3CD24578EF* L_3;
		L_3 = Enumerable_CombinePredicates_TisPlayerLoopSystem_t8AED6BF1C8A309CAA6FF71AC91DD33BDDFF7CF1F_m5B25B3D43C643FAB7D206EA8F9F4AF8AD600629C(L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		WhereEnumerableIterator_1_tA0D618D4EA7801FF9CD22AE1C91E2DC17F8DC7C8* L_4 = (WhereEnumerableIterator_1_tA0D618D4EA7801FF9CD22AE1C91E2DC17F8DC7C8*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 3));
		WhereEnumerableIterator_1__ctor_m8B955BCA6F751E2E1C64E3C4C7615E7D55F83C37(L_4, L_0, L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 5));
		return (RuntimeObject*)L_4;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereEnumerableIterator_1__ctor_m2DD2BB86C5517EDD8C051BBF8CE38C43D712A8D6_gshared (WhereEnumerableIterator_1_t8B24528558F527941435C4FE1D046216FE4F277B* __this, RuntimeObject* ___0_source, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* ___1_predicate, const RuntimeMethod* method) 
{
	{
		((  void (*) (Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 0)))((Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		RuntimeObject* L_0 = ___0_source;
		il2cpp_codegen_write_instance_field_data<RuntimeObject*>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),0), L_0);
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_1 = ___1_predicate;
		il2cpp_codegen_write_instance_field_data<Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B*>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),1), L_1);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0* WhereEnumerableIterator_1_Clone_m0317D203B88386A9A479C72FA9D62763FD0A91D3_gshared (WhereEnumerableIterator_1_t8B24528558F527941435C4FE1D046216FE4F277B* __this, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = *(RuntimeObject**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),0));
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_1 = *(Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),1));
		WhereEnumerableIterator_1_t8B24528558F527941435C4FE1D046216FE4F277B* L_2 = (WhereEnumerableIterator_1_t8B24528558F527941435C4FE1D046216FE4F277B*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 3));
		((  void (*) (WhereEnumerableIterator_1_t8B24528558F527941435C4FE1D046216FE4F277B*, RuntimeObject*, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 5)))(L_2, L_0, L_1, il2cpp_rgctx_method(method->klass->rgctx_data, 5));
		return (Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereEnumerableIterator_1_Dispose_m2583FECFDC8EDFE66C959C7C386F99E287C5763E_gshared (WhereEnumerableIterator_1_t8B24528558F527941435C4FE1D046216FE4F277B* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		RuntimeObject* L_0 = *(RuntimeObject**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),2));
		if (!L_0)
		{
			goto IL_0013;
		}
	}
	{
		RuntimeObject* L_1 = *(RuntimeObject**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),2));
		NullCheck((RuntimeObject*)L_1);
		InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, (RuntimeObject*)L_1);
	}

IL_0013:
	{
		il2cpp_codegen_write_instance_field_data<RuntimeObject*>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),2), (RuntimeObject*)NULL);
		NullCheck((Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)__this);
		((  void (*) (Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 8)))((Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 8));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereEnumerableIterator_1_MoveNext_m1A18D4050C069B6C4310DAB9857281E37DCB2C69_gshared (WhereEnumerableIterator_1_t8B24528558F527941435C4FE1D046216FE4F277B* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	const uint32_t SizeOf_TSource_tC0EDCBB06D927E5200EDA4B413FCECB2FDD7AFEB = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 11));
	const Il2CppFullySharedGenericAny L_6 = alloca(SizeOf_TSource_tC0EDCBB06D927E5200EDA4B413FCECB2FDD7AFEB);
	const Il2CppFullySharedGenericAny L_10 = L_6;
	const Il2CppFullySharedGenericAny L_8 = alloca(SizeOf_TSource_tC0EDCBB06D927E5200EDA4B413FCECB2FDD7AFEB);
	int32_t V_0 = 0;
	Il2CppFullySharedGenericAny V_1 = alloca(SizeOf_TSource_tC0EDCBB06D927E5200EDA4B413FCECB2FDD7AFEB);
	memset(V_1, 0, SizeOf_TSource_tC0EDCBB06D927E5200EDA4B413FCECB2FDD7AFEB);
	{
		int32_t L_0 = *(int32_t*)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 6),1));
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_004e;
		}
	}
	{
		goto IL_0061;
	}

IL_0011:
	{
		RuntimeObject* L_3 = *(RuntimeObject**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),0));
		NullCheck(L_3);
		RuntimeObject* L_4;
		L_4 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 2), L_3);
		il2cpp_codegen_write_instance_field_data<RuntimeObject*>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),2), L_4);
		il2cpp_codegen_write_instance_field_data<int32_t>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 6),1), 2);
		goto IL_004e;
	}

IL_002b:
	{
		RuntimeObject* L_5 = *(RuntimeObject**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),2));
		NullCheck(L_5);
		InterfaceActionInvoker1Invoker< Il2CppFullySharedGenericAny* >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 7), L_5, (Il2CppFullySharedGenericAny*)L_6);
		il2cpp_codegen_memcpy(V_1, L_6, SizeOf_TSource_tC0EDCBB06D927E5200EDA4B413FCECB2FDD7AFEB);
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_7 = *(Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),1));
		il2cpp_codegen_memcpy(L_8, V_1, SizeOf_TSource_tC0EDCBB06D927E5200EDA4B413FCECB2FDD7AFEB);
		NullCheck(L_7);
		bool L_9;
		L_9 = InvokerFuncInvoker1< bool, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 12)), il2cpp_rgctx_method(method->klass->rgctx_data, 12), L_7, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 11)) ? L_8: *(void**)L_8));
		if (!L_9)
		{
			goto IL_004e;
		}
	}
	{
		il2cpp_codegen_memcpy(L_10, V_1, SizeOf_TSource_tC0EDCBB06D927E5200EDA4B413FCECB2FDD7AFEB);
		il2cpp_codegen_write_instance_field_data(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 6),2), L_10, SizeOf_TSource_tC0EDCBB06D927E5200EDA4B413FCECB2FDD7AFEB);
		return (bool)1;
	}

IL_004e:
	{
		RuntimeObject* L_11 = *(RuntimeObject**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),2));
		NullCheck((RuntimeObject*)L_11);
		bool L_12;
		L_12 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, (RuntimeObject*)L_11);
		if (L_12)
		{
			goto IL_002b;
		}
	}
	{
		NullCheck((Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)__this);
	}

IL_0061:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereEnumerableIterator_1_Where_mC623267514B4299E409A01161DBBDA5362CEDFC2_gshared (WhereEnumerableIterator_1_t8B24528558F527941435C4FE1D046216FE4F277B* __this, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* ___0_predicate, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = *(RuntimeObject**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),0));
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_1 = *(Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),1));
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_2 = ___0_predicate;
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_3;
		L_3 = ((  Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* (*) (Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B*, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 13)))(L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		WhereEnumerableIterator_1_t8B24528558F527941435C4FE1D046216FE4F277B* L_4 = (WhereEnumerableIterator_1_t8B24528558F527941435C4FE1D046216FE4F277B*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 3));
		((  void (*) (WhereEnumerableIterator_1_t8B24528558F527941435C4FE1D046216FE4F277B*, RuntimeObject*, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 5)))(L_4, L_0, L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 5));
		return (RuntimeObject*)L_4;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereListIterator_1__ctor_m3333DE6CD3476F2462F6D1B996546C42075A6374_gshared (WhereListIterator_1_t1F690B0B32001794569AD59FAF2DA7A3BD84F4E5* __this, List_1_t8A1639802238DEF3222B6CBBC0DEF0B4B5F350EB* ___0_source, Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* ___1_predicate, const RuntimeMethod* method) 
{
	{
		Iterator_1__ctor_m0D72EABA02C6FB0A61DB8BDD0992DCD58C9C58FC((Iterator_1_t6F8827EED7DB0C845108D7DF969A608714128E05*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		List_1_t8A1639802238DEF3222B6CBBC0DEF0B4B5F350EB* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t6F8827EED7DB0C845108D7DF969A608714128E05* WhereListIterator_1_Clone_mD2DED80C16F284377E259315D0189E5757299AD9_gshared (WhereListIterator_1_t1F690B0B32001794569AD59FAF2DA7A3BD84F4E5* __this, const RuntimeMethod* method) 
{
	{
		List_1_t8A1639802238DEF3222B6CBBC0DEF0B4B5F350EB* L_0 = __this->___source;
		Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* L_1 = __this->___predicate;
		WhereListIterator_1_t1F690B0B32001794569AD59FAF2DA7A3BD84F4E5* L_2 = (WhereListIterator_1_t1F690B0B32001794569AD59FAF2DA7A3BD84F4E5*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 3));
		WhereListIterator_1__ctor_m3333DE6CD3476F2462F6D1B996546C42075A6374(L_2, L_0, L_1, il2cpp_rgctx_method(method->klass->rgctx_data, 5));
		return (Iterator_1_t6F8827EED7DB0C845108D7DF969A608714128E05*)L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereListIterator_1_MoveNext_mF7EC719D5FEBDE1DF60A7ECF2FB5F1C7F0694398_gshared (WhereListIterator_1_t1F690B0B32001794569AD59FAF2DA7A3BD84F4E5* __this, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		int32_t L_0 = ((Iterator_1_t6F8827EED7DB0C845108D7DF969A608714128E05*)__this)->___state;
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_004e;
		}
	}
	{
		goto IL_0061;
	}

IL_0011:
	{
		List_1_t8A1639802238DEF3222B6CBBC0DEF0B4B5F350EB* L_3 = __this->___source;
		NullCheck(L_3);
		Enumerator_t81E3046D0BB629D86FAC325CBBF319731C3E36A4 L_4;
		L_4 = List_1_GetEnumerator_mF067420DAFF52D4C46250012FBE1232F35652C7B(L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 7));
		__this->___enumerator = L_4;
		Il2CppCodeGenWriteBarrier((void**)&(((&__this->___enumerator))->____list), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&__this->___enumerator))->____current))->___key), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&__this->___enumerator))->____current))->___value), (void*)NULL);
		#endif
		((Iterator_1_t6F8827EED7DB0C845108D7DF969A608714128E05*)__this)->___state = 2;
		goto IL_004e;
	}

IL_002b:
	{
		Enumerator_t81E3046D0BB629D86FAC325CBBF319731C3E36A4* L_5 = (Enumerator_t81E3046D0BB629D86FAC325CBBF319731C3E36A4*)(&__this->___enumerator);
		KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 L_6;
		L_6 = Enumerator_get_Current_m2E99DFD369025C91E4B23FA90EE17A41271106A4_inline(L_5, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		V_1 = L_6;
		Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* L_7 = __this->___predicate;
		KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 L_8 = V_1;
		NullCheck(L_7);
		bool L_9;
		L_9 = Func_2_Invoke_m18A3A6EDA433C635C66C43DA6B86F7BC746BFDD0_inline(L_7, L_8, il2cpp_rgctx_method(method->klass->rgctx_data, 12));
		if (!L_9)
		{
			goto IL_004e;
		}
	}
	{
		KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 L_10 = V_1;
		((Iterator_1_t6F8827EED7DB0C845108D7DF969A608714128E05*)__this)->___current = L_10;
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_t6F8827EED7DB0C845108D7DF969A608714128E05*)__this)->___current))->___key), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_t6F8827EED7DB0C845108D7DF969A608714128E05*)__this)->___current))->___value), (void*)NULL);
		#endif
		return (bool)1;
	}

IL_004e:
	{
		Enumerator_t81E3046D0BB629D86FAC325CBBF319731C3E36A4* L_11 = (Enumerator_t81E3046D0BB629D86FAC325CBBF319731C3E36A4*)(&__this->___enumerator);
		bool L_12;
		L_12 = Enumerator_MoveNext_m7303D41C6A0DB6D9A9B9F5923546BF98515E7B39(L_11, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		if (L_12)
		{
			goto IL_002b;
		}
	}
	{
		NullCheck((Iterator_1_t6F8827EED7DB0C845108D7DF969A608714128E05*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t6F8827EED7DB0C845108D7DF969A608714128E05*)__this);
	}

IL_0061:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereListIterator_1_Where_m12C16ACD65089A9D3F78BBECF8C7A385AAE6AEBF_gshared (WhereListIterator_1_t1F690B0B32001794569AD59FAF2DA7A3BD84F4E5* __this, Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* ___0_predicate, const RuntimeMethod* method) 
{
	{
		List_1_t8A1639802238DEF3222B6CBBC0DEF0B4B5F350EB* L_0 = __this->___source;
		Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* L_1 = __this->___predicate;
		Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* L_2 = ___0_predicate;
		Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* L_3;
		L_3 = Enumerable_CombinePredicates_TisKeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230_m9F329AA67F4C35877F54CE7441C4E759BCD33522(L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 15));
		WhereListIterator_1_t1F690B0B32001794569AD59FAF2DA7A3BD84F4E5* L_4 = (WhereListIterator_1_t1F690B0B32001794569AD59FAF2DA7A3BD84F4E5*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 3));
		WhereListIterator_1__ctor_m3333DE6CD3476F2462F6D1B996546C42075A6374(L_4, L_0, L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 5));
		return (RuntimeObject*)L_4;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereListIterator_1__ctor_m05CE151D6212647A87D227E25199E25869695A13_gshared (WhereListIterator_1_t519EB7A0906C9C15E2FCF014C1367A494D254C3E* __this, List_1_tDA4D291C60B1EFA9EA50BBA3367C657CC9410576* ___0_source, Func_2_t1C8F983F9A1AA802D45E89037E2AA7ACD1094821* ___1_predicate, const RuntimeMethod* method) 
{
	{
		Iterator_1__ctor_m9788F4EF50A0094F325E620BFC1D32ED3DAE63BB((Iterator_1_tEEF82AE11FFC6DF9B283B2D5E4A87B3E3BFD805E*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		List_1_tDA4D291C60B1EFA9EA50BBA3367C657CC9410576* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t1C8F983F9A1AA802D45E89037E2AA7ACD1094821* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_tEEF82AE11FFC6DF9B283B2D5E4A87B3E3BFD805E* WhereListIterator_1_Clone_m549C8EBF4C3C4ED38561C07B769B2587C35B6DF4_gshared (WhereListIterator_1_t519EB7A0906C9C15E2FCF014C1367A494D254C3E* __this, const RuntimeMethod* method) 
{
	{
		List_1_tDA4D291C60B1EFA9EA50BBA3367C657CC9410576* L_0 = __this->___source;
		Func_2_t1C8F983F9A1AA802D45E89037E2AA7ACD1094821* L_1 = __this->___predicate;
		WhereListIterator_1_t519EB7A0906C9C15E2FCF014C1367A494D254C3E* L_2 = (WhereListIterator_1_t519EB7A0906C9C15E2FCF014C1367A494D254C3E*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 3));
		WhereListIterator_1__ctor_m05CE151D6212647A87D227E25199E25869695A13(L_2, L_0, L_1, il2cpp_rgctx_method(method->klass->rgctx_data, 5));
		return (Iterator_1_tEEF82AE11FFC6DF9B283B2D5E4A87B3E3BFD805E*)L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereListIterator_1_MoveNext_m70FAD4AE08129883FE632BA9FFE3457117373D86_gshared (WhereListIterator_1_t519EB7A0906C9C15E2FCF014C1367A494D254C3E* __this, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		int32_t L_0 = ((Iterator_1_tEEF82AE11FFC6DF9B283B2D5E4A87B3E3BFD805E*)__this)->___state;
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_004e;
		}
	}
	{
		goto IL_0061;
	}

IL_0011:
	{
		List_1_tDA4D291C60B1EFA9EA50BBA3367C657CC9410576* L_3 = __this->___source;
		NullCheck(L_3);
		Enumerator_t6209EE23CCD16838DA331AC87789A15508C6C72B L_4;
		L_4 = List_1_GetEnumerator_m87BBBF3FBB0A4EBF1C2940AA91570D7F1565F60D(L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 7));
		__this->___enumerator = L_4;
		Il2CppCodeGenWriteBarrier((void**)&(((&__this->___enumerator))->____list), (void*)NULL);
		((Iterator_1_tEEF82AE11FFC6DF9B283B2D5E4A87B3E3BFD805E*)__this)->___state = 2;
		goto IL_004e;
	}

IL_002b:
	{
		Enumerator_t6209EE23CCD16838DA331AC87789A15508C6C72B* L_5 = (Enumerator_t6209EE23CCD16838DA331AC87789A15508C6C72B*)(&__this->___enumerator);
		int32_t L_6;
		L_6 = Enumerator_get_Current_mB6A201CD563FEF33A6BDA75B83C7BF2AA36CD98C_inline(L_5, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		V_1 = L_6;
		Func_2_t1C8F983F9A1AA802D45E89037E2AA7ACD1094821* L_7 = __this->___predicate;
		int32_t L_8 = V_1;
		NullCheck(L_7);
		bool L_9;
		L_9 = Func_2_Invoke_m095D2006A2DDB336987862DC15A7EFAED53E08EC_inline(L_7, L_8, il2cpp_rgctx_method(method->klass->rgctx_data, 12));
		if (!L_9)
		{
			goto IL_004e;
		}
	}
	{
		int32_t L_10 = V_1;
		((Iterator_1_tEEF82AE11FFC6DF9B283B2D5E4A87B3E3BFD805E*)__this)->___current = L_10;
		return (bool)1;
	}

IL_004e:
	{
		Enumerator_t6209EE23CCD16838DA331AC87789A15508C6C72B* L_11 = (Enumerator_t6209EE23CCD16838DA331AC87789A15508C6C72B*)(&__this->___enumerator);
		bool L_12;
		L_12 = Enumerator_MoveNext_mCAE99D26B8B4D7880B37A70AC8DFD8C7AA4FCCE5(L_11, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		if (L_12)
		{
			goto IL_002b;
		}
	}
	{
		NullCheck((Iterator_1_tEEF82AE11FFC6DF9B283B2D5E4A87B3E3BFD805E*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_tEEF82AE11FFC6DF9B283B2D5E4A87B3E3BFD805E*)__this);
	}

IL_0061:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereListIterator_1_Where_m57702A2F1FB9584F10CCD02ACBC7E2C0918CCB3E_gshared (WhereListIterator_1_t519EB7A0906C9C15E2FCF014C1367A494D254C3E* __this, Func_2_t1C8F983F9A1AA802D45E89037E2AA7ACD1094821* ___0_predicate, const RuntimeMethod* method) 
{
	{
		List_1_tDA4D291C60B1EFA9EA50BBA3367C657CC9410576* L_0 = __this->___source;
		Func_2_t1C8F983F9A1AA802D45E89037E2AA7ACD1094821* L_1 = __this->___predicate;
		Func_2_t1C8F983F9A1AA802D45E89037E2AA7ACD1094821* L_2 = ___0_predicate;
		Func_2_t1C8F983F9A1AA802D45E89037E2AA7ACD1094821* L_3;
		L_3 = Enumerable_CombinePredicates_TisInt32Enum_tCBAC8BA2BFF3A845FA599F303093BBBA374B6F0C_m88CBD9562882820B08530454AF5A344C7453C267(L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 15));
		WhereListIterator_1_t519EB7A0906C9C15E2FCF014C1367A494D254C3E* L_4 = (WhereListIterator_1_t519EB7A0906C9C15E2FCF014C1367A494D254C3E*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 3));
		WhereListIterator_1__ctor_m05CE151D6212647A87D227E25199E25869695A13(L_4, L_0, L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 5));
		return (RuntimeObject*)L_4;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereListIterator_1__ctor_mEF8F62B9078E538C1DC46BCB876C2AC5B29EA73B_gshared (WhereListIterator_1_t1F40F08BAF8586F2C09294085BC605CC2FA432EB* __this, List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* ___0_source, Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* ___1_predicate, const RuntimeMethod* method) 
{
	{
		Iterator_1__ctor_m3E47867714E05673E54C6B73D9242F5FFADA1F63((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA* WhereListIterator_1_Clone_mB7087945B135AFA9D70F30479082AD370DDDB66A_gshared (WhereListIterator_1_t1F40F08BAF8586F2C09294085BC605CC2FA432EB* __this, const RuntimeMethod* method) 
{
	{
		List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* L_0 = __this->___source;
		Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* L_1 = __this->___predicate;
		WhereListIterator_1_t1F40F08BAF8586F2C09294085BC605CC2FA432EB* L_2 = (WhereListIterator_1_t1F40F08BAF8586F2C09294085BC605CC2FA432EB*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 3));
		WhereListIterator_1__ctor_mEF8F62B9078E538C1DC46BCB876C2AC5B29EA73B(L_2, L_0, L_1, il2cpp_rgctx_method(method->klass->rgctx_data, 5));
		return (Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereListIterator_1_MoveNext_mEE70CAE79424880884D3CD6947167DEDB297FB47_gshared (WhereListIterator_1_t1F40F08BAF8586F2C09294085BC605CC2FA432EB* __this, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	RuntimeObject* V_1 = NULL;
	{
		int32_t L_0 = ((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this)->___state;
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_004e;
		}
	}
	{
		goto IL_0061;
	}

IL_0011:
	{
		List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* L_3 = __this->___source;
		NullCheck(L_3);
		Enumerator_t9473BAB568A27E2339D48C1F91319E0F6D244D7A L_4;
		L_4 = List_1_GetEnumerator_mD8294A7FA2BEB1929487127D476F8EC1CDC23BFC(L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 7));
		__this->___enumerator = L_4;
		Il2CppCodeGenWriteBarrier((void**)&(((&__this->___enumerator))->____list), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&(((&__this->___enumerator))->____current), (void*)NULL);
		#endif
		((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this)->___state = 2;
		goto IL_004e;
	}

IL_002b:
	{
		Enumerator_t9473BAB568A27E2339D48C1F91319E0F6D244D7A* L_5 = (Enumerator_t9473BAB568A27E2339D48C1F91319E0F6D244D7A*)(&__this->___enumerator);
		RuntimeObject* L_6;
		L_6 = Enumerator_get_Current_m6330F15D18EE4F547C05DF9BF83C5EB710376027_inline(L_5, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		V_1 = L_6;
		Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* L_7 = __this->___predicate;
		RuntimeObject* L_8 = V_1;
		NullCheck(L_7);
		bool L_9;
		L_9 = Func_2_Invoke_m2014423FB900F135C8FF994125604FF9E6AAE829_inline(L_7, L_8, il2cpp_rgctx_method(method->klass->rgctx_data, 12));
		if (!L_9)
		{
			goto IL_004e;
		}
	}
	{
		RuntimeObject* L_10 = V_1;
		((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this)->___current = L_10;
		Il2CppCodeGenWriteBarrier((void**)(&((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this)->___current), (void*)L_10);
		return (bool)1;
	}

IL_004e:
	{
		Enumerator_t9473BAB568A27E2339D48C1F91319E0F6D244D7A* L_11 = (Enumerator_t9473BAB568A27E2339D48C1F91319E0F6D244D7A*)(&__this->___enumerator);
		bool L_12;
		L_12 = Enumerator_MoveNext_mE921CC8F29FBBDE7CC3209A0ED0D921D58D00BCB(L_11, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		if (L_12)
		{
			goto IL_002b;
		}
	}
	{
		NullCheck((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this);
	}

IL_0061:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereListIterator_1_Where_mD1D1F307DE1E555A5F7237BCA2C32947BCF6A14D_gshared (WhereListIterator_1_t1F40F08BAF8586F2C09294085BC605CC2FA432EB* __this, Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* ___0_predicate, const RuntimeMethod* method) 
{
	{
		List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* L_0 = __this->___source;
		Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* L_1 = __this->___predicate;
		Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* L_2 = ___0_predicate;
		Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* L_3;
		L_3 = Enumerable_CombinePredicates_TisRuntimeObject_m613479C29B013E8FC2987E22F42A3BC6CC2C9768(L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 15));
		WhereListIterator_1_t1F40F08BAF8586F2C09294085BC605CC2FA432EB* L_4 = (WhereListIterator_1_t1F40F08BAF8586F2C09294085BC605CC2FA432EB*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 3));
		WhereListIterator_1__ctor_mEF8F62B9078E538C1DC46BCB876C2AC5B29EA73B(L_4, L_0, L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 5));
		return (RuntimeObject*)L_4;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereListIterator_1__ctor_mAE63FC161959863AE0A9DACA5FC683E2B8448600_gshared (WhereListIterator_1_t758114B160DB8D0A2FAD2AB6D95ABBFFA378664A* __this, List_1_tB751FDCEDAE7A97430AD924824F5D0193A720E52* ___0_source, Func_2_t92F44173C14E7022E392A8FEA4374C3CD24578EF* ___1_predicate, const RuntimeMethod* method) 
{
	{
		Iterator_1__ctor_mF6CD5E26F94CF7F842315D35A872B8C7298BD467((Iterator_1_t90E419394494C38051F176EB657B6E351726C1A5*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		List_1_tB751FDCEDAE7A97430AD924824F5D0193A720E52* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t92F44173C14E7022E392A8FEA4374C3CD24578EF* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t90E419394494C38051F176EB657B6E351726C1A5* WhereListIterator_1_Clone_m676F883A3C0A8B58A58A500C79D3A8AB872F332E_gshared (WhereListIterator_1_t758114B160DB8D0A2FAD2AB6D95ABBFFA378664A* __this, const RuntimeMethod* method) 
{
	{
		List_1_tB751FDCEDAE7A97430AD924824F5D0193A720E52* L_0 = __this->___source;
		Func_2_t92F44173C14E7022E392A8FEA4374C3CD24578EF* L_1 = __this->___predicate;
		WhereListIterator_1_t758114B160DB8D0A2FAD2AB6D95ABBFFA378664A* L_2 = (WhereListIterator_1_t758114B160DB8D0A2FAD2AB6D95ABBFFA378664A*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 3));
		WhereListIterator_1__ctor_mAE63FC161959863AE0A9DACA5FC683E2B8448600(L_2, L_0, L_1, il2cpp_rgctx_method(method->klass->rgctx_data, 5));
		return (Iterator_1_t90E419394494C38051F176EB657B6E351726C1A5*)L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereListIterator_1_MoveNext_m9A082C3EF2D14A32F8CC2A286F29785043DB4299_gshared (WhereListIterator_1_t758114B160DB8D0A2FAD2AB6D95ABBFFA378664A* __this, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	PlayerLoopSystem_t8AED6BF1C8A309CAA6FF71AC91DD33BDDFF7CF1F V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		int32_t L_0 = ((Iterator_1_t90E419394494C38051F176EB657B6E351726C1A5*)__this)->___state;
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_004e;
		}
	}
	{
		goto IL_0061;
	}

IL_0011:
	{
		List_1_tB751FDCEDAE7A97430AD924824F5D0193A720E52* L_3 = __this->___source;
		NullCheck(L_3);
		Enumerator_tB025B2FCAB9376692902C91754C98265C07AEA9A L_4;
		L_4 = List_1_GetEnumerator_mB7A6105C8257C829CB8FE710A42F5C97C70ED72E(L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 7));
		__this->___enumerator = L_4;
		Il2CppCodeGenWriteBarrier((void**)&(((&__this->___enumerator))->____list), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&__this->___enumerator))->____current))->___type), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&__this->___enumerator))->____current))->___subSystemList), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&__this->___enumerator))->____current))->___updateDelegate), (void*)NULL);
		#endif
		((Iterator_1_t90E419394494C38051F176EB657B6E351726C1A5*)__this)->___state = 2;
		goto IL_004e;
	}

IL_002b:
	{
		Enumerator_tB025B2FCAB9376692902C91754C98265C07AEA9A* L_5 = (Enumerator_tB025B2FCAB9376692902C91754C98265C07AEA9A*)(&__this->___enumerator);
		PlayerLoopSystem_t8AED6BF1C8A309CAA6FF71AC91DD33BDDFF7CF1F L_6;
		L_6 = Enumerator_get_Current_m0B4ED9AF252261F8FAEF61A9A59B085B4CE88528_inline(L_5, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		V_1 = L_6;
		Func_2_t92F44173C14E7022E392A8FEA4374C3CD24578EF* L_7 = __this->___predicate;
		PlayerLoopSystem_t8AED6BF1C8A309CAA6FF71AC91DD33BDDFF7CF1F L_8 = V_1;
		NullCheck(L_7);
		bool L_9;
		L_9 = Func_2_Invoke_m92C683F52E538828B33BA3E1E37C285A7A73A744_inline(L_7, L_8, il2cpp_rgctx_method(method->klass->rgctx_data, 12));
		if (!L_9)
		{
			goto IL_004e;
		}
	}
	{
		PlayerLoopSystem_t8AED6BF1C8A309CAA6FF71AC91DD33BDDFF7CF1F L_10 = V_1;
		((Iterator_1_t90E419394494C38051F176EB657B6E351726C1A5*)__this)->___current = L_10;
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_t90E419394494C38051F176EB657B6E351726C1A5*)__this)->___current))->___type), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_t90E419394494C38051F176EB657B6E351726C1A5*)__this)->___current))->___subSystemList), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_t90E419394494C38051F176EB657B6E351726C1A5*)__this)->___current))->___updateDelegate), (void*)NULL);
		#endif
		return (bool)1;
	}

IL_004e:
	{
		Enumerator_tB025B2FCAB9376692902C91754C98265C07AEA9A* L_11 = (Enumerator_tB025B2FCAB9376692902C91754C98265C07AEA9A*)(&__this->___enumerator);
		bool L_12;
		L_12 = Enumerator_MoveNext_m8323C42D98FCDA16F05D5351131455C3DD40C66B(L_11, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		if (L_12)
		{
			goto IL_002b;
		}
	}
	{
		NullCheck((Iterator_1_t90E419394494C38051F176EB657B6E351726C1A5*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t90E419394494C38051F176EB657B6E351726C1A5*)__this);
	}

IL_0061:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereListIterator_1_Where_m196ECB86EECD6F7A891CC9B0CB45E42883BC1FEB_gshared (WhereListIterator_1_t758114B160DB8D0A2FAD2AB6D95ABBFFA378664A* __this, Func_2_t92F44173C14E7022E392A8FEA4374C3CD24578EF* ___0_predicate, const RuntimeMethod* method) 
{
	{
		List_1_tB751FDCEDAE7A97430AD924824F5D0193A720E52* L_0 = __this->___source;
		Func_2_t92F44173C14E7022E392A8FEA4374C3CD24578EF* L_1 = __this->___predicate;
		Func_2_t92F44173C14E7022E392A8FEA4374C3CD24578EF* L_2 = ___0_predicate;
		Func_2_t92F44173C14E7022E392A8FEA4374C3CD24578EF* L_3;
		L_3 = Enumerable_CombinePredicates_TisPlayerLoopSystem_t8AED6BF1C8A309CAA6FF71AC91DD33BDDFF7CF1F_m5B25B3D43C643FAB7D206EA8F9F4AF8AD600629C(L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 15));
		WhereListIterator_1_t758114B160DB8D0A2FAD2AB6D95ABBFFA378664A* L_4 = (WhereListIterator_1_t758114B160DB8D0A2FAD2AB6D95ABBFFA378664A*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 3));
		WhereListIterator_1__ctor_mAE63FC161959863AE0A9DACA5FC683E2B8448600(L_4, L_0, L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 5));
		return (RuntimeObject*)L_4;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereListIterator_1__ctor_mC075454926AF320E4679335A1B81D3F56ACEFC0C_gshared (WhereListIterator_1_tD37742ECD2F53395BA8B668C2671C4C82E8E85F0* __this, List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* ___0_source, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* ___1_predicate, const RuntimeMethod* method) 
{
	{
		((  void (*) (Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 0)))((Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* L_0 = ___0_source;
		il2cpp_codegen_write_instance_field_data<List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A*>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),0), L_0);
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_1 = ___1_predicate;
		il2cpp_codegen_write_instance_field_data<Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B*>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),1), L_1);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0* WhereListIterator_1_Clone_mAA3ED56493E5FF2F49FE37EB7CDF6C0A957698B5_gshared (WhereListIterator_1_tD37742ECD2F53395BA8B668C2671C4C82E8E85F0* __this, const RuntimeMethod* method) 
{
	{
		List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* L_0 = *(List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),0));
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_1 = *(Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),1));
		WhereListIterator_1_tD37742ECD2F53395BA8B668C2671C4C82E8E85F0* L_2 = (WhereListIterator_1_tD37742ECD2F53395BA8B668C2671C4C82E8E85F0*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 3));
		((  void (*) (WhereListIterator_1_tD37742ECD2F53395BA8B668C2671C4C82E8E85F0*, List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A*, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 5)))(L_2, L_0, L_1, il2cpp_rgctx_method(method->klass->rgctx_data, 5));
		return (Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereListIterator_1_MoveNext_mB5E4EB089AD8CF7156B8972C7FB61739C466ED5E_gshared (WhereListIterator_1_tD37742ECD2F53395BA8B668C2671C4C82E8E85F0* __this, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_TSource_t85B7C93A555823AE666813BFFC5FEC432E108956 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 11));
	const uint32_t SizeOf_Enumerator_t8E62FE91E95BFC5D28A3B09EFA69C2A33120205E = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 8));
	const Il2CppFullySharedGenericAny L_5 = alloca(SizeOf_TSource_t85B7C93A555823AE666813BFFC5FEC432E108956);
	const Il2CppFullySharedGenericAny L_9 = L_5;
	const Il2CppFullySharedGenericAny L_7 = alloca(SizeOf_TSource_t85B7C93A555823AE666813BFFC5FEC432E108956);
	const Enumerator_tF5AC6CD19D283FBD724440520CEE68FE2602F7AF L_4 = alloca(SizeOf_Enumerator_t8E62FE91E95BFC5D28A3B09EFA69C2A33120205E);
	int32_t V_0 = 0;
	Il2CppFullySharedGenericAny V_1 = alloca(SizeOf_TSource_t85B7C93A555823AE666813BFFC5FEC432E108956);
	memset(V_1, 0, SizeOf_TSource_t85B7C93A555823AE666813BFFC5FEC432E108956);
	{
		int32_t L_0 = *(int32_t*)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 6),1));
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_004e;
		}
	}
	{
		goto IL_0061;
	}

IL_0011:
	{
		List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* L_3 = *(List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),0));
		NullCheck(L_3);
		InvokerActionInvoker1< Enumerator_tF5AC6CD19D283FBD724440520CEE68FE2602F7AF* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 7)), il2cpp_rgctx_method(method->klass->rgctx_data, 7), L_3, (Enumerator_tF5AC6CD19D283FBD724440520CEE68FE2602F7AF*)L_4);
		il2cpp_codegen_write_instance_field_data(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),2), L_4, SizeOf_Enumerator_t8E62FE91E95BFC5D28A3B09EFA69C2A33120205E);
		il2cpp_codegen_write_instance_field_data<int32_t>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 6),1), 2);
		goto IL_004e;
	}

IL_002b:
	{
		InvokerActionInvoker1< Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 9)), il2cpp_rgctx_method(method->klass->rgctx_data, 9), (((Enumerator_tF5AC6CD19D283FBD724440520CEE68FE2602F7AF*)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),2)))), (Il2CppFullySharedGenericAny*)L_5);
		il2cpp_codegen_memcpy(V_1, L_5, SizeOf_TSource_t85B7C93A555823AE666813BFFC5FEC432E108956);
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_6 = *(Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),1));
		il2cpp_codegen_memcpy(L_7, V_1, SizeOf_TSource_t85B7C93A555823AE666813BFFC5FEC432E108956);
		NullCheck(L_6);
		bool L_8;
		L_8 = InvokerFuncInvoker1< bool, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 12)), il2cpp_rgctx_method(method->klass->rgctx_data, 12), L_6, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 11)) ? L_7: *(void**)L_7));
		if (!L_8)
		{
			goto IL_004e;
		}
	}
	{
		il2cpp_codegen_memcpy(L_9, V_1, SizeOf_TSource_t85B7C93A555823AE666813BFFC5FEC432E108956);
		il2cpp_codegen_write_instance_field_data(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 6),2), L_9, SizeOf_TSource_t85B7C93A555823AE666813BFFC5FEC432E108956);
		return (bool)1;
	}

IL_004e:
	{
		bool L_10;
		L_10 = ((  bool (*) (Enumerator_tF5AC6CD19D283FBD724440520CEE68FE2602F7AF*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 13)))((((Enumerator_tF5AC6CD19D283FBD724440520CEE68FE2602F7AF*)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),2)))), il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		if (L_10)
		{
			goto IL_002b;
		}
	}
	{
		NullCheck((Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)__this);
	}

IL_0061:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereListIterator_1_Where_mC767815DE2249E70B38D6D172A0C61B028D7A44B_gshared (WhereListIterator_1_tD37742ECD2F53395BA8B668C2671C4C82E8E85F0* __this, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* ___0_predicate, const RuntimeMethod* method) 
{
	{
		List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* L_0 = *(List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),0));
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_1 = *(Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),1));
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_2 = ___0_predicate;
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_3;
		L_3 = ((  Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* (*) (Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B*, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 15)))(L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 15));
		WhereListIterator_1_tD37742ECD2F53395BA8B668C2671C4C82E8E85F0* L_4 = (WhereListIterator_1_tD37742ECD2F53395BA8B668C2671C4C82E8E85F0*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 3));
		((  void (*) (WhereListIterator_1_tD37742ECD2F53395BA8B668C2671C4C82E8E85F0*, List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A*, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 5)))(L_4, L_0, L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 5));
		return (RuntimeObject*)L_4;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectArrayIterator_2__ctor_m8296F02CCC8B11B40CCBF3ECD8EBC331A663143E_gshared (WhereSelectArrayIterator_2_tE62B26B94FCE5CA9F72DF29CD156E5D3147809AB* __this, KeyValuePair_2U5BU5D_t105762EC2DE353037ECAD13437FC19081314CE67* ___0_source, Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* ___1_predicate, Func_2_t696684549FAB37B32A9C38A40F33DB777B757E69* ___2_selector, const RuntimeMethod* method) 
{
	{
		Iterator_1__ctor_m933F57174CB01524F09C26B69041178FE65EE1E2((Iterator_1_t92BE161457BB4186D87644A87E4C1FAC67B8E430*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		KeyValuePair_2U5BU5D_t105762EC2DE353037ECAD13437FC19081314CE67* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_t696684549FAB37B32A9C38A40F33DB777B757E69* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t92BE161457BB4186D87644A87E4C1FAC67B8E430* WhereSelectArrayIterator_2_Clone_m0771119CF1533884D8DDA4A15EA4201681CF8543_gshared (WhereSelectArrayIterator_2_tE62B26B94FCE5CA9F72DF29CD156E5D3147809AB* __this, const RuntimeMethod* method) 
{
	{
		KeyValuePair_2U5BU5D_t105762EC2DE353037ECAD13437FC19081314CE67* L_0 = __this->___source;
		Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* L_1 = __this->___predicate;
		Func_2_t696684549FAB37B32A9C38A40F33DB777B757E69* L_2 = __this->___selector;
		WhereSelectArrayIterator_2_tE62B26B94FCE5CA9F72DF29CD156E5D3147809AB* L_3 = (WhereSelectArrayIterator_2_tE62B26B94FCE5CA9F72DF29CD156E5D3147809AB*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 3));
		WhereSelectArrayIterator_2__ctor_m8296F02CCC8B11B40CCBF3ECD8EBC331A663143E(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_t92BE161457BB4186D87644A87E4C1FAC67B8E430*)L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectArrayIterator_2_MoveNext_mEC7F81D1A8CF020B38374B3F69B1177A481880DB_gshared (WhereSelectArrayIterator_2_tE62B26B94FCE5CA9F72DF29CD156E5D3147809AB* __this, const RuntimeMethod* method) 
{
	KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ((Iterator_1_t92BE161457BB4186D87644A87E4C1FAC67B8E430*)__this)->___state;
		if ((!(((uint32_t)L_0) == ((uint32_t)1))))
		{
			goto IL_006b;
		}
	}
	{
		goto IL_0055;
	}

IL_000b:
	{
		KeyValuePair_2U5BU5D_t105762EC2DE353037ECAD13437FC19081314CE67* L_1 = __this->___source;
		int32_t L_2 = __this->___index;
		NullCheck(L_1);
		int32_t L_3 = L_2;
		KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 L_4 = (L_1)->GetAt(static_cast<il2cpp_array_size_t>(L_3));
		V_0 = L_4;
		int32_t L_5 = __this->___index;
		__this->___index = ((int32_t)il2cpp_codegen_add(L_5, 1));
		Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* L_6 = __this->___predicate;
		if (!L_6)
		{
			goto IL_0041;
		}
	}
	{
		Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* L_7 = __this->___predicate;
		KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 L_8 = V_0;
		NullCheck(L_7);
		bool L_9;
		L_9 = Func_2_Invoke_m18A3A6EDA433C635C66C43DA6B86F7BC746BFDD0_inline(L_7, L_8, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		if (!L_9)
		{
			goto IL_0055;
		}
	}

IL_0041:
	{
		Func_2_t696684549FAB37B32A9C38A40F33DB777B757E69* L_10 = __this->___selector;
		KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 L_11 = V_0;
		NullCheck(L_10);
		DictionaryEntry_t171080F37B311C25AA9E75888F9C9D703FA721BB L_12;
		L_12 = Func_2_Invoke_mFDA9BF3EFEFF70ED1767096A0993BCF4E97414BF_inline(L_10, L_11, il2cpp_rgctx_method(method->klass->rgctx_data, 10));
		((Iterator_1_t92BE161457BB4186D87644A87E4C1FAC67B8E430*)__this)->___current = L_12;
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_t92BE161457BB4186D87644A87E4C1FAC67B8E430*)__this)->___current))->____key), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_t92BE161457BB4186D87644A87E4C1FAC67B8E430*)__this)->___current))->____value), (void*)NULL);
		#endif
		return (bool)1;
	}

IL_0055:
	{
		int32_t L_13 = __this->___index;
		KeyValuePair_2U5BU5D_t105762EC2DE353037ECAD13437FC19081314CE67* L_14 = __this->___source;
		NullCheck(L_14);
		if ((((int32_t)L_13) < ((int32_t)((int32_t)(((RuntimeArray*)L_14)->max_length)))))
		{
			goto IL_000b;
		}
	}
	{
		NullCheck((Iterator_1_t92BE161457BB4186D87644A87E4C1FAC67B8E430*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t92BE161457BB4186D87644A87E4C1FAC67B8E430*)__this);
	}

IL_006b:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectArrayIterator_2_Where_m9C66E8CDAAACA3AAF5A4799DB920D458F7048741_gshared (WhereSelectArrayIterator_2_tE62B26B94FCE5CA9F72DF29CD156E5D3147809AB* __this, Func_2_tDBF8C754A8F1FC6DE54BB9904D2D81C266DFF6B4* ___0_predicate, const RuntimeMethod* method) 
{
	{
		Func_2_tDBF8C754A8F1FC6DE54BB9904D2D81C266DFF6B4* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t307785595D84CE47B35794516959DED6A6541913* L_1 = (WhereEnumerableIterator_1_t307785595D84CE47B35794516959DED6A6541913*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 14));
		WhereEnumerableIterator_1__ctor_m7A674E2DF8B9F1C27EDB614D6EF6BECFA0B57C1D(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 15));
		return (RuntimeObject*)L_1;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectArrayIterator_2__ctor_m244B6951BFA16F3362319E9F6233F0D2A1AEEF9B_gshared (WhereSelectArrayIterator_2_t9545399CAA4F1FAF69940E5FE8C16D33DDE69BEE* __this, KeyValuePair_2U5BU5D_t105762EC2DE353037ECAD13437FC19081314CE67* ___0_source, Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* ___1_predicate, Func_2_tA526681EE526C81F376160E44520BDC21770A705* ___2_selector, const RuntimeMethod* method) 
{
	{
		Iterator_1__ctor_m426D8BD95B00FDA5C5E8FAE956FCB74E54BC7CC7((Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		KeyValuePair_2U5BU5D_t105762EC2DE353037ECAD13437FC19081314CE67* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_tA526681EE526C81F376160E44520BDC21770A705* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07* WhereSelectArrayIterator_2_Clone_mC1389A3259AC15ECB5744D81919EFEDF77F53823_gshared (WhereSelectArrayIterator_2_t9545399CAA4F1FAF69940E5FE8C16D33DDE69BEE* __this, const RuntimeMethod* method) 
{
	{
		KeyValuePair_2U5BU5D_t105762EC2DE353037ECAD13437FC19081314CE67* L_0 = __this->___source;
		Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* L_1 = __this->___predicate;
		Func_2_tA526681EE526C81F376160E44520BDC21770A705* L_2 = __this->___selector;
		WhereSelectArrayIterator_2_t9545399CAA4F1FAF69940E5FE8C16D33DDE69BEE* L_3 = (WhereSelectArrayIterator_2_t9545399CAA4F1FAF69940E5FE8C16D33DDE69BEE*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 3));
		WhereSelectArrayIterator_2__ctor_m244B6951BFA16F3362319E9F6233F0D2A1AEEF9B(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectArrayIterator_2_MoveNext_m3D0185549C624A11812D4A2C6F1780E17E3164B2_gshared (WhereSelectArrayIterator_2_t9545399CAA4F1FAF69940E5FE8C16D33DDE69BEE* __this, const RuntimeMethod* method) 
{
	KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ((Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this)->___state;
		if ((!(((uint32_t)L_0) == ((uint32_t)1))))
		{
			goto IL_006b;
		}
	}
	{
		goto IL_0055;
	}

IL_000b:
	{
		KeyValuePair_2U5BU5D_t105762EC2DE353037ECAD13437FC19081314CE67* L_1 = __this->___source;
		int32_t L_2 = __this->___index;
		NullCheck(L_1);
		int32_t L_3 = L_2;
		KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 L_4 = (L_1)->GetAt(static_cast<il2cpp_array_size_t>(L_3));
		V_0 = L_4;
		int32_t L_5 = __this->___index;
		__this->___index = ((int32_t)il2cpp_codegen_add(L_5, 1));
		Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* L_6 = __this->___predicate;
		if (!L_6)
		{
			goto IL_0041;
		}
	}
	{
		Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* L_7 = __this->___predicate;
		KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 L_8 = V_0;
		NullCheck(L_7);
		bool L_9;
		L_9 = Func_2_Invoke_m18A3A6EDA433C635C66C43DA6B86F7BC746BFDD0_inline(L_7, L_8, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		if (!L_9)
		{
			goto IL_0055;
		}
	}

IL_0041:
	{
		Func_2_tA526681EE526C81F376160E44520BDC21770A705* L_10 = __this->___selector;
		KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 L_11 = V_0;
		NullCheck(L_10);
		int32_t L_12;
		L_12 = Func_2_Invoke_m450153F6300275E6112B4346D2EF20A15EB7091E_inline(L_10, L_11, il2cpp_rgctx_method(method->klass->rgctx_data, 10));
		((Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this)->___current = L_12;
		return (bool)1;
	}

IL_0055:
	{
		int32_t L_13 = __this->___index;
		KeyValuePair_2U5BU5D_t105762EC2DE353037ECAD13437FC19081314CE67* L_14 = __this->___source;
		NullCheck(L_14);
		if ((((int32_t)L_13) < ((int32_t)((int32_t)(((RuntimeArray*)L_14)->max_length)))))
		{
			goto IL_000b;
		}
	}
	{
		NullCheck((Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this);
	}

IL_006b:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectArrayIterator_2_Where_m0EAD36294E0091A2309C1177ACFF9D5D625DE4A0_gshared (WhereSelectArrayIterator_2_t9545399CAA4F1FAF69940E5FE8C16D33DDE69BEE* __this, Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA* ___0_predicate, const RuntimeMethod* method) 
{
	{
		Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t5DBA717695B8C7E60489C86AEB1FF673F50E293A* L_1 = (WhereEnumerableIterator_1_t5DBA717695B8C7E60489C86AEB1FF673F50E293A*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 14));
		WhereEnumerableIterator_1__ctor_mA7F4C6508A043D99B8288E43867D576F4697E4EE(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 15));
		return (RuntimeObject*)L_1;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectArrayIterator_2__ctor_m383D3735901E9831AC4849D5C0764824A3BAB2D9_gshared (WhereSelectArrayIterator_2_t9CC38AD9D47BA9244379A17890759D5740D5113C* __this, KeyValuePair_2U5BU5D_t105762EC2DE353037ECAD13437FC19081314CE67* ___0_source, Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* ___1_predicate, Func_2_tF42287527472FA89789873F068A87C60A00EC7D3* ___2_selector, const RuntimeMethod* method) 
{
	{
		Iterator_1__ctor_m3E47867714E05673E54C6B73D9242F5FFADA1F63((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		KeyValuePair_2U5BU5D_t105762EC2DE353037ECAD13437FC19081314CE67* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_tF42287527472FA89789873F068A87C60A00EC7D3* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA* WhereSelectArrayIterator_2_Clone_mBCC830BC9243678C5DA418E8DEB0E4F4FE2D2AFE_gshared (WhereSelectArrayIterator_2_t9CC38AD9D47BA9244379A17890759D5740D5113C* __this, const RuntimeMethod* method) 
{
	{
		KeyValuePair_2U5BU5D_t105762EC2DE353037ECAD13437FC19081314CE67* L_0 = __this->___source;
		Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* L_1 = __this->___predicate;
		Func_2_tF42287527472FA89789873F068A87C60A00EC7D3* L_2 = __this->___selector;
		WhereSelectArrayIterator_2_t9CC38AD9D47BA9244379A17890759D5740D5113C* L_3 = (WhereSelectArrayIterator_2_t9CC38AD9D47BA9244379A17890759D5740D5113C*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 3));
		WhereSelectArrayIterator_2__ctor_m383D3735901E9831AC4849D5C0764824A3BAB2D9(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectArrayIterator_2_MoveNext_mDA432054506D8E000369C19368D0C897C342FE74_gshared (WhereSelectArrayIterator_2_t9CC38AD9D47BA9244379A17890759D5740D5113C* __this, const RuntimeMethod* method) 
{
	KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this)->___state;
		if ((!(((uint32_t)L_0) == ((uint32_t)1))))
		{
			goto IL_006b;
		}
	}
	{
		goto IL_0055;
	}

IL_000b:
	{
		KeyValuePair_2U5BU5D_t105762EC2DE353037ECAD13437FC19081314CE67* L_1 = __this->___source;
		int32_t L_2 = __this->___index;
		NullCheck(L_1);
		int32_t L_3 = L_2;
		KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 L_4 = (L_1)->GetAt(static_cast<il2cpp_array_size_t>(L_3));
		V_0 = L_4;
		int32_t L_5 = __this->___index;
		__this->___index = ((int32_t)il2cpp_codegen_add(L_5, 1));
		Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* L_6 = __this->___predicate;
		if (!L_6)
		{
			goto IL_0041;
		}
	}
	{
		Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* L_7 = __this->___predicate;
		KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 L_8 = V_0;
		NullCheck(L_7);
		bool L_9;
		L_9 = Func_2_Invoke_m18A3A6EDA433C635C66C43DA6B86F7BC746BFDD0_inline(L_7, L_8, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		if (!L_9)
		{
			goto IL_0055;
		}
	}

IL_0041:
	{
		Func_2_tF42287527472FA89789873F068A87C60A00EC7D3* L_10 = __this->___selector;
		KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 L_11 = V_0;
		NullCheck(L_10);
		RuntimeObject* L_12;
		L_12 = Func_2_Invoke_m8EC2E5D1BEEA74F624F19C59924823693B9B39A5_inline(L_10, L_11, il2cpp_rgctx_method(method->klass->rgctx_data, 10));
		((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this)->___current = L_12;
		Il2CppCodeGenWriteBarrier((void**)(&((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this)->___current), (void*)L_12);
		return (bool)1;
	}

IL_0055:
	{
		int32_t L_13 = __this->___index;
		KeyValuePair_2U5BU5D_t105762EC2DE353037ECAD13437FC19081314CE67* L_14 = __this->___source;
		NullCheck(L_14);
		if ((((int32_t)L_13) < ((int32_t)((int32_t)(((RuntimeArray*)L_14)->max_length)))))
		{
			goto IL_000b;
		}
	}
	{
		NullCheck((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this);
	}

IL_006b:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectArrayIterator_2_Where_m4D0F69F6A98FC104510306F890015B213B148577_gshared (WhereSelectArrayIterator_2_t9CC38AD9D47BA9244379A17890759D5740D5113C* __this, Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* ___0_predicate, const RuntimeMethod* method) 
{
	{
		Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t1E787D13759F5A31C94B3FAED181402B25C278F4* L_1 = (WhereEnumerableIterator_1_t1E787D13759F5A31C94B3FAED181402B25C278F4*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 14));
		WhereEnumerableIterator_1__ctor_m8C0DA4CDA5431C03561F67C4393BB18CDD891F01(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 15));
		return (RuntimeObject*)L_1;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectArrayIterator_2__ctor_mA5AF3B283A737C737C53F5DB1B4DA4CA9B682003_gshared (WhereSelectArrayIterator_2_t250814D5FF34B1F8B88A5E8334436BB633B7B29F* __this, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___0_source, Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA* ___1_predicate, Func_2_t2FDA873D8482C79555CFB05233D610E8F1C7C354* ___2_selector, const RuntimeMethod* method) 
{
	{
		Iterator_1__ctor_m426D8BD95B00FDA5C5E8FAE956FCB74E54BC7CC7((Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_t2FDA873D8482C79555CFB05233D610E8F1C7C354* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07* WhereSelectArrayIterator_2_Clone_m8C792A51CA247F98A02981FF4012268F569521E3_gshared (WhereSelectArrayIterator_2_t250814D5FF34B1F8B88A5E8334436BB633B7B29F* __this, const RuntimeMethod* method) 
{
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_0 = __this->___source;
		Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA* L_1 = __this->___predicate;
		Func_2_t2FDA873D8482C79555CFB05233D610E8F1C7C354* L_2 = __this->___selector;
		WhereSelectArrayIterator_2_t250814D5FF34B1F8B88A5E8334436BB633B7B29F* L_3 = (WhereSelectArrayIterator_2_t250814D5FF34B1F8B88A5E8334436BB633B7B29F*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 3));
		WhereSelectArrayIterator_2__ctor_mA5AF3B283A737C737C53F5DB1B4DA4CA9B682003(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectArrayIterator_2_MoveNext_m5EC62B5404A4E884D74BA4308DBEC2E2A1ECCFDE_gshared (WhereSelectArrayIterator_2_t250814D5FF34B1F8B88A5E8334436BB633B7B29F* __this, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		int32_t L_0 = ((Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this)->___state;
		if ((!(((uint32_t)L_0) == ((uint32_t)1))))
		{
			goto IL_006b;
		}
	}
	{
		goto IL_0055;
	}

IL_000b:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_1 = __this->___source;
		int32_t L_2 = __this->___index;
		NullCheck(L_1);
		int32_t L_3 = L_2;
		int32_t L_4 = (L_1)->GetAt(static_cast<il2cpp_array_size_t>(L_3));
		V_0 = L_4;
		int32_t L_5 = __this->___index;
		__this->___index = ((int32_t)il2cpp_codegen_add(L_5, 1));
		Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA* L_6 = __this->___predicate;
		if (!L_6)
		{
			goto IL_0041;
		}
	}
	{
		Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA* L_7 = __this->___predicate;
		int32_t L_8 = V_0;
		NullCheck(L_7);
		bool L_9;
		L_9 = Func_2_Invoke_m1543D7041BADF87D1F63EBF838B0DDCB40340C7E_inline(L_7, L_8, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		if (!L_9)
		{
			goto IL_0055;
		}
	}

IL_0041:
	{
		Func_2_t2FDA873D8482C79555CFB05233D610E8F1C7C354* L_10 = __this->___selector;
		int32_t L_11 = V_0;
		NullCheck(L_10);
		int32_t L_12;
		L_12 = Func_2_Invoke_m1F8EE2DF137BE5132901C0297848BC7A373A676B_inline(L_10, L_11, il2cpp_rgctx_method(method->klass->rgctx_data, 10));
		((Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this)->___current = L_12;
		return (bool)1;
	}

IL_0055:
	{
		int32_t L_13 = __this->___index;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_14 = __this->___source;
		NullCheck(L_14);
		if ((((int32_t)L_13) < ((int32_t)((int32_t)(((RuntimeArray*)L_14)->max_length)))))
		{
			goto IL_000b;
		}
	}
	{
		NullCheck((Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this);
	}

IL_006b:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectArrayIterator_2_Where_mF0C74EFB57C1E84DDC5D33232715B110348B6A21_gshared (WhereSelectArrayIterator_2_t250814D5FF34B1F8B88A5E8334436BB633B7B29F* __this, Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA* ___0_predicate, const RuntimeMethod* method) 
{
	{
		Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t5DBA717695B8C7E60489C86AEB1FF673F50E293A* L_1 = (WhereEnumerableIterator_1_t5DBA717695B8C7E60489C86AEB1FF673F50E293A*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 14));
		WhereEnumerableIterator_1__ctor_mA7F4C6508A043D99B8288E43867D576F4697E4EE(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 15));
		return (RuntimeObject*)L_1;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectArrayIterator_2__ctor_m04357D1A96A8C4B96BD7145021AE39DD2C9F2A41_gshared (WhereSelectArrayIterator_2_t562C68C2C77B3AA5A84BBA4A0B21DB823E66B703* __this, ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* ___0_source, Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* ___1_predicate, Func_2_t9A0D493A82DCC47C9C819A3B045E02D9B5DDCE1B* ___2_selector, const RuntimeMethod* method) 
{
	{
		Iterator_1__ctor_m426D8BD95B00FDA5C5E8FAE956FCB74E54BC7CC7((Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_t9A0D493A82DCC47C9C819A3B045E02D9B5DDCE1B* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07* WhereSelectArrayIterator_2_Clone_m16E741269BE3A7B4433982BC91570D271F7E5596_gshared (WhereSelectArrayIterator_2_t562C68C2C77B3AA5A84BBA4A0B21DB823E66B703* __this, const RuntimeMethod* method) 
{
	{
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_0 = __this->___source;
		Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* L_1 = __this->___predicate;
		Func_2_t9A0D493A82DCC47C9C819A3B045E02D9B5DDCE1B* L_2 = __this->___selector;
		WhereSelectArrayIterator_2_t562C68C2C77B3AA5A84BBA4A0B21DB823E66B703* L_3 = (WhereSelectArrayIterator_2_t562C68C2C77B3AA5A84BBA4A0B21DB823E66B703*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 3));
		WhereSelectArrayIterator_2__ctor_m04357D1A96A8C4B96BD7145021AE39DD2C9F2A41(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectArrayIterator_2_MoveNext_mC860F5837EEE113DBAE2259DF696D9A8FA2F0DFA_gshared (WhereSelectArrayIterator_2_t562C68C2C77B3AA5A84BBA4A0B21DB823E66B703* __this, const RuntimeMethod* method) 
{
	RuntimeObject* V_0 = NULL;
	{
		int32_t L_0 = ((Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this)->___state;
		if ((!(((uint32_t)L_0) == ((uint32_t)1))))
		{
			goto IL_006b;
		}
	}
	{
		goto IL_0055;
	}

IL_000b:
	{
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_1 = __this->___source;
		int32_t L_2 = __this->___index;
		NullCheck(L_1);
		int32_t L_3 = L_2;
		RuntimeObject* L_4 = (L_1)->GetAt(static_cast<il2cpp_array_size_t>(L_3));
		V_0 = L_4;
		int32_t L_5 = __this->___index;
		__this->___index = ((int32_t)il2cpp_codegen_add(L_5, 1));
		Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* L_6 = __this->___predicate;
		if (!L_6)
		{
			goto IL_0041;
		}
	}
	{
		Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* L_7 = __this->___predicate;
		RuntimeObject* L_8 = V_0;
		NullCheck(L_7);
		bool L_9;
		L_9 = Func_2_Invoke_m2014423FB900F135C8FF994125604FF9E6AAE829_inline(L_7, L_8, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		if (!L_9)
		{
			goto IL_0055;
		}
	}

IL_0041:
	{
		Func_2_t9A0D493A82DCC47C9C819A3B045E02D9B5DDCE1B* L_10 = __this->___selector;
		RuntimeObject* L_11 = V_0;
		NullCheck(L_10);
		int32_t L_12;
		L_12 = Func_2_Invoke_m5216F6C7BCECCCED81384876C2968E0D4358618B_inline(L_10, L_11, il2cpp_rgctx_method(method->klass->rgctx_data, 10));
		((Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this)->___current = L_12;
		return (bool)1;
	}

IL_0055:
	{
		int32_t L_13 = __this->___index;
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_14 = __this->___source;
		NullCheck(L_14);
		if ((((int32_t)L_13) < ((int32_t)((int32_t)(((RuntimeArray*)L_14)->max_length)))))
		{
			goto IL_000b;
		}
	}
	{
		NullCheck((Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this);
	}

IL_006b:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectArrayIterator_2_Where_m024D09309EC9944FE71020A6CAC6F766910A7B5B_gshared (WhereSelectArrayIterator_2_t562C68C2C77B3AA5A84BBA4A0B21DB823E66B703* __this, Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA* ___0_predicate, const RuntimeMethod* method) 
{
	{
		Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t5DBA717695B8C7E60489C86AEB1FF673F50E293A* L_1 = (WhereEnumerableIterator_1_t5DBA717695B8C7E60489C86AEB1FF673F50E293A*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 14));
		WhereEnumerableIterator_1__ctor_mA7F4C6508A043D99B8288E43867D576F4697E4EE(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 15));
		return (RuntimeObject*)L_1;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectArrayIterator_2__ctor_m3660F197ECE4BF2A6F8BC99BC8BEF585C9D7BF97_gshared (WhereSelectArrayIterator_2_tC80EB6F425911E71B4D4712B7DA01244DF6E7C58* __this, ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* ___0_source, Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* ___1_predicate, Func_2_tACBF5A1656250800CE861707354491F0611F6624* ___2_selector, const RuntimeMethod* method) 
{
	{
		Iterator_1__ctor_m3E47867714E05673E54C6B73D9242F5FFADA1F63((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_tACBF5A1656250800CE861707354491F0611F6624* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA* WhereSelectArrayIterator_2_Clone_mDABFA8CCAFDC157CCF8428160F29DA90F22FCBD0_gshared (WhereSelectArrayIterator_2_tC80EB6F425911E71B4D4712B7DA01244DF6E7C58* __this, const RuntimeMethod* method) 
{
	{
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_0 = __this->___source;
		Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* L_1 = __this->___predicate;
		Func_2_tACBF5A1656250800CE861707354491F0611F6624* L_2 = __this->___selector;
		WhereSelectArrayIterator_2_tC80EB6F425911E71B4D4712B7DA01244DF6E7C58* L_3 = (WhereSelectArrayIterator_2_tC80EB6F425911E71B4D4712B7DA01244DF6E7C58*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 3));
		WhereSelectArrayIterator_2__ctor_m3660F197ECE4BF2A6F8BC99BC8BEF585C9D7BF97(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectArrayIterator_2_MoveNext_m4A8194EF96624D7C6656C87F6058990E389F6290_gshared (WhereSelectArrayIterator_2_tC80EB6F425911E71B4D4712B7DA01244DF6E7C58* __this, const RuntimeMethod* method) 
{
	RuntimeObject* V_0 = NULL;
	{
		int32_t L_0 = ((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this)->___state;
		if ((!(((uint32_t)L_0) == ((uint32_t)1))))
		{
			goto IL_006b;
		}
	}
	{
		goto IL_0055;
	}

IL_000b:
	{
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_1 = __this->___source;
		int32_t L_2 = __this->___index;
		NullCheck(L_1);
		int32_t L_3 = L_2;
		RuntimeObject* L_4 = (L_1)->GetAt(static_cast<il2cpp_array_size_t>(L_3));
		V_0 = L_4;
		int32_t L_5 = __this->___index;
		__this->___index = ((int32_t)il2cpp_codegen_add(L_5, 1));
		Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* L_6 = __this->___predicate;
		if (!L_6)
		{
			goto IL_0041;
		}
	}
	{
		Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* L_7 = __this->___predicate;
		RuntimeObject* L_8 = V_0;
		NullCheck(L_7);
		bool L_9;
		L_9 = Func_2_Invoke_m2014423FB900F135C8FF994125604FF9E6AAE829_inline(L_7, L_8, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		if (!L_9)
		{
			goto IL_0055;
		}
	}

IL_0041:
	{
		Func_2_tACBF5A1656250800CE861707354491F0611F6624* L_10 = __this->___selector;
		RuntimeObject* L_11 = V_0;
		NullCheck(L_10);
		RuntimeObject* L_12;
		L_12 = Func_2_Invoke_mDBA25DA5DA5B7E056FB9B026AF041F1385FB58A9_inline(L_10, L_11, il2cpp_rgctx_method(method->klass->rgctx_data, 10));
		((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this)->___current = L_12;
		Il2CppCodeGenWriteBarrier((void**)(&((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this)->___current), (void*)L_12);
		return (bool)1;
	}

IL_0055:
	{
		int32_t L_13 = __this->___index;
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_14 = __this->___source;
		NullCheck(L_14);
		if ((((int32_t)L_13) < ((int32_t)((int32_t)(((RuntimeArray*)L_14)->max_length)))))
		{
			goto IL_000b;
		}
	}
	{
		NullCheck((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this);
	}

IL_006b:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectArrayIterator_2_Where_m14341A500E696138BE1356922F31FA3E16E131D7_gshared (WhereSelectArrayIterator_2_tC80EB6F425911E71B4D4712B7DA01244DF6E7C58* __this, Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* ___0_predicate, const RuntimeMethod* method) 
{
	{
		Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t1E787D13759F5A31C94B3FAED181402B25C278F4* L_1 = (WhereEnumerableIterator_1_t1E787D13759F5A31C94B3FAED181402B25C278F4*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 14));
		WhereEnumerableIterator_1__ctor_m8C0DA4CDA5431C03561F67C4393BB18CDD891F01(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 15));
		return (RuntimeObject*)L_1;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectArrayIterator_2__ctor_mCFDF5484DEE46045B320C928B40C1DB170ED7221_gshared (WhereSelectArrayIterator_2_t0565EB3033FAD927C35E0B8525D2ABB0F1FECB40* __this, StyleSelectorPartU5BU5D_tBA574FB3E75E94E52874FDB7B05B9048E8A5421B* ___0_source, Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* ___1_predicate, Func_2_t12F902B64E731F36B1BC057F3AF13BF1D833E1DF* ___2_selector, const RuntimeMethod* method) 
{
	{
		Iterator_1__ctor_m426D8BD95B00FDA5C5E8FAE956FCB74E54BC7CC7((Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		StyleSelectorPartU5BU5D_tBA574FB3E75E94E52874FDB7B05B9048E8A5421B* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_t12F902B64E731F36B1BC057F3AF13BF1D833E1DF* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07* WhereSelectArrayIterator_2_Clone_mE692EDCE0B99BC732F4CACD51F11BE1EEE374A81_gshared (WhereSelectArrayIterator_2_t0565EB3033FAD927C35E0B8525D2ABB0F1FECB40* __this, const RuntimeMethod* method) 
{
	{
		StyleSelectorPartU5BU5D_tBA574FB3E75E94E52874FDB7B05B9048E8A5421B* L_0 = __this->___source;
		Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* L_1 = __this->___predicate;
		Func_2_t12F902B64E731F36B1BC057F3AF13BF1D833E1DF* L_2 = __this->___selector;
		WhereSelectArrayIterator_2_t0565EB3033FAD927C35E0B8525D2ABB0F1FECB40* L_3 = (WhereSelectArrayIterator_2_t0565EB3033FAD927C35E0B8525D2ABB0F1FECB40*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 3));
		WhereSelectArrayIterator_2__ctor_mCFDF5484DEE46045B320C928B40C1DB170ED7221(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectArrayIterator_2_MoveNext_mBD5F957C9042812D79CBE41A404B4B1877D9B57B_gshared (WhereSelectArrayIterator_2_t0565EB3033FAD927C35E0B8525D2ABB0F1FECB40* __this, const RuntimeMethod* method) 
{
	StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ((Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this)->___state;
		if ((!(((uint32_t)L_0) == ((uint32_t)1))))
		{
			goto IL_006b;
		}
	}
	{
		goto IL_0055;
	}

IL_000b:
	{
		StyleSelectorPartU5BU5D_tBA574FB3E75E94E52874FDB7B05B9048E8A5421B* L_1 = __this->___source;
		int32_t L_2 = __this->___index;
		NullCheck(L_1);
		int32_t L_3 = L_2;
		StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 L_4 = (L_1)->GetAt(static_cast<il2cpp_array_size_t>(L_3));
		V_0 = L_4;
		int32_t L_5 = __this->___index;
		__this->___index = ((int32_t)il2cpp_codegen_add(L_5, 1));
		Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* L_6 = __this->___predicate;
		if (!L_6)
		{
			goto IL_0041;
		}
	}
	{
		Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* L_7 = __this->___predicate;
		StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 L_8 = V_0;
		NullCheck(L_7);
		bool L_9;
		L_9 = Func_2_Invoke_m7C54973F594216484A4F81A59CDF821AF554339D_inline(L_7, L_8, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		if (!L_9)
		{
			goto IL_0055;
		}
	}

IL_0041:
	{
		Func_2_t12F902B64E731F36B1BC057F3AF13BF1D833E1DF* L_10 = __this->___selector;
		StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 L_11 = V_0;
		NullCheck(L_10);
		int32_t L_12;
		L_12 = Func_2_Invoke_m57961B138A397ADAB0DC71E56519ADBD63327D27_inline(L_10, L_11, il2cpp_rgctx_method(method->klass->rgctx_data, 10));
		((Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this)->___current = L_12;
		return (bool)1;
	}

IL_0055:
	{
		int32_t L_13 = __this->___index;
		StyleSelectorPartU5BU5D_tBA574FB3E75E94E52874FDB7B05B9048E8A5421B* L_14 = __this->___source;
		NullCheck(L_14);
		if ((((int32_t)L_13) < ((int32_t)((int32_t)(((RuntimeArray*)L_14)->max_length)))))
		{
			goto IL_000b;
		}
	}
	{
		NullCheck((Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this);
	}

IL_006b:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectArrayIterator_2_Where_m91E5F85357F179E8A1AD355DF734DE64669E6208_gshared (WhereSelectArrayIterator_2_t0565EB3033FAD927C35E0B8525D2ABB0F1FECB40* __this, Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA* ___0_predicate, const RuntimeMethod* method) 
{
	{
		Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t5DBA717695B8C7E60489C86AEB1FF673F50E293A* L_1 = (WhereEnumerableIterator_1_t5DBA717695B8C7E60489C86AEB1FF673F50E293A*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 14));
		WhereEnumerableIterator_1__ctor_mA7F4C6508A043D99B8288E43867D576F4697E4EE(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 15));
		return (RuntimeObject*)L_1;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectArrayIterator_2__ctor_mC246DFE6E89D80A80900F10D492E7093FF349C47_gshared (WhereSelectArrayIterator_2_tF795401649F680CCD3CB35E5CF5B073D7D6B03CB* __this, StyleSelectorPartU5BU5D_tBA574FB3E75E94E52874FDB7B05B9048E8A5421B* ___0_source, Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* ___1_predicate, Func_2_tFD36EA818BBCBD1EDE1E1540FC3EF156A6ADCCAD* ___2_selector, const RuntimeMethod* method) 
{
	{
		Iterator_1__ctor_m3E47867714E05673E54C6B73D9242F5FFADA1F63((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		StyleSelectorPartU5BU5D_tBA574FB3E75E94E52874FDB7B05B9048E8A5421B* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_tFD36EA818BBCBD1EDE1E1540FC3EF156A6ADCCAD* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA* WhereSelectArrayIterator_2_Clone_mC58B097CD37B6E685B1E0FCBEBA7A4090AC38B1C_gshared (WhereSelectArrayIterator_2_tF795401649F680CCD3CB35E5CF5B073D7D6B03CB* __this, const RuntimeMethod* method) 
{
	{
		StyleSelectorPartU5BU5D_tBA574FB3E75E94E52874FDB7B05B9048E8A5421B* L_0 = __this->___source;
		Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* L_1 = __this->___predicate;
		Func_2_tFD36EA818BBCBD1EDE1E1540FC3EF156A6ADCCAD* L_2 = __this->___selector;
		WhereSelectArrayIterator_2_tF795401649F680CCD3CB35E5CF5B073D7D6B03CB* L_3 = (WhereSelectArrayIterator_2_tF795401649F680CCD3CB35E5CF5B073D7D6B03CB*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 3));
		WhereSelectArrayIterator_2__ctor_mC246DFE6E89D80A80900F10D492E7093FF349C47(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectArrayIterator_2_MoveNext_m7DECB795E90F03B26EED3D176C5AE451F79FFB70_gshared (WhereSelectArrayIterator_2_tF795401649F680CCD3CB35E5CF5B073D7D6B03CB* __this, const RuntimeMethod* method) 
{
	StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this)->___state;
		if ((!(((uint32_t)L_0) == ((uint32_t)1))))
		{
			goto IL_006b;
		}
	}
	{
		goto IL_0055;
	}

IL_000b:
	{
		StyleSelectorPartU5BU5D_tBA574FB3E75E94E52874FDB7B05B9048E8A5421B* L_1 = __this->___source;
		int32_t L_2 = __this->___index;
		NullCheck(L_1);
		int32_t L_3 = L_2;
		StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 L_4 = (L_1)->GetAt(static_cast<il2cpp_array_size_t>(L_3));
		V_0 = L_4;
		int32_t L_5 = __this->___index;
		__this->___index = ((int32_t)il2cpp_codegen_add(L_5, 1));
		Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* L_6 = __this->___predicate;
		if (!L_6)
		{
			goto IL_0041;
		}
	}
	{
		Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* L_7 = __this->___predicate;
		StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 L_8 = V_0;
		NullCheck(L_7);
		bool L_9;
		L_9 = Func_2_Invoke_m7C54973F594216484A4F81A59CDF821AF554339D_inline(L_7, L_8, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		if (!L_9)
		{
			goto IL_0055;
		}
	}

IL_0041:
	{
		Func_2_tFD36EA818BBCBD1EDE1E1540FC3EF156A6ADCCAD* L_10 = __this->___selector;
		StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 L_11 = V_0;
		NullCheck(L_10);
		RuntimeObject* L_12;
		L_12 = Func_2_Invoke_m1F78C6C79382EA6E74D62E31DD00A9378266A518_inline(L_10, L_11, il2cpp_rgctx_method(method->klass->rgctx_data, 10));
		((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this)->___current = L_12;
		Il2CppCodeGenWriteBarrier((void**)(&((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this)->___current), (void*)L_12);
		return (bool)1;
	}

IL_0055:
	{
		int32_t L_13 = __this->___index;
		StyleSelectorPartU5BU5D_tBA574FB3E75E94E52874FDB7B05B9048E8A5421B* L_14 = __this->___source;
		NullCheck(L_14);
		if ((((int32_t)L_13) < ((int32_t)((int32_t)(((RuntimeArray*)L_14)->max_length)))))
		{
			goto IL_000b;
		}
	}
	{
		NullCheck((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this);
	}

IL_006b:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectArrayIterator_2_Where_mB937F9BD8E5AD7BE8381B407B28D772D3323B4B3_gshared (WhereSelectArrayIterator_2_tF795401649F680CCD3CB35E5CF5B073D7D6B03CB* __this, Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* ___0_predicate, const RuntimeMethod* method) 
{
	{
		Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t1E787D13759F5A31C94B3FAED181402B25C278F4* L_1 = (WhereEnumerableIterator_1_t1E787D13759F5A31C94B3FAED181402B25C278F4*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 14));
		WhereEnumerableIterator_1__ctor_m8C0DA4CDA5431C03561F67C4393BB18CDD891F01(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 15));
		return (RuntimeObject*)L_1;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectArrayIterator_2__ctor_mB15DB27A8DC3B4E00BCA6E8F63F00F7E374F76A4_gshared (WhereSelectArrayIterator_2_tBE026CE497BB8F36E31685722BBD7CB567570174* __this, __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* ___0_source, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* ___1_predicate, Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0* ___2_selector, const RuntimeMethod* method) 
{
	{
		((  void (*) (Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 0)))((Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_0 = ___0_source;
		il2cpp_codegen_write_instance_field_data<__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC*>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),0), L_0);
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_1 = ___1_predicate;
		il2cpp_codegen_write_instance_field_data<Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B*>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),1), L_1);
		Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0* L_2 = ___2_selector;
		il2cpp_codegen_write_instance_field_data<Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0*>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),2), L_2);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0* WhereSelectArrayIterator_2_Clone_mFBF81AE0E2B6F7A7A79FC98398E7A6AC0FD330E9_gshared (WhereSelectArrayIterator_2_tBE026CE497BB8F36E31685722BBD7CB567570174* __this, const RuntimeMethod* method) 
{
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_0 = *(__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),0));
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_1 = *(Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),1));
		Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0* L_2 = *(Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),2));
		WhereSelectArrayIterator_2_tBE026CE497BB8F36E31685722BBD7CB567570174* L_3 = (WhereSelectArrayIterator_2_tBE026CE497BB8F36E31685722BBD7CB567570174*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 3));
		((  void (*) (WhereSelectArrayIterator_2_tBE026CE497BB8F36E31685722BBD7CB567570174*, __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC*, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B*, Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 6)))(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectArrayIterator_2_MoveNext_mEF7E8E7B117D6D1147C53CAE838836974171392C_gshared (WhereSelectArrayIterator_2_tBE026CE497BB8F36E31685722BBD7CB567570174* __this, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_TSource_t21BF09076F270DC063711DE3ABB52B001A331F78 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 8));
	const uint32_t SizeOf_TResult_t278B55150BC17BB45D33B605F011F4D96EFE5425 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 11));
	const Il2CppFullySharedGenericAny L_4 = alloca(SizeOf_TSource_t21BF09076F270DC063711DE3ABB52B001A331F78);
	const Il2CppFullySharedGenericAny L_8 = L_4;
	const Il2CppFullySharedGenericAny L_11 = L_4;
	const Il2CppFullySharedGenericAny L_12 = alloca(SizeOf_TResult_t278B55150BC17BB45D33B605F011F4D96EFE5425);
	Il2CppFullySharedGenericAny V_0 = alloca(SizeOf_TSource_t21BF09076F270DC063711DE3ABB52B001A331F78);
	memset(V_0, 0, SizeOf_TSource_t21BF09076F270DC063711DE3ABB52B001A331F78);
	{
		int32_t L_0 = *(int32_t*)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 7),1));
		if ((!(((uint32_t)L_0) == ((uint32_t)1))))
		{
			goto IL_006b;
		}
	}
	{
		goto IL_0055;
	}

IL_000b:
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_1 = *(__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),0));
		int32_t L_2 = *(int32_t*)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),3));
		NullCheck(L_1);
		int32_t L_3 = L_2;
		il2cpp_codegen_memcpy(L_4, (L_1)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_3)), SizeOf_TSource_t21BF09076F270DC063711DE3ABB52B001A331F78);
		il2cpp_codegen_memcpy(V_0, L_4, SizeOf_TSource_t21BF09076F270DC063711DE3ABB52B001A331F78);
		int32_t L_5 = *(int32_t*)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),3));
		il2cpp_codegen_write_instance_field_data<int32_t>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),3), ((int32_t)il2cpp_codegen_add(L_5, 1)));
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_6 = *(Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),1));
		if (!L_6)
		{
			goto IL_0041;
		}
	}
	{
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_7 = *(Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),1));
		il2cpp_codegen_memcpy(L_8, V_0, SizeOf_TSource_t21BF09076F270DC063711DE3ABB52B001A331F78);
		NullCheck(L_7);
		bool L_9;
		L_9 = InvokerFuncInvoker1< bool, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 9)), il2cpp_rgctx_method(method->klass->rgctx_data, 9), L_7, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 8)) ? L_8: *(void**)L_8));
		if (!L_9)
		{
			goto IL_0055;
		}
	}

IL_0041:
	{
		Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0* L_10 = *(Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),2));
		il2cpp_codegen_memcpy(L_11, V_0, SizeOf_TSource_t21BF09076F270DC063711DE3ABB52B001A331F78);
		NullCheck(L_10);
		InvokerActionInvoker2< Il2CppFullySharedGenericAny, Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 10)), il2cpp_rgctx_method(method->klass->rgctx_data, 10), L_10, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 8)) ? L_11: *(void**)L_11), (Il2CppFullySharedGenericAny*)L_12);
		il2cpp_codegen_write_instance_field_data(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 7),2), L_12, SizeOf_TResult_t278B55150BC17BB45D33B605F011F4D96EFE5425);
		return (bool)1;
	}

IL_0055:
	{
		int32_t L_13 = *(int32_t*)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),3));
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_14 = *(__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),0));
		NullCheck(L_14);
		if ((((int32_t)L_13) < ((int32_t)((int32_t)(((RuntimeArray*)L_14)->max_length)))))
		{
			goto IL_000b;
		}
	}
	{
		NullCheck((Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)__this);
	}

IL_006b:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectArrayIterator_2_Where_mD81DB59B1D07BC8DDB099A652B22BA9C1538D7A3_gshared (WhereSelectArrayIterator_2_tBE026CE497BB8F36E31685722BBD7CB567570174* __this, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* ___0_predicate, const RuntimeMethod* method) 
{
	{
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t8B24528558F527941435C4FE1D046216FE4F277B* L_1 = (WhereEnumerableIterator_1_t8B24528558F527941435C4FE1D046216FE4F277B*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 14));
		((  void (*) (WhereEnumerableIterator_1_t8B24528558F527941435C4FE1D046216FE4F277B*, RuntimeObject*, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 15)))(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 15));
		return (RuntimeObject*)L_1;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2__ctor_m9B32DF6B14A2CE48A6D0BF78BF9994571F6FC06F_gshared (WhereSelectEnumerableIterator_2_tA07904A1CD5E908A2DC6C14712B4B966A86AE0A1* __this, RuntimeObject* ___0_source, Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* ___1_predicate, Func_2_t696684549FAB37B32A9C38A40F33DB777B757E69* ___2_selector, const RuntimeMethod* method) 
{
	{
		Iterator_1__ctor_m933F57174CB01524F09C26B69041178FE65EE1E2((Iterator_1_t92BE161457BB4186D87644A87E4C1FAC67B8E430*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		RuntimeObject* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_t696684549FAB37B32A9C38A40F33DB777B757E69* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t92BE161457BB4186D87644A87E4C1FAC67B8E430* WhereSelectEnumerableIterator_2_Clone_m91EDEDEDFD4E7B5C8B49341AB67677F3F2466EC4_gshared (WhereSelectEnumerableIterator_2_tA07904A1CD5E908A2DC6C14712B4B966A86AE0A1* __this, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = __this->___source;
		Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* L_1 = __this->___predicate;
		Func_2_t696684549FAB37B32A9C38A40F33DB777B757E69* L_2 = __this->___selector;
		WhereSelectEnumerableIterator_2_tA07904A1CD5E908A2DC6C14712B4B966A86AE0A1* L_3 = (WhereSelectEnumerableIterator_2_tA07904A1CD5E908A2DC6C14712B4B966A86AE0A1*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 3));
		WhereSelectEnumerableIterator_2__ctor_m9B32DF6B14A2CE48A6D0BF78BF9994571F6FC06F(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_t92BE161457BB4186D87644A87E4C1FAC67B8E430*)L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2_Dispose_m445960643CEF79380F14C613EA4CCC91BF1050AD_gshared (WhereSelectEnumerableIterator_2_tA07904A1CD5E908A2DC6C14712B4B966A86AE0A1* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		RuntimeObject* L_0 = __this->___enumerator;
		if (!L_0)
		{
			goto IL_0013;
		}
	}
	{
		RuntimeObject* L_1 = __this->___enumerator;
		NullCheck((RuntimeObject*)L_1);
		InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, (RuntimeObject*)L_1);
	}

IL_0013:
	{
		__this->___enumerator = (RuntimeObject*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___enumerator), (void*)(RuntimeObject*)NULL);
		NullCheck((Iterator_1_t92BE161457BB4186D87644A87E4C1FAC67B8E430*)__this);
		Iterator_1_Dispose_m0C3F89201F6D4DCC8782FC7192792E0F19D6A50D((Iterator_1_t92BE161457BB4186D87644A87E4C1FAC67B8E430*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectEnumerableIterator_2_MoveNext_m248E83E2F2CF19350B38BFB85A6F150779FD13BB_gshared (WhereSelectEnumerableIterator_2_tA07904A1CD5E908A2DC6C14712B4B966A86AE0A1* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		int32_t L_0 = ((Iterator_1_t92BE161457BB4186D87644A87E4C1FAC67B8E430*)__this)->___state;
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_0061;
		}
	}
	{
		goto IL_0074;
	}

IL_0011:
	{
		RuntimeObject* L_3 = __this->___source;
		NullCheck(L_3);
		RuntimeObject* L_4;
		L_4 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 2), L_3);
		__this->___enumerator = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___enumerator), (void*)L_4);
		((Iterator_1_t92BE161457BB4186D87644A87E4C1FAC67B8E430*)__this)->___state = 2;
		goto IL_0061;
	}

IL_002b:
	{
		RuntimeObject* L_5 = __this->___enumerator;
		NullCheck(L_5);
		KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 L_6;
		L_6 = InterfaceFuncInvoker0< KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 8), L_5);
		V_1 = L_6;
		Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* L_7 = __this->___predicate;
		if (!L_7)
		{
			goto IL_004d;
		}
	}
	{
		Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* L_8 = __this->___predicate;
		KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 L_9 = V_1;
		NullCheck(L_8);
		bool L_10;
		L_10 = Func_2_Invoke_m18A3A6EDA433C635C66C43DA6B86F7BC746BFDD0_inline(L_8, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		if (!L_10)
		{
			goto IL_0061;
		}
	}

IL_004d:
	{
		Func_2_t696684549FAB37B32A9C38A40F33DB777B757E69* L_11 = __this->___selector;
		KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 L_12 = V_1;
		NullCheck(L_11);
		DictionaryEntry_t171080F37B311C25AA9E75888F9C9D703FA721BB L_13;
		L_13 = Func_2_Invoke_mFDA9BF3EFEFF70ED1767096A0993BCF4E97414BF_inline(L_11, L_12, il2cpp_rgctx_method(method->klass->rgctx_data, 14));
		((Iterator_1_t92BE161457BB4186D87644A87E4C1FAC67B8E430*)__this)->___current = L_13;
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_t92BE161457BB4186D87644A87E4C1FAC67B8E430*)__this)->___current))->____key), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_t92BE161457BB4186D87644A87E4C1FAC67B8E430*)__this)->___current))->____value), (void*)NULL);
		#endif
		return (bool)1;
	}

IL_0061:
	{
		RuntimeObject* L_14 = __this->___enumerator;
		NullCheck((RuntimeObject*)L_14);
		bool L_15;
		L_15 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, (RuntimeObject*)L_14);
		if (L_15)
		{
			goto IL_002b;
		}
	}
	{
		NullCheck((Iterator_1_t92BE161457BB4186D87644A87E4C1FAC67B8E430*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t92BE161457BB4186D87644A87E4C1FAC67B8E430*)__this);
	}

IL_0074:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectEnumerableIterator_2_Where_m4A2D188CB1A10E8815B01BD21CE46957AC0215B5_gshared (WhereSelectEnumerableIterator_2_tA07904A1CD5E908A2DC6C14712B4B966A86AE0A1* __this, Func_2_tDBF8C754A8F1FC6DE54BB9904D2D81C266DFF6B4* ___0_predicate, const RuntimeMethod* method) 
{
	{
		Func_2_tDBF8C754A8F1FC6DE54BB9904D2D81C266DFF6B4* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t307785595D84CE47B35794516959DED6A6541913* L_1 = (WhereEnumerableIterator_1_t307785595D84CE47B35794516959DED6A6541913*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 17));
		WhereEnumerableIterator_1__ctor_m7A674E2DF8B9F1C27EDB614D6EF6BECFA0B57C1D(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 18));
		return (RuntimeObject*)L_1;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2__ctor_m3954E3860873975DFAC12A7151C42E9DD36D50B8_gshared (WhereSelectEnumerableIterator_2_t4B528FB254140E926E606C12F0FCC0B34224AD27* __this, RuntimeObject* ___0_source, Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* ___1_predicate, Func_2_tA526681EE526C81F376160E44520BDC21770A705* ___2_selector, const RuntimeMethod* method) 
{
	{
		Iterator_1__ctor_m426D8BD95B00FDA5C5E8FAE956FCB74E54BC7CC7((Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		RuntimeObject* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_tA526681EE526C81F376160E44520BDC21770A705* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07* WhereSelectEnumerableIterator_2_Clone_m0D0E2D97512A42802228BB03969A2C277F1ECAA9_gshared (WhereSelectEnumerableIterator_2_t4B528FB254140E926E606C12F0FCC0B34224AD27* __this, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = __this->___source;
		Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* L_1 = __this->___predicate;
		Func_2_tA526681EE526C81F376160E44520BDC21770A705* L_2 = __this->___selector;
		WhereSelectEnumerableIterator_2_t4B528FB254140E926E606C12F0FCC0B34224AD27* L_3 = (WhereSelectEnumerableIterator_2_t4B528FB254140E926E606C12F0FCC0B34224AD27*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 3));
		WhereSelectEnumerableIterator_2__ctor_m3954E3860873975DFAC12A7151C42E9DD36D50B8(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2_Dispose_m28D511FF661F767C9A4017F2619A9F840B90C1CD_gshared (WhereSelectEnumerableIterator_2_t4B528FB254140E926E606C12F0FCC0B34224AD27* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		RuntimeObject* L_0 = __this->___enumerator;
		if (!L_0)
		{
			goto IL_0013;
		}
	}
	{
		RuntimeObject* L_1 = __this->___enumerator;
		NullCheck((RuntimeObject*)L_1);
		InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, (RuntimeObject*)L_1);
	}

IL_0013:
	{
		__this->___enumerator = (RuntimeObject*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___enumerator), (void*)(RuntimeObject*)NULL);
		NullCheck((Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this);
		Iterator_1_Dispose_m93D0EFD9DDA495E64D508A05C5065C6AC5C4A3DB((Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectEnumerableIterator_2_MoveNext_m34726C6BCB34F72EF797B32B420AF0CD7A5DBDCE_gshared (WhereSelectEnumerableIterator_2_t4B528FB254140E926E606C12F0FCC0B34224AD27* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		int32_t L_0 = ((Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this)->___state;
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_0061;
		}
	}
	{
		goto IL_0074;
	}

IL_0011:
	{
		RuntimeObject* L_3 = __this->___source;
		NullCheck(L_3);
		RuntimeObject* L_4;
		L_4 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 2), L_3);
		__this->___enumerator = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___enumerator), (void*)L_4);
		((Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this)->___state = 2;
		goto IL_0061;
	}

IL_002b:
	{
		RuntimeObject* L_5 = __this->___enumerator;
		NullCheck(L_5);
		KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 L_6;
		L_6 = InterfaceFuncInvoker0< KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 8), L_5);
		V_1 = L_6;
		Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* L_7 = __this->___predicate;
		if (!L_7)
		{
			goto IL_004d;
		}
	}
	{
		Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* L_8 = __this->___predicate;
		KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 L_9 = V_1;
		NullCheck(L_8);
		bool L_10;
		L_10 = Func_2_Invoke_m18A3A6EDA433C635C66C43DA6B86F7BC746BFDD0_inline(L_8, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		if (!L_10)
		{
			goto IL_0061;
		}
	}

IL_004d:
	{
		Func_2_tA526681EE526C81F376160E44520BDC21770A705* L_11 = __this->___selector;
		KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 L_12 = V_1;
		NullCheck(L_11);
		int32_t L_13;
		L_13 = Func_2_Invoke_m450153F6300275E6112B4346D2EF20A15EB7091E_inline(L_11, L_12, il2cpp_rgctx_method(method->klass->rgctx_data, 14));
		((Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this)->___current = L_13;
		return (bool)1;
	}

IL_0061:
	{
		RuntimeObject* L_14 = __this->___enumerator;
		NullCheck((RuntimeObject*)L_14);
		bool L_15;
		L_15 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, (RuntimeObject*)L_14);
		if (L_15)
		{
			goto IL_002b;
		}
	}
	{
		NullCheck((Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this);
	}

IL_0074:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectEnumerableIterator_2_Where_m25AF10D891C6659208A0484EBAF3D8BD2E6BC984_gshared (WhereSelectEnumerableIterator_2_t4B528FB254140E926E606C12F0FCC0B34224AD27* __this, Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA* ___0_predicate, const RuntimeMethod* method) 
{
	{
		Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t5DBA717695B8C7E60489C86AEB1FF673F50E293A* L_1 = (WhereEnumerableIterator_1_t5DBA717695B8C7E60489C86AEB1FF673F50E293A*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 17));
		WhereEnumerableIterator_1__ctor_mA7F4C6508A043D99B8288E43867D576F4697E4EE(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 18));
		return (RuntimeObject*)L_1;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2__ctor_m446D9DFA8D6FD6C06663AC92CA2E2E70549BF6DC_gshared (WhereSelectEnumerableIterator_2_tB95A85F4BD200CD46FC8E0FF660D1BBC2AA388FF* __this, RuntimeObject* ___0_source, Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* ___1_predicate, Func_2_tF42287527472FA89789873F068A87C60A00EC7D3* ___2_selector, const RuntimeMethod* method) 
{
	{
		Iterator_1__ctor_m3E47867714E05673E54C6B73D9242F5FFADA1F63((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		RuntimeObject* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_tF42287527472FA89789873F068A87C60A00EC7D3* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA* WhereSelectEnumerableIterator_2_Clone_m38097E44A3899778665A2ED17EF993951AABACA6_gshared (WhereSelectEnumerableIterator_2_tB95A85F4BD200CD46FC8E0FF660D1BBC2AA388FF* __this, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = __this->___source;
		Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* L_1 = __this->___predicate;
		Func_2_tF42287527472FA89789873F068A87C60A00EC7D3* L_2 = __this->___selector;
		WhereSelectEnumerableIterator_2_tB95A85F4BD200CD46FC8E0FF660D1BBC2AA388FF* L_3 = (WhereSelectEnumerableIterator_2_tB95A85F4BD200CD46FC8E0FF660D1BBC2AA388FF*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 3));
		WhereSelectEnumerableIterator_2__ctor_m446D9DFA8D6FD6C06663AC92CA2E2E70549BF6DC(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2_Dispose_m2D6490DE58CC42B00A164EA99EE03CE9551051A3_gshared (WhereSelectEnumerableIterator_2_tB95A85F4BD200CD46FC8E0FF660D1BBC2AA388FF* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		RuntimeObject* L_0 = __this->___enumerator;
		if (!L_0)
		{
			goto IL_0013;
		}
	}
	{
		RuntimeObject* L_1 = __this->___enumerator;
		NullCheck((RuntimeObject*)L_1);
		InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, (RuntimeObject*)L_1);
	}

IL_0013:
	{
		__this->___enumerator = (RuntimeObject*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___enumerator), (void*)(RuntimeObject*)NULL);
		NullCheck((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this);
		Iterator_1_Dispose_m953BCF886C8A63456821023DBA45EBD9AC44EB07((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectEnumerableIterator_2_MoveNext_m4CCCD4BF2BF54F02643E872F3754E9DFCE7C7653_gshared (WhereSelectEnumerableIterator_2_tB95A85F4BD200CD46FC8E0FF660D1BBC2AA388FF* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		int32_t L_0 = ((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this)->___state;
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_0061;
		}
	}
	{
		goto IL_0074;
	}

IL_0011:
	{
		RuntimeObject* L_3 = __this->___source;
		NullCheck(L_3);
		RuntimeObject* L_4;
		L_4 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 2), L_3);
		__this->___enumerator = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___enumerator), (void*)L_4);
		((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this)->___state = 2;
		goto IL_0061;
	}

IL_002b:
	{
		RuntimeObject* L_5 = __this->___enumerator;
		NullCheck(L_5);
		KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 L_6;
		L_6 = InterfaceFuncInvoker0< KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 8), L_5);
		V_1 = L_6;
		Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* L_7 = __this->___predicate;
		if (!L_7)
		{
			goto IL_004d;
		}
	}
	{
		Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* L_8 = __this->___predicate;
		KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 L_9 = V_1;
		NullCheck(L_8);
		bool L_10;
		L_10 = Func_2_Invoke_m18A3A6EDA433C635C66C43DA6B86F7BC746BFDD0_inline(L_8, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		if (!L_10)
		{
			goto IL_0061;
		}
	}

IL_004d:
	{
		Func_2_tF42287527472FA89789873F068A87C60A00EC7D3* L_11 = __this->___selector;
		KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 L_12 = V_1;
		NullCheck(L_11);
		RuntimeObject* L_13;
		L_13 = Func_2_Invoke_m8EC2E5D1BEEA74F624F19C59924823693B9B39A5_inline(L_11, L_12, il2cpp_rgctx_method(method->klass->rgctx_data, 14));
		((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this)->___current = L_13;
		Il2CppCodeGenWriteBarrier((void**)(&((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this)->___current), (void*)L_13);
		return (bool)1;
	}

IL_0061:
	{
		RuntimeObject* L_14 = __this->___enumerator;
		NullCheck((RuntimeObject*)L_14);
		bool L_15;
		L_15 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, (RuntimeObject*)L_14);
		if (L_15)
		{
			goto IL_002b;
		}
	}
	{
		NullCheck((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this);
	}

IL_0074:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectEnumerableIterator_2_Where_m1B6D30667B96E95ACD733216CAE8B6EBF7C491AD_gshared (WhereSelectEnumerableIterator_2_tB95A85F4BD200CD46FC8E0FF660D1BBC2AA388FF* __this, Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* ___0_predicate, const RuntimeMethod* method) 
{
	{
		Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t1E787D13759F5A31C94B3FAED181402B25C278F4* L_1 = (WhereEnumerableIterator_1_t1E787D13759F5A31C94B3FAED181402B25C278F4*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 17));
		WhereEnumerableIterator_1__ctor_m8C0DA4CDA5431C03561F67C4393BB18CDD891F01(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 18));
		return (RuntimeObject*)L_1;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2__ctor_m96BAED87987DAE93B4E6887AE45943A3E21D4E13_gshared (WhereSelectEnumerableIterator_2_tB03350F7AB4B216F4FAF54A3032ACA3E746AF29D* __this, RuntimeObject* ___0_source, Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA* ___1_predicate, Func_2_t2FDA873D8482C79555CFB05233D610E8F1C7C354* ___2_selector, const RuntimeMethod* method) 
{
	{
		Iterator_1__ctor_m426D8BD95B00FDA5C5E8FAE956FCB74E54BC7CC7((Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		RuntimeObject* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_t2FDA873D8482C79555CFB05233D610E8F1C7C354* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07* WhereSelectEnumerableIterator_2_Clone_mC7E56BD61B2455925C350C460F2649317EA766E7_gshared (WhereSelectEnumerableIterator_2_tB03350F7AB4B216F4FAF54A3032ACA3E746AF29D* __this, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = __this->___source;
		Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA* L_1 = __this->___predicate;
		Func_2_t2FDA873D8482C79555CFB05233D610E8F1C7C354* L_2 = __this->___selector;
		WhereSelectEnumerableIterator_2_tB03350F7AB4B216F4FAF54A3032ACA3E746AF29D* L_3 = (WhereSelectEnumerableIterator_2_tB03350F7AB4B216F4FAF54A3032ACA3E746AF29D*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 3));
		WhereSelectEnumerableIterator_2__ctor_m96BAED87987DAE93B4E6887AE45943A3E21D4E13(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2_Dispose_m8E1E6EC7D7A52BC4CCF587115E0C3DEDB1D68D09_gshared (WhereSelectEnumerableIterator_2_tB03350F7AB4B216F4FAF54A3032ACA3E746AF29D* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		RuntimeObject* L_0 = __this->___enumerator;
		if (!L_0)
		{
			goto IL_0013;
		}
	}
	{
		RuntimeObject* L_1 = __this->___enumerator;
		NullCheck((RuntimeObject*)L_1);
		InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, (RuntimeObject*)L_1);
	}

IL_0013:
	{
		__this->___enumerator = (RuntimeObject*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___enumerator), (void*)(RuntimeObject*)NULL);
		NullCheck((Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this);
		Iterator_1_Dispose_m93D0EFD9DDA495E64D508A05C5065C6AC5C4A3DB((Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectEnumerableIterator_2_MoveNext_mAFA6BD49EF447B55B348AE2F161C05BFE92FC7F6_gshared (WhereSelectEnumerableIterator_2_tB03350F7AB4B216F4FAF54A3032ACA3E746AF29D* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		int32_t L_0 = ((Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this)->___state;
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_0061;
		}
	}
	{
		goto IL_0074;
	}

IL_0011:
	{
		RuntimeObject* L_3 = __this->___source;
		NullCheck(L_3);
		RuntimeObject* L_4;
		L_4 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 2), L_3);
		__this->___enumerator = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___enumerator), (void*)L_4);
		((Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this)->___state = 2;
		goto IL_0061;
	}

IL_002b:
	{
		RuntimeObject* L_5 = __this->___enumerator;
		NullCheck(L_5);
		int32_t L_6;
		L_6 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 8), L_5);
		V_1 = L_6;
		Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA* L_7 = __this->___predicate;
		if (!L_7)
		{
			goto IL_004d;
		}
	}
	{
		Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA* L_8 = __this->___predicate;
		int32_t L_9 = V_1;
		NullCheck(L_8);
		bool L_10;
		L_10 = Func_2_Invoke_m1543D7041BADF87D1F63EBF838B0DDCB40340C7E_inline(L_8, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		if (!L_10)
		{
			goto IL_0061;
		}
	}

IL_004d:
	{
		Func_2_t2FDA873D8482C79555CFB05233D610E8F1C7C354* L_11 = __this->___selector;
		int32_t L_12 = V_1;
		NullCheck(L_11);
		int32_t L_13;
		L_13 = Func_2_Invoke_m1F8EE2DF137BE5132901C0297848BC7A373A676B_inline(L_11, L_12, il2cpp_rgctx_method(method->klass->rgctx_data, 14));
		((Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this)->___current = L_13;
		return (bool)1;
	}

IL_0061:
	{
		RuntimeObject* L_14 = __this->___enumerator;
		NullCheck((RuntimeObject*)L_14);
		bool L_15;
		L_15 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, (RuntimeObject*)L_14);
		if (L_15)
		{
			goto IL_002b;
		}
	}
	{
		NullCheck((Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this);
	}

IL_0074:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectEnumerableIterator_2_Where_mCA64407851D78E9202A2FF794D8B0AFA724F8263_gshared (WhereSelectEnumerableIterator_2_tB03350F7AB4B216F4FAF54A3032ACA3E746AF29D* __this, Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA* ___0_predicate, const RuntimeMethod* method) 
{
	{
		Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t5DBA717695B8C7E60489C86AEB1FF673F50E293A* L_1 = (WhereEnumerableIterator_1_t5DBA717695B8C7E60489C86AEB1FF673F50E293A*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 17));
		WhereEnumerableIterator_1__ctor_mA7F4C6508A043D99B8288E43867D576F4697E4EE(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 18));
		return (RuntimeObject*)L_1;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2__ctor_m7BBD99849FABDA48F6D93BCE742C5B8398B5409F_gshared (WhereSelectEnumerableIterator_2_t7BA7CE7768E39319636272B29292281AB152E7D6* __this, RuntimeObject* ___0_source, Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* ___1_predicate, Func_2_t9A0D493A82DCC47C9C819A3B045E02D9B5DDCE1B* ___2_selector, const RuntimeMethod* method) 
{
	{
		Iterator_1__ctor_m426D8BD95B00FDA5C5E8FAE956FCB74E54BC7CC7((Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		RuntimeObject* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_t9A0D493A82DCC47C9C819A3B045E02D9B5DDCE1B* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07* WhereSelectEnumerableIterator_2_Clone_m4B36594513DB9C2DBA924AAF739AC72A69AB27D8_gshared (WhereSelectEnumerableIterator_2_t7BA7CE7768E39319636272B29292281AB152E7D6* __this, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = __this->___source;
		Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* L_1 = __this->___predicate;
		Func_2_t9A0D493A82DCC47C9C819A3B045E02D9B5DDCE1B* L_2 = __this->___selector;
		WhereSelectEnumerableIterator_2_t7BA7CE7768E39319636272B29292281AB152E7D6* L_3 = (WhereSelectEnumerableIterator_2_t7BA7CE7768E39319636272B29292281AB152E7D6*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 3));
		WhereSelectEnumerableIterator_2__ctor_m7BBD99849FABDA48F6D93BCE742C5B8398B5409F(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2_Dispose_mC12A42F6C76D71F9AFF6E1DEAE90F894570F25B9_gshared (WhereSelectEnumerableIterator_2_t7BA7CE7768E39319636272B29292281AB152E7D6* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		RuntimeObject* L_0 = __this->___enumerator;
		if (!L_0)
		{
			goto IL_0013;
		}
	}
	{
		RuntimeObject* L_1 = __this->___enumerator;
		NullCheck((RuntimeObject*)L_1);
		InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, (RuntimeObject*)L_1);
	}

IL_0013:
	{
		__this->___enumerator = (RuntimeObject*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___enumerator), (void*)(RuntimeObject*)NULL);
		NullCheck((Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this);
		Iterator_1_Dispose_m93D0EFD9DDA495E64D508A05C5065C6AC5C4A3DB((Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectEnumerableIterator_2_MoveNext_mC431839D47615578A26F4BA58347C3DDD142D7DA_gshared (WhereSelectEnumerableIterator_2_t7BA7CE7768E39319636272B29292281AB152E7D6* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	RuntimeObject* V_1 = NULL;
	{
		int32_t L_0 = ((Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this)->___state;
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_0061;
		}
	}
	{
		goto IL_0074;
	}

IL_0011:
	{
		RuntimeObject* L_3 = __this->___source;
		NullCheck(L_3);
		RuntimeObject* L_4;
		L_4 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 2), L_3);
		__this->___enumerator = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___enumerator), (void*)L_4);
		((Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this)->___state = 2;
		goto IL_0061;
	}

IL_002b:
	{
		RuntimeObject* L_5 = __this->___enumerator;
		NullCheck(L_5);
		RuntimeObject* L_6;
		L_6 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 8), L_5);
		V_1 = L_6;
		Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* L_7 = __this->___predicate;
		if (!L_7)
		{
			goto IL_004d;
		}
	}
	{
		Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* L_8 = __this->___predicate;
		RuntimeObject* L_9 = V_1;
		NullCheck(L_8);
		bool L_10;
		L_10 = Func_2_Invoke_m2014423FB900F135C8FF994125604FF9E6AAE829_inline(L_8, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		if (!L_10)
		{
			goto IL_0061;
		}
	}

IL_004d:
	{
		Func_2_t9A0D493A82DCC47C9C819A3B045E02D9B5DDCE1B* L_11 = __this->___selector;
		RuntimeObject* L_12 = V_1;
		NullCheck(L_11);
		int32_t L_13;
		L_13 = Func_2_Invoke_m5216F6C7BCECCCED81384876C2968E0D4358618B_inline(L_11, L_12, il2cpp_rgctx_method(method->klass->rgctx_data, 14));
		((Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this)->___current = L_13;
		return (bool)1;
	}

IL_0061:
	{
		RuntimeObject* L_14 = __this->___enumerator;
		NullCheck((RuntimeObject*)L_14);
		bool L_15;
		L_15 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, (RuntimeObject*)L_14);
		if (L_15)
		{
			goto IL_002b;
		}
	}
	{
		NullCheck((Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this);
	}

IL_0074:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectEnumerableIterator_2_Where_m2B6930F0E1F6019D3862F399109622D7D0877D6F_gshared (WhereSelectEnumerableIterator_2_t7BA7CE7768E39319636272B29292281AB152E7D6* __this, Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA* ___0_predicate, const RuntimeMethod* method) 
{
	{
		Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t5DBA717695B8C7E60489C86AEB1FF673F50E293A* L_1 = (WhereEnumerableIterator_1_t5DBA717695B8C7E60489C86AEB1FF673F50E293A*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 17));
		WhereEnumerableIterator_1__ctor_mA7F4C6508A043D99B8288E43867D576F4697E4EE(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 18));
		return (RuntimeObject*)L_1;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2__ctor_m2E08505C4CB96CC2AD340B4A2B0D3BF0D6DA01F9_gshared (WhereSelectEnumerableIterator_2_t585674E4C2106F965D6B51B3B1068924FC97CE0F* __this, RuntimeObject* ___0_source, Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* ___1_predicate, Func_2_tACBF5A1656250800CE861707354491F0611F6624* ___2_selector, const RuntimeMethod* method) 
{
	{
		Iterator_1__ctor_m3E47867714E05673E54C6B73D9242F5FFADA1F63((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		RuntimeObject* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_tACBF5A1656250800CE861707354491F0611F6624* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA* WhereSelectEnumerableIterator_2_Clone_m2ED927CF2549A759AE2454F97E33F05FA19B552E_gshared (WhereSelectEnumerableIterator_2_t585674E4C2106F965D6B51B3B1068924FC97CE0F* __this, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = __this->___source;
		Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* L_1 = __this->___predicate;
		Func_2_tACBF5A1656250800CE861707354491F0611F6624* L_2 = __this->___selector;
		WhereSelectEnumerableIterator_2_t585674E4C2106F965D6B51B3B1068924FC97CE0F* L_3 = (WhereSelectEnumerableIterator_2_t585674E4C2106F965D6B51B3B1068924FC97CE0F*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 3));
		WhereSelectEnumerableIterator_2__ctor_m2E08505C4CB96CC2AD340B4A2B0D3BF0D6DA01F9(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2_Dispose_mD2A476DDFBA6E23D20625E4C1C35AC98DE5F19F2_gshared (WhereSelectEnumerableIterator_2_t585674E4C2106F965D6B51B3B1068924FC97CE0F* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		RuntimeObject* L_0 = __this->___enumerator;
		if (!L_0)
		{
			goto IL_0013;
		}
	}
	{
		RuntimeObject* L_1 = __this->___enumerator;
		NullCheck((RuntimeObject*)L_1);
		InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, (RuntimeObject*)L_1);
	}

IL_0013:
	{
		__this->___enumerator = (RuntimeObject*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___enumerator), (void*)(RuntimeObject*)NULL);
		NullCheck((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this);
		Iterator_1_Dispose_m953BCF886C8A63456821023DBA45EBD9AC44EB07((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectEnumerableIterator_2_MoveNext_mC68F6626ADFD57493351521CE15400BBD158BC68_gshared (WhereSelectEnumerableIterator_2_t585674E4C2106F965D6B51B3B1068924FC97CE0F* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	RuntimeObject* V_1 = NULL;
	{
		int32_t L_0 = ((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this)->___state;
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_0061;
		}
	}
	{
		goto IL_0074;
	}

IL_0011:
	{
		RuntimeObject* L_3 = __this->___source;
		NullCheck(L_3);
		RuntimeObject* L_4;
		L_4 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 2), L_3);
		__this->___enumerator = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___enumerator), (void*)L_4);
		((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this)->___state = 2;
		goto IL_0061;
	}

IL_002b:
	{
		RuntimeObject* L_5 = __this->___enumerator;
		NullCheck(L_5);
		RuntimeObject* L_6;
		L_6 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 8), L_5);
		V_1 = L_6;
		Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* L_7 = __this->___predicate;
		if (!L_7)
		{
			goto IL_004d;
		}
	}
	{
		Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* L_8 = __this->___predicate;
		RuntimeObject* L_9 = V_1;
		NullCheck(L_8);
		bool L_10;
		L_10 = Func_2_Invoke_m2014423FB900F135C8FF994125604FF9E6AAE829_inline(L_8, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		if (!L_10)
		{
			goto IL_0061;
		}
	}

IL_004d:
	{
		Func_2_tACBF5A1656250800CE861707354491F0611F6624* L_11 = __this->___selector;
		RuntimeObject* L_12 = V_1;
		NullCheck(L_11);
		RuntimeObject* L_13;
		L_13 = Func_2_Invoke_mDBA25DA5DA5B7E056FB9B026AF041F1385FB58A9_inline(L_11, L_12, il2cpp_rgctx_method(method->klass->rgctx_data, 14));
		((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this)->___current = L_13;
		Il2CppCodeGenWriteBarrier((void**)(&((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this)->___current), (void*)L_13);
		return (bool)1;
	}

IL_0061:
	{
		RuntimeObject* L_14 = __this->___enumerator;
		NullCheck((RuntimeObject*)L_14);
		bool L_15;
		L_15 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, (RuntimeObject*)L_14);
		if (L_15)
		{
			goto IL_002b;
		}
	}
	{
		NullCheck((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this);
	}

IL_0074:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectEnumerableIterator_2_Where_mA93AACD32DB1D01903967A4CD1F5D74E84AA5F96_gshared (WhereSelectEnumerableIterator_2_t585674E4C2106F965D6B51B3B1068924FC97CE0F* __this, Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* ___0_predicate, const RuntimeMethod* method) 
{
	{
		Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t1E787D13759F5A31C94B3FAED181402B25C278F4* L_1 = (WhereEnumerableIterator_1_t1E787D13759F5A31C94B3FAED181402B25C278F4*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 17));
		WhereEnumerableIterator_1__ctor_m8C0DA4CDA5431C03561F67C4393BB18CDD891F01(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 18));
		return (RuntimeObject*)L_1;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2__ctor_m646AB1CCB6D9D0F7262BFB41A4D35C6C14C6A4D2_gshared (WhereSelectEnumerableIterator_2_tDD70C727530B3DBADEB387A0E353F5F829380BF9* __this, RuntimeObject* ___0_source, Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* ___1_predicate, Func_2_t12F902B64E731F36B1BC057F3AF13BF1D833E1DF* ___2_selector, const RuntimeMethod* method) 
{
	{
		Iterator_1__ctor_m426D8BD95B00FDA5C5E8FAE956FCB74E54BC7CC7((Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		RuntimeObject* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_t12F902B64E731F36B1BC057F3AF13BF1D833E1DF* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07* WhereSelectEnumerableIterator_2_Clone_mD30F529FA8B647CBBA40A65D23303FEF34EE1894_gshared (WhereSelectEnumerableIterator_2_tDD70C727530B3DBADEB387A0E353F5F829380BF9* __this, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = __this->___source;
		Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* L_1 = __this->___predicate;
		Func_2_t12F902B64E731F36B1BC057F3AF13BF1D833E1DF* L_2 = __this->___selector;
		WhereSelectEnumerableIterator_2_tDD70C727530B3DBADEB387A0E353F5F829380BF9* L_3 = (WhereSelectEnumerableIterator_2_tDD70C727530B3DBADEB387A0E353F5F829380BF9*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 3));
		WhereSelectEnumerableIterator_2__ctor_m646AB1CCB6D9D0F7262BFB41A4D35C6C14C6A4D2(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2_Dispose_m1B072DB2262D5BCCC2AC1631021D83B762BB9FEB_gshared (WhereSelectEnumerableIterator_2_tDD70C727530B3DBADEB387A0E353F5F829380BF9* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		RuntimeObject* L_0 = __this->___enumerator;
		if (!L_0)
		{
			goto IL_0013;
		}
	}
	{
		RuntimeObject* L_1 = __this->___enumerator;
		NullCheck((RuntimeObject*)L_1);
		InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, (RuntimeObject*)L_1);
	}

IL_0013:
	{
		__this->___enumerator = (RuntimeObject*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___enumerator), (void*)(RuntimeObject*)NULL);
		NullCheck((Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this);
		Iterator_1_Dispose_m93D0EFD9DDA495E64D508A05C5065C6AC5C4A3DB((Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectEnumerableIterator_2_MoveNext_m0A34BD808DE51E67A332F51F39948D36D06D9CC5_gshared (WhereSelectEnumerableIterator_2_tDD70C727530B3DBADEB387A0E353F5F829380BF9* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		int32_t L_0 = ((Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this)->___state;
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_0061;
		}
	}
	{
		goto IL_0074;
	}

IL_0011:
	{
		RuntimeObject* L_3 = __this->___source;
		NullCheck(L_3);
		RuntimeObject* L_4;
		L_4 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 2), L_3);
		__this->___enumerator = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___enumerator), (void*)L_4);
		((Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this)->___state = 2;
		goto IL_0061;
	}

IL_002b:
	{
		RuntimeObject* L_5 = __this->___enumerator;
		NullCheck(L_5);
		StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 L_6;
		L_6 = InterfaceFuncInvoker0< StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 8), L_5);
		V_1 = L_6;
		Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* L_7 = __this->___predicate;
		if (!L_7)
		{
			goto IL_004d;
		}
	}
	{
		Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* L_8 = __this->___predicate;
		StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 L_9 = V_1;
		NullCheck(L_8);
		bool L_10;
		L_10 = Func_2_Invoke_m7C54973F594216484A4F81A59CDF821AF554339D_inline(L_8, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		if (!L_10)
		{
			goto IL_0061;
		}
	}

IL_004d:
	{
		Func_2_t12F902B64E731F36B1BC057F3AF13BF1D833E1DF* L_11 = __this->___selector;
		StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 L_12 = V_1;
		NullCheck(L_11);
		int32_t L_13;
		L_13 = Func_2_Invoke_m57961B138A397ADAB0DC71E56519ADBD63327D27_inline(L_11, L_12, il2cpp_rgctx_method(method->klass->rgctx_data, 14));
		((Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this)->___current = L_13;
		return (bool)1;
	}

IL_0061:
	{
		RuntimeObject* L_14 = __this->___enumerator;
		NullCheck((RuntimeObject*)L_14);
		bool L_15;
		L_15 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, (RuntimeObject*)L_14);
		if (L_15)
		{
			goto IL_002b;
		}
	}
	{
		NullCheck((Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this);
	}

IL_0074:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectEnumerableIterator_2_Where_mC57788BE1F1B0BD7D1D2FCAF01EC182D83C0906E_gshared (WhereSelectEnumerableIterator_2_tDD70C727530B3DBADEB387A0E353F5F829380BF9* __this, Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA* ___0_predicate, const RuntimeMethod* method) 
{
	{
		Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t5DBA717695B8C7E60489C86AEB1FF673F50E293A* L_1 = (WhereEnumerableIterator_1_t5DBA717695B8C7E60489C86AEB1FF673F50E293A*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 17));
		WhereEnumerableIterator_1__ctor_mA7F4C6508A043D99B8288E43867D576F4697E4EE(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 18));
		return (RuntimeObject*)L_1;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2__ctor_m67E0676B846F7D5D13322DFE2366E000F49CCE01_gshared (WhereSelectEnumerableIterator_2_tE9E39B5B3920248DC542D84A8CFB82C524F6E586* __this, RuntimeObject* ___0_source, Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* ___1_predicate, Func_2_tFD36EA818BBCBD1EDE1E1540FC3EF156A6ADCCAD* ___2_selector, const RuntimeMethod* method) 
{
	{
		Iterator_1__ctor_m3E47867714E05673E54C6B73D9242F5FFADA1F63((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		RuntimeObject* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_tFD36EA818BBCBD1EDE1E1540FC3EF156A6ADCCAD* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA* WhereSelectEnumerableIterator_2_Clone_m79D0125A1A65347F4522C73EA7D684850A856150_gshared (WhereSelectEnumerableIterator_2_tE9E39B5B3920248DC542D84A8CFB82C524F6E586* __this, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = __this->___source;
		Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* L_1 = __this->___predicate;
		Func_2_tFD36EA818BBCBD1EDE1E1540FC3EF156A6ADCCAD* L_2 = __this->___selector;
		WhereSelectEnumerableIterator_2_tE9E39B5B3920248DC542D84A8CFB82C524F6E586* L_3 = (WhereSelectEnumerableIterator_2_tE9E39B5B3920248DC542D84A8CFB82C524F6E586*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 3));
		WhereSelectEnumerableIterator_2__ctor_m67E0676B846F7D5D13322DFE2366E000F49CCE01(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2_Dispose_m4059A77B770FEFC2E069A60DF9EE649B4D3C4DE5_gshared (WhereSelectEnumerableIterator_2_tE9E39B5B3920248DC542D84A8CFB82C524F6E586* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		RuntimeObject* L_0 = __this->___enumerator;
		if (!L_0)
		{
			goto IL_0013;
		}
	}
	{
		RuntimeObject* L_1 = __this->___enumerator;
		NullCheck((RuntimeObject*)L_1);
		InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, (RuntimeObject*)L_1);
	}

IL_0013:
	{
		__this->___enumerator = (RuntimeObject*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___enumerator), (void*)(RuntimeObject*)NULL);
		NullCheck((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this);
		Iterator_1_Dispose_m953BCF886C8A63456821023DBA45EBD9AC44EB07((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectEnumerableIterator_2_MoveNext_mF9058AE915E95BB4D1B6852E177B962E5C72041C_gshared (WhereSelectEnumerableIterator_2_tE9E39B5B3920248DC542D84A8CFB82C524F6E586* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		int32_t L_0 = ((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this)->___state;
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_0061;
		}
	}
	{
		goto IL_0074;
	}

IL_0011:
	{
		RuntimeObject* L_3 = __this->___source;
		NullCheck(L_3);
		RuntimeObject* L_4;
		L_4 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 2), L_3);
		__this->___enumerator = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___enumerator), (void*)L_4);
		((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this)->___state = 2;
		goto IL_0061;
	}

IL_002b:
	{
		RuntimeObject* L_5 = __this->___enumerator;
		NullCheck(L_5);
		StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 L_6;
		L_6 = InterfaceFuncInvoker0< StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 8), L_5);
		V_1 = L_6;
		Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* L_7 = __this->___predicate;
		if (!L_7)
		{
			goto IL_004d;
		}
	}
	{
		Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* L_8 = __this->___predicate;
		StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 L_9 = V_1;
		NullCheck(L_8);
		bool L_10;
		L_10 = Func_2_Invoke_m7C54973F594216484A4F81A59CDF821AF554339D_inline(L_8, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		if (!L_10)
		{
			goto IL_0061;
		}
	}

IL_004d:
	{
		Func_2_tFD36EA818BBCBD1EDE1E1540FC3EF156A6ADCCAD* L_11 = __this->___selector;
		StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 L_12 = V_1;
		NullCheck(L_11);
		RuntimeObject* L_13;
		L_13 = Func_2_Invoke_m1F78C6C79382EA6E74D62E31DD00A9378266A518_inline(L_11, L_12, il2cpp_rgctx_method(method->klass->rgctx_data, 14));
		((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this)->___current = L_13;
		Il2CppCodeGenWriteBarrier((void**)(&((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this)->___current), (void*)L_13);
		return (bool)1;
	}

IL_0061:
	{
		RuntimeObject* L_14 = __this->___enumerator;
		NullCheck((RuntimeObject*)L_14);
		bool L_15;
		L_15 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, (RuntimeObject*)L_14);
		if (L_15)
		{
			goto IL_002b;
		}
	}
	{
		NullCheck((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this);
	}

IL_0074:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectEnumerableIterator_2_Where_m7F40A08064DE17F179D3D40D6F7D38500D7167FE_gshared (WhereSelectEnumerableIterator_2_tE9E39B5B3920248DC542D84A8CFB82C524F6E586* __this, Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* ___0_predicate, const RuntimeMethod* method) 
{
	{
		Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t1E787D13759F5A31C94B3FAED181402B25C278F4* L_1 = (WhereEnumerableIterator_1_t1E787D13759F5A31C94B3FAED181402B25C278F4*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 17));
		WhereEnumerableIterator_1__ctor_m8C0DA4CDA5431C03561F67C4393BB18CDD891F01(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 18));
		return (RuntimeObject*)L_1;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2__ctor_m9A4AF54DC527FA1CEF8B803C8DDA5E632838B06F_gshared (WhereSelectEnumerableIterator_2_t1FBA58379B31F544881FB4C45B2D102F32A71E1C* __this, RuntimeObject* ___0_source, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* ___1_predicate, Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0* ___2_selector, const RuntimeMethod* method) 
{
	{
		((  void (*) (Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 0)))((Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		RuntimeObject* L_0 = ___0_source;
		il2cpp_codegen_write_instance_field_data<RuntimeObject*>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),0), L_0);
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_1 = ___1_predicate;
		il2cpp_codegen_write_instance_field_data<Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B*>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),1), L_1);
		Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0* L_2 = ___2_selector;
		il2cpp_codegen_write_instance_field_data<Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0*>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),2), L_2);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0* WhereSelectEnumerableIterator_2_Clone_mD773B8B24D1459B11BA4462A6DD68865514ADC9E_gshared (WhereSelectEnumerableIterator_2_t1FBA58379B31F544881FB4C45B2D102F32A71E1C* __this, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = *(RuntimeObject**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),0));
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_1 = *(Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),1));
		Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0* L_2 = *(Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),2));
		WhereSelectEnumerableIterator_2_t1FBA58379B31F544881FB4C45B2D102F32A71E1C* L_3 = (WhereSelectEnumerableIterator_2_t1FBA58379B31F544881FB4C45B2D102F32A71E1C*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 3));
		((  void (*) (WhereSelectEnumerableIterator_2_t1FBA58379B31F544881FB4C45B2D102F32A71E1C*, RuntimeObject*, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B*, Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 6)))(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2_Dispose_m640FAC111BC786414B40480BB03E4F84B2FFB179_gshared (WhereSelectEnumerableIterator_2_t1FBA58379B31F544881FB4C45B2D102F32A71E1C* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		RuntimeObject* L_0 = *(RuntimeObject**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),3));
		if (!L_0)
		{
			goto IL_0013;
		}
	}
	{
		RuntimeObject* L_1 = *(RuntimeObject**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),3));
		NullCheck((RuntimeObject*)L_1);
		InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, (RuntimeObject*)L_1);
	}

IL_0013:
	{
		il2cpp_codegen_write_instance_field_data<RuntimeObject*>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),3), (RuntimeObject*)NULL);
		NullCheck((Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)__this);
		((  void (*) (Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 9)))((Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 9));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectEnumerableIterator_2_MoveNext_mB384EFAF6366166F28EDFDBA272EEC1089E1A115_gshared (WhereSelectEnumerableIterator_2_t1FBA58379B31F544881FB4C45B2D102F32A71E1C* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	const uint32_t SizeOf_TSource_t5B0D27614F68D07DB050466831DEDC1DDEFFC093 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 12));
	const uint32_t SizeOf_TResult_t33CDF94D13BEBA6908E84F958D63A95F7466E520 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 15));
	const Il2CppFullySharedGenericAny L_6 = alloca(SizeOf_TSource_t5B0D27614F68D07DB050466831DEDC1DDEFFC093);
	const Il2CppFullySharedGenericAny L_9 = L_6;
	const Il2CppFullySharedGenericAny L_12 = L_6;
	const Il2CppFullySharedGenericAny L_13 = alloca(SizeOf_TResult_t33CDF94D13BEBA6908E84F958D63A95F7466E520);
	int32_t V_0 = 0;
	Il2CppFullySharedGenericAny V_1 = alloca(SizeOf_TSource_t5B0D27614F68D07DB050466831DEDC1DDEFFC093);
	memset(V_1, 0, SizeOf_TSource_t5B0D27614F68D07DB050466831DEDC1DDEFFC093);
	{
		int32_t L_0 = *(int32_t*)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 7),1));
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_0061;
		}
	}
	{
		goto IL_0074;
	}

IL_0011:
	{
		RuntimeObject* L_3 = *(RuntimeObject**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),0));
		NullCheck(L_3);
		RuntimeObject* L_4;
		L_4 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 2), L_3);
		il2cpp_codegen_write_instance_field_data<RuntimeObject*>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),3), L_4);
		il2cpp_codegen_write_instance_field_data<int32_t>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 7),1), 2);
		goto IL_0061;
	}

IL_002b:
	{
		RuntimeObject* L_5 = *(RuntimeObject**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),3));
		NullCheck(L_5);
		InterfaceActionInvoker1Invoker< Il2CppFullySharedGenericAny* >::Invoke(0, il2cpp_rgctx_data(method->klass->rgctx_data, 8), L_5, (Il2CppFullySharedGenericAny*)L_6);
		il2cpp_codegen_memcpy(V_1, L_6, SizeOf_TSource_t5B0D27614F68D07DB050466831DEDC1DDEFFC093);
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_7 = *(Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),1));
		if (!L_7)
		{
			goto IL_004d;
		}
	}
	{
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_8 = *(Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),1));
		il2cpp_codegen_memcpy(L_9, V_1, SizeOf_TSource_t5B0D27614F68D07DB050466831DEDC1DDEFFC093);
		NullCheck(L_8);
		bool L_10;
		L_10 = InvokerFuncInvoker1< bool, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 13)), il2cpp_rgctx_method(method->klass->rgctx_data, 13), L_8, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 12)) ? L_9: *(void**)L_9));
		if (!L_10)
		{
			goto IL_0061;
		}
	}

IL_004d:
	{
		Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0* L_11 = *(Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),2));
		il2cpp_codegen_memcpy(L_12, V_1, SizeOf_TSource_t5B0D27614F68D07DB050466831DEDC1DDEFFC093);
		NullCheck(L_11);
		InvokerActionInvoker2< Il2CppFullySharedGenericAny, Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 14)), il2cpp_rgctx_method(method->klass->rgctx_data, 14), L_11, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 12)) ? L_12: *(void**)L_12), (Il2CppFullySharedGenericAny*)L_13);
		il2cpp_codegen_write_instance_field_data(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 7),2), L_13, SizeOf_TResult_t33CDF94D13BEBA6908E84F958D63A95F7466E520);
		return (bool)1;
	}

IL_0061:
	{
		RuntimeObject* L_14 = *(RuntimeObject**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),3));
		NullCheck((RuntimeObject*)L_14);
		bool L_15;
		L_15 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, (RuntimeObject*)L_14);
		if (L_15)
		{
			goto IL_002b;
		}
	}
	{
		NullCheck((Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)__this);
	}

IL_0074:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectEnumerableIterator_2_Where_mB8ACBBFA48460E67B18647EF16E6EE4D0BE08679_gshared (WhereSelectEnumerableIterator_2_t1FBA58379B31F544881FB4C45B2D102F32A71E1C* __this, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* ___0_predicate, const RuntimeMethod* method) 
{
	{
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t8B24528558F527941435C4FE1D046216FE4F277B* L_1 = (WhereEnumerableIterator_1_t8B24528558F527941435C4FE1D046216FE4F277B*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 17));
		((  void (*) (WhereEnumerableIterator_1_t8B24528558F527941435C4FE1D046216FE4F277B*, RuntimeObject*, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 18)))(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 18));
		return (RuntimeObject*)L_1;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectListIterator_2__ctor_m6988AD11F7C5AE41145E6B5A44BEFCB016099702_gshared (WhereSelectListIterator_2_t67AC19AA42DBCC5EC6C01ACD9BEE8A2D23A2EEE1* __this, List_1_t8A1639802238DEF3222B6CBBC0DEF0B4B5F350EB* ___0_source, Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* ___1_predicate, Func_2_t696684549FAB37B32A9C38A40F33DB777B757E69* ___2_selector, const RuntimeMethod* method) 
{
	{
		Iterator_1__ctor_m933F57174CB01524F09C26B69041178FE65EE1E2((Iterator_1_t92BE161457BB4186D87644A87E4C1FAC67B8E430*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		List_1_t8A1639802238DEF3222B6CBBC0DEF0B4B5F350EB* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_t696684549FAB37B32A9C38A40F33DB777B757E69* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t92BE161457BB4186D87644A87E4C1FAC67B8E430* WhereSelectListIterator_2_Clone_m62BAAD0DC7C1D733349F55F9743F8492D7756E25_gshared (WhereSelectListIterator_2_t67AC19AA42DBCC5EC6C01ACD9BEE8A2D23A2EEE1* __this, const RuntimeMethod* method) 
{
	{
		List_1_t8A1639802238DEF3222B6CBBC0DEF0B4B5F350EB* L_0 = __this->___source;
		Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* L_1 = __this->___predicate;
		Func_2_t696684549FAB37B32A9C38A40F33DB777B757E69* L_2 = __this->___selector;
		WhereSelectListIterator_2_t67AC19AA42DBCC5EC6C01ACD9BEE8A2D23A2EEE1* L_3 = (WhereSelectListIterator_2_t67AC19AA42DBCC5EC6C01ACD9BEE8A2D23A2EEE1*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 3));
		WhereSelectListIterator_2__ctor_m6988AD11F7C5AE41145E6B5A44BEFCB016099702(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_t92BE161457BB4186D87644A87E4C1FAC67B8E430*)L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectListIterator_2_MoveNext_m9F03FFE214D498C4D186DC0102D687761178EFF2_gshared (WhereSelectListIterator_2_t67AC19AA42DBCC5EC6C01ACD9BEE8A2D23A2EEE1* __this, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		int32_t L_0 = ((Iterator_1_t92BE161457BB4186D87644A87E4C1FAC67B8E430*)__this)->___state;
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_0061;
		}
	}
	{
		goto IL_0074;
	}

IL_0011:
	{
		List_1_t8A1639802238DEF3222B6CBBC0DEF0B4B5F350EB* L_3 = __this->___source;
		NullCheck(L_3);
		Enumerator_t81E3046D0BB629D86FAC325CBBF319731C3E36A4 L_4;
		L_4 = List_1_GetEnumerator_mF067420DAFF52D4C46250012FBE1232F35652C7B(L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 8));
		__this->___enumerator = L_4;
		Il2CppCodeGenWriteBarrier((void**)&(((&__this->___enumerator))->____list), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&__this->___enumerator))->____current))->___key), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&__this->___enumerator))->____current))->___value), (void*)NULL);
		#endif
		((Iterator_1_t92BE161457BB4186D87644A87E4C1FAC67B8E430*)__this)->___state = 2;
		goto IL_0061;
	}

IL_002b:
	{
		Enumerator_t81E3046D0BB629D86FAC325CBBF319731C3E36A4* L_5 = (Enumerator_t81E3046D0BB629D86FAC325CBBF319731C3E36A4*)(&__this->___enumerator);
		KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 L_6;
		L_6 = Enumerator_get_Current_m2E99DFD369025C91E4B23FA90EE17A41271106A4_inline(L_5, il2cpp_rgctx_method(method->klass->rgctx_data, 10));
		V_1 = L_6;
		Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* L_7 = __this->___predicate;
		if (!L_7)
		{
			goto IL_004d;
		}
	}
	{
		Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* L_8 = __this->___predicate;
		KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 L_9 = V_1;
		NullCheck(L_8);
		bool L_10;
		L_10 = Func_2_Invoke_m18A3A6EDA433C635C66C43DA6B86F7BC746BFDD0_inline(L_8, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		if (!L_10)
		{
			goto IL_0061;
		}
	}

IL_004d:
	{
		Func_2_t696684549FAB37B32A9C38A40F33DB777B757E69* L_11 = __this->___selector;
		KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 L_12 = V_1;
		NullCheck(L_11);
		DictionaryEntry_t171080F37B311C25AA9E75888F9C9D703FA721BB L_13;
		L_13 = Func_2_Invoke_mFDA9BF3EFEFF70ED1767096A0993BCF4E97414BF_inline(L_11, L_12, il2cpp_rgctx_method(method->klass->rgctx_data, 14));
		((Iterator_1_t92BE161457BB4186D87644A87E4C1FAC67B8E430*)__this)->___current = L_13;
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_t92BE161457BB4186D87644A87E4C1FAC67B8E430*)__this)->___current))->____key), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&(((&((Iterator_1_t92BE161457BB4186D87644A87E4C1FAC67B8E430*)__this)->___current))->____value), (void*)NULL);
		#endif
		return (bool)1;
	}

IL_0061:
	{
		Enumerator_t81E3046D0BB629D86FAC325CBBF319731C3E36A4* L_14 = (Enumerator_t81E3046D0BB629D86FAC325CBBF319731C3E36A4*)(&__this->___enumerator);
		bool L_15;
		L_15 = Enumerator_MoveNext_m7303D41C6A0DB6D9A9B9F5923546BF98515E7B39(L_14, il2cpp_rgctx_method(method->klass->rgctx_data, 16));
		if (L_15)
		{
			goto IL_002b;
		}
	}
	{
		NullCheck((Iterator_1_t92BE161457BB4186D87644A87E4C1FAC67B8E430*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t92BE161457BB4186D87644A87E4C1FAC67B8E430*)__this);
	}

IL_0074:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectListIterator_2_Where_m09EA7BFBBF46E38A6A42D145F4FEF99892268BC1_gshared (WhereSelectListIterator_2_t67AC19AA42DBCC5EC6C01ACD9BEE8A2D23A2EEE1* __this, Func_2_tDBF8C754A8F1FC6DE54BB9904D2D81C266DFF6B4* ___0_predicate, const RuntimeMethod* method) 
{
	{
		Func_2_tDBF8C754A8F1FC6DE54BB9904D2D81C266DFF6B4* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t307785595D84CE47B35794516959DED6A6541913* L_1 = (WhereEnumerableIterator_1_t307785595D84CE47B35794516959DED6A6541913*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 19));
		WhereEnumerableIterator_1__ctor_m7A674E2DF8B9F1C27EDB614D6EF6BECFA0B57C1D(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 20));
		return (RuntimeObject*)L_1;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectListIterator_2__ctor_m9E7D9C2AC5C4EE62428D630E2153A54CA911CEAF_gshared (WhereSelectListIterator_2_t984D9217719A2864144A476CBB92FB7754CC788F* __this, List_1_t8A1639802238DEF3222B6CBBC0DEF0B4B5F350EB* ___0_source, Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* ___1_predicate, Func_2_tA526681EE526C81F376160E44520BDC21770A705* ___2_selector, const RuntimeMethod* method) 
{
	{
		Iterator_1__ctor_m426D8BD95B00FDA5C5E8FAE956FCB74E54BC7CC7((Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		List_1_t8A1639802238DEF3222B6CBBC0DEF0B4B5F350EB* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_tA526681EE526C81F376160E44520BDC21770A705* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07* WhereSelectListIterator_2_Clone_m5543BC2ADA2036AEA8AD33BB33B715E67B25E425_gshared (WhereSelectListIterator_2_t984D9217719A2864144A476CBB92FB7754CC788F* __this, const RuntimeMethod* method) 
{
	{
		List_1_t8A1639802238DEF3222B6CBBC0DEF0B4B5F350EB* L_0 = __this->___source;
		Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* L_1 = __this->___predicate;
		Func_2_tA526681EE526C81F376160E44520BDC21770A705* L_2 = __this->___selector;
		WhereSelectListIterator_2_t984D9217719A2864144A476CBB92FB7754CC788F* L_3 = (WhereSelectListIterator_2_t984D9217719A2864144A476CBB92FB7754CC788F*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 3));
		WhereSelectListIterator_2__ctor_m9E7D9C2AC5C4EE62428D630E2153A54CA911CEAF(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectListIterator_2_MoveNext_mE1D16DDBA8514349D61E5734B72CDE6E55D0E7E4_gshared (WhereSelectListIterator_2_t984D9217719A2864144A476CBB92FB7754CC788F* __this, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		int32_t L_0 = ((Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this)->___state;
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_0061;
		}
	}
	{
		goto IL_0074;
	}

IL_0011:
	{
		List_1_t8A1639802238DEF3222B6CBBC0DEF0B4B5F350EB* L_3 = __this->___source;
		NullCheck(L_3);
		Enumerator_t81E3046D0BB629D86FAC325CBBF319731C3E36A4 L_4;
		L_4 = List_1_GetEnumerator_mF067420DAFF52D4C46250012FBE1232F35652C7B(L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 8));
		__this->___enumerator = L_4;
		Il2CppCodeGenWriteBarrier((void**)&(((&__this->___enumerator))->____list), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&__this->___enumerator))->____current))->___key), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&__this->___enumerator))->____current))->___value), (void*)NULL);
		#endif
		((Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this)->___state = 2;
		goto IL_0061;
	}

IL_002b:
	{
		Enumerator_t81E3046D0BB629D86FAC325CBBF319731C3E36A4* L_5 = (Enumerator_t81E3046D0BB629D86FAC325CBBF319731C3E36A4*)(&__this->___enumerator);
		KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 L_6;
		L_6 = Enumerator_get_Current_m2E99DFD369025C91E4B23FA90EE17A41271106A4_inline(L_5, il2cpp_rgctx_method(method->klass->rgctx_data, 10));
		V_1 = L_6;
		Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* L_7 = __this->___predicate;
		if (!L_7)
		{
			goto IL_004d;
		}
	}
	{
		Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* L_8 = __this->___predicate;
		KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 L_9 = V_1;
		NullCheck(L_8);
		bool L_10;
		L_10 = Func_2_Invoke_m18A3A6EDA433C635C66C43DA6B86F7BC746BFDD0_inline(L_8, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		if (!L_10)
		{
			goto IL_0061;
		}
	}

IL_004d:
	{
		Func_2_tA526681EE526C81F376160E44520BDC21770A705* L_11 = __this->___selector;
		KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 L_12 = V_1;
		NullCheck(L_11);
		int32_t L_13;
		L_13 = Func_2_Invoke_m450153F6300275E6112B4346D2EF20A15EB7091E_inline(L_11, L_12, il2cpp_rgctx_method(method->klass->rgctx_data, 14));
		((Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this)->___current = L_13;
		return (bool)1;
	}

IL_0061:
	{
		Enumerator_t81E3046D0BB629D86FAC325CBBF319731C3E36A4* L_14 = (Enumerator_t81E3046D0BB629D86FAC325CBBF319731C3E36A4*)(&__this->___enumerator);
		bool L_15;
		L_15 = Enumerator_MoveNext_m7303D41C6A0DB6D9A9B9F5923546BF98515E7B39(L_14, il2cpp_rgctx_method(method->klass->rgctx_data, 16));
		if (L_15)
		{
			goto IL_002b;
		}
	}
	{
		NullCheck((Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this);
	}

IL_0074:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectListIterator_2_Where_m6068BC7507F99A18650B2195728A397A4B255F95_gshared (WhereSelectListIterator_2_t984D9217719A2864144A476CBB92FB7754CC788F* __this, Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA* ___0_predicate, const RuntimeMethod* method) 
{
	{
		Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t5DBA717695B8C7E60489C86AEB1FF673F50E293A* L_1 = (WhereEnumerableIterator_1_t5DBA717695B8C7E60489C86AEB1FF673F50E293A*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 19));
		WhereEnumerableIterator_1__ctor_mA7F4C6508A043D99B8288E43867D576F4697E4EE(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 20));
		return (RuntimeObject*)L_1;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectListIterator_2__ctor_m2A8C85666C5A665630499B7FAAF130D59E60BFD1_gshared (WhereSelectListIterator_2_tB5F3E1B3B06A8D74CA5DBD8ACEB44A8F1E549AF6* __this, List_1_t8A1639802238DEF3222B6CBBC0DEF0B4B5F350EB* ___0_source, Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* ___1_predicate, Func_2_tF42287527472FA89789873F068A87C60A00EC7D3* ___2_selector, const RuntimeMethod* method) 
{
	{
		Iterator_1__ctor_m3E47867714E05673E54C6B73D9242F5FFADA1F63((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		List_1_t8A1639802238DEF3222B6CBBC0DEF0B4B5F350EB* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_tF42287527472FA89789873F068A87C60A00EC7D3* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA* WhereSelectListIterator_2_Clone_m7549B7E49F1A52E465C4F9B0827E3A9241D0C573_gshared (WhereSelectListIterator_2_tB5F3E1B3B06A8D74CA5DBD8ACEB44A8F1E549AF6* __this, const RuntimeMethod* method) 
{
	{
		List_1_t8A1639802238DEF3222B6CBBC0DEF0B4B5F350EB* L_0 = __this->___source;
		Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* L_1 = __this->___predicate;
		Func_2_tF42287527472FA89789873F068A87C60A00EC7D3* L_2 = __this->___selector;
		WhereSelectListIterator_2_tB5F3E1B3B06A8D74CA5DBD8ACEB44A8F1E549AF6* L_3 = (WhereSelectListIterator_2_tB5F3E1B3B06A8D74CA5DBD8ACEB44A8F1E549AF6*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 3));
		WhereSelectListIterator_2__ctor_m2A8C85666C5A665630499B7FAAF130D59E60BFD1(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectListIterator_2_MoveNext_m96C28F46AFA617F5C19FFC661CD4F9E63BE75103_gshared (WhereSelectListIterator_2_tB5F3E1B3B06A8D74CA5DBD8ACEB44A8F1E549AF6* __this, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		int32_t L_0 = ((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this)->___state;
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_0061;
		}
	}
	{
		goto IL_0074;
	}

IL_0011:
	{
		List_1_t8A1639802238DEF3222B6CBBC0DEF0B4B5F350EB* L_3 = __this->___source;
		NullCheck(L_3);
		Enumerator_t81E3046D0BB629D86FAC325CBBF319731C3E36A4 L_4;
		L_4 = List_1_GetEnumerator_mF067420DAFF52D4C46250012FBE1232F35652C7B(L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 8));
		__this->___enumerator = L_4;
		Il2CppCodeGenWriteBarrier((void**)&(((&__this->___enumerator))->____list), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&__this->___enumerator))->____current))->___key), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&__this->___enumerator))->____current))->___value), (void*)NULL);
		#endif
		((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this)->___state = 2;
		goto IL_0061;
	}

IL_002b:
	{
		Enumerator_t81E3046D0BB629D86FAC325CBBF319731C3E36A4* L_5 = (Enumerator_t81E3046D0BB629D86FAC325CBBF319731C3E36A4*)(&__this->___enumerator);
		KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 L_6;
		L_6 = Enumerator_get_Current_m2E99DFD369025C91E4B23FA90EE17A41271106A4_inline(L_5, il2cpp_rgctx_method(method->klass->rgctx_data, 10));
		V_1 = L_6;
		Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* L_7 = __this->___predicate;
		if (!L_7)
		{
			goto IL_004d;
		}
	}
	{
		Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* L_8 = __this->___predicate;
		KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 L_9 = V_1;
		NullCheck(L_8);
		bool L_10;
		L_10 = Func_2_Invoke_m18A3A6EDA433C635C66C43DA6B86F7BC746BFDD0_inline(L_8, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		if (!L_10)
		{
			goto IL_0061;
		}
	}

IL_004d:
	{
		Func_2_tF42287527472FA89789873F068A87C60A00EC7D3* L_11 = __this->___selector;
		KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 L_12 = V_1;
		NullCheck(L_11);
		RuntimeObject* L_13;
		L_13 = Func_2_Invoke_m8EC2E5D1BEEA74F624F19C59924823693B9B39A5_inline(L_11, L_12, il2cpp_rgctx_method(method->klass->rgctx_data, 14));
		((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this)->___current = L_13;
		Il2CppCodeGenWriteBarrier((void**)(&((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this)->___current), (void*)L_13);
		return (bool)1;
	}

IL_0061:
	{
		Enumerator_t81E3046D0BB629D86FAC325CBBF319731C3E36A4* L_14 = (Enumerator_t81E3046D0BB629D86FAC325CBBF319731C3E36A4*)(&__this->___enumerator);
		bool L_15;
		L_15 = Enumerator_MoveNext_m7303D41C6A0DB6D9A9B9F5923546BF98515E7B39(L_14, il2cpp_rgctx_method(method->klass->rgctx_data, 16));
		if (L_15)
		{
			goto IL_002b;
		}
	}
	{
		NullCheck((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this);
	}

IL_0074:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectListIterator_2_Where_m2F81906E04BD7F8616E72DD5160FE9BB1D207D35_gshared (WhereSelectListIterator_2_tB5F3E1B3B06A8D74CA5DBD8ACEB44A8F1E549AF6* __this, Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* ___0_predicate, const RuntimeMethod* method) 
{
	{
		Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t1E787D13759F5A31C94B3FAED181402B25C278F4* L_1 = (WhereEnumerableIterator_1_t1E787D13759F5A31C94B3FAED181402B25C278F4*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 19));
		WhereEnumerableIterator_1__ctor_m8C0DA4CDA5431C03561F67C4393BB18CDD891F01(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 20));
		return (RuntimeObject*)L_1;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectListIterator_2__ctor_m42B6E206A0E398E45DA94F8109B58ACE1749F6A4_gshared (WhereSelectListIterator_2_t770A927BE7E150C131946093084804F846AF241A* __this, List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* ___0_source, Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA* ___1_predicate, Func_2_t2FDA873D8482C79555CFB05233D610E8F1C7C354* ___2_selector, const RuntimeMethod* method) 
{
	{
		Iterator_1__ctor_m426D8BD95B00FDA5C5E8FAE956FCB74E54BC7CC7((Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_t2FDA873D8482C79555CFB05233D610E8F1C7C354* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07* WhereSelectListIterator_2_Clone_m89B70C1B596662479F7844116D9B99FE501BFD84_gshared (WhereSelectListIterator_2_t770A927BE7E150C131946093084804F846AF241A* __this, const RuntimeMethod* method) 
{
	{
		List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* L_0 = __this->___source;
		Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA* L_1 = __this->___predicate;
		Func_2_t2FDA873D8482C79555CFB05233D610E8F1C7C354* L_2 = __this->___selector;
		WhereSelectListIterator_2_t770A927BE7E150C131946093084804F846AF241A* L_3 = (WhereSelectListIterator_2_t770A927BE7E150C131946093084804F846AF241A*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 3));
		WhereSelectListIterator_2__ctor_m42B6E206A0E398E45DA94F8109B58ACE1749F6A4(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectListIterator_2_MoveNext_mA4673028DAC84866E54385B22CBEFC22D92BC9CD_gshared (WhereSelectListIterator_2_t770A927BE7E150C131946093084804F846AF241A* __this, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		int32_t L_0 = ((Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this)->___state;
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_0061;
		}
	}
	{
		goto IL_0074;
	}

IL_0011:
	{
		List_1_t05915E9237850A58106982B7FE4BC5DA4E872E73* L_3 = __this->___source;
		NullCheck(L_3);
		Enumerator_t9DBCD072C72E44AB8959D9884EF7F528028F20EC L_4;
		L_4 = List_1_GetEnumerator_mCADB185AB483C855873FCD0B1D5AAC909ED7F7BD(L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 8));
		__this->___enumerator = L_4;
		Il2CppCodeGenWriteBarrier((void**)&(((&__this->___enumerator))->____list), (void*)NULL);
		((Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this)->___state = 2;
		goto IL_0061;
	}

IL_002b:
	{
		Enumerator_t9DBCD072C72E44AB8959D9884EF7F528028F20EC* L_5 = (Enumerator_t9DBCD072C72E44AB8959D9884EF7F528028F20EC*)(&__this->___enumerator);
		int32_t L_6;
		L_6 = Enumerator_get_Current_mB49912FF111A954F2C326BF4FA29A53C1027187B_inline(L_5, il2cpp_rgctx_method(method->klass->rgctx_data, 10));
		V_1 = L_6;
		Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA* L_7 = __this->___predicate;
		if (!L_7)
		{
			goto IL_004d;
		}
	}
	{
		Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA* L_8 = __this->___predicate;
		int32_t L_9 = V_1;
		NullCheck(L_8);
		bool L_10;
		L_10 = Func_2_Invoke_m1543D7041BADF87D1F63EBF838B0DDCB40340C7E_inline(L_8, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		if (!L_10)
		{
			goto IL_0061;
		}
	}

IL_004d:
	{
		Func_2_t2FDA873D8482C79555CFB05233D610E8F1C7C354* L_11 = __this->___selector;
		int32_t L_12 = V_1;
		NullCheck(L_11);
		int32_t L_13;
		L_13 = Func_2_Invoke_m1F8EE2DF137BE5132901C0297848BC7A373A676B_inline(L_11, L_12, il2cpp_rgctx_method(method->klass->rgctx_data, 14));
		((Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this)->___current = L_13;
		return (bool)1;
	}

IL_0061:
	{
		Enumerator_t9DBCD072C72E44AB8959D9884EF7F528028F20EC* L_14 = (Enumerator_t9DBCD072C72E44AB8959D9884EF7F528028F20EC*)(&__this->___enumerator);
		bool L_15;
		L_15 = Enumerator_MoveNext_m39C71A39758E2B4A04F44F20FCEFAF7009D5F312(L_14, il2cpp_rgctx_method(method->klass->rgctx_data, 16));
		if (L_15)
		{
			goto IL_002b;
		}
	}
	{
		NullCheck((Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this);
	}

IL_0074:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectListIterator_2_Where_m2B1D8127CD81AE6BA9FA935CA573327EACB64820_gshared (WhereSelectListIterator_2_t770A927BE7E150C131946093084804F846AF241A* __this, Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA* ___0_predicate, const RuntimeMethod* method) 
{
	{
		Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t5DBA717695B8C7E60489C86AEB1FF673F50E293A* L_1 = (WhereEnumerableIterator_1_t5DBA717695B8C7E60489C86AEB1FF673F50E293A*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 19));
		WhereEnumerableIterator_1__ctor_mA7F4C6508A043D99B8288E43867D576F4697E4EE(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 20));
		return (RuntimeObject*)L_1;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectListIterator_2__ctor_m5658691CD6D5E52B8CB4D7BF7728DF1A36AD99BF_gshared (WhereSelectListIterator_2_tFA8E9A90E251C243AA65C041D7421667E9920343* __this, List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* ___0_source, Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* ___1_predicate, Func_2_t9A0D493A82DCC47C9C819A3B045E02D9B5DDCE1B* ___2_selector, const RuntimeMethod* method) 
{
	{
		Iterator_1__ctor_m426D8BD95B00FDA5C5E8FAE956FCB74E54BC7CC7((Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_t9A0D493A82DCC47C9C819A3B045E02D9B5DDCE1B* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07* WhereSelectListIterator_2_Clone_m62045FC9E5DDF7C34F754695E9EBF13C4326DCE8_gshared (WhereSelectListIterator_2_tFA8E9A90E251C243AA65C041D7421667E9920343* __this, const RuntimeMethod* method) 
{
	{
		List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* L_0 = __this->___source;
		Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* L_1 = __this->___predicate;
		Func_2_t9A0D493A82DCC47C9C819A3B045E02D9B5DDCE1B* L_2 = __this->___selector;
		WhereSelectListIterator_2_tFA8E9A90E251C243AA65C041D7421667E9920343* L_3 = (WhereSelectListIterator_2_tFA8E9A90E251C243AA65C041D7421667E9920343*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 3));
		WhereSelectListIterator_2__ctor_m5658691CD6D5E52B8CB4D7BF7728DF1A36AD99BF(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectListIterator_2_MoveNext_mE97A1BC013242BE83F2417B94F433533ECA0BE17_gshared (WhereSelectListIterator_2_tFA8E9A90E251C243AA65C041D7421667E9920343* __this, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	RuntimeObject* V_1 = NULL;
	{
		int32_t L_0 = ((Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this)->___state;
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_0061;
		}
	}
	{
		goto IL_0074;
	}

IL_0011:
	{
		List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* L_3 = __this->___source;
		NullCheck(L_3);
		Enumerator_t9473BAB568A27E2339D48C1F91319E0F6D244D7A L_4;
		L_4 = List_1_GetEnumerator_mD8294A7FA2BEB1929487127D476F8EC1CDC23BFC(L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 8));
		__this->___enumerator = L_4;
		Il2CppCodeGenWriteBarrier((void**)&(((&__this->___enumerator))->____list), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&(((&__this->___enumerator))->____current), (void*)NULL);
		#endif
		((Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this)->___state = 2;
		goto IL_0061;
	}

IL_002b:
	{
		Enumerator_t9473BAB568A27E2339D48C1F91319E0F6D244D7A* L_5 = (Enumerator_t9473BAB568A27E2339D48C1F91319E0F6D244D7A*)(&__this->___enumerator);
		RuntimeObject* L_6;
		L_6 = Enumerator_get_Current_m6330F15D18EE4F547C05DF9BF83C5EB710376027_inline(L_5, il2cpp_rgctx_method(method->klass->rgctx_data, 10));
		V_1 = L_6;
		Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* L_7 = __this->___predicate;
		if (!L_7)
		{
			goto IL_004d;
		}
	}
	{
		Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* L_8 = __this->___predicate;
		RuntimeObject* L_9 = V_1;
		NullCheck(L_8);
		bool L_10;
		L_10 = Func_2_Invoke_m2014423FB900F135C8FF994125604FF9E6AAE829_inline(L_8, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		if (!L_10)
		{
			goto IL_0061;
		}
	}

IL_004d:
	{
		Func_2_t9A0D493A82DCC47C9C819A3B045E02D9B5DDCE1B* L_11 = __this->___selector;
		RuntimeObject* L_12 = V_1;
		NullCheck(L_11);
		int32_t L_13;
		L_13 = Func_2_Invoke_m5216F6C7BCECCCED81384876C2968E0D4358618B_inline(L_11, L_12, il2cpp_rgctx_method(method->klass->rgctx_data, 14));
		((Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this)->___current = L_13;
		return (bool)1;
	}

IL_0061:
	{
		Enumerator_t9473BAB568A27E2339D48C1F91319E0F6D244D7A* L_14 = (Enumerator_t9473BAB568A27E2339D48C1F91319E0F6D244D7A*)(&__this->___enumerator);
		bool L_15;
		L_15 = Enumerator_MoveNext_mE921CC8F29FBBDE7CC3209A0ED0D921D58D00BCB(L_14, il2cpp_rgctx_method(method->klass->rgctx_data, 16));
		if (L_15)
		{
			goto IL_002b;
		}
	}
	{
		NullCheck((Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this);
	}

IL_0074:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectListIterator_2_Where_m3FE0D83DC912C8134BC2E276A0BBBF78E7CCDFF2_gshared (WhereSelectListIterator_2_tFA8E9A90E251C243AA65C041D7421667E9920343* __this, Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA* ___0_predicate, const RuntimeMethod* method) 
{
	{
		Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t5DBA717695B8C7E60489C86AEB1FF673F50E293A* L_1 = (WhereEnumerableIterator_1_t5DBA717695B8C7E60489C86AEB1FF673F50E293A*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 19));
		WhereEnumerableIterator_1__ctor_mA7F4C6508A043D99B8288E43867D576F4697E4EE(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 20));
		return (RuntimeObject*)L_1;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectListIterator_2__ctor_m9CC6A34DCA0012E593221AFBACC4F20664BD876A_gshared (WhereSelectListIterator_2_tC97775A217B6CD43A5FD2A085EE12720F7C3808A* __this, List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* ___0_source, Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* ___1_predicate, Func_2_tACBF5A1656250800CE861707354491F0611F6624* ___2_selector, const RuntimeMethod* method) 
{
	{
		Iterator_1__ctor_m3E47867714E05673E54C6B73D9242F5FFADA1F63((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_tACBF5A1656250800CE861707354491F0611F6624* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA* WhereSelectListIterator_2_Clone_mF22589DABD608C024E039C0F5DE9F457967EC3E8_gshared (WhereSelectListIterator_2_tC97775A217B6CD43A5FD2A085EE12720F7C3808A* __this, const RuntimeMethod* method) 
{
	{
		List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* L_0 = __this->___source;
		Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* L_1 = __this->___predicate;
		Func_2_tACBF5A1656250800CE861707354491F0611F6624* L_2 = __this->___selector;
		WhereSelectListIterator_2_tC97775A217B6CD43A5FD2A085EE12720F7C3808A* L_3 = (WhereSelectListIterator_2_tC97775A217B6CD43A5FD2A085EE12720F7C3808A*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 3));
		WhereSelectListIterator_2__ctor_m9CC6A34DCA0012E593221AFBACC4F20664BD876A(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectListIterator_2_MoveNext_m4609B745A7644E640F319C2651F1A97C2D304458_gshared (WhereSelectListIterator_2_tC97775A217B6CD43A5FD2A085EE12720F7C3808A* __this, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	RuntimeObject* V_1 = NULL;
	{
		int32_t L_0 = ((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this)->___state;
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_0061;
		}
	}
	{
		goto IL_0074;
	}

IL_0011:
	{
		List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* L_3 = __this->___source;
		NullCheck(L_3);
		Enumerator_t9473BAB568A27E2339D48C1F91319E0F6D244D7A L_4;
		L_4 = List_1_GetEnumerator_mD8294A7FA2BEB1929487127D476F8EC1CDC23BFC(L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 8));
		__this->___enumerator = L_4;
		Il2CppCodeGenWriteBarrier((void**)&(((&__this->___enumerator))->____list), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&(((&__this->___enumerator))->____current), (void*)NULL);
		#endif
		((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this)->___state = 2;
		goto IL_0061;
	}

IL_002b:
	{
		Enumerator_t9473BAB568A27E2339D48C1F91319E0F6D244D7A* L_5 = (Enumerator_t9473BAB568A27E2339D48C1F91319E0F6D244D7A*)(&__this->___enumerator);
		RuntimeObject* L_6;
		L_6 = Enumerator_get_Current_m6330F15D18EE4F547C05DF9BF83C5EB710376027_inline(L_5, il2cpp_rgctx_method(method->klass->rgctx_data, 10));
		V_1 = L_6;
		Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* L_7 = __this->___predicate;
		if (!L_7)
		{
			goto IL_004d;
		}
	}
	{
		Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* L_8 = __this->___predicate;
		RuntimeObject* L_9 = V_1;
		NullCheck(L_8);
		bool L_10;
		L_10 = Func_2_Invoke_m2014423FB900F135C8FF994125604FF9E6AAE829_inline(L_8, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		if (!L_10)
		{
			goto IL_0061;
		}
	}

IL_004d:
	{
		Func_2_tACBF5A1656250800CE861707354491F0611F6624* L_11 = __this->___selector;
		RuntimeObject* L_12 = V_1;
		NullCheck(L_11);
		RuntimeObject* L_13;
		L_13 = Func_2_Invoke_mDBA25DA5DA5B7E056FB9B026AF041F1385FB58A9_inline(L_11, L_12, il2cpp_rgctx_method(method->klass->rgctx_data, 14));
		((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this)->___current = L_13;
		Il2CppCodeGenWriteBarrier((void**)(&((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this)->___current), (void*)L_13);
		return (bool)1;
	}

IL_0061:
	{
		Enumerator_t9473BAB568A27E2339D48C1F91319E0F6D244D7A* L_14 = (Enumerator_t9473BAB568A27E2339D48C1F91319E0F6D244D7A*)(&__this->___enumerator);
		bool L_15;
		L_15 = Enumerator_MoveNext_mE921CC8F29FBBDE7CC3209A0ED0D921D58D00BCB(L_14, il2cpp_rgctx_method(method->klass->rgctx_data, 16));
		if (L_15)
		{
			goto IL_002b;
		}
	}
	{
		NullCheck((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this);
	}

IL_0074:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectListIterator_2_Where_mA37F84C07852A5760237B9A50C373846A6528477_gshared (WhereSelectListIterator_2_tC97775A217B6CD43A5FD2A085EE12720F7C3808A* __this, Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* ___0_predicate, const RuntimeMethod* method) 
{
	{
		Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t1E787D13759F5A31C94B3FAED181402B25C278F4* L_1 = (WhereEnumerableIterator_1_t1E787D13759F5A31C94B3FAED181402B25C278F4*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 19));
		WhereEnumerableIterator_1__ctor_m8C0DA4CDA5431C03561F67C4393BB18CDD891F01(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 20));
		return (RuntimeObject*)L_1;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectListIterator_2__ctor_m6D88E3712F21C182AA3200920A4231559C7E8C64_gshared (WhereSelectListIterator_2_tB360A4830EF7E0F0829573AE66B167A7996E0E52* __this, List_1_t85FF16594D5F70EECC5855882558F8E26EF6BAFF* ___0_source, Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* ___1_predicate, Func_2_t12F902B64E731F36B1BC057F3AF13BF1D833E1DF* ___2_selector, const RuntimeMethod* method) 
{
	{
		Iterator_1__ctor_m426D8BD95B00FDA5C5E8FAE956FCB74E54BC7CC7((Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		List_1_t85FF16594D5F70EECC5855882558F8E26EF6BAFF* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_t12F902B64E731F36B1BC057F3AF13BF1D833E1DF* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07* WhereSelectListIterator_2_Clone_mD7DFE8C6AD3458E99FCBEA0751FF7C4043732CD4_gshared (WhereSelectListIterator_2_tB360A4830EF7E0F0829573AE66B167A7996E0E52* __this, const RuntimeMethod* method) 
{
	{
		List_1_t85FF16594D5F70EECC5855882558F8E26EF6BAFF* L_0 = __this->___source;
		Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* L_1 = __this->___predicate;
		Func_2_t12F902B64E731F36B1BC057F3AF13BF1D833E1DF* L_2 = __this->___selector;
		WhereSelectListIterator_2_tB360A4830EF7E0F0829573AE66B167A7996E0E52* L_3 = (WhereSelectListIterator_2_tB360A4830EF7E0F0829573AE66B167A7996E0E52*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 3));
		WhereSelectListIterator_2__ctor_m6D88E3712F21C182AA3200920A4231559C7E8C64(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectListIterator_2_MoveNext_m2F302C62B7FF8D42DDE74A666313CDC858137AC4_gshared (WhereSelectListIterator_2_tB360A4830EF7E0F0829573AE66B167A7996E0E52* __this, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		int32_t L_0 = ((Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this)->___state;
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_0061;
		}
	}
	{
		goto IL_0074;
	}

IL_0011:
	{
		List_1_t85FF16594D5F70EECC5855882558F8E26EF6BAFF* L_3 = __this->___source;
		NullCheck(L_3);
		Enumerator_t55FB90597665ED8BB37C633F6FD72EFAD48FE20F L_4;
		L_4 = List_1_GetEnumerator_m171CCAFC24F3096494C02B26FB8B10C408952751(L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 8));
		__this->___enumerator = L_4;
		Il2CppCodeGenWriteBarrier((void**)&(((&__this->___enumerator))->____list), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&__this->___enumerator))->____current))->___m_Value), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&__this->___enumerator))->____current))->___tempData), (void*)NULL);
		#endif
		((Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this)->___state = 2;
		goto IL_0061;
	}

IL_002b:
	{
		Enumerator_t55FB90597665ED8BB37C633F6FD72EFAD48FE20F* L_5 = (Enumerator_t55FB90597665ED8BB37C633F6FD72EFAD48FE20F*)(&__this->___enumerator);
		StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 L_6;
		L_6 = Enumerator_get_Current_m4E279E6389EB06C5DBE88A74E3BD3F23FB2B17E4_inline(L_5, il2cpp_rgctx_method(method->klass->rgctx_data, 10));
		V_1 = L_6;
		Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* L_7 = __this->___predicate;
		if (!L_7)
		{
			goto IL_004d;
		}
	}
	{
		Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* L_8 = __this->___predicate;
		StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 L_9 = V_1;
		NullCheck(L_8);
		bool L_10;
		L_10 = Func_2_Invoke_m7C54973F594216484A4F81A59CDF821AF554339D_inline(L_8, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		if (!L_10)
		{
			goto IL_0061;
		}
	}

IL_004d:
	{
		Func_2_t12F902B64E731F36B1BC057F3AF13BF1D833E1DF* L_11 = __this->___selector;
		StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 L_12 = V_1;
		NullCheck(L_11);
		int32_t L_13;
		L_13 = Func_2_Invoke_m57961B138A397ADAB0DC71E56519ADBD63327D27_inline(L_11, L_12, il2cpp_rgctx_method(method->klass->rgctx_data, 14));
		((Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this)->___current = L_13;
		return (bool)1;
	}

IL_0061:
	{
		Enumerator_t55FB90597665ED8BB37C633F6FD72EFAD48FE20F* L_14 = (Enumerator_t55FB90597665ED8BB37C633F6FD72EFAD48FE20F*)(&__this->___enumerator);
		bool L_15;
		L_15 = Enumerator_MoveNext_m6A369A40774C06803D46E3D1DBA2874ECFF63E9E(L_14, il2cpp_rgctx_method(method->klass->rgctx_data, 16));
		if (L_15)
		{
			goto IL_002b;
		}
	}
	{
		NullCheck((Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_tCCB165DB1184FCEC531345224E55B98DDF04BD07*)__this);
	}

IL_0074:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectListIterator_2_Where_m98B6BE2F15454CBA305692F230C66425836665F4_gshared (WhereSelectListIterator_2_tB360A4830EF7E0F0829573AE66B167A7996E0E52* __this, Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA* ___0_predicate, const RuntimeMethod* method) 
{
	{
		Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t5DBA717695B8C7E60489C86AEB1FF673F50E293A* L_1 = (WhereEnumerableIterator_1_t5DBA717695B8C7E60489C86AEB1FF673F50E293A*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 19));
		WhereEnumerableIterator_1__ctor_mA7F4C6508A043D99B8288E43867D576F4697E4EE(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 20));
		return (RuntimeObject*)L_1;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectListIterator_2__ctor_m15AA54F3B60B64CEFB048CD88E3A1BD06AC2C62E_gshared (WhereSelectListIterator_2_t60681EEE1A6CB8E9C8EE807AA2E2BDA68B9B6989* __this, List_1_t85FF16594D5F70EECC5855882558F8E26EF6BAFF* ___0_source, Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* ___1_predicate, Func_2_tFD36EA818BBCBD1EDE1E1540FC3EF156A6ADCCAD* ___2_selector, const RuntimeMethod* method) 
{
	{
		Iterator_1__ctor_m3E47867714E05673E54C6B73D9242F5FFADA1F63((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		List_1_t85FF16594D5F70EECC5855882558F8E26EF6BAFF* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_tFD36EA818BBCBD1EDE1E1540FC3EF156A6ADCCAD* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA* WhereSelectListIterator_2_Clone_m6D285DDC28CFAF8BDCF8C2ED06F9982D33D0342A_gshared (WhereSelectListIterator_2_t60681EEE1A6CB8E9C8EE807AA2E2BDA68B9B6989* __this, const RuntimeMethod* method) 
{
	{
		List_1_t85FF16594D5F70EECC5855882558F8E26EF6BAFF* L_0 = __this->___source;
		Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* L_1 = __this->___predicate;
		Func_2_tFD36EA818BBCBD1EDE1E1540FC3EF156A6ADCCAD* L_2 = __this->___selector;
		WhereSelectListIterator_2_t60681EEE1A6CB8E9C8EE807AA2E2BDA68B9B6989* L_3 = (WhereSelectListIterator_2_t60681EEE1A6CB8E9C8EE807AA2E2BDA68B9B6989*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 3));
		WhereSelectListIterator_2__ctor_m15AA54F3B60B64CEFB048CD88E3A1BD06AC2C62E(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectListIterator_2_MoveNext_m9DBE2E1EDA00E9EBE1A6E90D5DA81A39E1CEBF37_gshared (WhereSelectListIterator_2_t60681EEE1A6CB8E9C8EE807AA2E2BDA68B9B6989* __this, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		int32_t L_0 = ((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this)->___state;
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_0061;
		}
	}
	{
		goto IL_0074;
	}

IL_0011:
	{
		List_1_t85FF16594D5F70EECC5855882558F8E26EF6BAFF* L_3 = __this->___source;
		NullCheck(L_3);
		Enumerator_t55FB90597665ED8BB37C633F6FD72EFAD48FE20F L_4;
		L_4 = List_1_GetEnumerator_m171CCAFC24F3096494C02B26FB8B10C408952751(L_3, il2cpp_rgctx_method(method->klass->rgctx_data, 8));
		__this->___enumerator = L_4;
		Il2CppCodeGenWriteBarrier((void**)&(((&__this->___enumerator))->____list), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&__this->___enumerator))->____current))->___m_Value), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&__this->___enumerator))->____current))->___tempData), (void*)NULL);
		#endif
		((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this)->___state = 2;
		goto IL_0061;
	}

IL_002b:
	{
		Enumerator_t55FB90597665ED8BB37C633F6FD72EFAD48FE20F* L_5 = (Enumerator_t55FB90597665ED8BB37C633F6FD72EFAD48FE20F*)(&__this->___enumerator);
		StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 L_6;
		L_6 = Enumerator_get_Current_m4E279E6389EB06C5DBE88A74E3BD3F23FB2B17E4_inline(L_5, il2cpp_rgctx_method(method->klass->rgctx_data, 10));
		V_1 = L_6;
		Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* L_7 = __this->___predicate;
		if (!L_7)
		{
			goto IL_004d;
		}
	}
	{
		Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* L_8 = __this->___predicate;
		StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 L_9 = V_1;
		NullCheck(L_8);
		bool L_10;
		L_10 = Func_2_Invoke_m7C54973F594216484A4F81A59CDF821AF554339D_inline(L_8, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 13));
		if (!L_10)
		{
			goto IL_0061;
		}
	}

IL_004d:
	{
		Func_2_tFD36EA818BBCBD1EDE1E1540FC3EF156A6ADCCAD* L_11 = __this->___selector;
		StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 L_12 = V_1;
		NullCheck(L_11);
		RuntimeObject* L_13;
		L_13 = Func_2_Invoke_m1F78C6C79382EA6E74D62E31DD00A9378266A518_inline(L_11, L_12, il2cpp_rgctx_method(method->klass->rgctx_data, 14));
		((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this)->___current = L_13;
		Il2CppCodeGenWriteBarrier((void**)(&((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this)->___current), (void*)L_13);
		return (bool)1;
	}

IL_0061:
	{
		Enumerator_t55FB90597665ED8BB37C633F6FD72EFAD48FE20F* L_14 = (Enumerator_t55FB90597665ED8BB37C633F6FD72EFAD48FE20F*)(&__this->___enumerator);
		bool L_15;
		L_15 = Enumerator_MoveNext_m6A369A40774C06803D46E3D1DBA2874ECFF63E9E(L_14, il2cpp_rgctx_method(method->klass->rgctx_data, 16));
		if (L_15)
		{
			goto IL_002b;
		}
	}
	{
		NullCheck((Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t99A1802EE86A3D5BF71B2DDB37F159C4AFA448EA*)__this);
	}

IL_0074:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectListIterator_2_Where_mE0E3E8BE8176B317F5FF0D03313F7D4DFE68681E_gshared (WhereSelectListIterator_2_t60681EEE1A6CB8E9C8EE807AA2E2BDA68B9B6989* __this, Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* ___0_predicate, const RuntimeMethod* method) 
{
	{
		Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t1E787D13759F5A31C94B3FAED181402B25C278F4* L_1 = (WhereEnumerableIterator_1_t1E787D13759F5A31C94B3FAED181402B25C278F4*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 19));
		WhereEnumerableIterator_1__ctor_m8C0DA4CDA5431C03561F67C4393BB18CDD891F01(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 20));
		return (RuntimeObject*)L_1;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectListIterator_2__ctor_m6BFCBB5460270ED1896D24DC7E3B83F4950D2140_gshared (WhereSelectListIterator_2_t86EE6817E8A1706688C6D82D82C9D44BC99CC336* __this, List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* ___0_source, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* ___1_predicate, Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0* ___2_selector, const RuntimeMethod* method) 
{
	{
		((  void (*) (Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 0)))((Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* L_0 = ___0_source;
		il2cpp_codegen_write_instance_field_data<List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A*>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),0), L_0);
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_1 = ___1_predicate;
		il2cpp_codegen_write_instance_field_data<Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B*>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),1), L_1);
		Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0* L_2 = ___2_selector;
		il2cpp_codegen_write_instance_field_data<Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0*>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),2), L_2);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0* WhereSelectListIterator_2_Clone_m8EC8E684FFDC3BC579DF37C08993B7F80966639D_gshared (WhereSelectListIterator_2_t86EE6817E8A1706688C6D82D82C9D44BC99CC336* __this, const RuntimeMethod* method) 
{
	{
		List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* L_0 = *(List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),0));
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_1 = *(Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),1));
		Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0* L_2 = *(Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),2));
		WhereSelectListIterator_2_t86EE6817E8A1706688C6D82D82C9D44BC99CC336* L_3 = (WhereSelectListIterator_2_t86EE6817E8A1706688C6D82D82C9D44BC99CC336*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 3));
		((  void (*) (WhereSelectListIterator_2_t86EE6817E8A1706688C6D82D82C9D44BC99CC336*, List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A*, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B*, Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 6)))(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		return (Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectListIterator_2_MoveNext_mBB81EEF5DFFEBDDB1AC24116FAD1D13505525569_gshared (WhereSelectListIterator_2_t86EE6817E8A1706688C6D82D82C9D44BC99CC336* __this, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_TSource_tEB7490DB2885922B8C60E28873F5DB811BD9CEB3 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 12));
	const uint32_t SizeOf_Enumerator_t8A622325AF1352D3AB0ECDBB45A0AFB7AF959716 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 9));
	const uint32_t SizeOf_TResult_t11AC9139084FDCB528CAF75FE5166467D3329A05 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 15));
	const Il2CppFullySharedGenericAny L_5 = alloca(SizeOf_TSource_tEB7490DB2885922B8C60E28873F5DB811BD9CEB3);
	const Il2CppFullySharedGenericAny L_8 = L_5;
	const Il2CppFullySharedGenericAny L_11 = L_5;
	const Il2CppFullySharedGenericAny L_12 = alloca(SizeOf_TResult_t11AC9139084FDCB528CAF75FE5166467D3329A05);
	const Enumerator_tF5AC6CD19D283FBD724440520CEE68FE2602F7AF L_4 = alloca(SizeOf_Enumerator_t8A622325AF1352D3AB0ECDBB45A0AFB7AF959716);
	int32_t V_0 = 0;
	Il2CppFullySharedGenericAny V_1 = alloca(SizeOf_TSource_tEB7490DB2885922B8C60E28873F5DB811BD9CEB3);
	memset(V_1, 0, SizeOf_TSource_tEB7490DB2885922B8C60E28873F5DB811BD9CEB3);
	{
		int32_t L_0 = *(int32_t*)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 7),1));
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_0061;
		}
	}
	{
		goto IL_0074;
	}

IL_0011:
	{
		List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* L_3 = *(List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),0));
		NullCheck(L_3);
		InvokerActionInvoker1< Enumerator_tF5AC6CD19D283FBD724440520CEE68FE2602F7AF* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 8)), il2cpp_rgctx_method(method->klass->rgctx_data, 8), L_3, (Enumerator_tF5AC6CD19D283FBD724440520CEE68FE2602F7AF*)L_4);
		il2cpp_codegen_write_instance_field_data(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),3), L_4, SizeOf_Enumerator_t8A622325AF1352D3AB0ECDBB45A0AFB7AF959716);
		il2cpp_codegen_write_instance_field_data<int32_t>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 7),1), 2);
		goto IL_0061;
	}

IL_002b:
	{
		InvokerActionInvoker1< Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 10)), il2cpp_rgctx_method(method->klass->rgctx_data, 10), (((Enumerator_tF5AC6CD19D283FBD724440520CEE68FE2602F7AF*)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),3)))), (Il2CppFullySharedGenericAny*)L_5);
		il2cpp_codegen_memcpy(V_1, L_5, SizeOf_TSource_tEB7490DB2885922B8C60E28873F5DB811BD9CEB3);
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_6 = *(Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),1));
		if (!L_6)
		{
			goto IL_004d;
		}
	}
	{
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_7 = *(Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),1));
		il2cpp_codegen_memcpy(L_8, V_1, SizeOf_TSource_tEB7490DB2885922B8C60E28873F5DB811BD9CEB3);
		NullCheck(L_7);
		bool L_9;
		L_9 = InvokerFuncInvoker1< bool, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 13)), il2cpp_rgctx_method(method->klass->rgctx_data, 13), L_7, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 12)) ? L_8: *(void**)L_8));
		if (!L_9)
		{
			goto IL_0061;
		}
	}

IL_004d:
	{
		Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0* L_10 = *(Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),2));
		il2cpp_codegen_memcpy(L_11, V_1, SizeOf_TSource_tEB7490DB2885922B8C60E28873F5DB811BD9CEB3);
		NullCheck(L_10);
		InvokerActionInvoker2< Il2CppFullySharedGenericAny, Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 14)), il2cpp_rgctx_method(method->klass->rgctx_data, 14), L_10, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 12)) ? L_11: *(void**)L_11), (Il2CppFullySharedGenericAny*)L_12);
		il2cpp_codegen_write_instance_field_data(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 7),2), L_12, SizeOf_TResult_t11AC9139084FDCB528CAF75FE5166467D3329A05);
		return (bool)1;
	}

IL_0061:
	{
		bool L_13;
		L_13 = ((  bool (*) (Enumerator_tF5AC6CD19D283FBD724440520CEE68FE2602F7AF*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 16)))((((Enumerator_tF5AC6CD19D283FBD724440520CEE68FE2602F7AF*)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3),3)))), il2cpp_rgctx_method(method->klass->rgctx_data, 16));
		if (L_13)
		{
			goto IL_002b;
		}
	}
	{
		NullCheck((Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)__this);
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)__this);
	}

IL_0074:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectListIterator_2_Where_m1739BDD134D3AF5A55DBB06AEE130B0C58E47014_gshared (WhereSelectListIterator_2_t86EE6817E8A1706688C6D82D82C9D44BC99CC336* __this, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* ___0_predicate, const RuntimeMethod* method) 
{
	{
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t8B24528558F527941435C4FE1D046216FE4F277B* L_1 = (WhereEnumerableIterator_1_t8B24528558F527941435C4FE1D046216FE4F277B*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 19));
		((  void (*) (WhereEnumerableIterator_1_t8B24528558F527941435C4FE1D046216FE4F277B*, RuntimeObject*, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 20)))(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(method->klass->rgctx_data, 20));
		return (RuntimeObject*)L_1;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WithoutCurrentEnumerable__ctor_m5F2548C9BDEA098E43955DB9F5AB9AC9867A1446_gshared (WithoutCurrentEnumerable_t61691720F7363FB52D0166233D6F1CDEC9A12368* __this, AsyncReactiveProperty_1_t55DCE046DB85F4B8B8BFAD7AE879EE536D5F9733* ___0_parent, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2((RuntimeObject*)__this, NULL);
		AsyncReactiveProperty_1_t55DCE046DB85F4B8B8BFAD7AE879EE536D5F9733* L_0 = ___0_parent;
		__this->___parent = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___parent), (void*)L_0);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WithoutCurrentEnumerable_GetAsyncEnumerator_mA34590B1BE46B1BCA23E0AFE548A2B8EEC33788B_gshared (WithoutCurrentEnumerable_t61691720F7363FB52D0166233D6F1CDEC9A12368* __this, CancellationToken_t51142D9C6D7C02D314DA34A6A7988C528992FFED ___0_cancellationToken, const RuntimeMethod* method) 
{
	RuntimeObject* V_0 = NULL;
	{
		AsyncReactiveProperty_1_t55DCE046DB85F4B8B8BFAD7AE879EE536D5F9733* L_0 = __this->___parent;
		CancellationToken_t51142D9C6D7C02D314DA34A6A7988C528992FFED L_1 = ___0_cancellationToken;
		Enumerator_t52AB038CB588CDE841350C02AA5D28DAAA6DBA60* L_2 = (Enumerator_t52AB038CB588CDE841350C02AA5D28DAAA6DBA60*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 2));
		((  void (*) (Enumerator_t52AB038CB588CDE841350C02AA5D28DAAA6DBA60*, AsyncReactiveProperty_1_t55DCE046DB85F4B8B8BFAD7AE879EE536D5F9733*, CancellationToken_t51142D9C6D7C02D314DA34A6A7988C528992FFED, bool, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 3)))(L_2, L_0, L_1, (bool)0, il2cpp_rgctx_method(method->klass->rgctx_data, 3));
		V_0 = (RuntimeObject*)L_2;
		goto IL_0011;
	}

IL_0011:
	{
		RuntimeObject* L_3 = V_0;
		return L_3;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WithoutCurrentEnumerable__ctor_m4C8C640AF658BB633522AD90FBFFFD2A4C742B2C_gshared (WithoutCurrentEnumerable_tA165573F50CE7FD8626E075AE98BC04DE9B29888* __this, ReadOnlyAsyncReactiveProperty_1_tB7349A20B00D8047434C5CDE4CB7EC263380B1E9* ___0_parent, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2((RuntimeObject*)__this, NULL);
		ReadOnlyAsyncReactiveProperty_1_tB7349A20B00D8047434C5CDE4CB7EC263380B1E9* L_0 = ___0_parent;
		__this->___parent = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___parent), (void*)L_0);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WithoutCurrentEnumerable_GetAsyncEnumerator_mF8EB8E275666D4F8CB9E5DB7DA08CF20E14A833C_gshared (WithoutCurrentEnumerable_tA165573F50CE7FD8626E075AE98BC04DE9B29888* __this, CancellationToken_t51142D9C6D7C02D314DA34A6A7988C528992FFED ___0_cancellationToken, const RuntimeMethod* method) 
{
	RuntimeObject* V_0 = NULL;
	{
		ReadOnlyAsyncReactiveProperty_1_tB7349A20B00D8047434C5CDE4CB7EC263380B1E9* L_0 = __this->___parent;
		CancellationToken_t51142D9C6D7C02D314DA34A6A7988C528992FFED L_1 = ___0_cancellationToken;
		Enumerator_t2264BA8CF3D7072C596172D20E9E9AB2BF7CF0BE* L_2 = (Enumerator_t2264BA8CF3D7072C596172D20E9E9AB2BF7CF0BE*)il2cpp_codegen_object_new(il2cpp_rgctx_data(method->klass->rgctx_data, 2));
		((  void (*) (Enumerator_t2264BA8CF3D7072C596172D20E9E9AB2BF7CF0BE*, ReadOnlyAsyncReactiveProperty_1_tB7349A20B00D8047434C5CDE4CB7EC263380B1E9*, CancellationToken_t51142D9C6D7C02D314DA34A6A7988C528992FFED, bool, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 3)))(L_2, L_0, L_1, (bool)0, il2cpp_rgctx_method(method->klass->rgctx_data, 3));
		V_0 = (RuntimeObject*)L_2;
		goto IL_0011;
	}

IL_0011:
	{
		RuntimeObject* L_3 = V_0;
		return L_3;
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
void WriteDelegate_Invoke_mE86A5384298CF3DF2344D386DC4CA589E42DE399_Multicast(WriteDelegate_t6A0EB21668C92D873ACB875924DE54518D8B7234* __this, Rect_tA04E0F8A1830E767F40FB27ECD8D309303571F0D* ___0_val, float ___1_fieldValue, const RuntimeMethod* method)
{
	il2cpp_array_size_t length = __this->___delegates->max_length;
	Delegate_t** delegatesToInvoke = reinterpret_cast<Delegate_t**>(__this->___delegates->GetAddressAtUnchecked(0));
	for (il2cpp_array_size_t i = 0; i < length; i++)
	{
		WriteDelegate_t6A0EB21668C92D873ACB875924DE54518D8B7234* currentDelegate = reinterpret_cast<WriteDelegate_t6A0EB21668C92D873ACB875924DE54518D8B7234*>(delegatesToInvoke[i]);
		typedef void (*FunctionPointerType) (RuntimeObject*, Rect_tA04E0F8A1830E767F40FB27ECD8D309303571F0D*, float, const RuntimeMethod*);
		((FunctionPointerType)currentDelegate->___invoke_impl)((Il2CppObject*)currentDelegate->___method_code, ___0_val, ___1_fieldValue, reinterpret_cast<RuntimeMethod*>(currentDelegate->___method));
	}
}
void WriteDelegate_Invoke_mE86A5384298CF3DF2344D386DC4CA589E42DE399_OpenInst(WriteDelegate_t6A0EB21668C92D873ACB875924DE54518D8B7234* __this, Rect_tA04E0F8A1830E767F40FB27ECD8D309303571F0D* ___0_val, float ___1_fieldValue, const RuntimeMethod* method)
{
	typedef void (*FunctionPointerType) (Rect_tA04E0F8A1830E767F40FB27ECD8D309303571F0D*, float, const RuntimeMethod*);
	((FunctionPointerType)__this->___method_ptr)(___0_val, ___1_fieldValue, method);
}
void WriteDelegate_Invoke_mE86A5384298CF3DF2344D386DC4CA589E42DE399_OpenStatic(WriteDelegate_t6A0EB21668C92D873ACB875924DE54518D8B7234* __this, Rect_tA04E0F8A1830E767F40FB27ECD8D309303571F0D* ___0_val, float ___1_fieldValue, const RuntimeMethod* method)
{
	typedef void (*FunctionPointerType) (Rect_tA04E0F8A1830E767F40FB27ECD8D309303571F0D*, float, const RuntimeMethod*);
	((FunctionPointerType)__this->___method_ptr)(___0_val, ___1_fieldValue, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WriteDelegate__ctor_m630834333CB7AE51AB01F7713157EE57991D03D7_gshared (WriteDelegate_t6A0EB21668C92D873ACB875924DE54518D8B7234* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method) 
{
	__this->___method_ptr = (intptr_t)il2cpp_codegen_get_method_pointer((RuntimeMethod*)___1_method);
	__this->___method = ___1_method;
	__this->___m_target = ___0_object;
	Il2CppCodeGenWriteBarrier((void**)(&__this->___m_target), (void*)___0_object);
	int parameterCount = il2cpp_codegen_method_parameter_count((RuntimeMethod*)___1_method);
	__this->___method_code = (intptr_t)__this;
	if (MethodIsStatic((RuntimeMethod*)___1_method))
	{
		bool isOpen = parameterCount == 2;
		if (isOpen)
			__this->___invoke_impl = (intptr_t)&WriteDelegate_Invoke_mE86A5384298CF3DF2344D386DC4CA589E42DE399_OpenStatic;
		else
			{
				__this->___invoke_impl = __this->___method_ptr;
				__this->___method_code = (intptr_t)__this->___m_target;
			}
	}
	else
	{
		bool isOpen = parameterCount == 1;
		if (isOpen)
		{
			__this->___invoke_impl = (intptr_t)&WriteDelegate_Invoke_mE86A5384298CF3DF2344D386DC4CA589E42DE399_OpenInst;
		}
		else
		{
			if (___0_object == NULL)
				il2cpp_codegen_raise_exception(il2cpp_codegen_get_argument_exception(NULL, "Delegate to an instance method cannot have null 'this'."), NULL);
			__this->___invoke_impl = __this->___method_ptr;
			__this->___method_code = (intptr_t)__this->___m_target;
		}
	}
	__this->___extra_arg = (intptr_t)&WriteDelegate_Invoke_mE86A5384298CF3DF2344D386DC4CA589E42DE399_Multicast;
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WriteDelegate_Invoke_mE86A5384298CF3DF2344D386DC4CA589E42DE399_gshared (WriteDelegate_t6A0EB21668C92D873ACB875924DE54518D8B7234* __this, Rect_tA04E0F8A1830E767F40FB27ECD8D309303571F0D* ___0_val, float ___1_fieldValue, const RuntimeMethod* method) 
{
	typedef void (*FunctionPointerType) (RuntimeObject*, Rect_tA04E0F8A1830E767F40FB27ECD8D309303571F0D*, float, const RuntimeMethod*);
	((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_val, ___1_fieldValue, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
void WriteDelegate_Invoke_m86BA7048E52732500448764B50B058BBB1AB029A_Multicast(WriteDelegate_t737D0DA8D96562AD76BB67D9C5A5199EDB0171E1* __this, RectInt_t1744D10E1063135DA9D574F95205B98DAC600CB8* ___0_val, int32_t ___1_fieldValue, const RuntimeMethod* method)
{
	il2cpp_array_size_t length = __this->___delegates->max_length;
	Delegate_t** delegatesToInvoke = reinterpret_cast<Delegate_t**>(__this->___delegates->GetAddressAtUnchecked(0));
	for (il2cpp_array_size_t i = 0; i < length; i++)
	{
		WriteDelegate_t737D0DA8D96562AD76BB67D9C5A5199EDB0171E1* currentDelegate = reinterpret_cast<WriteDelegate_t737D0DA8D96562AD76BB67D9C5A5199EDB0171E1*>(delegatesToInvoke[i]);
		typedef void (*FunctionPointerType) (RuntimeObject*, RectInt_t1744D10E1063135DA9D574F95205B98DAC600CB8*, int32_t, const RuntimeMethod*);
		((FunctionPointerType)currentDelegate->___invoke_impl)((Il2CppObject*)currentDelegate->___method_code, ___0_val, ___1_fieldValue, reinterpret_cast<RuntimeMethod*>(currentDelegate->___method));
	}
}
void WriteDelegate_Invoke_m86BA7048E52732500448764B50B058BBB1AB029A_OpenInst(WriteDelegate_t737D0DA8D96562AD76BB67D9C5A5199EDB0171E1* __this, RectInt_t1744D10E1063135DA9D574F95205B98DAC600CB8* ___0_val, int32_t ___1_fieldValue, const RuntimeMethod* method)
{
	typedef void (*FunctionPointerType) (RectInt_t1744D10E1063135DA9D574F95205B98DAC600CB8*, int32_t, const RuntimeMethod*);
	((FunctionPointerType)__this->___method_ptr)(___0_val, ___1_fieldValue, method);
}
void WriteDelegate_Invoke_m86BA7048E52732500448764B50B058BBB1AB029A_OpenStatic(WriteDelegate_t737D0DA8D96562AD76BB67D9C5A5199EDB0171E1* __this, RectInt_t1744D10E1063135DA9D574F95205B98DAC600CB8* ___0_val, int32_t ___1_fieldValue, const RuntimeMethod* method)
{
	typedef void (*FunctionPointerType) (RectInt_t1744D10E1063135DA9D574F95205B98DAC600CB8*, int32_t, const RuntimeMethod*);
	((FunctionPointerType)__this->___method_ptr)(___0_val, ___1_fieldValue, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WriteDelegate__ctor_m2AA9BE88F67A2DA68720D6B5F2AFFA89E23BB597_gshared (WriteDelegate_t737D0DA8D96562AD76BB67D9C5A5199EDB0171E1* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method) 
{
	__this->___method_ptr = (intptr_t)il2cpp_codegen_get_method_pointer((RuntimeMethod*)___1_method);
	__this->___method = ___1_method;
	__this->___m_target = ___0_object;
	Il2CppCodeGenWriteBarrier((void**)(&__this->___m_target), (void*)___0_object);
	int parameterCount = il2cpp_codegen_method_parameter_count((RuntimeMethod*)___1_method);
	__this->___method_code = (intptr_t)__this;
	if (MethodIsStatic((RuntimeMethod*)___1_method))
	{
		bool isOpen = parameterCount == 2;
		if (isOpen)
			__this->___invoke_impl = (intptr_t)&WriteDelegate_Invoke_m86BA7048E52732500448764B50B058BBB1AB029A_OpenStatic;
		else
			{
				__this->___invoke_impl = __this->___method_ptr;
				__this->___method_code = (intptr_t)__this->___m_target;
			}
	}
	else
	{
		bool isOpen = parameterCount == 1;
		if (isOpen)
		{
			__this->___invoke_impl = (intptr_t)&WriteDelegate_Invoke_m86BA7048E52732500448764B50B058BBB1AB029A_OpenInst;
		}
		else
		{
			if (___0_object == NULL)
				il2cpp_codegen_raise_exception(il2cpp_codegen_get_argument_exception(NULL, "Delegate to an instance method cannot have null 'this'."), NULL);
			__this->___invoke_impl = __this->___method_ptr;
			__this->___method_code = (intptr_t)__this->___m_target;
		}
	}
	__this->___extra_arg = (intptr_t)&WriteDelegate_Invoke_m86BA7048E52732500448764B50B058BBB1AB029A_Multicast;
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WriteDelegate_Invoke_m86BA7048E52732500448764B50B058BBB1AB029A_gshared (WriteDelegate_t737D0DA8D96562AD76BB67D9C5A5199EDB0171E1* __this, RectInt_t1744D10E1063135DA9D574F95205B98DAC600CB8* ___0_val, int32_t ___1_fieldValue, const RuntimeMethod* method) 
{
	typedef void (*FunctionPointerType) (RuntimeObject*, RectInt_t1744D10E1063135DA9D574F95205B98DAC600CB8*, int32_t, const RuntimeMethod*);
	((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_val, ___1_fieldValue, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
void WriteDelegate_Invoke_m6DAF352FCBE9E4A508A3AB7056209E9DEDCE6ACC_Multicast(WriteDelegate_t907C2DAF3A619B832C6D9441AF1C4CDA7914AF1D* __this, Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7* ___0_val, float ___1_fieldValue, const RuntimeMethod* method)
{
	il2cpp_array_size_t length = __this->___delegates->max_length;
	Delegate_t** delegatesToInvoke = reinterpret_cast<Delegate_t**>(__this->___delegates->GetAddressAtUnchecked(0));
	for (il2cpp_array_size_t i = 0; i < length; i++)
	{
		WriteDelegate_t907C2DAF3A619B832C6D9441AF1C4CDA7914AF1D* currentDelegate = reinterpret_cast<WriteDelegate_t907C2DAF3A619B832C6D9441AF1C4CDA7914AF1D*>(delegatesToInvoke[i]);
		typedef void (*FunctionPointerType) (RuntimeObject*, Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7*, float, const RuntimeMethod*);
		((FunctionPointerType)currentDelegate->___invoke_impl)((Il2CppObject*)currentDelegate->___method_code, ___0_val, ___1_fieldValue, reinterpret_cast<RuntimeMethod*>(currentDelegate->___method));
	}
}
void WriteDelegate_Invoke_m6DAF352FCBE9E4A508A3AB7056209E9DEDCE6ACC_OpenInst(WriteDelegate_t907C2DAF3A619B832C6D9441AF1C4CDA7914AF1D* __this, Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7* ___0_val, float ___1_fieldValue, const RuntimeMethod* method)
{
	typedef void (*FunctionPointerType) (Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7*, float, const RuntimeMethod*);
	((FunctionPointerType)__this->___method_ptr)(___0_val, ___1_fieldValue, method);
}
void WriteDelegate_Invoke_m6DAF352FCBE9E4A508A3AB7056209E9DEDCE6ACC_OpenStatic(WriteDelegate_t907C2DAF3A619B832C6D9441AF1C4CDA7914AF1D* __this, Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7* ___0_val, float ___1_fieldValue, const RuntimeMethod* method)
{
	typedef void (*FunctionPointerType) (Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7*, float, const RuntimeMethod*);
	((FunctionPointerType)__this->___method_ptr)(___0_val, ___1_fieldValue, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WriteDelegate__ctor_m4F33ED7C62B9E61B33CC81A7B5C739D0396BC209_gshared (WriteDelegate_t907C2DAF3A619B832C6D9441AF1C4CDA7914AF1D* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method) 
{
	__this->___method_ptr = (intptr_t)il2cpp_codegen_get_method_pointer((RuntimeMethod*)___1_method);
	__this->___method = ___1_method;
	__this->___m_target = ___0_object;
	Il2CppCodeGenWriteBarrier((void**)(&__this->___m_target), (void*)___0_object);
	int parameterCount = il2cpp_codegen_method_parameter_count((RuntimeMethod*)___1_method);
	__this->___method_code = (intptr_t)__this;
	if (MethodIsStatic((RuntimeMethod*)___1_method))
	{
		bool isOpen = parameterCount == 2;
		if (isOpen)
			__this->___invoke_impl = (intptr_t)&WriteDelegate_Invoke_m6DAF352FCBE9E4A508A3AB7056209E9DEDCE6ACC_OpenStatic;
		else
			{
				__this->___invoke_impl = __this->___method_ptr;
				__this->___method_code = (intptr_t)__this->___m_target;
			}
	}
	else
	{
		bool isOpen = parameterCount == 1;
		if (isOpen)
		{
			__this->___invoke_impl = (intptr_t)&WriteDelegate_Invoke_m6DAF352FCBE9E4A508A3AB7056209E9DEDCE6ACC_OpenInst;
		}
		else
		{
			if (___0_object == NULL)
				il2cpp_codegen_raise_exception(il2cpp_codegen_get_argument_exception(NULL, "Delegate to an instance method cannot have null 'this'."), NULL);
			__this->___invoke_impl = __this->___method_ptr;
			__this->___method_code = (intptr_t)__this->___m_target;
		}
	}
	__this->___extra_arg = (intptr_t)&WriteDelegate_Invoke_m6DAF352FCBE9E4A508A3AB7056209E9DEDCE6ACC_Multicast;
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WriteDelegate_Invoke_m6DAF352FCBE9E4A508A3AB7056209E9DEDCE6ACC_gshared (WriteDelegate_t907C2DAF3A619B832C6D9441AF1C4CDA7914AF1D* __this, Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7* ___0_val, float ___1_fieldValue, const RuntimeMethod* method) 
{
	typedef void (*FunctionPointerType) (RuntimeObject*, Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7*, float, const RuntimeMethod*);
	((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_val, ___1_fieldValue, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
void WriteDelegate_Invoke_mDCBB3FCC716BDB01FBB6A93055CB254FEFF466CA_Multicast(WriteDelegate_tE9F20B5E1A664D239EFDD91143B963A216AAB1C7* __this, Vector2Int_t69B2886EBAB732D9B880565E18E7568F3DE0CE6A* ___0_val, int32_t ___1_fieldValue, const RuntimeMethod* method)
{
	il2cpp_array_size_t length = __this->___delegates->max_length;
	Delegate_t** delegatesToInvoke = reinterpret_cast<Delegate_t**>(__this->___delegates->GetAddressAtUnchecked(0));
	for (il2cpp_array_size_t i = 0; i < length; i++)
	{
		WriteDelegate_tE9F20B5E1A664D239EFDD91143B963A216AAB1C7* currentDelegate = reinterpret_cast<WriteDelegate_tE9F20B5E1A664D239EFDD91143B963A216AAB1C7*>(delegatesToInvoke[i]);
		typedef void (*FunctionPointerType) (RuntimeObject*, Vector2Int_t69B2886EBAB732D9B880565E18E7568F3DE0CE6A*, int32_t, const RuntimeMethod*);
		((FunctionPointerType)currentDelegate->___invoke_impl)((Il2CppObject*)currentDelegate->___method_code, ___0_val, ___1_fieldValue, reinterpret_cast<RuntimeMethod*>(currentDelegate->___method));
	}
}
void WriteDelegate_Invoke_mDCBB3FCC716BDB01FBB6A93055CB254FEFF466CA_OpenInst(WriteDelegate_tE9F20B5E1A664D239EFDD91143B963A216AAB1C7* __this, Vector2Int_t69B2886EBAB732D9B880565E18E7568F3DE0CE6A* ___0_val, int32_t ___1_fieldValue, const RuntimeMethod* method)
{
	typedef void (*FunctionPointerType) (Vector2Int_t69B2886EBAB732D9B880565E18E7568F3DE0CE6A*, int32_t, const RuntimeMethod*);
	((FunctionPointerType)__this->___method_ptr)(___0_val, ___1_fieldValue, method);
}
void WriteDelegate_Invoke_mDCBB3FCC716BDB01FBB6A93055CB254FEFF466CA_OpenStatic(WriteDelegate_tE9F20B5E1A664D239EFDD91143B963A216AAB1C7* __this, Vector2Int_t69B2886EBAB732D9B880565E18E7568F3DE0CE6A* ___0_val, int32_t ___1_fieldValue, const RuntimeMethod* method)
{
	typedef void (*FunctionPointerType) (Vector2Int_t69B2886EBAB732D9B880565E18E7568F3DE0CE6A*, int32_t, const RuntimeMethod*);
	((FunctionPointerType)__this->___method_ptr)(___0_val, ___1_fieldValue, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WriteDelegate__ctor_m1067E857FEE330354C23F3DB8C7B30143BCA679D_gshared (WriteDelegate_tE9F20B5E1A664D239EFDD91143B963A216AAB1C7* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method) 
{
	__this->___method_ptr = (intptr_t)il2cpp_codegen_get_method_pointer((RuntimeMethod*)___1_method);
	__this->___method = ___1_method;
	__this->___m_target = ___0_object;
	Il2CppCodeGenWriteBarrier((void**)(&__this->___m_target), (void*)___0_object);
	int parameterCount = il2cpp_codegen_method_parameter_count((RuntimeMethod*)___1_method);
	__this->___method_code = (intptr_t)__this;
	if (MethodIsStatic((RuntimeMethod*)___1_method))
	{
		bool isOpen = parameterCount == 2;
		if (isOpen)
			__this->___invoke_impl = (intptr_t)&WriteDelegate_Invoke_mDCBB3FCC716BDB01FBB6A93055CB254FEFF466CA_OpenStatic;
		else
			{
				__this->___invoke_impl = __this->___method_ptr;
				__this->___method_code = (intptr_t)__this->___m_target;
			}
	}
	else
	{
		bool isOpen = parameterCount == 1;
		if (isOpen)
		{
			__this->___invoke_impl = (intptr_t)&WriteDelegate_Invoke_mDCBB3FCC716BDB01FBB6A93055CB254FEFF466CA_OpenInst;
		}
		else
		{
			if (___0_object == NULL)
				il2cpp_codegen_raise_exception(il2cpp_codegen_get_argument_exception(NULL, "Delegate to an instance method cannot have null 'this'."), NULL);
			__this->___invoke_impl = __this->___method_ptr;
			__this->___method_code = (intptr_t)__this->___m_target;
		}
	}
	__this->___extra_arg = (intptr_t)&WriteDelegate_Invoke_mDCBB3FCC716BDB01FBB6A93055CB254FEFF466CA_Multicast;
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WriteDelegate_Invoke_mDCBB3FCC716BDB01FBB6A93055CB254FEFF466CA_gshared (WriteDelegate_tE9F20B5E1A664D239EFDD91143B963A216AAB1C7* __this, Vector2Int_t69B2886EBAB732D9B880565E18E7568F3DE0CE6A* ___0_val, int32_t ___1_fieldValue, const RuntimeMethod* method) 
{
	typedef void (*FunctionPointerType) (RuntimeObject*, Vector2Int_t69B2886EBAB732D9B880565E18E7568F3DE0CE6A*, int32_t, const RuntimeMethod*);
	((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_val, ___1_fieldValue, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
void WriteDelegate_Invoke_m78604525C7D756C919B71D80FE8B7C42684A0F60_Multicast(WriteDelegate_t023838BBDB83C818E9FDC98ABFA9A9396823E789* __this, Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2* ___0_val, float ___1_fieldValue, const RuntimeMethod* method)
{
	il2cpp_array_size_t length = __this->___delegates->max_length;
	Delegate_t** delegatesToInvoke = reinterpret_cast<Delegate_t**>(__this->___delegates->GetAddressAtUnchecked(0));
	for (il2cpp_array_size_t i = 0; i < length; i++)
	{
		WriteDelegate_t023838BBDB83C818E9FDC98ABFA9A9396823E789* currentDelegate = reinterpret_cast<WriteDelegate_t023838BBDB83C818E9FDC98ABFA9A9396823E789*>(delegatesToInvoke[i]);
		typedef void (*FunctionPointerType) (RuntimeObject*, Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2*, float, const RuntimeMethod*);
		((FunctionPointerType)currentDelegate->___invoke_impl)((Il2CppObject*)currentDelegate->___method_code, ___0_val, ___1_fieldValue, reinterpret_cast<RuntimeMethod*>(currentDelegate->___method));
	}
}
void WriteDelegate_Invoke_m78604525C7D756C919B71D80FE8B7C42684A0F60_OpenInst(WriteDelegate_t023838BBDB83C818E9FDC98ABFA9A9396823E789* __this, Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2* ___0_val, float ___1_fieldValue, const RuntimeMethod* method)
{
	typedef void (*FunctionPointerType) (Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2*, float, const RuntimeMethod*);
	((FunctionPointerType)__this->___method_ptr)(___0_val, ___1_fieldValue, method);
}
void WriteDelegate_Invoke_m78604525C7D756C919B71D80FE8B7C42684A0F60_OpenStatic(WriteDelegate_t023838BBDB83C818E9FDC98ABFA9A9396823E789* __this, Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2* ___0_val, float ___1_fieldValue, const RuntimeMethod* method)
{
	typedef void (*FunctionPointerType) (Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2*, float, const RuntimeMethod*);
	((FunctionPointerType)__this->___method_ptr)(___0_val, ___1_fieldValue, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WriteDelegate__ctor_mC9073752A9F993A89037EB0FCF8968BCB14AE3A3_gshared (WriteDelegate_t023838BBDB83C818E9FDC98ABFA9A9396823E789* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method) 
{
	__this->___method_ptr = (intptr_t)il2cpp_codegen_get_method_pointer((RuntimeMethod*)___1_method);
	__this->___method = ___1_method;
	__this->___m_target = ___0_object;
	Il2CppCodeGenWriteBarrier((void**)(&__this->___m_target), (void*)___0_object);
	int parameterCount = il2cpp_codegen_method_parameter_count((RuntimeMethod*)___1_method);
	__this->___method_code = (intptr_t)__this;
	if (MethodIsStatic((RuntimeMethod*)___1_method))
	{
		bool isOpen = parameterCount == 2;
		if (isOpen)
			__this->___invoke_impl = (intptr_t)&WriteDelegate_Invoke_m78604525C7D756C919B71D80FE8B7C42684A0F60_OpenStatic;
		else
			{
				__this->___invoke_impl = __this->___method_ptr;
				__this->___method_code = (intptr_t)__this->___m_target;
			}
	}
	else
	{
		bool isOpen = parameterCount == 1;
		if (isOpen)
		{
			__this->___invoke_impl = (intptr_t)&WriteDelegate_Invoke_m78604525C7D756C919B71D80FE8B7C42684A0F60_OpenInst;
		}
		else
		{
			if (___0_object == NULL)
				il2cpp_codegen_raise_exception(il2cpp_codegen_get_argument_exception(NULL, "Delegate to an instance method cannot have null 'this'."), NULL);
			__this->___invoke_impl = __this->___method_ptr;
			__this->___method_code = (intptr_t)__this->___m_target;
		}
	}
	__this->___extra_arg = (intptr_t)&WriteDelegate_Invoke_m78604525C7D756C919B71D80FE8B7C42684A0F60_Multicast;
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WriteDelegate_Invoke_m78604525C7D756C919B71D80FE8B7C42684A0F60_gshared (WriteDelegate_t023838BBDB83C818E9FDC98ABFA9A9396823E789* __this, Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2* ___0_val, float ___1_fieldValue, const RuntimeMethod* method) 
{
	typedef void (*FunctionPointerType) (RuntimeObject*, Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2*, float, const RuntimeMethod*);
	((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_val, ___1_fieldValue, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
void WriteDelegate_Invoke_m86B402A7CEAB3ADDAB046D1975023F53BFB4E878_Multicast(WriteDelegate_t98EF2EAAD5827503FF2F0213C32A4961968D75A0* __this, Vector3Int_t65CB06F557251D18A37BD71F3655BA836A357376* ___0_val, int32_t ___1_fieldValue, const RuntimeMethod* method)
{
	il2cpp_array_size_t length = __this->___delegates->max_length;
	Delegate_t** delegatesToInvoke = reinterpret_cast<Delegate_t**>(__this->___delegates->GetAddressAtUnchecked(0));
	for (il2cpp_array_size_t i = 0; i < length; i++)
	{
		WriteDelegate_t98EF2EAAD5827503FF2F0213C32A4961968D75A0* currentDelegate = reinterpret_cast<WriteDelegate_t98EF2EAAD5827503FF2F0213C32A4961968D75A0*>(delegatesToInvoke[i]);
		typedef void (*FunctionPointerType) (RuntimeObject*, Vector3Int_t65CB06F557251D18A37BD71F3655BA836A357376*, int32_t, const RuntimeMethod*);
		((FunctionPointerType)currentDelegate->___invoke_impl)((Il2CppObject*)currentDelegate->___method_code, ___0_val, ___1_fieldValue, reinterpret_cast<RuntimeMethod*>(currentDelegate->___method));
	}
}
void WriteDelegate_Invoke_m86B402A7CEAB3ADDAB046D1975023F53BFB4E878_OpenInst(WriteDelegate_t98EF2EAAD5827503FF2F0213C32A4961968D75A0* __this, Vector3Int_t65CB06F557251D18A37BD71F3655BA836A357376* ___0_val, int32_t ___1_fieldValue, const RuntimeMethod* method)
{
	typedef void (*FunctionPointerType) (Vector3Int_t65CB06F557251D18A37BD71F3655BA836A357376*, int32_t, const RuntimeMethod*);
	((FunctionPointerType)__this->___method_ptr)(___0_val, ___1_fieldValue, method);
}
void WriteDelegate_Invoke_m86B402A7CEAB3ADDAB046D1975023F53BFB4E878_OpenStatic(WriteDelegate_t98EF2EAAD5827503FF2F0213C32A4961968D75A0* __this, Vector3Int_t65CB06F557251D18A37BD71F3655BA836A357376* ___0_val, int32_t ___1_fieldValue, const RuntimeMethod* method)
{
	typedef void (*FunctionPointerType) (Vector3Int_t65CB06F557251D18A37BD71F3655BA836A357376*, int32_t, const RuntimeMethod*);
	((FunctionPointerType)__this->___method_ptr)(___0_val, ___1_fieldValue, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WriteDelegate__ctor_mAA1CB4066F7346F24DA38ED5A1240309F0C4BC60_gshared (WriteDelegate_t98EF2EAAD5827503FF2F0213C32A4961968D75A0* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method) 
{
	__this->___method_ptr = (intptr_t)il2cpp_codegen_get_method_pointer((RuntimeMethod*)___1_method);
	__this->___method = ___1_method;
	__this->___m_target = ___0_object;
	Il2CppCodeGenWriteBarrier((void**)(&__this->___m_target), (void*)___0_object);
	int parameterCount = il2cpp_codegen_method_parameter_count((RuntimeMethod*)___1_method);
	__this->___method_code = (intptr_t)__this;
	if (MethodIsStatic((RuntimeMethod*)___1_method))
	{
		bool isOpen = parameterCount == 2;
		if (isOpen)
			__this->___invoke_impl = (intptr_t)&WriteDelegate_Invoke_m86B402A7CEAB3ADDAB046D1975023F53BFB4E878_OpenStatic;
		else
			{
				__this->___invoke_impl = __this->___method_ptr;
				__this->___method_code = (intptr_t)__this->___m_target;
			}
	}
	else
	{
		bool isOpen = parameterCount == 1;
		if (isOpen)
		{
			__this->___invoke_impl = (intptr_t)&WriteDelegate_Invoke_m86B402A7CEAB3ADDAB046D1975023F53BFB4E878_OpenInst;
		}
		else
		{
			if (___0_object == NULL)
				il2cpp_codegen_raise_exception(il2cpp_codegen_get_argument_exception(NULL, "Delegate to an instance method cannot have null 'this'."), NULL);
			__this->___invoke_impl = __this->___method_ptr;
			__this->___method_code = (intptr_t)__this->___m_target;
		}
	}
	__this->___extra_arg = (intptr_t)&WriteDelegate_Invoke_m86B402A7CEAB3ADDAB046D1975023F53BFB4E878_Multicast;
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WriteDelegate_Invoke_m86B402A7CEAB3ADDAB046D1975023F53BFB4E878_gshared (WriteDelegate_t98EF2EAAD5827503FF2F0213C32A4961968D75A0* __this, Vector3Int_t65CB06F557251D18A37BD71F3655BA836A357376* ___0_val, int32_t ___1_fieldValue, const RuntimeMethod* method) 
{
	typedef void (*FunctionPointerType) (RuntimeObject*, Vector3Int_t65CB06F557251D18A37BD71F3655BA836A357376*, int32_t, const RuntimeMethod*);
	((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_val, ___1_fieldValue, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
void WriteDelegate_Invoke_mCB317932D29E39DF2768AD06B5DA7A84CD3A2C16_Multicast(WriteDelegate_t055D02BADD3A5DFA009116D80BC93C235313CAE8* __this, Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3* ___0_val, float ___1_fieldValue, const RuntimeMethod* method)
{
	il2cpp_array_size_t length = __this->___delegates->max_length;
	Delegate_t** delegatesToInvoke = reinterpret_cast<Delegate_t**>(__this->___delegates->GetAddressAtUnchecked(0));
	for (il2cpp_array_size_t i = 0; i < length; i++)
	{
		WriteDelegate_t055D02BADD3A5DFA009116D80BC93C235313CAE8* currentDelegate = reinterpret_cast<WriteDelegate_t055D02BADD3A5DFA009116D80BC93C235313CAE8*>(delegatesToInvoke[i]);
		typedef void (*FunctionPointerType) (RuntimeObject*, Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3*, float, const RuntimeMethod*);
		((FunctionPointerType)currentDelegate->___invoke_impl)((Il2CppObject*)currentDelegate->___method_code, ___0_val, ___1_fieldValue, reinterpret_cast<RuntimeMethod*>(currentDelegate->___method));
	}
}
void WriteDelegate_Invoke_mCB317932D29E39DF2768AD06B5DA7A84CD3A2C16_OpenInst(WriteDelegate_t055D02BADD3A5DFA009116D80BC93C235313CAE8* __this, Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3* ___0_val, float ___1_fieldValue, const RuntimeMethod* method)
{
	typedef void (*FunctionPointerType) (Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3*, float, const RuntimeMethod*);
	((FunctionPointerType)__this->___method_ptr)(___0_val, ___1_fieldValue, method);
}
void WriteDelegate_Invoke_mCB317932D29E39DF2768AD06B5DA7A84CD3A2C16_OpenStatic(WriteDelegate_t055D02BADD3A5DFA009116D80BC93C235313CAE8* __this, Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3* ___0_val, float ___1_fieldValue, const RuntimeMethod* method)
{
	typedef void (*FunctionPointerType) (Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3*, float, const RuntimeMethod*);
	((FunctionPointerType)__this->___method_ptr)(___0_val, ___1_fieldValue, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WriteDelegate__ctor_m6165AFE856EC0CC9CDE8A145B404312481261696_gshared (WriteDelegate_t055D02BADD3A5DFA009116D80BC93C235313CAE8* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method) 
{
	__this->___method_ptr = (intptr_t)il2cpp_codegen_get_method_pointer((RuntimeMethod*)___1_method);
	__this->___method = ___1_method;
	__this->___m_target = ___0_object;
	Il2CppCodeGenWriteBarrier((void**)(&__this->___m_target), (void*)___0_object);
	int parameterCount = il2cpp_codegen_method_parameter_count((RuntimeMethod*)___1_method);
	__this->___method_code = (intptr_t)__this;
	if (MethodIsStatic((RuntimeMethod*)___1_method))
	{
		bool isOpen = parameterCount == 2;
		if (isOpen)
			__this->___invoke_impl = (intptr_t)&WriteDelegate_Invoke_mCB317932D29E39DF2768AD06B5DA7A84CD3A2C16_OpenStatic;
		else
			{
				__this->___invoke_impl = __this->___method_ptr;
				__this->___method_code = (intptr_t)__this->___m_target;
			}
	}
	else
	{
		bool isOpen = parameterCount == 1;
		if (isOpen)
		{
			__this->___invoke_impl = (intptr_t)&WriteDelegate_Invoke_mCB317932D29E39DF2768AD06B5DA7A84CD3A2C16_OpenInst;
		}
		else
		{
			if (___0_object == NULL)
				il2cpp_codegen_raise_exception(il2cpp_codegen_get_argument_exception(NULL, "Delegate to an instance method cannot have null 'this'."), NULL);
			__this->___invoke_impl = __this->___method_ptr;
			__this->___method_code = (intptr_t)__this->___m_target;
		}
	}
	__this->___extra_arg = (intptr_t)&WriteDelegate_Invoke_mCB317932D29E39DF2768AD06B5DA7A84CD3A2C16_Multicast;
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WriteDelegate_Invoke_mCB317932D29E39DF2768AD06B5DA7A84CD3A2C16_gshared (WriteDelegate_t055D02BADD3A5DFA009116D80BC93C235313CAE8* __this, Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3* ___0_val, float ___1_fieldValue, const RuntimeMethod* method) 
{
	typedef void (*FunctionPointerType) (RuntimeObject*, Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3*, float, const RuntimeMethod*);
	((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_val, ___1_fieldValue, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
void WriteDelegate_Invoke_m314AB1F8889F277917B21F5F09093D797490FE93_Multicast(WriteDelegate_tCC7EDE8329D3D4B81ABF643CABCC600B2CC335D7* __this, Il2CppFullySharedGenericAny* ___0_val, Il2CppFullySharedGenericAny ___1_fieldValue, const RuntimeMethod* method)
{
	il2cpp_array_size_t length = __this->___delegates->max_length;
	Delegate_t** delegatesToInvoke = reinterpret_cast<Delegate_t**>(__this->___delegates->GetAddressAtUnchecked(0));
	for (il2cpp_array_size_t i = 0; i < length; i++)
	{
		WriteDelegate_tCC7EDE8329D3D4B81ABF643CABCC600B2CC335D7* currentDelegate = reinterpret_cast<WriteDelegate_tCC7EDE8329D3D4B81ABF643CABCC600B2CC335D7*>(delegatesToInvoke[i]);
		typedef void (*FunctionPointerType) (RuntimeObject*, Il2CppFullySharedGenericAny*, Il2CppFullySharedGenericAny, const RuntimeMethod*);
		((FunctionPointerType)currentDelegate->___invoke_impl)((Il2CppObject*)currentDelegate->___method_code, ___0_val, ___1_fieldValue, reinterpret_cast<RuntimeMethod*>(currentDelegate->___method));
	}
}
void WriteDelegate_Invoke_m314AB1F8889F277917B21F5F09093D797490FE93_OpenStaticInvoker(WriteDelegate_tCC7EDE8329D3D4B81ABF643CABCC600B2CC335D7* __this, Il2CppFullySharedGenericAny* ___0_val, Il2CppFullySharedGenericAny ___1_fieldValue, const RuntimeMethod* method)
{
	InvokerActionInvoker2< Il2CppFullySharedGenericAny*, Il2CppFullySharedGenericAny >::Invoke((Il2CppMethodPointer)__this->___method_ptr, method, NULL, ___0_val, ___1_fieldValue);
}
void WriteDelegate_Invoke_m314AB1F8889F277917B21F5F09093D797490FE93_ClosedStaticInvoker(WriteDelegate_tCC7EDE8329D3D4B81ABF643CABCC600B2CC335D7* __this, Il2CppFullySharedGenericAny* ___0_val, Il2CppFullySharedGenericAny ___1_fieldValue, const RuntimeMethod* method)
{
	InvokerActionInvoker3< RuntimeObject*, Il2CppFullySharedGenericAny*, Il2CppFullySharedGenericAny >::Invoke((Il2CppMethodPointer)__this->___method_ptr, method, NULL, __this->___m_target, ___0_val, ___1_fieldValue);
}
void WriteDelegate_Invoke_m314AB1F8889F277917B21F5F09093D797490FE93_ClosedInstInvoker(WriteDelegate_tCC7EDE8329D3D4B81ABF643CABCC600B2CC335D7* __this, Il2CppFullySharedGenericAny* ___0_val, Il2CppFullySharedGenericAny ___1_fieldValue, const RuntimeMethod* method)
{
	InvokerActionInvoker2< Il2CppFullySharedGenericAny*, Il2CppFullySharedGenericAny >::Invoke((Il2CppMethodPointer)__this->___method_ptr, method, __this->___m_target, ___0_val, ___1_fieldValue);
}
void WriteDelegate_Invoke_m314AB1F8889F277917B21F5F09093D797490FE93_OpenInstInvoker(WriteDelegate_tCC7EDE8329D3D4B81ABF643CABCC600B2CC335D7* __this, Il2CppFullySharedGenericAny* ___0_val, Il2CppFullySharedGenericAny ___1_fieldValue, const RuntimeMethod* method)
{
	NullCheck(___0_val);
	InvokerActionInvoker1< Il2CppFullySharedGenericAny >::Invoke((Il2CppMethodPointer)__this->___method_ptr, method, ___0_val, ___1_fieldValue);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WriteDelegate__ctor_mCE6F306923A685DD2E41E1BAABB666E0F7B4E137_gshared (WriteDelegate_tCC7EDE8329D3D4B81ABF643CABCC600B2CC335D7* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method) 
{
	__this->___method_ptr = (intptr_t)il2cpp_codegen_get_method_pointer((RuntimeMethod*)___1_method);
	__this->___method = ___1_method;
	__this->___m_target = ___0_object;
	Il2CppCodeGenWriteBarrier((void**)(&__this->___m_target), (void*)___0_object);
	int parameterCount = il2cpp_codegen_method_parameter_count((RuntimeMethod*)___1_method);
	__this->___method_code = (intptr_t)__this;
	if (MethodIsStatic((RuntimeMethod*)___1_method))
	{
		bool isOpen = parameterCount == 2;
		if (isOpen)
			__this->___invoke_impl = (intptr_t)&WriteDelegate_Invoke_m314AB1F8889F277917B21F5F09093D797490FE93_OpenStaticInvoker;
		else
			__this->___invoke_impl = (intptr_t)&WriteDelegate_Invoke_m314AB1F8889F277917B21F5F09093D797490FE93_ClosedStaticInvoker;
	}
	else
	{
		bool isOpen = parameterCount == 1;
		if (isOpen)
		{
			__this->___invoke_impl = (intptr_t)&WriteDelegate_Invoke_m314AB1F8889F277917B21F5F09093D797490FE93_OpenInstInvoker;
		}
		else
		{
			if (___0_object == NULL)
				il2cpp_codegen_raise_exception(il2cpp_codegen_get_argument_exception(NULL, "Delegate to an instance method cannot have null 'this'."), NULL);
			__this->___invoke_impl = (intptr_t)&WriteDelegate_Invoke_m314AB1F8889F277917B21F5F09093D797490FE93_ClosedInstInvoker;
		}
	}
	__this->___extra_arg = (intptr_t)&WriteDelegate_Invoke_m314AB1F8889F277917B21F5F09093D797490FE93_Multicast;
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WriteDelegate_Invoke_m314AB1F8889F277917B21F5F09093D797490FE93_gshared (WriteDelegate_tCC7EDE8329D3D4B81ABF643CABCC600B2CC335D7* __this, Il2CppFullySharedGenericAny* ___0_val, Il2CppFullySharedGenericAny ___1_fieldValue, const RuntimeMethod* method) 
{
	typedef void (*FunctionPointerType) (RuntimeObject*, Il2CppFullySharedGenericAny*, Il2CppFullySharedGenericAny, const RuntimeMethod*);
	((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_val, ___1_fieldValue, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void ValueTuple_1__ctor_m538A52BFBDA47CC5C05AEE670CAE9D0657D425CB_gshared_inline (ValueTuple_1_t8587BAAE6DE27A90339279F96A1B89714EE33EAF* __this, Il2CppFullySharedGenericAny ___0_item1, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T1_t104843BD74F7E6ADD698448FBE261AF8CF0637AB = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0));
	const Il2CppFullySharedGenericAny L_0 = alloca(SizeOf_T1_t104843BD74F7E6ADD698448FBE261AF8CF0637AB);
	{
		il2cpp_codegen_memcpy(L_0, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0)) ? ___0_item1 : &___0_item1), SizeOf_T1_t104843BD74F7E6ADD698448FBE261AF8CF0637AB);
		il2cpp_codegen_write_instance_field_data(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 1),0), L_0, SizeOf_T1_t104843BD74F7E6ADD698448FBE261AF8CF0637AB);
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void WhenEachResult_1_get_Result_m7C267B764B881AA53B7DFDCF94975161B9022DE8_gshared_inline (WhenEachResult_1_t56488B449B4BD9DA81B279363A63B1C123605F21* __this, Il2CppFullySharedGenericAny* il2cppRetVal, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T_tF8C17784C5288E922C2784A100DEEAD36B1E4619 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 1));
	const Il2CppFullySharedGenericAny L_0 = alloca(SizeOf_T_tF8C17784C5288E922C2784A100DEEAD36B1E4619);
	{
		il2cpp_codegen_memcpy(L_0, il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),0)), SizeOf_T_tF8C17784C5288E922C2784A100DEEAD36B1E4619);
		il2cpp_codegen_memcpy(il2cppRetVal, L_0, SizeOf_T_tF8C17784C5288E922C2784A100DEEAD36B1E4619);
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Exception_t* WhenEachResult_1_get_Exception_m1EC0B9E8E5D8C4AAAD9853628CC5BB8A4EFEF7E2_gshared_inline (WhenEachResult_1_t56488B449B4BD9DA81B279363A63B1C123605F21* __this, const RuntimeMethod* method) 
{
	{
		Exception_t* L_0 = *(Exception_t**)il2cpp_codegen_get_instance_field_data_pointer(__this, il2cpp_rgctx_field(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 0),1));
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Func_2_Invoke_m18A3A6EDA433C635C66C43DA6B86F7BC746BFDD0_gshared_inline (Func_2_t9364FA627D95BAC4CDA1FB83D8857B61F71B1858* __this, KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 ___0_arg, const RuntimeMethod* method) 
{
	typedef bool (*FunctionPointerType) (RuntimeObject*, KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_arg, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Func_2_Invoke_m095D2006A2DDB336987862DC15A7EFAED53E08EC_gshared_inline (Func_2_t1C8F983F9A1AA802D45E89037E2AA7ACD1094821* __this, int32_t ___0_arg, const RuntimeMethod* method) 
{
	typedef bool (*FunctionPointerType) (RuntimeObject*, int32_t, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_arg, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Func_2_Invoke_m2014423FB900F135C8FF994125604FF9E6AAE829_gshared_inline (Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* __this, RuntimeObject* ___0_arg, const RuntimeMethod* method) 
{
	typedef bool (*FunctionPointerType) (RuntimeObject*, RuntimeObject*, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_arg, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Func_2_Invoke_m92C683F52E538828B33BA3E1E37C285A7A73A744_gshared_inline (Func_2_t92F44173C14E7022E392A8FEA4374C3CD24578EF* __this, PlayerLoopSystem_t8AED6BF1C8A309CAA6FF71AC91DD33BDDFF7CF1F ___0_arg, const RuntimeMethod* method) 
{
	typedef bool (*FunctionPointerType) (RuntimeObject*, PlayerLoopSystem_t8AED6BF1C8A309CAA6FF71AC91DD33BDDFF7CF1F, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_arg, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Func_2_Invoke_mDDB42512D647D9FDCAD0330A12EDB64CAD533A99_gshared_inline (Func_2_tDBF8C754A8F1FC6DE54BB9904D2D81C266DFF6B4* __this, DictionaryEntry_t171080F37B311C25AA9E75888F9C9D703FA721BB ___0_arg, const RuntimeMethod* method) 
{
	typedef bool (*FunctionPointerType) (RuntimeObject*, DictionaryEntry_t171080F37B311C25AA9E75888F9C9D703FA721BB, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_arg, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Func_2_Invoke_m1543D7041BADF87D1F63EBF838B0DDCB40340C7E_gshared_inline (Func_2_t63A057E8762189D8C22BF71360D00C1047680DFA* __this, int32_t ___0_arg, const RuntimeMethod* method) 
{
	typedef bool (*FunctionPointerType) (RuntimeObject*, int32_t, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_arg, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 Enumerator_get_Current_m2E99DFD369025C91E4B23FA90EE17A41271106A4_gshared_inline (Enumerator_t81E3046D0BB629D86FAC325CBBF319731C3E36A4* __this, const RuntimeMethod* method) 
{
	{
		KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 L_0 = __this->____current;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Enumerator_get_Current_mB6A201CD563FEF33A6BDA75B83C7BF2AA36CD98C_gshared_inline (Enumerator_t6209EE23CCD16838DA331AC87789A15508C6C72B* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____current;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RuntimeObject* Enumerator_get_Current_m6330F15D18EE4F547C05DF9BF83C5EB710376027_gshared_inline (Enumerator_t9473BAB568A27E2339D48C1F91319E0F6D244D7A* __this, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = __this->____current;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR PlayerLoopSystem_t8AED6BF1C8A309CAA6FF71AC91DD33BDDFF7CF1F Enumerator_get_Current_m0B4ED9AF252261F8FAEF61A9A59B085B4CE88528_gshared_inline (Enumerator_tB025B2FCAB9376692902C91754C98265C07AEA9A* __this, const RuntimeMethod* method) 
{
	{
		PlayerLoopSystem_t8AED6BF1C8A309CAA6FF71AC91DD33BDDFF7CF1F L_0 = __this->____current;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR DictionaryEntry_t171080F37B311C25AA9E75888F9C9D703FA721BB Func_2_Invoke_mFDA9BF3EFEFF70ED1767096A0993BCF4E97414BF_gshared_inline (Func_2_t696684549FAB37B32A9C38A40F33DB777B757E69* __this, KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 ___0_arg, const RuntimeMethod* method) 
{
	typedef DictionaryEntry_t171080F37B311C25AA9E75888F9C9D703FA721BB (*FunctionPointerType) (RuntimeObject*, KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_arg, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Func_2_Invoke_m450153F6300275E6112B4346D2EF20A15EB7091E_gshared_inline (Func_2_tA526681EE526C81F376160E44520BDC21770A705* __this, KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 ___0_arg, const RuntimeMethod* method) 
{
	typedef int32_t (*FunctionPointerType) (RuntimeObject*, KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_arg, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RuntimeObject* Func_2_Invoke_m8EC2E5D1BEEA74F624F19C59924823693B9B39A5_gshared_inline (Func_2_tF42287527472FA89789873F068A87C60A00EC7D3* __this, KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230 ___0_arg, const RuntimeMethod* method) 
{
	typedef RuntimeObject* (*FunctionPointerType) (RuntimeObject*, KeyValuePair_2_tFC32D2507216293851350D29B64D79F950B55230, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_arg, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Func_2_Invoke_m1F8EE2DF137BE5132901C0297848BC7A373A676B_gshared_inline (Func_2_t2FDA873D8482C79555CFB05233D610E8F1C7C354* __this, int32_t ___0_arg, const RuntimeMethod* method) 
{
	typedef int32_t (*FunctionPointerType) (RuntimeObject*, int32_t, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_arg, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Func_2_Invoke_m5216F6C7BCECCCED81384876C2968E0D4358618B_gshared_inline (Func_2_t9A0D493A82DCC47C9C819A3B045E02D9B5DDCE1B* __this, RuntimeObject* ___0_arg, const RuntimeMethod* method) 
{
	typedef int32_t (*FunctionPointerType) (RuntimeObject*, RuntimeObject*, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_arg, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RuntimeObject* Func_2_Invoke_mDBA25DA5DA5B7E056FB9B026AF041F1385FB58A9_gshared_inline (Func_2_tACBF5A1656250800CE861707354491F0611F6624* __this, RuntimeObject* ___0_arg, const RuntimeMethod* method) 
{
	typedef RuntimeObject* (*FunctionPointerType) (RuntimeObject*, RuntimeObject*, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_arg, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Func_2_Invoke_m7C54973F594216484A4F81A59CDF821AF554339D_gshared_inline (Func_2_t7E7216694EE7A991563EC30D68D86C597BF2A56A* __this, StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 ___0_arg, const RuntimeMethod* method) 
{
	typedef bool (*FunctionPointerType) (RuntimeObject*, StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_arg, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Func_2_Invoke_m57961B138A397ADAB0DC71E56519ADBD63327D27_gshared_inline (Func_2_t12F902B64E731F36B1BC057F3AF13BF1D833E1DF* __this, StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 ___0_arg, const RuntimeMethod* method) 
{
	typedef int32_t (*FunctionPointerType) (RuntimeObject*, StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_arg, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RuntimeObject* Func_2_Invoke_m1F78C6C79382EA6E74D62E31DD00A9378266A518_gshared_inline (Func_2_tFD36EA818BBCBD1EDE1E1540FC3EF156A6ADCCAD* __this, StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 ___0_arg, const RuntimeMethod* method) 
{
	typedef RuntimeObject* (*FunctionPointerType) (RuntimeObject*, StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_arg, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Enumerator_get_Current_mB49912FF111A954F2C326BF4FA29A53C1027187B_gshared_inline (Enumerator_t9DBCD072C72E44AB8959D9884EF7F528028F20EC* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____current;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 Enumerator_get_Current_m4E279E6389EB06C5DBE88A74E3BD3F23FB2B17E4_gshared_inline (Enumerator_t55FB90597665ED8BB37C633F6FD72EFAD48FE20F* __this, const RuntimeMethod* method) 
{
	{
		StyleSelectorPart_tEE5B8ADC7D114C7486CC8301FF96C114FF3C9470 L_0 = __this->____current;
		return L_0;
	}
}
