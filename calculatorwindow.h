#ifndef CALCULATORWINDOW_H
#define CALCULATORWINDOW_H

#include <QMainWindow>
#include "cutexpression.h"
#include <QTextEdit>
#include "make_operations.h"
#include "dialog_err.h"
#include "dialogsetvariables.h"

QT_BEGIN_NAMESPACE
namespace Ui { class CalculatorWindow; }
QT_END_NAMESPACE

class CalculatorWindow : public QMainWindow
{
    Q_OBJECT

public:
    CalculatorWindow(QWidget *parent = nullptr);
    ~CalculatorWindow();

private slots:

    void on_pushButton_number_0_clicked();

    void on_pushButton_action_comma_clicked();

    void on_pushButton_action_point_clicked();

    void on_pushButton_action_plus_clicked();

    void on_pushButton_action_result_clicked();

    void on_pushButton_number_1_clicked();

    void on_pushButton_number_2_clicked();

    void on_pushButton_number_3_clicked();

    void on_pushButton_action_minus_clicked();

    void on_pushButton_number_4_clicked();

    void on_pushButton_number_5_clicked();

    void on_pushButton_number_6_clicked();

    void on_pushButton_number_7_clicked();

    void on_pushButton_number_8_clicked();

    void on_pushButton_number_9_clicked();

    void on_pushButton_action_divide_clicked();

    void on_pushButton_action_multiply_clicked();

    void on_pushButton_action_open_round_bracket_clicked();

    void on_pushButton_action_close_round_bracket_clicked();

    void on_pushButton_action_open_square_bracket_clicked();

    void on_pushButton_action_close_square_bracket_clicked();

    void on_pushButton_clear_input_clicked();

    void on_pushButton_action_sin_clicked();

    void on_pushButton_action_cos_clicked();

    void on_pushButton_action_degree_clicked();

    void on_pushButton_action_ln_clicked();

    void on_pushButton_action_log_clicked();

    void on_pushButton_action_Pi_clicked();

    void on_pushButton_action_e_clicked();

    map<QString, QString> set_variables(vector<QString>);

    void on_pushButton_action_balance_clicked();

private:
    Ui::CalculatorWindow *ui;
};
#endif // CALCULATORWINDOW_H
