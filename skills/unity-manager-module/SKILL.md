---
name: Unity Manager Module Pattern
description: Create or extend Unity manager classes following the Fuel framework singleton pattern with init/dispose lifecycle
---

## When to use
- User asks to create a new manager (Audio, Scene, UI, Event, Network, etc.)
- User asks to add features to an existing manager module

## Procedure

### 1. Identify manager type
Determine if this is a:
- **Singleton Manager** - Global instance (most managers)
- **Module Manager** - Registered with `ModuleManager`

### 2. Create file structure
```
Assets/Scripts/Manager/{ManagerName}/
├── {ManagerName}.cs              # Main class, singleton boilerplate
├── {ManagerName}.Data.cs         # Enums, data classes, inner types
├── {ManagerName}.Loading.cs      # Async operations (if needed)
└── {ManagerName}.Events.cs       # Event registration/dispatch (if needed)
```

### 3. Singleton boilerplate
```csharp
using Fuel.Singleton;

namespace Fuel.Manager.{ManagerName}
{
    public sealed partial class {ManagerName} : Singleton<{ManagerName}>
    {
        protected override void OnInit() { }
        protected override void OnDispose() { }
    }
}
```

### 4. Data classes pattern
For data classes that need pooling:
```csharp
public sealed class {TypeName}Data
{
    // Properties
    public string Path { get; set; }
    
    // Pool
    private static readonly Stack<{TypeName}Data> s_pool = new Stack<{TypeName}Data>();
    
    public static {TypeName}Data Get()
    {
        return s_pool.Count > 0 ? s_pool.Pop() : new {TypeName}Data();
    }
    
    public void Reset()
    {
        // Reset all properties to defaults
    }
    
    public void Release()
    {
        Reset();
        s_pool.Push(this);
    }
    
    public {TypeName}Data Clone()
    {
        var clone = Get();
        // Copy all properties
        return clone;
    }
}
```

### 5. Naming conventions
- Namespace: `Fuel.Manager.{ManagerName}`
- Use `DebugLogger` with appropriate `LogWriter` instead of `Debug.Log`
- Partial classes for logical separation

## Examples in codebase
- `Assets/Scripts/Manager/AudioManager/` - Full implementation with pooling
- `Assets/Scripts/Manager/SceneManager/` - Scene loading with events
- `Assets/Scripts/Manager/UIManager/` - Stack-based UI management
- `Assets/Scripts/Manager/EventDispatcher/` - Event system
