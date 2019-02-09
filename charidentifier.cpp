#include "charIdentifier.h"

bool charIdentifier::isOperator(char symbol)
{
    if(symbol=='+' ||symbol=='-' ||symbol=='*' ||symbol=='/' ||symbol=='^')
        return 1 ;
    return 0 ;
}
bool charIdentifier::isOperand(char symbol)
{
    if( (symbol>='a' && symbol<='z') || (symbol>='A' && symbol<='Z' ) || (symbol>='0' && symbol<='9' ))
        return 1;

    return 0 ;
}
bool charIdentifier::isUnary(char symbol)
{
    if(symbol=='~')
        return 1;

    return 0;
}
bool charIdentifier::isParantheses(char symbol)
{
    if(symbol=='(' || symbol==')')
        return 1;
    return 0;
}
bool charIdentifier::priority(char op1,char op2)
{
    // priority of op1 is more than op2
    //pop : return 1
    //push : return 0

    if(op2 == '\0')
        return 0;

    if(op2=='(')
        return 0;
    if(op1==')')
        return 1;

    if( op1=='+' || op1=='-' )
        return 1;

    if( (op1=='*' || op1=='/') )
    {
        if(op2=='+' || op2=='-')
            return 0;
        else
            return 1;
    }

    if( op1=='^' )
    {
        if( isUnary(op2))
            return 1;
        else
            return 0;
    }

    if(isUnary(op1))
    {
        if( isUnary(op2) )
            return 1;
        else
            return 0;
    }

    return 0;
}

bool charIdentifier::isNum(char symbol)
{
    if( (symbol>='0' && symbol<='9' ) )
        return 1;

    return 0 ;
}
