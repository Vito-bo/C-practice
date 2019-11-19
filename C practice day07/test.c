#include<stdio.h>
#include<string.h>
#include<assert.h>

//�����������ı�̼��ɳ�Ϊ�ݹ飨 recursion��
//�ݹ���Ҫ�б߽��������ݹ�ǰ���κ͵ݹ鷵�ضΡ�
//���߽�����������ʱ���ݹ�ǰ�������߽���������ʱ���ݹ鷵�ء�

1.�ݹ�ͷǵݹ�ֱ�ʵ�����n��쳲���������
�ݹ�
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
�ǵݹ�
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

//2.��дһ������ʵ��n^k��ʹ�õݹ�ʵ��
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

//3. дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮�ͣ�
//���磬����DigitSum(1729)����Ӧ�÷���1 + 7 + 2 + 9�����ĺ���19
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

//4. ��дһ������ reverse_string(char * string)���ݹ�ʵ�֣�
//ʵ�֣��������ַ����е��ַ��������С�
//Ҫ�󣺲���ʹ��C�������е��ַ�������������

//�ǵݹ�
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
//�ݹ�
void Reverse_Str(char* str)
{
	assert(str);
	if(*str != '\0')
	{
		//ͳ��Ԫ��
		str++;
		Reverse_Str(str);
		//�����ӡ�ַ���
		printf("%c ", *(str - 1));
	}
}
int main()
{
	char str[] = "abcdef";
	Reverse_Str(str);
	return 0;
}
//5.�ݹ�ͷǵݹ�ֱ�ʵ��strlen
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
	printf("str�ַ�������Ϊ��%d\n", My_strlen(str));
	return 0;
}

//6.�ݹ�ͷǵݹ�ֱ�ʵ����n�Ľ׳�
//�ǵݹ�
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
//�ݹ�
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

//7.�ݹ鷽ʽʵ�ִ�ӡһ��������ÿһλ.
void Print(int n)
{
	if (n < 10) 
	{
		printf("%d ", n);//���n<10��ӡ������
	}
	else if (n>10) 
	{
		Print(n / 10);//���n>10����ݹ�
		printf("%d ", n % 10);//�ݹ���ɴӺ����δ�ӡ
	}
}
int main()
{
	int num = 0;
	scanf("%d", &num);
	Print(num);
	return 0;
}