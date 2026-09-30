// Example of classes

#pragma once

class Car{
    private: //Normally the attributes are private
        float fuel;
        float speed;
        int passengers;
    
        // The behaviour should be public
    public:
        void FillFuel(float amount);
        void Accelerate();
        void Brake();
        void AddPassangers(int count);
        void Dashboard();
};

