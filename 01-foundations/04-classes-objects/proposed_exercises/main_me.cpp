#include "measurements.h"
#include <iostream>

int main(){
    // Create a Measurements object with 5 elements initialized to 10.0
    Measurements m1(5, 10.0);
    m1.Print();
    Measurements m2(3, 20.0);
    m2.Print();
    // Copy the m2 object and moddify it
    Measurements m3(m2); 
    m3.Set(0, 30.0); 
    m3.Print();
    m2.Print(); 

    // Display the average of m2 and m3
    std::cout << "Average of m2: "<< m2.Average() << std::endl;
    std::cout << "Average of m3: "<< m3.Average() << std::endl;

    // Print the total number of Measurements objects created
    std::cout << "Total Measurements objects: " << Measurements::GetTotalObjects() << std::endl;

    // The counter inside a block: the object is destroyed at the closing brace
    {
        Measurements c;
        std::cout << "Inside the block: " << Measurements::GetTotalObjects() << std::endl;
    }
    std::cout << "After the block: " << Measurements::GetTotalObjects() << std::endl;

    // A const object can only call const functions
    const Measurements k(5, 2.0);
    std::cout << "Average of k: " << k.Average() << std::endl;
    // k.Set(0, 1.0);   // error: Set is not const
}