// Here we declare the prototypes of the functions used in sensor toolbox.
namespace Sensor{
    // We define the constants
    const double MinVal{-40.0};
    const double MaxVal{125.0};
    // We define the inline Function
    inline bool IsValid(double v){ return v >= MinVal && v <= MaxVal;};
    // We define the prototypes of the functions
    void MinMax(const double *data, int size, double &min, double &max);
    double Average(const double *data, int size);
    double *Find(double *data, int size, double value);
    void Apply(double *data, int size, double (*op)(double));
    void Print(const double *data, int size, int decimals = 2);
    double ToFahrenheit(double c);   
    double ToCelsius(double c);       
}  