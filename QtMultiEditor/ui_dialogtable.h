/********************************************************************************
** Form generated from reading UI file 'dialogtable.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGTABLE_H
#define UI_DIALOGTABLE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_Dialogtable
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QSpinBox *spinBox;
    QPushButton *pushButton;
    QLabel *label_2;
    QSpinBox *spinBox_2;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Dialogtable)
    {
        if (Dialogtable->objectName().isEmpty())
            Dialogtable->setObjectName("Dialogtable");
        Dialogtable->resize(202, 151);
        gridLayout = new QGridLayout(Dialogtable);
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(Dialogtable);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        spinBox = new QSpinBox(Dialogtable);
        spinBox->setObjectName("spinBox");
        spinBox->setWrapping(false);
        spinBox->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::PlusMinus);
        spinBox->setStepType(QAbstractSpinBox::StepType::DefaultStepType);

        gridLayout->addWidget(spinBox, 0, 1, 1, 1);

        pushButton = new QPushButton(Dialogtable);
        pushButton->setObjectName("pushButton");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/qrc/\347\241\256\345\256\232.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton->setIcon(icon);

        gridLayout->addWidget(pushButton, 0, 2, 1, 1);

        label_2 = new QLabel(Dialogtable);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        spinBox_2 = new QSpinBox(Dialogtable);
        spinBox_2->setObjectName("spinBox_2");

        gridLayout->addWidget(spinBox_2, 1, 1, 1, 1);

        pushButton_2 = new QPushButton(Dialogtable);
        pushButton_2->setObjectName("pushButton_2");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/qrc/\345\217\226\346\266\210.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_2->setIcon(icon1);

        gridLayout->addWidget(pushButton_2, 1, 2, 1, 1);


        retranslateUi(Dialogtable);
        QObject::connect(pushButton_2, &QPushButton::clicked, Dialogtable, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(Dialogtable);
    } // setupUi

    void retranslateUi(QDialog *Dialogtable)
    {
        Dialogtable->setWindowTitle(QCoreApplication::translate("Dialogtable", "\350\256\276\347\275\256\350\241\250\346\240\274\345\244\247\345\260\217", nullptr));
        label->setText(QCoreApplication::translate("Dialogtable", "\350\241\214\346\225\260\357\274\232", nullptr));
        pushButton->setText(QCoreApplication::translate("Dialogtable", "\347\241\256\345\256\232", nullptr));
        label_2->setText(QCoreApplication::translate("Dialogtable", "\345\210\227\346\225\260\357\274\232", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Dialogtable", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialogtable: public Ui_Dialogtable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGTABLE_H
