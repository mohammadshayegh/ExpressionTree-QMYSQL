#include "node.h"

Node::Node(int val , node *left , node *right)
{
    allocateNode(val ,left ,right) ;
}
node *Node::allocateNode(int val , node *left , node *right)
{
    node* Node = new node ;
    Node->left = left ;
    Node->right = right ;
    Node->val = val ;
    return Node ;
}
char Node::freeNode(node* first)
{
    if(first)
    {
        char c =  first->val;
        delete first ;
        return c;
    }

    return 0 ;
}
