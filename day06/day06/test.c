#include<stdio.h>

#if 0
int main()
{
	int n = 2;
	int ret = n += n -= n * 2;//-4
	printf("%d\n", ret);
}


int main()
{
	char *p = "abcdefgh", *r;
	long *q;
	q = (long*)p;
	q++;
	r = (char*)q;
	printf("%s\n", r);
}


int main()
{
	char str[] = "ABCD", *p = str;
	printf("%d\n", *(p + 4));
	return 0;
};

//�ȶ�����һ��ָ���ַ�������str��ָ��p��ָ��pּ������str���׵�ַ��p+4��ָ��ָ��str[4]��
//����Ϊ�ַ��������ڴ���ַ���ʱ���Զ���ĩβ����'\0'������*(p+4)=0��

int f(int n)
{
	if (n) 
		return f(n - 1) + n;
	else 
		return n;
}
int main()
{
	printf("%d\n", f(4));
	return 0;

}


int fun(int x, int y)
{
	if (x == y)
		return (x);
	else
		return ((x + y) / 2);
} 
int main()
{
	int a = 4, b = 5, c = 6;
	printf("%d\n", fun(2 * a, fun(b, c)));
	return 0;
}


int a, b;
void fun()
{
	a = 100;
	b = 200;
} 
int main()
{
	int a = 5, b = 7;
	fun();
	printf("% d % d / n", a, b);
	return 0;
}
//��ȫ�ֱ����;ֲ������ı�����һ�µ�ʱ������ʹ�þֲ�����

#endif

struct HAR
{ 
	int x, y; 
	struct HAR *p; 
} h[2];
int main()
{
	h[0].x = 1; h[0].y = 2;
	h[1].x = 3; h[1].y = 4;
	h[0].p = &h[1]; h[1].p = h;
	printf("%d,%d \n", (h[0].p)->x, (h[1].p)->y);
	return 0;
}