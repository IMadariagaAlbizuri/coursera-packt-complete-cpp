#include "Measurements_ms.h"
#include <iostream>

int main(){
    Measurements a(3, 1.0);
    Measurements b(a); // Copy constructor is called
    std::cout << " A is printed"<< std::endl;
    a.Print();
    std::cout << " B is printed"<< std::endl;
    b.Print();
    Measurements c(std::move(a)); // Move constructor is called
    std::cout << " C is printed after move constructor called"<< std::endl;
    c.Print();
    std::cout << " A is printed after move constructor called"<< std::endl;
    a.Print();

    Measurements d;
    d=b; // Copy assignment operator is called
    std::cout << " D is printed after copy assignment called"<< std::endl;
    d.Print();
    d=std::move(c); // Move assignment operator is called
    std::cout << " D is printed again after move assignment called"<< std::endl;
    d.Print();
    return 0;
}
