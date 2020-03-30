


#include <stdio.h>
#include <assert.h>


/*
void ReplaceBlank(char* str, int len)
{
	int NumBlank = 0;
	int i = 0;
	int mlen = 0;
	int newLen = 0;
	int indexofMylen = 0;
	int indexofNewlen = 0;
	assert(str != NULL);
	while (str[i] != '\0')
	{
		++mlen;  //strlen
		if (str[i] = ' ')
		{
			++NumBlank; //空格的个数
		}
		i++;
	}
	//新的数组长度
	newLen = mlen + NumBlank * 2 + 1;
	if (newLen > len)
	{
		return;
	}
	indexofMylen = mlen;
	indexofNewlen = newLen;

	while (indexofMylen >= 0 
		&& indexofNewlen > indexofMylen)
	{
		if (str[indexofMylen] == ' ')
		{
			str[indexofNewlen] = '0';
			str[indexofNewlen] = '2';
			str[indexofNewlen] = '%';

		}
		else
		{
			str[indexofNewlen] = str[indexofMylen];
			indexofNewlen--; 
		}
		indexofMylen--;
	}
}

int main()
{
	char str[50] = "abc defgx yz";
	int len = sizeof(str) / sizeof(str[0]);

	ReplaceBlank(str, len);
	printf("%s\n", str);
	return 0;
} 


int main()
{
	int a = 5;
	if (a = 0)
	{
		printf("%d\n", a - 10);
	}
	else
	{
		printf("%d\n", a++);
	}
	double** d[3][4];
	printf("%d\n", sizeof(d));
	return 0;
}

//非递归求第n个斐波那契数列的值
int Fibonacci(int n)
{
	int f1 = 1;
	int f2 = 1;
	int f3 = 1; 
	int i = 3;
	for (i = 3; i <= n; i++)
	{
		f3 = f1 + f2;
		f1 = f2;
		f2 = f3;
	}
	return f3;
}

int main()
{
	printf("%d\n", Fibonacci(1));
	printf("%d\n", Fibonacci(2));
	printf("%d\n", Fibonacci(3));
	printf("%d\n", Fibonacci(4));

	return 0;
}


//青蛙跳台阶(递归)
int JumpFloor(int n)
{
	if (n <= 2)
		return n;
	else
		return JumpFloor(n - 1) + JumpFloor(n - 2);
}
//青蛙跳台阶(非递归)
int JumpFloor(int n)
{
	int f1 = 1;
	int f2 = 2;
	int f3 = 0;
	if (n <= 0)
		return 0;
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	int i = 3;
	for (i = 3; i <= n; i++)
	{
		f3 = f1 + f2;
		f1 = f2;
		f2 = f3;
	}
	return f3;
}
int main()
{
	printf("%d\n", JumpFloor(1));
	printf("%d\n", JumpFloor(2));
	printf("%d\n", JumpFloor(3));
	printf("%d\n", JumpFloor(4));
	return 0;
}


//1:A->C  2^1-1
//2:A->B A->C B->C  2^2-1
//3:A->C A->B C->B A->C B->A B->C A->C  2^3-1

void Move(char pos1, char pos2)
{
	printf("%c->%c ", pos1, pos2);
}
//n盘子个数，
//pos1:开始位置
//pos2:中间位置
//pos3:结束位置
void Hanota(int n, char pos1, char pos2, char pos3)
{
	//终止条件
	if (n == 1)
		Move(pos1, pos3);
	//递归调用
	else
	{
	
		Hanota(n - 1, pos1, pos3, pos2);
		Move(pos1, pos3);
		Hanota(n - 1, pos2, pos1, pos3);
	}
}
int main()
{
	Hanota(1,'A','B','C');
	printf("\n");
	Hanota(2, 'A', 'B', 'C');
	printf("\n");
	Hanota(3, 'A', 'B', 'C');
	printf("\n");

	return 0;
}
*/
int Numberof1(int n)
{
	int count = 0;
	while (n)
	{
		++count;
		n = (n - 1)&n;
	} 
	return count;
} 
int main()
{
	printf("%d\n", Numberof1(4));
	return 0;
}
