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


    
    // ��� ������
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

     string ERROR_DIVIDE_NULL = u8"������ �� ���� ��������� �����������"; //   101
     string ERROR_DIVIDE_MYLONG_TO_FRACTIONAL = u8"������ ������ ������� ����� �� �������"; //  102
     string ERROR_DIVIDE_FRACTIONAL_TO_MYLONG = u8"������ ������ ������� ����� �� �������"; //  103
     string ERROR_TRUGONOMETRIC_FUNCTION = u8"������ ������� ������������������ ������� �� �������� �����"; //  104
     string ERROR_WHILE_POW_GET_MYLONG = u8"��� ���������� � ������� ���������� ������� �����"; //  105
     string ERROR_ODZ_LOG_BASE_1 = u8"��������� ��������� �� ����� ���� 1"; //  106
     string ERROR_ODZ_LOG_BASE_0 = u8"��������� ��������� �� ����� ���� 0";//  107
     string ERROR_ODZ_LOG_NUMBER = u8"��� ������ ��������� ������ ���� ����� ������ 0"; //  108
     string ERROR_LOG_MYLONG = u8"������ ������� �������� �� �������� �����"; //  109
     string ERROR_DEGREE_MYLONG = u8"������ ��������� � ������� �������!"; //  110
     string ERROR_DEGREE_ODZ = u8"������ ��������� � ������� ������� ������������� �����!"; //  111
     string ERROR_DOUBLE_BALANCE = u8"������ ����� ������� �� ������� �� �������� �����"; //  112
     string ERROR_DEGREE_MINUS_MYLONG = u8"������ ��������� ������� ����� � ������������� �������"; // 113
     
    // ������ �������

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

     string ERROR_INCORRECT_END_OF_EXPRESSION = u8"�������� ����� ���������"; // 6
     string ERROR_CHECK_LOG = u8"��������� ������������ ���������� ���������"; // 5
     string ERROR_INCORRECT_SYMBOL = u8"�������� ����������� ������: "; // 3
     string ERROR_INCORRECT_PLACEMENT_OF_PARENTHESES = u8"��������� ������������ ����������� ������"; // 4
     string ERROR_INCORRECT_PLACEMENT_OF_SEPARATORS_IN_NUMBER = u8"�c������� ����� ������ ����������� � ���������� �����"; // 2
     string ERROR_INCORRECT_SYMBOL_BEFORE_NUMBER = u8"�������� ����������� ���� ����� ������"; // 7
     string ERROR_INCORRECT_START_NULL_NUMBER = u8"����� �� ����� ���������� � �������� ����, ����� ����������� ����� � ������� ����� ������"; // 1
};

#endif // DIALOG_ERR_H
