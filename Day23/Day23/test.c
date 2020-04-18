

/*
#include <stdio.h> 
#include <math.h>

int board[100][100] = { 0 };//���� 
int count = 1;//���δ������˳�� 
int dis[4][2] = { { 0, 0 }, { 0, 1 }, { 1, 0 }, { 1, 1 } };//�����ң��£����½�����λ�� 

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
	//����ֻ��һ�����ӵ���� 
	if (size < 2)
		return;

	size /= 2;
	num = count++;
	for (i = 0; i < 4; i++)
	{
		//�ֳ��ĸ����飬row,col�ֱ�Ϊ�ĸ���������Ͻ�λ�� 
		row = dis[i][0] * size + tx;
		col = dis[i][1] * size + ty;

		//���ȱ�ٵĸ��Ӳ��ڵ�ǰ��Χ���Ͱ��¼ӵĲ�ȱ���� 
		if (!(x >= row && x < (row + size) && \
			y >= col && y < (col + size)))
		{
			//r,c Ϊ�¼ӵĲ�ȱ��λ�� 
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
	int x, y;//��ȱ���λ��
	int size = pow(2, k);//���̵�����


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


	//����
	qsort(list, n, sizeof(node), node_cmp);

	while (right <= n)
	{
		if (right == 1 || list[left].end < list[right].start)
		{
			left = right;
			printf("��%d���������:%d��ʼ,%d����.\n", \
				list[left].num, list[left].start, list[left].end);

			num++;
		}
		right++;
	}
	printf("�ܼ�%d���������\n", num);
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


	//����
	qsort(list, n, sizeof(node), node_cmp);

	while (right <= n)
	{
		if (right == 1 || list[left].end < list[right].start)
		{
			left = right;
			printf("��%d���������:%d��ʼ,%d����.\n", \
				list[left].num, list[left].start, list[left].end);

			num++;
		}
		right++;
	}
	printf("�ܼ�%d���������\n", num);
	return 0;
}


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int i, len, flag;
	printf("����һ���ַ����ж��Ƿ�Ϊ���ġ�\n");
	char ch[100];    //��ż�����ַ���
	scanf("%s", ch); //���ܼ�����ַ���

	//���ַ�������
	len = strlen(ch);
	//���־λ����Ϊ���Ĵ�
	flag = 1;
	//�ж��Ƿ�Ϊ���Ĵ�
	for (i = 0; i < len / 2; i++) {
		if (ch[i] != ch[len - 1 - i]) {
			flag = 0;
			break;
		}
	}
	//�жϱ�־λ�����
	if (flag) {
		printf("������ǻ��ġ�\n");
	}
	else {
		printf("����Ĳ��ǻ��ġ�\n");
	}
	return 0;
}



#include<stdio.h>
int main()
{
	long n; //��ż��������ֵ
	int a[3] = { 4, 7, 9 };
	int flag[3];
	int i, k;
	k = 0;
	printf("������һ��������");
	scanf("%ld", &n);//��ȡ���������ֵ
	for (i = 0; i < 3; i++) {
		if (n%a[i] == 0) {
			flag[k++] = a[i];
		}
	}
	if (k == 1) {
		printf("������ܱ�%d����\n", flag[0]);
	}
	else {
		printf("�������ͬʱ��");
		for (i = 0; i < k - 1; i++) {
			printf("%d,", flag[i]);
		}
		printf("%d����\n", flag[k - 1]);
	}
	return 0;
}


#include<stdio.h>
int main() {
	int i, j, k, m, c, e, f;
	int a[4] = { 2, 3, 5, 7 };
	//ѭ�������ʽ
	printf("��Ŀ�еĳ�ʽΪ��\n");
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
//�жϾ�λ�����Ƿ�Ϊÿ�����ֶ�����ͬ��
int check(int a[], int n) {
	//���ñ�־λ
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
	//���м���
	for (i = 5; i <= 9; i++) {
		for (j = 0; j <= 9; j++) {
			//ÿλ��ͬ
			if (i != j) {
				for (k = 0; k <= 9; k++) {
					//ÿλ��ͬ
					if (k != i && k != j) {
						for (m = 0; m <= 9; m++) {
							//ÿλ��ͬ
							if (m != i && m != j && m != k) {
								n = i * 1000 + j * 100 + k * 10 + m;
								a[0] = i;
								a[1] = j;
								a[2] = k;
								a[3] = m;
								//�жϽ���Ƿ�Ϊ��λ����ͬ������ 
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
	int n, sum, m, num;//��������������
	int len;
	int a[5];//�����������ÿ������ 
	printf("������һ����λ���ڵ�������\n");
	scanf("%d", &n); //��ȡ�����������
	len = 0;
	//������¼ԭ����������� 
	m = n;
	while (n) {
		n /= 10;
		len++;
	}
	sum = 0;
	//������¼�������ֵ�λ�� 
	num = len;
	n = m;
	while (len) {
		sum += n % 10 * pow(10, len - 1);
		n /= 10;
		len--;
	}
	printf("�������������һ��%dλ��\n", num);
	printf("��˳�����Ϊ��\n%d\n", m);
	printf("���������Ϊ��\n%d\n", sum);
}


#include<stdio.h>
#include<stdlib.h>
int ctn = 0;
int count(int i) //λ�����㺯��
{
	//�ж�ѭ���˳�����
	if (i / 10 == 0) {
		return ctn + 1;
	}
	ctn++;
	//�ݹ�
	return count(i / 10);
}
void nxdisp(int i) //�����������
{
	//�ݹ��˳����� 
	if (i / 10 == 0) {
		printf("%d", i % 10);
		return;
	}
	printf("%d", i % 10);
	nxdisp(i / 10);
}
void sxdisp(int i)//˳���������
{
	if (i / 10 != 0) {
		sxdisp(i / 10);
	}
	printf("%d", i % 10);
}

int main()
{
	int n;//��������������
	//����������
	printf("������һ��������\n");
	scanf("%d", &n);
	printf("%d��%dλ��\n", n, count(n));
	printf("�����ӡ\n");
	nxdisp(n);
	printf("\n");
	printf("˳���ӡ\n");
	sxdisp(n);
}
*/

#include<stdio.h>
int main() {
	int i, j, k, m, c, e, f;
	int a[4] = { 2, 3, 5, 7 };
	//ѭ�������ʽ
	printf("��Ŀ�еĳ�ʽΪ��\n");
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