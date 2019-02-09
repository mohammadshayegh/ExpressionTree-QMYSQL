#ifndef STACK_H
#define STACK_H
#include "node.h"

struct stack{
    node *pos ;
    stack* next ;
};


class Stack
{
public:
    stack* first = nullptr ;
public:
    void Push(node *pos);
    node* Pop();
    void print();
    void clean();
    bool isEmpty();
};

#endif // STACK_H
