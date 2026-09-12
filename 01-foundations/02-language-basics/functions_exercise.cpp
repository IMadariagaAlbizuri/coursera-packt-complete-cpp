#include <iostream>
#include "Math.h" // Always include header files

// Prototypes of the functions
// int Add(int x, int y);

int main() {
    int x, y;
    std::cin >> x >> y;
    //int result = x+y;
    //std::cout << "The sum of " << x << " and " << y << " is : " << result << std::endl;
    //int result = Add(x, y);
    //Use the result
    int last_result = Multiply(x, y);
    std::cout << "The product of " << x << " and " << y << " is : " << last_result << std::endl;
    return last_result;
}

//Definition of the function
//int Add(int x, int y) {
//  int sum = x + y;
// std::cout << "The sum is : " << sum << std::endl;
//    return sum;
//}
//It is necesary to use the return if the function has a return type declared.

/* When we use a function, first the compilor need to know that the function exists, so we need to declare the function before using it. 
This is done by using a function prototype. The function prototype is a declaration of the function that tells the compiler about the function's name, return type, and parameters. 
The function prototype is usually placed at the top of the file or in a header file. */


/*If we want to use a function that is defined in another file, we need to include the header file that contains the function prototype. 
 This is done by using the #include directive. The header file should be included at the top of the file before any other code. */
