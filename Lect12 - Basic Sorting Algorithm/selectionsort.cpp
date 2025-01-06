#include <iostream>
using namespace std;

//Selection Sort

void printArr(int arr[],int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void selectionSort(int arr[],int n){
    for(int i=0; i<n-1; i++){ //To place element in their sorted order
        int minIdx = i;
        for(int j=i+1; j<n; j++){ //loop for finding out minimum value'th index from the array
            if(arr[j]<arr[minIdx]){
                minIdx = j;
            }
        }
        swap(arr[i],arr[minIdx]);
    }
    printArr(arr,n);
}

int main(){
    int arr[] = {5,4,1,3,2};
    int n = sizeof(arr)/sizeof(arr[0]);

    selectionSort(arr,n);
    return 0;
}