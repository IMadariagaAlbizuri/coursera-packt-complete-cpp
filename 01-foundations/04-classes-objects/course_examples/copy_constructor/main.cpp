#include "integer.h"
#include <iostream>

//In these cases, the copy of the values are pased to the functions
void Print(Integer i){

}

Integer Add(int x, int y){
    return Integer(x+y);
}

int main(){
    int *p1 = new int(5);
    //Shallow copy
    int *p2 = p1; // It copies the address -> This make it crash
    
    //Deep Copy 
    int *p3 = new int(*p1);//We copy the value of the pointer rather than the address

    Integer i(5);

    //Copy of the object manually
    Integer i2(i);  //Problem, it crashes due to the copy of the pointer
    // Now with deep copy, it does not crash.

    // A copy is also created through assignment
    i = i2;
    std::cout << i.GetValue() << std::endl;

    return 0;
}