#include <stdio.h>
#include<string.h>
#include <stdlib.h>




//ABCDEFG
//BABCDEF
//CBABCDE
//DCBABCD
//EDCBABC
//这是一个5行7列的图形，请找出这个图形的规律，
//并输出一个n行m列的图形。

#define MAXSIZE 26

//输出
void Print(char matrix[MAXSIZE][MAXSIZE], int n, int m)
{
	int i, j;
	for (i = 0; i<n; i++)
	{
		for (j = 0; j<m; j++)
		{
			printf("%c", matrix[i][j]);
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
	char matrix[MAXSIZE][MAXSIZE];
	for (i = 0; i<n; i++)
	{
		str = 'A';
		for (j = i; j<m; j++)
		{
			matrix[i][j] = str++;
		}
		str = 'A';
		for (j = i - 1; j >= 0; j--)
		{
			matrix[i][j] = ++str;
		}
	}
	Print(matrix, n, m);
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	Drawing(n, m);
	return 0;
}


/*
//特殊回文数
int main(){	int n;	scanf("%d", &n);	int i = 0;	for (i = 10000; i <= 999999; i++)	{		if (i < 100000)		{			int d1 = i % 10;			int d2 = i / 10 % 10;			int d3 = i / 100 % 10;			int d4 = i / 1000 % 10;			int d5 = i / 10000;			if ((d1 == d5) && (d2 == d4) && (n == (d1 + d2 + d3 + d4 + d5)))			{				printf("%d\n", i);			}		}		else		{			int d1 = i % 10;			int d2 = i / 10 % 10;			int d3 = i / 100 % 10;			int d4 = i / 1000 % 10;			int d5 = i / 10000 % 10;			int d6 = i / 100000;			if ((d1 == d6) && (d2 == d5) && (d3 == d4) && (n == (d1 + d2 + d3 + d4 + d5 + d6)))			{				printf("%d\n", i);			}		}	}	return 0;}




//01字串
int main()
{
	int a, b, c, d, e;
	for (a = 0; a <= 1; a++)
	{
		for (b = 0; b <= 1; b++)
		{
			for (c = 0; c <= 1; c++)
			{
				for (d = 0; d <= 1; d++)
				{
					for (e = 0; e <= 1; e++)
					{
						printf("%d%d%d%d%d\n", a, b, c, d, e);
					}

				}

			}

		}

	}
	return 0;
}

*/