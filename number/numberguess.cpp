#include<iostream>
#include<ctime>
#include<stdlib.h>
#include<time.h>
using namespace std;
int main()
{
	//�����������һ��1~100��������Ϊdaan
	srand(time(NULL)) ;
	int daan=rand()%100+1;
	//�û���������Ϊhuida
	int huida=0;
	while(1) 
	{
		cout<<"����1~100֮�������:"<<endl;
		cin>>huida;
		if(huida>daan)
		{
			cout<<"���� �ٲ�һ�ΰɣ�"<<endl; 
		}
		else if(huida<daan)
		{
			cout<<"С�� �ٲ�һ�ΰɣ�"<<endl;
		}
		else
		{
			cout<<"�ش���ȷ ̫������"<<endl; 
			break;
		}
	}
}
