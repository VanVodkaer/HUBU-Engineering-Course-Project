#include<iostream>
#include<math.h> 
using namespace std;

int main()
{
	int x,flag=0; 
	cout<<"请输入一个正整数：";
	cin>>x;
	if(x<=0)
	{
		cout<<endl<<"Invalid Number"; 
		exit(0);
	}
	for (int i=2;i<sqrt(x);i++)
	{
		if(x%i==0)
		{
			flag=1; 
			cout<<endl<<x<<"不是一个质数"<<endl;
			break;
		}
	}
	if(flag==0)
	{
		cout<<endl<<x<<"是一个质数"<<endl; 
	}
	return 0;
} 
