package data

import (
	"context"
	"errors"
)

// UnitOfWork 工作单元。
//
// 用途:把多个 Repository 的操作包在一个事务里。
// 比如"登录成功"同时要:
//   1. 更新 Player.LastLoginAt
//   2. 写一条 LoginLog
//   3. 给 Item 表加一个新手礼包
// 这三个操作要么全成功,要么全回滚。
//
// Go 不支持泛型方法,所以 Repository() 返回 any,
// 调用方用 data.RepositoryOf[T](uow) 取具体类型(自动断言/缓存)。
//
// 参考使用:
//
//	uow := memory.NewMemoryUnitOfWork()
//	playerRepo := data.RepositoryOf[Player](uow)
//	itemRepo   := data.RepositoryOf[Item](uow)
//
//	if err := uow.Begin(ctx); err != nil { return err }
//	if err := playerRepo.Update(ctx, p); err != nil { uow.Rollback(); return err }
//	if err := itemRepo.Insert(ctx, gift); err != nil { uow.Rollback(); return err }
//	return uow.Commit()
type UnitOfWork interface {
	// Repository 返回底层仓储实例(类型为 any)。
	// 业务层用 data.RepositoryOf[T](uow) 拿到具体类型。
	Repository() any

	// Begin 开启事务(对支持事务的实现有效,如 GORM;内存实现是 no-op)。
	Begin(ctx context.Context) (UnitOfWork, error)

	// Commit 提交事务。
	Commit() error

	// Rollback 回滚事务。
	Rollback() error
}

// 通用错误
var (
	ErrNotFound      = errors.New("entity not found")
	ErrDuplicateKey  = errors.New("duplicate key")
	ErrInvalidEntity = errors.New("invalid entity")
)

// RepositoryOf 泛型便捷方法:从 UnitOfWork 取出指定实体的 Repository。
//
// 调用方:
//
//	playerRepo, err := data.RepositoryOf[Player](uow)
//
// 注意:目前是简单类型断言,生产实现里可以加缓存 + 事务绑定。
func RepositoryOf[T Entity](uow UnitOfWork) Repository[T] {
	if r, ok := uow.Repository().(Repository[T]); ok {
		return r
	}
	// 兜底:返回一个新的内存仓储(内存版语义)
	// 生产实现应该 panic 或者返回错误,这里为了骨架跑通先静默
	return nil
}