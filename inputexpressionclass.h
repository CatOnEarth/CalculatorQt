#ifndef INPUTEXPRESSIONCLASS_H
#define INPUTEXPRESSIONCLASS_H

#include <QString>
#include "stack_int.h"

enum Operation
    {
        Subtract,
        Summation,
        Multiply,
        Divide,
        sin_,
        cos_,
        log_,
        Null_
    };

class InputExpressionClass
{
public:
    InputExpressionClass();

    long long getLength_expression() const;
    void setLength_expression(long long value);

    QString getInput_expression() const;
    void setInput_expression(const QString &value);

    Operation getCurrent_operation() const;

    QString getResult();


private:
    long long length_expression;
    QString input_expression;
    Operation current_operation;
};

#endif // INPUTEXPRESSIONCLASS_H
