/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_1;
    QAction *action_2;
    QAction *action_3;
    QAction *action_4;
    QAction *action_5;
    QAction *action_6;
    QAction *action_7;
    QAction *action_8;
    QAction *actionMDI;
    QAction *action_9;
    QAction *action_10;
    QAction *action_11;
    QAction *actionwigdet;
    QAction *action_wigdet;
    QAction *action;
    QAction *action_13;
    QAction *action_14;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(870, 586);
        MainWindow->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);
        action_1 = new QAction(MainWindow);
        action_1->setObjectName("action_1");
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::DocumentNew));
        action_1->setIcon(icon);
        action_1->setMenuRole(QAction::MenuRole::NoRole);
        action_2 = new QAction(MainWindow);
        action_2->setObjectName("action_2");
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::FolderNew));
        action_2->setIcon(icon1);
        action_2->setMenuRole(QAction::MenuRole::NoRole);
        action_3 = new QAction(MainWindow);
        action_3->setObjectName("action_3");
        QIcon icon2(QIcon::fromTheme(QIcon::ThemeIcon::DocumentSave));
        action_3->setIcon(icon2);
        action_3->setMenuRole(QAction::MenuRole::NoRole);
        action_4 = new QAction(MainWindow);
        action_4->setObjectName("action_4");
        QIcon icon3(QIcon::fromTheme(QIcon::ThemeIcon::EditClear));
        action_4->setIcon(icon3);
        action_4->setMenuRole(QAction::MenuRole::NoRole);
        action_5 = new QAction(MainWindow);
        action_5->setObjectName("action_5");
        QIcon icon4(QIcon::fromTheme(QIcon::ThemeIcon::EditCut));
        action_5->setIcon(icon4);
        action_5->setMenuRole(QAction::MenuRole::NoRole);
        action_6 = new QAction(MainWindow);
        action_6->setObjectName("action_6");
        QIcon icon5(QIcon::fromTheme(QIcon::ThemeIcon::EditCopy));
        action_6->setIcon(icon5);
        action_6->setMenuRole(QAction::MenuRole::NoRole);
        action_7 = new QAction(MainWindow);
        action_7->setObjectName("action_7");
        QIcon icon6(QIcon::fromTheme(QIcon::ThemeIcon::EditPaste));
        action_7->setIcon(icon6);
        action_7->setMenuRole(QAction::MenuRole::NoRole);
        action_8 = new QAction(MainWindow);
        action_8->setObjectName("action_8");
        QIcon icon7(QIcon::fromTheme(QIcon::ThemeIcon::MailMessageNew));
        action_8->setIcon(icon7);
        action_8->setMenuRole(QAction::MenuRole::NoRole);
        actionMDI = new QAction(MainWindow);
        actionMDI->setObjectName("actionMDI");
        actionMDI->setCheckable(true);
        actionMDI->setChecked(true);
        actionMDI->setEnabled(true);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/qrc/MDI.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionMDI->setIcon(icon8);
        actionMDI->setMenuRole(QAction::MenuRole::NoRole);
        action_9 = new QAction(MainWindow);
        action_9->setObjectName("action_9");
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/qrc/\347\272\247\350\201\224\345\261\225\345\274\200.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        action_9->setIcon(icon9);
        action_9->setMenuRole(QAction::MenuRole::NoRole);
        action_10 = new QAction(MainWindow);
        action_10->setObjectName("action_10");
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/qrc/\345\271\263\351\223\272\345\261\225\345\274\200.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        action_10->setIcon(icon10);
        action_10->setMenuRole(QAction::MenuRole::NoRole);
        action_11 = new QAction(MainWindow);
        action_11->setObjectName("action_11");
        action_11->setCheckable(true);
        action_11->setChecked(false);
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/qrc/\345\244\232\347\252\227\345\217\243\346\250\241\345\274\217.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        action_11->setIcon(icon11);
        action_11->setMenuRole(QAction::MenuRole::NoRole);
        actionwigdet = new QAction(MainWindow);
        actionwigdet->setObjectName("actionwigdet");
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/qrc/widget.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionwigdet->setIcon(icon12);
        actionwigdet->setMenuRole(QAction::MenuRole::NoRole);
        action_wigdet = new QAction(MainWindow);
        action_wigdet->setObjectName("action_wigdet");
        action_wigdet->setIcon(icon12);
        action_wigdet->setMenuRole(QAction::MenuRole::NoRole);
        action = new QAction(MainWindow);
        action->setObjectName("action");
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/qrc/\350\241\250\346\240\274\345\233\276\346\240\207.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        action->setIcon(icon13);
        action->setMenuRole(QAction::MenuRole::NoRole);
        action_13 = new QAction(MainWindow);
        action_13->setObjectName("action_13");
        action_13->setIcon(icon13);
        action_13->setMenuRole(QAction::MenuRole::NoRole);
        action_14 = new QAction(MainWindow);
        action_14->setObjectName("action_14");
        QIcon icon14(QIcon::fromTheme(QIcon::ThemeIcon::SystemLogOut));
        action_14->setIcon(icon14);
        action_14->setMenuRole(QAction::MenuRole::NoRole);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 870, 18));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);

        toolBar->addAction(action_1);
        toolBar->addAction(action_2);
        toolBar->addAction(action_3);
        toolBar->addAction(action_4);
        toolBar->addSeparator();
        toolBar->addAction(action_5);
        toolBar->addAction(action_6);
        toolBar->addAction(action_7);
        toolBar->addAction(action_8);
        toolBar->addSeparator();
        toolBar->addAction(action_11);
        toolBar->addAction(actionwigdet);
        toolBar->addAction(action_wigdet);
        toolBar->addAction(action);
        toolBar->addAction(action_13);
        toolBar->addSeparator();
        toolBar->addAction(actionMDI);
        toolBar->addAction(action_9);
        toolBar->addAction(action_10);
        toolBar->addSeparator();
        toolBar->addAction(action_14);

        retranslateUi(MainWindow);
        QObject::connect(action_14, &QAction::triggered, MainWindow, qOverload<>(&QMainWindow::close));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\345\244\232\347\247\215\347\252\227\345\217\243\346\250\241\345\274\217", nullptr));
        action_1->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272", nullptr));
#if QT_CONFIG(tooltip)
        action_1->setToolTip(QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272\346\226\260\347\232\204\346\226\207\344\273\266", nullptr));
#endif // QT_CONFIG(tooltip)
        action_2->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200", nullptr));
#if QT_CONFIG(tooltip)
        action_2->setToolTip(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
#endif // QT_CONFIG(tooltip)
        action_3->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230", nullptr));
#if QT_CONFIG(tooltip)
        action_3->setToolTip(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230\346\226\207\344\273\266", nullptr));
#endif // QT_CONFIG(tooltip)
        action_4->setText(QCoreApplication::translate("MainWindow", "\345\205\263\351\227\255\345\205\250\351\203\250", nullptr));
#if QT_CONFIG(tooltip)
        action_4->setToolTip(QCoreApplication::translate("MainWindow", "\345\205\263\351\227\255\345\205\250\351\203\250\346\226\207\344\273\266", nullptr));
#endif // QT_CONFIG(tooltip)
        action_5->setText(QCoreApplication::translate("MainWindow", "\345\211\252\345\210\207", nullptr));
#if QT_CONFIG(tooltip)
        action_5->setToolTip(QCoreApplication::translate("MainWindow", "\345\211\252\345\210\207\351\200\211\344\270\255\345\206\205\345\256\271", nullptr));
#endif // QT_CONFIG(tooltip)
        action_6->setText(QCoreApplication::translate("MainWindow", "\345\244\215\345\210\266", nullptr));
#if QT_CONFIG(tooltip)
        action_6->setToolTip(QCoreApplication::translate("MainWindow", "\345\244\215\345\210\266\351\200\211\344\270\255\345\206\205\345\256\271", nullptr));
#endif // QT_CONFIG(tooltip)
        action_7->setText(QCoreApplication::translate("MainWindow", "\350\264\264\350\264\264", nullptr));
#if QT_CONFIG(tooltip)
        action_7->setToolTip(QCoreApplication::translate("MainWindow", "\345\244\215\345\210\266\350\264\264\350\264\264\345\206\205\345\256\271", nullptr));
#endif // QT_CONFIG(tooltip)
        action_8->setText(QCoreApplication::translate("MainWindow", "\345\255\227\344\275\223\350\256\276\347\275\256", nullptr));
#if QT_CONFIG(tooltip)
        action_8->setToolTip(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256\345\255\227\344\275\223\345\206\205\345\256\271\345\255\227\344\275\223", nullptr));
#endif // QT_CONFIG(tooltip)
        actionMDI->setText(QCoreApplication::translate("MainWindow", "MDI\346\250\241\345\274\217", nullptr));
#if QT_CONFIG(tooltip)
        actionMDI->setToolTip(QCoreApplication::translate("MainWindow", "\344\270\273\347\252\227\345\217\243\345\274\200\345\220\257MDI\346\250\241\345\274\217", nullptr));
#endif // QT_CONFIG(tooltip)
        action_9->setText(QCoreApplication::translate("MainWindow", "\347\272\247\350\201\224\345\261\225\345\274\200", nullptr));
#if QT_CONFIG(tooltip)
        action_9->setToolTip(QCoreApplication::translate("MainWindow", "\344\273\245\344\272\222\350\201\224\347\275\221\346\250\241\345\274\217\345\261\225\345\274\200\346\226\207\344\273\266", nullptr));
#endif // QT_CONFIG(tooltip)
        action_10->setText(QCoreApplication::translate("MainWindow", "\345\271\263\351\223\272\345\261\225\345\274\200", nullptr));
#if QT_CONFIG(tooltip)
        action_10->setToolTip(QCoreApplication::translate("MainWindow", "\345\271\263\351\223\272\345\261\225\345\274\200", nullptr));
#endif // QT_CONFIG(tooltip)
        action_11->setText(QCoreApplication::translate("MainWindow", "\345\244\232\347\252\227\345\217\243\346\250\241\345\274\217", nullptr));
#if QT_CONFIG(tooltip)
        action_11->setToolTip(QCoreApplication::translate("MainWindow", "\345\244\232\347\252\227\345\217\243\346\250\241\345\274\217", nullptr));
#endif // QT_CONFIG(tooltip)
        actionwigdet->setText(QCoreApplication::translate("MainWindow", "wigdet", nullptr));
#if QT_CONFIG(tooltip)
        actionwigdet->setToolTip(QCoreApplication::translate("MainWindow", "wigdet\347\252\227\345\217\243", nullptr));
#endif // QT_CONFIG(tooltip)
        action_wigdet->setText(QCoreApplication::translate("MainWindow", "\347\213\254\347\253\213wigdet\347\252\227\345\217\243", nullptr));
#if QT_CONFIG(tooltip)
        action_wigdet->setToolTip(QCoreApplication::translate("MainWindow", "\347\213\254\347\253\213wigdet\347\252\227\345\217\243", nullptr));
#endif // QT_CONFIG(tooltip)
        action->setText(QCoreApplication::translate("MainWindow", "\350\241\250\346\240\274", nullptr));
#if QT_CONFIG(tooltip)
        action->setToolTip(QCoreApplication::translate("MainWindow", "\350\241\250\346\240\274\347\252\227\345\217\243", nullptr));
#endif // QT_CONFIG(tooltip)
        action_13->setText(QCoreApplication::translate("MainWindow", "\347\213\254\347\253\213\350\241\250\346\240\274\347\252\227\345\217\243", nullptr));
#if QT_CONFIG(tooltip)
        action_13->setToolTip(QCoreApplication::translate("MainWindow", "\347\213\254\347\253\213\350\241\250\346\240\274\347\252\227\345\217\243", nullptr));
#endif // QT_CONFIG(tooltip)
        action_14->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
#if QT_CONFIG(tooltip)
        action_14->setToolTip(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272\347\250\213\345\272\217", nullptr));
#endif // QT_CONFIG(tooltip)
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
