基于Qt框架的多模式文本编辑器，支持MDI和TabWidget两种窗口管理模式，展示了Qt核心组件的综合运用。
该项目实现了两种窗口模式的无缝切换，提供了基本的文本编辑功能，并包含了登录验证和启动动画等用户体验元素。
使用QApplication自己建立账本密码和账号会存放到注册表里（别的系统请看文档https://doc.qt.io/qt-6/zh/qsettings.html#details）
使用QCryptographicHash加密密码
账号：12345  密码：88888
<img width="1101" height="828" alt="image" src="https://github.com/user-attachments/assets/55363332-e4c1-47a2-a9f3-f4d8f4c633ba" />
成功登录密码会保存到注册表里，下次打开软件会自动保存账号和密码

登录页面Start是继承于QDialog（没有移动效果）
为了让登录页面有移动效果，重新写    
void mousePressEvent(QMouseEvent*event);
void mouseMoveEvent(QMouseEvent*event);
void mouseReleaseEvent(QMouseEvent*event);实现移动效果。

登录与启动流程
登录验证界面
3秒启动动画效果
<img width="646" height="360" alt="image" src="https://github.com/user-attachments/assets/aea5bc97-4a51-49e6-ba79-329435ade432" />
基于QDialog和QSplashScreen实现

双模式窗口管理
<img width="1919" height="1017" alt="image" src="https://github.com/user-attachments/assets/0c8657c8-d7a1-438f-b109-ef6d06d99e59" />
多文档界面，支持子窗口层叠/平铺排列
标签页界面，支持标签关闭
两种模式可通过菜单栏无缝切换
响应式菜单栏（根据当前模式动态显示/隐藏菜单项）

文本编辑功能
<img width="1919" height="1005" alt="image" src="https://github.com/user-attachments/assets/b6af2b6c-c81f-4bfd-9789-508d02cab039" />
基本编辑操作（复制、粘贴、剪切）
撤销/重做功能
字体选择与设置
文件打开与读取

自定义UI与交互
![4d6c43a214e31dadb06b4932ccab75a3](https://github.com/user-attachments/assets/3766e68c-0224-473c-bedc-f76c0fbd0eae)
TabWidget背景自定义绘制
事件过滤器的应用
友好的错误提示信息





