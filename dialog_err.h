#ifndef DIALOG_ERR_H
#define DIALOG_ERR_H

#include <QDialog>
#include <string>

using namespace std;

namespace Ui {
class Dialog_err;
}

class Dialog_err : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_err(int num_err, QWidget *parent = nullptr);
    ~Dialog_err();

private:
    QString error;
    Ui::Dialog_err *ui;


    
    // мат ошибки
    std::vector<string> err_math;
    void inizialize_err_math() {
        err_math.push_back("error math");
        err_math.push_back(ERROR_DIVIDE_NULL);
        err_math.push_back(ERROR_DIVIDE_MYLONG_TO_FRACTIONAL);
        err_math.push_back(ERROR_DIVIDE_FRACTIONAL_TO_MYLONG);
        err_math.push_back(ERROR_TRUGONOMETRIC_FUNCTION);
        err_math.push_back(ERROR_WHILE_POW_GET_MYLONG);
        err_math.push_back(ERROR_ODZ_LOG_BASE_1);
        err_math.push_back(ERROR_ODZ_LOG_BASE_0);
        err_math.push_back(ERROR_ODZ_LOG_NUMBER);
        err_math.push_back(ERROR_LOG_MYLONG);
        err_math.push_back(ERROR_DEGREE_MYLONG);
        err_math.push_back(ERROR_DEGREE_ODZ);
        err_math.push_back(ERROR_DOUBLE_BALANCE);
        err_math.push_back(ERROR_DEGREE_MINUS_MYLONG);
    }

     string ERROR_DIVIDE_NULL = u8"Делить на ноль запрещено математикой"; //   101
     string ERROR_DIVIDE_MYLONG_TO_FRACTIONAL = u8"Нельзя делить длинное число на дробное"; //  102
     string ERROR_DIVIDE_FRACTIONAL_TO_MYLONG = u8"Нельзя делить дробное число на длинное"; //  103
     string ERROR_TRUGONOMETRIC_FUNCTION = u8"Нельзя считать тригонометрические функции от длинного числа"; //  104
     string ERROR_WHILE_POW_GET_MYLONG = u8"При возведении в степень получилось длинное число"; //  105
     string ERROR_ODZ_LOG_BASE_1 = u8"Основание логарифма не может быть 1"; //  106
     string ERROR_ODZ_LOG_BASE_0 = u8"Основание логарифма не может быть 0";//  107
     string ERROR_ODZ_LOG_NUMBER = u8"Под знаком логарифма должно быть число больше 0"; //  108
     string ERROR_LOG_MYLONG = u8"Нельзя считать логарифм от длинного числа"; //  109
     string ERROR_DEGREE_MYLONG = u8"Нельзя возводить в длинную степень!"; //  110
     string ERROR_DEGREE_ODZ = u8"Нельзя возводить в дробную степень отрицательное число!"; //  111
     string ERROR_DOUBLE_BALANCE = u8"Нельзя брать остаток от деления от дробного числа"; //  112
     string ERROR_DEGREE_MINUS_MYLONG = u8"Нельзя возводить длинное число в отрицательную степень"; // 113
     
    // ошибки разбора

    std::vector<string> err_cutexpression;
    void inizialize_err_curexpr() {
        err_cutexpression.push_back("error cutexpresion");
        err_cutexpression.push_back(ERROR_INCORRECT_START_NULL_NUMBER); // 1
        err_cutexpression.push_back(ERROR_INCORRECT_PLACEMENT_OF_SEPARATORS_IN_NUMBER); // 2
        err_cutexpression.push_back(ERROR_INCORRECT_SYMBOL); // 3
        err_cutexpression.push_back(ERROR_INCORRECT_PLACEMENT_OF_PARENTHESES); // 4
        err_cutexpression.push_back(ERROR_CHECK_LOG); // 5
        err_cutexpression.push_back(ERROR_INCORRECT_END_OF_EXPRESSION); // 6
        err_cutexpression.push_back(ERROR_INCORRECT_SYMBOL_BEFORE_NUMBER); // 7
    }

     string ERROR_INCORRECT_END_OF_EXPRESSION = u8"Неверный конец выражения"; // 6
     string ERROR_CHECK_LOG = u8"Проверьте правильность введенного логарифма"; // 5
     string ERROR_INCORRECT_SYMBOL = u8"Встречен неожиданный символ: "; // 3
     string ERROR_INCORRECT_PLACEMENT_OF_PARENTHESES = u8"Проверьте правильность расстановки скобок"; // 4
     string ERROR_INCORRECT_PLACEMENT_OF_SEPARATORS_IN_NUMBER = u8"Вcтречено более одного разделителя в десятичном числе"; // 2
     string ERROR_INCORRECT_SYMBOL_BEFORE_NUMBER = u8"Встречен неожиданный знак перед числом"; // 7
     string ERROR_INCORRECT_START_NULL_NUMBER = u8"Число не может начинаться с ведущего нуля, кроме десятичного числа с нулевой целой частью"; // 1
};

#endif // DIALOG_ERR_H
