# Exercises

Hi everyone! Additionally to the course, I add up some exercises to practise the concepts learnt during the videos, which are:

1. **Calculator**

   Read two numbers and an operation from `cin` and the result is printed according to the operation selected.

   Four functions, `Add`, `Subtract`, `Multiply` and `Divide`. Also, add a `void PrintResult()` for the case of a function with no return value.

2. **Array statistics**

   An array of 10 integers initialized with braces, and three functions: `Max`, `Min` and `Average`. `Average` returns a `double`.

   An array passed to a function loses its size, so it goes as a second parameter.

3. **Geometry**

   `geometry.h` and `geometry.cpp` with the area and the perimeter of a circle, a rectangle and a triangle. `main.cpp` with a menu that asks for the shape and its dimensions.

   `const double PI{3.14159}`.

4. **Find in an array**

   A `Find()` function that receives an array, its size and a value, and returns a pointer to the element if it is there, or `nullptr` if it is not.

   In `main()`, check the returned pointer before dereferencing it. Once it is found, use the pointer to modify the element inside the array.

5. **Sensor toolbox -- [Last exercise with everything]**

   A program that reads 10 temperature measurements from `cin` and analyses them. Everything lives inside a `namespace Sensor`, split into `sensor.h` and `sensor.cpp`, and called from `main()` with the full name.

```cpp
   namespace Sensor {
       const double MIN_VALID{-40.0};
       const double MAX_VALID{125.0};

       inline bool IsValid(double v) { return v >= MIN_VALID && v <= MAX_VALID; }

       void MinMax(const double* data, int size, double& min, double& max);
       double Average(const double* data, int size);
       double* Find(double* data, int size, double value);
       void Apply(double* data, int size, double (*op)(double));
       void Print(const double* data, int size, int decimals = 2);

       double ToFahrenheit(double c);
       double Normalize(double c);
   }
```

   In `main()`:

   - Read the 10 values with a classic `for`, and reject the ones that do not pass `IsValid()`.
   - Call `MinMax()` and print both results. A function returns only one value, so the two of them come back as references.
   - Ask for a value and call `Find()`. Check the returned pointer against `nullptr` before dereferencing it, and if it is there modify the element through the pointer.
   - Ask which transformation to apply, declare the function pointer with `auto`, assign `ToFahrenheit` or `Normalize` to it and pass it to `Apply()`.
   - Print the array with a range-based for loop and `auto`, then scale every element with `auto&` in a second loop.
   - Print it again with `Print()`, once with the default decimals and once with 4.

   The functions that only read take a `const double*`, the ones that modify take a `double*`.

   Inside `sensor.cpp` the loops have to be classic `for` with an index, because the array arrives as  a pointer and has lost its size.