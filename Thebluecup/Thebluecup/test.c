#include<stdio.h>
#include<string.h>

int main()
{
	int n, a, b, c, i;
	int count = 0;
	scanf("%d", &n);
	scanf("%d%d%d", &a, &b, &c);
	for (i = 1; i <= n; i++)
	{
		if ((i%a != 0) && (i%b != 0) && (i%c) != 0)
		{
			count++;
		}
	}
	printf("%d", count);
	return 0;
}

#if 0
//洁净数
#include<stdio.h>
int main()
{
	int i = 0;
	int count = 0;
	int n = 0;
	int m = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; ++i)
	{
		m = i;
		while (m)
		{
			if ( m % 10 == 2)
			{
				count++;
				break;
			}
			m = m / 10;
		}
	}
	printf("%d", n-count );
	return 0;
}

#include<stdio.h>
#include<string.h>
#define MAX 100
int main()
{
	char a[MAX], tag;
	int len, i;
	gets(a);
	tag = 'n';
	for (i = 0; i< strlen(a); i++)
	{
		if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u')
		{
			tag = a[i];
			break;
		}
	}
	printf("%c", tag);
	return 0;
}

//回文数
//1221是一个非常特殊的数，它从左边读和从右边读是一样的，编程求所有这样的四位十进制数。

int main()
{
	int i, a, b, c, d;
	for (i = 1000; i <= 9999; ++i)
	{
		a = i / 1000;
		b = i / 100 % 10;
		c = i / 10 % 10;
		d = i % 10;
		if (a == d&&c == b)
		{
			printf("%d ",i);
		}
	}
	return 0;
}

// A+B问题
int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%d\n", a + b);
	return 0;
}

//  序列求和
int main()
{
	int n;
	long long sum=0;
	scanf("%d", &n);
	sum = (1+n)*n/2;
	printf("%I64d\n", sum);
	//int n, i;
	//scanf("%d", &n);
	//int sum = 0;
	//for (i = 1; i <= n; ++i)
	//{
	//	sum += i;
	//}
	//printf("%d\n", sum);
	return 0;
}

//2.求圆面积
int main()
{
	int r = 0;
	double s, PI;
	scanf("%d", &r);
	PI = atan(1.0) * 4;
	s = PI*r*r;
	printf("%.7lf", s);
	return 0;
}

//Fibonacci数列
#defibne MAX 1000001
#define MOD 1007
int n = 0;
int i = 0;
int F[MAX];
int main()
{
	scanf("%d", &n);
	F[1] = 1;
	F[2] = 1;
	for (i = 3; i <= n; ++i)
	{
		F[i] = (F[i - 1] + F[i - 2]) % MOD;
	}
	printf("%d\n", F[n]);
	return 0;
}

#endif