#include"D:/homework/QG/zhan/SqStack/SqStack.h"
#include<stdlib.h> 
#include<string.h>
#include<stdio.h>

//˳��ջ(���������)
Status initStack(SqStack *s,int sizes)  //��ʼ��ջ
{
	if(s == NULL)
		return ERROR;
	s->elem = (ElemType	*)malloc(sizes * sizeof(ElemType));
	if(s->elem == NULL)
		return ERROR;
	s->top = -1 ;
	s->size = sizes;
	return OK;
} 
Status isEmptyStack(SqStack *s)   //�ж�ջ�Ƿ�Ϊ��
{
	if(s == NULL)
		return ERROR;
	else
		return OK;
}
Status getTopStack(SqStack *s,ElemType *e)   //�õ�ջ��Ԫ��
{
	if(s->top >= 0)
		return *e = s->elem[s->top];
	else return ERROR;
}
Status clearStack(SqStack *s)   //���ջ
{
	if(s == NULL || s->top == -1)
		return 	ERROR;
		int sizes = s->size;
		free(s->elem);
		s->elem = (ElemType	*)malloc(sizes*sizeof(ElemType));
		s->top = -1 ;
	    s->size = sizes;
	    return OK;
}
Status destroyStack(SqStack *s)  //����ջ
{
	if(s->elem == NULL)
	return ERROR;
	free(s->elem); 
	s->elem = NULL;
	return OK;
}
Status stackLength(SqStack *s,int length)   //���ջ���� 
{
	if(s == NULL || s->top == -1)
		return 	ERROR;
	else 
		return length = s->top+1;
}
Status pushStack(SqStack *s,ElemType data)  //��ջ
{
	if(s->elem == NULL || s->top == s->size - 1)  //ջ�� 
	return ERROR;
	else 
	{
		s->top++;
		s->elem[s->top] = data;
		return OK;
	}
}
Status popStack(SqStack *s,ElemType *data)   //��ջ
{
	if(s == NULL || s->top == -1)
		return ERROR;
	*data = s->elem[s->top];
	s->top--;
	return OK;
}

