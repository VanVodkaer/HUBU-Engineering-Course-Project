#include <iostream>

using namespace std;

int main() { char op; double num1, num2; double result;

while (true) {
    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter operation (+, -, *, /): ";
    cin >> op;

    cout << "Enter second number: ";
    cin >> num2;

    switch (op) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
            } else {
                cout << "Error: Division by zero" << endl;
                continue;
            }
            break;
        default:
            cout << "Invalid operation" << endl;
            continue;
    }

    cout << "Result: " << result << endl;

    char choice;
    cout << "Do you want to continue (y/n)? ";
    cin >> choice;

    if (choice != 'y') {
        break;
    }
}

return 0;
}
