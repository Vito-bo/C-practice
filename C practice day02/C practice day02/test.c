#include<stdio.h>

1. �����������α�����ֵ��������ֵ�����ݽ��н�����
void Swap(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
int main()
{
	int a = 3, b = 5;
	/*int tmp = a;
	a = b;
	b = tmp;*/
	Swap(&a, &b);
	printf("a=%d,b=%d\n", a, b);
	return 0;
}

2. ����������ʱ���������������������ݣ������⣩
int main()
{
	int a = 3;
	int b = 5;
	a = a^b;
	b = a^b;
	a = a^b;
	/*a = a + b;
	b = a - b;
	a = a - b;*/
	printf("a=%d,b=%d\n", a, b);
	return 0;
}

3.��10 �����������ֵ��
int main()
{
	int a[10] = { 11, 22, 33, 44, 9, 99, 77, 56, 45, 67 };
	int i= 0;
	int max = a[0];
	for (i = 0; i < 10; ++i)
	{
		if (max < a[i])
		{
			max = a[i];
		}
	}
	printf("max=%d\n", max);
	return 0;
}

4.�����������Ӵ�С�����
int main()
{
	int a = 3, b = 7, c = 9;
	int tmp = 0;
	if (a < b)
	{
		tmp = a;
		a = b;
		b = tmp;
	}
	if (a < c)
	{
		tmp = a;
		a = c;
		c = tmp;
	}if (b < c)
	{
		tmp = b;
		b = c;
		c = tmp;
	}
	printf("%d,%d,%d\n", a, b, c);
	return 0;
}
//5.�������������Լ��������Ϊ0��ʱ�򣬳����������Լ��
int main()
{
	int a = 0, b = 0;
	scanf("%d%d", &a, &b);
	int c = 0;
	while ((a%b)!= 0)
	{
		c = a%b;
		a = b;
		b = c;
	}
	printf("%d\n", c);
	return 0;
}