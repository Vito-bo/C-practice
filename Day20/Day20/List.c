
#include "LIST.h"

// ��ʼ��������
void InitList(pList plist)
{
	assert(plist != NULL);
	plist->data = -1;
	plist->next = NULL;
}

// ��ȡһ�����
static Node* GetNode(int val)
{
	Node* pGet = (Node*)malloc(sizeof(Node));
	assert(pGet != NULL); 
	pGet->data = val;
	pGet->next = NULL;
	return pGet;
}

// ͷ��  plist����ͷ���ĵ�ַ
void InsertHead(pList plist, int val)
{
	Node* pGet = GetNode(val);
	assert(plist != NULL);
	pGet->next = plist->next;
	plist->next = pGet;
}

// β��
void InsertTail(pList plist, int val)
{
	Node* pGet = GetNode(val);
	assert(plist != NULL);
	Node* p = plist;
	//��β
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = pGet;
}

// ��ӡ
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

// ������k�����
Node* LastKNode(pList plist, int k)
{
	assert(plist!= NULL);
	Node* p = plist;
	Node* q = plist;
	if (k < 0)
	{
		return NULL;
	}
	//1.��һ��ָ������K-1��
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
	//2.����ָ��ͬʱ��
	while (q->next != NULL)
	{
		p = p->next;
		q = q->next;
	}
	return p;
}


