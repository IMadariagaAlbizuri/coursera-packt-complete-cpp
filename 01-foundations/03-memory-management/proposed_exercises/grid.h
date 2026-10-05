// The prototype declaration of the functions to be used
#pragma once
namespace Grid {
    // Allocates the grid in the heap and returns the pointer to the array of pointers
    int **Create(int rows, int cols);

    // Releases the memory allocated by Create
    void Destroy(int **grid, int rows);

    // Asks the user for every value of the grid
    void Fill(int **grid, int rows, int cols);

    // Prints all the elements of the grid
    void Print(const int *const *grid, int rows, int cols, int width = 4);

    // Returns a pointer to the biggest element of one row
    int *RowMax(int *row, int cols);

    // Calculates the average of all the elements of the grid
    double Average(const int *const *grid, int rows, int cols);

    // Changes the first appearance of a value and returns a pointer to it, or nullptr
    int *FindAndChange(int **grid, int rows, int cols, int value, int newValue);
}