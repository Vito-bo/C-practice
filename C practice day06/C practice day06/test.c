#include<stdio.h>
#include<string.h>
//1.ʵ��һ����������ӡ�˷��ھ����ھ���������������Լ�ָ����
//����9�����9 * 9�ھ�������12�����12 * 12�ĳ˷��ھ���
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
//2.ʹ�ú���ʵ���������Ľ�����
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
//3.ʵ��һ�������ж�year�ǲ������ꡣ
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
//		printf("������\n");
//	}
//	else if (ret == 0)
//	{
//		printf("��������\n");
//	}
//	return 0;
//}

//4.
//����һ�����飬
//ʵ�ֺ���init������ʼ�����顢
//ʵ��empty����������顢
//ʵ��reverse���������������Ԫ�ص����á�
//Ҫ���Լ���ƺ����Ĳ���������ֵ��

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
//5.ʵ��һ���������ж�һ�����ǲ���������
//������ָ�ڴ���1����Ȼ���У�����1�����������ⲻ����������������Ȼ����
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
//		printf("������\n");
//	}
//	else if (ret == 0)
//	{
//		printf("��������\n");
//	}
//	return 0;
//}