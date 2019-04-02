#include<stdio.h>
#include"D:/homework/QG/zhan/SqStack/SqStack.h"
#include<stdlib.h> 
#include<string.h>


void menu();

int main()
{
	menu();
	int flag = 0; //允许创建节点后，输入其他数字也成功 
	int fflag = 0;  //控制菜单退出 
	int t = 0; //避免它创多个节点 
	int num = 0; //给地址给e 
	ElemType *e = &num;
	int length = 0;
	SqStack *s = NULL;
	s = (SqStack*)malloc(sizeof(SqStack));
	while(1)
	{
		int x,y;  //x是输入菜单选项，y是接受返回值 
		printf("请输入你要开始的菜单选项\n");
		int w = 0;  //w是接受输入返回值 
		while(1 != w)
		{
			 w = scanf("%d",&x);
			if(w ==0 )printf("error,重新输入\n");
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
			printf("数组已创建，不用再次创建,你可以选5销毁后再重创栈\n");
			break; 
		}
		printf("输入你要创的数组大小sizes:\n");
		int w = 0;  //w是接受输入返回值 
		int sizes ;
		while(1 != w)
		{
			w = scanf("%d",&sizes);
			if(w == 0) printf("error,重新输入\n");
 			while(getchar()!='\n');
		} 
		y = initStack(s,sizes);
		if(y){ 
			printf("成功创建\n");
			t = 2;
		}
		else
			printf("创建失败\n");
		break;
	}
	
	case 2:
	{
		y = isEmptyStack(s);
		if(y)
		{
			printf("它不是空栈\n");
		}
		else
		{
			printf("它是空栈,可能是你之前清空过，快选7为它输入新的数据\n");	
		}
		break;
	}
	
	case 3:
	{
		y = getTopStack(s,e);
		if(y)
		{
			printf("成功获得栈顶元素：%d\n",*e);
		}
		else
		{
			printf("获得栈顶元素失败，可能栈被销毁了,也可能是你刚创的，还没有入栈，请选1重创栈或选7入栈\n");
			t = 1; 
		}
		break;
	}
	
	case 4:
	{
		y = clearStack(s);
		if(y)
		{
			printf("清除栈元素成功\n");	
		}
		else
		{
			printf("清除栈元素失败，可能栈被销毁了，也可能是你刚创的，还没有入栈，请选1重创栈或选7入栈\n");
			t = 1;
		} 
		break;
	}
	
	case 5:
	{
		y = destroyStack(s);
		if(y)
		{
			printf("销毁栈成功\n");
			t = 1;
		}
		else
		{
			printf("销毁栈失败，可能栈被销毁了，请选1重创栈\n");
		}
		break;
	}
	
	case 6:
	{
		y = stackLength(s,length);
		if(y)
		{
			printf("栈的长度为:%d\n",length);
			length = 0;
		}
		else
		{
			printf("数组不存在，可能栈被销毁了，也可能是你刚创的，还没有入栈，请选1重创栈或选7入栈\n");
			t = 1;
		}
		break;
	}
	
	case 7:
	{
		ElemType data;
		printf("请输入的你要入栈的元素\n");
		int w = 0;  //w是接受输入返回值 
		while(1 != w)
		{
			w = scanf("%d",&data);
			if(w == 0)printf("error,重新输入\n");
 			while(getchar()!='\n');
		} 
		y = pushStack(s,data);
		if(y)
		{
			printf("入栈成功，入栈的元素为:%d\n",data);
		}
		else
		{
			if(s->top == s->size - 1) 
			printf("栈满了,你可以重建栈，先销毁，再创建\n");
			else
			{
			printf("入栈失败，可能栈被销毁了，请选1重创栈\n");
			t = 1;
		    }
		} 
		break;
	}
	
	case 8:
	{
		int d = 0;//给地址data 
		ElemType *data = &d;
		y =  popStack(s,data);
		if(y)
		{
			printf("出栈成功，出栈的元素为:%d\n",*data);
		}
		else
		{
			printf("出栈失败,可能栈被销毁了，可能是栈的元素出栈完了，也可能是你刚创的，还没有入栈，请选1重创栈或选7入栈\n");
			t = 1;
		}
		break;
	}
	
	case 9:
	{
		printf("菜单为:\n");
		menu();
		break;	
	}
	
	case 10:
	{
		printf("退出菜单\n");
		fflag = 1;
		break;
	}
	
	case 11:
	{
		system("cls");
		menu();
		break;
	} 
	
	default:
	{
		printf("输入的菜单不在范围内\n");
		break;	
	}	
	}
    }
	else
    {
    	printf("数组还没有创建，请先选菜单那1来创建\n");
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
	printf("************************************计科3黄宗琪********************************************\n");
	printf("***************************************栈**************************************************\n");
	printf("                                   1.初始化栈                                              \n");
	printf("                                   2.判断栈的是否为空                                      \n");
	printf("                                   3.得到栈顶元素                                          \n");
	printf("                                   4.清空栈                                                \n");
	printf("                                   5.销毁栈                                                \n");
	printf("                                   6.检测栈长度                                            \n");
	printf("                                   7.入栈                                                  \n");
	printf("                                   8.出栈                                                  \n");
	printf("                                   9.菜单                                                  \n");
	printf("                                   10.退出                                                 \n");
	printf("                                   11.清屏                                                 \n");	
	printf("*******************************************************************************************\n");
	printf("*******************************************************************************************\n\n");
	}
