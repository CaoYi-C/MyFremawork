using System.Collections.Generic;
public class AOTGenericReferences : UnityEngine.MonoBehaviour
{

	// {{ AOT assemblies
	public static readonly IReadOnlyList<string> PatchedAOTAssemblyList = new List<string>
	{
		"System.Core.dll",
		"UniTask.dll",
		"UnityEngine.CoreModule.dll",
		"YooAsset.dll",
		"mscorlib.dll",
	};
	// }}

	// {{ constraint implement type
	// }} 

	// {{ AOT generic types
	// Cysharp.Threading.Tasks.CompilerServices.AsyncUniTask.<>c<object,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>
	// Cysharp.Threading.Tasks.CompilerServices.AsyncUniTask.<>c<object>
	// Cysharp.Threading.Tasks.CompilerServices.AsyncUniTask<object,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>
	// Cysharp.Threading.Tasks.CompilerServices.AsyncUniTask<object>
	// Cysharp.Threading.Tasks.CompilerServices.AsyncUniTaskMethodBuilder<System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>
	// Cysharp.Threading.Tasks.CompilerServices.IStateMachineRunnerPromise<System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>
	// Cysharp.Threading.Tasks.ITaskPoolNode<object>
	// Cysharp.Threading.Tasks.IUniTaskSource<System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>
	// Cysharp.Threading.Tasks.IUniTaskSource<System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>
	// Cysharp.Threading.Tasks.IUniTaskSource<System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>
	// Cysharp.Threading.Tasks.IUniTaskSource<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>
	// Cysharp.Threading.Tasks.IUniTaskSource<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>
	// Cysharp.Threading.Tasks.IUniTaskSource<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>
	// Cysharp.Threading.Tasks.IUniTaskSource<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>>
	// Cysharp.Threading.Tasks.IUniTaskSource<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>>>
	// Cysharp.Threading.Tasks.IUniTaskSource<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>>>>
	// Cysharp.Threading.Tasks.IUniTaskSource<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>>>>>
	// Cysharp.Threading.Tasks.UniTask.Awaiter<System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>
	// Cysharp.Threading.Tasks.UniTask.Awaiter<System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>
	// Cysharp.Threading.Tasks.UniTask.Awaiter<System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>
	// Cysharp.Threading.Tasks.UniTask.Awaiter<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>
	// Cysharp.Threading.Tasks.UniTask.Awaiter<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>
	// Cysharp.Threading.Tasks.UniTask.Awaiter<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>
	// Cysharp.Threading.Tasks.UniTask.Awaiter<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>>
	// Cysharp.Threading.Tasks.UniTask.Awaiter<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>>>
	// Cysharp.Threading.Tasks.UniTask.Awaiter<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>>>>
	// Cysharp.Threading.Tasks.UniTask.Awaiter<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>>>>>
	// Cysharp.Threading.Tasks.UniTask.IsCanceledSource<System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>
	// Cysharp.Threading.Tasks.UniTask.IsCanceledSource<System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>
	// Cysharp.Threading.Tasks.UniTask.IsCanceledSource<System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>
	// Cysharp.Threading.Tasks.UniTask.IsCanceledSource<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>
	// Cysharp.Threading.Tasks.UniTask.IsCanceledSource<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>
	// Cysharp.Threading.Tasks.UniTask.IsCanceledSource<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>
	// Cysharp.Threading.Tasks.UniTask.IsCanceledSource<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>>
	// Cysharp.Threading.Tasks.UniTask.IsCanceledSource<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>>>
	// Cysharp.Threading.Tasks.UniTask.IsCanceledSource<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>>>>
	// Cysharp.Threading.Tasks.UniTask.IsCanceledSource<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>>>>>
	// Cysharp.Threading.Tasks.UniTask.MemoizeSource<System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>
	// Cysharp.Threading.Tasks.UniTask.MemoizeSource<System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>
	// Cysharp.Threading.Tasks.UniTask.MemoizeSource<System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>
	// Cysharp.Threading.Tasks.UniTask.MemoizeSource<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>
	// Cysharp.Threading.Tasks.UniTask.MemoizeSource<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>
	// Cysharp.Threading.Tasks.UniTask.MemoizeSource<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>
	// Cysharp.Threading.Tasks.UniTask.MemoizeSource<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>>
	// Cysharp.Threading.Tasks.UniTask.MemoizeSource<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>>>
	// Cysharp.Threading.Tasks.UniTask.MemoizeSource<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>>>>
	// Cysharp.Threading.Tasks.UniTask.MemoizeSource<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>>>>>
	// Cysharp.Threading.Tasks.UniTask<System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>
	// Cysharp.Threading.Tasks.UniTask<System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>
	// Cysharp.Threading.Tasks.UniTask<System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>
	// Cysharp.Threading.Tasks.UniTask<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>
	// Cysharp.Threading.Tasks.UniTask<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>
	// Cysharp.Threading.Tasks.UniTask<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>
	// Cysharp.Threading.Tasks.UniTask<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>>
	// Cysharp.Threading.Tasks.UniTask<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>>>
	// Cysharp.Threading.Tasks.UniTask<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>>>>
	// Cysharp.Threading.Tasks.UniTask<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>>>>>
	// Cysharp.Threading.Tasks.UniTask<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>>>>>>
	// Cysharp.Threading.Tasks.UniTaskCompletionSourceCore<Cysharp.Threading.Tasks.AsyncUnit>
	// Cysharp.Threading.Tasks.UniTaskCompletionSourceCore<System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>
	// System.Action<object,object>
	// System.Action<object>
	// System.Collections.Generic.ArraySortHelper<object>
	// System.Collections.Generic.Comparer<System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>
	// System.Collections.Generic.Comparer<System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>
	// System.Collections.Generic.Comparer<System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>
	// System.Collections.Generic.Comparer<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>
	// System.Collections.Generic.Comparer<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>
	// System.Collections.Generic.Comparer<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>
	// System.Collections.Generic.Comparer<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>>
	// System.Collections.Generic.Comparer<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>>>
	// System.Collections.Generic.Comparer<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>>>>
	// System.Collections.Generic.Comparer<byte>
	// System.Collections.Generic.Comparer<object>
	// System.Collections.Generic.Dictionary.Enumerator<int,object>
	// System.Collections.Generic.Dictionary.Enumerator<object,object>
	// System.Collections.Generic.Dictionary.KeyCollection.Enumerator<int,object>
	// System.Collections.Generic.Dictionary.KeyCollection.Enumerator<object,object>
	// System.Collections.Generic.Dictionary.KeyCollection<int,object>
	// System.Collections.Generic.Dictionary.KeyCollection<object,object>
	// System.Collections.Generic.Dictionary.ValueCollection.Enumerator<int,object>
	// System.Collections.Generic.Dictionary.ValueCollection.Enumerator<object,object>
	// System.Collections.Generic.Dictionary.ValueCollection<int,object>
	// System.Collections.Generic.Dictionary.ValueCollection<object,object>
	// System.Collections.Generic.Dictionary<int,object>
	// System.Collections.Generic.Dictionary<object,object>
	// System.Collections.Generic.EqualityComparer<System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>
	// System.Collections.Generic.EqualityComparer<System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>
	// System.Collections.Generic.EqualityComparer<System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>
	// System.Collections.Generic.EqualityComparer<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>
	// System.Collections.Generic.EqualityComparer<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>
	// System.Collections.Generic.EqualityComparer<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>
	// System.Collections.Generic.EqualityComparer<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>>
	// System.Collections.Generic.EqualityComparer<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>>>
	// System.Collections.Generic.EqualityComparer<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>>>>
	// System.Collections.Generic.EqualityComparer<byte>
	// System.Collections.Generic.EqualityComparer<int>
	// System.Collections.Generic.EqualityComparer<object>
	// System.Collections.Generic.ICollection<System.Collections.Generic.KeyValuePair<int,object>>
	// System.Collections.Generic.ICollection<System.Collections.Generic.KeyValuePair<object,object>>
	// System.Collections.Generic.ICollection<object>
	// System.Collections.Generic.IComparer<object>
	// System.Collections.Generic.IEnumerable<System.Collections.Generic.KeyValuePair<int,object>>
	// System.Collections.Generic.IEnumerable<System.Collections.Generic.KeyValuePair<object,object>>
	// System.Collections.Generic.IEnumerable<object>
	// System.Collections.Generic.IEnumerator<System.Collections.Generic.KeyValuePair<int,object>>
	// System.Collections.Generic.IEnumerator<System.Collections.Generic.KeyValuePair<object,object>>
	// System.Collections.Generic.IEnumerator<object>
	// System.Collections.Generic.IEqualityComparer<int>
	// System.Collections.Generic.IEqualityComparer<object>
	// System.Collections.Generic.IList<object>
	// System.Collections.Generic.KeyValuePair<int,object>
	// System.Collections.Generic.KeyValuePair<object,object>
	// System.Collections.Generic.List.Enumerator<object>
	// System.Collections.Generic.List<object>
	// System.Collections.Generic.ObjectComparer<System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>
	// System.Collections.Generic.ObjectComparer<System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>
	// System.Collections.Generic.ObjectComparer<System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>
	// System.Collections.Generic.ObjectComparer<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>
	// System.Collections.Generic.ObjectComparer<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>
	// System.Collections.Generic.ObjectComparer<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>
	// System.Collections.Generic.ObjectComparer<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>>
	// System.Collections.Generic.ObjectComparer<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>>>
	// System.Collections.Generic.ObjectComparer<byte>
	// System.Collections.Generic.ObjectComparer<object>
	// System.Collections.Generic.ObjectEqualityComparer<System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>
	// System.Collections.Generic.ObjectEqualityComparer<System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>
	// System.Collections.Generic.ObjectEqualityComparer<System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>
	// System.Collections.Generic.ObjectEqualityComparer<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>
	// System.Collections.Generic.ObjectEqualityComparer<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>
	// System.Collections.Generic.ObjectEqualityComparer<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>
	// System.Collections.Generic.ObjectEqualityComparer<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>>
	// System.Collections.Generic.ObjectEqualityComparer<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>>>
	// System.Collections.Generic.ObjectEqualityComparer<byte>
	// System.Collections.Generic.ObjectEqualityComparer<int>
	// System.Collections.Generic.ObjectEqualityComparer<object>
	// System.Collections.ObjectModel.ReadOnlyCollection<object>
	// System.Comparison<object>
	// System.Func<System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>
	// System.Func<System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>
	// System.Func<System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>
	// System.Func<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>
	// System.Func<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>
	// System.Func<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>
	// System.Func<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>>
	// System.Func<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>>>
	// System.Func<int>
	// System.Func<object,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>
	// System.Func<object,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>
	// System.Func<object,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>
	// System.Func<object,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>
	// System.Func<object,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>
	// System.Func<object,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>
	// System.Func<object,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>>
	// System.Func<object,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>>>
	// System.Func<object,byte>
	// System.Func<object,object>
	// System.Linq.Enumerable.<SelectManyIterator>d__17<object,object>
	// System.Linq.Enumerable.Iterator<object>
	// System.Linq.Enumerable.WhereArrayIterator<object>
	// System.Linq.Enumerable.WhereEnumerableIterator<object>
	// System.Linq.Enumerable.WhereListIterator<object>
	// System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>
	// System.Predicate<object>
	// System.Runtime.CompilerServices.AsyncTaskMethodBuilder<System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>
	// System.Runtime.CompilerServices.AsyncTaskMethodBuilder<System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>
	// System.Runtime.CompilerServices.AsyncTaskMethodBuilder<System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>
	// System.Runtime.CompilerServices.AsyncTaskMethodBuilder<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>
	// System.Runtime.CompilerServices.AsyncTaskMethodBuilder<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>
	// System.Runtime.CompilerServices.AsyncTaskMethodBuilder<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>
	// System.Runtime.CompilerServices.AsyncTaskMethodBuilder<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>>
	// System.Runtime.CompilerServices.AsyncTaskMethodBuilder<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>>>
	// System.Runtime.CompilerServices.AsyncTaskMethodBuilder<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>>>>
	// System.Runtime.CompilerServices.ConfiguredTaskAwaitable.ConfiguredTaskAwaiter<System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>
	// System.Runtime.CompilerServices.ConfiguredTaskAwaitable.ConfiguredTaskAwaiter<System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>
	// System.Runtime.CompilerServices.ConfiguredTaskAwaitable.ConfiguredTaskAwaiter<System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>
	// System.Runtime.CompilerServices.ConfiguredTaskAwaitable.ConfiguredTaskAwaiter<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>
	// System.Runtime.CompilerServices.ConfiguredTaskAwaitable.ConfiguredTaskAwaiter<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>
	// System.Runtime.CompilerServices.ConfiguredTaskAwaitable.ConfiguredTaskAwaiter<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>
	// System.Runtime.CompilerServices.ConfiguredTaskAwaitable.ConfiguredTaskAwaiter<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>>
	// System.Runtime.CompilerServices.ConfiguredTaskAwaitable<System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>
	// System.Runtime.CompilerServices.ConfiguredTaskAwaitable<System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>
	// System.Runtime.CompilerServices.ConfiguredTaskAwaitable<System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>
	// System.Runtime.CompilerServices.ConfiguredTaskAwaitable<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>
	// System.Runtime.CompilerServices.ConfiguredTaskAwaitable<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>
	// System.Runtime.CompilerServices.ConfiguredTaskAwaitable<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>
	// System.Runtime.CompilerServices.ConfiguredTaskAwaitable<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>>
	// System.Runtime.CompilerServices.ConfiguredTaskAwaitable<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>>>
	// System.Runtime.CompilerServices.ConfiguredValueTaskAwaitable.ConfiguredValueTaskAwaiter<System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>
	// System.Runtime.CompilerServices.ConfiguredValueTaskAwaitable.ConfiguredValueTaskAwaiter<System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>
	// System.Runtime.CompilerServices.ConfiguredValueTaskAwaitable.ConfiguredValueTaskAwaiter<System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>
	// System.Runtime.CompilerServices.ConfiguredValueTaskAwaitable.ConfiguredValueTaskAwaiter<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>
	// System.Runtime.CompilerServices.ConfiguredValueTaskAwaitable.ConfiguredValueTaskAwaiter<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>
	// System.Runtime.CompilerServices.ConfiguredValueTaskAwaitable.ConfiguredValueTaskAwaiter<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>
	// System.Runtime.CompilerServices.ConfiguredValueTaskAwaitable.ConfiguredValueTaskAwaiter<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>>
	// System.Runtime.CompilerServices.ConfiguredValueTaskAwaitable.ConfiguredValueTaskAwaiter<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>>>
	// System.Runtime.CompilerServices.ConfiguredValueTaskAwaitable<System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>
	// System.Runtime.CompilerServices.ConfiguredValueTaskAwaitable<System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>
	// System.Runtime.CompilerServices.ConfiguredValueTaskAwaitable<System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>
	// System.Runtime.CompilerServices.ConfiguredValueTaskAwaitable<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>
	// System.Runtime.CompilerServices.ConfiguredValueTaskAwaitable<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>
	// System.Runtime.CompilerServices.ConfiguredValueTaskAwaitable<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>
	// System.Runtime.CompilerServices.ConfiguredValueTaskAwaitable<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>>
	// System.Runtime.CompilerServices.ConfiguredValueTaskAwaitable<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>>>
	// System.Runtime.CompilerServices.ConfiguredValueTaskAwaitable<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>>>>
	// System.Runtime.CompilerServices.TaskAwaiter<System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>
	// System.Runtime.CompilerServices.TaskAwaiter<System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>
	// System.Runtime.CompilerServices.TaskAwaiter<System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>
	// System.Runtime.CompilerServices.TaskAwaiter<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>
	// System.Runtime.CompilerServices.TaskAwaiter<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>
	// System.Runtime.CompilerServices.TaskAwaiter<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>
	// System.Runtime.CompilerServices.TaskAwaiter<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>>
	// System.Runtime.CompilerServices.TaskAwaiter<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>>>
	// System.Runtime.CompilerServices.ValueTaskAwaiter<System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>
	// System.Runtime.CompilerServices.ValueTaskAwaiter<System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>
	// System.Runtime.CompilerServices.ValueTaskAwaiter<System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>
	// System.Runtime.CompilerServices.ValueTaskAwaiter<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>
	// System.Runtime.CompilerServices.ValueTaskAwaiter<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>
	// System.Runtime.CompilerServices.ValueTaskAwaiter<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>
	// System.Runtime.CompilerServices.ValueTaskAwaiter<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>>
	// System.Runtime.CompilerServices.ValueTaskAwaiter<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>>>
	// System.Runtime.CompilerServices.ValueTaskAwaiter<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>>>>
	// System.Threading.Tasks.ContinuationTaskFromResultTask<System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>
	// System.Threading.Tasks.ContinuationTaskFromResultTask<System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>
	// System.Threading.Tasks.ContinuationTaskFromResultTask<System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>
	// System.Threading.Tasks.ContinuationTaskFromResultTask<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>
	// System.Threading.Tasks.ContinuationTaskFromResultTask<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>
	// System.Threading.Tasks.ContinuationTaskFromResultTask<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>
	// System.Threading.Tasks.ContinuationTaskFromResultTask<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>>
	// System.Threading.Tasks.ContinuationTaskFromResultTask<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>>>
	// System.Threading.Tasks.Sources.IValueTaskSource<System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>
	// System.Threading.Tasks.Sources.IValueTaskSource<System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>
	// System.Threading.Tasks.Sources.IValueTaskSource<System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>
	// System.Threading.Tasks.Sources.IValueTaskSource<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>
	// System.Threading.Tasks.Sources.IValueTaskSource<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>
	// System.Threading.Tasks.Sources.IValueTaskSource<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>
	// System.Threading.Tasks.Sources.IValueTaskSource<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>>
	// System.Threading.Tasks.Sources.IValueTaskSource<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>>>
	// System.Threading.Tasks.Sources.IValueTaskSource<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>>>>
	// System.Threading.Tasks.Task<System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>
	// System.Threading.Tasks.Task<System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>
	// System.Threading.Tasks.Task<System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>
	// System.Threading.Tasks.Task<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>
	// System.Threading.Tasks.Task<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>
	// System.Threading.Tasks.Task<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>
	// System.Threading.Tasks.Task<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>>
	// System.Threading.Tasks.Task<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>>>
	// System.Threading.Tasks.Task<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>>>>
	// System.Threading.Tasks.ValueTask.ValueTaskSourceAsTask.<>c<System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>
	// System.Threading.Tasks.ValueTask.ValueTaskSourceAsTask.<>c<System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>
	// System.Threading.Tasks.ValueTask.ValueTaskSourceAsTask.<>c<System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>
	// System.Threading.Tasks.ValueTask.ValueTaskSourceAsTask.<>c<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>
	// System.Threading.Tasks.ValueTask.ValueTaskSourceAsTask.<>c<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>
	// System.Threading.Tasks.ValueTask.ValueTaskSourceAsTask.<>c<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>
	// System.Threading.Tasks.ValueTask.ValueTaskSourceAsTask.<>c<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>>
	// System.Threading.Tasks.ValueTask.ValueTaskSourceAsTask.<>c<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>>>
	// System.Threading.Tasks.ValueTask.ValueTaskSourceAsTask<System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>
	// System.Threading.Tasks.ValueTask.ValueTaskSourceAsTask<System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>
	// System.Threading.Tasks.ValueTask.ValueTaskSourceAsTask<System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>
	// System.Threading.Tasks.ValueTask.ValueTaskSourceAsTask<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>
	// System.Threading.Tasks.ValueTask.ValueTaskSourceAsTask<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>
	// System.Threading.Tasks.ValueTask.ValueTaskSourceAsTask<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>
	// System.Threading.Tasks.ValueTask.ValueTaskSourceAsTask<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>>
	// System.Threading.Tasks.ValueTask.ValueTaskSourceAsTask<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>>>
	// System.Threading.Tasks.ValueTask.ValueTaskSourceAsTask<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>>>>
	// System.Threading.Tasks.ValueTask<System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>
	// System.Threading.Tasks.ValueTask<System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>
	// System.Threading.Tasks.ValueTask<System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>
	// System.Threading.Tasks.ValueTask<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>
	// System.Threading.Tasks.ValueTask<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>
	// System.Threading.Tasks.ValueTask<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>
	// System.Threading.Tasks.ValueTask<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>>
	// System.Threading.Tasks.ValueTask<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>>>
	// System.Threading.Tasks.ValueTask<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>>>>
	// System.Threading.Tasks.ValueTask<System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>>>>>
	// System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>
	// System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>
	// System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>
	// System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>
	// System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>
	// System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>
	// System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>>
	// System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>>>
	// System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>>>>
	// System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.ValueTuple<byte,System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>>>>>>>>>>
	// }}

	public void RefMethods()
	{
		// System.Void Cysharp.Threading.Tasks.CompilerServices.AsyncUniTaskMethodBuilder.AwaitUnsafeOnCompleted<Cysharp.Threading.Tasks.UniTask.Awaiter,object>(Cysharp.Threading.Tasks.UniTask.Awaiter&,object&)
		// System.Void Cysharp.Threading.Tasks.CompilerServices.AsyncUniTaskMethodBuilder.AwaitUnsafeOnCompleted<Cysharp.Threading.Tasks.UniTask.Awaiter<System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>,object>(Cysharp.Threading.Tasks.UniTask.Awaiter<System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>&,object&)
		// System.Void Cysharp.Threading.Tasks.CompilerServices.AsyncUniTaskMethodBuilder<System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>.AwaitUnsafeOnCompleted<Cysharp.Threading.Tasks.UniTask.Awaiter,object>(Cysharp.Threading.Tasks.UniTask.Awaiter&,object&)
		// System.Void Cysharp.Threading.Tasks.CompilerServices.AsyncUniTaskMethodBuilder.Start<object>(object&)
		// System.Void Cysharp.Threading.Tasks.CompilerServices.AsyncUniTaskMethodBuilder<System.Nullable<HotUpdate.Configs.TableKitConfigLoader.TableData>>.Start<object>(object&)
		// object System.Linq.Enumerable.FirstOrDefault<object>(System.Collections.Generic.IEnumerable<object>,System.Func<object,bool>)
		// System.Collections.Generic.IEnumerable<object> System.Linq.Enumerable.SelectMany<object,object>(System.Collections.Generic.IEnumerable<object>,System.Func<object,System.Collections.Generic.IEnumerable<object>>)
		// System.Collections.Generic.IEnumerable<object> System.Linq.Enumerable.SelectManyIterator<object,object>(System.Collections.Generic.IEnumerable<object>,System.Func<object,System.Collections.Generic.IEnumerable<object>>)
		// System.Collections.Generic.IEnumerable<object> System.Linq.Enumerable.Where<object>(System.Collections.Generic.IEnumerable<object>,System.Func<object,bool>)
		// object UnityEngine.Resources.Load<object>(string)
		// object YooAsset.AssetHandle.GetAssetObject<object>()
		// YooAsset.AssetHandle YooAsset.ResourcePackage.LoadAssetAsync<object>(string,uint)
	}
}