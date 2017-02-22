// Example program
#include <iostream>
#include <string>

int main()
{
    int myVariable = 5;
    int expressionValue = 0;
    
    std:: cout << myVariable << std::endl;
    
    expressionValue = (myVariable--);
    std:: cout << myVariable << std::endl;
    std:: cout << "Exp value" << expressionValue << std::endl;
    
    expressionValue = (--myVariable);
    
    std:: cout << myVariable << std::endl;
    std:: cout << "Exp value" << expressionValue << std::endl;
}
