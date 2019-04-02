#include"D:/homework/QG/zhan/计算器/Stackhead.h"
#include<stdlib.h> 
#include<string.h>
#include<stdio.h>

//顺序栈(基于数组的)
Status initStack(SqStack *s)  //初始化栈
{
	if(s == NULL)
	return ERROR;
	s->top = -1;
	return OK;
} 

Status pushStack(SqStack *s,ElemType data)  //入栈
{
	if(s->elem == NULL )  //栈满 
		return ERROR;
	else 
	{
		printf("入栈数据 :%f\n",data);
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
			if(num2 == 0)
			{
				printf("分母不为零\n");
				exit(0);
			}
			ret = num1 / num2;
			break; 
	    }
	}
	return ret;
} 

Status initCharStack(CharSqStack *sym)//初始化栈
{
	if(sym == NULL)
	return ERROR;
	sym->top = -1 ;
	return OK;
}

Status pushCharStack(CharSqStack *sym,CharElemType chardata)//入栈
{
		sym->top++;
		sym->elem[sym->top] = chardata;
		printf("%c 入栈\n",chardata);
		printf("sym->elem[%d] = %c",sym->top,sym->elem[sym->top]);
		return OK;
}
Status popCharStack(CharSqStack *sym,CharElemType *chardata)//出栈
{
	if(sym == NULL || sym->top == -1)
		return ERROR;
	*chardata = sym->elem[sym->top];
	sym->top--;
	return OK;
}
Status JudgeScan(CharElemType chardata)//判断输入的字符是否正确 
{
	if(chardata == '+' || chardata == '-' || chardata == '*' || chardata == '/' || chardata == '(' || chardata == ')')
	return OK;
	else
	return ERROR;
}
char Judgeprior(CharElemType ch1,CharElemType ch2)//判断输入的字符的优先级 
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
	printf("比较优先级\n");
	printf("ch = %c,ch1 = %c,ch2 = %c\n",ch,ch1,ch2);
	return ch;
}

