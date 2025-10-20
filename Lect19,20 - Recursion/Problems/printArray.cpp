#include <iostream>
using namespace std;

void display(int arr[], int n, int i){
    if(n == i) return;
    cout << arr[i++] << " ";
    display(arr,n,i);
}

int main(){
    int arr[] = {2,3,5,6,7,1,9,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    display(arr,n,0);
}