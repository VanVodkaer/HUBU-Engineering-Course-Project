#include<iostream>
using namespace std;
int main() {
	int a, b = 0;
	char c;
	cout << "��������Ҫ���������" << endl;
	cin >> a >> b;
	cout << "�����������" << endl;
	cin >> c;
	int d;
	if (c == '+') {
		d = a + b;
		cout << "a+b=" << d << endl;
	}
	if (c == '-') {
		d = a-b;
		cout << "a-b=" << d << endl;
	}
	if (c == '*') {
		d = a * b;
		cout << "a*b=" << d << endl;
		
	}
	if (c == '/') {
		d = a / b;
		cout << "a/b=" << d << endl;
	}
	system("pause");
	return 0;
}