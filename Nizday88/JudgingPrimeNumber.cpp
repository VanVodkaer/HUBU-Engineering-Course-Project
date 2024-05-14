#include<iostream>
#include<cmath> 
using namespace std;

int main()
{
	int x,flag=0; 
	cout<<"可输入非正数以结束程序"<<endl; 
	cout<<"请输入一个数：";
	cin>>x;
	while(x>0)
	{
		for (int i=2;i<=sqrt(x);i++)
		{
			if(x%i==0)
			{
				flag=1; 
				cout<<x<<"不是一个质数"<<endl;
				break;
			}
			flag=0; 
		}
		if(flag==0)
		{
			cout<<x<<"是一个质数"<<endl; 
		}
		cout<<"请输入一个数：";
		cin>>x;
	}
	return 0;
} 
