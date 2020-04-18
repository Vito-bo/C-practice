
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
	printf("��һ����%d������\n", peach);
	return 0;
}

#include <stdio.h>
#include <math.h>
//���1-8�Ƿ������һ�Σ����ǣ��򷵻�1�����򷵻�0
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

//����Ƿ���ͬһ�Խ����ϣ������ڣ�����1�����򷵻�0��
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
	int n = 0;    //����
	long a;

	for (a = 12345678; a <= 87654321; a += 9) //ö�����п�����
	{
		if (check_1_8(a) == 0)   //�������1-8
			continue;
		if (check_dia(a) == 0)    //���Խ���
			continue;
		printf("%ld     ", a);     //�õ�һ����
		n++;
		if (n % 6 == 0)            //ÿ�д�ӡ6��
			printf("\n");
	}
	printf("\nһ����%d��\n", n);     //����ܵķ�����
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