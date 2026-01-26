QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    to_comboboxitem.cpp \
    to_tableitemmodel_styleditemdelegate.cpp \
    to_tfloatitem.cpp

HEADERS += \
    mainwindow.h \
    to_comboboxitem.h \
    to_tableitemmodel_styleditemdelegate.h \
    to_tfloatitem.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    qrc.qrc

DISTFILES += \
    rtc/生成特定图片.png \
    rtc/生成特定图片.png \
    rtc/生成特定图片1.png \
    rtc/生成特定图片1.png \
    rtc/粗体.png \
    rtc/粗体.png
