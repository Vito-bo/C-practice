
#include <stdio.h>

#if 0
//����905-����ż��������
int* sortArrayByParity(int* A, int ASize, int* returnSize)
{
	int* B = (int*)malloc(ASize*sizeof(int));
	int i = 0;
	int j = 0;
	for (i = 0; i<ASize; i++)
	{
		if (A[i] % 2 == 0)
		{
			B[j] = A[i];
			j++;
		}
	}
	for (i = 0; i<ASize; i++)
	{
		if (A[i] % 2 == 1)
		{
			B[j] = A[i];
			j++;
		}
	}
	*returnSize = ASize;
	return B;
}

//����724-Ѱ���������������
int pivotIndex(int* nums, int numsSize){
	if (numsSize<3)
		return -1;
	int i, left_sum = 0, right_sum = 0;
	for (i = 1; i<numsSize; i++)
	{
		right_sum = right_sum + nums[i];
	}
	if (right_sum == 0)
		return 0;
	for (i = 1; i<numsSize; i++)
	{
		left_sum = left_sum + nums[i - 1];
		right_sum = right_sum - nums[i];
		if (left_sum == right_sum)
			return i;
	}
	return -1;
}
#endif 
