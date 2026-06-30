# MassBattleEditorMCP 中文文档中心

欢迎使用 **MassBattleEditorMCP**。  
本项目的文档已统一归档到 `Document` 分支，建议优先使用网页入口查看。

## 立即开始

- 在线阅读（推荐）：`https://winyunq.github.io/MassBattleEditorMCP/`
- 本地查看：`git checkout Document` 后打开 `Document/index.html`

## 文档结构

- `README.md`：入口与总览（当前页）
- `MassBattleEditorMCP_Design.md`：插件能力、API 与实现说明
- `BatchFxMarketplaceConversion.md`：市场特效转批处理特效流程
- `MassBattleEditor.md`：单位编辑、调参与工作流说明
- `index.html`：网页式阅读页（含目录、搜索、代码高亮）

## 使用提示

1. 建议先读本文档，确认你的需求属于哪个 Order：
   - 外观/特效/表现问题 → 按 Order 1 或 Order 3 走
   - 数值平衡/批量改动 → 按 Order 2 走
2. 修改时尽量保留 plan 与 readback 证据，便于复核。
3. 需要快速查验执行结果时，建议先在 `Document/index.html` 中查阅对应章节，再回到工作区执行 MCP 操作。

## 更新说明

- 文档与网页入口由 `Document` 分支维护，`main` 分支仅保留对用户可见的引导入口。
- 设计与功能更新请同步提交至 `Document` 分支对应 Markdown 文件。
