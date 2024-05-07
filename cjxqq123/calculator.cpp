#include <iostream>
using namespace std;
int main()
{
	int a, b = 0;
	char c;
	cout << "请输入你要计算的数字" << endl;
	cin >> a >> b;
	cout << "请输入运算符" << endl;
	cin >> c;
	int d;
	if (c == '+')
	{
		d = a + b;
		cout << "a+b=" << d << endl;
	}
	if (c == '-')
	{
		d = a - b;
		cout << "a-b=" << d << endl;
	}
	if (c == '*')
	{
		d = a * b;
		cout << "a*b=" << d << endl;
	}
	if (c == '/')
	{
		d = a / b;
		cout << "a/b=" << d << endl;
	}
	system("pause");
	return 0;
}