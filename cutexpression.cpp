#include "cutexpression.h"

cutexpression::cutexpression(QString expression_)
{
    start_expression = expression_.trimmed();
    postfix_expression = "";
    priority_operations.clear();
    operations.clear();
    stack_postfix_expression.clear();
    inizialize_priority();
    
}

cutexpression::~cutexpression()
{
    stack_postfix_expression.clear();
}

void cutexpression::create_postfix_expression() {
    std::vector<short> start_stop_log; // 0 - начал log; 1 - точка с запятой;
    Type now_category = START;
    stack_qstring stack_operations;
    QString elem_now = "";
    QChar current_char;
    QString tmp_back_stack;
    bool flag_minus = false;

    QString without_space;
    for (int ii = 0; ii < start_expression.length(); ++ii) {
        if (start_expression[ii] != " ") {
            without_space.push_back(start_expression[ii]);
        }
    }

    start_expression = without_space;

    for (int ii = 0; ii < start_expression.length(); ++ii) {
        if (start_expression[ii] == ",") {
            start_expression[ii] = '.';
        }
    }

    for (int ii = 0; ii < start_expression.length(); ++ii) {
        elem_now = "";
        current_char = start_expression[ii];
        
        if (current_char == "-" && (now_category == START || now_category == OPEN || now_category == SEMILICON)) {
            flag_minus = true;
            continue;
        }
        if (current_char.isDigit()) {
            if (now_category == START || now_category == SIGN || now_category == OPEN || now_category == SEMILICON) {
                now_category = NUMBER;
                if (flag_minus) {
                    elem_now += "-";
                    flag_minus = false;
                }
                elem_now += current_char;
                if ((start_expression.length() >= ii + 1) && current_char == "0" && start_expression[ii + 1].isDigit()) {
                    throw 1;
                }

                int count_sep = 0;
                bool flag_separator = false;
                while ((start_expression.length() >= ii + 1) && (start_expression[ii + 1].isDigit() || start_expression[ii + 1] == ".") && count_sep < 2) {
                    elem_now += start_expression[ii + 1];
                    flag_separator = false;
                    if (start_expression[ii + 1] == ".") {
                        ++count_sep;
                        flag_separator = true;
                    }
                    ++ii;
                }
                if (count_sep >= 2 || flag_separator) {
                    throw 2;
                }
                stack_postfix_expression.push(elem_now);
                postfix_expression += elem_now + " ";

                continue;
            }
            else {
                throw 3;
            }
        }
        else if (operations.count(current_char) != 0) {
            if (now_category == NUMBER || now_category == CLOSE) {
                now_category = SIGN;
                while (!stack_operations.empty() && ((priority_operations[stack_operations.back()] >= priority_operations[current_char] && current_char != "^")
                    || (priority_operations[stack_operations.back()] > priority_operations[current_char] && current_char == "^"))) {
                    stack_postfix_expression.push(stack_operations.back());
                    postfix_expression += stack_operations.pop() + " ";
                }
                stack_operations.push(current_char);
            }
            else {
                throw 3;
            }
        }
        else if (current_char == "(" || current_char == "[") {
            if (flag_minus) {
                flag_minus = false;
                stack_postfix_expression.push("-1");
                postfix_expression += " -1 ";
                while (!stack_operations.empty() && priority_operations[stack_operations.back()] >= priority_operations["*"]) {
                    stack_postfix_expression.push(stack_operations.back());
                    postfix_expression += stack_operations.pop() + " ";
                }
                stack_operations.push("*");

                now_category = OPEN;
                stack_operations.push(current_char);
            }
            else if (now_category == SIGN || now_category == FUNC || now_category == START || now_category == SEMILICON || now_category == OPEN) {
                now_category = OPEN;
                stack_operations.push(current_char);
            }
            else {
                throw 3;
            }
        }
        else if (current_char == ")" || current_char == "]") {
            if (now_category == CLOSE || now_category == NUMBER) {
                now_category = CLOSE;
                int type_;
                if (stack_operations.empty()) {
                    throw 4;
                }
                if (current_char == ")") {
                    type_ = priority_operations["("];
                }
                else {
                    type_ = priority_operations["["];
                }
                while (!stack_operations.empty() && priority_operations[stack_operations.back()] != type_) {
                    if ((stack_operations.back() == "(" && type_ == priority_operations["["]) || (stack_operations.back() == "[" &&
                        type_ == priority_operations["("])) {

                        throw 4;
                    }
                    if (stack_operations.back() == "log" || stack_operations.back() == "-log") {
                        if (start_stop_log.size() > 0) {
                            if (start_stop_log[start_stop_log.size() - 1] != 1) {
                                throw 5;
                            }
                            else {
                                start_stop_log.pop_back();

                            }
                        }
                        else {
                            throw 5;
                        }
                    }
                    stack_postfix_expression.push(stack_operations.back());
                    postfix_expression += stack_operations.pop() + " ";
                }
                if (!stack_operations.empty() && priority_operations[stack_operations.back()] == type_) {
                    stack_operations.pop();
                    if (!stack_operations.empty()) {
                        if (stack_operations.back() == "log" || stack_operations.back() == "-log") {
                            if (start_stop_log.size() > 0) {
                                if (start_stop_log[start_stop_log.size() - 1] != 1) {
                                    throw 5;
                                }
                                else {
                                    start_stop_log.pop_back();
                                    stack_postfix_expression.push(stack_operations.back());
                                    postfix_expression += stack_operations.pop() + " ";
                                }
                            }
                            else {
                                throw 5;
                            }
                        }
                    }
                }
            }
            else {
                throw 3;
            }
        }
        else if (current_char.isLetter()) {
            if (now_category == SIGN || now_category == START || now_category == OPEN || now_category == SEMILICON) {
                if (flag_minus) {
                    elem_now += "-";
                    flag_minus = false;
                }
                while ((start_expression.length() >= ii + 1) && start_expression[ii].isLetter()) {
                    elem_now += start_expression[ii];
                    ++ii;
                }
                --ii;

                if (operations.find(elem_now) != operations.end()) {
                    now_category = FUNC;
                    if (elem_now == "log" || elem_now == "-log") {
                        start_stop_log.push_back(0);
                    }
                    stack_operations.push(elem_now);
                }
                else if (CONSTANTS.find(elem_now) != CONSTANTS.end()) {
                    now_category = NUMBER;
                    stack_postfix_expression.push(elem_now);
                    postfix_expression += elem_now + " ";
                }
                else {
                    now_category = NUMBER; // переменная
                    stack_postfix_expression.push(elem_now);
                    postfix_expression += elem_now;
                    if (find(parametrs.begin(), parametrs.end(), elem_now) == parametrs.end()) {
                        parametrs.push_back(elem_now);
                    }
                }

                continue;
            }
            else {
                throw 3;
            }
        }
        else if (current_char == ";") {
            if (now_category == CLOSE || now_category == NUMBER) {
                now_category = SEMILICON;
                if (start_stop_log.size() > 0) {
                    if (start_stop_log[start_stop_log.size() - 1] == 0) {
                        start_stop_log[start_stop_log.size() - 1] = 1;
                    }
                    else {
                        throw 5;
                    }
                }
                else {
                    throw 5;
                }
                while (!stack_operations.empty() && priority_operations[stack_operations.back()] != priority_operations["("]) {
                    stack_postfix_expression.push(stack_operations.back());
                    postfix_expression += stack_operations.pop() + " ";
                }
            }
            else {
                throw 5;
            }
        }
        else if (flag_minus) {
            throw 7;
        }
        else {
            throw 3;
        }
    }
    
    if (now_category == OPEN || now_category == SIGN || now_category == FUNC) {
        throw 6;
    }

    while (!stack_operations.empty()) {
        if (stack_operations.back() == "(" || stack_operations.back() == "[" || stack_operations.back() == ")" || stack_operations.back() == "]") {
            throw 4;
        }
        stack_postfix_expression.push(stack_operations.back());
        postfix_expression += stack_operations.pop() + " ";
    }

    if (start_stop_log.size() != 0) {
        throw 5;
    }
}

void cutexpression::inizialize_priority() {
    priority_operations["^"] = 25;
    priority_operations["*"] = 20;
    priority_operations["/"] = 20;
    priority_operations["%"] = 20;
    priority_operations["+"] = 10;
    priority_operations["-"] = 10;
    priority_operations["("] = 5;
    priority_operations["["] = 4;
    priority_operations["sin"] = 20; // sin
    priority_operations["cos"] = 20; // cos
    priority_operations["-sin"] = 20; // sin
    priority_operations["-cos"] = 20; // cos
    priority_operations["log"] = 20; // log
    priority_operations["-log"] = 20; // log
    priority_operations["ln"] = 20; // log
    priority_operations["-ln"] = 20; // log

    operations.insert("*");
    operations.insert("/");
    operations.insert("%");
    operations.insert("+");
    operations.insert("-");
    operations.insert("^");
    operations.insert("cos");
    operations.insert("sin");
    operations.insert("-cos");
    operations.insert("-sin");
    operations.insert("log");
    operations.insert("-log");
    operations.insert("ln");
    operations.insert("-ln");

    CONSTANTS.insert("Pi");
    CONSTANTS.insert("e");
    CONSTANTS.insert("-e");
    CONSTANTS.insert("-Pi");
}

