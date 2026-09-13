/* 
Array Statistics Exercise


Lets make the user introduce 10 numbers and then calculate their statistics:

1º Maximum
2º Minimum
3º Average

*/

#include <iostream>

int main() {
    using namespace std;
    int array[10];
    cout << "Some statistic of an array will be calculated: " << endl;
    cout << "Please introduce 10 numbers: " << endl;
    cout << "First number: ";
    cin >> array[0];
    cout << "Second number: ";
    cin >> array[1];
    cout << "Third number: ";
    cin >> array[2];
    cout << "Fourth number: ";
    cin >> array[3];
    cout << "Fifth number: ";
    cin >> array[4];
    cout << "Sixth number: ";
    cin >> array[5];
    cout << "Seventh number: ";
    cin >> array[6];
    cout << "Eighth number: ";
    cin >> array[7];
    cout << "Ninth number: ";
    cin >> array[8];
    cout << "Tenth number: ";
    cin >> array[9];

    int max = array[0];
    int min = array[0]; 
    float average = 0;

    for (int i = 1; i < 10; i++) {
        if (array[i] > max) {
            max = array[i];
            average += array[i];
        }
        if (array[i] < min) {
            min = array[i];
            average += array[i];
        }
    }

    cout << "Maximum: " << max << endl;
    cout << "Minimum: " << min << endl;
    average = average / 10.0;
    cout << "Average: " << average << endl;
    return 0;
}