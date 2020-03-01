
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#if 0
// 支持动态增长的栈
typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top; // 栈顶
	int _capacity; // 容量
}Stack;

// 初始化栈
void StackInit(Stack* ps)
{
	assert(ps);
	ps->_a = NULL;
	ps->_top = ps->_capacity = 0;
}

// 入栈
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

// 出栈
void StackPop(Stack* ps)
{
	assert(ps && ps->_top > 0);
	--ps->_top;
}

// 获取栈顶元素
STDataType StackTop(Stack* ps)
{
	assert(ps);
	return ps->_a[ps->_top - 1];
}

// 获取栈中有效元素个数
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->_top;
}

// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0
int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->_top == 0 ? 1 : 0;
}

// 销毁栈
void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->_a);
	ps->_top = ps->_capacity = 0;
}
#endif



// 链式结构：表示队列
typedef int QDataType;
typedef struct QListNode
{
	QDataType _data;          //数据域
	struct QListNode* _pNext; //指针域
}QNode;

// 队列的结构
typedef struct Queue
{
	QNode* _front;  //头指针
	QNode* _rear;   //尾指针
}Queue;

// 初始化队列
void QueueInit(Queue* q)
{
	assert(q);
	q->_front = q->_rear = NULL;
}

// 队尾入队列
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

// 队头出队列
void QueuePop(Queue* q)
{
	assert(q);
	QNode* next = q->_front->_pNext;
	free(q->_front);
	q->_front = next;

	//处理最后一个结点被弹出的情况
	if (q->_front == NULL)
	{
		q->_rear = NULL;
	}
}

// 获取队列头部元素
QDataType QueueFront(Queue* q)
{
	assert(q);
	return q->_front->_data;
}

// 获取队列队尾元素
QDataType QueueBack(Queue* q)
{
	assert(q);
	return q->_rear->_data;
}

// 获取队列中有效元素个数
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

// 检测队列是否为空，如果为空返回非零结果，如果非空返回0
int QueueEmpty(Queue* q)
{
	assert(q);
	return q->_front == NULL ? 1 : 0;
}

// 销毁队列
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