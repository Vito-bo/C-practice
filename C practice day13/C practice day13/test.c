#include<stdio.h>
#include<assert.h>

//1.һ��������ֻ�����������ǳ���һ�Σ�
//�����������ֶ����������Ρ�
//�ҳ�������ֻ����һ�ε����֣����ʵ�֡�
//void print_once_num(int* a, int n)
//{
//	assert(a);
//	int ret = 0;
//	for (int i = 0; i < n; i++)
//	{
//		ret ^= a[i];
//	}
//	//ret����ֻ����һ�ε����������Ľ��
//	int pos = 0;
//	for (; pos < 32; ++pos)
//	{
//		if (ret & (1 << pos))
//		{
//			break;
//		}
//	}
//	//ret�ĵ�posλΪ1
//	int ret0 = 0, ret1 = 0;
//	for (int i = 0; i < n; ++i)
//	{
//		if (a[i] & (1 << pos))
//		{
//			ret1 ^= a[i];
//		}
//		else
//		{
//			ret0 ^= a[i];
//		}
//	}
//	printf("%d,%d\n", ret0, ret1);
//}
//int main()
//{
//	int  a[] = { 2, 3, 4, 2, 5, 4, 5, 6 };
//	int len = sizeof(a) / sizeof(a[0]);
//	print_once_num(a, len);
//	return 0;
//}

//2.����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ��
//��20Ԫ�����Ժȶ�����ˮ��
//���ʵ�֡�



int main()
{
	int total = 0;//�ܹ�����ˮ��
	int money = 20;//�����е�Ǯ
	int empty = 0;//��ƿ�ӵ�����
	//scanf("%d", &money);

	//��ʼ����ˮ
	total = money;//���˶���ƿ
	empty = money;//��ƿ��
	while (empty > 1)
	{
		//����ˮ 
		total += empty / 2;
		//����ʣ�µĿ�ƿ������
		empty = empty / 2 + empty % 2;
	}
	printf("����ˮ��Ϊ��%d\n", total);
	return 0;
}