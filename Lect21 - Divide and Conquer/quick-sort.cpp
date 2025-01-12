#include <iostream>
#include <vector>
using namespace std;

int partition(int arr[], int si, int ei){ //
    int i = si - 1; //return pivotIdx and place pivot elem to its right index position (And also place other elem with less than or greater than prespective with the pivot)
    int pivot = arr[ei];
    for(int j=si; j<ei; j++){
        if(arr[j] <= pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    i++;
    swap(arr[i],arr[ei]); //Why not pivot here (for arr[ei]) -> pivot(local variable) but we need swap numbers in array that's why
    //pivotIdx - i
    return i;
}

void quickSort(int arr[], int si, int ei){ // avg case -> O(n*logn) , worst case -> O(n^2)
    //Base case 
    if(si >= ei){
        return;
    }

    int pivotIdx = partition(arr,si,ei);
    quickSort(arr,si,pivotIdx-1); // left
    quickSort(arr,pivotIdx+1,ei); // right

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

    quickSort(arr,0,n-1);
    printArr(arr,n);

    return 0;
}