#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include <string.h>
void Menu()
{
	printf("***********欢迎来到猜数字游戏***********\n");
	printf("*********         1.play     ***********\n");
	printf("*********         0.exit     ***********\n");
	printf("****************************************\n");
}
void Game()
{
	//产生1-100的随机数
	int randNum = rand() % 100 + 1;
	int num = 0;
	while (1)
	{
		printf("请输入你要猜的数字->");
		scanf("%d", &num);
		if (num > randNum)
		{
			printf("猜大了\n");
		}
		else if (num < randNum)
		{
			printf("猜小了\n");
		}
		else
		{
			printf("恭喜你,猜对了\n");
			break;
		}
	}
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		Menu();
		printf("请输入你的操作：->");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			Game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("请输入正确的操作数\n");
			break;
		}
	} while (input);
	return 0;
}

//2.写代码可以在整型有序数组中查找想要的数字，找到了返回下标，找不到返回-1.（折半查找）

int Binsearch(int key, int arr[], int len)
{
	int left = 0;
	int right = len - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (key < arr[mid])
		{
			right = mid - 1;
		}
		else if (key>arr[mid])
		{
			left = mid + 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
	
}
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int ret=Binsearch(8 , arr, len);
	printf("%d\n", ret);
	return 0;
}

//3.编写代码模拟三次密码输入的场景。
//最多能输入三次密码，密码正确，提示“登录成功”,密码错误，
//可以重新输入，最多输入三次。三次均错，则提示退出程序。

int main()
{
	char password[20] = {0};
	int count = 3;
	while (count != 0)
	{
		printf("请输入你的密码:",password);
		scanf("%s", password);
		if(strcmp(password, "123456") == 0)
		{
			printf("登录成功\n");
			break;
		}
		else
		{
			count--;
			printf("登录失败,你还有%d次机会\n",count);

		}
	}
	return 0;
}

//4.编写一个程序，可以一直接收键盘字符，
//如果是小写字符就输出对应的大写字符，
//如果接收的是大写字符，就输出对应的小写字符，
//如果是数字不输出。 例如：123ABCD45efG ==> abcdEFg

int main()
{
	char ch = 0;
	while ((ch = getchar()) != EOF)
	{
		if (ch >= 'a' && ch <= 'z')
		{
			putchar(ch - 32);
		}
		else if (ch >= 'A' && ch <= 'Z')
		{
			putchar(ch + 32);
		}
		else if (ch >= '0' && ch <= '9')
		{
			putchar(ch);
		}
	}
	return 0;
}
