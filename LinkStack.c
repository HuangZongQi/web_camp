#include"D:/homework/QG/zhan/LinkStack/LinkStack.h"
#include<stdio.h>
#include<stdlib.h> 
#include<string.h>

//��ջ(���������)
Status initLStack(LinkStack *s)   //��ʼ��
{
	if(s == NULL)
	{
		printf("s����ռ�ʧ��\n");
		return ERROR;
	}
	else
	{
		s->top = (StackNode*)malloc(sizeof(StackNode));
		if(s->top == NULL)
		{
			printf("s->top����ռ�ʧ��\n");
			return ERROR;	
		}
		printf("1����ͷ�ڵ����ݳ�ʼ������������\n");
		int w = 0; 
		while(1 != w)
		{
			w = scanf("%d",&s->top->data);
			if(w == 0) printf("error,��������\n");
 			while(getchar()!='\n');
		}  
		s->top->next = NULL;
		s->count = 0;
	}
	return OK;
}
 
Status isEmptyLStack(LinkStack *s)  //�ж���ջ�Ƿ�Ϊ��
{
	if(s->top == NULL)
	return ERROR;
	else return OK;
}
Status getTopLStack(LinkStack *s,ElemType *e)  //�õ�ջ��Ԫ��
{
	if(s->top != NULL)
	return *e = s->top->data;
	else return ERROR;
}
Status clearLStack(LinkStack *s)   //���ջ
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
Status destroyLStack(LinkStack *s)   //����ջ
{
	if(s->top == NULL)
	return OK;
	else
	{
		StackNode *temp = (StackNode*)malloc(sizeof(StackNode));
		if(temp == NULL)
		{
			printf("����ʧ��\n");
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
Status LStackLength(LinkStack *s,int *length)    //���ջ����
{
	LinkStack *temp = (LinkStack*)malloc(sizeof(LinkStack));
	*temp = *s;  //ע�� 
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
Status pushLStack(LinkStack *s,ElemType data)   //��ջ
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
Status popLStack(LinkStack *s,ElemType *data)   //��ջ
{
	if(s->top == NULL)
	{
		return ERROR;
	}
	else
	{
		StackNode *temp = (StackNode*)malloc(sizeof(StackNode));  //ע�� 
		if(temp == NULL)
		{
			printf("����ʧ��\n");
			return ERROR;	
		}
			temp = s->top;   //ע�� 
			s->top = s->top->next;
			*data = temp->data;
			free(temp); 
	}
	return OK;
}
