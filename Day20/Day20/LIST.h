
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Node
{
	int data;
	struct Node* next;
}Node,*pList;

// 初始化单链表
void InitList(pList plist);

// 获取一个结点
Node* GetNode(int val);

// 头插
void InsertHead(int val);

// 尾插
void InsertTail(int val);

// 删除

// 倒数第k个结点
Node* LastKNode(pList plist,int k);

// 打印
void ShowList(pList plist);

