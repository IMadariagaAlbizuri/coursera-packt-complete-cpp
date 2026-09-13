#include <iostream>

int main() {
    using namespace std;
    cout << "Hello world \n" << 45 << 8.2f << endl;
    int age;
    cout << "Tell me your age : ";
    cin >> age;
    cout << "Your age is : " << age << endl;
    char buffer[512]; // Read character from the keybord, until it encounters a space or enter key.
    // If we want it to read the full line we need to use the getline function. We will see that in the next exercise.
    cout << "What is your name : ";
    cin >> buffer;
    
    cin.getline(buffer, 512, '\n'); // The variable, the size and the delimiter.
    cout << "Your name is : " << buffer << endl;
    return 0;
}