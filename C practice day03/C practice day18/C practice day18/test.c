


//ceil���� ����ȡ��  ceil(2.5)=3 
//floor���� ����ȡ�� floor(2.5)=2 


//����һ������Ϊn�����У���������а���С�����˳�����С�1<=n<=200
//�����ʽ,��һ��Ϊһ������n��
//�ڶ��а���n��������Ϊ�����������ÿ�������ľ���ֵС��10000��
//�����ʽ,���һ�У�����С�����˳��������������С�

#include <stdio.h>
#include <stdlib.h>
//��ӡ
void Print(int *data, int n)
{
	int i;
	for (i = 0; i<n; i++)
	{
		printf("%d ", data[i]);
	}
	printf("\n");
}

int Split(int *data, int pre, int rear)
{
	int value = data[pre];
	while (pre<rear)
	{
		while (data[rear] >= value && pre<rear) rear--;
		data[pre] = data[rear];
		while (data[pre]<value && pre<rear) pre++;
		data[rear] = data[pre];
	}
	data[pre] = value;
	return pre;
}

//��������
void QuickSort(int *data, int pre, int rear)
{
	if (pre<rear)
	{
		int mid = Split(data, pre, rear);
		QuickSort(data, pre, mid - 1);
		QuickSort(data,mid+1,rear);
	}
}

int main()
{
	int i;
	int n;
	int *data;
	scanf("%d",&n);
	data=(int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&data[i]);
	}
	QuickSort(data,0,n-1);
	Print(data,n);
	return 0;
}




#if 0
//2.С������λ�к���2��0��1��9�����ֺܸ���Ȥ��������ǰ��0����
//��1��40��������������1��2��9��10��32��39��40����28�������ǵĺ���574��
//���ʣ��� 1 �� n �У��������������ĺ��Ƕ��٣�
//����һ�а���һ������ n�����һ�У�����һ����������ʾ�������������ĺ͡�

int main()
{
	int n, i, sum = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; ++i)
	{
		int t = i, ok = 0;
		while (t > 0)
		{
			int g = t % 10;
			if (g == 2 || g == 0 || g == 1 || g == 9)
			{
				ok = 1;
			}
			t = t / 10;
		}
		if (ok)
		{
			sum += i;
		}
	}
	printf("%d", sum);
	return 0;
}

//1.�и����ÿ�δӾ�����������������Σ�֪��ʣ�µĶ���������Ϊֹ
#include<stdio.h>
int main()
{
	int m, n;
	scanf("%d%d", &m, &n);
	int count = 0;
	while (1)
	{
		if (m > n)//�г�һ��������
		{
			m -= n;//��ȥ�е��ĳ���
			count++;
		}
		else if (m < n)//�г�һ��������
		{
			n -= m;//��ȥ�е��ĳ���
			count++;
		}
		else
		{
			count++;//���ʱ�����ֻʣ�������Σ��޾���ʱ����ѭ��
			break;
		}
	}
	printf("%d\n", count);
}

#endif 