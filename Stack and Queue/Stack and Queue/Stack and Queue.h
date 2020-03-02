
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#if 0
// ֧�ֶ�̬������ջ
typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top; // ջ��
	int _capacity; // ����
}Stack;

// ��ʼ��ջ
void StackInit(Stack* ps)
{
	assert(ps);
	ps->_a = NULL;
	ps->_top = ps->_capacity = 0;
}

// ��ջ
void StackPush(Stack* ps, STDataType data)
{
	assert(ps);
	if (ps->_top == ps->_capacity)
	{
		int newcapacity = ps->_capacity == 0 ? 4 : ps->_capacity * 2;
		ps->_a = (STDataType*)realloc(ps->_a, newcapacity*sizeof(STDataType));
		ps->_capacity = newcapacity;
	}
	ps->_a[ps->_top] = data;
	ps->_top++;
}

// ��ջ
void StackPop(Stack* ps)
{
	assert(ps && ps->_top > 0);
	--ps->_top;
}

// ��ȡջ��Ԫ��
STDataType StackTop(Stack* ps)
{
	assert(ps);
	return ps->_a[ps->_top - 1];
}

// ��ȡջ����ЧԪ�ظ���
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->_top;
}

// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0
int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->_top == 0 ? 1 : 0;
}

// ����ջ
void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->_a);
	ps->_top = ps->_capacity = 0;
}
#endif



// ��ʽ�ṹ����ʾ����
typedef int QDataType;
typedef struct QListNode
{
	QDataType _data;          //������
	struct QListNode* _pNext; //ָ����
}QNode;

// ���еĽṹ
typedef struct Queue
{
	QNode* _front;  //ͷָ��
	QNode* _rear;   //βָ��
}Queue;

// ��ʼ������
void QueueInit(Queue* q)
{
	assert(q);
	q->_front = q->_rear = NULL;
}

// ��β�����
void QueuePush(Queue* q, QDataType data)
{
	assert(q);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	newnode->_data = data;
	newnode->_pNext = NULL;
	if (q->_rear == NULL)
	{
		q->_front = q->_rear = newnode;
	}
	else
	{
		q->_rear->_pNext = newnode;
		q->_rear = newnode;
	}
}

// ��ͷ������
void QueuePop(Queue* q)
{
	assert(q);
	QNode* next = q->_front->_pNext;
	free(q->_front);
	q->_front = next;

	//�������һ����㱻���������
	if (q->_front == NULL)
	{
		q->_rear = NULL;
	}
}

// ��ȡ����ͷ��Ԫ��
QDataType QueueFront(Queue* q)
{
	assert(q);
	return q->_front->_data;
}

// ��ȡ���ж�βԪ��
QDataType QueueBack(Queue* q)
{
	assert(q);
	return q->_rear->_data;
}

// ��ȡ��������ЧԪ�ظ���
int QueueSize(Queue* q)
{
	assert(q);
	int count = 0;
	QNode* cur = q->_front;
	while (cur != NULL)
	{
		++count;
		cur = cur->_pNext;
	}
	return count;
}

// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0
int QueueEmpty(Queue* q)
{
	assert(q);
	return q->_front == NULL ? 1 : 0;
}

// ���ٶ���
void QueueDestroy(Queue* q)
{
	assert(q);
	QNode* cur = q->_front;
	while (cur != NULL)
	{
		QNode* next = cur->_pNext;
		free(cur);
		cur = next;
	}
	q->_front = q->_rear = NULL;
}