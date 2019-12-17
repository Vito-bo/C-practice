


//ceil函数 向上取整  ceil(2.5)=3 
//floor函数 向下取整 floor(2.5)=2 


//给定一个长度为n的数列，将这个数列按从小到大的顺序排列。1<=n<=200
//输入格式,第一行为一个整数n。
//第二行包含n个整数，为待排序的数，每个整数的绝对值小于10000。
//输出格式,输出一行，按从小到大的顺序输出排序后的数列。

#include <stdio.h>
#include <stdlib.h>
//打印
void Print(int *data, int n)
{
	int i;
	for (i = 0; i<n; i++)
	{
		printf("%d ", data[i]);
	}
	printf("\n");
}

int Split(int *data, int pre, int rear)
{
	int value = data[pre];
	while (pre<rear)
	{
		while (data[rear] >= value && pre<rear) rear--;
		data[pre] = data[rear];
		while (data[pre]<value && pre<rear) pre++;
		data[rear] = data[pre];
	}
	data[pre] = value;
	return pre;
}

//快速排序
void QuickSort(int *data, int pre, int rear)
{
	if (pre<rear)
	{
		int mid = Split(data, pre, rear);
		QuickSort(data, pre, mid - 1);
		QuickSort(data,mid+1,rear);
	}
}

int main()
{
	int i;
	int n;
	int *data;
	scanf("%d",&n);
	data=(int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&data[i]);
	}
	QuickSort(data,0,n-1);
	Print(data,n);
	return 0;
}




#if 0
//2.小明对数位中含有2、0、1、9的数字很感兴趣（不包括前导0），
//在1到40中这样的数包括1、2、9、10至32、39和40，共28个，他们的和是574。
//请问，在 1 到 n 中，所有这样的数的和是多少？
//输入一行包含一个整数 n。输出一行，包含一个整数，显示满足条件的数的和。

int main()
{
	int n, i, sum = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; ++i)
	{
		int t = i, ok = 0;
		while (t > 0)
		{
			int g = t % 10;
			if (g == 2 || g == 0 || g == 1 || g == 9)
			{
				ok = 1;
			}
			t = t / 10;
		}
		if (ok)
		{
			sum += i;
		}
	}
	printf("%d", sum);
	return 0;
}

//1.切割矩阵，每次从矩阵契切下最大正方形，知道剩下的都是正方形为止
#include<stdio.h>
int main()
{
	int m, n;
	scanf("%d%d", &m, &n);
	int count = 0;
	while (1)
	{
		if (m > n)//切出一块正方形
		{
			m -= n;//减去切掉的长度
			count++;
		}
		else if (m < n)//切出一块正方形
		{
			n -= m;//减去切掉的长度
			count++;
		}
		else
		{
			count++;//相等时则代表只剩下正方形，无矩形时跳出循环
			break;
		}
	}
	printf("%d\n", count);
}

#endif 