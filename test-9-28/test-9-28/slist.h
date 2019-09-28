#ifndef _SLIST_H_
#define _SLIST_H_
#include"common.h"

//typedef struct Node
//{
//	DataType date;
//	struct Node *next;
//}Node;
//
//typedef Node* List;
//
//
//void InitList(List *head);
//void CreatList_Tail(List *head);
//void CreatList_Front(List *head);
//void ShowList(List head);
//
////头节点不需要初始化第一个节点；
//void CreatList_Tail(List *head)
//{
//	*head = (Node*)malloc(sizeof(Node));
//	(*head)->date = 1;
//	(*head)->next = NULL;
//
//
//	Node *p = *head;
//	for (int i = 2; i <= 10; ++i)
//	{
//		Node *s =(Node*)malloc(sizeof(Node));
//		assert(s != NULL);
//		s->date = i;
//		s->next = NULL;
//
//	}
//}
//void ShowList(List head)
//{
//	for (int i = 2; i <= 10; ++i)
//	{
//		printf("%d",)
//	}
//}
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
bool SListPushBack(SList *plist, DataType x)
{
	SListNode *s = (SListNode*)malloc(sizeof(SListNode));//先将节点申请出来
	assert(s != NULL);
	SListNode *s = _Buynode(x);
	 plist->last->next = s;

	plist->last = s;
	plist->size++;
	return true;

}

#endif