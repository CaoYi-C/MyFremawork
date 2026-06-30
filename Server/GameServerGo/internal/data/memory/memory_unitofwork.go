package memory

import (
	"context"
	"sync"

	"testserver/internal/data"
)

// MemoryUnitOfWork 内存版 UnitOfWork。
//
// 内存存储本身没有事务概念,所以 Begin/Commit/Rollback 都是 no-op,
// 仅保留接口形状以兼容生产实现(GORM 等)。
type MemoryUnitOfWork struct {
	mu sync.Mutex
}

// NewMemoryUnitOfWork 构造一个新的内存 UoW。
func NewMemoryUnitOfWork() *MemoryUnitOfWork {
	return &MemoryUnitOfWork{}
}

// Repository 返回一个共享的内存仓储。
//
// 内存版每个 UoW 用一个共享 map,所有 Repository 共享同一份数据。
// 实际生产里这里应该返回 GORM 等带事务的 Repository。
func (u *MemoryUnitOfWork) Repository() any {
	return NewMemoryRepository[any]()
}

// Begin 内存版是 no-op。
func (u *MemoryUnitOfWork) Begin(_ context.Context) (data.UnitOfWork, error) {
	return u, nil
}

// Commit 内存版是 no-op。
func (u *MemoryUnitOfWork) Commit() error {
	return nil
}

// Rollback 内存版是 no-op。
func (u *MemoryUnitOfWork) Rollback() error {
	return nil
}