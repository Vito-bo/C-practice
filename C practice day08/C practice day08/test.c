#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//ָ�������������
int main()
{

	/*
	//һά����
	int a[] = { 1, 2, 3, 4 };
	printf("%d\n", sizeof(a)); //16
	//sizeof(a)�У�a������������
	printf("%d\n", sizeof(a+0));//4
	//a+0�Ѿ��������㣬����a[0]�ĵ�ַ
	printf("%d\n", sizeof(*a)); //4
	//*a����������������Ԫ�صĵ�ַ�������ô���Ԫ��1���ֽڴ�С
	printf("%d\n", sizeof(a + 1));//4
	//��������2�ĵ�ַ
	printf("%d\n", sizeof(a[1])); //4 
	//a[]��������2�ĵ�ַ
	printf("%d\n", sizeof(&a));//4
	//������Ԫ�صĵ�ַ
	printf("%d\n", sizeof(*&a));//16   
	// &a������������ĵ�ַ�������ú��������������ֽڴ�С
	printf("%d\n", sizeof(&a + 1));//4
	//4����Ԫ�صĵ�ַ
	printf("%d\n", sizeof(&a[0]));//4  
	//������Ԫ�صĵ�ַ
	printf("%d\n", sizeof(&a[0] + 1));//4
	//����2 �ĵ�ַ

	�ַ����� 
	char arr[] = {'a','b','c','d','e','f'}; 
	printf("%d\n", sizeof(arr));//6 
	//��������Ĵ�С
	printf("%d\n", sizeof(arr+0));//4
	//�ַ�'a'�ĵ�ַ
	printf("%d\n", sizeof(*arr));//1
	//�ַ�'a'�Ĵ�С
	printf("%d\n", sizeof(arr[1]));//1 
	//�ַ�'b'�Ĵ�С
	printf("%d\n", sizeof(&arr));//4 
	printf("%d\n", sizeof(&arr+1));//4 
	printf("%d\n", sizeof(&arr[0]+1));//4

	char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	printf("%d\n", strlen(arr));//���ֵ
	arr����������������������Ԫ�ص�ַ��
	strlen�Ǻ�����ֻ����char*(�ַ���)������������Ҫ��õ��Ľ����ȷ���������\0��
	printf("%d\n", strlen(arr + 0));//���ֵ 
	printf("%d\n", strlen(*arr));//�﷨����   char*
	printf("%d\n", strlen(arr[1]));// �﷨����
	printf("%d\n", strlen(&arr)); //�﷨����     ����ָ��
	printf("%d\n", strlen(&arr + 1));//�﷨����  ����ָ��
	printf("%d\n", strlen(&arr[0] + 1));//���ֵ-1
	strlen ���ַ�������
	*/

	char arr[] = "abcdef"; 
	printf("%d\n", sizeof(arr));//7
	//sizeof������Ƿ���ռ��ʵ���ֽ������ַ���Ĭ����\0
	printf("%d\n", sizeof(arr + 0));//4
	//�ַ�'a'�ĵ�ַ�����ַ��ָ�������С��4
	printf("%d\n", sizeof(*arr));//1 
	//*arr�����ַ�'a'
	printf("%d\n", sizeof(arr[1])); //1
	//�����ַ�'b'
	printf("%d\n", sizeof(&arr));//4
	printf("%d\n", sizeof(&arr + 1));//4 
	printf("%d\n", sizeof(&arr[0] + 1));//4
	
	char arr[] = "abcdef";
	printf("%d\n", strlen(arr)); //6
	printf("%d\n", strlen(arr + 0)); //6
	//printf("%d\n", strlen(*arr)); //�﷨����
	//printf("%d\n", strlen(arr[1]));//�﷨����
	//printf("%d\n", strlen(&arr));// �﷨����
	//printf("%d\n", strlen(&arr + 1)); //�﷨����
	printf("%d\n", strlen(&arr[0] + 1));//5
	
	

	return 0;
}
