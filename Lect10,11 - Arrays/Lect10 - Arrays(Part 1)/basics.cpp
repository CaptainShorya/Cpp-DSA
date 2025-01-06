#include <iostream>
using namespace std;
int main(){
    // int marks[50];
    // int marks2[50] = {1,2,3};
    // int marks3[] = {1,2,3,4};
    // cout<<marks[0]<<endl;

    //Output and Input Array
    // int arr[] = {7,5,3,1};
    // int n = sizeof(arr)/sizeof(arr[0]);

    // for(int i=0; i<n; i++){
    //     cout<< arr[i] << " ";
    // }
    // cout<<endl;
    
    //Dynamically creating array
    int n;
    cout << "Enter size of array : ";
    cin >> n;

    int arr[n];

    for(int i=0; i<n; i++){
        cin >>arr[i];
    }

    for(int j=0; j<n; j++){
        cout << arr[j] << " ";
    }

    
    return 0;
}