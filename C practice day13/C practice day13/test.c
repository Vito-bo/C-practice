#include<stdio.h>
#include<assert.h>

//1.一个数组中只有两个数字是出现一次，
//其他所有数字都出现了两次。
//找出这两个只出现一次的数字，编程实现。
//void print_once_num(int* a, int n)
//{
//	assert(a);
//	int ret = 0;
//	for (int i = 0; i < n; i++)
//	{
//		ret ^= a[i];
//	}
//	//ret就是只出现一次的那两个异或的结果
//	int pos = 0;
//	for (; pos < 32; ++pos)
//	{
//		if (ret & (1 << pos))
//		{
//			break;
//		}
//	}
//	//ret的第pos位为1
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

//2.喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，
//给20元，可以喝多少汽水。
//编程实现。



int main()
{
	int total = 0;//总共喝汽水数
	int money = 20;//手里有的钱
	int empty = 0;//空瓶子的数量
	//scanf("%d", &money);

	//开始买汽水
	total = money;//喝了多少瓶
	empty = money;//空瓶数
	while (empty > 1)
	{
		//换汽水 
		total += empty / 2;
		//计算剩下的空瓶子数量
		empty = empty / 2 + empty % 2;
	}
	printf("喝汽水数为：%d\n", total);
	return 0;
}