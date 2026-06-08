# UGUI 图层命名工具 — 开发与分发包（签名密码：123456）

Photoshop 2024+ 用的 CEP 扩展,给选中的图层批量加 Unity UGUI 前缀(`btn_` / `txt_` / `img_` 等)。
这个文件夹就是完整的开发 + 分发包,所有依赖都内嵌了。

---

## 文件结构

```
Ps_UGUI_Rename\
├── com.ugui.rename\           ← 扩展源码,你日常改这里
│   ├── client\
│   │   ├── index.html         面板 HTML
│   │   ├── index.js           面板逻辑(按钮事件 + evalScript 调用)
│   │   ├── style.css          面板样式
│   │   └── jsx\
│   │       └── CSInterface.js Adobe 官方通信库,一般不用改
│   ├── CSXS\
│   │   └── manifest.xml       扩展元数据(版本/兼容性/菜单名)
│   ├── host\
│   │   └── UGUI_Rename.jsx    后端 ExtendScript(真正改图层名的地方)
│   ├── img\                   面板图标(可选)
│   ├── META-INF\
│   │   └── signatures.xml     签名元数据(由 ZXPSignCmd 自动生成,别手改)
│   └── mimetype               Adobe 扩展标识,别删
│
├── com.ugui.rename.zxp        已签名的分发包(给同事的最终交付物)
│
├── ZXPSignCmd.exe             Adobe 官方签名工具
├── UGUI_Rename.p12            签名证书(自签名,需要密码)
│
├── install.cmd                同事首次安装入口(双击)
├── install.ps1                部署逻辑:解压 zxp + 注册表 + 验证
│
├── rebuild.cmd                本地改源码后入口(双击)
├── rebuild.ps1                打包 + 签名 + 部署
│
└── ReadMe.MD                  本文件
```

---

## 修改流程(你改源码 → 本地 PS 生效)

1. 在 `Ps_UGUI_Rename\com.ugui.rename\` 里直接改源码
   - 改完记得**先关掉 PS**(避免文件被锁)
2. 双击 `rebuild.cmd`
3. UAC 弹窗点"是" → PowerShell 弹窗输入 `.p12` 证书密码(不回显)
4. 等出现 `DONE. Restart Photoshop.` 即可
5. 打开 PS,`窗口` → `扩展` → `UGUI 图层命名工具`,改动生效

**脚本做了什么:**
- 复制 `com.ugui.rename\` → 临时快照,清掉旧 META-INF 签名
- ZXPSignCmd 把快照打包成 `.zxp` 并签名
- 部署签名后的内容到 `C:\Program Files (x86)\Common Files\Adobe\CEP\extensions\com.ugui.rename`
- 覆盖 `com.ugui.rename.zxp`(同步给同事的版本)
- `ZXPSignCmd -verify` 自检签名

---

## 分发流程(给同事)

### 方式 A:整包发(推荐)
1. 把整个 `Ps_UGUI_Rename\` 文件夹压缩成 zip / 7z 发给同事
2. 同事解压到任意位置
3. 同事双击 `install.cmd`
4. UAC 弹"是" → 看到 `DONE` 即可
5. 重启 PS,`窗口` → `扩展` → `UGUI 图层命名工具`

### 方式 B:只发 zxp
1. 跑过一次 `rebuild.cmd` 之后,`com.ugui.rename.zxp` 就是最新版本
2. 把 `com.ugui.rename.zxp` 单独发给同事
3. 同事双击 zxp(Adobe Creative Cloud 桌面版会自动安装到 `Common Files\Adobe\CEP\extensions\`)

**⚠️ 给同事的注意事项:**
- 同事的 PS 必须是 2022+(CSXS.11),目前覆盖到 PS 2024
- 因为用的是自签名证书(`UGUI_Rename.p12` 不是 Adobe 颁发的),同事跑 install.cmd 时脚本会自动给注册表 `PlayerDebugMode=1` 跳过签名检查
- 如果想正式分发(免去 PlayerDebugMode),需要去 [Adobe Exchange](https://exchange.adobe.com/) 申请开发者签名证书,用真证书重新签 zxp

---

## 常见问题

### ZXPSignCmd 报密码错
确认输的密码跟当初导 `UGUI_Rename.p12` 时设的密码一致。密码不会回显,输错就重新跑。

### Robocopy 退出码 >= 8
检查 PS 是否真的关了(占用扩展目录文件),或者 `Program Files (x86)` 权限被收紧。重跑一次通常就好。

### PS 启动后看不到面板
`窗口` → `扩展` 应该能看到 `UGUI 图层命名工具`。如果点开是空白,检查 `com.ugui.rename\CSXS\manifest.xml` 的 `<Host>` 版本范围是否覆盖你 PS 的版本。

### PS 2024+ 报"未经正确签署"
要么重新跑 `install.cmd` / `rebuild.cmd`(会自动设 `PlayerDebugMode=1`),要么把 `UGUI_Rename.p12` 装到同事的 Adobe 信任库:
```powershell
& ".\ZXPSignCmd.exe" -verify "C:\Program Files (x86)\Common Files\Adobe\CEP\extensions\com.ugui.rename" -addCerts ".\UGUI_Rename.p12"
```

### 改名操作没弹窗
`rebuild.ps1` 已经把 `index.js` 默认改成"成功静默、错误才弹窗"。需要看反馈的话,改 `com.ugui.rename\client\index.js` 第 54 行的 if 条件,去掉 `&& /^(错误|重命名失败)/.test(result)` 即可恢复总是弹窗。

---

## 注意事项

- **改完代码一定要先关 PS** 再跑 `rebuild.cmd`
- 脚本会自动清理 `%TEMP%\ugui_*` 临时目录,但偶尔会留,看到 `ugui_build_xxx` 文件夹残留直接删
- 证书 `UGUI_Rename.p12` **别泄露**,谁拿到谁就能以你的名义签 CEP 扩展
- `META-INF\signatures.xml` 是签名的产物,源码里那份是上次签的,ZXPSignCmd 会用新 hash 重新生成,不用手动改
- 整套流程只在 Windows 上验证过;Mac / Linux 下的 `Program Files` 路径不同,需要改脚本
