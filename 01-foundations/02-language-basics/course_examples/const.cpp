#include <iostream>

/*int main(){
    using namespace std;
    float radius = 0;
    cout << "Enter the radius of the circle: " << endl;
    cin >> radius;
    const float PI = 3.14159f;
    float area = PI * radius * radius;
    cout << "Area of circle: " << area << endl;
    float circumference = 2 * PI * radius;
    cout << "Circumference of circle: " << circumference << endl;
    return 0;
}*/


// USEFUL CASE
void Print(const int *ptr){
    using namespace std;
    cout << "Value: " << *ptr << endl;
}

/*Like that, if someone want to change the constant value, it will result in a compilation error.
It is a good practice to write the constant values in capital letters.*/

// How const behave with pointers and 

int main(){
   /*using namespace std;
    const int CHUNK_SIZE = 512;
    const int *ptr = &CHUNK_SIZE; // pointer to a constant integer
    *ptr = 1024; // Error: cannot modify the value of a constant integer through a pointer
    return 0;*/

    // The second case
    const int CHUNK_SIZE = 512;
    const int *const ptr = &CHUNK_SIZE; // constant pointer to a constant integer
    int x = 10;
    Print(&x);
    std::cout << "main -> x" << x << std::endl;
    return 0;
}

// So, if a pointer is constant, we can modify its value.