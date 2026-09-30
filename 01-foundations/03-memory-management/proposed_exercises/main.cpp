#include <iostream>
#include "grid.h"

int main() {
    // Dimensions of the grid
    int rows, cols;
    std::cout << "Number of rows: ";
    std::cin >> rows;
    std::cout << "Number of columns: ";
    std::cin >> cols;

    if (rows <= 0 || cols <= 0) {
        std::cout << "Rows and columns must be positive.\n";
        return 1;
    }

    // Fill it
    int **grid = Grid::Create(rows, cols);
    Grid::Fill(grid, rows, cols);

    std::cout << "\nGrid:\n";
    Grid::Print(grid, rows, cols);

    // Obtain the average
    std::cout << "\nAverage: " << Grid::Average(grid, rows, cols) << '\n';

    // Obtain the Maximun on the final row
    int *pMax = Grid::RowMax(grid[rows-1], cols);
    std::cout << "Adress of the maximum of the last row is: " << *pMax << '\n';

    // Print the original grid
    std::cout << "Printing original grid \n";
    Grid::Print(grid, rows, cols);

    // Change the first 9 for a 3
    int *pChanged=Grid::FindAndChange(grid,rows,cols,9,3);

    if (pChanged==nullptr){
        std::cout << "Number not found";
    }
    else{
        std::cout << "Grid changed \n";
        Grid::Print(grid,rows,cols);
    }


    // End the code -> Free the resources
    Grid::Destroy(grid, rows);
    grid = nullptr;  
    return 0;
}