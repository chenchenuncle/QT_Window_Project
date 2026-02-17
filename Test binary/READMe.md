# Binary 数据序列化项目

## 项目简介

本项目是一个基于Qt框架的二进制数据序列化工具，实现了通用的数据读写接口。项目通过模板编程技术，支持多种数据类型的序列化和反序列化，包括基本数据类型、QByteArray、QString等复杂类型。项目展示了Qt框架中QDataStream的使用，以及自定义序列化接口的实现方法。

## 项目功能

### 核心功能

1. **通用数据读写接口**
   - 支持多种数据类型的序列化
   - 提供统一的读写接口
   - 自动类型识别

2. **双序列化模式**
   - 官方QDataStream接口
   - 自定义readRawData/writeRawData接口

3. **复杂类型支持**
   - QByteArray序列化
   - QString序列化
   - char*指针序列化

### 支持的数据类型

#### 基本数据类型
- qint8, quint8 (8位有符号/无符号整数)
- qint16, quint16 (16位有符号/无符号整数)
- qint32, quint32 (32位有符号/无符号整数)
- qint64, quint64 (64位有符号/无符号整数)
- float, double (浮点数)
- bool (布尔值，需特殊处理)

#### 复杂数据类型
- QByteArray (字节数组)
- QString (字符串)
- char* (字符指针)

## 技术架构

### 模板设计

项目使用C++模板技术实现通用接口：

```cpp
template <class T>
void Read(T& t);  // 通用读取接口

template <class T>
void Wired(T& type);  // 通用写入接口
```

### 序列化策略

#### 策略1：QDataStream接口
```cpp
template <class T>
void read(T& da) {
    data.resetStatus();
    data >> da;  // 使用QDataStream的operator>>
}

template <class T>
void wired(T& da) {
    data.resetStatus();
    data << da;  // 使用QDataStream的operator<<
}
```

#### 策略2：自定义接口
```cpp
template <class T>
void Read(T& type) {
    if(!file.open(QIODevice::ReadOnly))
        return;
    
    data.resetStatus();
    if(ui->radioButton_5->isChecked())
        data.readRawData((char*)&type, sizeof(type));  // 直接内存读写
    else
        read(type);  // 使用QDataStream
    
    file.close();
}
```

### 复杂类型特化

对于复杂类型，项目提供了特化版本：

#### QByteArray特化
```cpp
template<>
void MainWindow::Read<QByteArray>(QByteArray &t) {
    // 读取长度信息
    qint32 sum=0;
    data.readRawData((char*)&sum, sizeof(sum));
    
    // 分配内存并读取数据
    t.resize(sum);
    data.readRawData(t.data(), (qint64)sum);
}

template<>
void MainWindow::Wired<QByteArray>(QByteArray &t) {
    // 写入长度信息
    qint32 sum=t.size();
    data.writeRawData((char*)&sum, sizeof(sum));
    
    // 写入数据
    data.writeRawData(t.data(), (qint64)t.size());
}
```

#### QString特化
```cpp
template<>
void MainWindow::Read<QString>(QString &t) {
    // 读取字符数
    qint32 sum=0;
    data.readRawData((char*)&sum, sizeof(sum));
    
    // 读取UTF-16数据
    ushort* str = new ushort[sum];
    data.readRawData((char*)str, (qint64)sum*2);
    
    // 转换为QString
    t = QString::fromUtf16((const char16_t*)str, sum);
    delete[] str;
}

template<>
void MainWindow::Wired<QString>(QString &t) {
    // 写入字符数
    qint32 sum=t.size();
    data.writeRawData((char*)&sum, sizeof(sum));
    
    // 写入UTF-16数据
    data.writeRawData((char*)t.utf16(), (qint64)sum*2);
}
```

## 技术栈

### 核心技术
- **Qt Framework 6.9.2**：跨平台应用程序开发框架
- **Qt Widgets**：桌面应用程序UI组件
- **QDataStream**：二进制数据序列化
- **QFile**：文件I/O操作
- **C++17**：现代C++标准

### 编程技术
- **模板编程**：实现通用接口
- **模板特化**：处理特殊类型
- **操作符重载**：实现序列化接口
- **内存管理**：动态内存分配和释放

## 序列化格式

### 基本类型格式
```
[数据内容]
```
直接存储数据的二进制表示

### QByteArray格式
```
[4字节长度][数据内容]
```
- 前4字节：数据长度（字节数）
- 后面：原始字节数据

### QString格式
```
[4字节长度][UTF-16编码的数据]
```
- 前4字节：字符数（不是字节数）
- 后面：UTF-16编码的数据（每个字符2字节）

## 开发环境

### 系统要求
- **操作系统**：Windows 10/11
- **编译器**：MinGW 64-bit
- **Qt版本**：Qt 6.9.2
- **C++标准**：C++17

### 开发工具
- **IDE**：Qt Creator
- **版本控制**：Git
- **构建系统**：qmake

## 项目结构

```
binary/
├── main.cpp           # 程序入口
├── mainwindow.h       # 主窗口头文件
├── mainwindow.cpp     # 主窗口实现
├── mainwindow.ui      # UI界面文件
├── binary.pro         # 项目配置文件
└── README.md          # 本文件
```

## 快速开始

### 构建项目
1. 使用Qt Creator打开binary.pro文件
2. 选择MinGW 64-bit编译套件
3. 点击构建按钮进行编译
4. 运行生成的可执行文件

### 使用示例

#### 写入数据
```cpp
qint8 value = 42;
Wired(value);  // 写入数据
```

#### 读取数据
```cpp
qint8 value;
Read(value);  // 读取数据
```

#### 写入字符串
```cpp
QString str = "你好世界";
Wired(str);  // 写入字符串
```

#### 读取字符串
```cpp
QString str;
Read(str);  // 读取字符串
```

## 技术亮点

### 1. 模板特化技术
项目展示了如何为特定类型提供模板特化，实现类型安全的序列化。

### 2. 双模式序列化
项目实现了两种序列化模式，可以根据需要选择使用QDataStream接口或自定义接口。

### 3. 复杂类型处理
项目正确处理了QByteArray和QString等复杂类型的序列化，避免了直接内存读写的问题。

### 4. UTF-16编码处理
QString序列化正确处理了UTF-16编码，支持多语言文本。

## 遇到的问题与解决方案

### 问题1：QString序列化警告
**问题**：使用`QString::fromUtf16(const ushort*, qsizetype)`时出现弃用警告。

**解决方案**：改用`QString::fromUtf16(const char16_t*, qsizetype)`，使用标准C++11类型。

### 问题2：QByteArray内存分配
**问题**：读取QByteArray时，如果未先分配内存，会导致缓冲区溢出。

**解决方案**：在读取数据前，先调用`t.resize(sum)`分配足够的内存。

### 问题3：QString内存泄漏
**问题**：读取QString时，动态分配的内存没有释放。

**解决方案**：使用`delete[] str`释放动态分配的内存。

### 问题4：QDataStream设备状态
**问题**：每次重新打开文件后，QDataStream的设备可能处于无效状态。

**解决方案**：在每次打开文件后，调用`data.setDevice(&file)`重新设置设备。

## 学习价值

本项目展示了以下Qt和C++技术：

1. **Qt序列化系统**：深入理解QDataStream的工作原理
2. **模板编程**：掌握C++模板和特化技术
3. **内存管理**：正确处理动态内存分配和释放
4. **编码处理**：理解UTF-16编码和字符串序列化
5. **错误处理**：实现健壮的文件I/O操作

## 扩展建议

### 1. 支持更多类型
- 添加对QList、QVector等容器类型的支持
- 实现QMap、QHash等关联容器的序列化
- 支持自定义结构体和类的序列化

### 2. 压缩和加密
- 添加数据压缩功能
- 实现数据加密和解密
- 支持多种压缩算法

### 3. 版本兼容性
- 实现版本控制机制
- 支持不同版本数据的兼容
- 添加数据格式验证

### 4. 错误恢复
- 实现更完善的错误处理
- 添加数据校验和验证
- 支持损坏数据的恢复

## 许可证

本项目仅供学习和交流使用。

## 联系方式

- **GitHub**：[chenchenuncle](https://github.com/chenchenuncle)
- **项目主页**：[QT_Window_ITEM](https://github.com/chenchenuncle/QT_Window_ITEM)

## 致谢

感谢Qt社区提供的优秀文档和技术支持！

---

**注意**：本项目主要用于学习和交流，展示了Qt框架在数据序列化方面的应用。通过本项目，可以深入理解Qt的序列化机制、C++模板编程以及内存管理等技术。
