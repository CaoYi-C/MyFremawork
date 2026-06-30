// Package memory 提供 data.Repository[T] 的内存实现。
//
// 仅供开发/测试用,进程重启数据丢失。
// 线程安全:用 sync.RWMutex 保护读写。
//
// 生产替换:实现 GormRepository[T] / MongoRepository[T] 等,handler 改 DI 注册即可。
package memory

import (
	"context"
	"sync"

	"testserver/internal/data"
)

// MemoryRepository 内存版 Repository[T]。
type MemoryRepository[T data.Entity] struct {
	mu   sync.RWMutex
	data map[any]T
}

// NewMemoryRepository 构造一个新的内存仓储。
func NewMemoryRepository[T data.Entity]() *MemoryRepository[T] {
	return &MemoryRepository[T]{
		data: make(map[any]T),
	}
}

// Insert 插入新实体。ID 已存在返回 ErrDuplicateKey。
func (r *MemoryRepository[T]) Insert(_ context.Context, entity T) error {
	if entity == nil {
		return data.ErrInvalidEntity
	}
	id := entity.GetID()

	r.mu.Lock()
	defer r.mu.Unlock()

	if _, exists := r.data[id]; exists {
		return data.ErrDuplicateKey
	}
	r.data[id] = entity
	return nil
}

// Update 更新已存在的实体。ID 不存在返回 ErrNotFound。
func (r *MemoryRepository[T]) Update(_ context.Context, entity T) error {
	if entity == nil {
		return data.ErrInvalidEntity
	}
	id := entity.GetID()

	r.mu.Lock()
	defer r.mu.Unlock()

	if _, exists := r.data[id]; !exists {
		return data.ErrNotFound
	}
	r.data[id] = entity
	return nil
}

// Remove 按 ID 删除实体。ID 不存在不报错(幂等)。
func (r *MemoryRepository[T]) Remove(_ context.Context, id any) error {
	r.mu.Lock()
	defer r.mu.Unlock()
	delete(r.data, id)
	return nil
}

// FindOne 按 ID 查找单个实体。不存在返回 (zero, ErrNotFound)。
func (r *MemoryRepository[T]) FindOne(_ context.Context, id any) (T, error) {
	r.mu.RLock()
	defer r.mu.RUnlock()

	v, ok := r.data[id]
	if !ok {
		var zero T
		return zero, data.ErrNotFound
	}
	return v, nil
}

// FindMany 按一组 ID 批量查找。不存在的 ID 跳过。
func (r *MemoryRepository[T]) FindMany(_ context.Context, ids ...any) ([]T, error) {
	r.mu.RLock()
	defer r.mu.RUnlock()

	out := make([]T, 0, len(ids))
	for _, id := range ids {
		if v, ok := r.data[id]; ok {
			out = append(out, v)
		}
	}
	return out, nil
}

// FindAll 返回所有实体。
func (r *MemoryRepository[T]) FindAll(_ context.Context) ([]T, error) {
	r.mu.RLock()
	defer r.mu.RUnlock()

	out := make([]T, 0, len(r.data))
	for _, v := range r.data {
		out = append(out, v)
	}
	return out, nil
}

// Count 返回实体总数。
func (r *MemoryRepository[T]) Count(_ context.Context) (int64, error) {
	r.mu.RLock()
	defer r.mu.RUnlock()
	return int64(len(r.data)), nil
}