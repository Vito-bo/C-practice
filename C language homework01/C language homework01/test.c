#include<stdio.h>
#include<math.h>
#include<assert.h>
#include<string.h>
/*
//1. ��ӡ100~200֮�������
int main()
{
	int i = 0;
	int count = 0;
	//for (i = 100; i <= 200; ++i)
	for (i = 101; i <= 200;i+=2)//���˵�ż��
	{
		int j = 0;
		//for (j = 2; j < i; ++j)
		//for (j = 2; j <=i/2;++j)
		for (j = 2; j <= sqrt((double)i);++j)
		{
			if (i %j == 0)
			{
				break;
			}
		}
		//if (i == j)
		//if (j>i/2)
		if (j>sqrt((double)i))
		{
			printf("%d ", i);
			count++;
		}
	}
	printf("\n");
	printf("count=%d\n", count);
	return 0;
}
//2. ����˷��ھ���
int main()
{
	int i = 0;
	int j = 0;
	printf("��ӡ�žų˷���:\n");
	for (i = 1; i <= 9; ++i)
	{
		for (j = 1; j <= i; ++j)
		{
			printf("%d*%d=%-3d", i, j, i*j);
		}
		printf("\n");
	}
	
	return 0;
}

//3. �ж�1000��-- - 2000��֮�������
int main()
{
	int year = 0;
	printf("1000-2000֮�������Ϊ: \n");
	for (year = 1000; year <= 2000; ++year)
	{
		if (year % 400 == 0)
		{
			printf("%d ", year);
		}
		else if (year % 4 == 0 && year % 100 != 0)
		{
			printf("%d ", year);
		}
	}
	printf("\n");
	return 0;
}

