#include <iostream>
#include "Integer_sp.h"
#include <memory> //A C++ library for smart pointers

class IntPtr{
    Integer *m_p;
public:
    IntPtr(Integer *p):m_p(p){

    }
    ~IntPtr(){
        delete m_p;
    }
    Integer *operator ->(){
        return m_p;
    }

    Integer & operator *(){
        return *m_p;
    }
};
void Process(std::unique_ptr<Integer> ptr){
    std::cout << ptr->GetValue() << std::endl;
}
void CreateInteger(){
    std::unique_ptr<Integer> p(new Integer); //It is used when you dont want to share the underlying resource
    //We can not create a copy of the unique pointer auto p2(p) [ERROR]
    //However, you can move it.
    Process(std::move(p));

    //We can use another smat pointer
    std::shared_ptr<Integer> m(new Integer);
    //When the reference count is 0, the memory will be released
    //Now with this pointer, we can make copies.
    (*p).SetValue(3);
    //p->SetValue(3);
    //std::cout << p->GetValue() << std::endl;
    //delete p;
}

int main(){
    CreateInteger();
    return 0;
}

//To avoid memory leaks, we using an idiom called as Resource acquisition is initialization.

//With this idiom, the life time of the resource is bound to a local object.
//So, when the local object is destroyed, it will automatically realease the resource (the destructor).

//Using RAII we have bound the resource to the lifetime of the local object

//Like that, we create a local object that behaves like a pointer
//but the resources are realeased when the object lifecycle is done.
//Making it a SMART POINTER.

//It is recommended to use smart pointer that raw pointers