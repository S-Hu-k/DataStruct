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
int my_change(char *arr1,char *arr2)
{	
	while (*arr1)	
	{		
		if (*arr1 != ' ')

		{		
			*arr2 = *arr1;		
			arr2++;	
		}		
		else		
		{		
			strcpy(arr2, "%20");	
			arr2 = arr2 + 3;		
		}		
		arr1++;	
	}	
	*arr2 = '\0';	
	return 0;
}
int main()
{	
	char arr1[] = "we are happy.";
	char arr2[40];	
	my_change(arr1,arr2);
	printf("%s", arr2);
	return 0;
}
