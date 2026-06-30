package data

import "context"

// Repository 泛型仓储接口。
//
// 设计原则:
//   - 跟具体存储解耦:业务层依赖此接口,具体实现可以是内存 / GORM / mongo-driver
//   - Context 透传:支持超时、取消、trace 等
//   - 不暴露底层 ORM 类型:返回的都是业务实体(Entity)
//
// 错误约定:
//   - ErrNotFound:实体不存在
//   - 其他错误:底层存储错误,业务层应当记录并返回 500 类错误码
type Repository[T Entity] interface {
	// Insert 插入新实体。ID 已存在的实体应返回错误(不要静默覆盖)。
	Insert(ctx context.Context, entity T) error

	// Update 更新已存在的实体。ID 不存在时返回 ErrNotFound。
	Update(ctx context.Context, entity T) error

	// Upsert 不存在则插入,存在则更新。骨架阶段不实现,需要时再加。
	// Upsert(ctx context.Context, entity T) error

	// Remove 按 ID 删除实体。ID 不存在不报错(幂等)。
	Remove(ctx context.Context, id any) error

	// FindOne 按 ID 查找单个实体。不存在返回 (zero, ErrNotFound)。
	FindOne(ctx context.Context, id any) (T, error)

	// FindMany 按一组 ID 批量查找。返回的切片顺序不保证跟输入 ID 一致。
	// 不存在的 ID 会跳过,不会报错。
	FindMany(ctx context.Context, ids ...any) ([]T, error)

	// FindAll 返回所有实体。大数据量慎用,生产应当用分页。
	FindAll(ctx context.Context) ([]T, error)

	// Count 返回实体总数。
	Count(ctx context.Context) (int64, error)
}