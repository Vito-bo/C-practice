
#include <iostream>
using namespace std;



/* 
//1.�ܲ�ѵ��
 
 //����1������
 //����2����� 
int main()
{
	int e=10000;
	int min=0;
	
	while(e>0)
	{
		//���������һ�ˣ����� 
		if(e-600>=0)
		{
			min=min+2*60;
			e=e-600+300;
		}
		//�ܲ���һ�ˣ����ȼ���ʣ�µ����� 
		else
		{
			min = min+e*0.1;
			e=0;
		} 
		
	}
	cout<<min<<endl; //3880
	return 0;
}



//2-������ 
����1:�����������ڼ��㣺���ڼ����� 
����2����� 
bool IsLeapYear(int y)
{
	return (y%4==0 && y%100!=0) || (y%400==0);
}
int main()
{
	int y=1921;
	int m=7;
	int d=23;
	
	for(int i=0; i<36138; i++)
	{
		d++;
		//��һ�����Ϸ�
		if(m==12 && d==32) 
		{
			y++;
			m=1;
			d=1;
			continue;
		}
		//���´���
		if((m==1 || m==3 ||m==5 || m==7 || m==8 || m==10) && d==32)
		{
			m++;
			d=1;
			continue;
		}
		//С�´���
		if((m==4 || m==6 || m==9 || m==11) && d==31)
		{
			m++;
			d=1;
			continue;
		} 
		//������´���
		if(IsLeapYear(y) && m==2 && d==30)
		{
			m++;
			d=1;
			continue;
		} 
		//ƽ����´���
		if((!IsLeapYear(y)) && m==2 && d==29)
		{
			m++;
			d=1;
			continue;
		} 
	}
	cout<<y<<"-"<<m<<"-"<<d<<endl;
	
	int min=36138*24*60;
	cout<<min<<endl; //52038720
	return 0;
} 



//F-��������

int main()
{
	long long n;
	cin>>n;
	while(n!=1)
	{
		cout<<n<<" ";
		n = n>>1;
	}
	cout<<1<<endl;
	return 0;
} 




//H-�߷���
typedef long long ll;
const int MAXN = 35;
ll dp[MAXN][MAXN];
int main() 
{
	dp[1][1]=1;
	int n,m;
	cin>>n>>m; 
	for(int i=1;i<=n;i++)
	{		
		for(int j=1;j<=m;j++)
		{
			if(i==1&&j==1)
				continue;//����1,1 
			if ((i%2==1) || (j%2==1)) //����кź���������ż��������������һ����
			{   
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
		}
	}
	cout<< dp[n][m]<<endl;
  return 0;
}


//G-����
 
 #include <string>
 int main()
 {
 	string s;
 	cin>>s;
 	for(int i=0;i<s.length()-1;i++)
 	{
 		if(s[i+1]>='0' && s[i+1]<='9')//�����һλ�ַ�������
		{
			int k=s[i+1]-'0'; //���ַ�תΪ����
			for(int j=0;j<k;j++)
			{
				cout<<s[i];
			} 
			++i; //��������λ 
		} 
		else
		{
			cout<<s[i]; //�����������λ��ֱ����� 
		}
 	}
 	return 0;
 }
 */ 
 
 
 //I-����ƴ��

#include<iostream>
#include<algorithm>

int n,k,a[1001],ans;

bool Merge(int i,int j) //��i�����͵�j����ƴ�� �Ƿ��������
{
	int t=a[j],cnt=1;
	while(t!=0){
		cnt*=10;
		t/=10;
	}
	
	if((a[i]*cnt+a[j])%k==0)
		return true;				
	return false;
}
int main()
{
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>a[i];
	
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(Merge(i,j))
				ans++;
			if(Merge(j,i))
				ans++;
		}
	}
	cout<<ans;
	return 0;
} 


