#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#include<assert.h>

/*
//1.ʵ��һ�����������������ַ����е�k���ַ���
//ABCD����һ���ַ��õ�BCDA
//ABCD���������ַ��õ�CDAB

//�����ַ���
//���磺����s1 = AABCD��s2 = BCDAA������1
//����s1 = abcd��s2 = ACBD������0.
//AABCD����һ���ַ��õ�ABCDA
//AABCD���������ַ��õ�BCDAA
//AABCD����һ���ַ��õ�DAABC

int is_rotate_str(char* str, char* rt_str)
{
	int len = strlen(str);
	char* double_str = (char*)malloc(len * 2 + 1);
	strcpy(double_str, str);
	strcat(double_str, str);
	/*if (strstr(double_str, rt_str) != NULL)
	{
		free(double_str);
		return 1;
	}
	else
	{
		free(double_str);

		return 0;
	}
	*/
	int ret = strstr(double_str, rt_str) == NULL ? 0 : 1;
	free(double_str);
	return ret;
}
int main()
{
	printf("%d\n", is_rotate_str("AABCD", "BCDAA"));
	return 0;
}