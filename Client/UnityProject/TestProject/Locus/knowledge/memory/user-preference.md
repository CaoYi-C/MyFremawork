---
id: kd_builtin_memory_user_preference
type: memory
path: user-preference.md
title: user-preference
injectMode: rule
summaryEnabled: false
commandEnabled: false
readOnly: false
aiMaintained: true
explicitMaintenanceRules: true
createdAt: 1778427694231
updatedAt: 1782114886592
---

# user-preference

<!-- locus:maintain-rules:start -->
- Record only long-term user preferences that stay stable across tasks
- Prioritize language, reporting style, code style, taboos, and explicit requirements
- Keep each entry short and limited to stable preferences or hard constraints
- Keep the list within 20 items and merge similar preferences
- Remove one-off arrangements, temporary phrasing, and unconfirmed inferences
<!-- locus:maintain-rules:end -->

<!-- locus:body:start -->
- 后续如果需要切换 Unity 编辑器状态（进入/退出 Play��暂停等），先给用户选择并等用户确认后再切换。
<!-- locus:body:end -->
