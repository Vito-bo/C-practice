
#if 0
//分解质因数
#include<stdio.h>
#include<math.h>
int main()
{
	long int b, i, k, m, n, w = 0;
	scanf("%ld%ld", &m, &n);
	for (i = m; i <= n; i++)
	{
		printf("%ld=", i);
		b = i; k = 2;
		while (k <= sqrt(i))
		{
			if (b%k == 0)
			{
				b = b / k;
				if (b>1)
				{
					printf("%ld*", k); 
					continue;
				}
				if (b == 1) 
					printf("%ld\n", k);
			}
			k++;
		}
		if (b>1 && b<i) 
			printf("%ld\n", b);
		if (b == i)
		{
			printf("%d\n", i); 
			w++;
		}
	}
	return 0;
}
#endif 


#include <stdio.h>
#include <string.h>
#define N 100
int A[N][N], t[N][N], r[N][N];
int main()
{
	int n, m, i, j, k;
	scanf("%d%d", &n, &m);
	for (i = 0; i<n; i++)
	for (j = 0; j<n; j++)
		scanf("%d", &A[i][j]);
	for (i = 0; i<n; i++)
		r[i][i] = 1;//单位矩阵，如同数的乘法中的1
	while (m--)
	{
		memset(t, 0, sizeof(t));
		for (i = 0; i<n; i++)
		for (j = 0; j<n; j++)
		for (k = 0; k<n; k++)
			t[i][j] += r[i][k] * A[k][j];
		for (i = 0; i<n; i++)
		for (j = 0; j<n; j++)
			r[i][j] = t[i][j];
	}
	for (i = 0; i<n; i++)
	{
		for (j = 0; j<n - 1; j++)
			printf("%d ", r[i][j]);
		printf("%d\n", r[i][j]);
	}
	return 0;
}
