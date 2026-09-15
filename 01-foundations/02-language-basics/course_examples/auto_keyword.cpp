#include <iostream>

int SumTot(int x, int y){
    return x+y;
}
int main(){
    auto i = 10;
    auto j= 5;
    auto sum = i +4.3f;  // The type of sum is going to be the Larger size variable type

    auto result = SumTot(i,j);
    static auto y=2;
    const int x = 10;
    const auto var = x; // To var be constant with auto, consta must be declared.
    auto &var= y;
    auto list = {1,2,3,4};
    return 0;
}


// Auto works differently with variable that has volatile or const qualifiers.

