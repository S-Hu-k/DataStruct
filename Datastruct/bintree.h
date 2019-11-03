#ifndef _BINTREE_H_
#define _BINTREE_H_

#include"common.h"


typedef struct BinTreeNode
{
	DataType data;
	struct BinTreeNode *leftChild;
	struct BinTreeNode *rightChild;
}BinTreeNode;

typedef struct BinTree
{
	BinTreeNode *root;
}BinTree;
//二叉数创建
void BinTreeInit(BinTree *t);
void BinTreeCreate(BinTree *t);
void _BinTreeCreate_1(BinTreeNode **t);
BinTreeNode* _BinTreeCreate_2();
BinTreeNode* _BinTreeCreateByStr(char *str, int *i);//字符串
void BinTreeCreateByStr(BinTree *t, char *str, int *i);


BinTreeNode* _BinTreeCreateBy_VLR_LVR(char*vlr, char*lvr, int n);
void BinTreeCreateBy_VLR_LVR(BinTree *t, char*vlr, char*lvr, int n);


//二叉树遍历
void _PreOrder(BinTreeNode *t);
void PreOrder(BinTree *t);
void _InOrder(BinTreeNode *t);
void InOrder(BinTree *t);
void _PostOrder(BinTreeNode *t);
void PostOrder(BinTree *t);
void _LevelOrder(BinTreeNode *t);
void LevelOrder(BinTree *t);

//二叉树实现  递归
size_t _Size(BinTreeNode* t);
size_t Size(BinTree *t);
size_t _Height(BinTreeNode* t);
size_t Height(BinTree *t);
BinTreeNode* _Find(BinTreeNode *t, DataType key);
BinTreeNode* Find(BinTree *t, DataType key);
BinTreeNode* _Parent(BinTreeNode *t, DataType key);
BinTreeNode* Parent(BinTree *t, DataType key);

BinTreeNode* _Clone(BinTreeNode *t);
void Clone(BinTree *t1, BinTree *t2);
bool _Equal(BinTreeNode *t1, BinTreeNode *t2);// true false
bool Equal(BinTree *t1, BinTree *t2);// true false

//非递归（重点）
void _PreOrderNoR(BinTreeNode *t);
void PreOrderNoR(BinTree *t);
void _InOrderNoR(BinTreeNode *t);
void InOrderNoR(BinTree *t);
void _PostOrderNoR(BinTreeNode *t);
void PostOrderNoR(BinTree *t);


void BinTreeInit(BinTree *t)
{
	t->root = NULL;
}
void BinTreeCreate(BinTree *t)
{
	//_BinTreeCreate(&t->root);
	t->root = _BinTreeCreate_2();
}
void _BinTreeCreate_1(BinTreeNode **t)
{
	DataType item;
	scanf("%c", &item);
	if (item == '#')
	{
		*t = NULL;
	}
	else
	{
		*t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(*t != NULL);
		(*t)->data = item;
		_BinTreeCreate_1(&((*t)->leftChild));
		_BinTreeCreate_1(&((*t)->rightChild));
	}
}
BinTreeNode* _BinTreeCreate_2()
{
	DataType item;
	scanf("%c", &item);
	if (item == '#')
	{
		return NULL;
	}
	else
	{
		BinTreeNode *t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(t != NULL);
		t->data = item;
		t->leftChild = _BinTreeCreate_2();
		t->rightChild = _BinTreeCreate_2();
		return t;
	}
}
BinTreeNode* _BinTreeCreateByStr(char *str, int *i)
{
	if (str[*i] == '#' || str[*i] == '\0')
		return NULL;
	else
	{
		BinTreeNode *t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		t->data = str[*i];
		(*i)++;
		t->leftChild = _BinTreeCreateByStr(str, i);
		(*i)++;
		t->rightChild = _BinTreeCreateByStr(str, i);
		return t;


	}
}
void BinTreeCreateByStr(BinTree *t, char *str, int *i)
{
	t->root = _BinTreeCreateByStr(str, i);
}
#include"queue.h"
void _LevelOrder(BinTreeNode *t)
{
	if (t != NULL)
	{
		LinkQueue Q;
		LinkQueueInit(&Q);

		LinkQueueEn(&Q, t);
		while (!LinkQueueEmpty(&Q))
		{
			BinTreeNode *p = LinkQueueFront(&Q);
			LinkQueueDe(&Q);
			printf("%c ", p->data);
			if (p->leftChild != NULL)
				LinkQueueEn(&Q, p->leftChild);
			if (p->rightChild != NULL)
				LinkQueueEn(&Q, p->rightChild);
		}
	}
}
void LevelOrder(BinTree *t)
{
	_LevelOrder(t->root);
}
void PreOrder(BinTree *t)
{
	_PreOrder(t->root);
}
void _PreOrder(BinTreeNode *t)
{
	if (t != NULL)
	{
		printf("%c ", t->data);
		_PreOrder(t->leftChild);
		_PreOrder(t->rightChild);
	}
}

void InOrder(BinTree *t)
{
	_InOrder(t->root);
}
void _InOrder(BinTreeNode *t)
{
	if (t != NULL)
	{
		_InOrder(t->leftChild);
		printf("%c ", t->data);
		_InOrder(t->rightChild);
	}
}
void _PostOrder(BinTreeNode *t)
{
	if (t != NULL)
	{
		_PostOrder(t->leftChild);
		_PostOrder(t->rightChild);
		printf("%c ", t->data);
		
	}
}
void PostOrder(BinTree *t)
{
	_PostOrder(t->root);
}
size_t _Size(BinTreeNode* t)
{
	if (t == NULL)
		return 0;
	else
		return _Size(t->leftChild) + _Size(t->rightChild) + 1;

}
size_t Size(BinTree *t)
{
	return _Size(t->root);
}
size_t _Height(BinTreeNode* t)
{
	if (t == NULL)
		return 0;
	else
	{
		int left_h = _Height(t->leftChild);
		int right_h = _Height(t->rightChild);
		return (left_h > right_h ? left_h : right_h) + 1;
	}
}
size_t Height(BinTree *t)
{
	return _Height(t->root);
}
BinTreeNode* _Find(BinTreeNode *t, DataType key)
{
	BinTreeNode *p;
	if (t == NULL)
		return NULL;
	if (t->data == key)
		return t;
	else
	{
		p = _Find(t->leftChild, key);
		if (p != NULL)
			return p;
		return _Find(t->rightChild, key);
	}
}
BinTreeNode* Find(BinTree *t, DataType key)
{
	return _Find(t->root, key);
}
BinTreeNode* _Parent(BinTreeNode *t, DataType key)
{
	int pr = 0;
	BinTreeNode *p;
	p = _Find(t, key);
	if (p == NULL || t == NULL || p == t)
		return NULL;
	if (t->leftChild == p || t->rightChild == p)
		return t;
	pr = _Parent(t->leftChild, key);
	if (pr != NULL)
		return pr;
	return _Parent(t->rightChild, key);

}
BinTreeNode* Parent(BinTree *t, DataType key)
{
	return _Parent(t->root, key);
}

BinTreeNode* _Clone(BinTreeNode *t)
{
	if (t == NULL)
		return false;
	else
	{
		BinTreeNode *p = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		p->data = t->data;
		p->leftChild = _Clone(t->leftChild);
		p->rightChild = _Clone(t->rightChild);
		return p;
	}
}
//
//BinTreeNode* _Clone(BinTreeNode *t)
//{
//	if (t == NULL)
//		return NULL;
//	else
//	{
//		BinTreeNode *p = (BinTreeNode*)malloc(sizeof(BinTreeNode));
//		p->data = t->data;
//		p->leftChild = _Clone(t->leftChild);
//		p->rightChild = _Clone(t->rightChild);
//		return p;
//
//
//	}
//}
void Clone(BinTree *t1, BinTree *t2)
{
	t2->root= _Clone(t1->root);
}
bool _Equal(BinTreeNode *t1, BinTreeNode *t2)
{
	if (t1 == NULL&&t2 == NULL)
		return true;
	if (t1 == NULL || t2 == NULL)
		return false;
	return ((t1->data == t2->data)&&_Equal(t1->leftChild, t2->leftChild) && _Equal(t1->rightChild, t2->rightChild));
}
//bool _Equal(BinTreeNode *t1, BinTreeNode *t2)// true false
//{
//	if (t1 == NULL&&t2 == NULL)
//		return true;
//	if (t1 == NULL || t2 == NULL)
//		return false;
//	return (t1->data == t2->data) && _Equal(t1->leftChild, t2->leftChild) && _Equal(t1->rightChild, t2->rightChild);
//
//}
bool Equal(BinTree *t1, BinTree *t2)// true false
{
	return _Equal(t1->root, t2->root);
}

#include"stack.h"
void _PreOrderNoR(BinTreeNode *t)
{
	/*if (t != NULL)
	{
		BinTreeNode *p;
		ListStack st;
		ListStackInit(&st);
		ListStackPush(&st, t);
		while (!ListStackEmpty(&st))
		{
			p = ListStackTop(&st);
			ListStackPop(&st);
			printf("%c ", p->data);
			if (p->rightChild != NULL)
				ListStackPush(&st, p->rightChild);
			if (p->leftChild != NULL)
				ListStackPush(&st, p->leftChild);
		}
	}*/
	if (t != NULL)
	{
		BinTreeNode *p;
		ListStack st;
		ListStackInit(&st);
		do
		{
			while (t != NULL)
			{
				ListStackPush(&st, t);
			    t = t->leftChild;
			}
			p = ListStackTop(&st);
			ListStackPop(&st);
			printf("%c ", p->data);
			if (p->rightChild != NULL)
			t = p->rightChild;
		} while (!ListStackEmpty(&st) || t != NULL);
	}
}
void PreOrderNoR(BinTree *t)
{
	_PreOrderNoR(t->root);
}
void _InOrderNoR(BinTreeNode *t)
{
	if (t != NULL)
	{
		BinTreeNode *p;
		ListStack st;
		ListStackInit(&st);
		ListStackPush(&st, t);
		while (!ListStackEmpty(&st))
		{
			p = ListStackTop(&st);
			ListStackPop(&st);
			printf("%c ", p->data);
			if (p->rightChild != NULL)
				ListStackPush(&st, p->rightChild);
			if (p->leftChild != NULL)
				ListStackPush(&st, p->leftChild);
		}
	}
}
void InOrderNoR(BinTree *t)
{
	_InOrderNoR(t->root);
}
void _PostOrderNoR(BinTreeNode *t)
{
	if (t != NULL)
	{
		BinTreeNode *p, *pre = NULL;
		ListStack st;
		ListStackInit(&st);

	do
		{
			while (t != NULL)
			{
				ListStackPush(&st, t);
				t = t->leftChild;
			}
			p = ListStackTop(&st);
			if (p->rightChild == NULL || p->rightChild == pre)
			{
				ListStackPop(&st);
				printf("%c ", p->data);
				pre = p;
			}
			else
			{
			t = p->rightChild;
			}
		} while (!ListStackEmpty(&st));
	}
}
void PostOrderNoR(BinTree *t)
{
	_PostOrderNoR(t->root);
}
BinTreeNode* _BinTreeCreateBy_VLR_LVR(char *vlr, char *lvr, int n)
{
	if (n == 0)
		return NULL;
	int k = 0;
	while (lvr[k] != vlr[0])
		k++;
	BinTreeNode *t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
	t->data = lvr[k];
	t->leftChild = _BinTreeCreateBy_VLR_LVR(vlr + 1, lvr, k);
	t->rightChild = _BinTreeCreateBy_VLR_LVR(vlr + k + 1, lvr + k + 1, n - k - 1);
	return t;
}
void BinTreeCreateBy_VLR_LVR(BinTree *t, char *vlr, char *lvr, int n)
{
	t->root = _BinTreeCreateBy_VLR_LVR(vlr, lvr, n);
}
/*
BinTreeNode* _BinTreeCreateBy_VLR_LVR(char*vlr, char*lvr, int n)
{	
	if (n == 0)
		return NULL;
	int k = 0;
	while (lvr[k] != vlr[0])
	{
		k++;
	}
	BinTreeNode *t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
	t->data = lvr[k];
	t->rightChild = _BinTreeCreateBy_VLR_LVR(vlr + k + 1, lvr + k + 1, n - k - 1);
	t->leftChild = _BinTreeCreateBy_VLR_LVR(vlr + 1, lvr, k);
	
	return t;
}
void BinTreeCreateBy_VLR_LVR(BinTree *t, char*vlr, char*lvr, int n)
{
	t->root = _BinTreeCreateBy_VLR_LVR(lvr, vlr, n);
}









































/*
typedef BinTreeNode* BinTree;
void BinTreeInit(BinTree *t);
void BinTreeCreat_1(BinTree *t);
//BinTreeNode* BinTreeCreat_2();



void BinTreeInit(BinTree *t)
{
	*t = NULL;
}

void BinTreeCreat_1(BinTree *t)
{
	DataType item;
	scanf("%c", &item);
	if (item == '#')
	{
		(*t) = NULL;
	}
	else
	{
		*t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(*t != NULL);
		(*t)->date = item;
		BinTreeCreat_1(&((*t)->leftChild));
		BinTreeCreat_1(&((*t)->rightChild));
	
	}

}

//BinTreeNode* BinTreeCreat_2()
//{
//	DataType item;
//	scanf_s("%c", &item);
//	if (item == '#')
//	{
//		return NULL;
//	}
//	else
//	{
//		BinTreeNode *t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
//		assert(t != NULL);
//		t->date = item;
//		t->leftChild = BinTreeCreat_2();
//		t->rightChild = BinTreeCreat_2();
//		return t;
//	}
//
*/
#endif /*_BINTREE_H_*/