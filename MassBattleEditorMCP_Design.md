# MassBattleEditorMCP 技术方案与设计文档

本项目旨在为 **MassBattle** 插件构建一个基于 **MCP (Model Context Protocol)** 的编辑器后端，允许 AI 智能体直接在虚幻引擎 5 编辑器中操纵、配置并监控大规模战争实体（Battle Agents）的仿真。

---

## 1. MCP 后端架构方案

MCP 后端将参照 `UmgMcp` (FabUmgMcp) 的成熟架构进行设计，通过以下几个层级实现与 AI 的双向通信：

1. **协议传输层 (Transport Layer)**：
   * 在编辑器子系统（Editor Subsystem）中建立异步 TCP/WebSocket 本地服务器。
   * 监听并解析标准的 MCP JSON-RPC 2.0 请求（如 `tools/list`、`tools/call`）。
2. **命令路由与分发 (Command Dispatcher)**：
   * 将接收到的 JSON 命令分发至对应的功能处理器（如 Spawner 处理器、Simulation 处理器等）。
   * 统一进行主线程（GameThread）调度，保证 UObject 读写和关卡 Actor 操作的线程安全。
3. **接口层 (Tool Bindings)**：
   * 将 MassBattle 的 C++ API 封装为标准 JSON Schema 格式，供 LLM（大语言模型）识别并调用。

---

## 2. MassBattle MCP 核心工具（Tools）列表设计

为充分支持大规模实体战争的配置和仿真，初步规划以下 MCP 工具列表：

### 2.1 实体生成器配置 (Spawners & Agents)

#### `massbattle_get_spawners`
* **功能**：获取当前关卡中所有的 Mass 实体生成器（Spawner）及其关键配置。
* **返回**：Spawner Actor 名称、生成实体类型、关联数据资产（Config Asset）等。

#### `massbattle_edit_spawner`
* **功能**：动态修改生成器的参数。
* **参数**：
  * `spawner_name` (string): 目标生成器名称
  * `agent_count` (number, optional): 生成的实体数量
  * `spawn_radius` (number, optional): 生成半径范围
  * `alignment` (string, optional): 阵营（例如：Red / Blue / Neutral）

---

### 2.2 阵型与战术控制 (Formations & Tactics)

#### `massbattle_set_formation`
* **功能**：配置或更改实体群的生成/移动阵型。
* **参数**：
  * `spawner_name` (string): 目标生成器
  * `formation_type` (string): 阵型样式（如 `Line`、`Column`、`Wedge`、`Circle`）
  * `spacing` (number): 实体间隔距离

#### `massbattle_set_move_target`
* **功能**：为指定阵营或生成器的实体群设定行军目标点。
* **参数**：
  * `spawner_name` (string)
  * `target_location` (vector3: `{x, y, z}`)

---

### 2.3 仿真控制与监控 (Simulation & Monitoring)

#### `massbattle_control_simulation`
* **功能**：启动、暂停、单步运行或重置 Mass 战斗仿真。
* **参数**：
  * `action` (string): `start` / `pause` / `step` / `reset`

#### `massbattle_get_simulation_stats`
* **功能**：实时查询当前战斗仿真的统计数据与性能指标。
* **返回**：总实体数、当前帧率（FPS）、GPU 渲染开销、各状态下（如 Idle、Combat、Flee）的实体比例。

---

### 2.4 粒子渲染控制 (Niagara Visualization)

#### `massbattle_modify_niagara_params`
* **功能**：调整用于表示和渲染 Mass 实体的 Niagara 粒子系统参数，以优化视觉效果或性能。
* **参数**：
  * `emitter_name` (string): 粒子发射器或系统名
  * `particle_limit` (number, optional): 最大渲染粒子上限
  * `lod_distance` (number, optional): LOD 裁剪距离阀值
