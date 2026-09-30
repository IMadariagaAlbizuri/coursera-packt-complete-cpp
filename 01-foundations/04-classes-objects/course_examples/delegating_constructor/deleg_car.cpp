// The definitions of the function and classes used in statics example

#include "deleg_car.h"
#include <iostream>

int Car::totalCount=0;

//Multiple constructors for one class-> These is a source of bugs
/* Car::Car(){
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

Car::Car(float amount, int pass){
    ++totalCount;
    speed = 0;
    fuel = amount;
    passengers= pass;
}*/

//How to fix it! -> By initializing the rest of constructor by using a main one.

Car::Car():Car(0){}

Car::Car(float amount):Car(amount,0){}

Car::Car(float amount, int pass){
    ++totalCount;
    speed = 0;
    fuel = amount;
    passengers= pass;
} //This is the main template

void Car::FillFuel(float amount){
    fuel = amount;
}

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