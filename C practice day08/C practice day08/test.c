#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//指针和数组面试题
int main()
{

	/*
	//一维数组
	int a[] = { 1, 2, 3, 4 };
	printf("%d\n", sizeof(a)); //16
	//sizeof(a)中，a代表整个数组
	printf("%d\n", sizeof(a+0));//4
	//a+0已经发生运算，代表a[0]的地址
	printf("%d\n", sizeof(*a)); //4
	//*a数组名代表数组首元素的地址，解引用代表元素1的字节大小
	printf("%d\n", sizeof(a + 1));//4
	//代表数据2的地址
	printf("%d\n", sizeof(a[1])); //4 
	//a[]代表数据2的地址
	printf("%d\n", sizeof(&a));//4
	//数组首元素的地址
	printf("%d\n", sizeof(*&a));//16   
	// &a代表整个数组的地址，解引用后代表整个数组的字节大小
	printf("%d\n", sizeof(&a + 1));//4
	//4后面元素的地址
	printf("%d\n", sizeof(&a[0]));//4  
	//数组首元素的地址
	printf("%d\n", sizeof(&a[0] + 1));//4
	//数据2 的地址

	字符数组 
	char arr[] = {'a','b','c','d','e','f'}; 
	printf("%d\n", sizeof(arr));//6 
	//整个数组的大小
	printf("%d\n", sizeof(arr+0));//4
	//字符'a'的地址
	printf("%d\n", sizeof(*arr));//1
	//字符'a'的大小
	printf("%d\n", sizeof(arr[1]));//1 
	//字符'b'的大小
	printf("%d\n", sizeof(&arr));//4 
	printf("%d\n", sizeof(&arr+1));//4 
	printf("%d\n", sizeof(&arr[0]+1));//4

	char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	printf("%d\n", strlen(arr));//随机值
	arr代表数组名，代表数组首元素地址。
	strlen是函数，只能以char*(字符串)做参数。而且要想得到的结果正确必须包含‘\0’
	printf("%d\n", strlen(arr + 0));//随机值 
	printf("%d\n", strlen(*arr));//语法错误   char*
	printf("%d\n", strlen(arr[1]));// 语法错误
	printf("%d\n", strlen(&arr)); //语法错误     数组指针
	printf("%d\n", strlen(&arr + 1));//语法错误  数组指针
	printf("%d\n", strlen(&arr[0] + 1));//随机值-1
	strlen 求字符串长度
	*/

	char arr[] = "abcdef"; 
	printf("%d\n", sizeof(arr));//7
	//sizeof计算的是分配空间的实际字节数。字符串默认有\0
	printf("%d\n", sizeof(arr + 0));//4
	//字符'a'的地址，存地址的指针变量大小是4
	printf("%d\n", sizeof(*arr));//1 
	//*arr代表字符'a'
	printf("%d\n", sizeof(arr[1])); //1
	//代表字符'b'
	printf("%d\n", sizeof(&arr));//4
	printf("%d\n", sizeof(&arr + 1));//4 
	printf("%d\n", sizeof(&arr[0] + 1));//4
	
	char arr[] = "abcdef";
	printf("%d\n", strlen(arr)); //6
	printf("%d\n", strlen(arr + 0)); //6
	//printf("%d\n", strlen(*arr)); //语法错误
	//printf("%d\n", strlen(arr[1]));//语法错误
	//printf("%d\n", strlen(&arr));// 语法错误
	//printf("%d\n", strlen(&arr + 1)); //语法错误
	printf("%d\n", strlen(&arr[0] + 1));//5
	
	

	return 0;
}
