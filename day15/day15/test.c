#include<stdio.h>


//例1 编写算法找出1000以内所有完数。
//完数：其因数（因数不含自身）之和 = 自身的数。
int main()
{
	int arr[50] = { 0 };
	int i, j;
	for (i = 2; i <= 1000 / 2; i++)
	{
		int sum = 1;
		int k = 0;
		for (j = 2; j < i; j++)
		{
			if ((i%j) == 0)
			{
				sum = sum + j; //j是i的因数
				arr[k] = j;
				k++;
			}
		}
		if (sum == i)
		{
			printf("%d it's factors are: ", sum);
			printf("1 ");
			for (j = 0; j < k; j++)
			{
				printf("%d ", arr[j]);
			}
			printf("\n");
		}
	}
	return 0;
}

// 2.求一个矩阵的鞍点
int main()
{
	int i, j;//行i  列j
	int d = 0, e = 0, f; //行最小d 列最大e
	int a, b;
	int temp, flag = 0;
	int c[50][50];
	printf("请输入矩阵行数和列数");
	scanf("%d %d", &i, &j);
	for (a = 0; a < i; a++)
	{
		for (b = 0; b < j; b++)
		{
			scanf("%d", &c[a][b]);
		}
	}
	for (a = 0; a < i; a++)
	{
		d = c[a][1];
		//找到每行的最小值d
		for (b = 0; b < j; b++)
		{
			if (d > c[a][b])
			{
				d = c[a][b];
				f = b;
			}
		}
		//找到d所在列的最大值e
		for (temp = 0; temp < i; temp++)
		{
			if (e < c[temp][f])
			{
				e = c[temp][f];
			}
		}
		//如果d和e相等，则为鞍点
		if (d == e)
		{
			printf("鞍点为%d\n", d);
			flag = 1;
		}
	}
	if (flag == 0)
	{
		printf("此矩阵没有鞍点\n");
	}
	return 0;
}

