#include "static_car.h"

int main(){
    Car::ShowCount();
    Car car(4);
    car.Accelerate();
    car.Accelerate();
    car.Accelerate();
    car.Accelerate();
    car.DashBoard();

    Car c1;
    Car c2;

    Car::ShowCount();

    return 0;
}