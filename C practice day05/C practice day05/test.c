#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include <string.h>
void Menu()
{
	printf("***********��ӭ������������Ϸ***********\n");
	printf("*********         1.play     ***********\n");
	printf("*********         0.exit     ***********\n");
	printf("****************************************\n");
}
void Game()
{
	//����1-100�������
	int randNum = rand() % 100 + 1;
	int num = 0;
	while (1)
	{
		printf("��������Ҫ�µ�����->");
		scanf("%d", &num);
		if (num > randNum)
		{
			printf("�´���\n");
		}
		else if (num < randNum)
		{
			printf("��С��\n");
		}
		else
		{
			printf("��ϲ��,�¶���\n");
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
		printf("��������Ĳ�����->");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			Game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("��������ȷ�Ĳ�����\n");
			break;
		}
	} while (input);
	return 0;
}

//2.д����������������������в�����Ҫ�����֣��ҵ��˷����±꣬�Ҳ�������-1.���۰���ң�

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

//3.��д����ģ��������������ĳ�����
//����������������룬������ȷ����ʾ����¼�ɹ���,�������
//�����������룬����������Ρ����ξ�������ʾ�˳�����

int main()
{
	char password[20] = {0};
	int count = 3;
	while (count != 0)
	{
		printf("�������������:",password);
		scanf("%s", password);
		if(strcmp(password, "123456") == 0)
		{
			printf("��¼�ɹ�\n");
			break;
		}
		else
		{
			count--;
			printf("��¼ʧ��,�㻹��%d�λ���\n",count);

		}
	}
	return 0;
}

//4.��дһ�����򣬿���һֱ���ռ����ַ���
//�����Сд�ַ��������Ӧ�Ĵ�д�ַ���
//������յ��Ǵ�д�ַ����������Ӧ��Сд�ַ���
//��������ֲ������ ���磺123ABCD45efG ==> abcdEFg

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
