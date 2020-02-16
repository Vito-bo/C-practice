
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

//带头+双向+循环链表增删查改实现
typedef int LTDataType;
typedef struct ListNode
{
	LTDataType _data;
	struct ListNode* next;
	struct ListNode* prev;
}ListNode;

//创建一个新节点
ListNode* BuyListNode(LTDataType x)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->_data = x;
	node->next = NULL;
	node->prev = NULL;
	return node;
}

//创建返回链表的头节点
ListNode* ListCreate()
{
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	head->next = head;
	head->prev = head;
	return head;
}

//双向链表销毁
//定义一个指向第一个节点的指针(第一个节点不是头节点)
//循环遍历，依次释放，并将指针指向下一个要释放的位置
//循环结束后，头节点需要单独释放，并将头指针置空
void ListDestory(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead->next;
	if (phead == NULL)
	{
		return 0;
	}
	while (cur != phead)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = NULL;
		cur = next;
	}
	free(phead);
	phead = NULL;
}

//双向链表打印
void ListPrint(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead->next;

}

