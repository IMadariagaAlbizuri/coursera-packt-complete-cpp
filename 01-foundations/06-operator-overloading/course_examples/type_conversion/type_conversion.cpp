#include <iostream>
#include "integer_tc1.h"

class Product{
    Integer m_Id;
public:
    Product(const Integer &id){
        std::cout << "Product(const Integer &)" << std::endl;
    }
    ~Product(){
        std::cout<< "~";
    }

    const Integer & GetInteger()const{
        return m_Id;
    }

    operator Integer(){
        return m_Id;
    }
};

void Print(const Integer &a){

}

int main(){
    int a=5, b=2;
    float f = a; //Even if the types are different, the compilor allowed this.
    // The compiler will implicitly conver the integer into a float.
    float m = a/b; // -> This will make data loss -> The division will be integer, lossing the decimal values.
    std::cout << m << std::endl;
    float l = (float)a /b; // This are C style cast

    // Static cast -> It check if the casting is allowed
    float k = static_cast<float>(a)/b;
    char *p = (char*)&a; // This type of casting is not right
    // Pointer types are not casteable
    // char *s = static_cast<char*>(&a);
    
    // We can make this cast work by using re-interpret cast
    char *s = reinterpret_cast<char*>(&a);

    const int x = 1;
    int *r = const_cast<int*>(&x);

    // FROM PARAMETER TYPE TO USER-DEFINED TYPE
    Integer a1{5}; // Constructor takes part of type conversion
    // The compiler will search for the constructor that has the correct argument type

    Print(5);

    // The other case -> The assignment operator
    a1 = 7; // It will use the copy or the move assigment.
    //THEIR IS A BIG DIFFERENCE: ONE IS ASSIGNMENT AND THE OTHER ONE IS INITIALIZATION

    //IF THE MARK THE CONSTRUCTOR WITH EXPLICT
    //explicit Integer(int value){} -> TO AVOID AUTOMATIC CASTING.

    //NOW FROM USER-DEFINE TYPE TO PRIMITIVE TYPE
    int v = static_cast<int>(a1); //TYPE CONVERSION OPERATOR FUNCTION

    // CONVERSION BETWEEN USER DEFINED TYPES
    Product p3{5};
    Integer id = p3;  //The compilor will automatically use the defined type convertion operator
    // id = p.operator Integer();

    Integer id6{6};
    return 0;
}

//NOTE: WE SHOULD ALWAYS USE THE CASTING OPERATORS, NOT THE C STYLE CAST
