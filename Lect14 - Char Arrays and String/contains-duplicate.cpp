#include <iostream>
using namespace std;

//Leetcode Problem - 217

bool duplicate(int arr[],int n){
    for(int i=0; i<n; i++){
        int elem = arr[i];
        for(int j=i+1; j<n; j++){
            if(elem == arr[j]){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int arr[] = {5,6,7,6};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << bool(duplicate(arr,size)) << endl;
    return 0;
}