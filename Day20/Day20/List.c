
#include "LIST.h"

// 初始化单链表
void InitList(pList plist)
{
	assert(plist != NULL);
	plist->data = -1;
	plist->next = NULL;
}

// 获取一个结点
static Node* GetNode(int val)
{
	Node* pGet = (Node*)malloc(sizeof(Node));
	assert(pGet != NULL); 
	pGet->data = val;
	pGet->next = NULL;
	return pGet;
}

// 头插  plist代表头结点的地址
void InsertHead(pList plist, int val)
{
	Node* pGet = GetNode(val);
	assert(plist != NULL);
	pGet->next = plist->next;
	plist->next = pGet;
}

// 尾插
void InsertTail(pList plist, int val)
{
	Node* pGet = GetNode(val);
	assert(plist != NULL);
	Node* p = plist;
	//找尾
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = pGet;
}

// 打印
void ShowList(pList plist)
{
	Node* p = NULL;
	assert(plist != NULL);
	p = plist->next;
	while (p != NULL)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	printf("NULL");
	printf("\n");
}

// 倒数第k个结点
Node* LastKNode(pList plist, int k)
{
	assert(plist!= NULL);
	Node* p = plist;
	Node* q = plist;
	if (k < 0)
	{
		return NULL;
	}
	//1.让一个指针先走K-1步
	while ((k - 1)>0)
	{
		if (q->next != NULL)
		{
			q = q->next;
			--k;
		}
		else
		{
			return NULL;
		}
	}
	//2.两个指针同时走
	while (q->next != NULL)
	{
		p = p->next;
		q = q->next;
	}
	return p;
}


