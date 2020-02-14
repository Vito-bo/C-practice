
#include<stdio.h>
#include<stdlib.h>

#if 0
//malloc 动态内存开辟
int main()
{
	//代码1
	int num = 0;
	scanf("%d", &num);
	int arr[num] = { 0 };
	//代码2
	int* ptr = NULL;
	ptr = (int*)malloc(num*sizeof(int));
	if (NULL != ptr)//判断ptr指针是否为空
	{
		int i = 0;
		for (i = 0; i<num; i++)
		{
			*(ptr + i) = 0;
		}
	}
	free(ptr);//释放ptr所指向的动态内存
	ptr = NULL;
	return 0;
}
#endif

int main()
{
	int *p = calloc(10, sizeof(int));
	if (NULL != p)
	{
		//使用空间
	}
	free(p);
	p = NULL;
	return 0;
}