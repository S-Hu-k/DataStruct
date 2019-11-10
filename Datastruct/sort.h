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
void TestSort(int *ar, int left, int right)
{
	/*TestSort(ar, left, right);
	InsertSort_1(ar, left, right);
	InsertSort_2(ar, left, right); */
	BinInsertSort(ar, left, right);


	PrintArray(ar, left, right);
}


//²åÈëÅÅÐò
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
void BinInsertSort(int *ar, int left, int right)
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
//void TowWayInsertSort(int *ar, int left, int right)
//{
//	int left = 0;
//}*/
#endif/*_SORT_H_*/


