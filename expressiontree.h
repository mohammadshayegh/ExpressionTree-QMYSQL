#ifndef EXPRESSIONTREE_H
#define EXPRESSIONTREE_H
#include <math.h>
#include "node.h"
#include "charidentifier.h"
#include "traversal.h"
#include "stack.h"
#include <vector>

class expressionTree
{
private:
    node *root = nullptr ;
    char *text ;
    int depth = 0;
    unsigned int textSize;
    vector<int> pos;
    vector<char> charVal;
public:
    //constructors
    expressionTree(string text,char Xfix);

    //value of private values
    // -> set
    void setRoot(node *root){this->root = root;}
    void setText(char *text){this->text = text;}
    void setDepth(){this->depth = treeDepth(this->root);}
    void setTextSize(unsigned int size){this->textSize = size;}
    // -> get
    node *getRoot(){ return this->root ;}
    char *getText(){return this->text  ;}
    int  getDepth(){return this->depth ;}
    unsigned int  getTextSize(){return this->textSize;}
    vector<int> getPos(){return pos;}
    vector<char> getChar(){return charVal;}

    //positioning
    void nodeLocator(node *root, node *parent, int depth, int width, int height);//positioning nodes for drawing tree

    //tree Constructor
    node *postFix_to_tree(unsigned int &end);//postFix to tree
    node *infix_to_tree(char *text);//infix to tree - whith parantheses and whit no parantheses

    //integer value of expression tree
    float lastVal(node *root);

    //tree depth
    int treeDepth(node *root);

    char *stringToChar(string text);
};

#endif // EXPRESSIONTREE_H
