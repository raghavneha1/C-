#include <iostream>

int main() {
    double num1, num2;
    char operation;

    std::cout << "Enter the first number: ";
    std::cin >> num1;

    std::cout << "Enter the second number: ";
    std::cin >> num2;

    std::cout << "Choose an operation (+, -, *, /): ";
    std::cin >> operation;

    switch (operation) {
        case '+':
            std::cout << num1 << " + " << num2 << " = " << num1 + num2 << "\n";
            break;
        case '-':
            std::cout << num1 << " - " << num2 << " = " << num1 - num2 << "\n";
            break;
        case '*':
            std::cout << num1 << " * " << num2 << " = " << num1 * num2 << "\n";
            break;
        case '/':
            if (num2 != 0) {
                std::cout << num1 << " / " << num2 << " = " << num1 / num2 << "\n";
            } else {
                std::cout << "Error: Division by zero is not allowed.\n";
            }
            break;
        default:
            std::cout << "Invalid operation. Please choose from +, -, *, or /.\n";
            break;
    }

    return 0;
}
