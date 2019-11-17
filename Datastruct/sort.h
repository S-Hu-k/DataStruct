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
		gap = gap / 3 + 1;//划分区间，和元素个数有关。
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

//选择排序
int GetMinIndex(int *ar, int left, int right)
{
	int min = ar[left];
	int index = left;
	for (int i = left + 1; i <= right; ++i)
	{
		if (ar[i] < min)
		{
			min = ar[i];
			index = i;
		}
	}
		return index;
}
void SelectSort(int *ar, int left, int right)
{
	for (int i = left; i <= right; ++i)
	{
		int index = GetMinIndex(ar, i, right);
		if (index != i)
		{
			Swap(&ar[index], &ar[i]);
		}
	}
}

//堆排是选择排序

void _AdjustDown(int *ar, int left, int right, int start)
{
	int n =  right - left+1;
	int i = start;
	int j = 2 * i + 1+left;
	while (j<n)
	{
		if (j + 1 < n && ar[j] < ar[j + 1])
			j++;
		if (ar[i] < ar[j])
		{
			Swap(&ar[i], &ar[j]);
			i = j;
			j = 2 * i + 1;
		}
		else
			break;
	}
}
void  HeapSort(int *ar, int left, int right)
{
	int n = right - left+1;
	int cur = n / 2 - 1+left;
	while (cur)
	{
		_AdjustDown(ar, left, right, cur);
		cur--;
	}
	int end = right;
	while (end > left)
	{
		Swap(&ar[left], &ar[end]);
		end--;
		_AdjustDown(ar, left, end, 0);
	}
}

/*
void _AdjustDown(int *ar, int left, int right, int start)
{
	int n = right - left + 1;
	int i = start;
	int j = 2 * i + 1 + left; //+left
	while (j < n)
	{
		if (j + 1<n && ar[j]<ar[j + 1])
			j++;
		if (ar[i] < ar[j])
		{
			Swap(&ar[i], &ar[j]);
			i = j;
			j = 2 * i + 1;
		}
		else
			break;
	}
}
void HeapSort(int *ar, int left, int right)
{
	int n = right - left + 1;
	int cur = n / 2 - 1 + left; //+left
	while (cur)
	{
		_AdjustDown(ar, left, right, cur);
		cur--;
	}
	int end = right;
	while (end > left)
	{
	Swap(&ar[left], &ar[end]);
		end--;
		_AdjustDown(ar, left, end, 0);
	}
}*/
//交换排序
//冒泡排序

void BubbleSort(int *ar, int left, int right)
{
	int n = right - left + 1;
	for (int i = left; i <= right-1; ++i)
	{
		for (int j = left; j < n - i - 1; ++j)
		{
			if (ar[j]>ar[j + 1])
			{
				Swap(&ar[j], &ar[j + 1]);
			}
		}
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

*/
//快速排序
int _Partition(int *ar, int left, int right)
{
	int key = ar[left];
	while (left < right)
	{
		while (left<right&&ar[right]>=key)
			right--;
		Swap(&ar[left], &ar[right]);
		while (ar[right] < key)
			left++;
		Swap(&ar[left], &ar[right]);

	}
	return left;
}
void QuickSort(int *ar, int left, int right)
{
	if (left >= right)
		return;
	int pos = _Partition(ar, left, right);
	QuickSort(ar, left, pos - 1);
	QuickSort(ar, pos + 1, right);
}

//调动函数会增加时间，通常用覆盖。

/*
int _Partition_1(int *ar, int left, int right)
{
	int key = ar[left];
	while (left < right)
	{
		while (left<right&&ar[right] >= key)
			right--;
		ar[left] = ar[right];
		while (ar[right] < key)
			left++;
		ar[right] = ar[left];

	}
	ar[left] = key;
	return left;
}
 
int _Partition_2(int *ar, int left, int right)
{
	int key = ar[left];
	int pos = left;
	for (int i = left + 1; i <= right; ++i)
	{
		if (ar[i] < key)
		{
			pos++;
			if (pos != i)
			{
				Swap(&ar[pos], &ar[i]);
			}
		}
	}
	Swap(&ar[left], &ar[pos]);
	return pos;
}
#define M 5

void QuickSort(int *ar, int left, int right)
{
if(left >= right)
return;
if(right-left+1 <= M)
{
InsertSort_1(ar, left, right);
}
else
{
int pos = _Partition_3(ar, left, right);
QuickSort(ar, left, pos-1);
QuickSort(ar, pos+1, right);
}
}
 */
/*
//归并排序
void _MergeSort(int *ar, int left, int right )
{
	if (left > right)
		return;



	//归并
	int  begin1, end1, begin2, end2, i;
	begin1 = i;
	begin2 = 0;
}




void MergeSort(int *ar, int left, int right)
{
	int n = right - left + 1;
	int *tmp1 = (int*)malloc(sizeof(int)*n);
	_MergeSort(ar, left, right, tmp1);
	free(tmp1);
	tmp1 = NULL;
}
*/
//非比较排序 基数排序 1.分发 2.回收
#include"slist.h"
#define k 3
#define RADIX 10
SList list[RADIX];

int GetKey(int value, int K)
{
	int key;
	while (	K>= 0)
	{
		key = value % 10;
		value /= 10;
		K--;
	}
}

void Distribute(int *ar, int left, int right, int K)
{
	for (int i=left; i <= right; ++i)
	{
		int key = GetKey(ar[i], K);
		SListPushBack(&list[key], ar[i]);
	}
}
void Collect(int *ar)
{
	int K = 0;
	for (int i = 0; i < RADIX; ++i)
	{
		if (! SListEmpty(&list[i]))
		{
			SListNode *p = list[i].first->next;
			while (p != NULL)
			{
				ar[K++] = p->data;
				p = p->next;
			}
		}
	}
	for (int i = 0; i < RADIX; ++i)
		SListClear(&list[i]);
}


void RadixSort(int *ar, int left, int right)//基数排序
{
	for (int i = 0; i < RADIX; ++i)
	{
		SListInit(&list[i]);
	}
		for (int i = 0; i < k; ++i)
		{
			//分发
			Distribute(ar, left, right, i);
			//回收
			Collect(ar);
		}
}

#endif/*_SORT_H_*/


