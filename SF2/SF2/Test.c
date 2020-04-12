
//2.7
#include<stdio.h>
int main() {
	int i, j, k, m, c, e, f;
	int a[4] = { 2, 3, 5, 7 };
	//循环求此算式
	printf("题目中的乘式为：\n");
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			for (k = 0; k < 4; k++) {
				for (m = 0; m < 4; m++) {
					c = a[i] * 100 + a[j] * 10 + a[k];
					e = a[m];
					f = a[m] * 10;
					if (c*e == 2325) {
						printf("%d%d%d\n", a[i], a[j], a[k]);
						printf("x%d%d\n", a[m], a[m]);
						printf("-----\n");
						printf(" %d\n", c*e);
						printf("%d\n", c*e);
						printf("-----\n");
						printf("%d", c*e * 10 + c*e);

					}

				}
			}
		}
	}
	return 0;
}










/*
//2.6
#include<stdio.h>
#include<stdlib.h>
int ctn = 0;
int count(int i) //位数计算函数
{
	//判断循环退出条件
	if (i / 10 == 0) {
		return ctn + 1;
	}
	ctn++;
	//递归
	return count(i / 10);
}
void nxdisp(int i) //逆序输出函数
{
	//递归退出条件 
	if (i / 10 == 0) {
		printf("%d", i % 10);
		return;
	}
	printf("%d", i % 10);
	nxdisp(i / 10);
}
void sxdisp(int i)//顺序输出函数
{
	if (i / 10 != 0) {
		sxdisp(i / 10);
	}
	printf("%d", i % 10);
}

int main()
{
	int n;//存放输入的正整数
	//输入正整数
	printf("请输入一个正整数\n");
	scanf("%d", &n);
	printf("%d是%d位数\n", n, count(n));
	printf("逆序打印\n");
	nxdisp(n);
	printf("\n");
	printf("顺序打印\n");
	sxdisp(n);
}


//2.5
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int n, sum, m, num;//存放输入的正整数
	int len;
	int a[5];//用来存放逆序每个数字 
	printf("请输入一个五位以内的正整数\n");
	scanf("%d", &n); //获取键入的正整数
	len = 0;
	//用来记录原来输入的数字 
	m = n;
	while (n) {
		n /= 10;
		len++;
	}
	sum = 0;
	//用来记录输入数字的位数 
	num = len;
	n = m;
	while (len) {
		sum += n % 10 * pow(10, len - 1);
		n /= 10;
		len--;
	}
	printf("所输入的数字是一个%d位数\n", num);
	printf("按顺序输出为：\n%d\n", m);
	printf("按逆序输出为：\n%d\n", sum);
	return 0;
}
//2.4
#include<stdio.h>
//判断九位数字是否为每个数字都不相同·
int check(int a[], int n) {
	//设置标志位
	int flag = 1;
	int i = 4;
	int j;
	while (n) {
		a[i++] = n % 10;
		n /= 10;
	}
	for (i = 0; i < 9; i++) {
		for (j = i + 1; j < 9; j++) {
			if (a[i] == a[j]) {
				flag = 0;
				break;
			}
		}
	}
	return flag;
}
int main() {
	int i, j, k, m, n;
	int a[9];
	//进行计算
	for (i = 5; i <= 9; i++) {
		for (j = 0; j <= 9; j++) {
			//每位不同
			if (i != j) {
				for (k = 0; k <= 9; k++) {
					//每位不同
					if (k != i && k != j) {
						for (m = 0; m <= 9; m++) {
							//每位不同
							if (m != i && m != j && m != k) {
								n = i * 1000 + j * 100 + k * 10 + m;
								a[0] = i;
								a[1] = j;
								a[2] = k;
								a[3] = m;
								//判断结果是否为九位不相同的数字 
								if (check(a, 2 * n)) {
									printf("2*%d=%d\n", n, 2 * n);
								}
							}
						}
					}
				}
			}
		}
	}
	return 0;
}


//2.3
#include<stdio.h>
int main()
{
	long n; //存放键入的整数值
	int a[3] = { 4, 7, 9 };
	int flag[3];
	int i, k;
	k = 0;
	printf("请输入一个整数：");
	scanf("%ld", &n);//获取键入的整数值
	for (i = 0; i < 3; i++) {
		if (n%a[i] == 0) {
			flag[k++] = a[i];
		}
	}
	if (k == 1) {
		printf("这个数能被%d整除\n", flag[0]);
	}
	else {
		printf("这个数能同时被");
		for (i = 0; i < k - 1; i++) {
			printf("%d,", flag[i]);
		}
		printf("%d整除\n", flag[k - 1]);
	}
	return;
}

//2.2
#include<stdio.h>
#include<string.h>
#define MAX 100 
char s[MAX];
int len;
int isPalindrome(int i)  //回文判断函数
{
	//当判断完成后结束 
	if (len - 2 * i == 1 || len - 2 * i == 0) {
		return 1;
	}
	//当不满足回文数要求时退出循环 
	if (s[i] != s[len - 1 - i]) {
		return 0;
	}
	return isPalindrome(++i);
}
int main()//主函数
{
	int i;
	printf("输入一串字符以判断是否为回文。\n");
	//输入字符串 
	gets(s);
	//求字符串长度 
	len = strlen(s);
	if (isPalindrome(0)) {
		printf("输入的是回文。\n");
	}
	else {
		printf("输入的不是回文。\n");
	}
	return 0;
}
*/