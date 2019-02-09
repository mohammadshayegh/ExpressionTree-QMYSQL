#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <string.h>

using namespace std;

struct node{
    char val;
    node *left;
    node *right;
    int width;
    int height;
};

class Node
{
public:
    Node(int val , node *left , node *right);
    static node *allocateNode(int val , node *left , node *right);
    static char freeNode(node* first);
};

#endif // NODE_H
