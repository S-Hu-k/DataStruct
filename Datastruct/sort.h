#ifndef _SORT_H_
#define _SORT_H_
#include"common.h"
void PrintArray(int *ar, int left, int right)
{
	for (int i = left; i <= right; ++i)
	{
		printf("%d ", ar[i]);
	}
	printf("\n");
}
//void TestSort(int *ar, int left, int right)
//{
	//PrintArray(ar, left, right);
	//InsertSort(ar, left, right);
	
//	PrintArray(ar, left, right);
   // InsertSort_2(ar, left, right); 
	//BinInsertSort(ar, left, right);


//	PrintArray(ar, left, right);
//}


//插入排序
void InsertSort(int *ar, int left, int right)
{
	for (int i = left + 1; i <= right; ++i)
	{
		int j = i;
		while (j>left && ar[j]<ar[j - 1])
		{
			Swap(&ar[j], &ar[j - 1]);
			j--;
		}
	}
}
void InsertSort_1(int *ar, int left, int right)
{
	for (int i = left + 1; i <= right; ++i)
	{
		int tmp = ar[i];
		int j = i;
		while (j>left && tmp<ar[j - 1])
		{
			ar[j] = ar[j - 1];
			j--;
		}
		ar[j] = tmp;
	}
}
void TestSortEfficiency()
{
	int n = 10000;
	int *a = (int*)malloc(sizeof(int)*n);

	srand(time(0));
	for (int i = 0; i < n; ++i)
	{
		a[i] = rand();
		
	}

	time_t start = clock();
	InsertSort(a, 0, n - 1);
	time_t end = clock();
	printf("InsertSort: %u\n", end - start);

}
void InsertSort_2(int *ar, int left, int right)
{
	for (int i = left + 1; i <= right; ++i)
	{
		ar[0] = ar[i];
		int j = i;
		while (ar[0]<ar[j - 1])
		{
			ar[j] = ar[j - 1];
			j--;
		}
		ar[j] = ar[0];
	}
}
void BinInsertSort(int *ar, int left, int right)//二分插入
{
	for (int i = left + 1; i <= right; ++i)
	{
		int tmp = ar[i];
		int low = left;
		int high = i - 1;
		int mid;
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (ar[i] >= ar[mid])
				low = mid + 1;
			if (ar[i] < ar[mid])
				high = mid - 1;
		}
		for (int j = i; j>low; --j)
		{
			ar[j] = ar[j - 1];
		}
		ar[low] = tmp;
	}
}
void TowWayInsertSort(int *ar, int left, int right)//二路查找
{
	int n = right - left + 1;
	int *tmp = (int*)malloc(sizeof(int));


	int first, final;
	tmp[0] = ar[left];
	first = final = 0;

	for (int i = left + 1; i <= right; ++i)
	{
		if (ar[i] < tmp[first])
		{
			first=(first-1+n)%n;
			tmp[first] = ar[i];
		}
		else if (ar[i] > tmp[first])
		{
			tmp[++final] = ar[i];
		}
		else
		{
			int end = final;
			while (ar[i] < tmp[end])
			{
				ar[(end + 1)%n] = tmp[end];
				end = (end - 1 + n) % n;
			}
			tmp[(end + 1) % n] = ar[i];
			final++;
		}
	}
	int k = 0;
	for (int i = first; k < n;)
	{
		ar[k++] = tmp[i];
		i = (i + 1) % n;
	}
	free(tmp);
	tmp = NULL;
}

//希尔排序  基本有序  直接插入
/*
int dlta[4] = { 5, 3, 2, 1 };
void _ShellSort(int *ar, int left, int right, int gap)
{
	for (int i = left ; i <= right-gap; ++i)
	{
		//int end = i;
		//int tmp = ar[end + gap];
		//while (end>=left&&tmp < ar[end])
		//{
		//	ar[end + gap] = ar[end];
		//	end -= gap;
		//}
		//ar[end + gap] = tmp;

		if (ar[i + gap] < ar[i])
		{
			int end = i;
			int tmp = ar[end + gap];
			while (end >= left&&tmp < ar[end])
			{
				ar[end + gap] = ar[end];
				end -= gap;
			}
			ar[end + gap] = tmp;
		}
	}
}
void ShellSort(int *ar, int left, int right)
{
	int n = sizeof(dlta) / sizeof(int);
	for (int i = 0; i < n; ++i)
	{
		_ShellSort(ar, left, right, dlta[i]);
	}
}*/
void ShellSort(int *ar, int left, int right)//希尔排序
{
	int gap = right - left + 1;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = left; i <= right - gap; ++i)
		{
			if (ar[i + gap] < ar[i])
			{
				int end = i;
				int tmp = ar[end + gap];
				while (end >= left&&tmp < ar[end])
				{
					ar[end + gap] = ar[end];
					end -= gap;
				}
				ar[end + gap] = tmp;
			}
		}
	}
}

//快速排序

void 
/*
void PrintArray(int *ar, int left, int right)
{
	for (int i = left; i <= right; ++i)
	{
		printf("%d ", ar[i]);
	}
}
void InsertSort(int *ar, int left, int right)
{
	for (int i = left + 1; i <= right; ++i)
	{
		int j = i;
		while (j>left&&ar[j] < ar[j - 1])
		{
			Swap(&ar[j], &ar[j - 1]);
			j--;
		}

	}
}
///////////////////////////////////////////
void TestSort(int *ar, int left, int right)
{
	TestSort(ar, left, right);
	PrintArray(ar, left, right);
}

*/
#endif/*_SORT_H_*/


