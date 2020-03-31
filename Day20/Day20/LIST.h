
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Node
{
	int data;
	struct Node* next;
}Node,*pList;

// ��ʼ��������
void InitList(pList plist);

// ��ȡһ�����
Node* GetNode(int val);

// ͷ��
void InsertHead(int val);

// β��
void InsertTail(int val);

// ɾ��

// ������k�����
Node* LastKNode(pList plist,int k);

// ��ӡ
void ShowList(pList plist);

