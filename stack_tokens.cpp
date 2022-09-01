#include "stack_tokens.h"

void stack_tokens::push(token newElem) {
    elem = new node(newElem, elem);
    _size++;
}

bool stack_tokens::empty() {
    return _size == 0;
}

token stack_tokens::pop() {
    node* prev = elem->prev;
    token elemVal = elem->value;
    delete elem;
    elem = prev;
    --_size;
    return elemVal;
}

token stack_tokens::top() {
    return elem->value;
}

int stack_tokens::size() {
    return _size;
}

void stack_tokens::clear() {
    while (!empty()) {
        pop();
    }
}