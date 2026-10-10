#include <iostream>
#include "Integer_sp.h"

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

/* Integer Integer::operator+(const Integer &a) const{
    Integer temp;
    *temp.m_pInt = *m_pInt + *a.m_pInt;
    return temp;
}*/

Integer & Integer::operator++(){
    ++(*m_pInt);
    return *this;
}

Integer & Integer::operator++(int){
    Integer temp(*this);
    ++(*m_pInt);
    return temp;
}

Integer & Integer::operator=(const Integer &obj){
    if (this == &obj){ //Self-assignment check -> To avoid bugs
        delete [] m_pInt;
        m_pInt = new int(*obj.m_pInt);}
    return *this;
}

Integer & Integer::operator=(Integer &&obj){
    if (this != &obj){ //Self-assignment check -> To avoid bugs
        delete [] m_pInt;
        m_pInt = obj.m_pInt;
        obj.m_pInt = nullptr;
    }
    return *this;

}
