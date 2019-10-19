#ifndef _STACK_H_
#define _STACK_H_
#include"common.h"

#define STACK_DEFAULT_SIZE 8
typedef struct SeqStack
{
	DataType  *base;
	size_t capacity;
	int top;
}SeqStack;

//顺序栈
void SeqStackInit(SeqStack *pst, int sz);
SeqStack*  SeqStackInit_1(int sz);
BOOL SeqStackFull(SeqStack *pst);
BOOL SeqStackEmpty(SeqStack *pst);
DataType SeqStackTop(SeqStack *pst);
void SeqStackPushBack(SeqStack *pst, DataType x);
void SeqStackPop(SeqStack *pst);
void SeqStackShow(SeqStack *pst);



BOOL SeqStackFull(SeqStack *pst)
{
	if ((pst->top) >= (pst->capacity))
		return TRUE;
	return FALSE;
}
BOOL SeqStackEmpty(SeqStack *pst)
{
	if (pst->top == 0)
		return TRUE;
	return FALSE;
}


//取了一个指针  初参返回
void SeqStackInit(SeqStack *pst, int sz)
{
	pst->capacity = sz > STACK_DEFAULT_SIZE ? sz : STACK_DEFAULT_SIZE;
	pst->base = (DataType*)malloc(sizeof(DataType)*pst->capacity);
	pst->top = 0;
}
//开辟了一个栈   栈返回
SeqStack*  SeqStackInit_1(int sz)
{
	SeqStack *pst = (SeqStack*)malloc(sizeof(SeqStack));
	pst->capacity = sz > STACK_DEFAULT_SIZE ? sz : STACK_DEFAULT_SIZE;
	pst->base = (DataType*)malloc(sizeof(DataType)*pst->capacity);
	pst->top = 0;
	return pst;
}
DataType SeqStackTop(SeqStack *pst)
{
	if (SeqStackEmpty(pst))
	{
		printf("栈已空，不能取栈顶元素.\n");
		return ;
	}
	return pst->base[pst->top - 1];
}
void SeqStackPushBack(SeqStack *pst,DataType x)
{
	if (SeqStackFull(pst))
	{
		printf("栈已满，%d不能插入.\n", x);
		return;
	}
	pst->base[pst->top++] = x;
	
}
void SeqStackPop(SeqStack *pst)
{
	if (SeqStackEmpty(pst))
	{
		printf("栈已空，不能出栈.\n");
		return;
	}
	pst->top--;
}
void SeqStackShow(SeqStack *pst)
{
	for (int i = pst->top - 1; i >= 0; --i)

		printf("%d\n", pst->base[i]);
}

//链栈
typedef struct StackNode
{
	DataType data;
	struct StackNode *next;
}StackNode;
typedef StackNode *ListStack;

void ListStackInit(ListStack*pst);
bool ListStackPush(ListStack*pst,DataType x);
DataType ListStackTop(ListStack*pst);
void ListStackShow(ListStack*pst);
void ListStackPop(ListStack *pst);


///////////////////////////////////////////
void ListStackInit(ListStack*pst)
{
	*pst = NULL;
}
bool ListStackPush(ListStack*pst, DataType x)
{
	ListStack *node = (ListStack*)malloc(sizeof(StackNode));
	assert(node != NULL);
	node->data = x;
	node->next = *pst;
	*pst = node;
}

DataType ListStackTop(ListStack*pst)
{
	assert(*pst != NULL);
	return (*pst)->data;
}



void ListStackPop(ListStack *pst)
{
	StackNode *p = *pst;
	*pst = p->next;
	free(p);
}

void ListStackShow(ListStack pst)
{
	StackNode *p = pst;
	while (p != NULL)
	{
		printf("%d\n", p->data);
		p = p->next;
	}
}


#endif