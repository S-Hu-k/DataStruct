////////////////////////反转一个链表
//#include<stdio.h>
//int main()
//{
//	struct ListNode* reverseList(struct ListNode* head){
//
//		if (head == NULL || head->next == NULL)
//			return head;
//		struct ListNode* p = head;
//		head->next = NULL;
//
//		while (p != NULL)
//		{
//			struct ListNode* q = p->next;
//			p->next = head;
//			head = p;
//			p = q;
//		}
//		return head;
//	}
//	return 0;
//}
///////////////////////////////////移除链表元素




//#include<stdio.h>
//int main()
//{
//	struct ListNode* removeElements(struct ListNode* head, int val)
//	{
//		if (head == NULL)
//			return NULL;
//
//
//		struct ListNode *p = head;
//		struct ListNode *prev = NULL;
//
//		while (p != NULL)
//		{
//			if (p->val == val)
//			{
//				if (prev == NULL)
//				{
//					head = head->next;
//					free(p);
//					p = head;
//				}
//				else
//				{
//					prev->next = p->next;
//					free(p);
//					p = prev->next;
//				}
//			}
//			else
//			{
//				prev = p;
//				p = p->next;
//			}
//		}
//		return head;
//	}
//}