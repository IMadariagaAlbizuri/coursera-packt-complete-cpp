/* Lets create a simple calculator that can perform basic arithmetic operations:
    1º - Addition
    2º - Subtraction
    3º - Multiplication
    4º - Division
*/

#include <iostream>
#include "operations.h"

void PrintResult(float result);


int main(){
    std::cout << "Welcome to the simple calculator!" << std::endl;
    std::cout << "Please enter two numbers: ";
    float a, b;
    std::cout << "First number: ";
    std::cin >> a;
    std::cout << "Second number: ";
    std::cin >> b;

    std::cout << "Please select an operation: " << std::endl;
    std::cout << "1 - Addition" << std::endl;
    std::cout << "2 - Subtraction" << std::endl;
    std::cout << "3 - Multiplication" << std::endl;
    std::cout << "4 - Division" << std::endl;

    int operation;
    std::cout << "Enter the number corresponding to the operation: ";
    std::cin >> operation;
    float result;
    if (operation == 1){
        result = add(a, b);
    }
    else if (operation == 2){
        result = subtract(a, b);
    }
    else if (operation == 3){
        result = multiply(a, b);
    }
    else if (operation == 4){
        result = divide(a, b);
    }
    PrintResult(result);

    return 0;
}

void PrintResult(float result){
    std::cout << "The result is: " << result << std::endl;
};