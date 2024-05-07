#include <iostream>
using namespace std;

int Fibonacci(int n);

int main()
{
	int n;
	cout << "请输入你要计算的数字n: ";
	cin >> n;
	if (n < 1)
	{
		cout << "输入的数字应大于0." << endl;
		return 1;
	}
	int result = Fibonacci(n);
	cout << "计算得到的斐波那契数列的值为: " << result << endl;
	return 0;
}

int Fibonacci(int n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	if (n > 2)
	{
		return Fibonacci(n - 1) + Fibonacci(n - 2);
	}
	return -1; // 为了完整性，添加一个默认返回值，实际上这行代码在逻辑上是无法到达的。
}
