// Example of operators

#include <iostream>

int main(){
    using namespace std;
    int x=10;
    cout << &x << endl; //The address of the operator.
    int *ptr = &x; //The pointer variable.
    cout << ptr << endl; //The pointer variable.
    *ptr = 20; //Dereferencing the pointer variable.
    cout << x << endl; //The value of the variable x.
    int y = *ptr; //Read from the operator
    cout << y << endl;
    return 0;
}