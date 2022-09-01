/********************************************************************************
** Form generated from reading UI file 'dialog_err.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_ERR_H
#define UI_DIALOG_ERR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Dialog_err
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label_text_error;

    void setupUi(QDialog *Dialog_err)
    {
        if (Dialog_err->objectName().isEmpty())
            Dialog_err->setObjectName(QString::fromUtf8("Dialog_err"));
        Dialog_err->resize(373, 147);
        buttonBox = new QDialogButtonBox(Dialog_err);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(20, 110, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label_text_error = new QLabel(Dialog_err);
        label_text_error->setObjectName(QString::fromUtf8("label_text_error"));
        label_text_error->setGeometry(QRect(30, 20, 321, 81));
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(12);
        label_text_error->setFont(font);

        retranslateUi(Dialog_err);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog_err, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog_err, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog_err);
    } // setupUi

    void retranslateUi(QDialog *Dialog_err)
    {
        Dialog_err->setWindowTitle(QCoreApplication::translate("Dialog_err", "Dialog", nullptr));
        label_text_error->setText(QCoreApplication::translate("Dialog_err", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_err: public Ui_Dialog_err {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_ERR_H
