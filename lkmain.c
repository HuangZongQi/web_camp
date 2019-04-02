#include<stdio.h>
#include"D:/homework/QG/zhan/LinkStack/LinkStack.h"
#include<stdlib.h> 
#include<string.h>


void menu();

int main()
{
	menu();
	int flag = 0;    //�ڴ��ýڵ�ã����������������� 
	int fflag = 0; //�˳��˵��ÿ��� 
	int t = 0; //������������ڵ� 
	int num = 0; //����ַ��e 
	int len = 0; //����ַ��lenght �����÷���ռ䣬��ΪҪ�Լ����� 
	LinkStack *s ;
	s = (LinkStack*)malloc(sizeof(LinkStack));
	ElemType *e = &num;
	int *length = &len;
	while(1)
	{
		int x,y;//y�������շ���ֵ��x�ǲ˵�ѡ�� 
		printf("��������Ҫ��ʼ�Ĳ˵�ѡ��\n");
		int w = 0; 
		while(1 != w)
		{
			w = scanf("%d",&x);
			if(w == 0) printf("error,��������\n");
 			while(getchar()!='\n');
		}  
		if(x == 1 || flag == 1)
	{
		flag = 1;
		switch(x)
	{
	case 1:
	{
		if(t == 2)
		{
			printf("�ڵ��Ѵ����������ٴδ���,�����ѡ5���ٺ����ش�ջ\n");
			break; 
		}
		y = initLStack(s);
		if(y)
		{
			printf("�����ɹ�\n");	
			t = 2;
		}
		else
			printf("����ʧ��\n"); 
		break;
	}
	
	case 2:
	{
		y = isEmptyLStack(s);
		if(y)
		{
			printf("�����ǿ�ջ\n");
		}
		else
		{
			printf("���ǿ�ջ,��������֮ǰ��չ�����ѡ7Ϊ�������µ�����\n");	
		}
		break;
	}
	
	case 3:
	{
		y = getTopLStack(s,e);
		if(y)
		{
			printf("�ɹ����ջ��Ԫ�أ�%d\n",*e);
		}
		else
		{
			printf("���ջ��Ԫ��ʧ�ܣ�����ջ�������ˣ���ѡ1�ش�ջ\n");
			t = 1; 
		}
		break;
	}
	
	case 4:
	{
		y = clearLStack(s);
		if(y)
		{
			printf("���ջԪ�سɹ�\n");	
		}
		else
		{
			printf("���ջԪ��ʧ�ܣ�����ջ�������ˣ���ѡ1�ش�ջ\n");
			t = 1;
		} 
		break;
	}
	
	case 5:
	{
		y = destroyLStack(s);
		if(y)
		{
			printf("����ջ�ɹ�\n");
			t = 1;
		}
		else
		{
			printf("����ջʧ�ܣ�����ջ�������ˣ���ѡ1�ش�ջ\n");
		}
		break;
	}
	
	case 6:
	{
		y = LStackLength(s,length);
		if(y)
		{
			printf("ջ�ĳ���Ϊ:%d\n",*length);
			*length = 0;
		}
		else
		{
			printf("�ڵ㲻���ڣ�����ջ�������ˣ���ѡ1�ش�ջ\n");
			t = 1;
		}
		break;
	}
	
	case 7:
	{
		ElemType data;
		printf("���������Ҫ��ջ��Ԫ��\n");
		int w = 0; 
		while(1!=w)
		{
			w = scanf("%d",&data);
			if(w == 0) printf("error,��������\n");
 			while(getchar()!='\n');
		} 
		y = pushLStack(s,data);
		if(y)
		{
			printf("��ջ�ɹ�����ջ��Ԫ��Ϊ:%d\n",data);
		}
		else
		{
			printf("��ջʧ�ܣ�����ջ�������ˣ���ѡ1�ش�ջ\n");
			t = 1;
		} 
		break;
	}
	
	case 8:
	{
		int d = 0;//����ַdata 
		ElemType *data = &d;
		y = popLStack(s,data);
		if(y)
		{
			printf("��ջ�ɹ�����ջ��Ԫ��Ϊ:%d\n",*data);
		}
		else
		{
			printf("��ջʧ��,����ջ�������ˣ���ѡ1�ش�ջ\n");
			t = 1;
		}
		break;
	}
	
	case 9:
	{
		printf("�˵�Ϊ:\n");
		menu();
		break;	
	}
	
	case 10:
	{
		printf("�˳��˵�\n");
		fflag = 1;
		break;
	}
	
	case 11:
	{
		system("cls");
		menu();	
	}
	default:
	{
		printf("����Ĳ˵����ڷ�Χ��\n");
		break;	
	}	
	}
    }
	else
    {
    	printf("�ڵ㻹û�д���������ѡ�˵���1������\n");
	}
		if(fflag)
		break;
	}
	return 0;
}
 
	void menu()
	{
	printf("*******************************************************************************************\n");
	printf("*******************************************************************************************\n\n");
	printf("************************************�ƿ�3������********************************************\n");
	printf("***************************************ջ**************************************************\n");
	printf("                                   1.��ʼ��ջ                                              \n");
	printf("                                   2.�ж�ջ���Ƿ�Ϊ��                                      \n");
	printf("                                   3.�õ�ջ��Ԫ��                                          \n");
	printf("                                   4.���ջ                                                \n");
	printf("                                   5.����ջ                                                \n");
	printf("                                   6.���ջ����                                            \n");
	printf("                                   7.��ջ                                                  \n");
	printf("                                   8.��ջ                                                  \n");
	printf("                                   9.�˵�                                                  \n");
	printf("                                   10.�˳�                                                 \n");
	printf("                                   11.����                                                 \n");	
	printf("*******************************************************************************************\n");
	printf("*******************************************************************************************\n\n");
	}
