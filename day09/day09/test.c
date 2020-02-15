

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

//无头+单向+非循环链表的增删查改实现
typedef int SLTDateType;
typedef struct SListNode
{
	SLTDateType data;
	struct SListNode* next;
}SListNode;

//动态申请一个节点
SListNode* BuySListNode(SLTDateType x)
{
	SListNode* node = (SListNode*)malloc(sizeof(SListNode));
	node->data = x;
	node->next = NULL;
	return node;
}

//单链表打印
void SListNodePrint(SListNode* p)
{
	SListNode* cur = p;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

//单链表尾插
void SListNodePushBack(SListNode** pp, SLTDateType x)
{
	SListNode* newnode = BuySListNode(x);
	if (*pp == NULL)
	{
		*pp = newnode;
	}
	else
	{
		SListNode* tail = *pp;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}

//单链表的尾删
void SListNodePopBack(SListNode** pp)
{
	//定义两个指针，同时往后遍历单链表找到表尾
	SListNode* prev = NULL;
	SListNode* tail = *pp;
	//1.链表为空2.链表只有一个结点
	if (tail == NULL || tail->next == NULL)
	{
		free(tail);
		*pp = NULL;
	}
	//两个及以上节点
	else
	{
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		tail = NULL;
		prev->next = NULL;
	}
}

//单链表的头插
void SListNodePushFront(SListNode** pp, SLTDateType x)
{
	assert(pp);
	SListNode* newnode = BuySListNode(x);
	//1.非空，2.空
	if (*pp == NULL)
	{
		*pp = newnode;
	}
	else
	{
		newnode->next = *pp;
		*pp = newnode;
	}
}

//单链表的头删
void SListNodePopFront(SListNode** pp)
{
	//1.空
	//2.一个节点
	//3.两个及以上节点
	SListNode* first = *pp;
	if (first == NULL)
	{
		return;
	}
	else if (first->next == NULL)
	{
		free(first);
		*pp = NULL;
	}
	else
	{
		SListNode* next = first->next;
		free(first);
		*pp = next;
	}
}

//单链表查找(找到返回该节点的地址，没找到返回NULL)
SListNode* SListFind(SListNode* p, SLTDateType x)
{
	assert(p);
	//1.空
	//2.一个节点
	//3.两个及以上
	while (p != NULL)
	{
		if (p->data == x)
		{
			return p;
		}
		p = p->next;
	}
	return NULL;
}

//单链表在pos位置之后插入x
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	//给x申请结点
	SListNode* node = BuySListNode(x);
	node->next = pos->next;
	pos->next = node;
}

//单链表删除pos位置之后的值
void SListEraseAfter(SListNode* pos)
{
	SListNode* next = pos->next;
	pos->next = next->next;
	free(next);
}
