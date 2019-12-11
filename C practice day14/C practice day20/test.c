#include <stdio.h>
#include<string.h>
#include <stdlib.h>




//ABCDEFG
//BABCDEF
//CBABCDE
//DCBABCD
//EDCBABC
//����һ��5��7�е�ͼ�Σ����ҳ����ͼ�εĹ��ɣ�
//�����һ��n��m�е�ͼ�Ρ�

#define MAXSIZE 26

//���
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

//ʵ����ĸͼ��
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
//���������
int main()




//01�ִ�
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