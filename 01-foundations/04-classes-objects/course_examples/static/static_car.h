// The header file for the static example class 
class Car{
    private:
        float fuel;
        float speed;
        int passengers;
        static int totalCount;

    public:
        Car();
        Car(float amount);
        ~Car();
        void FillFuel(float amount);
        void Accelerate();
        void Brake();
        void AddPassengers(int count);
        void DashBoard();
        static void ShowCount();
};