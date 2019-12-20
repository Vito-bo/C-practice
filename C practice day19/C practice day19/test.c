


//15.字符串对比
#include<stdio.h>
#include<string.h>
#define N 10
int main()
{
	char a[N], b[N];
	int len1, len2, i, j, flag = 0;
	scanf("%s%s", a, b);
	len1 = strlen(a);
	len2 = strlen(b);
	if (len1 != len2)
		printf("1\n");
	else if (len1 == len2&&strcmp(a, b) == 0)
		printf("2\n");
	else if (len1 == len2)
	{
		for (i = 0; i<len1; i++)
		{
			if (a[i] + 32 == b[i] || a[i] - 32 == b[i])
			{
				flag = 1;
				printf("3\n");
				break;
			}
		}
		if (flag == 0)
			printf("4\n");
	}
	return 0;
}

#if 0
//14.时间转换
#include<stdio.h>
int main()
{
	int t;
	scanf("%d", &t);
	int h, m, s;
	h = t / 3600;
	m = t % 3600 / 60;
	s = t % 3600 % 60;
	printf("%d:%d:%d", h,m,s);
	return 0;
}
#endif