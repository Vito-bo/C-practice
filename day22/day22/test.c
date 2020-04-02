
#include <stdio.h>


char FindOnceChar(char* str)
{
	int arr[256] = { 0 };
	//1.遍历字符串，统计每个字符出现的次数
	char* p = str;
	while (*p != '\0')
	{
		arr[*p]++;
		p++;
	}
	//2.查找第一个出现一次的字符
	p = str;
	while (*p != '\0')
	{
		if (arr[*p] == 1)
			return *p;
		p++;
	}
	return '\0';
}

int main()
{
	printf("%c\n", FindOnceChar("bacccadcb"));
	return 0;
}


/*
//如果一个数字累加arr[i]，加之前是一个负数，肯定是小于x的
//如果一个数字累加x,加之前是一个正数，肯定是大于x的
//要的是和最大，如果每次累加的这个数字就是一个最大的
int MaxArray(int* arr, int len)
{
	int max = arr[0];
	int sum = arr[0];
	int i = 1;
	for (i = 1; i < len; i++)
	{
		if (sum < 0)
		{
			sum = arr[i];
		}
		else
		{
			sum += arr[i];
		}
		if (sum>max)
		{
			max = sum;
		}
	}
	return max;
}

int main()
{
	int arr[] = { -18, -2, -3, -10, -4,-7, -2, -5 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int ret = MaxArray(arr, len);
	printf("%d\n", ret);

	return 0;
}

int Partion(int arr[], int left, int right)
{
	int tmp = arr[left];
	while (left < right)
	{
		//右边找比tmp小的数据
		while (left < right && arr[right] > tmp)
		{
			right--;
		}
		if (left >= right)
		{
			//arr[left] = tmp;
			break;
		}
		else
		{
			arr[left] = arr[right];
		}
		//左边找比tmp大的数据
		while (left < right && arr[left] < tmp)
		{
			left++;
		}
		if (left >= right)
		{
			//arr[left] = tmp;
			break;
		}
		else
		{
			arr[right] = arr[left];
		}
	}
	arr[left] = tmp;
	return left;
}

int arrayLenHalfNum(int* arr, int len)
{
	int mid = len >> 1;
	int start = 0;
	int end = len - 1;
	int result = 0;
	int index = Partion(arr, start, end);//使用上一个题目的Partion函数
	if (arr == NULL || len < 0)
	{
		return 0;//假设数组当中不存放数字0
	} 
	while(index != mid)
	{
			if (index > mid)
			{//说明在左边找
				end = index - 1;
				index = Partion(arr, start, end);
			} 
			else
			{
				start = index + 1;
				index = Partion(arr, start, end);
			}
		} 
	    result = arr[mid];
		//以上数据当中 我们一直认为 数组的中位数就是我们需要找的数字
		//但是 并不一定数组当中频率最高的数字 就是中位数 所以得到这个result
		//之后 我们还需要判断一下这个数字出现的频率是否为整个长度的一半
		if (!checkIsMoreThanHalf(arr, len,result))
		{
			result = 0;
		}
		return result;
} 
int checkIsMoreThanHalf(int *arr, int len, int num)
{
	int count = 0;
	int i = 0;
	for (i = 0; i < len; i++)
	{
		if (arr[i] == num)
		{
			count++;
		}
	} 
	if(count * 2 <= len)
	{
			return 0;
	}
	return 1;
}

int main()
{
	int arr[] = { 1, 2, 3, 2, 2, 2, 5, 4, 2 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int ret = arrayLenHalfNum(arr, len);
	printf("%d\n",ret);
	return 0;
}

int main()
{
	int s = 0, n;
	for (n = 0; n < 4; n++)
	{
		switch (n)
		{
		default:s += 4;
		case 1:s += 1;
		case 2:s += 2;
		case 3:s += 3;
		}
	}
	printf("%d\n", s);
	return 0;
}
*/