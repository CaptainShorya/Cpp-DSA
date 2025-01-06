#include <iostream>
using namespace std;

//O(n^3)
void maxSubArraySum(int *arr, int n){
    int maxSum = INT32_MIN;
    for(int start=0; start<n; start++){
        for(int end=start; end<n; end++){
            int currSum = 0;
            for(int i=start; i<=end; i++){
                currSum += arr[i];
            }
            cout<<currSum<<",";
            maxSum = max(maxSum,currSum);
        }
        cout<<endl;
    }
    cout<<"Maximum sum of subArray : "<<maxSum<<endl;
}

//Slightly Optimized -> O(n^2)
void maxSubArraySumOptimized(int *arr, int n){
    int maxSum = INT32_MIN;
    for(int start=0; start<n; start++){ // 2
        int currSum = 0;
        for(int end=start; end<n; end++){ // 2,3,4,5
            currSum += arr[end];
            cout<<currSum<<",";
            maxSum = max(maxSum,currSum);
        }
        cout<<endl;
    }
    
}

//Kadane's Algorithm
void maxSubArraySumKA(int *arr, int n){
    int maxSum = INT32_MIN;
    int currSum = 0;
    for(int i=0; i<n; i++){
        currSum += arr[i];
        maxSum = max(maxSum,currSum);
        if(currSum < 0){
            currSum = 0;
        }
    }
    cout<<"Maximum sum of subArray : "<<maxSum<<endl;
}

int main(){
    int arr[] = {2,-3,6,-5,4,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    maxSubArraySumKA(arr,n);
    return 0;
}