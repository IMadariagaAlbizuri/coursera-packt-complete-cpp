#include "constructors.h"

int main(){
    //Create the car object
    Car Car(10.0);
    Car.Accelerate();
    Car.Accelerate();
    Car.Accelerate();
    Car.Accelerate();
    Car.Dashboard();

    return 0;
}

// As it can be seen the attributes of the Car class are not initialized.

//To initialize them, we need the constructor.