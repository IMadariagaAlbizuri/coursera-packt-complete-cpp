#include "Integer_one.h"
#include <iostream>

Integer operator+(const Integer &a, const Integer &b){
    Integer temp;
    temp.SetValue(a.GetValue() + b.GetValue());
    return temp;
}

//Global operator to add an Integer and a primitive int
Integer operator+(int a, const Integer &b){
    Integer temp;
    temp.SetValue(a + b.GetValue());
    return temp;
} // Now the sum2 expression will work

std::ostream & operator <<(std::ostream &out, const Integer &obj){
    out << obj.GetValue();
    return out;
} //With this not need to use GetValue() method to print the value of an Integer object, we can use the << operator directly with cout

std::istream & operator >>(std::istream &in, Integer &obj){
    int value;
    in >> value;
    //How to access private members of a class from a global function? -> Use friend functions
    *obj.m_pInt = 10; // This is possible because the operator<< function is a friend of the Integer class
    return in;
} //With this not need to use SetValue() method to set the value of an Integer object, we can use the >> operator directly with cin

int main(){
    Integer a(1), b(3);
    Integer sum = a + b; //Internally the compiler will use the overloaded operator+ method
    std::cout << "Sum: " << sum.GetValue() << std::endl;
    ++sum;
    std::cout << "Sum after increment: " << sum.GetValue() << std::endl;
    sum++;
    std::cout << "Sum after increment: " << sum.GetValue() << std::endl;
    Integer c;
    c=a;
    std::cout << "Value of c: " << c.GetValue() << std::endl;
    Integer sum2 = 5+a; // This wont work unless we define a global operator
    std::cout << "Sum2: " << sum2 << std::endl;
    std::cout << "Enter a new value for sum2: ";
    std::cin >> sum2; // This wont work unless we define a global operator
    std::cout << "New Sum2: " << sum2 << std::endl;
    return 0;
}