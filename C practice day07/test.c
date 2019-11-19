#include<stdio.h>
#include<string.h>
#include<assert.h>

//程序调用自身的编程技巧称为递归（ recursion）
//递归需要有边界条件、递归前进段和递归返回段。
//当边界条件不满足时，递归前进；当边界条件满足时，递归返回。

1.递归和非递归分别实现求第n个斐波那契数。
递归
int Fib(int n)
{
	if (n < 3)
	{
		return 1;
	}
	else
	{
		return Fib(n - 1) + Fib(n - 2);
	}
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	printf("%d\n", Fib(n));
	return 0;
}
非递归
int Fib(int n)
{
	int a = 1;
	int b = 1;
	int c = 0;
	while (n > 2)
	{
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	int ret = 0;
	if ((n == 1) || (n == 2))
	{
		ret = 1;
	}
	else
	{
		ret = Fib(n);
	}
	printf("%d\n", ret);
	return 0;
}

//2.编写一个函数实现n^k，使用递归实现
//int Power(int n, int k)
{
	if(n==1)
	{
		return 1;
	}
	else if (k==1)
	{
		return n;
	}
	else
	{
		return n * Power(n, (k - 1));
	}
}
int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	int ret = Power(n, k);
	printf("%d\n", ret);
	return 0;
}

//3. 写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和，
//例如，调用DigitSum(1729)，则应该返回1 + 7 + 2 + 9，它的和是19
int DigitSum(int n)
{
	int sum = 0;
	int ret = 0;
  if(n!=0)
	{
		ret = n % 10;
	    sum = ret + DigitSum(n / 10);
	}
	return sum;
}
int main()
{
	int num = 0;
	scanf("%d", &num);
	printf("%d\n", DigitSum(num));
	return 0;
}

//4. 编写一个函数 reverse_string(char * string)（递归实现）
//实现：将参数字符串中的字符反向排列。
//要求：不能使用C函数库中的字符串操作函数。

//非递归
void Reverse_Str(char* str)
{
	assert(str);
	int left = 0;
	int right = strlen(str) - 1;
	while (left < right)
	{
		char tmp = str[left];
		str[left] = str[right];
		str[right] = tmp;
		left++;
		right--;
	}
	return str;
}
//递归
void Reverse_Str(char* str)
{
	assert(str);
	if(*str != '\0')
	{
		//统计元素
		str++;
		Reverse_Str(str);
		//反向打印字符串
		printf("%c ", *(str - 1));
	}
}
int main()
{
	char str[] = "abcdef";
	Reverse_Str(str);
	return 0;
}
//5.递归和非递归分别实现strlen
int My_strlen(char* str)
{
	int len = 0;
	while (*str != '\0')
	{
		str++;
		len++;
	}
	return len;
}
int main()
{
	char str[] = "shanxi";
	printf("str字符串长度为：%d\n", My_strlen(str));
	return 0;
}

//6.递归和非递归分别实现求n的阶乘
//非递归
int Factorial(int n)
{
	int ret = 1;
	while (n > 0)
	{
		ret= ret*n;
		n--;
	}
	return ret;
}
//递归
int Factorial(int n)
{
	if (n == 1) 
	{
		return 1;
	}
	else
	{
		return n*Factorial(n - 1);
	}
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	printf("%d\n", Factorial(n));
}

//7.递归方式实现打印一个整数的每一位.
void Print(int n)
{
	if (n < 10) 
	{
		printf("%d ", n);//如果n<10打印他本身
	}
	else if (n>10) 
	{
		Print(n / 10);//如果n>10进入递归
		printf("%d ", n % 10);//递归完成从后依次打印
	}
}
int main()
{
	int num = 0;
	scanf("%d", &num);
	Print(num);
	return 0;
}