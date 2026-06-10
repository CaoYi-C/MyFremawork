# mavis-migrate

一键打包 MiniMax Code (Mavis) 配置目录,方便换设备时整体迁移。

## 用法

```powershell
# 默认:打包整个 mavis 目录(推荐,首次迁移)
.\mavis-migrate.ps1

# 只打包技能
.\mavis-migrate.ps1 -Mode skills

# 只打包 agent 配置
.\mavis-migrate.ps1 -Mode agents

# 自定义输出位置
.\mavis-migrate.ps1 -OutputPath "D:\backup"
```

执行后会在输出目录生成:
- `mavis-backup-<mode>-<时间戳>.zip` — 压缩包
- `mavis-restore-README.txt` — 新设备上的还原步骤

## 还原(在新设备上)

```powershell
Expand-Archive -Path "mavis-backup-all-20260606-234200.zip" -DestinationPath "$env:USERPROFILE\.mavis" -Force
```

然后重启 MiniMax Code。

## 什么时候用

- 换电脑 / 重装系统
- 给团队成员配同样的环境
- 跨机器同步自己的 agent / skill 偏好

## 不会包含什么

- 临时缓存(daemon 跑起来自己重建)
- 项目里的 `AGENTS.md` / `.harness/`(在项目仓库里,跟代码一起走 git)
