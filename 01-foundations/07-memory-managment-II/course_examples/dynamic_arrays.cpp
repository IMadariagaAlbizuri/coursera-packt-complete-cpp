// It is posible to use smart pointer with dynamics arrays
#include <iostream>
#include <cstdlib>

int main() {
    std::unique_ptr<int> p{new int[5]{1,2,3,4,5}};
    //We can not access the array elements using the array syntax
    //p[0] = 10; 
    //How to get the elemnts
    p.get()[0]=10;
    //Solution -> Use a partial specialization of the smart pointer (int [])
    std::shared_ptr<int[]> q{new int[5]{1,2,3,4,5}};
    q[0]=100;
}