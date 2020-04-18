

/*
#include <stdio.h> 
#include <math.h>

int board[100][100] = { 0 };//棋盘 
int count = 1;//依次处理方格的顺序 
int dis[4][2] = { { 0, 0 }, { 0, 1 }, { 1, 0 }, { 1, 1 } };//本身，右，下，右下角三个位置 

void show(int size)
{
	int i = 1, j = 1;
	for (i = 1; i <= size; i++)
	{
		for (j = 1; j <= size; j++)
			printf("%2d ", board[i][j]);
		printf("\n");
	}
}

void Cover(int tx, int ty, int x, int y, int size)
{
	int num = 0;
	int i = 1;
	int row = 0, col = 0;
	int r = 0, c = 0;
	//处理只有一个格子的情况 
	if (size < 2)
		return;

	size /= 2;
	num = count++;
	for (i = 0; i < 4; i++)
	{
		//分成四个方块，row,col分别为四个方块的左上角位置 
		row = dis[i][0] * size + tx;
		col = dis[i][1] * size + ty;

		//如果缺少的格子不在当前范围，就把新加的残缺格补上 
		if (!(x >= row && x < (row + size) && \
			y >= col && y < (col + size)))
		{
			//r,c 为新加的残缺格位置 
			r = dis[3 - i][0] * (size - 1) + row;
			c = dis[3 - i][1] * (size - 1) + col;
			board[r][c] = num;
			Cover(row, col, r, c, size);
		}
		else
			Cover(row, col, x, y, size);
	}
}

int main()
{
	int k = 3;
	int x, y;//残缺格的位置
	int size = pow(2, k);//棋盘的行数


	//cout<<size; 


	x = 1, y = 1;
	board[x][y] = 0;

	Cover(1, 1, x, y, size);

	show(size);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int start;
	int end;
	int num;
}node;

node list[20] = { { 0 }, { 1, 3, 1 }, { 2, 4, 2 }, { 0, 5, 3 }, { 5, 7, 4 }, { 3, 8, 5 }, { 5, 9, 6 }, \
{6, 10, 7}, { 8, 11, 8 }, { 8, 12, 9 }, { 2, 13, 10 }, { 12, 14, 11 }, { 15, 18, 12 } };


int node_cmp(const void* a, const void* b)
{
	node* c = (node*)a;
	node* d = (node*)b;
	if (c->end != d->end)
		return c->end - d->end;
	return c->start - d->start;
}

int main()
{
	int i, j, k;
	int left = 1, right = 1;
	int n = 12;
	int num = 0;


	//排序
	qsort(list, n, sizeof(node), node_cmp);

	while (right <= n)
	{
		if (right == 1 || list[left].end < list[right].start)
		{
			left = right;
			printf("第%d个活动被安排:%d开始,%d结束.\n", \
				list[left].num, list[left].start, list[left].end);

			num++;
		}
		right++;
	}
	printf("总计%d个活动被安排\n", num);
	return 0;
}


#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int start;
	int end;
	int num;
}node;

node list[20] = { { 0 }, { 1, 3, 1 }, { 12, 14, 2 }, { 0, 5, 3 }, { 5, 7, 4 }, { 6, 10, 5 }, { 3, 8, 6 }, \
{8, 12, 7}, { 5, 9, 8 }, { 8, 11, 9 }, { 2, 13, 10 }, { 2, 4, 11 }, { 15, 18, 12 } };

int node_cmp(const void* a, const void* b)
{
	node* c = (node*)a;
	node* d = (node*)b;
	if (c->end != d->end)
		return c->end - d->end;
	return c->start - d->start;
}

int main()
{
	int i, j, k;
	int left = 1, right = 1;
	int n = 12;
	int num = 0;
	/*
	scanf("%d",&n);
	for(i = 1; i <= n; i++)
	{
	scanf("%d%d",&list[i].start,&list[i].end);
	list[i].num = i;
	}
	for(i = 1; i <= n; i++)
	{
	printf("{%d,%d,%d},",list[i].start,list[i].end,list[i].num);
	}


	//排序
	qsort(list, n, sizeof(node), node_cmp);

	while (right <= n)
	{
		if (right == 1 || list[left].end < list[right].start)
		{
			left = right;
			printf("第%d个活动被安排:%d开始,%d结束.\n", \
				list[left].num, list[left].start, list[left].end);

			num++;
		}
		right++;
	}
	printf("总计%d个活动被安排\n", num);
	return 0;
}


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int i, len, flag;
	printf("输入一串字符以判断是否为回文。\n");
	char ch[100];    //存放键入的字符串
	scanf("%s", ch); //接受键入的字符串

	//求字符串长度
	len = strlen(ch);
	//设标志位假设为回文串
	flag = 1;
	//判断是否为回文串
	for (i = 0; i < len / 2; i++) {
		if (ch[i] != ch[len - 1 - i]) {
			flag = 0;
			break;
		}
	}
	//判断标志位来检测
	if (flag) {
		printf("输入的是回文。\n");
	}
	else {
		printf("输入的不是回文。\n");
	}
	return 0;
}



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
	return 0;
}


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
}


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
*/

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