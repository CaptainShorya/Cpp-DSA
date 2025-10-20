#include <iostream>
using namespace std;

void printMax(int arr[], int n, int idx, int max){ //Print largest element code using max variable
    if(n == idx){
        cout << max;
        return;
    }
    if(max<arr[idx]) max = arr[idx];
    printMax(arr,n,idx+1,max);
}

int maxInArray(int arr[], int n, int idx){ //Print largest element without using max variable 
    //M1
    // if(idx+1 == n){
    //     return arr[idx];
    // }
    // if(arr[idx] > arr[idx+1]) arr[idx+1] = arr[idx];

    //M2
    if(idx == n) return INT16_MIN;
    return max(arr[idx],maxInArray(arr,n,idx+1)); 
}

int main(){
    int arr[] = {2,3,7,1,4,9,0,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    // printMax(arr,n,0,INT16_MIN);
    cout << maxInArray(arr,n,0);
}