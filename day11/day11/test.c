

#include <stdio.h>
#include <string.h>

#if 0
int main()
{
	char s[] = "abcdefgh", *p = s;
	p += 3;
	printf("%d\n", strlen(strcpy(p, "ABCD")));//4
	return 0;
}


int func(int i, int j)
{
	if (i <= 0 || j <= 0)
		return 1;
	return 2 * func(i - 3, j / 2);
}
int main()
{
	int ret = func(15, 20);
	printf("%d\n", ret);//32
	return 0;
}

int main()
{
	int a[] = { 2, 4, 6, 8 }, *p = a, i;
	for (i = 0; i<4; i++)
		a[i] = *p++;
	printf("%d\n", a[2]);//6
	return 0;
}


int main()
{
	int a = 1; int b = 2;
	for (; a<8; a++)
	{
		b += a; 
		a += 2;
	}
	printf("%d，%d\n", a, b);//10,14
	return 0;
}

//力扣9-回文数
bool isPalindrome(int x)
{
	int t;
	long y = 0;
	int begin = x;
	if (x<0)
	{
		return false;
	}
	else
	{
		while (x != 0)
		{
			t = x % 10;
			x = x / 10;
			y = t + y * 10;
		}
		if (begin == y)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}
#endif
//力扣383-赎金信
bool canConstruct(char * ransomNote, char * magazine){
	int i = 0;
	int a = strlen(ransomNote);
	int* p = (int*)calloc(sizeof(int), a);
	for (i; ransomNote[i] != '\0'; i++)
	{
		for (int j = 0; magazine[j] != '\0'; j++)
		{
			if (ransomNote[i] == magazine[j])
			{
				magazine[j] = ' ';
				p[i] = 1;
				break;
			}
		}
	}
	for (int i = 0; i<a; i++)
	{
		if (p[i] == 0)
			return false;
	}
	return true;
}
//力扣-217存在重复元素
int compare(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}
bool containsDuplicate(int* nums, int numsSize)
{
	qsort(nums, numsSize, sizeof(int), compare);
	for (int i = 0; i < numsSize - 1; i++)
	{
		if (nums[i] == nums[i + 1])
		{
			return true;
		}
	}
	return false;
}

