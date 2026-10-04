#include "measurements.h"
#include <iostream>

// Initialize the static member variable
int Measurements::totalObjects{0};

// The definitions of the class methods
Measurements::Measurements(int size, double initial){
    this ->size = size;
    this ->data = new double[size];
    for(int i = 0; i < size; i++){
        data[i] = initial;
    }
    totalObjects++;
}

Measurements::Measurements() : Measurements(10, 0.0){}

Measurements::Measurements(int size) : Measurements(size, 0.0){}

Measurements::Measurements(const Measurements &other){
    this->size = other.size;
    this->data = new double[size];
    for(int i = 0; i < size; i++){
        data[i] = other.data[i];
    }
    totalObjects++;
}

Measurements::~Measurements(){
    std::cout << "Destructor called for Measurements object." << std::endl;
    delete[] data;
    totalObjects--;
}

void Measurements::Set(int index, double value){
    data[index] = value;
}

double Measurements::Get(int index) const{
    return data[index];
}

int Measurements::Size() const{
    return size;
}

double Measurements::Average() const{
    double avg = 0.0;
    for (int i = 0; i<size; i++){
        avg += data[i];
    }
    return avg / size;
}

void Measurements::Print() const{
    std::cout << "Measurements: ";
    for (int i = 0; i < size; i++){
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

Range Measurements::GetRange() const{
    double min = data[0];
    double max = data[0];
    for (int i=1; i<size; i++){
        if (data[i] < min){
            min = data[i];
        }
        if (data[i] > max){
            max = data[i];
        }
    }
    Range range{min, max};
    return range;
}

int Measurements::GetTotalObjects(){
    return totalObjects;
}
