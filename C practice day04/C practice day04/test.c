#include<stdio.h>
#include<math.h>

//1.���0��999999֮������С�ˮ�ɻ������������
int main()
{
	int i = 0;
	for (i = 1; i <= 999999; i++)
	{
		//1����iΪ��λ��
		int tmp = i;
		int count = 0;
		int sum = 0;
		while (tmp != 0)
		{
			count++;
			tmp = tmp / 10;
		}
		tmp = i;
		while (tmp != 0)
		{
			sum += pow((double)(tmp % 10), (double)count);
			tmp = tmp / 10;
		}
		if (sum == i)
		{
			printf("%d ", i);
		}
	}
	printf("\n");
	return 0;
}
//2.��Sn = a + aa + aaa + aaaa + aaaaa��ǰn��֮�ͣ�����a��һ�����֣�
//���磺2 + 22 + 222 + 2222 + 22222
int main()
{
	int a = 0;
	int n = 0;
	int i = 0;
	int sum = 0;
	int tmp = 0;
	scanf("%d %d",&a,&n);
	for (i = 0; i < n; ++i)
	{
		tmp = tmp * 10 + a;
		sum += tmp;
	}
	printf("%d\n", sum);
	return 0;
}