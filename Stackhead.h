#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED



typedef enum Status
{ 
    ERROR = 0,OK = 1
}Status;

//������ 
typedef double ElemType;

typedef struct SqStack{
       ElemType	elem[20];
       int top;      //����ջ��ָ��
}SqStack;

Status initStack(SqStack *s);//��ʼ��ջ
Status pushStack(SqStack *s,ElemType data);//��ջ
Status popStack(SqStack *s,ElemType *data);//��ջ
double math(double num1,double num2,char ch); //�������� 

//������ 
typedef char CharElemType;

typedef struct SqCharStack{
       CharElemType	elem[20];
       int top;      //����ջ��ָ��
}CharSqStack;

Status initCharStack(CharSqStack *sym);//��ʼ��ջ
Status pushCharStack(CharSqStack *sym,CharElemType data);//��ջ
Status popCharStack(CharSqStack *sym,CharElemType *data);//��ջ
Status JudgeScan(CharElemType chardata);//�ж�������ַ��Ƿ���ȷ 
char Judgeprior(CharElemType ch1,CharElemType ch2);//�ж�������ַ������ȼ� 

#endif 


