#include <iostream>
using namespace std;

void printArray(int *ptr, int n){
    for(int i=0; i<n; i++){
        cout << *(ptr+i) <<endl;
    }
}
int main(){
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    printArray(arr,n);
    return 0;
}