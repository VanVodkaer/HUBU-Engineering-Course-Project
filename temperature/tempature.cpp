#include <iostream>
using namespace std;
int main()
{
    char a;
    double b, c;
    cout << "�������¶�ֵ���¶����ͣ�����Ϊ���϶��밴C��Ϊ���϶��밴F(��ע���Сд��"<<endl;
    cin >> b >> a;
    if (a == 'C')
    {
        c = 32 + 1.8 * b;
        cout << "ת��Ϊ���϶�Ϊ" << c << "�H"<<endl;
    }
    if (a == 'F')
    {
        c = (b - 32) / 1.8;
        cout << "ת��Ϊ���϶�Ϊ" << c << "��"<<endl;
    }
    if(a !='C'&& a !='F')
    {
        cout << "��������ȷ������";
    }
    return 0;
}