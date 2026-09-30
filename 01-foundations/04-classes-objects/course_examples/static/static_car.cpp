// The definitions of the function and classes used in statics example

#include "static_car.h"
#include <iostream>

int Car::totalCount=0;

//The constructors
Car::Car(){
    ++totalCount;
    std::cout << "Car()" << std::endl;
    fuel = 0;
    speed = 0;
    passengers = 0;
};

Car::Car(float amount){
    fuel = amount;
    speed = 0;
    passengers = 0;
}

void Car::FillFuel(float amount){
    fuel = amount;
};

void Car::Accelerate(){
    this->speed++;
    this->fuel -= 0.5f;
}

void Car::Brake(){
    speed=0;
}
//The destructor
Car::~Car(){
    --totalCount;
    std::cout << "Car() destructor" << std::endl;
};

void Car::AddPassengers(int count){
    passengers=count;
};

void Car::DashBoard(){
    std::cout << "Fuel: "<< fuel << std::endl;
    std::cout << "Speed: "<< speed << std::endl;
    std::cout << "Passengers: "<< passengers << std::endl;
};

void Car::ShowCount(){
    std::cout << "Total count: "<< totalCount << std::endl;
};