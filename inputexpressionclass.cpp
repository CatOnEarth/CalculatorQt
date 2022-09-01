#include "inputexpressionclass.h"

InputExpressionClass::InputExpressionClass()
{

}

long long InputExpressionClass::getLength_expression() const
{
    return length_expression;
}

void InputExpressionClass::setLength_expression(long long value)
{
    length_expression = value;
}

QString InputExpressionClass::getInput_expression() const
{
    return input_expression;
}

void InputExpressionClass::setInput_expression(const QString &value)
{
    input_expression = value;
    length_expression = value.size();
}

Operation InputExpressionClass::getCurrent_operation() const
{
    return current_operation;
}

QString InputExpressionClass::getResult() {
    //stack 
    QString ans;
    return ans;
}

