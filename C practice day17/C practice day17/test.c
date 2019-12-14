

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#if 0

//十六进制转八进制
#define MaxSize 100000

void saveB(char *b, char c3, char c2, char c1, char c0, int start)
{
	b[start] = c3;
	b[start + 1] = c2;
	b[start + 2] = c1;
	b[start + 3] = c0;
}
int htob(char *h, char *b)
{
	int i, j;
	int hl = strlen(h);
	for (i = 0; i<hl; i++)
		switch (h[i])
	{
		case '0':
		{
					saveB(b, '0', '0', '0', '0', 4 * i);
					break;
		}
		case '1':
		{
					saveB(b, '0', '0', '0', '1', 4 * i);
					break;
		}
		case '2':
		{
					saveB(b, '0', '0', '1', '0', 4 * i);
					break;
		}
		case '3':
		{
					saveB(b, '0', '0', '1', '1', 4 * i);
					break;
		}
		case '4':
		{
					saveB(b, '0', '1', '0', '0', 4 * i);
					break;
		}
		case '5':
		{
					saveB(b, '0', '1', '0', '1', 4 * i);
					break;
		}
		case '6':
		{
					saveB(b, '0', '1', '1', '0', 4 * i);
					break;
		}
		case '7':
		{
					saveB(b, '0', '1', '1', '1', 4 * i);
					break;
		}
		case '8':
		{
					saveB(b, '1', '0', '0', '0', 4 * i);
					break;
		}
		case '9':
		{
					saveB(b, '1', '0', '0', '1', 4 * i);
					break;
		}
		case 'A':
		{
					saveB(b, '1', '0', '1', '0', 4 * i);
					break;
		}
		case 'B':
		{
					saveB(b, '1', '0', '1', '1', 4 * i);
					break;
		}
		case 'C':
		{
					saveB(b, '1', '1', '0', '0', 4 * i);
					break;
		}
		case 'D':
		{
					saveB(b, '1', '1', '0', '1', 4 * i);
					break;
		}
		case 'E':
		{
					saveB(b, '1', '1', '1', '0', 4 * i);
					break;
		}
		case 'F':
		{
					saveB(b, '1', '1', '1', '1', 4 * i);
					break;
		}
	}
	return 4 * hl;
}
int btoo(char *b, char *o, int bl)
{
	int i, j;
	int ol;
	int value;
	if (bl % 3 == 0)
		ol = bl / 3;
	else
		ol = bl / 3 + 1;
	j = bl - 1;
	for (i = ol - 1; i >= 0; i--)
	{
		if (i>0)
			o[i] = b[j] - 48 + (b[j - 1] - 48) * 2 + (b[j - 2] - 48) * 4 + 48;
		else
		{
			switch (j)
			{
			case 2:
				o[i] = b[j] - 48 + (b[j - 1] - 48) * 2 + (b[j - 2] - 48) * 4 + 48;
				break;
			case 1:
				o[i] = b[j] - 48 + (b[j - 1] - 48) * 2 + 48;
				break;
			case 0:
				o[i] = b[j];
				break;
			}

		}
		j = j - 3;
	}
	return ol;
}
void printO(char *o, int ol)
{
	int i = 0;
	if (o[0] == '0')
		i = 1;
	for (; i<ol; i++)
	{
		printf("%c", o[i]);
	}
	printf("\n");
}
int main()
{
	char h[MaxSize];
	char b[4 * MaxSize];
	char o[4 * MaxSize / 3 + 1];
	int n, i, bl, ol;
	scanf("%d", &n);
	getchar();
	for (i = 0; i<n; i++)
	{
		gets(h);
		bl = htob(h, b);
		ol = btoo(b, o, bl);
		printO(o, ol);
	}
	return 0;
}


//11. 十六进制转十进制
int main()
{
	double sum = 0, x;
	char a[8];
	int len, i = 0;
	gets(a);
	len = strlen(a);
	while (len)
	{
		if (a[len - 1] >= 'A'&&a[len - 1] <= 'F')
			x = (a[len - 1] - '7')*pow(16, i++);
		else
			x = (a[len - 1] - '0')*pow(16, i++);
		sum += x;
		len--;
	}
	printf("%.0lf", sum);

	return 0;

}



//10.十进制转十六进制  
char data[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
//输出
void Print(char *num, int n)
{
	int i;
	for (i = n - 1; i >= 0; i--) 
		printf("%c", num[i]);
	printf("\0");
	printf("\n");
}

//将十六进制数转换为十进制数
int Transform(char *num, long long value)
{
	int n = 0;
	while (value >= 16)
	{
		num[n++] = data[value % 16];
		value /= 16;
	}
	num[n++] = data[value % 16];
	return n;
}

int main()
{
	long long value;
	char num[10];
	int n;
	scanf("%I64d", &value);
	n = Transform(num, value);
	Print(num, n);
	return 0;
}


//0除外
int main()
{
	int num;
	int a[100] = {0};
	int i = 0;
	int m = 0;
	int yushu;
	char hex[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
	scanf("%d",&num); 
	while(num>0) 
	{ 
		yushu=num%16;
	    a[i++]=yushu; 
	    num=num/16;
	} 
	for(i=i-1;i>=0;i--)
	{
		m=a[i];
		printf("%c",hex[m]); 
	} 
	return 0;
}


//9. 特殊回文数
int main()
{
	int n, i;
	scanf("%d", &n);
	for (i = 10000; i <= 999999; i++)
	{
		int a, b, c, d, e, f;
		if (i < 100000)
		{
			a = i % 10;
			b = i / 10 % 10;
			c = i / 100 % 10;
			d = i / 1000 % 10;
			e = i / 10000;
			if ((a == e) && (b == d) && (n == a + b + c + d + e))
			{
				printf("%d\n", i);
			}
		}
		else
		{
			a = i % 10;
			b = i / 10 % 10;
			c = i / 100 % 10;
			d = i / 1000 % 10;
			e = i / 10000 % 10;
			f = i / 100000;
			if ((a == f) && (b == e)  &&(c==d) && (n == a + b + c + d + e + f))
			{
				printf("%d\n", i);
			}
		}
	}
	return 0;
}
#endif