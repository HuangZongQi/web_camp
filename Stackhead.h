#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED



typedef enum Status
{ 
    ERROR = 0,OK = 1
}Status;

//操作数 
typedef double ElemType;

typedef struct SqStack{
       ElemType	elem[20];
       int top;      //用于栈顶指针
}SqStack;

Status initStack(SqStack *s);//初始化栈
Status pushStack(SqStack *s,ElemType data);//入栈
Status popStack(SqStack *s,ElemType *data);//出栈
double math(double num1,double num2,char ch); //进行算术 

//操作符 
typedef char CharElemType;

typedef struct SqCharStack{
       CharElemType	elem[20];
       int top;      //用于栈顶指针
}CharSqStack;

Status initCharStack(CharSqStack *sym);//初始化栈
Status pushCharStack(CharSqStack *sym,CharElemType data);//入栈
Status popCharStack(CharSqStack *sym,CharElemType *data);//出栈
Status JudgeScan(CharElemType chardata);//判断输入的字符是否正确 
char Judgeprior(CharElemType ch1,CharElemType ch2);//判断输入的字符的优先级 

#endif 


