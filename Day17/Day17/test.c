
#include <stdio.h>

/*
int main()
{
	printf("1\n");
	printf("5 2\n");
	printf("8 6 3\n");
	printf("10 9 7 4\n");
	return 0;
}


int main()
{
	int i, j ,n, k = 0;
	int a[100][100] = { 0 };
	scanf("%d", &n);
	k = 1;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n + 1 - i; j++)
		{
			a[i - 1 + j][j] = k;
			k = k+1;
		}
	}
	for (i = 1; i <= n; i++)
	{
		printf("\n");
		for (j = 1; j <= i; j++)
		{
			printf("%d ",a[i][j]);
		}
	}
	return 0;
}



int main()
{
	int i, j, x, y, z, a;
	int b[7] = { 0, 50, 20, 10, 5, 2, 1 };
	int sum[7] = { 0 };
	scanf("%d %d", &x, &y);
	z = y - x;
	printf("%d-%d=%d\n", y, x, z);
	for (i = 1; i <= 6; i++)
	{
		a = z / b[i];
		sum[i] = sum[i] + a;
		z = z - a*b[i];
	}
	for (i = 1; i <= 6; i++)
	{
		if (sum[i] != 0)
			printf("%d ", b[i]);
	}
	return 0;
}


int main()
{
	long x, y1, y2;
	int p[10];
	int i, t, k, num = 0;
	for (x = 10000;x<32000;x++)
	{
		for (i = 0; i <= 9; i++)
			p[i] = 1;
		y1 = x*x;
		y2 = y1;
		k = 0;
		for (i = 1; i <= 9; i++)
		{
			t = y2 % 10;
			y2 = y2 / 10;
			if (p[t] == 1)
			{
				k = k + 1;
				p[t] = 0;
			}
			else
				break;
		}
		if (k == 9)
		{
			num = num + 1;
			printf("%d,%ld\n", num, x);
		}
	}
	return 0;
}
*/

int main()
{
	int a[20001];//�洢ÿһλ���õ���
	int temp, digit, n, i, j = 0;//tempÿ�εĵ�����digitÿ�ε�����λ��
	scanf("%d", &n);
	a[0] = 1;//��1��ʼ��
	digit = 1;//λ���ӵ�һλ��ʼ
	for (i = 2; i <= n; i++)
	{
		int num = 0;
		for (j = 0; j < digit; j++)
		{
			temp = a[j] * i + num;  //��һ������ÿһλ�����ֱ����i
			a[j] = temp % 100;  //��һ������ÿһλ������������д洢
			num = temp / 100;
		}
		while (num) //�ж��˳�ѭ����num��ֵ�Ƿ�Ϊ0
		{
			a[digit] = num % 100;//�����洢
			num = num / 100;
			digit++;
		}
	}
	for (i = digit - 1; i >= 0; i--)//�������ÿһλ
		if (a[i] / 10 == 0)
			printf("0%d", a[i]);
		else
			printf("%d", a[i]);
	printf("\n");
	return 0;
}