#ifndef CHARIDENTIFIER_H
#define CHARIDENTIFIER_H


class charIdentifier
{
public:
    //characters checker
    static bool isOperator(char symbol);    //checking oparators
    static bool isOperand(char symbol);     //checking operands
    static bool isUnary(char symbol);       //checking unary minus
    static bool isParantheses(char symbol); //checking parantheses
    static bool priority(char op1,char op2);//for pushing datas in stack (priority checker)
    static bool isNum(char symbol);

};

#endif // CHARIDENTIFIER_H
