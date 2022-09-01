#include "stack_qstring.h"

void stack_qstring::push(QString newElem) {
    elem = new node(newElem, elem);
    _size++;
}

bool stack_qstring::empty() {
    return _size == 0;
}

QString stack_qstring::pop() {
    node* prev = elem->prev;
    QString elemVal = elem->value;
    delete elem;
    elem = prev;
    --_size;
    return elemVal;
}

QString stack_qstring::back() {
    return elem->value;
}

int stack_qstring::size() {
    return _size;
}

void stack_qstring::clear() {
    while (!empty()) {
        pop();
    }
}

vector<QString> stack_qstring::getVectorArray() {
    vector<QString> ans;
    node* tmp_elem = elem;
    while (tmp_elem != NULL) {
        ans.push_back(tmp_elem->value);
        tmp_elem = tmp_elem->prev;
    }

    delete tmp_elem;

   // reverse(ans.begin(), ans.end());
    return ans;
}
