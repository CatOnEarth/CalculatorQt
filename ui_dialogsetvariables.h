/********************************************************************************
** Form generated from reading UI file 'dialogsetvariables.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGSETVARIABLES_H
#define UI_DIALOGSETVARIABLES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogSetVariables
{
public:
    QDialogButtonBox *buttonBox;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;

    void setupUi(QDialog *DialogSetVariables)
    {
        if (DialogSetVariables->objectName().isEmpty())
            DialogSetVariables->setObjectName(QString::fromUtf8("DialogSetVariables"));
        DialogSetVariables->resize(400, 300);
        buttonBox = new QDialogButtonBox(DialogSetVariables);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        scrollArea = new QScrollArea(DialogSetVariables);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(20, 10, 351, 221));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 349, 219));
        scrollArea->setWidget(scrollAreaWidgetContents);

        retranslateUi(DialogSetVariables);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogSetVariables, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogSetVariables, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogSetVariables);
    } // setupUi

    void retranslateUi(QDialog *DialogSetVariables)
    {
        DialogSetVariables->setWindowTitle(QCoreApplication::translate("DialogSetVariables", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogSetVariables: public Ui_DialogSetVariables {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGSETVARIABLES_H
