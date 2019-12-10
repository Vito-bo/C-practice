
#if 0

//4.数列特征
#include<stdio.h>
#define MAX 10000
int main()
{
	int n, i;
	scanf("%d", &n);
	int arr[MAX];
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	int max = -MAX;
	int min = MAX;
	int sum = 0;
	for (i = 0; i < n; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
		}
		if (min>arr[i])
		{
			min = arr[i];
		}
		sum += arr[i];
	}
	printf("%d\n", max);
	printf("%d\n", min);
	printf("%d\n", sum);
	return 0;
}


#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 26
//3.字母图形
//打印
void Print(char ch[MAXSIZE][MAXSIZE], int n, int m)
{
	int i, j;
	for (i = 0; i<n; i++)
	{
		for (j = 0; j<m; j++)
		{
			printf("%c", ch[i][j]);
		}
		printf("\n");
	}
}
//实现字母图形
void Drawing(int n, int m)
{
	int i, j;
	int point = 0;
	char str;
	char ch[MAXSIZE][MAXSIZE];
	//i控制行
	for (i = 0; i<n; i++)
	{
		//j 控制列
		str = 'A';
		for (j = i; j<m; j++)
		{
			ch[i][j] = str++;
		}
		str = 'B';
		for (j = i - 1; j >= 0; j--)
		{
			ch[i][j] = str++;
		}
	}
	Print(ch, n, m);
}
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	Drawing(n, m);
	return 0;
}

// 2. 01字串
#include <stdio.h>
int main()
{
	int i, j, k, l, m;
	for (i = 0; i <= 1; ++i)
	for (j = 0; j <= 1; ++j)
	for (k = 0; k <= 1; ++k)
	for (l = 0; l <= 1; ++l)
	for (m = 0; m <= 1; ++m)
		printf("%d%d%d%d%d\n", i, j, k, l, m);
	return 0;
}
//1. 闰年判断
#include<stdio.h>
int main()
{
	int year;
	scanf("%d", &year);
	if ((year % 400) == 0 || ((year % 4 == 0) && (year % 100 != 0)))
	{
		printf("yes");
	}
	else
	{
		printf("no");
	}
	return 0;
}
#endif