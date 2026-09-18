// Here we define the declarations of the functions in sensors

#include <iostream>
#include "sensor.h"
#include <iomanip> //Ajusta el cout y el print.

namespace Sensor{
    // We define the definitions of the functions

    // Minimun & Maximum values of the data
    void MinMax(const double *data, int size, double &min, double &max){
        for(int i=0; i<size; i++){
            if(*(data+i)<min){
                min=*(data+i);
            }
            if(*(data+i)>max){
                max=*(data+i);
            }
        }
    }

    // Average value of the data
    double Average(const double *data, int size){
        double avg{};
        for(int i=0; i<size; i++){
            avg += *(data+i);
        }
        return avg / size;
    }

    // Find a value
    double *Find(double *data, int size, double value){
        for(int i=0; i<size; i++){
            if (value==*(data+i)){
                return data+i;
            }}
        return nullptr;

    }

    // Print all the numbers of the collected data
    void Print(const double *data, int size, int decimals){
        std::cout << std::fixed << std::setprecision(decimals); //We want to print with that precision
        for (int i=0; i<size; i++){
            std::cout << *(data+i)<< std::endl;
        }
        std::cout << std::endl;
    }

    // It applies the operation Fahrenheit or Celsius to the data
    void Apply(double *data, int size, double (*op)(double)){
        for(int i=0; i<size; i++){
            *(data+i)=op(*(data+i));
        }
    }

    // Function to convert numbers into Fahrenheit scale
    double ToFahrenheit(double c){
        return (c * 1.8) + 32;
    }

    // Function to convert numbers into Celsius scale
    double ToCelsius(double f){
        return (f-32)/1.8;
    }
}  