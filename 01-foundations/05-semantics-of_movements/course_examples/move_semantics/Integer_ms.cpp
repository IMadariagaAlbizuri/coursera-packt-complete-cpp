#include "Integer_ms.h"
#include <iostream>

//Definitions of the constructors
Integer::Integer(){
    std::cout << "Integer()" << std::endl;
    m_pInt = new int(0);
}

Integer::Integer(int value){
    std::cout << "Integer(int)" << std::endl;
    m_pInt = new int(value);
}

Integer::Integer(const Integer &obj){
    std::cout << "Integer(const Integer&)" << std::endl;
    m_pInt = new int(*obj.m_pInt);
}

// Move constructor
Integer::Integer(Integer &&obj){
    std::cout << "Integer(Integer&&)" << std::endl;
    m_pInt = obj.m_pInt;
    obj.m_pInt = nullptr;
}

//The Get and Set methods
int Integer::GetValue() const{
    return *m_pInt;
}

void Integer::SetValue(int value){
    *m_pInt = value;
}

//The destructor
Integer::~Integer(){
    std::cout << "~Integer()" << std::endl;
    delete m_pInt;
}