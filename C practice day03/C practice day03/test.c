#include<stdio.h>

/*
//1. 将数组A中的内容和数组B中的内容进行交换（数组一样大）
void Swap(int *p, int *q)
{
	int tmp = *q;
	*q = *p;
	*p = tmp;
}
void Show(int arr[], int len)
{
	int i = 0;
	for (i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	int arr1[5] = { 0 };
	int arr2[5] = { 0 };
	int len = sizeof(arr1) / sizeof(arr1[0]);
	int i = 0;
	//开始输入数据
	for (i = 0; i < len; i++)
	{
		scanf_s("%d", &arr1[i]);
	}
	for (i = 0; i < len; i++)
	{
		scanf_s("%d", &arr2[i]);
	}
	//开始交换数据
	for (i = 0; i < len; i++)
	{
		Swap(&arr1[i], &arr2[i]);
	}
	//打印数组
	Show(arr1, len);
	Show(arr2, len);
	return 0;
}
*/
//2. 计算1 / 1 - 1 / 2 + 1 / 3 - 1 / 4 + 1 / 5 …… + 1 / 99 - 1 / 100 的值。
//int main()
//{
//	int i = 1;
//	int ret = 0;
//	double  sum = 0;
//	for (i = 1; i <= 100; i+=2)
//	{
//		sum += (1.0 / i)-(1.0/(i+1));
//	}
//	printf("%lf\n", sum);
//	return 0;
//}
//int main()
//{
//	int i = 0;
//	int flg = 1;
//	double sum = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		sum += flg * 1.0 / i;
//		flg = -flg;
//	}
//	printf("%lf\n", sum);
//	return 0;
//}
//3. 编写程序数一下1到 100 的所有整数中出现多少个数字9。


int main()
{
	int i = 0;
	int count = 0;
	for (i = 1; i <= 100; ++i)
	{
		if ((i % 10 == 9) || (i / 10 == 9))
			count++;
	}
	printf("%d\n", count);
	return 0;
}