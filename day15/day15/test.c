#include<stdio.h>


//��1 ��д�㷨�ҳ�1000��������������
//��������������������������֮�� = ���������
int main()
{
	int arr[50] = { 0 };
	int i, j;
	for (i = 2; i <= 1000 / 2; i++)
	{
		int sum = 1;
		int k = 0;
		for (j = 2; j < i; j++)
		{
			if ((i%j) == 0)
			{
				sum = sum + j; //j��i������
				arr[k] = j;
				k++;
			}
		}
		if (sum == i)
		{
			printf("%d it's factors are: ", sum);
			printf("1 ");
			for (j = 0; j < k; j++)
			{
				printf("%d ", arr[j]);
			}
			printf("\n");
		}
	}
	return 0;
}

// 2.��һ������İ���
int main()
{
	int i, j;//��i  ��j
	int d = 0, e = 0, f; //����Сd �����e
	int a, b;
	int temp, flag = 0;
	int c[50][50];
	printf("�������������������");
	scanf("%d %d", &i, &j);
	for (a = 0; a < i; a++)
	{
		for (b = 0; b < j; b++)
		{
			scanf("%d", &c[a][b]);
		}
	}
	for (a = 0; a < i; a++)
	{
		d = c[a][1];
		//�ҵ�ÿ�е���Сֵd
		for (b = 0; b < j; b++)
		{
			if (d > c[a][b])
			{
				d = c[a][b];
				f = b;
			}
		}
		//�ҵ�d�����е����ֵe
		for (temp = 0; temp < i; temp++)
		{
			if (e < c[temp][f])
			{
				e = c[temp][f];
			}
		}
		//���d��e��ȣ���Ϊ����
		if (d == e)
		{
			printf("����Ϊ%d\n", d);
			flag = 1;
		}
	}
	if (flag == 0)
	{
		printf("�˾���û�а���\n");
	}
	return 0;
}

