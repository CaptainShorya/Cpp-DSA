#include <iostream>
using namespace std;

int secondLargestElem(int arr[],int size){
    int largest = arr[0];
    for(int i=0; i<(size-1); i++){
        if(arr[i] < arr[i+1]){
            largest = arr[i+1];
        }
    }
    cout << largest << endl;
    
    int secondlargest = 0;
    for(int j=0; j<(size-1); j++){
        if(arr[j] < arr[j+1]){
            secondlargest = arr[j+1];
        }
    }
}

int main(){
    int arr[] = {10,30,25,400,100};
    int size =  sizeof(arr)/sizeof(arr[0]);
    secondLargestElem(arr,size);
    return 0;
}