#include "dialog_err.h"
#include "ui_dialog_err.h"

Dialog_err::Dialog_err(int err_, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_err)
{
    QString err_text;
    if (err_ < 100) {
        inizialize_err_curexpr();
        err_text = QString::fromStdString(err_cutexpression[err_]);
    }
    else if ( err_ > 100 && err_ < 200){
        inizialize_err_math();
        err_text = QString::fromStdString(err_math[err_ - 100]);
    }
    QLocale::setDefault(QLocale("ru_RU"));
    ui->setupUi(this);
    ui->label_text_error->setWordWrap(true);
    ui->label_text_error->setText(err_text);
    
}

Dialog_err::~Dialog_err()
{
    delete ui;
}
