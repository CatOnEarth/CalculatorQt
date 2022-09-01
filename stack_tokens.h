#ifndef STACK_TOKENS_H
#define STACK_TOKENS_H

#include <QString>
#include <vector>
#include <set>
#include <QChar>
#include <map>

using namespace std;

enum Elemtype {
    //Переменная, константа, (, ), функция, операция, {, }
    var, num, op_br, cl_br, func, op, op_sbr, cl_sbr
};

struct token {
    QString name;
    Elemtype type;

    //Конструкторы
    token(QString str, Elemtype typ) {
        name = str;
        type = typ;
    }
    token() {}
};

//Массив токенов
typedef vector<token> tokens;


class stack_tokens
{
public:
    void push(token newElem);
    bool empty();
    token pop();
    token top();
    int size();
    void clear();


private:
    struct node {
        token value;
        node* prev = NULL;
        node(token val, node* prv) : value(val), prev(prv) {}
    };

    int _size = 0;
    node* elem = NULL;
};

#endif // STACK_TOKENS_H
