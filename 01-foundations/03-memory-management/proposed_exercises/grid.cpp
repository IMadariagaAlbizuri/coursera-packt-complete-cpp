// This file contains the definitos of the proposes functions
#include <iostream>
#include <iomanip>
#include "grid.h"

namespace Grid {
    // Allocates the grid in the heap and returns the pointer to the array of pointers
    int **Create(int rows, int cols){
        // First we create the pointer of pointers
        int **grid = new int *[rows];
        //Now we do a loop inside the pointers
        for (int i =0; i<rows; ++i){
            grid[i]=new int[cols]; //An array of integers
        }
        return grid;
    };

    // Releases the memory allocated by Create
    void Destroy(int **grid, int rows){
        for (int i=0; i<rows; ++i){
            delete[] grid[i];
        }
        delete[] grid;
    };


    // Asks the user for every value of the grid
    void Fill(int **grid, int rows, int cols){
        for (int i=0; i<rows; i++){
            for (int j=0; j<cols; j++){
                std::cout << "Value for row " << i << ", column " << j << ": ";
                std::cin >> grid[i][j]; 
            }
        }
    };

    // Prints all the elements of the grid
    void Print(const int *const *grid, int rows, int cols, int width){
        for (int i=0; i<rows; i++){
            for (int j=0; j<cols; j++){
                std::cout << std::setw(width) << grid[i][j];
            }
            std::cout << '\n';
        }
    };


    // Returns a pointer to the biggest element of one row
    int *RowMax(int *row, int cols){
        int *max= &row[0];
        for (int i=0; i<cols; i++){
            if(row[i]>*max){
                max = &row[i];
            }
        }
        return max;
    };

    // Calculates the average of all the elements of the grid
    double Average(const int *const *grid, int rows, int cols){
        float avg = 0.0;
        for (int i=0; i<rows; i++){
            for (int j=0; j<cols; j++){
                avg += grid[i][j];
            }
        }
        return avg /= (cols*rows);
    };

    // Changes the first appearance of a value and returns a pointer to it, or nullptr
    int *FindAndChange(int **grid, int rows, int cols, int value, int newValue){
        for (int i=0; i<rows; i++){
            for (int j=0; j<cols; j++){
                if(grid[i][j]==value){
                    grid[i][j] = newValue;
                    return &grid[i][j];
                }
            }
        }
        return nullptr;
    };
}