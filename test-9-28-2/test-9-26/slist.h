#ifndef _SLIST_H_
#define _SLIST_H_
#include"common.h"

//typedef struct Node
//{
//	DataType date;
//	struct Node *next;
//}Node;
typedef struct SListNode
{
	DataType date;
	struct SListNode *next;
}SListNode;


typedef struct SList
{
	SListNode *first;
	SListNode *last;
	size_t     size;

}SList;


bool SListPushBack(SList *plist, DataType x);
bool SListPushFront(SList *plist, DataType x);


bool SListPopBack(SList *plist);
bool SListPopFront(SList *plist);

SListNode* SListFindByVal(SList *plist, DataType key);
bool SListDeleteByVal(SList *plist, DataType key);


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
	s->next = plist->first->next;
	plist->first->next=s;
	if (plist->size ==0)
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
		p=p->next;

	p->next = NULL;
	free(plist->last);
	plist->last = p;
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
	free(p);
	plist->size--;
	if (plist->size == 0)
		plist->last = plist->first;
	return true;

}

SListNode* SListFindByVal(SList *plist, DataType key)
{
	SListNode *p = plist->first->next;
	//while (p != NULL&&p->date != key)
	//p = p->next;
	//return p;
	while (p != NULL)
	{
		if (p->date == key)
			return p;
	}
		p = p->next;
	return p;
}
bool SListDeleteByVal(SList *plist, DataType key)
{
	SListNode *q;
	SListNode *p = plist->first;
	while (&p != key)
	{
		p = p->next;
	}
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
#endif