

#if 0
#include <stdio.h>

int a[100][100];   //�����ά���飬�����Ҫ��ӡ������
int Matrix_Printed(int n)
{
	int i, j, k, count = 1;
	for (k = 0; k<n; k++)
	{
		i = k;
		for (j = k; j<n - k; j++)
		{
			a[i][j] = count;
			count++;
		}
		for (i = k + 1; i<n - k; i++)
		{
			a[i][n - k - 1] = count;
			count++;
		}
		for (j = n - k - 2; j >= k; j--)
		{
			a[n - 1 - k][j] = count;
			count++;
		}
		for (i = n - k - 2; i >= k + 1; i--)
		{
			a[i][k] = count;
			count++;
		}
	}
	for (i = 0; i<n; i++)
	for (j = 0; j<n; j++)
	{
		if (j%n == 0)
		{
			printf("\n");
			printf("%3d", a[i][j]);
		}
		else
			printf("%3d", a[i][j]);
	}
	printf("\n");
}
int main()
{
	int n;
	printf("������Ҫ��ӡ�ķ�����к�����n��");
	scanf("%d", &n);
	Matrix_Printed(n);
	return 0;
}

#include <stdio.h>

int main()
{
	int n;//��������׳˵ķ�Χ
	scanf("%d", &n);

	int div = 5; //���� 
	int ans = 0; //��ʾĩβ0����Ŀ

	while (div <= n)
	{
		ans += n / div;
		div *= 5;
	}

	printf("%d\n", ans);
	return 0;
}
#endif

#include<stdio.h>
int main()
{
	int a, b, c, n;
	printf("������������λ��Ϊ��\n");
	for (n = 10; n<32; n++)
	{
		a = n*n / 100;
		b = n*n / 10 % 10;
		c = n*n % 10;
		if (a == b || a == c || b == c)
			printf("%d\n", n*n);
	}
	return 0;
}
