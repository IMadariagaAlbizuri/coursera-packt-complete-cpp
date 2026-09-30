#include "Car.h"
#include <iostream>

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
