#include<iostream>
int Fabonacci(int n);
using namespace std;
int main() {
	int n;
	cout << "��������Ҫ���������n" << endl;
	cin >> n;
	int sum = Fabonacci(n);
	cout << "����õ���쳲��������е�ֵΪ" << sum << endl;
	system("pause");
	return 0;
}
int Fabonacci(int n) {
	if (n == 1 || n == 2) {
		return 1;
	}
	if (n > 2) {
		return (Fabonacci(n - 1) + Fabonacci(n - 2));
	}
}