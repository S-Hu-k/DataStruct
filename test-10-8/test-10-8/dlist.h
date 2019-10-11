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
	s->next=plist->last;
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

#endif
