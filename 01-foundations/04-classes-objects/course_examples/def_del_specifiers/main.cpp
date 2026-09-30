#include <iostream>

class Integer{
    int m_Value{0}; // With this we dont need the default constructor
public:
    Integer() = default; //With this, the compiler will create a default implementation of this constructor
    // with out having to define it manually.
    /*Integer(){
        m_Value = 0;
    }*/
    Integer(int value){
        m_Value = value;
    }

    //Copy constructor
    //Integer(const Integer &) = default;

    //When we dont want anyone to create a copy of the integer object
    //To tell the compiler not to synthesize the copy constructor

    Integer(const Integer &) = delete;

    void SetValue(int value){
    m_Value = value;
    }

    //We avoid that a float number is introduced in setValue
    void SetValue(float value) = delete;

};

int main(){
    Integer i1;
    Integer i2(3);
    i1.SetValue(5);
    i2.SetValue(67.1f);
    return 0;
}