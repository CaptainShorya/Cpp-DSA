#include <iostream>
using namespace std;

//Bubble Sort

void printArr(int arr[],int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void bubbleSort(int arr[],int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){ //Changing the sign will change the array's order into ascending or descending.
                swap(arr[j],arr[j+1]);
            }
        }
    }
    printArr(arr,n);
}

void bubbleSortOptimized(int arr[],int n){
    for(int i=0; i<n-1; i++){
        bool isSwap = false;
        cout<<"Outer Loop";
        for(int j=0; j<n-i-1; j++){
            cout<<"Inner Loop";
            if(arr[j]>arr[j+1]){ //Changing the sign will change the array's order into ascending or descending.
                swap(arr[j],arr[j+1]);
                isSwap = true;
            }
        }
        if(!isSwap){
            //Array is already sorted
            return;
        }
    }
    printArr(arr,n);
}

int main(){
    int arr[5] = {5,4,1,3,2};
    int arr2[10] = {1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(arr2)/sizeof(arr2[0]);

    // bubbleSort(arr,n);
    bubbleSortOptimized(arr2,n); //O(1,1)
    return 0;
}