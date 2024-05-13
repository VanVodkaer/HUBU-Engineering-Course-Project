#include <iostream>

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    while (true) {
        int n;
        std::cout << "请输入您想要计算的数字: ";
        std::cin >> n;

        if (n < 0) {
            std::cout << "无效输入，请输入一个非负数" << std::endl;
            continue;
        }

        std::cout << "Fibonacci的计算结果为 " << n << ": " << fibonacci(n) << std::endl;

        char choice;
        std::cout << "您是否想要继续呢(y/n)? ";
        std::cin >> choice;

        if (choice != 'y') {
            break;
        }
    }

    return 0;
}
