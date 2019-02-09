#include "traversal.h"

void traversal::inOrder(node *root)
{
    if(!root)
        return ;

    inOrder(root->left);
    ino.append(root->val);
    inOrder(root->right);
}
void traversal::postOrder(node *root)
{
    if(!root)
        return ;

    postOrder(root->left);
    postOrder(root->right);
    postO.append(root->val);
}
void traversal::preOrder(node *root)
{
    if(!root)
        return ;

    preO.append(root->val);
    preOrder(root->left);
    preOrder(root->right);
}
void traversal::treeToParanthesesInfix(node *root)
{
    if(!root)
        return ;

    if(charIdentifier::isOperator(root->val) || charIdentifier::isUnary(root->val))
        pInO.append('(');

    treeToParanthesesInfix(root->left);
    pInO.append(root->val);

    treeToParanthesesInfix(root->right);
    if(charIdentifier::isOperator(root->val) || charIdentifier::isUnary(root->val))
        pInO.append(')');

}

traversal::~traversal()
{
    ino.clear();
    preO.clear();
    postO.clear();
    pInO.clear();
}
