
#if 0
#include <stdio.h>
//基础训练18-矩形面积交
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
int main()
{
	double x1, y1, x2, y2;//矩形1 
	double x3, y3, x4, y4;//矩形2	
	double m1, n1;//交集左上角坐标 
	double m2, n2;//交集右下角坐标 
	scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
	scanf("%lf%lf%lf%lf", &x3, &y3, &x4, &y4);
	m1 = max(min(x1, x2), min(x3, x4));
	n1 = max(min(y1, y2), min(y3, y4));
	m2 = min(max(x1, x2), max(x3, x4));
	n2 = min(max(y1, y2), max(y3, y4));
	if (m2>m1&&n2>n1)
		printf("%.2f\n", (m2 - m1)*(n2 - n1));
	else
		printf("0.00\n");
	return 0;
}
#endif

#include<stdio.h>  
//基础训练19 贪心算法
int changes(char s[], char x, int n);
char x = '0 ';
int main(void)
{
	int n, i, k = 0, b[26] = { 0 }, j;
	char y, s[8000] = { 0 };
	scanf("%d", &n);
	getchar();
	for (i = 0; i<n; i++)
		scanf("%c", &s[i]);
	for (i = 0; i<n; i++)
	{
		j = s[i] - 'a';
		b[j]++;
	}
	for (j = 0; j<26; j++)
	{
		if (b[j] % 2 != 0)
		{
			k++;
			x = j + 'a';
		}
	}
	if (k >= 2)
		printf("Impossible\n");
	else
		printf("%d\n", changes(s, x, n));
	return 0;
}

int changes(char s[], char x, int n)
{
	int i, change = 0, j, k;
	for (i = 0; i<n / 2; i++)
	{
		if (s[i] == x)
		{
			for (j = i; j<n - i - 1; j++)
			if (s[n - i - 1] == s[j])
				break;
			change += j - i;
			for (k = j; k>i; k--)
				s[k] = s[k - 1];
			s[i] = s[n - i - 1];
		}
		else
		{
			for (j = n - i - 1; j >= i; j--)
			if (s[i] == s[j])
				break;
			change += n - i - 1 - j;
			for (k = j; k<n - i - 1; k++)
				s[k] = s[k + 1];
			s[n - i - 1] = s[i];
		}
	}
	return change;
}

