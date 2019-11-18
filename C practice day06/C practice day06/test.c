#include<stdio.h>
#include<string.h>
//1.实现一个函数，打印乘法口诀表，口诀表的行数和列数自己指定，
//输入9，输出9 * 9口诀表，输入12，输出12 * 12的乘法口诀表。
//void Print(int n)
//{
//	int i, j;
//	for (i = 1; i <= n; ++i)
//	{
//		for (j = 1; j <= i; ++j)
//		{
//			printf("%d*%d=%-3d", i, j, i*j);
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int n = 0;
//	scanf("%d",&n);
//	Print(n);
//	return 0;
//}
//2.使用函数实现两个数的交换。
/*void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	Swap(&a, &b);
	printf("%d %d\n", a, b);
	return 0;*/
//}
//3.实现一个函数判断year是不是润年。
//int Is_leapYear(int year)
//{
//	if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//int main()
//{
//	int year = 0;
//	scanf("%d", &year);
//	int ret=Is_leapYear(year);
//	if (ret == 1)
//	{
//		printf("是闰年\n");
//	}
//	else if (ret == 0)
//	{
//		printf("不是闰年\n");
//	}
//	return 0;
//}

//4.
//创建一个数组，
//实现函数init（）初始化数组、
//实现empty（）清空数组、
//实现reverse（）函数完成数组元素的逆置。
//要求：自己设计函数的参数，返回值。

void Init(int arr[], int len)
{
	int i = 0;
	for (i = 0; i < len; i++)
	{
		arr[i] = i;
	}
}
void Empty(int arr[], int len)
{
	int i = 0;
	for (i = 0; i < len; i++)
	{
		arr[i] = 0;
	}
}
void Reverse(int arr[], int len)
{
	int left = 0;
	int right = len - 1;
	while (left <= right)
	{
		int tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		left++;
		right--;
	}
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
	int arr[10];
	int len = sizeof(arr) / sizeof(arr[0]);
	Init(arr, len);
	Show(arr, len);
	Reverse(arr, len);
	Show(arr, len);
	Empty(arr, len);
	Show(arr, len);
}
//5.实现一个函数，判断一个数是不是素数。
//素数是指在大于1的自然数中，除了1和它本身以外不再有其他因数的自然数。
//int Is_Prime(int n)
//{
//	int i = 0;
//	for (i = 2; i < n; ++i)
//	{
//		if ( (n%i) != 0)
//		{
//			return 1;
//		}
//		else
//		{
//			return 0;
//		}
//	}
//}
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	int ret = Is_Prime(a);
//	if (ret == 1)
//	{
//		printf("是素数\n");
//	}
//	else if (ret == 0)
//	{
//		printf("不是素数\n");
//	}
//	return 0;
//}