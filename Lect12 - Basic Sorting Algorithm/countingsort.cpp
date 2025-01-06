#include <iostream>
using namespace std;

//Counting Sort

void printArr(int arr[],int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void countingSort(int arr[],int n){
    int freq[10000];
    
    int minVal = INT32_MAX , maxVal = INT32_MIN;

    //1st Step - O(n) //Also,To find min and max of an array
    for(int i=0; i<n; i++){
        freq[arr[i]]++;
        minVal = min(minVal,arr[i]);
        maxVal = max(maxVal,arr[i]);
    }

    //2nd Step - O(range) = max - min
    for(int i=minVal , j=0; i<=maxVal; i++){
        while(freq[i]>0){
            arr[j++] = i;
            freq[i]--;
        }
    }
    printArr(arr,n);
}

int main(){
    int arr[] = {1,4,1,3,2,4,3,7};
    int n = sizeof(arr)/sizeof(arr[0]);

    countingSort(arr,n);
    return 0;
}