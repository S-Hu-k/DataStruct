#ifndef _BST_H_
#define _BST_H_
#include"common.h"

typedef struct BstNode
{
	DataType data;
	struct BstNode *leftChild;
	struct BstNode *rightChild;
}BstNode;
typedef BstNode* BSTree;
void BSTreeInit(BSTree *t);
bool Insert(BSTree *t, DataType x);
void Sort(BSTree *t, int *ar, int *i);
bool Remove(BSTree *t, DataType key);
DataType MIN(BSTree t);
DataType MAX(BSTree t);


void BSTreeInit(BSTree *t){
	*t = NULL;
}
bool Insert(BSTree *t, DataType x)
{
	if (*t == NULL)
	{
		*t = (BstNode*)malloc(sizeof(BstNode));
		(*t)->data = x;
		(*t)->leftChild = NULL;
		(*t)->rightChild = NULL;
		return true;
	}
	else if (x < (*t)->data)
		Insert((&(*t)->leftChild), x);
	else if (x >(*t)->data)
		Insert((&(*t)->rightChild), x);
	else
		return false;
}
void Sort(BSTree t, int *ar, int *i)
{
	if (t != NULL)
	{
		Sort(t->leftChild, ar, i);
		ar[*i] = t->data;
		(*i)++;
		Sort(t->rightChild, ar, i);
	}
}
bool Remove(BSTree *t, DataType key)
{
	if (*t == NULL)
		return false;
	else if(key < (*t)->data)
		Remove(&((*t)->leftChild), key);
	else if (key>(*t)->data)
		Remove(&((*t)->rightChild), key);
	else
	{
		BstNode *p = *t;
		if (p->leftChild == NULL&&p->rightChild == NULL)
		{
			free(p);
			*t = NULL;
		}
		else if (p->leftChild != NULL&&p->rightChild == NULL)
		{
			p = *t;
			p = (*t)->leftChild;
			free(p);
		}
		else if (p->leftChild == NULL&&p->rightChild != NULL)
		{
			p = *t;
			p = (*t)->rightChild;
			free(p);
		}
		else
		{
			p = (*t)->leftChild;
			while (p->leftChild != NULL)
				p = p->rightChild;
			(*t)->data = p->data;
			Remove(&((*t)->leftChild), p->data);
		}
		return true;
	}

}

DataType MIN(BSTree t)
{
	while(t->leftChild != NULL)
		t = t->leftChild;
	return t->data;
}
DataType MAX(BSTree t)
{
	while (t->rightChild != NULL)
		t = t->rightChild;
	return t->data;
}
#endif