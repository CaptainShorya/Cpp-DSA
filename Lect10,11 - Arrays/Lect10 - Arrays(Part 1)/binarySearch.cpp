#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key){
    int start = 0 , end = n - 1;
    while(start<=end){
        int mid = (start+end)/2;
        if(arr[mid] == key){
            return mid;
        }
        else if(arr[mid] < key){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return -1;
}

int main(){
    int arr[] = {2,3,4,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<binarySearch(arr,n,3)<<endl;
    return 0;
}