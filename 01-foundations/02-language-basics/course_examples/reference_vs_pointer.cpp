// Examples of the difference between references and pointers in C++.

#include <iostream>

void Swap(int x, int y) {
    int temp = x;
    x = y;
    y = temp;
}

void SwapPointers(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void SwapReferences(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}

void Print(int *ptr){
    using namespace std;
    if (ptr == nullptr) {
        cout << "Value pointed to by ptr: " << *ptr << endl;
    }
}

int main(){
    using namespace std;
    int a = 5, b = 10;
    Swap(a,b);
    cout << "After Swap function: a = " << a << ", b = " << b << endl; // Output: a = 5, b = 10
    /* As seen the values are not swapped 
    
    To do so, we need pointers
    
    Now we are passing addressess*/
    SwapPointers(&a, &b);
    cout << "After SwapPointers function: a = " << a << ", b = " << b << endl; // Output: a = 10, b = 5
    // It works!
    SwapReferences(a, b);
    cout << "After SwapReferences function: a = " << a << ", b = " << b << endl; // Output: a = 5, b = 10
    // Also with references. Easier to read that pointers.
    return 0;
}
/* If you pass a Pointer ALWAYS CHECK FOR NULLPTR. 
 If you pass a reference, you don't have to check for null. */