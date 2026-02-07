/********************************************************************************
** Form generated from reading UI file 'ttable.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TTABLE_H
#define UI_TTABLE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TTable
{
public:
    QAction *action_1;
    QAction *action_2;
    QAction *action_3;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTableView *tableView;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;
    QToolBar *toolBar_2;

    void setupUi(QMainWindow *TTable)
    {
        if (TTable->objectName().isEmpty())
            TTable->setObjectName("TTable");
        TTable->resize(478, 328);
        action_1 = new QAction(TTable);
        action_1->setObjectName("action_1");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/qrc/\350\241\250\346\240\274\345\244\247\345\260\217.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        action_1->setIcon(icon);
        action_1->setMenuRole(QAction::MenuRole::NoRole);
        action_2 = new QAction(TTable);
        action_2->setObjectName("action_2");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/qrc/\350\256\276\347\275\256\350\241\250\345\244\264.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        action_2->setIcon(icon1);
        action_2->setMenuRole(QAction::MenuRole::NoRole);
        action_3 = new QAction(TTable);
        action_3->setObjectName("action_3");
        QIcon icon2(QIcon::fromTheme(QIcon::ThemeIcon::SystemLogOut));
        action_3->setIcon(icon2);
        action_3->setMenuRole(QAction::MenuRole::NoRole);
        centralwidget = new QWidget(TTable);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");

        verticalLayout->addWidget(tableView);

        TTable->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TTable);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 478, 18));
        TTable->setMenuBar(menubar);
        statusbar = new QStatusBar(TTable);
        statusbar->setObjectName("statusbar");
        TTable->setStatusBar(statusbar);
        toolBar = new QToolBar(TTable);
        toolBar->setObjectName("toolBar");
        TTable->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);
        toolBar_2 = new QToolBar(TTable);
        toolBar_2->setObjectName("toolBar_2");
        toolBar_2->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);
        TTable->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar_2);

        toolBar_2->addAction(action_1);
        toolBar_2->addAction(action_2);
        toolBar_2->addSeparator();
        toolBar_2->addAction(action_3);

        retranslateUi(TTable);
        QObject::connect(action_3, &QAction::triggered, TTable, qOverload<>(&QMainWindow::close));

        QMetaObject::connectSlotsByName(TTable);
    } // setupUi

    void retranslateUi(QMainWindow *TTable)
    {
        TTable->setWindowTitle(QCoreApplication::translate("TTable", "MainWindow", nullptr));
        action_1->setText(QCoreApplication::translate("TTable", "\350\256\276\347\275\256\350\241\250\346\240\274\345\244\247\345\260\217", nullptr));
#if QT_CONFIG(tooltip)
        action_1->setToolTip(QCoreApplication::translate("TTable", "\350\207\252\345\256\232\344\271\211\350\241\250\346\240\274\345\244\247\345\260\217", nullptr));
#endif // QT_CONFIG(tooltip)
        action_2->setText(QCoreApplication::translate("TTable", "\350\256\276\347\275\256\350\241\250\345\244\264", nullptr));
        action_3->setText(QCoreApplication::translate("TTable", "\351\200\200\345\207\272", nullptr));
#if QT_CONFIG(tooltip)
        action_3->setToolTip(QCoreApplication::translate("TTable", "\351\200\200\345\207\272\347\250\213\345\272\217", nullptr));
#endif // QT_CONFIG(tooltip)
        toolBar->setWindowTitle(QCoreApplication::translate("TTable", "toolBar", nullptr));
        toolBar_2->setWindowTitle(QCoreApplication::translate("TTable", "toolBar_2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TTable: public Ui_TTable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TTABLE_H
