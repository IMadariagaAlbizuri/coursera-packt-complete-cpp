#include <iostream>

int Add(int a, int b){
    return a+b;
} // It only works with integer, if we want to use dobles, the result will be 
// modified and reduced to integer values. To overcame this problem, we use function overload.


// The function will be overload, when the arguments are different.
double Add(double a, double b){
    return a+b;
}
int main(){
    using namespace std;
    int result = Add(3,5);
    cout << result << endl;
    Add(3.1, 6.2);
    cout << result << endl;
    return 0;
}