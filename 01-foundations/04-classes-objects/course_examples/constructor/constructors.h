#pragma one

class Car{
    private: 
        float fuel;
        float speed;
        int passengers;
    
    public:
        Car(float amount); // CONSTRUCTOR
        ~Car();  //Destructor
        void FillFuel(float amount);
        void Accelerate();
        void Brake();
        void AddPassangers(int count);
        void Dashboard();
};