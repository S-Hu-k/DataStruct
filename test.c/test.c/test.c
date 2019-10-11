#include<stdio.h>
int count_one_bits(unsigned int n)
{
	int count = 0;
	while (n)
	{
		if (n % 2 == 1)
		{
			count++;
		}
		n /= 2;
	}
	return count;
}

int main()
{

		int num = 25;
		int ret = 0;
		ret = count_one_bits(num);
		printf("ret=%d", ret);
		system("pause");
		return 0;

	}




