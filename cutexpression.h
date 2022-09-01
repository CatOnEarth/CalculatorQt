#ifndef CUTEXPRESSION_H
#define CUTEXPRESSION_H

using namespace std;

#include <QString>
#include <map>
#include <stack_qstring.h>
#include <set>

enum Type {
    START,
    NUMBER,
    SIGN,
    OPEN,
    CLOSE,
    FUNC,
    SEMILICON,
    CONST
};

class cutexpression
{
public:
    cutexpression(QString);

    ~cutexpression();

    void inizialize_priority();

    void create_postfix_expression();

    QString getPostfixExpression() {return postfix_expression;}

    void find_end_sin_cos(int &, Type&);

    stack_qstring getStackPostfixExpression() { return stack_postfix_expression; }

    vector<QString> getParams() { return parametrs; }


private:

    QString start_expression;
    QString postfix_expression;
    map<QString, int> priority_operations;
    set<QString> operations;
    set<QString> CONSTANTS;
    vector<QString> parametrs;

    stack_qstring stack_postfix_expression;
};

#endif // CUTEXPRESSION_H
