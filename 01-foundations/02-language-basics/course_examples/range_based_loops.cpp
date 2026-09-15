#include <iostream>

int main(){
    using namespace std;

    int arr[]={1,2,3,4,5};
    for (int i=0; i<5; i++){
        cout << arr[i] << "";
    }
    for (auto &x: arr){
        cout << x <<" ";
    }

    int *beg = &arr[0];
    int *end = &arr[5];

    while(beg != end){
        std::cout << *beg << " " ;
        ++beg;
    }

    //Functions already include in C++ for pointers
    int *end1 = std::end(arr);
    int *beg1 = std::begin(arr); 
    while(beg1 != end1){
        std::cout << *beg1 << " " ;
        ++beg1;
    }

    auto range = arr;
    auto begin = std::begin(arr);
    auto ending = std::end(arr);

    for (; begin != ending; ++begin){
        auto v = *begin;
    };
    

}