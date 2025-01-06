#include <iostream>
using namespace std;

//Find Largest Number in the array

int main(){
    int arr[] = {1,4,2,10,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int max = arr[0];
    int min = arr[0];
    for(int i=0; i<n; i++){
        if(arr[i] > max){
            max = arr[i];
        }
        if(arr[i] < min){
            min = arr[i];
        }
    }
    cout<<"Largest Number in the array : "<<max<<endl;
    cout<<"Smallest Number in the array : "<<min<<endl;
    return 0;
}