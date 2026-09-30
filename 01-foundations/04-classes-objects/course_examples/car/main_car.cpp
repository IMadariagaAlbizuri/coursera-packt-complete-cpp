#include "Car.h"

int main(){
    //Create the car object
    Car car;
    car.FillFuel(6);
    car.Accelerate();
    car.Accelerate();
    car.Accelerate();
    car.Accelerate();
    car.Dashboard();

    return 0;
}

// As it can be seen the attributes of the Car class are not initialized.

//To initialize them, we need the constructor.