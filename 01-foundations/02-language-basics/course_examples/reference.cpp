#include <iostream>

int main(){
    using namespace std;
    //referent
    int x = 10;
    //reference
    int &ref = x; // ref is a reference to x
    cout << "Value of x: " << x << endl; // Output: Value of x: 10
    cout << "Value of ref: " << ref << endl; // Output: Value of ref: 10
    // Modifying the value of x through the reference
    x=20;
    cout << "Value of x after modification: " << x << endl; // Output: Value of x after modification: 20
    cout << "Value of ref after modification: " << ref << endl; // Output:
    ref=30; // Modifying the value of x through the reference
    cout << "Value of x after modifying ref: " << x << endl; // Output
    cout << "Value of ref after modifying ref: " << ref << endl; // Output: Value of ref after modifying ref: 30
    return 0;
}