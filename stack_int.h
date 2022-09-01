#pragma once
#include <iostream>
#include <qstring.h>


struct node {
    QString value = "";
    node* prev = NULL;
    node(QString val, node* prv) : value(val), prev(prv) {}
};

struct stack {
    int _size = 0;
    node* elem = NULL;

    void push(QString num) {
        elem = new node(num, elem);
        _size++;
    }

    bool empty() {
        return _size == 0;
    }

    QString pop() {
        node* prev = elem->prev;
        QString elemVal = elem->value;
        delete elem;
        elem = prev;
        --_size;
        return elemVal;
    }

    QString back() {
        return elem->value;
    }

    int size() {
        return _size;
    }

    void clear() {
        while (!empty()) pop();
    }
};
