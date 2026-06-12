---
name: Unity Data Object Pool with Clone
description: Add object pooling (Get/Release) and Clone() methods to Unity data classes
---

## When to use
- User asks to add Clone() to a data/module class
- User asks to optimize allocations with object pooling
- Creating new data transfer objects for network responses

## Procedure

### 1. Identify the class
Target classes are typically:
- Module data classes (`*Module.Data.cs`)
- Response data classes (`*RspData`)
- Configuration data holders

### 2. Add object pool pattern

```csharp
public sealed class {ClassName}
{
    // Existing properties...
    
    // Object pool
    private static readonly Stack<{ClassName}> s_pool = new Stack<{ClassName}>();
    
    /// <summary>
    /// 从池中获取或创建新实例
    /// </summary>
    public static {ClassName} Get()
    {
        return s_pool.Count > 0 ? s_pool.Pop() : new {ClassName}();
    }
    
    /// <summary>
    /// 重置所有属性为默认值
    /// </summary>
    public void Reset()
    {
        // Reset each property to its default
        Property1 = default;
        Property2 = null;
        CollectionProperty?.Clear();
    }
    
    /// <summary>
    /// 归还到池中
    /// </summary>
    public void Release()
    {
        Reset();
        s_pool.Push(this);
    }
}
```

### 3. Add Clone method

For simple properties:
```csharp
public {ClassName} Clone()
{
    var clone = Get();
    clone.Prop1 = Prop1;
    clone.Prop2 = Prop2;
    // ... copy all fields
    return clone;
}
```

For collections (use AddRange):
```csharp
public {ClassName} Clone()
{
    var clone = Get();
    clone.Items.AddRange(Items);
    return clone;
}
```

For nested objects with pooling:
```csharp
public {ClassName} Clone()
{
    var clone = Get();
    clone.NestedObj = NestedObj?.Clone();
    return clone;
}
```

### 4. Update existing code
Replace direct `new {ClassName}()` with `{ClassName}Get()` where appropriate.

## Examples in codebase
- `Assets/HotUpdate/Module/Mount/MountModule.Data.cs` - MountData with Clone
- `Assets/HotUpdate/Module/Relic/RelicModule.Data.cs` - RelicData with Clone
- `Assets/HotUpdate/Module/EquipModule/EquipModule.Data.cs` - EquipItemData with Clone
- `Assets/HotUpdate/Module/Profile/ProfileModule.Data.cs` - GetOtherPlayerInfoRspData with Clone

## Pitfalls
- Always call `Reset()` before `Release()` to prevent stale data
- Collections should use `Clear()` then `AddRange()`, not direct assignment
- Nested pooled objects should be cloned, not shared
