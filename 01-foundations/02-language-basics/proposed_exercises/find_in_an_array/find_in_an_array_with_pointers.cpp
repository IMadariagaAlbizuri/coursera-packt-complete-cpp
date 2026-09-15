/* Is the same exercise than find an element in the array one, but in this case
   to access the element, we will do it with pointers
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
    std::cout << std::endl;

    std::cout << "Select the number to be found in the array, from 1 to 100: "<< std::endl;
    std::cin >> number;
    int *pnt_array = array;
    for(int i=0; i<20; i++){
        if(number == *(pnt_array+i)){
            counter += 1;
            std::cout << "Number Found! Pointer value: " << (pnt_array+1) << std::endl;
        }
    }
    return 0;
}
