
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>


//��̬˳���
//ʹ�ö�������洢

#define N 100
typedef int SLDataType;

typedef struct SeqList
{
	SLDataType arr[N];//��������
	size_t size;      //��Ч���ݵĸ���
}SeqList1;

//˳���Ķ�̬�洢
typedef struct SeqList
{
	SLDataType* arr; //ָ��̬���ٵ�����
	size_t size;     //��Ч���ݸ���
	size_t capacity; //�����ռ�Ĵ�С
}SeqList;

//��̬˳���Ļ�����ɾ���
//˳����ʼ��
void SeqListInit(SeqList* p, size_t capacity)
{
	assert(p);
	p->arr = NULL;
	//��ʼ��ʱ��Ч����Ϊ0
	p->size = 0;
	p->capacity = 0;
}

//����˳���
void SeqListDestory(SeqList* p)
{
	assert(p);
	free(p->arr);
	//free����οռ�֮��arr�ͱ����һ��Ұָ�룬�����ý���ָ��ָ���
	p->arr = NULL;
	p->size = p->capacity = 0;
}

//��ӡ����
void SeqListPrint(SeqList* p)
{
	assert(p);
	for (size_t i = 0; i < p->size; ++i)
	{
		printf("%d->", p->arr[i]);
	}
	printf("NULL\n");
}

//���ռ��Ƿ���
void SeqListCheckCapacity(SeqList* p)
{
	assert(p);
	//���ռ䲻��ʱ�ͽ��ռ����䵽ԭ����2��
	if (p->size >= p->capacity)
	{
		size_t newcapacity = p->capacity == 0 ? 4 : p->capacity * 2;
		p->arr = realloc(p->arr, newcapacity*sizeof(SLDataType));
		//���µĿռ��arr
		p->capacity = newcapacity;
	}
}

//β��
void SeqListPushBack(SeqList* p,SLDataType x)
{
	assert(p);
	SeqListCheckCapacity(p);
	//�����ݲ����β
	p->arr[p->size] = x;
	p->size++;
}

//βɾ
void SeqListPopBack(SeqList* p)
{
	assert(p && p->size > 0);
	p->size--;
}

//ͷ��
void SeqListPushFront(SeqList* p, SLDataType x)
{
	assert(p);
	//�ȿ��ǿռ䲻������
	SeqListCheckCapacity(p);
	//�ƶ�����
	int end = p->size - 1;
	for (; end >= 0; end--)
	{
		//����ǰ�������κ���
		p->arr[end + 1] = p->arr[end];
	}
	p->arr[0] = x;
	p->size++;
}

//ͷɾ
void SeqListPopFront(SeqList* p)
{
	assert(p&&p->size > 0);
	for (size_t i = 1; i < p->size; i++)
	{
		p->arr[i - 1] = p->arr[i];
	}
	p->size--;
}

//����
int SeqListFind(SeqList* p, SLDataType* x)
{
	assert(p);
	for (size_t i = 0; i < p->size; ++i)
	{
		if (x == p->arr[i])
		{
			return i;
		}
	}
	return -1;
}

//�м�ĳ������
void SeqListInsert(SeqList* p, size_t pos, SLDataType x)
{
	assert(p && pos<p->size);
	size_t end = p->size + 1;
	while (end>pos)
	{
		//��ָ��λ��֮���Ԫ�����κ���һ����λ������posλ��
		p->arr[end] = p->arr[end - 1];
		--end;
	}
	p->arr[pos] = x;
	p->size++;
}

//ָ��λ��ɾ��
void SeqListErase(SeqList* p, size_t pos)
{
	assert(p && pos < p->size);
	size_t i = pos + 1;
	while (i < p->size)
	{
		p->arr[i - 1] = p->arr[i];
		++i;
	}
	p->size--;
}

//ָ��Ԫ��ɾ��
void SeqListRemove(SeqList* p, SLDataType x)
{
	assert(p);
	int pos = SeqListFind(p, x);
	if (pos >= 0)
	{
		SeqListErase(p, x);
	}
}

//�޸�ĳ��λ�õ�ֵ
void SeqListModify(SeqList* p, size_t pos, SLDataType x)
{
	assert(p && (pos > 0 && pos < p->size));
	p->arr[pos - 1] = x;
}

//ð������
void SeqListBubbleSort(SeqList* p)
{
	assert(p);
	size_t i = 0;
	size_t j = 0;
	for (i = 0; i < p->size - 1; i++)
	{
		int exchange = 0;
		for (j = 0; j < p->size - i - 1; j++)
		{
			if (p->arr[j]>p->arr[j + 1])
			{
				int tmp = p->arr[j];
				p->arr[j] = p->arr[j + 1];
				p->arr[j + 1] = tmp;
				exchange = 1;
			}
		}
		if (exchange == 0)
		{
			break;
		}
	}
}

//���ֲ���
int SeqListBinaryFind(SeqList* p, SLDataType x)
{
	assert(p);
	int left = 0;
	int right = (int)p->size;
	while (left<right)
	{
		int mid = left + (right - left) / 2;
		if (p->arr[mid] == x)
		{
			return mid;
		}
		else if (p->arr[mid] < x)
		{
			left = mid + 1;
		}
		else
		{
			right = mid;
		}
	}
	return -1;
}