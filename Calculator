
#include <iostream>
#include <limits>
#include <cmath>

void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

double readDouble(const std::string &prompt) {
    double value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) {
            clearInput();
            return value;
        } else {
            std::cout << "Invalid number. Please try again.\n";
            clearInput();
        }
    }
}

long long readLongLong(const std::string &prompt) {
    long long value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) {
            clearInput();
            return value;
        } else {
            std::cout << "Invalid integer. Please try again.\n";
            clearInput();
        }
    }
}

void printMenu() {
    std::cout << "\nChoose an operation:\n\n";
    std::cout << "Press 1 For Add (+)\n";
    std::cout << "Press 2 For Subtract (-)\n";
    std::cout << "Press 3 For Multiply (*)\n";
    std::cout << "Press 4 For Divide (/)\n";
    std::cout << "Press 5 For Modulus (%) (integers)\n";
    std::cout << "Press 6 For Power (x^y)\n";
    std::cout << "Press 7 Exit\n";
}

int main() {

    while (true) {
        printMenu();
        int choice = static_cast<int>(readLongLong("\n Enter choice (1-7): "));
        switch (choice) {
            case 1: {
                double a = readDouble("Enter first number: ");
                double b = readDouble("Enter second number: ");
                std::cout << "Result: " << (a + b) << "\n";
                break;
            }
            case 2: {
                double a = readDouble("Enter first number: ");
                double b = readDouble("Enter second number: ");
                std::cout << "Result: " << (a - b) << "\n";
                break;
            }
            case 3: {
                double a = readDouble("Enter first number: ");
                double b = readDouble("Enter second number: ");
                std::cout << "Result: " << (a * b) << "\n";
                break;
            }
            case 4: {
                double a = readDouble("Enter numerator: ");
                double b = readDouble("Enter denominator: ");
                if (b == 0.0) {
                    std::cout << "Error: Division by zero is not allowed.\n";
                } else {
                    std::cout << "Result: " << (a / b) << "\n";
                }
                break;
            }
            case 5: {
                long long a = readLongLong("Enter first integer: ");
                long long b = readLongLong("Enter second integer: ");
                if (b == 0) {
                    std::cout << "Error: Division by zero (modulus by zero) is not allowed.\n";
                } else {
                    std::cout << "Result: " << (a % b) << "\n";
                }
                break;
            }
            case 6: {
                double a = readDouble("Enter base: ");
                double b = readDouble("Enter exponent: ");
                double res = std::pow(a, b);
                std::cout << "Result: " << res << "\n";
                break;
            }
            case 7:
                std::cout << "Come Back When You Have Math to Solve ! \n";
                return 0;
            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 7.\n";
        }
    }
    return 0;

}
