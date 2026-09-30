#include "constructors.h"
#include <iostream>

// Constructor
Car::Car(float amount){
    // Do not forget to initialize the other values
    fuel = amount;
    speed = 0;
    passengers = 0;
};

//Destructor
Car::~Car(){
    std::cout << "Car() destructor" << std::endl;
};

void Car::FillFuel(float amount){
    fuel = amount;
}

void Car::Accelerate(){
    speed++;
    fuel -= 0.5f;
}

void Car::Brake(){
    speed = 0;
}

void Car::AddPassangers(int count){
    passengers = count;
}

void Car::Dashboard(){
    std::cout << "Fuel: "<< fuel << std::endl;
    std::cout << "Speed: "<< speed << std::endl;
    std::cout << "Passangers: "<< passengers << std::endl;
}