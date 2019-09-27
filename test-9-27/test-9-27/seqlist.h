#ifndef _COMMON_H_
#define _COMMON_H_


#include"common.h"


#define SEQLIST_DEFAULT_SIZE 8
typedef struct SeqList
{
	DataType *base;
	size_t capacity;
	size_t size;

}SeqList;
////
//声明
void SeqListInit(SeqList *psl, int sz);
int SeqListPushBack(SeqList *psl, DataType x);
int SeqListPushFront(SeqList *psl, DataType x);
int SeqListLength(SeqList *psl);
void SeqListModifyByPos(SeqList *psl, int pos, DataType x);

int SeqListIsFull(SeqList *psl)
{
	return psl->size >= psl->capacity;
}
int SeqListIsEmpty(SeqList *psl)
{
	return psl->size == 0;
}


//实现
void SeqListInit(SeqList *psl, int sz)
{
	psl->capacity = sz > SEQLIST_DEFAULT_SIZE ? sz : SEQLIST_DEFAULT_SIZE;
	psl->base = (DataType*)malloc(sizeof(DataType)*(psl->capacity));
	psl->size = 0;
}

int SeqListPushBack(SeqList *psl, DataType x)
{
	assert(psl);
	if (SeqListIsFull(psl))
	{
		printf("顺序表已满, %d 不能插入.\n", x);
		return 0;
	}
	psl->base[psl->size++] = x;
	return 1;
}

int SeqListPushFront(SeqList *psl, DataType x)
{
	assert(psl);
	if (SeqListIsFull(psl))
	{
		printf("顺序表已满, %d 不能插入.\n", x);
		return 0;
	}
	for (int i = psl->size; i>0; --i)
	{
		psl->base[i] = psl->base[i - 1];
	}
	psl->base[0] = x;
	psl->size++;
	return 1;
}

void SeqListShow(SeqList *psl)
{
	for (int i = 0; i<psl->size; ++i)
	{
		printf("%d ", psl->base[i]);
	}
	printf("\n");
}
int SeqListLength(SeqList *psl)
{
	assert(psl);
	return psl->size;
}

#endif