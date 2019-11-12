#ifndef _SLIST_H_
#define _SLIST_H_
#include"common.h"
typedef struct SListNode
{
	DataType data;
	struct SListNode *next;
}SListNode;

typedef struct SList
{
	SListNode *first;
	SListNode *last;
	size_t     size;
}SList;
SListNode* _Buynode(DataType x)
{


	SListNode *s = (SListNode*)malloc(sizeof(SListNode));//¹ºÂò¿Õ¼ä
	//assert(s != NULL);
	if (s == NULL)
		return NULL;
	s->next = NULL;
	s->data = x;
	return s;
}

void SListInit(SList *plist);
void SListShow(SList *plist);

bool SListPushBack(SList *plist, DataType x);
bool SListPushFront(SList *plist, DataType x);

bool SListPopBack(SList *plist);
bool SListPopFront(SList *plist);

bool SListInsertVal(SList *plist, DataType x);


//bool SListDeletePos(SList *plist, DataType pos);
bool SListDeleteVal(SList *plist, DataType x);

size_t SListLength(SList *plist);

void SListClear(SList *plist);

void SListDestroy(SList *plist);
void SListSort(SList *plist);

void SListreverse(SList *plist);

///////////////////////////////////////////////////////
void SListInit(SList *plist)
{
	SListNode *s = _Buynode(0);
	plist->first = plist->last = s;
	plist->size = 0;
}
void SListShow(SList *plist)
{
	SListNode *p = plist->first->next;
	while (p != NULL)
	{
		printf("%d-->", p->data);
		p = p->next;
	}
	printf("Over.\n");
}

bool SListPushBack(SList *plist, DataType x)
{
		SListNode *s = _Buynode(x);
		if (s == NULL)
			return false;
		plist->last->next = s;
		plist->last = s;
		plist->size++;
		return true;

}

bool SListPushFront(SList *plist, DataType x)
{
	SListNode *s = _Buynode(x);
	if (s == NULL)
		return false;
	s->next=plist->first->next ;
	plist->first->next = s;
	if (plist->size == 0)
		plist->last = s;
	plist->size++;
	return true;
}

bool SListPopBack(SList *plist)
{
	SListNode *p;
	if (plist->size == 0)
		return false;
	p = plist->first;

	while (p->next != plist->last)
		p = p->next;

	p->next = NULL;
	free(plist->last);
	//p = plist->last;
	plist->size--;
	return true;
}

bool SListPopFront(SList *plist)
{
	SListNode *p;
	if (plist->size == 0)
		return false;
	p = plist->first->next;
	plist->first->next = p->next;
	plist->size--;
	free(p);
	if (plist->size == 0)

		plist->last = plist->first;
	return true;

}

bool SListInsertVal(SList *plist, DataType x)
{
	SListNode *p = plist->first;
	while (p->next != NULL && x>p->next->data)
		p = p->next;
	SListNode *s = _Buynode(x);
	if (p->next == NULL)
	{
		p->next = s;
		plist->last = s;
	}
	else
	{
		s->next = p->next;
		p->next = s;
	}
	plist->size++;
	return true;
}

//bool SListDeletePos(SList *plist, DataType pos)
//{
//
//}
bool SListDeleteVal(SList *plist, DataType x)
{
	SListNode *q;
	SListNode *p = plist->first;
	while (p->next != NULL && p->next->data != x)
		p = p->next;
	if (p->next == NULL)
		return false;
	q = p->next;
	if (p->next == plist->last)
		plist->last = p;
	p->next = q->next;
	free(q);
	plist->size--;
	return true;
}

void SListClear(SList *plist)
{
	SListNode *p = plist->first->next;
	while (p != NULL)
	{
		plist->first->next = p->next;
		free(p);
		p = plist->first->next;
	}
	plist->last = plist->first;
	plist->size = 0;
}

size_t SListLength(SList *plist)
{
	return plist->size;
}


void SListDestroy(SList *plist)
{
	SListClear(plist);
	free(plist->first);
	plist->first = plist->last = NULL;
}

void SListSort(SList *plist)
{
	if (plist->size > 1)
	{
		SListNode *prev;
		SListNode *p = plist->first->next;
		SListNode *q = p->next;
		plist->last = p;
		plist->last->next = NULL;
	
		p = q;
		while (p != NULL)
		{
			q = q->next;
			prev = plist->first;
			while (prev->next != NULL && p->data>prev->next->data)
				prev = prev->next;
			if (prev->next == NULL)
			{
				prev->next = p;
				plist->last = p;
				p->next = NULL;
			}
			else
			{
				p->next = prev->next;
				prev->next = p;
			}
			p = q;
		}
	}
}


void SListreverse(SList *plist)
{
	if (plist->size > 1)
	{
		SListNode *p1, *p2, *p3;
		p1 = NULL;
		p2 = plist->first->next;
		p3 = p2->next;


		plist->last = p2;
		while (p2 != NULL)
		{
			p2->next = p1;
			p1 = p2;
			p2 = p3;
			if (p3 != NULL)
				p3 = p3->next;
		}
		plist->first->next = p1;

	}
	
	
}

//bool SListPushBack(SList *plist, DataType x)
//{
//	SListNode *s = _Buynode(x);
//	if (s == NULL)
//		return false;
//	plist->last->next = s;
//	plist->last = s;
//	plist->size++;
//	return true;
//}

//void SListShow(SList *plist)
//{
//		SListNode *p=plist->first->next;
//		while (p != NULL)
//		{
//			printf("%d-->", p->data);
//			p = p->next;
//		}
//		printf("over.\n");
//}

#endif

