#include <iostream>

//Returns r-value
int Add(int x, int y) {
    return x + y;
}

//Returns l-value -> Returns by reference
int & Transform(int &x) {
    x *= x;
    return x;
}

void Print(int &x) {
    std::cout << "Print(int &)" << std::endl;
}
void Print(int &&x) {
    std::cout << "Print(int &&)" << std::endl;
}

//void Print(const int &x) {
//    std::cout << "Print(const int &)" << std::endl;
//}

int main(){
    //x, y & z are l-values & 5, 10 & 8 are r-values
    int x=5;
    int y=10;
    int z=8;

    //Expression returns r-value
    int result = (x+y) * z;

    //Expression returns l-value
    ++x=6;

    int &&r1 = 10;
    int && r2 = Add(5, 10);

    //We can not bind r-value reference to l-value
    //int && r3 = x; //Error

    //We can bind l-value reference to l-value
    int & l1 = x;

    //But we can not bind l-value reference to r-value
    //int & l2 = 10; //Error

    //However, we can bind an l-value reference to a function that returns an l-value
    int & l3 = Transform(x);

    //An l-value reference can bind to a temporary, if it is a constant
    const int & l4 = 3;

    int m = 10;
    Print(x); //Print(int &)
    Print(10); //Print(int &&)
    
    return 0;
}