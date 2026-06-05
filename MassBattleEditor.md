# MassBattle Editor MCP API Status

以下是 MassBattle 编辑器后端规划的 MCP 接口列表。本表参考 `FabUmgMcp` 的设计风格，主要分为 **资产烘焙与资源准备 (Asset & VAT Preparation)**、**实体生成器配置 (Spawners & Agents)**、**阵型与战术控制 (Formations & Tactics)** 以及 **仿真监控与 Niagara 粒子控制 (Simulation & Niagara)** 四大类。

## MassBattle Editor API Status

| Category | API Name | Status | Description |
| :--- | :--- | :---: | :--- |
| **Asset & VAT Preparation** | `duplicate_class_asset` | ⏳ Planning | 复制类资产并返回新生成的类。对应 `DuplicateClassAsset`。 |
| | `set_class_default_properties` | ⏳ Planning | 设置目标代理渲染类（AMassBattleAgentRenderer）的默认属性。对应 `SetClassDefaultProperties`。 |
| | `convert_skel_mesh_to_static_mesh` | ⏳ Planning | 将骨骼网格体转换为带多级 LOD 的静态网格体（用于 Mass 渲染）。对应 `ConvertSkeletalMeshToStaticMeshWithLODs`。 |
| | `create_material_instance_for_lods` | ⏳ Planning | 为带 LOD 的静态网格体自动生成并配置材质实例。对应 `CreateMaterialInstanceForStaticMeshWithLODs`。 |
| | `find_and_fill_original_textures` | ⏳ Planning | 扫描搜索路径并自动填充骨骼网格体对应的原始贴图信息。对应 `FindAndFillOriginalTextures`。 |
| | `find_and_fill_anim_sequences` | ⏳ Planning | 自动扫描填充骨骼网格体关联的动画序列。对应 `FindAndFillAnimSequences`。 |
| | `find_and_fill_lod_settings` | ⏳ Planning | 自动寻找并填充骨骼网格体的 LOD 预设设置。对应 `FindAndFillLODSettings`。 |
| | `create_anim_data_texture` | ⏳ Planning | 烘焙生成用于在顶点着色器中读取的 VAT 动画数据纹理（RG16F）。对应 `CreateAnimDataTexture`。 |
| | `create_anims_data_from_sequences` | ⏳ Planning | 从烘焙好的 VAT 数据资产及动画序列计算全局帧偏移并生成动画数据。对应 `CreateAnimsDataFromSequences` |
| | `convert_lod_settings_to_lods_data` | ⏳ Planning | 将编辑器的 LOD 设置转换为 MassBattle 内部使用的二进制/数组数据。对应 `ConvertLODSettingsToLODsData`。 |
| | `validate_anim_sequences` | ⏳ Planning | 验证并截断动画序列（如限制最大动画数为 5），检查总帧数。对应 `ValidateAnimSequences`。 |
| | `rename_skeletal_mesh` | ⏳ Planning | 按命名规范重命名骨骼网格体及其关联的纹理资产。对应 `RenameSkeletalMesh`。 |
| | `rename_original_textures` | ⏳ Planning | 批量规范化重命名原始纹理资产。对应 `RenameOriginalTextures`。 |
| | `rename_anim_sequences` | ⏳ Planning | 批量规范化重命名动画序列资产。对应 `RenameAnimSequences`。 |
| | `sanitize_for_path` | ⏳ Planning | 清理并规范化路径/资产名称字符串。对应 `SanitizeForPath`。 |
| **Spawners & Agents** | `massbattle_get_spawners` | ⏳ Planning | 获取关卡中所有 Mass Spawner 及其生成参数与关联阵营。 |
| | `massbattle_edit_spawner` | ⏳ Planning | 编辑指定 Mass Spawner 的实体数量、生成半径和生成实体类型。 |
| **Formations & Tactics** | `massbattle_set_formation` | ⏳ Planning | 为 Spawner 的实体群配置阵型类型（如 Line, Column, Wedge）与实体间距。 |
| | `massbattle_set_move_target` | ⏳ Planning | 设置实体群的战术行军目标位置点（Vector3）。 |
| **Simulation & Niagara** | `massbattle_control_simulation` | ⏳ Planning | 启动、暂停、单步步进或重置 Mass 战斗仿真的运行状态。 |
| | `massbattle_get_simulation_stats` | ⏳ Planning | 获取仿真运行数据：实体总数、FPS、GPU 渲染负载和各状态实体占比。 |
| | `massbattle_modify_niagara_params` | ⏳ Planning | 动态调整渲染 Mass 材质/实体的 Niagara 粒子参数与 LOD 阈值。 |
