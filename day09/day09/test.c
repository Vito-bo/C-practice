

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

//��ͷ+����+��ѭ���������ɾ���ʵ��
typedef int SLTDateType;
typedef struct SListNode
{
	SLTDateType data;
	struct SListNode* next;
}SListNode;

//��̬����һ���ڵ�
SListNode* BuySListNode(SLTDateType x)
{
	SListNode* node = (SListNode*)malloc(sizeof(SListNode));
	node->data = x;
	node->next = NULL;
	return node;
}

//�������ӡ
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

//������β��
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

//�������βɾ
void SListNodePopBack(SListNode** pp)
{
	//��������ָ�룬ͬʱ��������������ҵ���β
	SListNode* prev = NULL;
	SListNode* tail = *pp;
	//1.����Ϊ��2.����ֻ��һ�����
	if (tail == NULL || tail->next == NULL)
	{
		free(tail);
		*pp = NULL;
	}
	//���������Ͻڵ�
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

//�������ͷ��
void SListNodePushFront(SListNode** pp, SLTDateType x)
{
	assert(pp);
	SListNode* newnode = BuySListNode(x);
	//1.�ǿգ�2.��
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

//�������ͷɾ
void SListNodePopFront(SListNode** pp)
{
	//1.��
	//2.һ���ڵ�
	//3.���������Ͻڵ�
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

//���������(�ҵ����ظýڵ�ĵ�ַ��û�ҵ�����NULL)
SListNode* SListFind(SListNode* p, SLTDateType x)
{
	assert(p);
	//1.��
	//2.һ���ڵ�
	//3.����������
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

//��������posλ��֮�����x
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	//��x������
	SListNode* node = BuySListNode(x);
	node->next = pos->next;
	pos->next = node;
}

//������ɾ��posλ��֮���ֵ
void SListEraseAfter(SListNode* pos)
{
	SListNode* next = pos->next;
	pos->next = next->next;
	free(next);
}
