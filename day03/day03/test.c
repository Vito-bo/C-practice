#include<stdio.h>
int main()
{
	int i=0,a=0;
	while(i<20)
	{
		for(;;)
		{
			if((i%10)==0) break;
			else i--;
		} 
		i+= 11; a += i;
	}
	printf("%d\n",a); // 32
	return 0;
}

#if 0
//力扣-189 旋转数组
void rotate(int* nums, int numsSize, int k)
{
	k = k%numsSize;
	reverse(nums, 0, numsSize - 1);
	reverse(nums, 0, k - 1);
	reverse(nums, k, numsSize - 1);
}
void reverse(int* nums, int left, int right)
{
	int mid = (left + right) / 2;
	for (int i = right; i>mid; i--)
	{
		int temp = nums[i];
		nums[i] = nums[left + right - i];
		nums[left + right - i] = temp;
	}
}
//力扣-35 搜索插入位置
//方法1
int searchInsert(int* nums, int numsSize, int target)
{
	if (target < nums[0])
		return 0;
	if (target > nums[numsSize - 1])
		return numsSize;
	int i;
	for (i = 0; i < numsSize; i++)
	{
		if (nums[i] == target)
			return i;
		if (nums[i] < target && target < nums[i + 1])
			return i + 1;
	}
	return i;
}
//方法2
int searchInsert(int* nums, int numsSize, int target){
	for (int i = 0; i<numsSize; i++)
	{
		if (target <= nums[i])
			return i;
	}
	return numsSize;
#endif