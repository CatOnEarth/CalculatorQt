#include "calculatorwindow.h"
#include "ui_calculatorwindow.h"

CalculatorWindow::CalculatorWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CalculatorWindow)
{
    ui->setupUi(this);
    ui->textEdit_inputexpression->setFocus();
    ui->textEdit_inputexpression->setAlignment(Qt::AlignCenter);
}

CalculatorWindow::~CalculatorWindow()
{
    delete ui;
}

// Цифры

void CalculatorWindow::on_pushButton_number_0_clicked()
{
    const QString text_button = "0";
    ui->textEdit_inputexpression->insertPlainText(text_button);
    ui->textEdit_inputexpression->setFocus();
}

void CalculatorWindow::on_pushButton_number_1_clicked()
{
    ui->textEdit_inputexpression->insertPlainText("1");
    ui->textEdit_inputexpression->setFocus();
}

void CalculatorWindow::on_pushButton_number_2_clicked()
{
    ui->textEdit_inputexpression->insertPlainText("2");
    ui->textEdit_inputexpression->setFocus();
}

void CalculatorWindow::on_pushButton_number_3_clicked()
{
    ui->textEdit_inputexpression->insertPlainText("3");
    ui->textEdit_inputexpression->setFocus();
}

void CalculatorWindow::on_pushButton_number_4_clicked()
{
    ui->textEdit_inputexpression->insertPlainText("4");
    ui->textEdit_inputexpression->setFocus();
}

void CalculatorWindow::on_pushButton_number_5_clicked()
{
    ui->textEdit_inputexpression->insertPlainText("5");
    ui->textEdit_inputexpression->setFocus();
}

void CalculatorWindow::on_pushButton_number_6_clicked()
{
    ui->textEdit_inputexpression->insertPlainText("6");
    ui->textEdit_inputexpression->setFocus();
}

void CalculatorWindow::on_pushButton_number_7_clicked()
{
    ui->textEdit_inputexpression->insertPlainText("7");
    ui->textEdit_inputexpression->setFocus();
}

void CalculatorWindow::on_pushButton_number_8_clicked()
{
    ui->textEdit_inputexpression->insertPlainText("8");
    ui->textEdit_inputexpression->setFocus();
}

void CalculatorWindow::on_pushButton_number_9_clicked()
{
    ui->textEdit_inputexpression->insertPlainText("9");
    ui->textEdit_inputexpression->setFocus();
}



// Операции

void CalculatorWindow::on_pushButton_action_comma_clicked()
{
    ui->textEdit_inputexpression->insertPlainText(",");
    ui->textEdit_inputexpression->setFocus();
}

void CalculatorWindow::on_pushButton_action_point_clicked()
{
    ui->textEdit_inputexpression->insertPlainText(".");
    ui->textEdit_inputexpression->setFocus();
}

void CalculatorWindow::on_pushButton_action_plus_clicked()
{
    ui->textEdit_inputexpression->insertPlainText("+");
    ui->textEdit_inputexpression->setFocus();
}


void CalculatorWindow::on_pushButton_action_minus_clicked()
{
    ui->textEdit_inputexpression->insertPlainText("-");
    ui->textEdit_inputexpression->setFocus();
}

void CalculatorWindow::on_pushButton_action_divide_clicked()
{
    ui->textEdit_inputexpression->insertPlainText("/");
    ui->textEdit_inputexpression->setFocus();
}

void CalculatorWindow::on_pushButton_action_multiply_clicked()
{
    ui->textEdit_inputexpression->insertPlainText("*");
    ui->textEdit_inputexpression->setFocus();
}

void CalculatorWindow::on_pushButton_action_open_round_bracket_clicked()
{
    ui->textEdit_inputexpression->insertPlainText("(");
    ui->textEdit_inputexpression->setFocus();
}

void CalculatorWindow::on_pushButton_action_close_round_bracket_clicked()
{
    ui->textEdit_inputexpression->insertPlainText(")");
    ui->textEdit_inputexpression->setFocus();
}

void CalculatorWindow::on_pushButton_action_open_square_bracket_clicked()
{
    ui->textEdit_inputexpression->insertPlainText("[");
    ui->textEdit_inputexpression->setFocus();
}

void CalculatorWindow::on_pushButton_action_close_square_bracket_clicked()
{
    ui->textEdit_inputexpression->insertPlainText("]");
    ui->textEdit_inputexpression->setFocus();
}

void CalculatorWindow::on_pushButton_clear_input_clicked()
{
    ui->textEdit_inputexpression->clear();
    ui->label_result->clear();
    ui->textBrowser_postfix_expression->clear();
}

void CalculatorWindow::on_pushButton_action_sin_clicked()
{
    ui->textEdit_inputexpression->insertPlainText("sin()");
    ui->textEdit_inputexpression->setFocus();
    QTextCursor textCursor = ui->textEdit_inputexpression->textCursor();
    textCursor.movePosition(QTextCursor::Left);
    ui->textEdit_inputexpression->setTextCursor(textCursor);
}

void CalculatorWindow::on_pushButton_action_cos_clicked()
{
    ui->textEdit_inputexpression->insertPlainText("cos()");
    ui->textEdit_inputexpression->setFocus();
    QTextCursor textCursor = ui->textEdit_inputexpression->textCursor();
    textCursor.movePosition(QTextCursor::Left);
    ui->textEdit_inputexpression->setTextCursor(textCursor);
}

void CalculatorWindow::on_pushButton_action_degree_clicked()
{
    ui->textEdit_inputexpression->insertPlainText("^");
    ui->textEdit_inputexpression->setFocus();
}

void CalculatorWindow::on_pushButton_action_ln_clicked()
{
    ui->textEdit_inputexpression->insertPlainText("ln()");
    ui->textEdit_inputexpression->setFocus();
    QTextCursor textCursor = ui->textEdit_inputexpression->textCursor();
    textCursor.movePosition(QTextCursor::Left);
    ui->textEdit_inputexpression->setTextCursor(textCursor);
}

void CalculatorWindow::on_pushButton_action_log_clicked()
{
    ui->textEdit_inputexpression->insertPlainText("log(;)");
    ui->textEdit_inputexpression->setFocus();
    QTextCursor textCursor = ui->textEdit_inputexpression->textCursor();
    textCursor.movePosition(QTextCursor::Left);
    textCursor.movePosition(QTextCursor::Left);
    ui->textEdit_inputexpression->setTextCursor(textCursor);
}

void CalculatorWindow::on_pushButton_action_balance_clicked()
{
    ui->textEdit_inputexpression->insertPlainText("%");
    ui->textEdit_inputexpression->setFocus();
}

void CalculatorWindow::on_pushButton_action_Pi_clicked()
{
    ui->textEdit_inputexpression->insertPlainText("Pi");
    ui->textEdit_inputexpression->setFocus();
}

void CalculatorWindow::on_pushButton_action_e_clicked()
{
    ui->textEdit_inputexpression->insertPlainText("e");
    ui->textEdit_inputexpression->setFocus();
}


map<QString, QString> CalculatorWindow::set_variables(vector<QString> params) {

    DialogSetVariables dialog(params, this);
    std::vector<QString> values;
    dialog.setModal(true);
    if (dialog.exec() == QDialog::Accepted) {
        values = dialog.getNumbers();
    }
    map<QString, QString> ans;

    for (int ii = 0; ii < values.size(); ++ii) {
        ans[params[ii]] = values[ii];
    }

    return ans;
}

// результат

void CalculatorWindow::on_pushButton_action_result_clicked()
{
    QString input_expr = ui->textEdit_inputexpression->toPlainText();
    if (!input_expr.isEmpty()) {
        cutexpression cut_expr(input_expr);
        QLocale::setDefault(QLocale("ru_RU"));
        try {
            cut_expr.create_postfix_expression();
            ui->textBrowser_postfix_expression->setText(cut_expr.getPostfixExpression());
            map<QString, QString> params_letter_number;
            if (cut_expr.getParams().size() > 0) {
                params_letter_number = set_variables(cut_expr.getParams());
            }

            make_operations count_expression(cut_expr.getStackPostfixExpression().getVectorArray(), params_letter_number);
            count_expression.distribution_of_operations();
            ui->textBrowser_result->setText(count_expression.getStringResult());
            QString item_in_list = input_expr + " = " + count_expression.getStringResult();
            ui->listWidget_journal->addItem(item_in_list);
        }
        catch (int num_err) {
            Dialog_err* dialog_err = new Dialog_err(num_err, this);
            dialog_err->setModal(true);
            dialog_err->exec();
            return;
        }
    }
}

