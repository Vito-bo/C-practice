#include<stdio.h>


#if 0
int main()
{
	int i = 10, j = 10, k = 3;
	k *= i + j;
	printf("%d\n", k); //60
	return 0;
}

int main()
{
	int num = 7;
	int sum = 7;
	sum = num++;
	sum++;
	++num;
	printf("%d\n", sum);//8
	printf("%d\n", num);
	return 0;
}
#endif

int main()
{
	int i, j, a[2][3];
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 3; j++)
		{
			a[i][j] = i * 3 + j + 1;
		}
	}
	return 0;
}

//ʵ�ֺ��� ToLowerCase()���ú�������һ���ַ������� str���������ַ����еĴ�д��ĸת����Сд��ĸ��֮�󷵻��µ��ַ���
char * toLowerCase(char * str){
	int i = 0;
	int len = strlen(str);
	for (i = 0; i<len; i++)
	{
		//str[i] = str[i] >= 'A' && str[i] <= 'Z' ? str[i] + 32 : str[i];
		if (str[i] >= 65 && str[i] <= 90)
			str[i] = str[i] + 32;
		else
			str[i] = str[i];
	}
	return str;
}
