// Package data 定义了所有实体的接口和仓储抽象。
//
// 跟 Server/C#Server/TestTcpServer/TestTcpServer/Data/Abstractions/ 对齐:
//   - IEntity       → Entity
//   - IRepository<T>→ Repository[T]
//   - IUnitOfWork   → UnitOfWork
//
// 业务层(handler)只依赖这三个抽象,不关心具体存储是内存还是 DB。
package data

// Entity 所有持久化实体必须实现这个接口,提供一个 comparable 的 ID。
//
// 推荐 ID 类型:int64(string ID 也可,但要求是 comparable)。
type Entity interface {
	// GetID 返回实体的唯一标识,用作仓储的主键。
	// 实现必须保证 ID 在实体的生命周期内不变。
	GetID() any
}

// IDOf 辅助函数:从 Entity 取出 ID,转成 int64。
// 业务层用得多,避免到处断言。
func IDOf(e Entity) int64 {
	if e == nil {
		return 0
	}
	if id, ok := e.GetID().(int64); ok {
		return id
	}
	return 0
}