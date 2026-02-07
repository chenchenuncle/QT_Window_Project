/********************************************************************************
** Form generated from reading UI file 'dialoghead.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGHEAD_H
#define UI_DIALOGHEAD_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialoghead
{
public:
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QListView *listView;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Dialoghead)
    {
        if (Dialoghead->objectName().isEmpty())
            Dialoghead->setObjectName("Dialoghead");
        Dialoghead->resize(326, 153);
        widget = new QWidget(Dialoghead);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, 0, 311, 151));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(widget);
        groupBox->setObjectName("groupBox");
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName("horizontalLayout");
        listView = new QListView(groupBox);
        listView->setObjectName("listView");

        horizontalLayout->addWidget(listView);


        horizontalLayout_2->addWidget(groupBox);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/qrc/\347\241\256\345\256\232.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton->setIcon(icon);

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName("pushButton_2");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/qrc/\345\217\226\346\266\210.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_2->setIcon(icon1);

        verticalLayout->addWidget(pushButton_2);


        horizontalLayout_2->addLayout(verticalLayout);


        retranslateUi(Dialoghead);
        QObject::connect(pushButton, &QPushButton::clicked, Dialoghead, qOverload<>(&QDialog::accept));
        QObject::connect(pushButton_2, &QPushButton::clicked, Dialoghead, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(Dialoghead);
    } // setupUi

    void retranslateUi(QDialog *Dialoghead)
    {
        Dialoghead->setWindowTitle(QCoreApplication::translate("Dialoghead", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Dialoghead", "\350\241\250\345\244\264\345\210\227\350\241\250", nullptr));
        pushButton->setText(QCoreApplication::translate("Dialoghead", "\347\241\256\345\256\232", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Dialoghead", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialoghead: public Ui_Dialoghead {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGHEAD_H
