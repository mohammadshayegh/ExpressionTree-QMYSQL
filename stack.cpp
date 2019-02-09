#include "stack.h"


void Stack::Push( node *pos)
{
    stack *newStack = new stack ;
    newStack->next = this->first ;
    newStack->pos = pos ;
    this->first = newStack ;
}


node *Stack::Pop() // deleteing data from stack
{
    if(first)
    {
        stack *next = first->next ;
        node *Node = first->pos ;
        delete first ;
        first = next ;
        return Node ;
    }
    return nullptr ;
}


void Stack::print() // print all members of stack
{
    stack* first = this->first;
    while(first)
    {
        cout<<first->pos->val<<endl;
        first = first->next ;
    }
}

void Stack::clean() // delete all of stack and nodes
{
    stack* first = this->first ;
    while(first)
    {
        stack* next = first->next;
        if(first->pos)
            delete first->pos;
        delete first ;
        first = next ;
    }
    this->first = nullptr;
}

bool Stack::isEmpty()
{
    if(!first)
        return 1;
    return 0;
}
