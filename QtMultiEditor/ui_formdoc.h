/********************************************************************************
** Form generated from reading UI file 'formdoc.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMDOC_H
#define UI_FORMDOC_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormDoc
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

    void setupUi(QWidget *FormDoc)
    {
        if (FormDoc->objectName().isEmpty())
            FormDoc->setObjectName("FormDoc");
        FormDoc->resize(543, 373);
        action_1 = new QAction(FormDoc);
        action_1->setObjectName("action_1");
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::FolderNew));
        action_1->setIcon(icon);
        action_1->setMenuRole(QAction::MenuRole::NoRole);
        action_2 = new QAction(FormDoc);
        action_2->setObjectName("action_2");
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::MailMessageNew));
        action_2->setIcon(icon1);
        action_2->setMenuRole(QAction::MenuRole::NoRole);
        action_3 = new QAction(FormDoc);
        action_3->setObjectName("action_3");
        QIcon icon2(QIcon::fromTheme(QIcon::ThemeIcon::EditCut));
        action_3->setIcon(icon2);
        action_3->setMenuRole(QAction::MenuRole::NoRole);
        action_4 = new QAction(FormDoc);
        action_4->setObjectName("action_4");
        QIcon icon3(QIcon::fromTheme(QIcon::ThemeIcon::EditCopy));
        action_4->setIcon(icon3);
        action_4->setMenuRole(QAction::MenuRole::NoRole);
        action_5 = new QAction(FormDoc);
        action_5->setObjectName("action_5");
        QIcon icon4(QIcon::fromTheme(QIcon::ThemeIcon::EditPaste));
        action_5->setIcon(icon4);
        action_5->setMenuRole(QAction::MenuRole::NoRole);
        action_6 = new QAction(FormDoc);
        action_6->setObjectName("action_6");
        QIcon icon5(QIcon::fromTheme(QIcon::ThemeIcon::DocumentRevert));
        action_6->setIcon(icon5);
        action_6->setMenuRole(QAction::MenuRole::NoRole);
        action_7 = new QAction(FormDoc);
        action_7->setObjectName("action_7");
        QIcon icon6(QIcon::fromTheme(QIcon::ThemeIcon::EditRedo));
        action_7->setIcon(icon6);
        action_7->setMenuRole(QAction::MenuRole::NoRole);
        action_8 = new QAction(FormDoc);
        action_8->setObjectName("action_8");
        QIcon icon7(QIcon::fromTheme(QIcon::ThemeIcon::SystemLogOut));
        action_8->setIcon(icon7);
        action_8->setMenuRole(QAction::MenuRole::NoRole);

        retranslateUi(FormDoc);
        QObject::connect(action_8, &QAction::triggered, FormDoc, qOverload<>(&QWidget::close));

        QMetaObject::connectSlotsByName(FormDoc);
    } // setupUi

    void retranslateUi(QWidget *FormDoc)
    {
        FormDoc->setWindowTitle(QCoreApplication::translate("FormDoc", "Form", nullptr));
        action_1->setText(QCoreApplication::translate("FormDoc", "\346\211\223\345\274\200", nullptr));
#if QT_CONFIG(tooltip)
        action_1->setToolTip(QCoreApplication::translate("FormDoc", "\346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
#endif // QT_CONFIG(tooltip)
        action_2->setText(QCoreApplication::translate("FormDoc", "\345\255\227\344\275\223\350\256\276\347\275\256", nullptr));
#if QT_CONFIG(tooltip)
        action_2->setToolTip(QCoreApplication::translate("FormDoc", "\350\256\276\347\275\256\345\255\227\344\275\223\345\206\205\345\256\271\345\255\227\344\275\223", nullptr));
#endif // QT_CONFIG(tooltip)
        action_3->setText(QCoreApplication::translate("FormDoc", "\345\211\252\345\210\207", nullptr));
#if QT_CONFIG(tooltip)
        action_3->setToolTip(QCoreApplication::translate("FormDoc", "\345\211\252\345\210\207\351\200\211\344\270\255\345\206\205\345\256\271", nullptr));
#endif // QT_CONFIG(tooltip)
        action_4->setText(QCoreApplication::translate("FormDoc", "\345\244\215\345\210\266", nullptr));
#if QT_CONFIG(tooltip)
        action_4->setToolTip(QCoreApplication::translate("FormDoc", "\345\244\215\345\210\266\351\200\211\344\270\255\345\206\205\345\256\271", nullptr));
#endif // QT_CONFIG(tooltip)
        action_5->setText(QCoreApplication::translate("FormDoc", "\350\264\264\350\264\264", nullptr));
#if QT_CONFIG(tooltip)
        action_5->setToolTip(QCoreApplication::translate("FormDoc", "\345\244\215\345\210\266\350\264\264\350\264\264\345\206\205\345\256\271", nullptr));
#endif // QT_CONFIG(tooltip)
        action_6->setText(QCoreApplication::translate("FormDoc", "\346\222\244\351\224\200", nullptr));
#if QT_CONFIG(tooltip)
        action_6->setToolTip(QCoreApplication::translate("FormDoc", "\346\224\276\345\233\236\344\270\212\344\270\200\346\254\241\346\224\271\345\217\230\345\206\205\345\256\271", nullptr));
#endif // QT_CONFIG(tooltip)
        action_7->setText(QCoreApplication::translate("FormDoc", "\345\233\236\344\270\212\346\254\241", nullptr));
#if QT_CONFIG(tooltip)
        action_7->setToolTip(QCoreApplication::translate("FormDoc", "\346\224\276\345\233\236\344\270\213\346\254\241\347\232\204\345\206\205\345\256\271", nullptr));
#endif // QT_CONFIG(tooltip)
        action_8->setText(QCoreApplication::translate("FormDoc", "\345\205\263\351\227\255", nullptr));
#if QT_CONFIG(tooltip)
        action_8->setToolTip(QCoreApplication::translate("FormDoc", "\351\200\200\345\207\272\350\277\231\347\250\213\345\272\217", nullptr));
#endif // QT_CONFIG(tooltip)
    } // retranslateUi

};

namespace Ui {
    class FormDoc: public Ui_FormDoc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMDOC_H
