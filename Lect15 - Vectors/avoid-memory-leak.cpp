#include <iostream>
using namespace std;

void funcInt(){
    int *ptr = new int;
    *ptr = 5;
    cout << *ptr << endl;
    delete ptr;
}

void funcArr(){
    int size;
    cin >> size;

    int *arr = new int[size];
    int x=1;
    for(int i=0; i<size; i++){
        arr[i] = x;
        cout << arr[i] << " ";
        x++;
    }
    delete [] arr;
    return;
}

int main(){
    funcInt();
    funcArr();
    return 0;
}