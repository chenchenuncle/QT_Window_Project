# SQL View Query Model

一个基于 Qt 和 SQLite 的员工信息管理系统，使用 Model/View 架构实现数据的展示、编辑和管理。

## 功能特性

- 员工信息的增删改查
- 数据表格展示与排序
- 员工照片管理
- 工资批量调整
- 多表关联查询

## 技术栈

- **前端框架**：Qt 6.9.2
- **数据库**：SQLite
- **开发工具**：Qt Creator
- **构建系统**：qmake

## 项目结构

```
SQL_View_querymodel/
├── SQLite/              # 数据库文件
│   └── sql.db3
├── main.cpp             # 主入口文件
├── mainwindow.cpp       # 主窗口实现
├── mainwindow.h         # 主窗口头文件
├── mainwindow.ui        # 主窗口界面
├── person_show.cpp      # 员工信息编辑窗口实现
├── person_show.h        # 员工信息编辑窗口头文件
├── person_show.ui       # 员工信息编辑窗口界面
├── SQL_View_querymodel.pro  # 项目配置文件
└── README.md            # 项目说明文档
```

## 数据库结构

### Employee Information 表
- `Employee_ID` (INTEGER): 员工ID（主键）
- `name` (VARCHAR): 员工姓名
- `Gender` (VARCHAR): 性别
- `birthday` (DATE): 出生日期
- `province` (VARCHAR): 省份
- `department` (VARCHAR): 部门
- `salary` (DOUBLE): 工资
- `photo` (BLOB): 照片（二进制数据）
- `meon` (TEXT): 备注

### 其他表
- `College Information`: 院校信息表
- `Professional Information`: 专业信息表
- `studyinfo`: 学习信息表

## 安装与运行

### 环境要求
- Qt 6.9.2 或更高版本
- MinGW 64-bit 编译器
- SQLite 3

### 安装步骤
1. 克隆或下载项目到本地
2. 使用 Qt Creator 打开 `SQL_View_querymodel.pro` 文件
3. 构建项目（Build）
4. 运行项目（Run）

## 使用说明

### 基本操作
1. **打开数据库**：点击"打开数据库"按钮选择数据库文件
2. **浏览员工信息**：使用"首记录"、"前记录"、"后记录"、"尾记录"按钮导航
3. **添加员工**：点击"插入信息"按钮，填写表单后点击"确定"
4. **编辑员工**：选择员工后点击"编辑记录"按钮，修改信息后点击"确定"
5. **删除员工**：选择员工后点击"删除记录"按钮
6. **调整工资**：点击"涨工资"按钮，为所有员工增加200元工资

### 照片管理
- **导入照片**：在员工编辑窗口点击"导入照片"按钮选择图片
- **清除照片**：点击"清除照片"按钮移除当前员工照片

## 核心功能实现

### 数据模型
使用 `QSqlQueryModel` 管理数据，`QItemSelectionModel` 跟踪选中状态，`QDataWidgetMapper` 实现数据与界面的映射。

### 数据库操作
- 使用 `QSqlQuery` 执行 SQL 语句
- 支持事务处理确保数据一致性
- 外键约束保证数据完整性

### 界面交互
- 信号槽机制实现组件间通信
- 事件处理确保用户操作响应
- 错误处理提供友好的用户提示

## 代码示例

### 数据库初始化
```cpp
// 初始化数据库
QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "socool");
db.setDatabaseName("path/to/database.db3");
if (!db.open()) {
    QMessageBox::critical(this, "错误", "无法打开数据库");
    return;
}
```

### 数据查询与展示
```cpp
// 初始化模型
model = new QSqlQueryModel(this);
model->setQuery("SELECT * FROM [Employee Information] ORDER BY Employee_ID ASC");

// 设置表头
model->setHeaderData(0, Qt::Horizontal, "工号");
model->setHeaderData(1, Qt::Horizontal, "姓名");
// ... 其他表头设置

// 绑定到视图
ui->tableView->setModel(model);
```

### 员工信息编辑
```cpp
// 数据映射
mapper = new QDataWidgetMapper(this);
mapper->setModel(model);
mapper->addMapping(ui->spinBox, 0);      // Employee_ID
mapper->addMapping(ui->lineEdit, 1);      // name
// ... 其他控件映射

// 连接选择变化信号
connect(itemmodel, &QItemSelectionModel::currentRowChanged,
        mapper, &QDataWidgetMapper::setCurrentModelIndex);
```

## 已知问题与解决方案

1. **参数绑定顺序错误**：确保绑定值的顺序与 SQL 语句中的占位符顺序一致
2. **外键约束语法错误**：SQLite 不支持 `INITIALLY IMMEDIATE` 语法，使用标准外键语法
3. **模型未排序**：在查询语句中添加 `ORDER BY` 子句
4. **图片显示问题**：确保正确处理二进制数据的读取和写入

## 许可证

本项目采用 MIT 许可证 - 详见 LICENSE 文件

## 贡献

欢迎提交 Issue 和 Pull Request 来改进这个项目！

## 联系方式

如有问题或建议，请通过 GitHub Issues 与我联系。

---

*项目开发日期：2026年3月*
