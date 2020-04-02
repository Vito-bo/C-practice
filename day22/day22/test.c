
#include <stdio.h>


char FindOnceChar(char* str)
{
	int arr[256] = { 0 };
	//1.�����ַ�����ͳ��ÿ���ַ����ֵĴ���
	char* p = str;
	while (*p != '\0')
	{
		arr[*p]++;
		p++;
	}
	//2.���ҵ�һ������һ�ε��ַ�
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
//���һ�������ۼ�arr[i]����֮ǰ��һ���������϶���С��x��
//���һ�������ۼ�x,��֮ǰ��һ���������϶��Ǵ���x��
//Ҫ���Ǻ�������ÿ���ۼӵ�������־���һ������
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
		//�ұ��ұ�tmpС������
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
		//����ұ�tmp�������
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
	int index = Partion(arr, start, end);//ʹ����һ����Ŀ��Partion����
	if (arr == NULL || len < 0)
	{
		return 0;//�������鵱�в��������0
	} 
	while(index != mid)
	{
			if (index > mid)
			{//˵���������
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
		//�������ݵ��� ����һֱ��Ϊ �������λ������������Ҫ�ҵ�����
		//���� ����һ�����鵱��Ƶ����ߵ����� ������λ�� ���Եõ����result
		//֮�� ���ǻ���Ҫ�ж�һ��������ֳ��ֵ�Ƶ���Ƿ�Ϊ�������ȵ�һ��
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