#ifndef TRAVERSAL_H
#define TRAVERSAL_H
#include <iostream>
#include <QString>
#include "expressiontree.h"

using namespace std;


class traversal
{
private:
    node *root = nullptr;
    QString ino,preO,postO,pInO;

public:
    QString getIno(){return ino;}
    QString getPreO(){return preO;}
    QString getPostO(){return postO;}
    QString getPInO(){return pInO;}

    void inOrder(node *root);     //inOrder Traversal
    void preOrder(node *root);    //preOrder Traversal
    void postOrder(node *root);   //postOrder Traversal
    void treeToParanthesesInfix(node *root); //inOrder traversal with complete-parantheses

    ~traversal();
};

#endif // TRAVERSAL_H
