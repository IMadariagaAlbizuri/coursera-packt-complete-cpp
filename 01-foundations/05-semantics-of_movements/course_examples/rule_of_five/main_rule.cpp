#include "integer_rule.h"

class Number{
    /* In this class, the compiler will synthesize the copy and move constructors and assignment operators, because we have not defined them explicitly. 
    The compiler will generate them based on the members of the class. 
    In this case, since m_Value is of type Integer, which has its own copy and move semantics defined, the compiler-generated functions will use those.*/
    Integer m_Value{};
public:
    Number(int value): m_Value(value){
    }
    //What will happen if I provide a copy constructor
    Number(const Number &obj): m_Value(obj.m_Value){
    }   
    // Now the move operator will not synthesize the move operations
    // It also happens if I provide only a Destructor, etc.
};

Number CreateNumber(int num){
    Number n{num};
    return n;
}

int main(){
    Number n1{1};
    auto n2{n1};
    n2=n1;

    auto n3{CreateNumber(3)};
    n3= CreateNumber(3);
}