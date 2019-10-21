#define _CRT_SECURE_NO_WARNINGS 1


//#include"slist.h"
#include"seqlist.h"
//#include"dlist.h"
//#include"dclist.h"
//#include"stack.h"
#include"queue.h"
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
	return 0;

}



int main()

{

SeqCyQueue CQ;
SeqQueueCyInit(&CQ, 8);
SeqQueueCyEn(&CQ, 1);
SeqQueueCyEn(&CQ, 2);
SeqQueueCyEn(&CQ, 3);
SeqQueueCyEn(&CQ, 4);
SeqQueueCyEn(&CQ, 5);



SeqQueueCyShow(&CQ);
SeqQueueCyDe(&CQ);
SeqQueueCyDe(&CQ);
SeqQueueCyShow(&CQ);

SeqQueueCyEn(&CQ, 6);
SeqQueueCyEn(&CQ, 7);
SeqQueueCyEn(&CQ, 8);
SeqQueueCyEn(&CQ, 9);

SeqQueueCyShow(&CQ);

SeqQueueCyEn(&CQ, 19);
return 0;
}
*/

int main()
{
SeqQueue Q;//
SeqQueueInit(&Q, DEFAULT_QUEUE_SIZE);
SeqQueueEn(&Q, 1); //
SeqQueueEn(&Q, 2);
SeqQueueEn(&Q, 3);
SeqQueueEn(&Q, 4);
SeqQueueEn(&Q, 5);
SeqQueueShow(&Q);

SeqQueueDe(&Q);
SeqQueueDe(&Q);

SeqQueueShow(&Q);
SeqQueueEn(&Q, 6);
SeqQueueEn(&Q, 7);
SeqQueueEn(&Q, 8);
SeqQueueEn(&Q, 9);

SeqQueueDestroy(&Q);

return 0;
}
/*
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
/*
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

/*int main()
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
			/*SeqListModifyPos(&mylist, item);*/
//
//			printf("请输入要修改的位置:>\n");
//			printf("请输入要修改的值:>\n");
//			scanf("%d%d", &pos, &item);
//			//SeqListModifyPos(&mylist, pos, item);
//			break;
//		case 17:
//			printf("请输入要改的值:>\n");
//			printf("请输入改后的值;>\n");
//			scanf("%d %d", &item, &x);
//			//SeqListModifyVal(&mylist, item, x);
//			break;
//		case 18:
//			//SListDestroy(&mylist);
//			DCListDestroy(&mylist);
//			break;
//		default:
//			printf("输入错误，请重新输入....\n");
//			break;
//		}
//		system("pause");
//	}
//	
//	return 0;
//}*/