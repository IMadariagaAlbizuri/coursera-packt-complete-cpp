# **Classes exercise**

    A class that owns an array of measurements on the heap. Split into `measurements.h`, `measurements.cpp` and `main_me.cpp`.

```cpp
    struct Range {
        double min;
        double max;
    };

    class Measurements {
    private:
        double *data{nullptr};
        int size{0};
        static int totalObjects;

    public:
        Measurements(int size, double initial);   // the one with the real code
        Measurements();                           // delegates: 10 elements, value 0
        Measurements(int size);                   // delegates: value 0
        Measurements(const Measurements &other);  // deep copy
        ~Measurements();

        void Set(int index, double value);
        double Get(int index) const;
        int Size() const;
        double Average() const;
        Range GetRange() const;
        void Print() const;

        static int GetTotalObjects();
    };
```

    - The main constructor allocates the array with `new[]` and fills it with `initial`. Name its parameters like the members and use `this->`.
    - `totalObjects` goes up in the constructors and down in the destructor. The destructor releases
      the array with `delete[]` and prints a message.
    - Every function that only reads must be `const`. `GetRange()` returns a `Range` struct.
    
    - In `main()`, create two objects, copy one of them, modify the copy and print both to check that the original did not change.
    - Open a block `{ }` in the middle of `main()`, create an object inside, and print
      `Measurements::GetTotalObjects()` before, inside and after the block.
    - Create a `const Measurements` and call `Average()` on it. Then try to call `Set()` and read the error.
    - Try to assign one object to another with `=` and read the error.