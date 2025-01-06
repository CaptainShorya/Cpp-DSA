#include <iostream>
using namespace std;

int main(){
    //Static Memory Allocation
    // int arr[100] = {1,2,3,4,5};

    //Dynamic Memory Allocation
    int size;
    cin >> size;

    int *arr = new int[size]; //arr pointer points towards this memory allocated

    int x = 1;
    for(int i=0; i<size; i++){
        arr[i] = x;
        cout << arr[i] << " ";
        x++;
    }
    return 0;
}

//Do this for vector
//Write this in terminal to avoid error while running program -> g++ -std=c++11 dynamic-memory-allocation.cpp