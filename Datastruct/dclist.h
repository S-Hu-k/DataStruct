#ifndef _DCLIST_H_
#define _DCLIST_H_
#include"common.h"

typedef struct DCListNode
{
	DataType data;
	struct DCListNode *next;
	struct DCListNode *prev;
}DCListNode;
typedef struct DCList
{
	struct DCListNode *first;
	struct DCListNode *last;
	size_t size;

}DCList;

DCListNode* _Buynode(DataType x)
{
	DCListNode *s = (DCListNode*)malloc(sizeof(DCListNode));
	if (NULL == s)
		return NULL;

	s->next = s->prev = NULL;
	s->data = x;
	return s;
}

void DCListInit(DCList *plist);
void DCListShow(DCList *plist);
bool DCListPushBack(DCList *plist, DataType x);
bool DCListPushFront(DCList *plist, DataType x);
size_t DCListLength(DCList *plist);
void DCListClear(DCList *plist);
void DCListDestroy(DCList *plist);
DCListNode* DCListFindVal(DCList *plist, DataType x);
//////////////////////////////////
void DCListInit(DCList *plist)
{
	DCListNode *s = _Buynode(0);
	plist->first = plist->last = s;
	plist->size = 0;
}
void DCListShow(DCList *plist)
{
	DCListNode *p = plist->first->next;
	while (p != plist->first)
	{
		printf("%d-->", p->data);
		p = p->next;
	}
	printf("over.\n");
}
bool DCListPushBack(DCList *plist, DataType x)
{
	DCListNode *p = _Buynode(x);
	if (NULL == p)
		return false;

	plist->last->next = p;
	p->prev = plist->last;
	plist->last = p;
	plist->last->next = plist->first;
	plist->first->prev = plist->last;
	
	/*plist->last->next = s;
	s->prev = plist->last;
	plist->last = s;
	plist->last->next = plist->first;
	plist->first->prev = plist->last;*/

	plist->size++;
	return true;
}
bool DCListPushFront(DCList *plist, DataType x)
{
	DCListNode *p = _Buynode(x);
	if ( NULL==p)
		return false;
	
		p->next->prev = p;
		p->next = plist->first->next;
		p->prev = plist->first;
		p->prev->next = p;
		
	
		if (plist->size == 0)
			plist->last = p;

	    plist->size++;
	return true;
}
size_t DCListLength(DCList *plist)
{
	return plist->size;
}
void DCListClear(DCList *plist)
{
	DCListNode*p = plist->first->next;
	while (p != plist->first)
	{
		p->next->prev = p->prev;
		p->prev->next = p->next;
		free(p);
		p = plist->first->next;
	}
	plist->size = 0;
}

void DCListDestroy(DCList *plist)
{
	DCListClear(plist);
	free(plist->first);
	plist->first = plist->last = NULL;
}
DCListNode* DCListFindVal(DCList *plist, DataType x)
{
	DCListNode *p = plist->first->next;
	while (p != NULL&&p->data != x)
		p = p->next;
	return p;
}

//bool DCListPushFront(DCList *plist, DataType x)
//{
//	DCListNode *s = _Buynode(x);
//	if (s == NULL)
//		return false;
//
//	s->next = plist->first->next;
//	s->next->prev = s;
//	s->prev = plist->first;
//	s->prev->next = s;
//
//	if (plist->size == 0)
//
//		plist->last = s;
//
//	plist->size++;
//	return true;
//}

//void DCListInit(DCList *plist)
//{
//	DCListNode *s = _Buynode(0);
//	plist->first = plist->last = s;
//	plist->size = 0;
//
//}
#endif