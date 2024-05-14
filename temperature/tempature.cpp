#include <iostream>
#include <limits>
using namespace std;

int main()
{
    char a;
    double b, c;
    cout << "请输入温度类型再输入温度值，类型为摄氏度请按C，为华氏度请按F (请注意大小写)。" << endl;
    cout << "若想终止输入请输入Q 0。" << endl;

    while (true)
    {
        cin >> a >> b;

        // 检查输入是否有效
        if (cin.fail())
        {
            cin.clear();                                         // 清除错误标志
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 忽略输入流中的所有字符，直到遇到换行符
            cout << "输入无效，请重新输入温度类型和温度值。" << endl;
            continue;
        }

        if (a == 'Q')
        {
            break; // 用户输入Q，退出循环
        }

        if (a == 'C')
        {
            c = 32 + 1.8 * b;
            cout << "转化为华氏度为 " << c << "℉" << endl;
        }
        else if (a == 'F')
        {
            c = (b - 32) / 1.8;
            cout << "转化为摄氏度为 " << c << "℃" << endl;
        }
        else
        {
            cout << "输入类型无效，请输入C或F。" << endl;
            // 清除当前行无效输入，重新提示用户输入
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    return 0;
}
