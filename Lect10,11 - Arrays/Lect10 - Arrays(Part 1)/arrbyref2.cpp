#include <iostream>
using namespace std;

void printarr(int nums[],int n){
    cout << nums << endl;
    // int n = sizeof(num)/sizeof(num[0]); //Taking this statement here, we don't get our desired output as size of num is size of int pointer(it is pointing to 0th index of the array of main function)
    for(int i=0; i<n; i++){
        cout << nums[i] << " ";
    }
    cout<<endl;
}

int main(){
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    printarr(arr,n);
    return 0;
}