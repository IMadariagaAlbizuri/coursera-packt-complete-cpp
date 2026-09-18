#include <stdio.h>
#include <stdlib.h>
#include <iostream>

void Malloc(){
    //int *p = (int*)calloc(5, sizeof(int));
    int *p = (int*)malloc(5*sizeof(int));
    if (p==NULL){
        printf("Failled to allocate memory\n");
    }
    *p = 5;
    printf("%d", *p);
    //free(p)
    p= NULL;
}

void New(){
    int *p = new int;  // It allocated the pointer in the memory automatically
    *p = 6;
    std::cout << *p << std::endl;
    delete p;
    p = nullptr;
}

void NewArray(){
    int *p = new int[5];
    for (int i=0; i<5; i++){
        p[i]=i;
    }
    delete []p; // If it is the last line of the function
    // no need to use p=nullptr, because it will be destroyed.
}

void Strings(){
    char *p = new char[4]; //For strings yoy always has to allocate an extra byte for the null terminating caracter.
    strcpy_s(p,4, "C++");
    std::cout << p << std::endl;
    delete []p;
}
//New it is also capable of initializing in the memory

void TwoD(){
    int *p1 = new int[3];
    int *p2 = new int[3];

    int **pData = new int *[2]; // A 1D array of pointers, where each point to an array

    pData[0] = p1;
    pData[1] = p2;

    pData[0][1]=2; //Second element of the first row
    
    // How to free the memory
    delete []p1; //delete []pData[0];
    delete []p2; //delete []pData[1];

    delete []pData;

    //Important the number of delete must match with the number of new calls.
}


int main() {
    NewArray();
}

//Ctrl+Shift+P Memory Inspector: Show Memory Inspector to see p or anything in the memory