#include<stdio.h>

//存放需要打印的数据 
int arr[8][8] = { 0 };
int main()
{
	int i = 1, j = 1;//数组的行和列 
	int num = 1; // 需要存放的数 
	//循环结束的条件是下一步存在数据 
	while (!arr[i][j])
	{
		//向右打印
		while (j < 8 && !arr[i][j])
			arr[i][j++] = num++;

		//下一步向下打印的位置 
		i++;
		j--;

		//向下打印
		while (i < 8 && !arr[i][j])
			arr[i++][j] = num++;

		//下一步向左打印的位置
		i--;
		j--;

		//向左打印
		while (j > 0 && !arr[i][j])
			arr[i][j--] = num++;

		//下一步向上打印的位置 
		i--;
		j++;

		//向上打印
		while (i > 0 && !arr[i][j])
			arr[i--][j] = num++;

		//下一步向左打印的位置 
		i++;
		j++;
	}

	for (i = 1; i <= 7; i++)
	{
		for (j = 1; j <= 7; j++)
			printf("%2d ", arr[i][j]);
		printf("\n");
	}
	return 0;
}

#include <stdio.h>
int main()
{
	int n;//键盘输入阶乘的范围
	printf("请输入一个数n(1000<n<10000):\n");
	scanf("%d", &n);

	int div = 5; //除数 
	int count = 0; //表示末尾0的数目

	while (div <= n)
	{
		count += n / div;
		div *= 5;
	}

	printf("该相乘数字末尾有%d个0\n", count);
	return 0;
}


#include <stdio.h>

int arr[6] = { 0 };//1--A 2--B 3--C 4--D 5--E
int visit[6] = { 0 };//判断该名词有没有被选择 

void slove()
{
	int a = (arr[2] == 3) + (arr[3] == 5);
	int b = (arr[4] == 3) + (arr[5] == 4);
	int c = (arr[2] == 1) + (arr[5] == 4);
	int d = (arr[3] == 1) + (arr[2] == 2);
	int e = (arr[4] == 2) + (arr[1] == 3);

	if (a != 1 || b != 1 || c != 1 || d != 1 || e != 1)
	{
		return;
	}

	//走到这里就是符合的情况
	char src = 'A';
	int i = 0;
	while (i < 5)
	{
		printf("%c是第%d名\n", src, arr[i + 1]);
		src++;
		i++;
	}
}

void dfs(int index)
{
	if (index == 6)
	{
		slove();
		return;
	}
	int i = 1;
	for (i = 1; i <= 5; i++)
	{
		if (!visit[i])
		{
			visit[i] = 1;
			arr[index] = i;
			dfs(index + 1);
			visit[i] = 0;
		}
	}
}
int main()
{
	//深搜遍历五种情况 
	dfs(1);
}


int main()
{
	int i = 10;

	while (i*i < 1000)
	{
		int num = i * i;
		int arr[10] = { 0 };//记录每一位的数字出现的次数

		while (num)
		{
			int j = num % 10;
			arr[j]++;

			if (arr[j] > 1)
			{
				printf("%d ", i*i);
				break;
			}
			num /= 10;
		}
		i++;
	}
	printf("\n");
	return 0;
}

// 前K个最小的数
// 一次划分的函数
// left=0, right=len-1
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
void PreKNum(int* arr, int len, int k)
{
	int left = 0;
	int right = len - 1;
	int par = Partion(arr, left, right);
	int i = 0;
	while (par != k - 1)
	{
		if (par > k - 1)
		{
			right = par - 1;
			par = Partion(arr, left, right);
		}
		else
		{
			left = par + 1;
			par = Partion(arr, left, right);
		}
	}
	for (i = 0; i < k; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main()
{
	int arr[] = { 12, 3, 5, 1, 0, 7, 14, 8, 6 };
	int len = sizeof(arr) / sizeof(arr[0]);
	PreKNum(arr, len, 5);
	return 0;
}
