
#include <stdio.h>

/*
//例1 统计选票
void Test1()
{
	//候选人编号xp
	int i, xp;
	int a[6] = { 0 };
	printf("input your choose: %d", xp);
	scanf("%d", &xp);
	while (xp != -1) //设计停止标志
	{
		if (xp >= 1 && xp <= 5)
		{
			a[xp] = a[xp] + 1;
		}
		else
			printf("input error!\n");
	}
	for (i = 1; i <= 5; i++)
	{
		printf("%d ", a[i]);
	}
}

//例2 统计身高（单位厘米）
//统计分150-154；155-159；160-164；165-169；170-174；175-179
//低于150、高于179共八档次进行。
void Test2()
{
	int i, h;
	int a[8];
	printf("plase input height data until input -1");
	scanf("%d", &h);
	while (h != -1)
	{
		if (h > 179)
			a[7] = a[7] + 1;
		else
		{
			if (h < 150)
				a[0] = a[0] + 1;
			else
				a[h / 5 - 29] = a[h / 5 - 29] + 1;
		}
	}
	for (i = 0; i <= 7; i++)
	{
		printf(i + 1, "field the number of people: ", a[i]);
	}
}

//例3 统计及格学生名单（三门课程都及格人数）
//方法1，枚举尝试
void Test3()
{
	int a[7], b[6], c[8];
	int i, j, k, v, flag;
	for (i = 0; i <= 6; i++)
		input(a[i]);
	for (i = 0; i <= 5; i++)
		input(b[i]);
	for (i = 0; i <= 7; i++)
		input(c[i]);
	for (i = 0; i <= 6; i++)
	{
		v = a[i];
		for (i = 0; i <= 5; i++)
		if (b[j]==v)
		for (k = 0; k <= 8;k++)
		if (c[k] == v)
		{
			printf(v);
			break;
		}
	}
}

//方法二，枚举
void Test4()
{
	int a[10], i, xh;
	for (i = 1; i <= 21; i++)//21个记录
	{
		scanf("%d",&xh);
		a[xh] = a[xh] + 1;
		for (xh = 1; xh <= 9; xh++)
		{
			if (a[xh] == 3)
			{
				printf("%d ",xh);
			}
		}
	}
}

//例4 统计找数字对出现的频率
void Test4()
{
	int a[10][10], n, i, j, k1, k0;
	printf("How many numbers?");
	input(n);
	printf("Please input these numbers:");
	input(k0);
	for (i = 2; i <= n; i++)
	{
		input(k1);
		a[k0][k1] = a[k0][k1] + 1;
	}
	for (i = 0; i <= 9; i++)
	{
		for (j = 0; j <= 9; j++)
		{
			if (a[i][j] != 0 && a[j][i] != 0)
			{
				printf("(", i, j, "),a[i][j],", (" ,j,i, )=", a[i][j]));
			}
		}
	}
}
*/
//例5 编程将编号“翻译”成英文。例35706“翻译”成three-five-seven-zero-six

#include<stdio.h>
int main()
{
	int i, a[10], ind;
	int num1, num2;
	char eng[10][6] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	printf("please input a num:\n");
	scanf("%d", &num1);
	num2 = num1;
	ind = 0;
	while (num2)
	{
		a[ind] = num2 % 10;//拆分编号，并用一个数组来存储
		ind = ind + 1;
		num2 = num2 / 10;
	}
	//倒着从高位向低位输出
	for (i = ind - 1; i >= 0; i--)
		printf("%s-", eng[a[i]]);
	printf("\n");
	return 0;
}
