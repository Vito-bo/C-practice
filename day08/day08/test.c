
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>


//静态顺序表
//使用定长数组存储

#define N 100
typedef int SLDataType;

typedef struct SeqList
{
	SLDataType arr[N];//定长数组
	size_t size;      //有效数据的个数
}SeqList1;

//顺序表的动态存储
typedef struct SeqList
{
	SLDataType* arr; //指向动态开辟的数组
	size_t size;     //有效数据个数
	size_t capacity; //容量空间的大小
}SeqList;

//动态顺序表的基本增删查改
//顺序表初始化
void SeqListInit(SeqList* p, size_t capacity)
{
	assert(p);
	p->arr = NULL;
	//初始化时有效个数为0
	p->size = 0;
	p->capacity = 0;
}

//销毁顺序表
void SeqListDestory(SeqList* p)
{
	assert(p);
	free(p->arr);
	//free掉这段空间之后arr就变成了一个野指针，因此最好将该指针指向空
	p->arr = NULL;
	p->size = p->capacity = 0;
}

//打印数据
void SeqListPrint(SeqList* p)
{
	assert(p);
	for (size_t i = 0; i < p->size; ++i)
	{
		printf("%d->", p->arr[i]);
	}
	printf("NULL\n");
}

//检查空间是否够用
void SeqListCheckCapacity(SeqList* p)
{
	assert(p);
	//当空间不足时就将空间扩充到原来的2倍
	if (p->size >= p->capacity)
	{
		size_t newcapacity = p->capacity == 0 ? 4 : p->capacity * 2;
		p->arr = realloc(p->arr, newcapacity*sizeof(SLDataType));
		//将新的空间给arr
		p->capacity = newcapacity;
	}
}

//尾插
void SeqListPushBack(SeqList* p,SLDataType x)
{
	assert(p);
	SeqListCheckCapacity(p);
	//将数据插入表尾
	p->arr[p->size] = x;
	p->size++;
}

//尾删
void SeqListPopBack(SeqList* p)
{
	assert(p && p->size > 0);
	p->size--;
}

//头插
void SeqListPushFront(SeqList* p, SLDataType x)
{
	assert(p);
	//先考虑空间不足问题
	SeqListCheckCapacity(p);
	//移动数据
	int end = p->size - 1;
	for (; end >= 0; end--)
	{
		//将当前数据依次后移
		p->arr[end + 1] = p->arr[end];
	}
	p->arr[0] = x;
	p->size++;
}

//头删
void SeqListPopFront(SeqList* p)
{
	assert(p&&p->size > 0);
	for (size_t i = 1; i < p->size; i++)
	{
		p->arr[i - 1] = p->arr[i];
	}
	p->size--;
}

//查找
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

//中间某处插入
void SeqListInsert(SeqList* p, size_t pos, SLDataType x)
{
	assert(p && pos<p->size);
	size_t end = p->size + 1;
	while (end>pos)
	{
		//将指定位置之后的元素依次后移一个单位，留出pos位置
		p->arr[end] = p->arr[end - 1];
		--end;
	}
	p->arr[pos] = x;
	p->size++;
}

//指定位置删除
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

//指定元素删除
void SeqListRemove(SeqList* p, SLDataType x)
{
	assert(p);
	int pos = SeqListFind(p, x);
	if (pos >= 0)
	{
		SeqListErase(p, x);
	}
}

//修改某个位置的值
void SeqListModify(SeqList* p, size_t pos, SLDataType x)
{
	assert(p && (pos > 0 && pos < p->size));
	p->arr[pos - 1] = x;
}

//冒泡排序
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

//二分查找
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