//#ifndef _SEQLIST_H_
//#define _SEQLIST_H_
//#include"common.h"
//#define SEQLIST_DEFAULT_SIZE 8
//typedef struct SeqList
//{
//	DataType *base;
//	size_t capacity;
//	size_t size;
//
//}SeqList;
//////
////声明
//void SeqListInit(SeqList *psl, int sz);
//bool SeqListPushBack(SeqList *psl, DataType x);
//bool SeqListPushFront(SeqList *psl, DataType x);
//bool SeqListLength(SeqList *psl);
//void SeqListModifyPos(SeqList *psl, DataType pos, DataType val);
//
//
//
//bool SeqListIsFull(SeqList *psl)
//{
//	return psl->size >= psl->capacity;
//}
//bool SeqListIsEmpty(SeqList *psl)
//{
//	return psl->size == 0;
//}
//
//
////实现
//void SeqListInit(SeqList *psl, int sz)
//{
//	psl->capacity = sz > SEQLIST_DEFAULT_SIZE ? sz : SEQLIST_DEFAULT_SIZE;
//	psl->base = (DataType*)malloc(sizeof(DataType)*(psl->capacity));
//	psl->size = 0;
//}
//
//bool SeqListPushBack(SeqList *psl, DataType x)
//{
//	assert(psl);
//	if (SeqListIsFull(psl))
//	{
//		printf("顺序表已满, %d 不能插入.\n", x);
//		return false;
//	}
//	psl->base[psl->size++] = x;
//	return true;
//}
//
//bool SeqListPushFront(SeqList *psl, DataType x)
//{
//	assert(psl);
//	if (SeqListIsFull(psl))
//	{
//		printf("顺序表已满, %d 不能插入.\n", x);
//		return false;
//	}
//	for (int i = psl->size; i>0; --i)
//	{
//		psl->base[i] = psl->base[i - 1];
//	}
//	psl->base[0] = x;
//	psl->size++;
//	return true;
//}
//
//void SeqListShow(SeqList *psl)
//{
//	for (int i = 0; i < psl->size; ++i)
//	{
//		printf("%d ", psl->base[i]);
//	}
//	printf("\n");
//}
////bool SeqListInsertPos(SeqList *psl, DataType x)
////{
////	assert(psl);
////	if (SeqListIsFull(psl))
////	{
////		printf("顺序表已满, %d 不能插入.\n", x);
////		return false;
////	}
////	else
////		if
////}
//bool SeqListLength(SeqList *psl)
//{
//	assert(psl);
//	return psl->size;
//}
//bool SeqListClear(SeqList *psl)
//{
//	assert(psl);
//	if (SeqListIsFull(psl))
//	{
//		printf("目录已经是空的，无须清除\n");
//	}
//	else
//	{
//		for (int i = 0; i < psl->size; ++i)
//		{
//			psl->base[i] = 0;
//		}
//	}
//}
//void SeqListModifyPos(SeqList *psl, DataType pos, DataType val)
//{
//
//	assert(psl);
//	psl->base[pos] = val;
//}
//#endif
//
