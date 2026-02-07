/********************************************************************************
** Form generated from reading UI file 'widget_edit.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_EDIT_H
#define UI_WIDGET_EDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_widget_edit
{
public:
    QHBoxLayout *horizontalLayout;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QWidget *widget_edit)
    {
        if (widget_edit->objectName().isEmpty())
            widget_edit->setObjectName("widget_edit");
        widget_edit->resize(395, 269);
        horizontalLayout = new QHBoxLayout(widget_edit);
        horizontalLayout->setObjectName("horizontalLayout");
        plainTextEdit = new QPlainTextEdit(widget_edit);
        plainTextEdit->setObjectName("plainTextEdit");

        horizontalLayout->addWidget(plainTextEdit);


        retranslateUi(widget_edit);

        QMetaObject::connectSlotsByName(widget_edit);
    } // setupUi

    void retranslateUi(QWidget *widget_edit)
    {
        widget_edit->setWindowTitle(QCoreApplication::translate("widget_edit", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class widget_edit: public Ui_widget_edit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_EDIT_H
