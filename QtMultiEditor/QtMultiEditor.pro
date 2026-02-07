QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dialoghead.cpp \
    dialogtable.cpp \
    formdoc.cpp \
    main.cpp \
    mainwindow.cpp \
    start.cpp \
    ttable.cpp \
    widget_edit.cpp

HEADERS += \
    dialoghead.h \
    dialogtable.h \
    formdoc.h \
    mainwindow.h \
    start.h \
    ttable.h \
    widget_edit.h

FORMS += \
    dialoghead.ui \
    dialogtable.ui \
    formdoc.ui \
    mainwindow.ui \
    start.ui \
    ttable.ui \
    widget_edit.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    qrc/多窗口模式.png \
    qrc/平铺展开.png \
    qrc/级联展开.png

RESOURCES += \
    qrc.qrc
