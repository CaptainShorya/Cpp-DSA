#include <iostream>
using namespace std;

//Insertion Sort

void printArr(int arr[],int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void insertionSort(int arr[],int n){
    //O(n^2) 
    for(int i=1; i<n; i++){ //Loop is for 1st element of unsorted array
        int curr = arr[i];
        int prev = i-1;
        while(prev>=0 && arr[prev] > curr){ //To reverse our condition,just change the sign of the comparision operator here
            swap(arr[prev],arr[prev+1]);
            prev--;
        }
        arr[prev+1] = curr;
    }
    printArr(arr,n);
}

int main(){
    int arr[] = {5,4,1,3,2};
    int n = sizeof(arr)/sizeof(arr[0]);

    insertionSort(arr,n);
    return 0;
}
