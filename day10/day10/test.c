
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

//��ͷ+˫��+ѭ��������ɾ���ʵ��
typedef int LTDataType;
typedef struct ListNode
{
	LTDataType _data;
	struct ListNode* next;
	struct ListNode* prev;
}ListNode;

//����һ���½ڵ�
ListNode* BuyListNode(LTDataType x)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->_data = x;
	node->next = NULL;
	node->prev = NULL;
	return node;
}

//�������������ͷ�ڵ�
ListNode* ListCreate()
{
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	head->next = head;
	head->prev = head;
	return head;
}

//˫����������
//����һ��ָ���һ���ڵ��ָ��(��һ���ڵ㲻��ͷ�ڵ�)
//ѭ�������������ͷţ�����ָ��ָ����һ��Ҫ�ͷŵ�λ��
//ѭ��������ͷ�ڵ���Ҫ�����ͷţ�����ͷָ���ÿ�
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

//˫�������ӡ
void ListPrint(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead->next;

}

