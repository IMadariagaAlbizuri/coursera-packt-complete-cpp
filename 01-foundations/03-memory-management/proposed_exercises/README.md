9. **Dynamic grid**

   A program that asks the user for the number of rows and columns of a grid, allocates it on the
   heap and works with it. Everything inside a `namespace Grid`, split into `grid.h` and `grid.cpp`.

```cpp
   namespace Grid {
       int **Create(int rows, int cols);
       void Destroy(int **grid, int rows);

       void Fill(int **grid, int rows, int cols);
       void Print(const int *const *grid, int rows, int cols, int width = 4);

       int *RowMax(int **grid, int cols);
       double Average(const int *const *grid, int rows, int cols);

       void Apply(int **grid, int rows, int cols, int (*op)(int));

       int Double(int v);
       int Negate(int v);
   }
```

   - `Create()` allocates the array of pointers and then every row, and returns the `int**`.
   - `Fill()` asks the user for every value, or fills it with `rand()` if you prefer not to type
     them all.
   - `RowMax()` receives one row and returns a pointer to its biggest element. In `main()`, use that
     pointer to set the element to 0, and print the grid to see that it changed.
   - `Apply()` takes a function pointer and transforms every element. Declare it with `auto` in
     `main()`.
   - `Destroy()` frees the rows first and then the array of pointers, and the caller sets the pointer
     to `nullptr` afterwards.
   - Count your `new` and your `delete[]` calls at the end: they must match.