#include <iostream>
#include <vector>
using namespace std;

//Merge Sort Algorithm 

void merge(int arr[], int si, int ei, int mid){
    vector<int> temp;

    int i = si, j = mid+1;

    while(i <= mid && j <= ei){
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i++]); //a++ -> first used then incremented
        }else{
            temp.push_back(arr[j++]);
        }
    }

    while(i <= mid){
        temp.push_back(arr[i++]);
    }
    while(j <= ei){
        temp.push_back(arr[j++]);
    }

    //Copy temp to array
    for(int idx=si , x=0; idx<=ei; idx++){
        arr[idx] = temp[x++]; 
    }

}

void mergeSort(int arr[], int si, int ei){
    if(si == ei){
        return;
    }

    int mid = si + (ei - si)/2; // si + (ei - si)/2 -> This way of writing is better as it avoid data overflow problem

    mergeSort(arr, si, mid); //Left
    mergeSort(arr, mid+1, ei); //Right

    merge(arr, si, ei, mid);
}

void printArr(int arr[], int n){
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main(){
    int arr[6] = {6,3,7,5,2,4};
    int n = 6;

    mergeSort(arr,0,n-1);
    printArr(arr,n);
    return 0;
}