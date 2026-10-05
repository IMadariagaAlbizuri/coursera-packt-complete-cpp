#include "Integer_copy.h"
#include <iostream>

Integer Add(const Integer &a, const Integer &b){
    //Integer temp;
    //temp.SetValue(a.GetValue() + b.GetValue());
    //Another better way is implementing a temporary object in the return statement
    return Integer(a.GetValue() + b.GetValue());
}

int main(){
    Integer a(1);
    Integer b(3);
    a.SetValue(Add(a, b).GetValue());
    return 0;
}