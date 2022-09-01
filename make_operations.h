#ifndef MAKE_OPERATIONS_H
#define MAKE_OPERATIONS_H

# define M_PI 3.1415926535 /* pi */
# define EULER_NUMBER  2.7182818284  /* e */


#include "stack_qstring.h"
#include <set>
#include "SafeInt.h"
#include "BigInt.h"
#include <cmath>
#include <map>
#include <qlocale.h>

class make_operations
{
public:
    make_operations(vector<QString>, map<QString, QString>);
    ~make_operations();

    void inizialize();

    bool is_big_number_integer(QString);
    bool is_big_number_double(QString);

    void distribution_of_operations();
    long long count_operations_in_expression();

    void getResult();

    QString getStringResult() { return result_operations; }

private:
    vector<QString> vector_expression;
    QString result_operations = "";
    vector<QString> operations;
    map<QString, QString> params;

    QString if_plus(QString, QString);
    QString if_minus(QString, QString);
    QString if_multiply(QString, QString);
    QString if_divide(QString, QString);
    QString if_balance(QString, QString);
    QString if_sin(QString);
    QString if_cos(QString);
    QString if_degree(QString, QString);
    QString if_log(QString, QString);
    QString if_ln(QString);

    map<QString, double> CONSTANTS_NUMBER;

};

#endif // MAKE_OPERATIONS_H
