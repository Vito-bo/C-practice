#include<stdio.h>
#include<string.h>

//ָ�������
/*
//����8
int main() 
{ 
	char *c[] = { "ENTER", "NEW", "POINT", "FIRST" };    
	char**cp[] = { c + 3, c + 2, c + 1, c };    
	char***cpp = cp;    
	printf("%s\n", **++cpp); //POINT   
	printf("%s\n", *--*++cpp + 3);  //ER  
	printf("%s\n", *cpp[-2] + 3);   //ST
	printf("%s\n", cpp[-1][-1] + 1);//EN    
    return 0; 
}

//����7
int main() 
{ 
	char *a[] = { "work", "at", "alibaba" };    
	char**pa = a;    pa++;    
	printf("%s\n", *pa);//at    
	return 0; 
}

//����6
int main()
{
	int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int *ptr1 = (int *)(&aa + 1);
	int *ptr2 = (int *)(*(aa + 1));
	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));
	return 0;
}
//����5
int main()
{
	int a[5][5];
	int(*p)[4];
	p = a;
	printf("%p,%d\n", &p[4][2] - &a[4][2],
		&p[4][2] - &a[4][2]);
	//FFFFFFFC 4
	return 0;
}

//����4
int main()
{
	int a[3][2] = { (0, 1), (2, 3), (4, 5) };
	int *p;
	p = a[0];
	printf("%d", p[0]);
}

//����3
int main() 
{
	int a[4] = { 1, 2, 3, 4 };
	int *ptr1 = (int *)(&a + 1);
	int *ptr2 = (int *)((int)a + 1);
	printf("%x,%x", ptr1[-1], *ptr2);//4  200 0000
	return 0;
}

//����2
//��֪�ṹ��Ĵ�С��20���ֽ�
struct Test
{
	int Num;
	char* pcName;
	short sDte;
	char ch[2];
	short sBa[4];
}*p;
int main()
{
	p = (struct Test *)0x100000;
	printf("%p\n", p + 0x1);//0x0010 0014
	//p�ṹ��ָ�룬p+1,��20���ֽ�
	printf("%p\n", (unsigned long)p + 0x1);//0x0010 0001
	//(unsigned long)p ǿת���޷��ų���������
	printf("%p\n", (unsigned int*)p + 0x1);//0x0010 0004
	//(unsigned int*)p ָ������ +4
	return 0;
}

int main()
{
	//����1
	int a[5] = { 1, 2, 3, 4, 5 };
	int *ptr = (int *)(&a + 1);
	printf("%d,%d", *(a + 1), *(ptr - 1));
	//2  5
	
	//��ά���� 
	int a[3][4] = {0}; 
	printf("%d\n",sizeof(a)); //48
	//sizeof(������)������������
	printf("%d\n",sizeof(a[0][0]));//4 
	//a[0][0]�����һ�е�һ�е�Ԫ��
	printf("%d\n",sizeof(a[0])); //16
	//a[0]�����һ�е�������
	printf("%d\n",sizeof(a[0]+1)); //4
	//(a[0]+1)����a[0][1]�ĵ�ַ
	printf("%d\n",sizeof(*(a[0]+1))); //4
	//(*(a[0]+1))���� a[0][1]������
	printf("%d\n",sizeof(a+1)); //4
	//a+1������ǵڶ��еĵ�ַ
	printf("%d\n",sizeof(*(a+1))); //16
	//*(a+1)����ڶ��е�����
	printf("%d\n",sizeof(&a[0]+1)); //4
	//&a[0]+1����ڶ�����Ԫ�صĵ�ַ
	printf("%d\n",sizeof(*(&a[0]+1))); //16
	//*(&a[0]+1)����ڶ��е�����
	printf("%d\n",sizeof(*a)); //16
	//*a,�����ã������һ�е�����
	printf("%d\n",sizeof(a[3]));//16
	//*(a+3) a+3������������ָ��

	char* p = "abcdef";
	printf("%d\n", sizeof(p));//4
	printf("%d\n", sizeof(p+1));//4
	printf("%d\n", sizeof(*p));//1
	printf("%d\n", sizeof(p[0]));//1
	printf("%d\n", sizeof(&p));//4
	printf("%d\n", sizeof(&p+1));//4
	printf("%d\n", sizeof(&p[0]+1));//4

	printf("%d\n", strlen(p));//6
	printf("%d\n", strlen(p+1));//5
	//printf("%d\n", strlen(*p));
	//printf("%d\n", strlen(p[0]));
	//printf("%d\n", strlen(&p));
	//printf("%d\n", strlen(&p+1));
	printf("%d\n", strlen(&p[0]+1));//5
	return 0;
}
*/