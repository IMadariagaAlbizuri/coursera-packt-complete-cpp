#include <iostream>
#include "sensor.h"

int main(){
    double data[10]={};
    for (int i = 0; i < 10; i++) {
    double dato;
    std::cout << "Introduce un valor" << std::endl;
    std::cin >> dato;

    while (!Sensor::IsValid(dato)) {
        std::cout << "Numero no valido / Rango: [-40.0, 125.0]" << std::endl;
        std::cin >> dato;
    }

    data[i] = dato;
    }

    double min=0.0;
    double max = 0.0;

    // Print the maximum and minimun values
    Sensor::MinMax(data, 10, min, max);
    std::cout << "Minimum: " << min << " / Maximum: " << max << std::endl;

    //Obtain the average
    double avg = Sensor::Average(data, 10);
    std::cout <<  "The average is: " << avg << std::endl;

    //Find a number
    double find;
    std::cout << "Find a number in the data?" << std::endl;
    std::cout << "Write number to be found: " << std::endl;
    std:: cin >> find;
    double *found = Sensor::Find(data, 10, find);

    if (found != nullptr) {
        std::cout << "Found. Write the new value: ";
        double newValue;
        std::cin >> newValue;
        *found = newValue;          // we modify the array through the pointer
    }
    else {
        std::cout << "The number is not in the data" << std::endl;
    }

    // Change metrics
    std::cout << "What to change metrics?" << std::endl;
    std::cout << "Select 1 for Celsius."<< std::endl;
    std::cout << "Select 2 for Farhenheit" << std::endl;

    int option;
    std::cin >> option;
    auto op = &Sensor::ToCelsius;
    if (option == 2) {
        op = &Sensor::ToFahrenheit;
    }

    Sensor::Apply(data, 10, op);

    // Print with the default decimals and with 4
    Sensor::Print(data, 10, 4);
    return 0;
}