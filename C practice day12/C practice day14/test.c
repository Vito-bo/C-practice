#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#include<assert.h>

/*
//1.ʵ��һ�����������������ַ����е�k���ַ���
//ABCD����һ���ַ��õ�BCDA
//ABCD���������ַ��õ�CDAB

//�����ַ���char* rotate_left(char* str, int k){	assert(str);	while (k--)	{		char tmp = *str;		char* cur = str;		while (*(cur + 1) != '\0')		{			*cur = *(cur + 1);			++cur;		}		*cur = tmp;	}	return str;}int main(){	char a[] = "ABCDE";	printf("%s\n", a);	rotate_left(a, 4);	printf("%s\n", a);	return 0;}//����˼·//�����ַ�void* reverse_str(char* left, char* right){	while (left < right)	{		char tmp = *left;		*left = *right;		*right = tmp;		++left;		--right;	}}void rotate_left(char* str, int k){	assert(str);	int len = strlen(str);	//k  len-k	//[o,k-1] [k,len-1]	reverse_str(str, str + k - 1);	reverse_str(str + k, str + len - 1);	reverse_str(str, str + len - 1);	return str;}int main(){	char a[] = "ABCDEF";	printf("%s\n", a);	rotate_left(a, 3);	printf("%s\n", a);	return 0;}*///2.�ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
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
