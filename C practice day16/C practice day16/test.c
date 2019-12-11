
#if 0

#include<stdio.h>
//8. 回文数
int main()
{
	int i, a, b, c, d;
	for (i = 1000; i <= 9999; i++)
	{
		a = i % 10;
		b = i / 10 % 10;
		c = i / 100 % 10;
		d = i / 1000;
		if ((a == d) && (b == c)) 
		{
			printf("%d\n", i);
		}
	}
	return 0;
}

//7.特殊的数字
#include<stdio.h>
#include<math.h>
int main()
{
	int i, a, b, c;
	for (i = 100; i < 1000; i++)
	{
		a = i % 10;
		b = i / 10 % 10;
		c = i / 100;
		if (i == (pow(a, 3) + pow(b, 3) + pow(c,3)))
		{
			printf("%d\n", i);
		}
	}
	return 0;
}

//6.杨辉三角
#define N 34
int main()
{
	int n, i, j;
	scanf("%d", &n);
	int arr[N][N];
	for (i = 0; i < n; i++)
	{
		arr[i][0] =arr[i][i] = 1;
		for (j = 1; j < i; j++)
		{
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= i; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}
//5.查找整数
#define N 1001
int main()
{
	int n = 0;
	scanf("%d", &n);
	int arr[N];
	int i = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	int m = 0;
	int ret = -1;
	scanf("%d", &m);
	for (i = 0; i < n; i++)
	{
		if (m == arr[i])
		{
			ret = i + 1;
			break;
		}
	}
	printf("%d",ret);
	return 0;
}
#endif