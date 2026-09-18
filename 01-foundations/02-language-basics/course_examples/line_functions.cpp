#include <iostream>

//int Square(int x){
//    return x*x;
//}

//#define Square(x) x*x; // Macro defines, but it has problem (bugs).

inline int Square(int x){
    return x*x;
}
int main(){
    using namespace std;
    int val =5;
    int result = Square(val);
    cout << result << endl;
    return 0;
}