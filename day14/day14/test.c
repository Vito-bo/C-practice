#include <stdio.h>
#include <stdlib.h>

#if 0
//力扣66-加一
int* plusOne(int* digits, int digitsSize, int* returnSize)
{
	//从后向前循环
	for (int i = digitsSize - 1; i >= 0; i--)
	{
		if (digits[i] < 9)
		{
			digits[i]++;
			*returnSize = digitsSize;
			return digits;
		}
		digits[i] = 0;
	}
	int* result = (int*)malloc(sizeof(int)*(digitsSize + 1));
	result[0] = 1;
	for (int i = 1; i < (digitsSize + 1); i++)
	{
		result[i] = 0;
	}
	*returnSize = digitsSize++;
	return result;
}


//力扣414-第三大数
//先从大到小排序，然后原地去除重复的数字
//如果剩余大于等于3个，那么返回第3个。否则返回i第一个（最大的）
int cmp(const void* a, const void* b)
{
	return *(int*)a < *(int*)b;
}
int thirdMax(int* nums, int numSize)
{
	int i, j;
	int last;
	qsort(nums, numSize, sizeof(int), cmp);
	last = nums[0];
	for (i = 1, j = 1; i < numSize; i++)
	{
		if (last == nums[i])
		{
			continue;
		}
		last = nums[i];
		nums[j++] = last;
	}
	return j < 3 ? nums[0] : nums[2];
}


//力扣1-两数之和
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
	int i = 0, j;
	int *result_nums;
	for (; i<numsSize; i++)
	{
		for (j = i + 1; j<numsSize; j++)
		{
			if ((nums[i] + nums[j]) == target)
			{
				*returnSize = 2;
				result_nums = (int*)malloc(sizeof(int)* 2);
				result_nums[0] = i;
				result_nums[1] = j;
				return result_nums;
			}
		}
	}
	return 0;
}
#endif

//力扣67-二进制求和
char * addBinary(char * a, char * b){
	int alen = strlen(a);
	int blen = strlen(b);
	if (alen == 0)
	{
		return b;
	}
	if (blen == 0)
	{
		return a;
	}
	int len = (alen > blen ? alen + 1 : blen + 1);
	char *result = (char *)malloc(sizeof(char)* (len + 1));
	char ma[len + 1];
	char mb[len + 1];
	//初始化数组
	memset(result, '0', sizeof(char)* (len + 1));

	//将a和b倒序，方便进位
	for (int i = 0; i < alen / 2; i++)
	{
		char tmp = a[i];
		a[i] = a[alen - 1 - i];
		a[alen - 1 - i] = tmp;
	}
	for (int i = 0; i < blen / 2; i++)
	{
		char tmp = b[i];
		b[i] = b[blen - 1 - i];
		b[blen - 1 - i] = tmp;
	}
	for (int i = 0; i < len; i++)
	{
		if (i < alen) {
			ma[i] = a[i];
		}
		else {
			ma[i] = '0';
		}
	}
	for (int i = 0; i < len; i++)
	{
		if (i < blen)
		{
			mb[i] = b[i];
		}
		else
		{
			mb[i] = '0';
		}
	}
	//开始相加
	for (int i = 0; i < len; i++)
	{
		if (ma[i] == '0' && mb[i] == '0')
		{
			if (result[i] == '0')
			{
				result[i] = '0';
			}
			else
			{
				result[i] = '1';
			}
		}
		if (ma[i] == '0' && mb[i] == '1')
		{
			if (result[i] == '0')
			{
				result[i] = '1';
			}
			else
			{
				result[i] = '0';
				result[i + 1] = result[i + 1] + 1;
			}
		}
		if (ma[i] == '1' && mb[i] == '0')
		{
			if (result[i] == '0')
			{
				result[i] = '1';
			}
			else
			{
				result[i] = '0';
				result[i + 1] = result[i + 1] + 1;
			}
		}
		if (ma[i] == '1' && mb[i] == '1')
		{
			if (result[i] == '0')
			{
				result[i] = '0';
				result[i + 1] = result[i + 1] + 1;
			}
			else
			{
				result[i] = '1';
				result[i + 1] = result[i + 1] + 1;
			}
		}
	}
	//确定实际长度
	if (result[len - 1] == '1')
	{
		len = len;
	}
	else
	{
		len = len - 1;
	}
	//结果倒回去
	for (int i = 0; i < len / 2; i++)
	{
		char tmp = result[i];
		result[i] = result[len - 1 - i];
		result[len - 1 - i] = tmp;
	}
	result[len] = '\0';
	return result;
}