
#include<stdio.h>
#include<string.h>
#if 0
//day04 宏替换
#define N 2
#define M N+1
#define NUM (M+1)*M/2
int main()
{
	printf("%d\n", NUM);
}

//合并有序数组
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
	for (int i = 0; i<n; i++)
	{
		int j = m - 1;
		for (; j >= 0; j--)
		{
			if (nums2[i]<nums1[j])
			{
				nums1[j + 1] = nums1[j];
			}
			else
			{
				break;
			}
		}
		nums1[j + 1] = nums2[i];
		m++;
	}
}
#endif
int main()
{
	char* s = "hello world";
	int len = strlen(s);
	printf("%d\n", len);
	return 0;
}
//力扣-最后一个单词的长度
int lengthOfLastWord(char * s)
{
	int len = strlen(s);
	if (len == 0)
		return 0;
	int i = len - 1;
	while (i >= 0 && s[i] == ' ')
	{
		i--;
	}

	len = i;
	while (i >= 0 && s[i] != ' ')
		i--;
	return len - i;
}