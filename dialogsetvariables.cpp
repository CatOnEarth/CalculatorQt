#include "dialogsetvariables.h"
#include "ui_dialogsetvariables.h"

DialogSetVariables::DialogSetVariables(const std::vector<QString>& data, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogSetVariables)
{
    ui->setupUi(this);
    data_ = data;
    add_textview(data);
}

DialogSetVariables::~DialogSetVariables()
{
    delete ui;
}

void DialogSetVariables::add_textview(const std::vector<QString>& data) {

    ui->scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->scrollArea->setWidgetResizable(true);

    QWidget* scrollAreaContent = new QWidget;
    scrollAreaContent->setLayout(flowLayout);

    ui->scrollArea->setWidget(scrollAreaContent);
    QString param;
    for (int ii = 0; ii < data.size(); ++ii) {
        QLineEdit* mValueEdit = new QLineEdit;
        param = data[ii];
        if (param[0] == "-") {
            param.remove(0, 1);
        }
        QLabel* mTypeLabel = new QLabel(param);

        flowLayout->addRow(mTypeLabel, mValueEdit);
    }

}


std::vector<QString> DialogSetVariables::getNumbers() {
    std::vector<QString> ans;
    int count_params = 0;
    for (int ii = 1; ii <= flowLayout->count(); ii += 2) {
        QLineEdit* bb = qobject_cast<QLineEdit*>(flowLayout->itemAt(ii)->widget());
        QString tt = bb->text();
        try {
            check_input_number(tt);
        }
        catch (int num_err) {
            throw num_err;
        }
        if (data_[count_params][0] == "-") {
            if (tt[0] == "-") {
                tt.remove(0, 1);
            }
            else {
                QString tmp_let = "-" + tt;
                tt = tmp_let;
            }
        }
        ans.push_back(tt);
        ++count_params;
    }
    return ans;
}

void DialogSetVariables::check_input_number(QString& number)
{
    QString without_space;
    for (int ii = 0; ii < number.length(); ++ii) {
        if (number[ii] != " ") {
            without_space.push_back(number[ii]);
        }
    }

    for (int ii = 0; ii < number.length(); ++ii) {
        if (number[ii] == ",") {
            number[ii] = '.';
        }
    }

    QString elem_now = "";
    QChar current_char;
    bool flag_minus;
    for (int ii = 0; ii < number.length(); ++ii) {
        elem_now = "";
        current_char = number[ii];

        if (current_char == "-" && ii == 0) {
            elem_now += "-";
            flag_minus = false;
            continue;
        }

        if (current_char.isDigit()) {
            if (flag_minus) {
                elem_now += "-";
                flag_minus = false;
            }
            elem_now += current_char;
            if ((number.length() >= ii + 1) && current_char == "0" && number[ii + 1].isDigit()) {
                throw 1;
            }

            int count_sep = 0;
            bool flag_separator = false;
            while ((number.length() >= ii + 1) && (number[ii + 1].isDigit() || number[ii + 1] == ".") && count_sep < 2) {
                elem_now += number[ii + 1];
                flag_separator = false;
                if (number[ii + 1] == ".") {
                    ++count_sep;
                    flag_separator = true;
                }
                ++ii;
            }
            if (count_sep >= 2 || flag_separator) {
                throw 2;
            }
        }
        else {
            throw 3;
        }
    }
}
