#ifndef _DLIST_H_
#define _DLIST_H_
#include"common.h"
typedef struct DListNode
{
	DataType data;
	struct DListNode *next;
	struct DListNode *prev;
}DListNode;

typedef struct DList
{
	struct DListNode *first;
	struct DListNode *last;
	size_t     size;
}DList;

DListNode* _Buynode(DataType x)
{
	DListNode *s = (DListNode*)malloc(sizeof(DListNode));
	if ( NULL==s)
		return NULL;

	s->next = s->prev= NULL;
	s->data= x;
	return s;
}


void DListInit(DList *plist);
void DListShow(DList *plist);
bool DListPushBack(DList *plist, DataType x);
bool DListPushFront(DList *plist, DataType x);
bool DListDeleteVal(DList *plist, DataType x);
DListNode* DListFindVal(DList *plist, DataType x);
bool DListPopBack(DList *plist);
bool DListPopFront(DList *plist);
size_t DListLength(DList *plist);
void DListClear(DList *plist);
void DListreverse(DList *plist);
void DListSort(DList *plist);
/////////////////////////////////////////////
void DListInit(DList *plist)
{
	DListNode *s = _Buynode(0);
	plist->first = plist->last=s;
	plist->size = 0;

}

void DListShow(DList *plist)
{
	DListNode *p = plist->first->next;
     while (p != NULL)
	{
		printf("%d-->", p->data);
		p = p->next;
	}
	printf("over.\n");
}
bool DListPushBack(DList *plist, DataType x)
{
	DListNode *s = _Buynode(x);
	if (s == NULL)
		return false;

	plist->last->next = s;
	s->prev = plist->last;
	plist->last = s;


	plist->size++;
	return true;
}
bool DListPushFront(DList *plist, DataType x)
{
	DListNode *s = _Buynode(x);
	if (s == NULL)
		return false;

	/*plist->first->next = s;
	s->next=plist->first->next;
	s->prev = plist->first;
	plist->last->prev = s;*/
	s->next = plist->first->next;
	if (s->next != NULL)
		s->next->prev = s;
	s->prev = plist->first;
	s->prev->next = s;

	if (plist->size == 0)
		plist->last = s;

	plist->size++;
	return true;
}

bool DListDeleteVal(DList *plist, DataType x)
{
	DListNode *p = DListFindVal(plist, x);

	if (p == NULL)
		return false;

	if (p == plist->last)
		plist->last = p->prev;
		p->prev->next = p->next;
		if (p->next!=NULL)

	p->next->prev = p->prev;
		free(p);
	plist->size--;
	return true;
}


DListNode* DListFindVal(DList *plist, DataType x)
{
	DListNode* p = plist->first->next;
	while (p != NULL&&p->data != x)
		p = p->next;
	return p;
}

bool DListPopBack(DList *plist)
{
	DListNode *p;
	if (plist->size == 0)
		return false;
	p = plist->first->next;
	while (p != plist->last)
		p = p->next;

	p->next = NULL;	

	p->prev = plist->last;
	plist->last->next =NULL;

	free(p);
	plist->size--;
	return true;
}
bool DListPopFront(DList *plist)
{
	DListNode *p = plist->first->next;
	if (p == NULL)
		return false;

	plist->first->next = p->next;
	p->next->prev = plist->first;
	
	free(p);
	plist->size--;
	return true;

}
size_t DListLength(DList *plist)
{
	return plist->size;
}

void DListClear(DList *plist)
{
	DListNode*p = plist->first->next;
	while (p != NULL)
	{
		plist->first->next = p->next;
		free(p);
		p = plist->first->next;
	}
	plist->last = plist->first;
	plist->first=plist->last;
	plist->size = 0;
	
	return true;
}

void DListreverse(DList *plist)
{
	DListNode*p1, *p2, *p3;
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

void DListSort(DList *plist)
{
	if (plist->size > 1)
	{
		DListNode *prev;
		DListNode *p = plist->first->next;
		DListNode *q = p->next;
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

#endif
