#include<stdio.h>
#include<math.h>

//1.求出0～999999之间的所有“水仙花数”并输出。
int main()
{
	int i = 0;
	for (i = 1; i <= 999999; i++)
	{
		//1、求i为几位数
		int tmp = i;
		int count = 0;
		int sum = 0;
		while (tmp != 0)
		{
			count++;
			tmp = tmp / 10;
		}
		tmp = i;
		while (tmp != 0)
		{
			sum += pow((double)(tmp % 10), (double)count);
			tmp = tmp / 10;
		}
		if (sum == i)
		{
			printf("%d ", i);
		}
	}
	printf("\n");
	return 0;
}
//2.求Sn = a + aa + aaa + aaaa + aaaaa的前n项之和，其中a是一个数字，
//例如：2 + 22 + 222 + 2222 + 22222
int main()
{
	int a = 0;
	int n = 0;
	int i = 0;
	int sum = 0;
	int tmp = 0;
	scanf("%d %d",&a,&n);
	for (i = 0; i < n; ++i)
	{
		tmp = tmp * 10 + a;
		sum += tmp;
	}
	printf("%d\n", sum);
	return 0;
}