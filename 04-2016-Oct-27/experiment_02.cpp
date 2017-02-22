// Example program
#include <iostream>
#include <string>

int main()
{
    int number1, number2;
    std::cin >> number1 >> number2;
    
    std::cout << "Min" << std::endl;
    if (number1 < number2) {
        std::cout << number1;
    } else if (number1 > number2) {
        std::cout << number2;
    } else {
        std::cout << "Equal" << std::endl;
    }
}
