#include<iostream>
int Fabonacci(int n);
using namespace std;
int main() {
	int n;
	cout << "请输入你要计算的数字n" << endl;
	cin >> n;
	int sum = Fabonacci(n);
	cout << "计算得到的斐波那契数列的值为" << sum << endl;
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