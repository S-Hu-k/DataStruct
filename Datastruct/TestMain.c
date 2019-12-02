#define _CRT_SECURE_NO_WARNINGS 1

//#include<stdio.h>

//#include"slist.h"
//#include"seqlist.h"
//#include"dlist.h"
//#include"dclist.h"
//#include"stack.h"
//#include"queue.h"
//#include"bintree.h"
//#include"sort.h"
//#include"heap.h"
//#include"bst.h"
//#include"hashtable.h"



/*
//现在有一个用来存放整数的Hash表，Hash表的存储单位称为桶，
//每个桶能放3个整数，当一个桶中要放的元素超过3个时，
//则要将新的元素存放在溢出桶中，每个溢出桶也能放3个元素，
//多个溢出桶使用链表串起来。此Hash表的基桶数目为素数P，
//Hash表的hash函数对P取模。代码定义如下：
*/


#define P 7
#define NULL_DATA -1
struct bucket_node
{
int data[3];
struct bucket_node *next;
};
struct bucket_node hash_table[P];



//现在假设hash_table已经初始化好了，
//insert_new_element()函数目的是把一个新的值插入hash_table中，
//元素插入成功时，函数返回0，否则返回-1，完成函数。

int Hash(int key)
{
	return key%P;
}
void Init_bucket_node()
{
	for (int i = 0; i < P; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			hash_table[i].data[j] = NULL_DATA;
		}
		hash_table[i].next =0;
	}
}
int insert_new_element(int new_element)
{
	int index = Hash(new_element);
	for (int i = 0; i < 3; ++i)
	{
		if (hash_table[index].data[i] == NULL_DATA)
		{
			hash_table[index].data[i] = new_element;
			return 0;
		}
	}
	struct bucket_node *p = &hash_table[index];
	while(p->next != NULL_DATA)
	{
		p = p->next;
		for (int i = 0; i < 3; ++i)
		{
			if (p->data[i] == NULL_DATA)
			{
				p->data[i] = new_element;
				return 0;
			}
		}
		
	}
	struct bucket_node *s = (struct bucket_node*)malloc(sizeof(struct bucket_node));
	for (int i = 0; i < 3; ++i)
	{
		s->data[i] = NULL_DATA;
	}
	s->next = NULL_DATA;
	s->data[0] = new_element;
	p->next = s;

	return 0;
}
/////////////////////////////
int main()
{
	Init_bucket_node();
	int array[] = { 15, 14, 21, 87, 96, 293, 35, 24, 149, 19, 63, 16, 103, 77, 5, 153, 145, 356, 51, 68, 705, 453 };
	for (int i = 0; i < sizeof(array) / sizeof(int); i++)
	{
		insert_new_element(array[i]);
	}
	return 0;

}










/*
int main()
{
	int ar[] = { 49, 38, 65, 97, 76, 13, 27 };
	int n = sizeof(ar) / sizeof(int);

	HashTable ht;
	HashTableInit(ht);

	for (int i = 0; i < n; ++i)
	{
		HashTableInsert(ht, ar[i]);
	}
	HashTableShow(ht);
	printf("====================================\n");
	HashTableRemove(ht, 65);
	HashTableShow(ht);

}

void main()
{
   // int ar[] = { 49, 38, 65, 97, 76, 13, 27, 49 };
	//int ar[] = { 9,1,2,5,7,4,8,6,3,5};
	int ar[] = { 278, 109, 63, 930, 589, 184, 505, 269, 8, 83 };
	int n = sizeof(ar) / sizeof(int);
	PrintArray(ar, 0, n - 1);
	RadixSort(ar, 0, n - 1);
	PrintArray(ar, 0, n - 1);
	//TestSortEfficiency();
	//printf("\n");
	//InsertSort_1(ar1, 0, n - 1);
	//TestSortEfficiency();
	
}

int main()
{
	BSTree bst;

	int j = 0;
	int ar[] = { 45, 10,24, 53, 12, 38,30,21, 90 };

	int n = sizeof(ar) / sizeof(int);
	BSTreeInit(&bst);
	for (int i = 0; i < n; ++i)
	{
		Insert(&bst, ar[i]);
	}
		printf("min=%d ", MIN(bst));
		printf("max=%d ", MAX(bst));

	Sort(&bst, ar,&j);
	return 0;
}

void main()
{
	int ar[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	int n = sizeof(ar) / sizeof(int);
	Heap hp;
	int i;
	HeapInit(&hp, n);

	for (i = 0; i<n; ++i)
	{
		HeapInsert(&hp, ar[i]);
	}
	HeapShow(&hp);

	HeapRemove(&hp);
	HeapShow(&hp);

	HeapRemove(&hp);
	HeapShow(&hp);

	HeapDestroy(&hp);
}


int main()
{
	int ar[]= { 5, 6, 2, 3, 4,3 , 8, 9, 7, 5, 1 };

	return 0;
}

int main()
{
	char *str = "ABC##DE##F##G#H##";
	char *str1 = "ABC##D#F##GE##H##";
	char *vlr = "ABCDEFGH";
	char *lvr = "CBEDFAGH";
	char *lrv = "CEFDBHGA";
	int n = strlen(lvr);
	int i = 0, j = 0;
	
	BinTree bt, bt1;
	BinTreeInit(&bt);
	BinTreeInit(&bt1);
	BinTreeCreate(&bt);
	BinTreeCreateByStr(&bt, str, &i);
	BinTreeCreateByStr(&bt1, str1, &j);
	BinTreeCreateBy_VLR_LVR(&bt, vlr, lvr, n);
	BinTreeCreateBy_LVR_LRV(&bt, lvr, lrv, n);

	printf("VLR   :");
	PreOrder(&bt);
	printf("\n");
	printf("VLR NR:");
	PreOrderNoR(&bt);
	printf("\n");
	printf("\n");

	printf("LVR   :");
	InOrder(&bt);
	printf("\n");
	printf("LVR NR:");
	InOrderNoR(&bt);
	printf("\n");
	printf("\n");

	printf("LRV   :");
	PostOrder(&bt);
	printf("\n");
	printf("LRV NR:");
	PostOrderNoR(&bt);
	printf("\n");
	printf("\n");

	
	printf("Level:");
	LevelOrder(&bt);
	printf("\n");
	printf("Size = %d\n", Size(&bt));
	printf("Hegith = %d\n", Height(&bt));
	BinTreeNode *p = Find(&bt, 'B');
	p = Parent(&bt, 'H');


	Clone(&bt, &bt1);
	bool flag = Equal(&bt, &bt1);
	return 0;
}


int main()
{
	//char *str = "ABC##DE##F##G#H##";
	//char *str1 = "ABC##D#F##GE##H##";
	char *vlr = "ABCDEFGH";
	char *lvr = "CBEDFAGH";

	//char *vlr = "ABCDEFGH";
	//char *lvr = "CBEDFAGH";
	int n = strlen(lvr);
	int i = 0,j=0;
	BinTree bt;
	BinTree bt1;

	BinTreeInit(&bt);
	BinTreeInit(&bt1);

    //BinTreeCreate(&bt);
    //BinTreeCreateByStr( &bt, str, &i);
    //BinTreeCreateByStr(&bt1, str, &j);

	printf("_VLR_LVR:");
	BinTreeCreateBy_VLR_LVR(&bt, vlr, lvr, n);
	printf("\n");
	

	printf("VLR:");
	PreOrder(&bt);
	printf("\n");
	printf("LVR:");
	InOrder(&bt);
	printf("\n");
	printf("LRV:");
	PostOrder(&bt);
	printf("\n");
	printf("Level:");
	PostOrder(&bt);
	printf("\n");


	printf("Size=%d \n", Size(&bt));
	printf("Height=%d\n", Height(&bt));
	BinTreeNode *p = Find(&bt, 'B');
	p = Parent(&bt, 'C');


	Clone(&bt,&bt1);

	bool flag = Equal(&bt, &bt1);
	return 0;
}
*/











/*
int main()
{
	LinkQueue LQ;
	LinkQueueInit(&LQ);
	LinkQueueEn(&LQ, 1);
	LinkQueueEn(&LQ, 2);
	LinkQueueEn(&LQ, 3);
	LinkQueueEn(&LQ, 4);
	LinkQueueEn(&LQ, 5);
	LinkQueueShow(&LQ);

	LinkQueueDestroy(&LQ);
	LinkQueueShow(&LQ);

	return 0;
}

int main()
{
	LinkQueue LQ;
	LinkQueueInit(&LQ);
	LinkQueueEn(&LQ, 1);
	LinkQueueEn(&LQ, 2);
	LinkQueueEn(&LQ, 3);
	LinkQueueEn(&LQ, 4);
	LinkQueueEn(&LQ, 5);

	LinkQueueShow(&LQ);

	LinkQueueDestroy(&LQ);
	return 0;

}




int main()
{
SeqCyQueue CQ;
SeqCyQueueInit(&CQ, 8);
SeqCyQueueEn(&CQ, 1);
SeqCyQueueEn(&CQ, 2);
SeqCyQueueEn(&CQ, 3);
SeqCyQueueEn(&CQ, 4);
SeqCyQueueEn(&CQ, 5);
SeqCyQueueShow(&CQ);
SeqCyQueueDe(&CQ);
SeqCyQueueDe(&CQ);

SeqCyQueueShow(&CQ);

SeqCyQueueEn(&CQ, 6);
SeqCyQueueEn(&CQ, 7);
SeqCyQueueEn(&CQ, 8);
SeqCyQueueEn(&CQ, 9);
SeqCyQueueShow(&CQ);

SeqCyQueueEn(&CQ, 19);
SeqCyQueueShow(&CQ);

//SeqCyQueueInit(&CQ, 8);
//SeqCyQueueEn(&CQ, 1);
//SeqCyQueueEn(&CQ, 2);
//SeqCyQueueEn(&CQ, 3);
//SeqCyQueueEn(&CQ, 4);
//SeqCyQueueEn(&CQ, 5);
//
//
//
//SeqCyQueueShow(&CQ);
//SeqCyQueueDe(&CQ);
//SeqCyQueueDe(&CQ);
//SeqCyQueueShow(&CQ);
//SeqCyQueueEn(&CQ, 6);
//SeqCyQueueEn(&CQ, 7);
//SeqCyQueueEn(&CQ, 8);
//SeqCyQueueEn(&CQ, 9);
//
//SeqCyQueueShow(&CQ);
//
//SeqCyQueueEn(&CQ, 19);
return 0;
}


int main()
{
SeqQueue Q;//
SeqQueueInit(&Q, DEFAULT_QUEUE_SIZE);
SeqQueueEn(&Q, 1); 
SeqQueueEn(&Q, 2);
SeqQueueEn(&Q, 3);
SeqQueueEn(&Q, 5);
SeqQueueEn(&Q, 6);

SeqQueueEn(&Q, 4);
SeqQueueShow(&Q);

SeqQueueDe(&Q);
SeqQueueDe(&Q);

SeqQueueShow(&Q);
SeqQueueEn(&Q, 6);
SeqQueueEn(&Q, 7);
SeqQueueEn(&Q, 8);
SeqQueueEn(&Q, 9);

//SeqQueueDestroy(&Q);


return 0;
}

int main()
{
	ListStack st;
	ListStackInit(&st);
	ListStackPush(&st, 1);
	ListStackPush(&st, 2);
	ListStackPush(&st, 3);
	ListStackPush(&st, 4);
	ListStackPush(&st, 5);

	ListStackShow(st);
	return 0;
}

int main()
{
	SeqStack st;
	SeqStackInit(&st, STACK_DEFAULT_SIZE);
	//SeqStack *pst=SeqStackInit_1(STACK_DEFAULT_SIZE);
	SeqStackPushBack(&st, 1);
	SeqStackPushBack(&st, 2);
	SeqStackPushBack(&st, 3);
	SeqStackPushBack(&st, 4);
	SeqStackPushBack(&st, 5);
	SeqStackPushBack(&st, 6);
	SeqStackPushBack(&st, 7);
	SeqStackPushBack(&st, 8);
	SeqStackPushBack(&st, 10);

	int val = SeqStackTop(&st);

	SeqStackPop(&st);
	SeqStackPushBack(&st, 9);

	SeqStackShow(&st);
	return 0;
}

int main()
{
	//SeqList mylist;
	//SeqListInit(&mylist, SEQLIST_DEFAULT_SIZE);

	//DList mylist;
	//DListInit(&mylist, DLIST_DEFAULT_SIZE);


	//SList mylist;
	//SListInit(&mylist);


	//DList mylist;
	//DListInit(&mylist);
	DCList mylist;
	DCListInit(&mylist);

	//SListNode *p;
	//DListNode *p;
	DCListNode *p;

	int select = 1;
	int pos = 0;
	DataType item;
	DataType x;
	//DataType n;
	//DataType x;
	//int select = 1;
	////SList mylist;
	//SListPushBack(&mylist, x);
	//return 0;
	while (select)
	{
		printf("*************************************\n");
		printf("**** 1.push_back    2.push_front ****\n");
		printf("**** 3.show_list    0.quit_system****\n");
		printf("**** 4.pop_back     5.pop_front  ****\n");
		printf("**** 6.insert_pos   7.insert_val ****\n");
		printf("**** 8.delete_pos   9.delete_val ****\n");
		printf("**** 10.find_pos    11.find_val  ****\n");
		printf("**** 12.sort        13.reverse   ****\n");
		printf("**** 14.length      15.clear     ****\n");
		printf("**** 16.modify_pos  17.modify_val****\n");
		printf("**** 18.destroy                  ****\n");
		printf("*************************************\n");
		printf("请选择:>");
		scanf("%d", &select);
		if (select == 0)
		{
			break;
		}
		switch (select)
		{
		case 1:
			printf("请输入要插入的数据<-1结束>:>");
			while (scanf("%d", &select), select != -1)
			{
				//SeqListPushBack(&mylist, select);
				//SListPushBack(&mylist, select);
			    // DListPushBack(&mylist, select);
				DCListPushBack(&mylist, select);
			}
			break;
		case 2:
			printf("请输入要插入的数据<-1结束>:>");
			while (scanf("%d", &item), item != -1)
			{
				//SeqListPushFront(&mylist, item);
				//SListPushFront(&mylist, item);
				//DListPushFront(&mylist, item);
				DCListPushFront(&mylist, item);
			}
			break;
		case 3:
			//SeqListShow(&mylist);
			//SListShow(&mylist);
			//DListShow(&mylist);
			DCListShow(&mylist);
			break;
			case 4:
				//SListPopBack(&mylist);
				//DListPopBack(&mylist);
			break;
			case 5:
		         //	SeqListPopFront();
				//SListPopFront(&mylist);
				//DListPopFront(&mylist);
			break;
		case 6:
			//printf("请输入要插入的数据<-1结束>:>");
			//if (scanf("%d%d", &item, &n), item != -1)
			//{

			//	//SeqListInsertPos(&mylist, item, n);
			//	//SListInsertPos(&mylist, item, n);
			//}
			printf("请输入要插入的位置;>");
				scanf("%d", &pos);
				printf("请输入要插入的数据;>");
				scanf("%d", &item);
				//SListInsertPos(&mylist, pos,item);
			break;
		case 7:
			//printf("请输入要插入的数据<-1结束>:>");
			//if (scanf("%d%d", &item, &n), item != -1)
			//{

			//	//SeqListInsertVal(&mylist, item, n);

			//}
			printf("请输入要插入的值;>");
			scanf("%d", &item);
		//	SListInsertVal(&mylist, item);
			break;
		case 8:
			printf("请输入要删除的位置；>");
			scanf("%d", &pos);
			//SeqListDeletePos(&mylist, pos);
			//SListDeletePos(&mylist, pos);
			break;
		case 9:
			printf("请输入要删除的值:>");
			scanf("%d", &x);
			//SeqListDeleteVal(&mylist, x);
			//SListDeleteVal(&mylist, x);
			//DListDeleteVal(&mylist, x);

			break;
		case 10:
			printf("请输入你要找的位置:>");
			scanf("%d", &pos);
			//SeqListFindPos(&mylist, pos);
			//DListFindPos(&mylist, pos);
			break;
		case 11:
			printf("请输入你要找的值:>");
			scanf("%d", &x);
			//SeqListFindVal(&mylist,x );
			//DListFindVal(&mylist, x);
			DCListFindVal(&mylist, x);
			break;
		case 12:
			//排序
			//printf("%d\n", SeqListsort(&mylist));
		//SListSort(&mylist);
			//DListSort(&mylist);
			break;
		case 13:
			// 逆转
			//printf("%d\n", SeqListreverse(&mylist));
			//SListreverse(&mylist);
			//DListreverse(&mylist);
			break;
		case 14:
			//printf("SeqList Length=%d\n", SeqListLength(&mylist));
			//printf("SList Length=%d\n", SListLength(&mylist));
			//printf("DList Length=%d\n", DListLength(&mylist));
			printf("DCList Length=%d\n", DCListLength(&mylist));
			break;
		case 15:
			//SeqListClear(&mylist, item);
			//SListClear(&mylist);
			//DListClear(&mylist);
			DCListClear(&mylist);
			break;
		case 16:
			/*SeqListModifyPos(&mylist, item);

			printf("请输入要修改的位置:>\n");
		printf("请输入要修改的值:>\n");
		scanf("%d%d", &pos, &item);
			//SeqListModifyPos(&mylist, pos, item);
		break;
	case 17:
		printf("请输入要改的值:>\n");
		printf("请输入改后的值;>\n");
		scanf("%d %d", &item, &x);
		//SeqListModifyVal(&mylist, item, x);
		break;
	case 18:
			//SListDestroy(&mylist);
			DCListDestroy(&mylist);
			break;
	default:
			printf("输入错误，请重新输入....\n");
			break;
		}
		system("pause");
	}
	
	return 0;
}

*/