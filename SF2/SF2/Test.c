
//2.7
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










/*
//2.6
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


//2.5
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
	return 0;
}
//2.4
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


//2.3
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
	return;
}

//2.2
#include<stdio.h>
#include<string.h>
#define MAX 100 
char s[MAX];
int len;
int isPalindrome(int i)  //�����жϺ���
{
	//���ж���ɺ���� 
	if (len - 2 * i == 1 || len - 2 * i == 0) {
		return 1;
	}
	//�������������Ҫ��ʱ�˳�ѭ�� 
	if (s[i] != s[len - 1 - i]) {
		return 0;
	}
	return isPalindrome(++i);
}
int main()//������
{
	int i;
	printf("����һ���ַ����ж��Ƿ�Ϊ���ġ�\n");
	//�����ַ��� 
	gets(s);
	//���ַ������� 
	len = strlen(s);
	if (isPalindrome(0)) {
		printf("������ǻ��ġ�\n");
	}
	else {
		printf("����Ĳ��ǻ��ġ�\n");
	}
	return 0;
}
*/