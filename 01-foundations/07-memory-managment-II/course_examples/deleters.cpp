#include <cstdlib>
#include <iostream>

struct Free{
    void operator()(int *p){
        free(p);
        std::cout << "pointer freed\n";
    }
};

void MallocFree(int *p){
    free(p);
    std::cout <<"pointer freed\n";
}

void UniquePtrDeleters(){
    //std::unique_ptr<int, Free> p{(int*) malloc(4), Free{}}; //To define the deleter (Must be an object->STRONG RECOMMENDATION ;))
    std::unique_ptr<int, void (*) (int *)> p {(int*) malloc(4), MallocFree};
    *p = 100;
    std::cout << *p << '\n';
    //free(p); for malloc we must declare free, for new delete
    //The smart pointers by default will call delete, not the corresponding memory free method.

    //The smart pointer invokes a deleter. A callback that releases the resource.
    //So, if we want to delete a certain resource, we can define a new deleter.
}

void SharedPtrDeleters(){
    //std::unique_ptr<int, Free> p{(int*) malloc(4), Free{}}; //To define the deleter (Must be an object->STRONG RECOMMENDATION ;))
    std::shared_ptr<int> p {(int*) malloc(4), MallocFree};
    *p = 100;
    std::cout << *p << '\n';
} 
// For share pointers you dont need to specify the type of the deleter

int main(){
    SharedPtrDeleters();
}

//EXAMPLE OF DEFINING THE TYPE OF DELETERS FOR THE POINTERS. -> FOR ANY KIND OF RESOURCE.