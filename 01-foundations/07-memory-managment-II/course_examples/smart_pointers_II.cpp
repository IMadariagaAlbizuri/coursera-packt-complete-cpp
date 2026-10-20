#include "Integer_sp_II.h"
//TO USE THE UNIQUE POINTER
#include <memory>

void Display(Integer *p){
    if(!p){
        return ;
    }
    std::cout<< p-> GetValue() << std::endl;
}

/*
The GertPointer function is like a factory function
that creates an instance of a class*/
Integer * GetPointer(int value){
    Integer *p = new Integer{value};
    return p;
}

//Pass the unique pointer into a function
void Store(std::unique_ptr<Integer> p){
    std::cout << "Storing the data into a file: " << p-> GetValue() << std::endl;
}

void Operate(int value){
    //Integer *p = GetPointer(value);
    std::unique_ptr<Integer> p{GetPointer(value)}; //Initialization of the smart pointer unique 
    if (p==nullptr){
        //p=new Integer{value};
        p.reset(new Integer{value});
        /* RESET WILL DO TWO THING:
        1º If the smart pointer object holds an existing pointer, 
        that will be deleted first.
        2º It will take ownership of this pointer*/
    }
    p->SetValue(100);
    //Display(p);
    Display(p.get());
    //p.get() will get the pointer of the object unique pointer
    //delete p; -> We can not deleted it, it does it automatically
    //p=nullptr; -> Deleting the unique pointer, not the memory
    p.reset();
    //p=new Integer{};
    *p = __LINE__;
    Display(p.get());
    Store(std::move(p)); //Will move the state of the object.
    //TO BE ABLE TO USE AGAIN THE P POINTER, WE SHOULD CHANGE
    //THE STORE FUNCITON AN PASS THE POINTER AS A REFERENCE.
    //delete p;
}

int main(){
    Operate(5);
}

// The code becomes a little hard to read!

// WRITTING CODE LIKE THIS IN C++ IS NOT RECOMMENDED.

// WE SHOULD USE SMART POINTERS.

//WITH THE SMART POINTERS THE CODE BECOMES EASIER TO READ.

//YOU CAN NOT CREATE A COPY OF THE UNIQUE POINTER, BUT WE CAN ALWAYS MOVE IT.
