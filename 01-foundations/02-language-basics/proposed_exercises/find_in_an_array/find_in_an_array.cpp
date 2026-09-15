/* In this exercise an array is given with 20 numbers randomly selected from 1 to 100.

    If the number is in the array, the pointer to the memory place is given.
    Else a null pointer is given.
*/

#include <iostream>
#include <random>

int main(){
    int array[20];
    int number;
    int counter = 0;
    std::random_device rd; 
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<> distrib(1, 100);
    for (int i=0; i<20; i++){
        array[i] = distrib(gen);
        std::cout << array[i] << " ";
    };

    std::cout << "Select the number to be found in the array, from 1 to 100: "<< std::endl;
    std::cin >> number;
    for(int i=0; i<20; i++){
        if(number == array[i]){
            auto *pointer = &array[i];
            std::cout << "Pointer value in :" << pointer << std::endl; 
            counter += 1;
        }
    }
    if(counter == 0){
        std::cout << "Pointer value in : nullptr";
    }
    return 0;
}
