#include <iostream>
using namespace std;

void printArr(int arr[]){ //Array passed as a reference in a function argument , No copy forms here it directly points to the array
    cout << arr << endl;  //0x...
    // cout << sizeof(arr) << endl; //Output -> 8 -> size of int pointer (Mam ke system m run kr rha tha )
    arr[0] = 1000; 
}

void printArr2(int *ptr){
    *ptr = 1000;
}
int main(){
    int a = 5;
    int *ptr = &a;
    cout << ptr << endl;

    int arr[] = {1,2,3,4,5};
    cout << arr << endl; //This points to 0th index element of array. //Output -> 0x...
    cout << *arr << *(arr+1) <<endl; //Output -> 1 2

    printArr(arr); //Passing array name is equivalent to passing the pointer.
    cout<< arr[0]<<endl;
    return 0;
}