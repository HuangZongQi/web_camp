#include"D:/homework/QG/zhan/������/Stackhead.h"
#include<stdlib.h> 
#include<string.h>
#include<stdio.h>

int main()
{
	
	SqStack *s = (SqStack*)malloc(sizeof(SqStack));
	initStack(s); 
	CharSqStack *sym = (CharSqStack*)malloc(sizeof(CharSqStack));
	initCharStack(sym);
	double num1 = 0;
	double num2 = 0;
	double num = 0;
	int cn = 1;
	int i = 0;
	int j = -1;
	int flag = 0;
	int fflag = 0;
	char *str = (char*)malloc(sizeof(char)*100);
	char array[100] ={'?'};
	char c;
	printf("��������������\n");
	while((c = getchar()) != '\n') {
        str[i] = c;
        i ++;
        
    }
    str[i] = '\0';
    i = 0;
    while(1)
    {
    	while (str[i] >= '0' && str[i] <= '9')
    	array[++j] = str[i++] ;
    	if(str[i] != '\0') array[++j]= '#';
    	
    	if(str[i] == '\0')
    	{
    		CharElemType sum;
			CharElemType *chardata = &sum;
			popCharStack(sym,chardata);
			array[++j] = sum;
			printf("���sum = %c\n",sum);
			array[++j] = '?';
    		break;
		}
    if(!JudgeScan(str[i]))
		{
			printf("����\n");
			printf("����");
			exit(0);	
		}
		else
		{
			printf("����ȷ���ַ�\n");
			if(str[i] == '=' )
			{
				
				printf("����1\n");
				printf("����");
				exit(0);	
			}
			if(str[i] == '(')
				flag = 1;
			if(str[i] == ')' && flag == 0)
			{
				printf("%c",str[i]);
				printf("����2\n");
				printf("����");
				exit(0);	
			}
			if(str[i] == ')' && flag == 1)
			{
				flag = 0;
			}
			if(sym->top == -1)
			{
				pushCharStack(sym,str[i]);
				printf("�ɹ��ĵ�һ���ַ���ջ\n");
			}
			else
			{
				if(str[i] == ')')
				{
					printf("�����Ų���\n");
					CharElemType sum;
					CharElemType *chardata = &sum;
					popCharStack(sym,chardata);
					printf("sum = %c\n",sum);
					while(sum != '(')
					{
						array[++j] = sum;
						popCharStack(sym,&sum); 
						printf("��������sum = %c\n",sum); 
					}
				i++;
				}
				do
				{
					if(str[i] == '\0' )
					break;
					char y = Judgeprior(sym->elem[sym->top],str[i]);
					printf("y=%c\n",y);
					switch(y)
					{
					case '=':
							{
								printf("����");
								exit(0);
							}
					case '>':
							{
								pushCharStack(sym,str[i]);
								printf("����>��ջ�ɹ�"); 
								fflag = 1;
								break;
							}
					case '<':
							{
								CharElemType sum;
								CharElemType *chardata = &sum;
								popCharStack(sym,chardata);
								printf("���뵽<\n");
								array[++j] = sum;
								break;
							}
					}
					if(fflag)
					{
						fflag = 0;
						break;
					}
					if(sym->top == -1)
					{
						pushCharStack(sym,str[i]);
						printf("��һ���ַ���ջ������һ���ַ���ջ\n");
						break;
					}
				}while(sym->top != -1);
			} 
		}
		i++;
	} 
	while(sym->top != -1)
	{
		CharElemType sum;
		CharElemType *chardata = &sum;
		popCharStack(sym,chardata);
		array[j] = sum;
		j++;
	}
	array[j] = '?'; 
	j = 0;
	do
	{
		do
		{
			if(array[j] == '#')
			j++;
			if(array[j] < '0' ||array[j] > '9')
			break;
			while(array[j] >= '0' && array[j] <= '9')
			{
				num *= cn;
				num += array[j]-48;
				cn = 10;
				j++;
			}
			printf("num = %f\n",num);
			pushStack(s,num);
			num = 0;
			cn = 1;
			if(array[j] == '#')
			j++;
			if(array[j] == '#')
			j++;
			if(array[j] < '0' ||array[j] > '9')
			break;
		}while(1);
				popStack(s,&num2);
				popStack(s,&num1);
				double ret	= math(num1,num2,array[j]);
				printf("ret = %f,num1 = %f,num2 = %f,array[%d] = %c\n",ret,num1,num2,j,array[j]);
				pushStack(s,ret);
				int k = 0;  
				for(k = 0; k < 20;k++)
				 printf("%c ",array[k]);
				 printf("\n"); 
				if(array[j+1] == '?')
				break;
				j++;
	}while(1);
	ElemType *data = &num;
	popStack(s,data);
	printf("���ս����%f\n",num);  
	getchar();
		free(str);
}
