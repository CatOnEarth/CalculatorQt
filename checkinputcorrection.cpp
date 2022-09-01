#include "checkinputcorrection.h"

CheckInputCorrection::CheckInputCorrection()
{

}

enum Example
{
    START,
    NUMBER,
    SIGN,
    FUNC,
    PARENTHESIS_OPEN,
    PARENTHESIS_CLOSE,
};

bool CheckInputCorrection::check_correct_expression(QString expr) {
    bool ans = false;
    QString elem_now;
    QChar current_elem;
    bool flag_first_minus = false;
    stack_qstring stack_operations;

    set<QString> operations;
    operations.insert("*");
    operations.insert("/");
    operations.insert("+");
    operations.insert("-");

    map<QString, int> priority_operations;
    priority_operations["*"] = 20;
    priority_operations["/"] = 20;
    priority_operations["+"] = 10;
    priority_operations["-"] = 10;
    priority_operations["("] = 5;
    priority_operations["["] = 4;

    for (int ii = 0; ii < expr.length(); ++ii) {
        elem_now = "";
        
        if (ii = 0 && expr[ii] == "-") {
            flag_first_minus = true;
        }
        current_elem = expr[ii];

        if (current_elem.isDigit()) { 
            if (current_elem == "0") { // проверка если число с нуля начинается
                if (ii + 1 < expr.length()) {
                    if (expr[ii + 1] != "," && expr[ii + 1] != ".") {
                        throw "ошибка. число не может начинаться с ведущего нуля, кроме случая с нулевой целой частью десятичнго числа";
                    }
                }
            }

            int count_separators = 0;
            for (; count_separators <= 1 && ii < expr.length() && expr[ii+1].isDigit(); ++ii, current_elem = expr[ii]) { // проверка количество точек и запятых в числе
                elem_now += current_elem;
                if (current_elem == ',' || current_elem == '.') {
                    ++count_separators;
                } 
            }
            if (count_separators >= 2) {
                throw "ошибка. ввод числа с одним и более разделителем дробной части";
            }
        }

    return ans;
    }
}
