#include <iostream>
#include <cmath>
#include <limits> 
using namespace std;

int main()
{
    int x;
    bool flag; 
    cout << "可输入非正数以结束程序" << endl;

    while (true)
    {
        cout << "请输入一个数：";
        cin >> x;

        // 检测输入是否为有效整数
        if (cin.fail()) 
		{
            cin.clear();  // 清除错误标志
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // 忽略输入流中的所有字符，直到遇到换行符
            cout << "请输入一个有效的整数。" << endl;
            continue;
        }

        // 如果输入的是非正数，结束程序
        if (x <= 0) {
            break;
        }

        flag = false;  // 重置标志变量

        for (int i = 2; i <= sqrt(x); i++)
        {
            if (x % i == 0)
            {
                flag = true;
                cout << x << " 不是一个质数" << endl;
                break;
            }
        }

        if (!flag)
        {
            cout << x << " 是一个质数" << endl;
        }
    }

    return 0;
}
