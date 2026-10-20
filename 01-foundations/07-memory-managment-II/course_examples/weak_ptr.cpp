#include <iostream>

class Printer {
    std::weak_ptr<int> m_pValue{};
public:
    void SetValue(std::weak_ptr<int> p){
        m_pValue = p;
    }
    void Print(){
        std::cout << "Ref count: "<< m_pValue.use_count() << std::endl;
        if(m_pValue.expired()){
            std::cout << "Resource is no longer available " << std::endl;
            return ;
        } //Chech if there is any shared ptr
        auto sp = m_pValue.lock(); //This will return a shared ptr
        std::cout<<"Value is: " << *sp <<std::endl;
        std::cout<<"Ref count: "<<sp.use_count() <<std::endl; 
    }
};

int main(){
    Printer prn;
    int num{};
    std::cin >> num;
    std::shared_ptr<int> p(new int{num});
    prn.SetValue(p);
    if(*p>10){
        p=nullptr;
    }
    prn.Print();
}

//The weak pointer helped us in pointing weakly to a resource that may or may not be available.

//Available -> Use lock().
//Not Available -> Nothing to do. Do a return.
