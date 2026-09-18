#include <iostream>

namespace Avg{
float Calculate(float x, float y){
    return (x+y)/2;
}}

namespace{
float Calculate(float x, float y){
    return x+y;
}}

int main(){
    float value = Avg::Calculate(3.9f, 8.2f);
    std::cout << value;
    return 0;
}