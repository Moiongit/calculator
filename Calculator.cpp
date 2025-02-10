#include <iostream>
using namespace std;

int main() {
    double firstNum, secondNum, result;
    char op;
    char choice;

    do {
        cout << "Enter first num: ";
        cin >> firstNum;

        cout << "What operation to use: ";
        cin >> op;

        cout << "Enter second num: ";
        cin >> secondNum;

        if (op == '+') {
            result = firstNum + secondNum;
        } else if (op == '-') {
            result = firstNum - secondNum;
        } else if (op == '*') {
            result = firstNum * secondNum;
        } else if (op == '/') {
            result = firstNum / secondNum;
        } else {
            cout << "Invalid operator!" << endl;
            continue;  
        }

        cout << "Result: " << result << endl;

        cout << "Perform another calculation? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    return 0;
}
