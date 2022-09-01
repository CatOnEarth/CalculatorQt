#include "make_operations.h"

make_operations::make_operations(vector<QString> vector_expression_, map<QString, QString> params_)
{
    vector_expression = vector_expression_;
    params = params_;
    inizialize();
}

make_operations::~make_operations() {
}

void make_operations::distribution_of_operations() {
    long long initial_number_of_elements_in_vector = count_operations_in_expression();
    QString number_1 = "";
    QString number_2 = "";

    for (int ii = vector_expression.size() - 1; initial_number_of_elements_in_vector > 0 && vector_expression.size() > 0; --ii) {
        QString current_elem = vector_expression[ii];
        
        if (count(operations.begin(), operations.end(), current_elem) != 0) {
            if (current_elem == "+" || current_elem == "-" || current_elem == "*" || current_elem == "/" || current_elem == "%" || current_elem == "^" || current_elem == "log" || current_elem == "-log") {
                number_2 = vector_expression[ii + 1];
                number_1 = vector_expression[ii + 2];

                vector_expression.erase(vector_expression.begin() + ii + 1);
                vector_expression.erase(vector_expression.begin() + ii + 1);
                
                if (current_elem == "+") {
                    vector_expression[ii] = if_plus(number_1, number_2);
                }
                else if (current_elem == "-") {
                    vector_expression[ii] = if_minus(number_1, number_2);
                }
                else if (current_elem == "*") {
                    vector_expression[ii] = if_multiply(number_1, number_2);
                }
                else if (current_elem == "/") {
                    vector_expression[ii] = if_divide(number_1, number_2);
                }
                else if (current_elem == "%") {
                    vector_expression[ii] = if_balance(number_1, number_2);
                }
                else if (current_elem == "^") {
                    vector_expression[ii] = if_degree(number_1, number_2);
                }
                else if (current_elem == "-log") {
                    vector_expression[ii] = QString::number(if_log(number_1, number_2).toDouble() * (-1));
                }
                else if (current_elem == "log") {
                    vector_expression[ii] = if_log(number_1, number_2);
                }
            }
            else if (current_elem == "sin" || current_elem == "-sin" || current_elem == "cos" || current_elem == "-cos" || current_elem == "ln" || current_elem == "-ln") {
                number_1 = vector_expression[ii + 1];
                vector_expression.erase(vector_expression.begin() + ii + 1);

                if (current_elem == "sin") {
                    vector_expression[ii] = if_sin(number_1);
                }
                else if (current_elem == "-sin") {
                    vector_expression[ii] = QString::number(if_sin(number_1).toDouble() * (-1));
                }
                else if (current_elem == "cos") {
                    vector_expression[ii] = if_cos(number_1);
                }
                else if (current_elem == "-cos") {
                    vector_expression[ii] = QString::number(if_cos(number_1).toDouble() * (-1));
                }
                else if (current_elem == "ln") {
                    vector_expression[ii] = if_ln(number_1);
                }
                else if (current_elem == "-ln") {
                    vector_expression[ii] = QString::number(if_ln(number_1).toDouble() * (-1));
                }
            }

            --initial_number_of_elements_in_vector;
        }
        else if (CONSTANTS_NUMBER.find(current_elem) != CONSTANTS_NUMBER.end()) {
            vector_expression[ii] = QString::number(CONSTANTS_NUMBER[current_elem]);
        }
        else if (params.find(current_elem) != params.end()) {
            vector_expression[ii] = params[current_elem];
        }
    }
    for (int ii = vector_expression.size() - 1; ii < vector_expression.size(); ++ii) {
        if (params.find(vector_expression[ii]) != params.end()) {
            vector_expression[ii] = params[vector_expression[ii]];
        }
        else if (CONSTANTS_NUMBER.find(vector_expression[ii]) != CONSTANTS_NUMBER.end()) {
            //vector_expression[ii] = CONSTANTS_NUMBER[vector_expression[ii]];
        }
    }

    getResult();
}

QString make_operations::if_plus(QString number_1, QString number_2) {
    QString ans_str = "0";
    long ans_long;
    if (!number_1.contains(".") && !number_2.contains(".") && !number_1.contains(",") && !number_2.contains(",")) { // если целое
        if (!is_big_number_integer(number_1) && !is_big_number_integer(number_2)) {
            long long_number_1 = number_1.toLong();
            long long_number_2 = number_2.toLong();

            long result_short;
            if (SafeAdd(long_number_1, long_number_2, result_short)) {
                return QString::number(result_short);
            }
            else {
                BigInt big_num_1(long_number_1);
                BigInt big_num_2(long_number_2);
                BigInt result_big = big_num_1 + big_num_2;

                return QString::fromUtf8(result_big.getValue().c_str());
            }
        }
        else {

            BigInt big_num_1(number_1.toStdString());
            BigInt big_num_2(number_2.toStdString());
            BigInt result_big = big_num_1 + big_num_2;

            return QString::fromUtf8(result_big.getValue().c_str());
        }
    } else { // оба дробные
        double result = number_1.toDouble() + number_2.toDouble();
        return QString::number(result);
    }

    return ans_str;
}

QString make_operations::if_minus(QString number_1, QString number_2) {
    QString ans_str = "0";
    long ans_long;
    if (!number_1.contains(".") && !number_2.contains(".") && !number_1.contains(",") && !number_2.contains(",")) { // если целое
        if (!is_big_number_integer(number_1) && !is_big_number_integer(number_2)) {
            long long_number_1 = number_1.toLong();
            long long_number_2 = number_2.toLong();

            long result_short;
            if (long_number_1 >= 0 && long_number_2 >= 0) {
                return QString::number(long_number_1 - long_number_2);
            }
            else if (long_number_1 < 0 && long_number_2 >= 0 && abs(long_number_1) + long_number_2 <= LONG_MAX) {
                return QString::number(long_number_1 - long_number_2);
            }
            else if (long_number_1 >= 0 && long_number_2 < 0 && long_number_1 + abs(long_number_2) <= LONG_MAX) {
                return QString::number(long_number_1 - long_number_2);
            }
            else if (long_number_1 < 0 && long_number_2 < 0 && abs(long_number_1) + abs(long_number_2) <= LONG_MAX) {
                return QString::number(long_number_1 - long_number_2);
            }
            else {
                BigInt big_num_1(long_number_1);
                BigInt big_num_2(long_number_2);
                BigInt result_big = big_num_1 - big_num_2;

                return QString::fromUtf8(result_big.getValue().c_str());
            }
        }
        else {

            BigInt big_num_1(number_1.toStdString());
            BigInt big_num_2(number_2.toStdString());
            BigInt result_big = big_num_1 - big_num_2;

            return QString::fromUtf8(result_big.getValue().c_str());
        }
    }
    else { // оба дробные
        double result = number_1.toDouble() - number_2.toDouble();
        return QString::number(result);
    }

    return ans_str;
}

QString make_operations::if_multiply(QString number_1, QString number_2) {
    QString ans_str = "0";

    if (!number_1.contains(".") && !number_2.contains(".") && !number_1.contains(",") && !number_2.contains(",")) { // если целое
        if (!is_big_number_integer(number_1) && !is_big_number_integer(number_2)) {
            long long_number_1 = number_1.toLong();
            long long_number_2 = number_2.toLong();

            long result_short;

            if (SafeMultiply(long_number_1, long_number_2, result_short)) {
                return QString::number(result_short);
            }
            else {
                BigInt big_num_1(long_number_1);
                BigInt big_num_2(long_number_2);
                BigInt result_big = big_num_1 * big_num_2;

                return QString::fromUtf8(result_big.getValue().c_str());
            }
        }
        else {

            BigInt big_num_1(number_1.toStdString());
            BigInt big_num_2(number_2.toStdString());
            BigInt result_big = big_num_1 * big_num_2;

            return QString::fromUtf8(result_big.getValue().c_str());
        }
    }
    else { // оба дробные
        double result = number_1.toDouble() * number_2.toDouble();
        return QString::number(result);
    }

    return ans_str;
}

QString make_operations::if_divide(QString number_1, QString number_2) {
    QString ans_str = "0";

    if (!number_1.contains(".") && !number_2.contains(".")) { // если целое
        if (!is_big_number_integer(number_1) && !is_big_number_integer(number_2)) {
            long long_number_1 = number_1.toLong();
            long long_number_2 = number_2.toLong();

            if (long_number_2 == 0) {
                throw 101;
            }

            long result_short;

            if (!SafeDivide(long_number_1, long_number_2, result_short)) {
                return QString::number(result_short);
            }
            else {
                BigInt big_num_1(long_number_1);
                BigInt big_num_2(long_number_2);
                BigInt result_big = big_num_1 / big_num_2;

                return QString::fromUtf8(result_big.getValue().c_str());
            }
        }
        else {

            BigInt big_num_1(number_1.toStdString());
            BigInt big_num_2(number_2.toStdString());
            
            BigInt result_big = big_num_1 / big_num_2;

            return QString::fromUtf8(result_big.getValue().c_str());
        }
    }
    else if (is_big_number_integer(number_1) && (number_2.contains(".") || number_2.contains(","))) {
        throw 102;
    }
    else if (is_big_number_integer(number_2) && (number_1.contains(".") || number_1.contains(","))) {
        throw 103;
    }
    else { // оба дробные
        double result = number_1.toDouble() / number_2.toDouble();
        return QString::number(result);
    }

    return ans_str;
}

QString make_operations::if_balance(QString number_1, QString number_2)
{
    QString ans = "";
    if (!number_1.contains(".") && !number_2.contains(".")) {
        if (!is_big_number_integer(number_1) && !is_big_number_integer(number_2)) {
            long long_number_1 = number_1.toLong();
            long long_number_2 = number_2.toLong();

            if (long_number_2 == 0) {
                throw 101;
            }

            return QString::number(long_number_1 % long_number_2);
        }
        else {
            if (number_2 == "0") {
                throw 101;
            }
            BigInt big_number_1(number_1.toStdString());
            BigInt big_number_2(number_2.toStdString());
            BigInt res = big_number_1 % big_number_2;
            return QString::fromStdString(res.getValue());
        }
    }
    else {
        throw 112;
    }
}

QString make_operations::if_sin(QString number_1) {
    QString ans_str = "0";

    if (!number_1.contains(".") && !number_1.contains(",")) { // если целое
        if (!is_big_number_integer(number_1)) {
            long long_number_1 = number_1.toLong();

            return QString::number(std::sin(long_number_1));
        }
        else {
            throw 104;
        }
    }

    else { // оба дробные
        return QString::number(std::sin(number_1.toDouble()));
    }

    return ans_str;
}

QString make_operations::if_cos(QString number_1) {
    QString ans_str = "0";

    if (!number_1.contains(".") && !number_1.contains(",")) { // если целое
        if (!is_big_number_integer(number_1)) {
            long long_number_1 = number_1.toLong();

            return QString::number(std::cos(long_number_1));
        }
        else {
            throw 104;
        }
    }
    else { // оба дробные
        return QString::number(std::cos(number_1.toDouble()));
    }

    return ans_str;
}

 QString make_operations::if_degree(QString number_1, QString number_2) {
     QString ans_str = "0";

     if (!number_1.contains(".") && !number_2.contains(".")) { // если целое
         if (!is_big_number_integer(number_1) && !is_big_number_integer(number_2)) {
             long long_number_1 = number_1.toLong();
             long long_number_2 = number_2.toLong();

             if (long_number_2 > 0) {
                 long result_short;
                 result_short = pow(long_number_1, long_number_2);
                 if (result_short == LONG_MIN) {
                     throw 105;
                 }
                 return QString::number(result_short);
             }
             else {
                 double result_short;
                 result_short = pow(long_number_1, long_number_2);

                 return QString::number(result_short);
             }
         }
         else if (is_big_number_integer(number_1) && !is_big_number_integer(number_2)) {
             if (number_2.toLong() < 0) {
                 throw 113;
             }
             BigInt big_num_1(number_1.toStdString());
             long big_num_2 = number_2.toLong();
             string ans_degree = big_num_1.pow(big_num_2).getValue();
             return QString::fromStdString(ans_degree);
         }
         else {
             throw 110;
         }
     }
     else { // оба дробные
         double double_num_1 = number_1.toDouble();
         double double_num_2 = number_2.toDouble();
         if (double_num_1 < 0 && number_2.contains(".")) {
             throw 111;
         }
         
         return QString::number(pow(double_num_1, double_num_2));
     }

     return ans_str;
 }

 QString make_operations::if_log(QString base, QString number) {
     QString ans_str = "0";

     if (!base.contains(".") && !number.contains(".") && !base.contains(",") && !number.contains(",")) { // если целое
         if (!is_big_number_integer(base) && !is_big_number_integer(number)) {
             long base_long = base.toDouble();
             long number_long = number.toDouble();
             if (base_long != 1 && base_long > 0 && number_long > 0) {
                 return QString::number(log(number_long) / log(base_long));
             }
             else if (base_long == 1) {
                 throw 106;
             }
             else if (base_long <= 0) {
                 throw 107;
             }
             else if (number_long <= 0) {
                 throw 108;
             }
         }
         else {
             throw 109;
         }
     }
     else { // оба дробные
         double base_double = base.toDouble();
         double number_double = number.toDouble();
         if (base_double != 1 && base_double > 0 && number_double > 0) {
             return QString::number(log(number_double) / log(base_double));
         }
         else if (base_double == 1) {
             throw 106;
         }
         else if (base_double <= 0) {
             throw 107;
         }
         else if (number_double <= 0) {
             throw 108;
         }
     }

     return ans_str;
 }

 QString make_operations::if_ln(QString number) {
     QString ans_str = "0";

     if (!number.contains(".") && !number.contains(",")) { // если целое
         if (!is_big_number_integer(number)) {
             long number_long = number.toDouble();
             if (number_long > 0) {
                 return QString::number(log(number_long));
             }
             else {
                 throw 108;
             }
         }
         else {
             throw 109;
         }
     }
     else { // оба дробные
         double number_double = number.toDouble();
         if (number_double > 0) {
             return QString::number(log(number_double));
         }
         else {
             throw 108;
         }
     }

     return ans_str;
 }

bool make_operations::is_big_number_integer(QString number) {
    int MAX_IN_LONG_PLUS = 10;
    int MAX_IN_LONG_MINUS = 11;

    if (number.length() == MAX_IN_LONG_PLUS && number[0] != "-") { // +
        if (QString(number[0]).toInt() <= 2) {
            if (QString(number[1]).toInt() <= 1) {
                if (QString(number[2]).toInt() <= 4) {
                    if (QString(number[3]).toInt() <= 7) {
                        if (QString(number[4]).toInt() <= 4) {
                            if (QString(number[5]).toInt() <= 8) {
                                if (QString(number[6]).toInt() <= 3) {
                                    if (QString(number[7]).toInt() <= 6) {
                                        if (QString(number[8]).toInt() <= 4) {
                                            if (QString(number[9]).toInt() <= 7) {
                                                return false;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        return true;
    }
    else if (number.length() == MAX_IN_LONG_MINUS && number[0] == "-") { // -
        if (QString(number[1]).toInt() <= 2) {
            if (QString(number[2]).toInt() <= 1) {
                if (QString(number[3]).toInt() <= 4) {
                    if (QString(number[4]).toInt() <= 7) {
                        if (QString(number[5]).toInt() <= 4) {
                            if (QString(number[6]).toInt() <= 8) {
                                if (QString(number[7]).toInt() <= 3) {
                                    if (QString(number[8]).toInt() <= 6) {
                                        if (QString(number[9]).toInt() <= 4) {
                                            if (QString(number[10]).toInt() <= 8) {
                                                return false;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        return true;
    }
    else if (number.length() < 10) {
        return false;
    }
    else {
        return true;
    }

    return true;
}

long long make_operations::count_operations_in_expression() {
    long long count_operations = 0;
    for (int ii = 0; ii < operations.size(); ++ii) {
        count_operations += count(vector_expression.begin(), vector_expression.end(), operations[ii]);
    }

    return count_operations;
}

void make_operations::inizialize() {
    QString elem_now = "";
    QString operations_string = { "+,-,*,/,%,^,cos,sin,-sin,-cos,log,-log,ln,-ln" };
    for (int ii = 0; ii < operations_string.length(); ++ii) {
        if (operations_string[ii] != ",") {
            elem_now += operations_string[ii];
        }
        else {
            operations.push_back(elem_now);
            elem_now = "";
        }
    }

    CONSTANTS_NUMBER["Pi"] = M_PI;
    CONSTANTS_NUMBER["e"] = EULER_NUMBER;
    CONSTANTS_NUMBER["-Pi"] = (-1) * M_PI;
    CONSTANTS_NUMBER["-e"] = (-1) * EULER_NUMBER;
}

void make_operations::getResult() {
    result_operations = vector_expression[0];
}
