#include<stdio.h>

#if 0
void Show(int arr[], int len)
{
	int i = 0;
	for (i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main()
{
	int arr[10] = { 0 };
	int i = 0;
	int len = sizeof(arr) / sizeof(arr[0]);
	Show(arr, len);
	for (i = 0; i < len; i++)
	{
		scanf_s("%d", &arr[i]);
	}
	Show(arr, len);
	return 0;
}

int main()
{
	int i = 0;
	for (i = 0; i < 4; i++)
	{
		if (i == 1)
		{
			continue;
		}
		printf("HELLO\n");
	}
	return 0;
}


int main()
{
	int i = 0;
	scanf("%d", &i);
	switch (i)
	{
	case 1:
		printf("1\n");
		break;
	case 2:
		printf("2\n");
		break;
	default://默认情况下
		printf("0\n");
		break;
	}
	return 0;
}



int main()
{
	int i = 1;
    w_go:i++;
	if (i < 5)
		goto w_go;
	else
	    printf("%d", i);
	return 0;

}
int main()
{
	int a = 10;
	int *p = &a;//取出a的地址
	//地址存放在对应类型的指针当中
	*p = 88;//间接访问符（解引用）
	//printf("%d\n", a);
	//printf("%d\n", *p);
	int **pp = &p;
	**pp = 99;
	//地址存放在对应类型的指针当中
	//printf("%p\n",&a);//打印变量的地址 十六进制显示
	//printf("%d\n",&a);//每次运行程序,变量的地址是不确定的
	return 0;
}


int main()
{
	int n = 1;
	int m = 2;
	switch (n)
	{
	case 1:
		m++;
	case 2:
		n++;
	case 3:
		switch (n)
		{//switch允许嵌套使用
		case 1:
			n++;
		case 2:
			m++;
			n++;
			break;
		}
	case 4:
		m++;
		break;
	default:
		break;
	}
	printf("m = %d, n = %d\n", m, n); //n=3 m=5
	return 0;
}


int main()
{
	int n;
	switch (n)
	{
	case 1:
		printf("wc\n ");
	case 2:
		printf("wto\n ");

	default:
		break;
	}
	return 0;
}

int Get_Max(int x, int y)
{
	return x > y ? x : y;
}
int main()
{
	int num1 = 10;
	int num2 = 20;
	printf("%d\n", Get_Max(num1, num2));
	return 0;
}
#endif
int main(void)
{
	char a = '\0 ';
	char b = '0';
	printf("a=%c,b=%c\n", a, b);
	return 0;
}