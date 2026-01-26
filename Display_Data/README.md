#使用Model/View架构，实现了`QStandardItemModel`与`QTableView`的数据绑定
有基础的添加行，插入行，删除行
右侧实现直接读取“QTableView”模型数据全部数据并显示数据

<img width="1919" height="1011" alt="image" src="https://github.com/user-attachments/assets/5604c93d-006e-436f-b2a6-72a22485fd0c" />


桌面应用，实现了数据的读取、展示、编辑和预览功能
如上图，设计并实现了3种自定义`QStyledItemDelegate`，支持浮点数,下拉框,整数多种数据类型的编辑
实现了从文件读取数据并动态构建表格的功能，支持数据的实时预览和编辑
最下面显示文件地址，单元格选中状态跟踪
代码结构清晰，模块化设计，便于维护和扩展
