
#include<stdio.h>


#if 0
//1.若变量a是 int 类型，并执行了语句 a=’A'+1.6 ；则正确的叙述是（ ）。
//A: a的值是字符C
//B : a的值是浮点型
//C : 不允许字符型和浮点型相加
//D : a的值是字符’A’的ASCⅡ值加上1
int main()
{
	int a;
	a = 'A' + 1.6;
	printf("%d\n", a);
	return 0;
}

//'A'为char型，1.6为double型
//运算过程中转化为高类型，即double类型。
//在赋值运算中，赋值号两边量的数据类型不同时，赋值号右边量的类型将转换为左边量的类型。
//如果右边量的数据类型长度比左边长时，将丢失一部分数据，这样会降低精度。


int main()
{
	int x = 10;
	int y = 10;
	x = y = ++y;
	printf("%d %d", x, y);
	return 0;
}
///给定一个数组 nums 和一个值 val，你需要原地移除所有数值等于 val 的元素，返回移除后数组的新长度。

//不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
//元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
int removeElement(int* nums, int numsSize, int val)
{
	//count记录不等于val的个数
	int count = 0;
	for (int i = 0; i<numsSize; i++)
	{
		if (nums[i] != val)
		{
			nums[count] = nums[i];
			count++;
		}
	}
	return count;
}
#endif
