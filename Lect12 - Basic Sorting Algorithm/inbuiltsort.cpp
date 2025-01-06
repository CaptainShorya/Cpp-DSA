#include <iostream>
#include <algorithm>
using namespace std;

//Counting Sort

void printArr(int arr[],int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[8] = {1,4,1,3,2,3,4,7};
    //Ascending Order
    sort(arr, arr+7); //Sort from 0th index to 7th index
    // sort(arr+2,arr+5); //Sort from 2nd index to 5th index

    //Descending Order
    // sort(arr,arr+8,greater<int>());
    printArr(arr,8);
}