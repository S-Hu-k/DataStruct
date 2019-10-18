//#include<stdio.h>
//int count_one_bits(unsigned int n)
//{
//	int count = 0;
//	while (n)
//	{
//		if (n % 2 == 1)
//		{
//			count++;
//		}
//		n /= 2;
//	}
//	return count;
//}
//
//int main()
//{
//
//		int num = 25;
//		int ret = 0;
//		ret = count_one_bits(num);
//		printf("ret=%d", ret);
//		system("pause");
//		return 0;
//
//	}


//#include <iostream>
//using namespace  std;/*请实现一个函数，将一个字符串中的空格替换成“ % 20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are % 20Happy*/ 
//void replaceSpace(char *str, int length) 
//{	
//	char *dest = str;	
//	int n = 0;	
//	for (int i = 0; i < length; i++)
//	{		
//		if (str[i] == ' ')	
//			n++;	
//	}
//	int j = length+n*2-1;
//	for (int i = length-1; i >=0; i--)
//	{		
//		if (dest[i] == ' ')		
//		{		
//			str[j--] = '0';		
//			str[j--] = '2';		
//			str[j--] = '%';		
//		}	
//		else	
//		{		
//			str[j--] = dest[i];	
//		}
//	}
//}
//int main()
//{
//	char str[100] = " hello world ";
//	replaceSpace(str, strlen(str));
//	cout << str;
//}
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<math.h>
//int my_change(char *arr1,char *arr2)
//{	
//	while (*arr1)	
//	{		
//		if (*arr1 != ' ')
//
//		{		
//			*arr2 = *arr1;		
//			arr2++;	
//		}		
//		else		
//		{		
//			strcpy(arr2, "%20");	
//			arr2 = arr2 + 3;		
//		}		
//		arr1++;	
//	}	
//	*arr2 = '\0';	
//	return 0;
//}
//int main()
//{	
//	char arr1[] = "we are happy.";
//	char arr2[40];	
//	my_change(arr1,arr2);
//	printf("%s", arr2);
//	return 0;
//}
//int main()
//{
//	int input = 0;
//	int sum = 0;
//	printf("请输入要操作的数:>");
//	scanf("%d", &input);
//	while (input % 10)
//	{
//		sum += input % 10;
//		input /= 10;
//	}
//	printf("sum = %d\n", sum);
//	return 0;
//}
//int main()
//{
//	char i = 0;
//	double a, b, c;
//	scanf("%1f%1f%1f", &a, &b, &c);
//	double d, de1, ans1, ans2;
//	d = b*b - 4.0*a*c;
//	if (a == b&&a == 0 && c != 0)
//		printf("not an equation\n");
//	else if (d == 0)
//	{
//		ans1 = (-b) / (2.0*a);
//		printf("&.2f\n", ans1);
//	}
//	else if (a==0)
//		printf("&.2f\n", (-c) / b);
//	else if (d > 0)
//	{
//		de1 = sqrt(d);
//		ans1 = (-b + de1) / (2.0*a);
//	}
//	else if (a == 0)
//		printf("&.2f\n", (-c) / b);
//	else if (d > 0)
//	{
//		de1 = sqrt(d);
//		ans1 = (-b + de1) / (2.0*a);
//		ans2 = (-b + de1) / (2.0*a);
//		printf("%.2f\n%.2f\n", ans1, ans2);
//	}
//	else if (d < 0)
//	{
//		de1 = sqrt(-d);
//		if (b != 0)
//			ans1 = (-b + de1) / (2.0*a);
//		else
//			ans1 = 0;
//		ans2 = de1 / (2.0*a);
//		printf("%.2f+%.2fi\n,%.2f-%.2fi\n", (ans1 + ans2(i)) ,(ans1 - ans2 i));
//	}
//	return 0;
//}
///////////////////////////////////////////////
//int main()
//{
//
//double a, b, c, x1, x2, d1, y1, y2, e, f, z;
//scanf("%lf%lf%lf", &a, &b, &c);
//if (b*b>4 * a*c&&a != 0 && b != 0 && c != 0)
//{
//	x1 = (-b + sqrt(b*b - 4 * a*c)) / (2 * a);
//	x2 = (-b - sqrt(b*b - 4 * a*c)) / (2 * a);
//	printf("%.2lf\n%.2lf\n", x1, x2);
//}
//else if (b*b == 4 * a*c&&a != 0)
//{
//
//	printf("%.2lf", -b / (2 * a));
//}
//else if (a == 0 && b != 0)
//{
//	d1 = -c / b;
//	printf("%.2lf", d1);
//}
//else if (b*b<4 * a*c&&b != 0)
//{
//	e = -b / (2 * a);
//	f = sqrt(4 * a*c - b*b) / (2 * a);
//	printf("%.2lf+%.2lfi\n%.2lf-%.2lfi\n", e, f, e, f);
//}
//else if (b*b<4 * a*c&&b == 0)
//{
//	e = 0.00;
//	f = sqrt(4 * a*c - b*b) / (2 * a);
//	printf("%.2lf+%.2lfi\n%.2lf-%.2lfi\n", e, f, e, f);
//}
//else if (a == 0 && b == 0 && c == 0)
//{
//	printf("Zero Equation");
//}
//else if (a == 0 && b == 0 && c != 0)
//{
//	printf("Not An Equation");
//}
//return 0;
//}

////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
typedef int ElemType;
typedef struct Node 
{   
	ElemType data;   
	struct Node *next;
} Node, *LinkStack; //初始化栈
LinkStack initStack(LinkStack s); 
//入栈
bool pushStack(LinkStack s, ElemType e);//出栈
Node* popStack(LinkStack s); //打印栈
void printStack(LinkStack s); //判空
bool isEmptyStack(LinkStack s); //获取栈元素个数
int getLength(LinkStack s); //初始化栈
LinkStack initStack(LinkStack s) 
{   
	s = (LinkStack) malloc(sizeof(Node)); 
	s->next = NULL;    return s;
} //入栈
bool pushStack(LinkStack s, ElemType e)
{    
	Node *p = (LinkStack) malloc(sizeof(Node));  
	if(!p) return false;   
	p->data = e;  
	p->next = s->next;  
	s->next = p;   
	return true;
} //出栈
Node* popStack(LinkStack s) 
{    
	Node *p = s->next;  
	if(p!=NULL) 
	{      
		s->next = p->next;   
	}    
	return p;
} //打印栈
void printStack(LinkStack s)
{  
	Node *p = s->next;
	while(p!=NULL) 
	{       
		printf("stack elem: %d\n",p->data); 
		p = p->next;  
	}
} //判空
bool isEmptyStack(LinkStack s)
{    
	if( !s || s->next == NULL) 
		return true;    
	return false;
} //获取栈元素个数
int getLength(LinkStack s)
{    
	Node *p = s->next;  
int i= 0;    while(p!=NULL)
{    

	i++;    
	p=p->next;   
}   
return i;
} 
int main()
{
	LinkStack S=0;
	 S = initStack(S); 
	pushStack(S,1);   
	pushStack(S,2);   
	pushStack(S,3);   
	pushStack(S,4);  
	printStack(S);  
	printf("pop elem is %d\n",popStack(S)->data);  
	printf("pop elem is %d\n",popStack(S)->data);  
	printf("pop elem is %d\n",popStack(S)->data);  
	printf("pop elem is %d\n",popStack(S)->data);   
	printf("stack length %d\n",getLength(S));
	return 0;
}
