#include<iostream>
#include<ctime>
#include<stdlib.h>
#include<time.h>
#include<limits>
using namespace std;
void GuessNumber() 
{
    int daan = rand() % 100 + 1;  // 生成 1 到 100 之间的随机数作为daan
    double huida;
    while (true) 
	{
        	cout << "请在1~100之间猜数字: ";
        	if (!(cin >> huida)) 
		{
            		cin.clear();
            		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            		cout << "输入无效，请重新输入一个整数。" << endl;
           		 continue;
       	 	}
        	int guess=static_cast<int>(huida);
        	if (guess == daan) 
		{
           	 	cout << "恭喜你，猜对了！" << endl;
            		break;
        	} 
		else if (guess < daan)
		{
            		cout << "猜小了" << endl;
        	} 
		else 
		{
            		cout << "猜大了" << endl;
        	}
    	}
}
int main() 
{
    char again;
    do 
	{
        	GuessNumber();
        	cout << "是否再来一次(y/n)？ ";
        	cin >> again;
    	} while (again == 'y' || again == 'Y');
    return 0;
}
