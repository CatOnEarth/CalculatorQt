#pragma once
#include <qstring.h>
#include<vector>
#include <algorithm>

using namespace std;

class stack_qstring
{
public:
    void push(QString newElem);
    bool empty();
    QString pop();
    QString back();
    int size();
    void clear();

    vector<QString> getVectorArray();


private:
    struct node {
        QString value = "";
        node* prev = NULL;
        node(QString val, node* prv) : value(val), prev(prv) {}
    };

    int _size = 0;
    node* elem = NULL;
};

