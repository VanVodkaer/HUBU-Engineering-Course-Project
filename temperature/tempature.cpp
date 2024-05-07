#include <iostream>
using namespace std;
int main()
{
    char a;
    double b, c;
    cout << "请输入温度值和温度类型，类型为摄氏度请按C，为华氏度请按F(请注意大小写）" << endl;
    cin >> b >> a;
    if (a == 'C')
    {
        c = 32 + 1.8 * b;
        cout << "转化为华氏度为" << c << "℉" << endl;
    }
    if (a == 'F')
    {
        c = (b - 32) / 1.8;
        cout << "转化为摄氏度为" << c << "℃" << endl;
    }
    if (a != 'C' && a != 'F')
    {
        cout << "请输入正确的类型";
    }
    return 0;
}