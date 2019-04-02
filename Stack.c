#include"D:/homework/QG/zhan/������/Stackhead.h"
#include<stdlib.h> 
#include<string.h>
#include<stdio.h>

//˳��ջ(���������)
Status initStack(SqStack *s)  //��ʼ��ջ
{
	if(s == NULL)
	return ERROR;
	s->top = -1;
	return OK;
} 

Status pushStack(SqStack *s,ElemType data)  //��ջ
{
	if(s->elem == NULL )  //ջ�� 
		return ERROR;
	else 
	{
		printf("��ջ���� :%f\n",data);
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

double math(double num1,double num2,char ch)
{
	double ret;
	switch(ch)
	{
		case '+': 
		{
			ret = num1 + num2;
			break;
		}
		
		case '-':
		{
			ret = num1 - num2;
			break;	
		} 
		
		case '*':
		{
			ret = num1 * num2;
			break;
		} 
		
		case '/': 
		{
			ret = num1 / num2;
			break; 
	    }
	}
	return ret;
} 

Status initCharStack(CharSqStack *sym)//��ʼ��ջ
{
	if(sym == NULL)
	return ERROR;
	sym->top = -1 ;
	return OK;
}

Status pushCharStack(CharSqStack *sym,CharElemType chardata)//��ջ
{
		sym->top++;
		sym->elem[sym->top] = chardata;
		printf("%c ��ջ\n",chardata);
		printf("sym->elem[%d] = %c",sym->top,sym->elem[sym->top]);
		return OK;
}
Status popCharStack(CharSqStack *sym,CharElemType *chardata)//��ջ
{
	if(sym == NULL || sym->top == -1)
		return ERROR;
	*chardata = sym->elem[sym->top];
	sym->top--;
	return OK;
}
Status JudgeScan(CharElemType chardata)//�ж�������ַ��Ƿ���ȷ 
{
	if(chardata == '+' || chardata == '-' || chardata == '*' || chardata == '/' || chardata == '(' || chardata == ')')
	return OK;
	else
	return ERROR;
}
char Judgeprior(CharElemType ch1,CharElemType ch2)//�ж�������ַ������ȼ� 
{
	char ch;
	switch(ch1)
	{
		case '-':
		case '+':
			{
				if(ch2 == '-' || ch2 == '+')
				ch = '<';
				else
				ch = '>';
				break;
			}
		case '*':
		case '/':
			{
				if(ch2 == '(')
				ch = '>';
				else
				ch = '<';
				break;
			}
		case '(':
			{
				if(ch2 == '(')
				ch = '=';
				else
				ch = '>';
				break;
			}
		case ')':
			{
				if(ch2 == ')')
				ch = '=';
				else
				ch = '<';
				break;
			}
	}
	printf("�Ƚ����ȼ�\n");
	printf("ch = %c,ch1 = %c,ch2 = %c\n",ch,ch1,ch2);
	return ch;
}

