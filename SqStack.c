#include"D:/homework/QG/zhan/SqStack/SqStack.h"
#include<stdlib.h> 
#include<string.h>
#include<stdio.h>

//顺序栈(基于数组的)
Status initStack(SqStack *s,int sizes)  //初始化栈
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
Status isEmptyStack(SqStack *s)   //判断栈是否为空
{
	if(s == NULL)
		return ERROR;
	else
		return OK;
}
Status getTopStack(SqStack *s,ElemType *e)   //得到栈顶元素
{
	if(s->top >= 0)
		return *e = s->elem[s->top];
	else return ERROR;
}
Status clearStack(SqStack *s)   //清空栈
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
Status destroyStack(SqStack *s)  //销毁栈
{
	if(s->elem == NULL)
	return ERROR;
	free(s->elem); 
	s->elem = NULL;
	return OK;
}
Status stackLength(SqStack *s,int length)   //检测栈长度 
{
	if(s == NULL || s->top == -1)
		return 	ERROR;
	else 
		return length = s->top+1;
}
Status pushStack(SqStack *s,ElemType data)  //入栈
{
	if(s->elem == NULL || s->top == s->size - 1)  //栈满 
	return ERROR;
	else 
	{
		s->top++;
		s->elem[s->top] = data;
		return OK;
	}
}
Status popStack(SqStack *s,ElemType *data)   //出栈
{
	if(s == NULL || s->top == -1)
		return ERROR;
	*data = s->elem[s->top];
	s->top--;
	return OK;
}

