#include"D:/homework/QG/zhan/LinkStack/LinkStack.h"
#include<stdio.h>
#include<stdlib.h> 
#include<string.h>

//链栈(基于链表的)
Status initLStack(LinkStack *s)   //初始化
{
	if(s == NULL)
	{
		printf("s分配空间失败\n");
		return ERROR;
	}
	else
	{
		s->top = (StackNode*)malloc(sizeof(StackNode));
		if(s->top == NULL)
		{
			printf("s->top分配空间失败\n");
			return ERROR;	
		}
		printf("1请问头节点数据初始化，输入数字\n");
		int w = 0; 
		while(1 != w)
		{
			w = scanf("%d",&s->top->data);
			if(w == 0) printf("error,重新输入\n");
 			while(getchar()!='\n');
		}  
		s->top->next = NULL;
		s->count = 0;
	}
	return OK;
}
 
Status isEmptyLStack(LinkStack *s)  //判断链栈是否为空
{
	if(s->top == NULL)
	return ERROR;
	else return OK;
}
Status getTopLStack(LinkStack *s,ElemType *e)  //得到栈顶元素
{
	if(s->top != NULL)
	return *e = s->top->data;
	else return ERROR;
}
Status clearLStack(LinkStack *s)   //清空栈
{
	if(s->top == NULL)
	{
		return OK;
	}
	else
	{
		while(s->top->next != NULL)
		{
			StackNode *temp = (StackNode*)malloc(sizeof(StackNode));
			temp = s->top;
			s->top = s->top->next;
			free(temp);
		}
	}
	return OK;
}
Status destroyLStack(LinkStack *s)   //销毁栈
{
	if(s->top == NULL)
	return OK;
	else
	{
		StackNode *temp = (StackNode*)malloc(sizeof(StackNode));
		if(temp == NULL)
		{
			printf("分配失败\n");
			return ERROR;	
		}
			temp = s->top;
			s->top = s->top->next;
			free(temp);
			if(s->top) 
			destroyLStack(s);
	}
	return OK;
}
Status LStackLength(LinkStack *s,int *length)    //检测栈长度
{
	LinkStack *temp = (LinkStack*)malloc(sizeof(LinkStack));
	*temp = *s;  //注意 
	if(temp->top == NULL)
	{
		*length = 0;
		return ERROR;
	}
	else
	{
		while(temp->top != NULL)
		{
			++*length;
			temp->top = temp->top->next;
		}
	}
	return OK;
}
Status pushLStack(LinkStack *s,ElemType data)   //入栈
{ 
	if(s->top == NULL)
	{
		return ERROR;
	}
	StackNode *temp = (LinkStackPtr)malloc(sizeof(StackNode));
	if(temp == NULL)
	{
		return ERROR;
	}
	else
	{
		temp->data = data;
		temp->next = s->top;
		s->top= temp;
		s->count++;
		return OK;	
	}
	
}
Status popLStack(LinkStack *s,ElemType *data)   //出栈
{
	if(s->top == NULL)
	{
		return ERROR;
	}
	else
	{
		StackNode *temp = (StackNode*)malloc(sizeof(StackNode));  //注意 
		if(temp == NULL)
		{
			printf("分配失败\n");
			return ERROR;	
		}
			temp = s->top;   //注意 
			s->top = s->top->next;
			*data = temp->data;
			free(temp); 
	}
	return OK;
}
