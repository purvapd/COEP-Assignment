#include <iostream>

int main() {
    int numerator, denominator;
    std::cout << "Enter numerator: ";
    std::cin >> numerator;
    std::cout << "Enter denominator: ";
    std::cin >> denominator;

    try {
        if (denominator == 0) {
            // Raise an exception for division by zero
            throw "Error: Division by zero!";
        } else {
            // Perform division
            double result = static_cast<double>(numerator) / denominator;
            std::cout << "Result: " << result << std::endl;
        }
    } catch (const char* exception) {
        // Catch the exception and handle it
        std::cout << "Exception caught: " << exception << std::endl;
    }

    return 0;
}
