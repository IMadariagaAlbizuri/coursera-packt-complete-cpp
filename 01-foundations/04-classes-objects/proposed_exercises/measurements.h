// The prototype of the class to be used and the struct Range
struct Range {
    double min;
    double max;
};

class Measurements{
private: 
    double *data{nullptr};
    int size{0};
    static int totalObjects;

public:
    // The Constructors
    Measurements(int size, double initial);
    Measurements();
    Measurements(int size);
    Measurements(const Measurements &other); 
    // The Destructor
    ~Measurements();
    //The method of the class
    void Set(int index, double value);
    double Get(int index) const; // It is a function that does not modify the object, if so, error will be generated
    int Size() const;
    double Average() const;
    void Print() const;
    Range GetRange() const;
    static int GetTotalObjects();
};