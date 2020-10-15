
#include <iostream>
using namespace std;



/* 
//1.跑步训练
 
 //方法1：笔算
 //方法2：编程 
int main()
{
	int e=10000;
	int min=0;
	
	while(e>0)
	{
		//如果能跑完一趟，就跑 
		if(e-600>=0)
		{
			min=min+2*60;
			e=e-600+300;
		}
		//跑不完一趟，均匀计算剩下的秒数 
		else
		{
			min = min+e*0.1;
			e=0;
		} 
		
	}
	cout<<min<<endl; //3880
	return 0;
}



//2-纪念日 
方法1:计算器：日期计算：日期减日期 
方法2：编程 
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
		//满一年往上翻
		if(m==12 && d==32) 
		{
			y++;
			m=1;
			d=1;
			continue;
		}
		//大月处理
		if((m==1 || m==3 ||m==5 || m==7 || m==8 || m==10) && d==32)
		{
			m++;
			d=1;
			continue;
		}
		//小月处理
		if((m==4 || m==6 || m==9 || m==11) && d==31)
		{
			m++;
			d=1;
			continue;
		} 
		//闰年二月处理
		if(IsLeapYear(y) && m==2 && d==30)
		{
			m++;
			d=1;
			continue;
		} 
		//平年二月处理
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



//F-整除序列

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




//H-走方格
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
				continue;//跳过1,1 
			if ((i%2==1) || (j%2==1)) //如果行号和列数都是偶数，不能走入这一格中
			{   
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
		}
	}
	cout<< dp[n][m]<<endl;
  return 0;
}


//G-解密
 
 #include <string>
 int main()
 {
 	string s;
 	cin>>s;
 	for(int i=0;i<s.length()-1;i++)
 	{
 		if(s[i+1]>='0' && s[i+1]<='9')//如果下一位字符是数字
		{
			int k=s[i+1]-'0'; //将字符转为数字
			for(int j=0;j<k;j++)
			{
				cout<<s[i];
			} 
			++i; //跳过数字位 
		} 
		else
		{
			cout<<s[i]; //如果不是数字位则直接输出 
		}
 	}
 	return 0;
 }
 */ 
 
 
 //I-整数拼接

#include<iostream>
#include<algorithm>

int n,k,a[1001],ans;

bool Merge(int i,int j) //第i个数和第j个数拼接 是否符合条件
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


