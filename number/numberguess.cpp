#include<iostream>
#include<ctime>
#include<stdlib.h>
#include<time.h>
using namespace std;
int main()
{
	char again;
	do
	{
		//电脑随机生成一个1~100的数，记为daan
		srand(time(NULL)) ;
		int daan=rand()%100+1;
		//用户输入数记为huida
		int huida=0;
	
		while(1) 
		{
			cout<<"请在1~100之间猜数字:"<<endl;
			cin>>huida;
			if(huida>daan)
			{
				cout<<"大了 再猜一次吧！"<<endl; 
			}
			else if(huida<daan)
			{
				cout<<"小了 再猜一次吧！"<<endl;
			}
			else
			{
				cout<<"回答正确 太棒啦！"<<endl; 
				cout<<"还想再来一次吗？（y/n）:";
				cin>>again;
			}
		}
	}while(again=='y');
	return 0;
}
