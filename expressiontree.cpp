#include "expressiontree.h"

expressionTree::expressionTree(string text, char Xfix)
{
    this->text = stringToChar(text);
    this->textSize = text.size()-1;

    if(Xfix=='p')
    {
        unsigned int end = this->textSize;
        this->root = postFix_to_tree(end);
    }
    else if(Xfix == 'i')
    {
        this->root = infix_to_tree(this->text);
    }
}

void expressionTree::nodeLocator(node *root,node *parent, int depth ,int width ,int height)
{
    if(!root)
        return ;

    if(parent)
    {
        pos.push_back(parent->width);
        pos.push_back(parent->height);
    }
    else
    {
        pos.push_back(width);
        pos.push_back(height);
    }


    root->width = width;
    root->height = height ;

    pos.push_back(width);pos.push_back(height);
    charVal.push_back(root->val);

    nodeLocator(root->left,root,depth-1,root->width-10*depth,root->height+20);
    nodeLocator(root->right,root,depth-1 ,root->width+10*depth ,root->height+20);
}

node *expressionTree::postFix_to_tree(unsigned int &end)
{
    node *root = Node::allocateNode(this->text[end],NULL,NULL);

    if(charIdentifier::isOperator(this->text[end]))
    {
        end--;
        root->right = postFix_to_tree(end);
        end = end-1;
        root->left = postFix_to_tree(end);
    }
    if(charIdentifier::isUnary(this->text[end]))
    {
        end--;
        root->right = postFix_to_tree(end);
    }
    this->root = root;
    return root;
}

node *expressionTree::infix_to_tree(char *text)
{
    Stack operand,operators;
    char val='\0';

    for(int i=0 ;text[i]!='\0';i++)
    {
        if(charIdentifier::isOperator(text[i]) || charIdentifier::isUnary(text[i]) || charIdentifier::isParantheses(text[i]))
        {
            if(operators.first)
                val = operators.first->pos->val;

            if(text[i]==')')
            {
                while(!operators.isEmpty() && operators.first->pos->val !='(')
                {
                    node *op = operators.Pop();
                    op->right= operand.Pop();
                    if(!charIdentifier::isUnary(op->val))
                        op->left = operand.Pop();
                    operand.Push(op);
                }
                operators.Pop();
            }
            else if( !charIdentifier::priority( text[i],val ) )
                operators.Push(Node::allocateNode(text[i],nullptr,nullptr));
            else
            {
                node *op = operators.Pop();
                op->right= operand.Pop();
                op->left = operand.Pop();
                operand.Push(op);
                operators.Push(Node::allocateNode(text[i],nullptr,nullptr));
            }
        }
        else if(charIdentifier::isOperand(text[i]))
            operand.Push(Node::allocateNode(text[i],nullptr,nullptr));
    }

    while( !operators.isEmpty())
    {
        node *op  = operators.Pop();
        op->right = operand.Pop();
        op->left  = operand.Pop();
        operand.Push(op);
    }

    node *root = operand.Pop();
    this->root = root;
    return root;

}

float expressionTree::lastVal(node *root)
{
    if(root && (!root->left && !root->right))
    {
        if(charIdentifier::isNum(root->val))
            return root->val-'0';
        else
            return 0;
    }

    if(root)
        switch (root->val)
        {
            case '+' : return lastVal(root->left)+lastVal(root->right);
            case '-' : return lastVal(root->left)-lastVal(root->right);
            case '*' : return lastVal(root->left)*lastVal(root->right);
            case '/' : return lastVal(root->left)/lastVal(root->right);
            case '^' : return pow(lastVal(root->left),lastVal(root->right));
            case '~' : return -1*lastVal(root->right);
            default  : return 0;
        }
    else
        return 0;
}

int expressionTree::treeDepth(node *root)
{
    int l,r;
    if(root)
    {
        l = treeDepth(root->left);
        r = treeDepth(root->right);
        if(l>r)
        {
            this->depth = l+1;
            return l+1;
        }
        else
        {
            this->depth = r+1;
            return r+1;
        }
    }
    return 0;
}

char *expressionTree::stringToChar(string text)
{
    char *CharedStr = new char[ text.length() + 1 ] ;
    strcpy(CharedStr , text.c_str()) ;
    return CharedStr ;
}

