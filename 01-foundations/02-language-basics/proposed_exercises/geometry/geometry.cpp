/* Geometry Exercise 

A program to calculate the area and perimeter of one of these shapes:

1º Rectangle
2º Circle
3º Triangle

*/

#include <iostream>
#include "calculations.h"

const float pi = 3.14159;
int shape;
int option;

int main(){
    std::cout << "¡Geometry Calculator!" << std::endl;
    std::cout << "First lets choose the shape: " << std::endl;
    std::cout << "1º Rectangle" << std::endl;
    std::cout << "2º Circle" << std::endl;
    std::cout << "3º Triangle" << std::endl;
    std::cin >> shape;
    std::cout << "Now choose area or perimeter:: " << std::endl;
    std::cout << "1º Area" << std::endl;
    std::cout << "2º Perimeter" << std::endl;
    std::cin >> option;

    if (shape == 1 && option == 1) {
        float length, width;
        std::cout << "Please introduce the length: " << std::endl;
        std::cin >> length;
        std::cout << "Please introduce the width: " << std::endl;
        std::cin >> width;
        float area = calculateRectangleArea(length, width);
        std::cout << "The area of the rectangle is: " << area << std::endl;
    } else if (shape == 1 && option == 2) {
        float length, width;
        std::cout << "Please introduce the length: " << std::endl;
        std::cin >> length;
        std::cout << "Please introduce the width: " << std::endl;
        std::cin >> width;
        float perimeter = calculateRectanglePerimeter(length, width);
        std::cout << "The perimeter of the rectangle is: " << perimeter << std::endl;
    } else if (shape == 2 && option == 1) {
        float radius;
        std::cout << "Please introduce the radius: " << std::endl;
        std::cin >> radius;
        float area = calculateCircleArea(radius);
        std::cout << "The area of the circle is: " << area << std::endl;
    } else if (shape == 2 && option == 2) {
        float radius;
        std::cout << "Please introduce the radius: " << std::endl;
        std::cin >> radius;
        float perimeter = calculateCirclePerimeter(radius);
        std::cout << "The perimeter of the circle is: " << perimeter << std::endl;
    } else if (shape == 3 && option == 1) {
        float base, height;
        std::cout << "Please introduce the base: " << std::endl;
        std::cin >> base;
        std::cout << "Please introduce the height: " << std::endl;
        std::cin >> height;
        float area = calculateTriangleArea(base, height);
        std::cout << "The area of the triangle is: " << area << std::endl; 
    } else if (shape == 3 && option == 2) {
        float side1, side2, side3;
        std::cout << "Please introduce the first side: " << std::endl;
        std::cin >> side1;
        std::cout << "Please introduce the second side: " << std::endl;
        std::cin >> side2;
        std::cout << "Please introduce the third side: " << std::endl;
        std::cin >> side3;
        float perimeter = calculateTrianglePerimeter(side1, side2, side3);
        std::cout << "The perimeter of the triangle is: " << perimeter << std::endl;
    } else {
        std::cout << "Invalid option" << std::endl;
    }
    return 0;
}