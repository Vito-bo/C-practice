
/*
#include <stdio.h>
int main()
{
	int peach = 2, i;
	for (i = 9; i >=1; i--)
	{
		peach += 2;
		peach = peach * 2;
	}
	printf("第一天有%d个桃子\n", peach);
	return 0;
}

#include <stdio.h>
#include <math.h>
//检查1-8是否各出现一次，若是，则返回1，否则返回0
int check_1_8(long m)
{
	int f[10], i, flag;
	for (i = 0; i<10; i++)
		f[i] = 0;
	while (m != 0)
	{
		f[m % 10]++;
		m = m / 10;
	}
	for (flag = 1, i = 1; i <= 8; i++)
	{
		if (f[i] != 1)
		{
			flag = 0;
			break;
		}
	}
	return flag;
}

//检测是否在同一对角线上，若不在，返回1，否则返回0；
int check_dia(long m)
{
	int g[9], i, j, flag;
	for (i = 8; i >= 1; i--)
	{
		g[i] = m % 10;
		m = m / 10;
	}

	flag = 1;
	for (i = 1; i <= 7; i++)
	{
		for (j = i + 1; j <= 8; j++)
		{
			if (abs(g[j] - g[i]) == j - i)
			{
				flag = 0;
				break;
			}
		}
	}
	return flag;
}

int main()
{
	int n = 0;    //总数
	long a;

	for (a = 12345678; a <= 87654321; a += 9) //枚举所有可能数
	{
		if (check_1_8(a) == 0)   //检查数字1-8
			continue;
		if (check_dia(a) == 0)    //检测对角线
			continue;
		printf("%ld     ", a);     //得到一个解
		n++;
		if (n % 6 == 0)            //每行打印6个
			printf("\n");
	}
	printf("\n一共有%d种\n", n);     //输出总的方案数
	return 0;
}
*/

#include <stdio.h>
int main()
{
	for (int A = 1000; A <= 9999; A++)
	{

		int a = A / 1000;
		int b = A % 1000 / 100;
		int c = A % 100 / 10;
		int d = A % 10;
		int B = a + b + c + d;

		int sum = B*B;
		if ((a - b != 0) && (a - c != 0) && (a - d != 0) && (b - c != 0) && (b - d != 0) && (c - d != 0))
		{
			if ((A%sum) == 0)
				printf("%d\n", A);
		}
	}
	return 0;
}