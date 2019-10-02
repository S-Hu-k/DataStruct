#define _CRT_SECURE_NO_WARNINGS 1


//#include"slist.h"
#include"seqlist.h"
int main()
{
	SeqList mylist;
	SeqListInit(&mylist, SEQLIST_DEFAULT_SIZE);
	int select = 1;
	int pos = 0;
	DataType item;

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
				SeqListPushBack(&mylist, select);
			}
			break;
		case 2:
			printf("请输入要插入的数据<-1结束>:>");
			while (scanf("%d", &item), item != -1)
			{
				SeqListPushFront(&mylist, item);
			}
			break;
		case 3:
			SeqListShow(&mylist);
			break;
			/*case 4:
			SeqListPopBack();
			break;
			case 5:
			SeqListPopFront();
			break;*/
			/*case 6:
			printf("请输入要插入的数据<-1结束>:>");
			while (scanf("%d", &item), item != -1)
			{
			SeqListInsertPos(&mylist, item);
			}
			break;*/
		case 12:
			//排序
			printf("%d\n", SeqListsort(&mylist));
			break;
		case 13:
			// 逆转
			printf("%d\n", SeqListreverse(&mylist));
			break;
		case 14:
			printf("SeqList Length=%d\n", SeqListLength(&mylist));
			break;
		case 15:
			SeqListClear(&mylist, item);
			break;
		case 16:
			/*SeqListModifyPos(&mylist, item);*/

			printf("请输入要修改的位置:>\n");
			printf("请输入要修改的值:>\n");
			scanf("%d%d", &pos, &item);
			SeqListModifyPos(&mylist, pos, item);
			break;
		default:
			printf("输入错误，请重新输入....\n");
			break;
		}
		system("pause");
	}

	return 0;
}