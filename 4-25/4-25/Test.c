
/*
#include<stdio.h>
#define N 10

void max_min(int *a, int m, int n, int *min1, int *min2, int *max1, int *max2);

int main(void)
{
	printf("һ����k������k=10\n");
	int a[N] = { 4,8,3,9,7,1,0,6,5,2 };
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	int min1, min2;
	int max1, max2;
	max_min(a, 0, N - 1, &min1, &min2, &max1, &max2);
	//���ĸ������Ĵ�С��ϵΪ min1<min2<max2<max1 
	printf("min1=%d min2=%d\nmax1=%d max2=%d\n", min1, min2, max1, max2);
	return 0;
}

void max_min(int *a, int m, int n, int *min1, int *min2, int *max1, int *max2)
{
	int lmin1, lmin2, lmax1, lmax2;
	int rmin1, rmin2, rmax1, rmax2;
	int mid;

	if (m == n)//������������ֻ��һ����
	{
		*min1 = *min2 = *max1 = *max2 = a[m];
	}

	else//�����������в�ֹһ����
	if (m == n - 1)//�����������н���2����
	{
		if (a[m]<a[n])
		{
			*min1 = a[m];
			*min2 = a[n];
			*max1 = a[n];
			*max2 = a[m];
		}
		else
		{
			*min1 = a[n];
			*min2 = a[m];
			*max1 = a[m];
			*max2 = a[n];
		}
	}

	else//�������������г���2����
	{
		mid = (m + n) / 2;
		max_min(a, m, mid, &lmin1, &lmin2, &lmax1, &lmax2);
		max_min(a, mid + 1, n, &rmin1, &rmin2, &rmax1, &rmax2);

		//**************************************************
		//ȷ������������С��������
		//**************************************************
		if (lmin1<rmin1)//����������С��<����������С��
		{
			if (lmin2<rmin1)
			{
				*min1 = lmin1;
				*min2 = lmin2;
			}
			else
			{
				*min1 = lmin1;
				*min2 = rmin1;
			}
		}
		else//����������С��<����������С��
		if (rmin2<lmin1)
		{
			*min1 = rmin1;
			*min2 = rmin2;
		}
		else
		{
			*min1 = rmin1;
			*min2 = lmin1;
		}

		//**************************************************
		//ȷ��������������������
		//**************************************************
		if (lmax1>rmax1)//�������������>�������������
		{
			if (lmax2>rmax1)
			{
				*max1 = lmax1;
				*max2 = lmax2;
			}
			else
			{
				*max1 = lmax1;
				*max2 = rmax1;
			}
		}
		else//�������������>�������������
		if (rmax2>lmax1)
		{
			*max1 = rmax1;
			*max2 = rmax2;
		}
		else
		{
			*max1 = rmax1;
			*max2 = lmax1;
		}
	}
}


#include <stdio.h>
int	map[8][8] = { { 0, 0, 0, 1, 0, 0, 0, 0 }, { 0, 1, 1, 1, 1, 1, 1, 1 }, { 0, 0, 0, 1, 0, 0, 0, 1 }, { 0, 1, 0, 1, 0, 1, 0, 1 }, { 0, 1, 0, 0, 0, 1, 0, 1 }, { 0, 1, 1, 1, 1, 1, 0, 1 }, { 0, 1, 0, 0, 0, 1, 0, 0 }, { 0, 1, 0, 0, 0, 0, 1, 0 } };
int dep;
int count;
void search(int i, int j);  //·��Ѱ�ң�Ҫ��ʹ�õݹ�

//�ж�·�Ƿ������
int check(int x, int y) {
	int i, j;
	int flag = 1;
	//��������߲�ͨ
	if (x < 0 || x > 7 || y < 0 || y > 7) {
		flag = 0;
	}
	else {
		//��·����·�Ѿ����߹�
		if (map[x][y] != 0) {
			flag = 0;
		}
	}
	return flag;
}

//��ӡ���н�
void print() {
	int i, j;
	for (i = 0; i < 8; i++) {
		printf("\n");
		for (j = 0; j < 8; j++) {
			printf("  %d", map[i][j]);
		}
	}
}


int main() {

	count = 0;  //��¼���н� 
	dep = 2;
	map[0][0] = 1;
	search(0, 0);
	printf("\n����%d�ַ���", count);
	return 0;
}

void search(int i, int j) {
	//�����ҡ��¡������ĸ����� 
	int fx[4] = { 0, 1, 0, -1 };
	int fy[4] = { 1, 0, -1, 0 };
	int k, xx, yy;
	//�ֱ�����ĸ�����
	for (k = 0; k < 4; k++) {
		//��ǰһ��Ҫ�ߵ�����
		xx = i + fx[k];
		yy = j + fy[k];
		//����·������
		if (check(xx, yy)) {
			map[xx][yy] = dep++;  //����s����2
			//�����յ����
			if (xx == 7 && yy == 7) {
				count++;
				print();
			}
			else {
				search(xx, yy);
			}

		}
	}
	map[i][j] = 0; //����
	dep--;

}


#include <stdio.h>
int	map[8][8] = { { 0, 0, 0, 1, 0, 0, 0, 0 }, { 0, 1, 1, 1, 1, 1, 1, 1 }, { 0, 0, 0, 1, 0, 0, 0, 1 }, { 0, 1, 0, 1, 0, 1, 0, 1 }, { 0, 1, 0, 0, 0, 1, 0, 1 }, { 0, 1, 1, 1, 1, 1, 0, 1 }, { 0, 1, 0, 0, 0, 1, 0, 0 }, { 0, 1, 0, 0, 0, 0, 1, 0 } };
int dep;
int count;
void search(int i, int j);  //·��Ѱ�ң�Ҫ��ʹ�õݹ�

//�ж�·�Ƿ������
int check(int x, int y) {
	int i, j;
	int flag = 1;
	//��������߲�ͨ
	if (x < 0 || x > 7 || y < 0 || y > 7) {
		flag = 0;
	}
	else {
		//��·����·�Ѿ����߹�
		if (map[x][y] != 0) {
			flag = 0;
		}
	}
	return flag;
}

//��ӡ���н�
void print() {
	int i, j;
	for (i = 0; i < 8; i++) {
		printf("\n");
		for (j = 0; j < 8; j++) {
			printf("  %d", map[i][j]);
		}
	}
}


int main() {

	count = 0;  //��¼���н� 
	dep = 2;
	map[0][0] = 1;
	search(0, 0);
	printf("\n����%d�ַ���", count);
	return 0;
}

void search(int i, int j) {
	//�����ҡ��¡������ĸ����� 
	int fx[4] = { 0, 1, 0, -1 };
	int fy[4] = { 1, 0, -1, 0 };
	int k, xx, yy;
	//�ֱ�����ĸ�����
	for (k = 0; k < 4; k++) {
		//��ǰһ��Ҫ�ߵ�����
		xx = i + fx[k];
		yy = j + fy[k];
		//����·������
		if (check(xx, yy)) {
			map[xx][yy] = dep++;  //����s����2
			//�����յ����
			if (xx == 7 && yy == 7) {
				count++;
				print();
			}
			else {
				search(xx, yy);
			}

		}
	}
	map[i][j] = 0; //����
	dep--;

}

//2
#include <stdio.h>
int main(void)
{
	int array1[6][7] = {
		{ 16, 4, 3, 12, 6, 0, 3 },
		{ 4, -5, 6, 7, 0, 0, 2 },
		{ 6, 0, -1, -2, 3, 6, 8 },
		{ 5, 3, 4, 0, 0, -2, 7 },
		{ -1, 7, 4, 0, 7, -5, 6 },
		{ 0, -1, 3, 4, 12, 4, 2 }
	};
	int b[6][7], c[6][7];
	int i, j, k;
	int max;
	int flag;

	for (i = 0; i<6; i++)
	for (j = 0; j<7; j++)
	{
		b[i][j] = array1[i][j];
		c[i][j] = -1;
	}
	for (i = 1; i<5; i++)
	{
		for (j = 0; j<7; j++)
		{
			max = 0;
			for (k = j - 2; k <= j + 2; k++)
			{
				if (k<0) continue;
				else
				if (k>6) break;
				else
				{
					if (b[i][j] + b[i - 1][k]>max)
					{
						max = b[i][j] + b[i - 1][k];
						flag = k;
					}
				}
			}
			b[i][j] = max;
			c[i][j] = flag;
		}
	}

	for (j = 1; j <= 5; j++)//i=5
	{
		max = 0;
		for (k = j - 2; k <= j + 2; k++)
		{
			if (k<0)
				continue;
			else
			if (k>6)  break;
			else
			{
				if (b[i][j] + b[i - 1][k]>max)
				{
					max = b[i][j] + b[i - 1][k];
					flag = k;
				}
			}
		}
		b[i][j] = max;
		c[i][j] = flag;
	}

	max = 0;
	for (j = 1; j <= 5; j++)   //�ҳ�
	{
		if (b[i][j]>max)
		{
			max = b[i][j];
			flag = j;
		}
	}
	printf("���·������%d\n", max);
	return 0;
}

#include <stdio.h>
int	map[8][8] = { { 0, 0, 0, 1, 0, 0, 0, 0 }, { 0, 1, 1, 1, 1, 1, 1, 1 }, { 0, 0, 0, 1, 0, 0, 0, 1 }, { 0, 1, 0, 1, 0, 1, 0, 1 }, { 0, 1, 0, 0, 0, 1, 0, 1 }, { 0, 1, 1, 1, 1, 1, 0, 1 }, { 0, 1, 0, 0, 0, 1, 0, 0 }, { 0, 1, 0, 0, 0, 0, 1, 0 } };
int dep;
int count;
void search(int i, int j);  //·��Ѱ�ң�Ҫ��ʹ�õݹ�

//�ж�·�Ƿ������
int check(int x, int y) {
	int i, j;
	int flag = 1;
	//��������߲�ͨ
	if (x < 0 || x > 7 || y < 0 || y > 7) {
		flag = 0;
	}
	else {
		//��·����·�Ѿ����߹�
		if (map[x][y] != 0) {
			flag = 0;
		}
	}
	return flag;
}

//��ӡ���н�
void print() {
	int i, j;
	for (i = 0; i < 8; i++) {
		printf("\n");
		for (j = 0; j < 8; j++) {
			printf("  %d", map[i][j]);
		}
	}
}


int main() {

	count = 0;  //��¼���н� 
	dep = 2;
	map[0][0] = 1;
	search(0, 0);
	printf("\n����%d�ַ���\n", count);
	return 0;
}

void search(int i, int j) {
	//�����ҡ��¡������ĸ����� 
	int fx[4] = { 0, 1, 0, -1 };
	int fy[4] = { 1, 0, -1, 0 };
	int k, xx, yy;
	//�ֱ�����ĸ�����
	for (k = 0; k < 4; k++) {
		//��ǰһ��Ҫ�ߵ�����
		xx = i + fx[k];
		yy = j + fy[k];
		//����·������
		if (check(xx, yy)) {
			map[xx][yy] = dep++;  //����s����2
			//�����յ����
			if (xx == 7 && yy == 7) {
				count++;
				print();
			}
			else {
				search(xx, yy);
			}

		}
	}
	map[i][j] = 0; //����
	dep--;

}
#include "stdio.h"
int	map[8][8] = { { 0, 0, 0, 1, 0, 0, 0, 0 }, { 0, 1, 1, 1, 1, 1, 1, 1 }, { 0, 0, 0, 1, 0, 0, 0, 1 }, { 0, 1, 0, 1, 0, 1, 0, 1 }, { 0, 1, 0, 0, 0, 1, 0, 1 }, { 0, 1, 1, 1, 1, 1, 0, 1 }, { 0, 1, 0, 0, 0, 1, 0, 0 }, { 0, 1, 0, 0, 0, 0, 1, 0 } };
int dep;
int count;
void search(int i, int j);  //·��Ѱ�ң�Ҫ��ʹ�õݹ�

//�ж�·�Ƿ������
int check(int x, int y) {
	int i, j;
	int flag = 1;
	//��������߲�ͨ
	if (x < 0 || x > 7 || y < 0 || y > 7) {
		flag = 0;
	}
	else {
		//��·����·�Ѿ����߹�
		if (map[x][y] != 0) {
			flag = 0;
		}
	}
	return flag;
}

//��ӡ���н�
void print() {
	int i, j;
	for (i = 0; i < 8; i++) {
		printf("\n");
		for (j = 0; j < 8; j++) {
			printf("  %d", map[i][j]);
		}
	}
}


int main() {

	count = 0;  //��¼���н� 
	dep = 2;
	map[0][0] = 1;
	search(0, 0);
	printf("\n����%d��·��\n", count);
	return 0;
}

void search(int i, int j) {
	//�����ҡ��¡������ĸ����� 
	int fx[4] = { 0, 1, 0, -1 };
	int fy[4] = { 1, 0, -1, 0 };
	int k, xx, yy;
	//�ֱ�����ĸ�����
	for (k = 0; k < 4; k++) {
		//��ǰһ��Ҫ�ߵ�����
		xx = i + fx[k];
		yy = j + fy[k];
		//����·������
		if (check(xx, yy)) {
			map[xx][yy] = dep++;  //����s����2
			//�����յ����
			if (xx == 7 && yy == 7) {
				count++;
				print();
			}
			else {
				search(xx, yy);
			}

		}
	}
	map[i][j] = 0; //����
	dep--;

}

#include "stdio.h" 
int main()
{

	//A��B��Cӵ�еĻ�������ӯ������Ķ�Ӧ��ϵ
	int A[6] = { 0, 3, 8, 9, 12, 13 };
	int B[6] = { 0, 5, 10, 11, 11, 11 };
	int C[6] = { 0, 4, 6, 11, 12, 12 };
	/************begin************/
	int bestf = 0;
	int sum, x, y, z;
	int i, j, k;

	for (i = 0; i <= 5; i++) {
		for (j = 0; j <= 5; j++) {
			k = 5 - i - j;
			if (k >= 0) {
				sum = A[i] + B[j] + C[k]; //sum����ӯ���ܶ� 
				//��¼���Ž� 
				if (sum > bestf) {
					x = i;
					y = j;
					z = k;
					bestf = sum;
				}
			}

		}
	}
	printf("A B C���ŷ������������Ϊ %d %d %d\n", x, y, z);
	printf("���ӯ��ֵΪ%d\n", bestf);
	return 0;

	/************end************/
}
