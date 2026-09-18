#include <iostream>

void Print(int count, char ch){
    using namespace std;
    for (int i=0; i < count; i++){
        cout << ch;
    }
}

void EndMassage(){
    using namespace std;
    cout << "End of progam" << endl;
}

int main(){
    atexit(EndMassage);
    Print(5, '#');
    void(*pnf) (int, char)= Print;
    (*pnf)(8, '@');
    pnf(5, '+');
    using namespace std;
    cout << "End of main" << endl;
    return 0;
}