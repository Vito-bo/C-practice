
#include<stdio.h>
#include<stdlib.h>

#if 0
//malloc ��̬�ڴ濪��
int main()
{
	//����1
	int num = 0;
	scanf("%d", &num);
	int arr[num] = { 0 };
	//����2
	int* ptr = NULL;
	ptr = (int*)malloc(num*sizeof(int));
	if (NULL != ptr)//�ж�ptrָ���Ƿ�Ϊ��
	{
		int i = 0;
		for (i = 0; i<num; i++)
		{
			*(ptr + i) = 0;
		}
	}
	free(ptr);//�ͷ�ptr��ָ��Ķ�̬�ڴ�
	ptr = NULL;
	return 0;
}
#endif

int main()
{
	int *p = calloc(10, sizeof(int));
	if (NULL != p)
	{
		//ʹ�ÿռ�
	}
	free(p);
	p = NULL;
	return 0;
}