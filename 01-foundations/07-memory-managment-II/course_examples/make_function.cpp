#include <cstdlib>
#include <iostream>
#include <memory>

/*There is new functionalities so you dont new to locate memory manually 
for the underlying resource. -> MAKE FUNCTIONS
*/

class Point{
public:
    Point(int x, int y){}
};

int main(){
    std::unique_ptr<int> p(new int{5});
    auto m = std::make_unique<int>(5); //It is a template that allocates automaticaty the resource into the memory
    auto pt = std::make_unique<Point>(3,5);
    //It is aplicable also to share pointers. And it accepts any kind of strcuture.

    auto w = std::make_shared<int>(7);
    //It is more complex than the share pointer: It contains more information.
    //More operations in the Constructor and Destructor.

    //DISADVANTAGE:
    //There is no way to define a custom deleter while using make function 
}