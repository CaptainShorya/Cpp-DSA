#include <iostream>
#include <vector>
using namespace std;

//Maximum Sum Subarray of Size K
int bruteForce(vector<int> vec, int k, int n){ // TC : O(k*n)
    int maxSum = INT8_MIN;
    for(int i=0;i<=n-k; i++){ // total ops = n-k+1
        int currSum = 0;
        for(int j=i; j<i+k; j++){ // total ops = k
            currSum += vec[j];
        }
        if(currSum > maxSum){
            maxSum = currSum;
        }
    }
    return maxSum;
}

//Sliding Window Approach -> TC : O(n)
int sliding_window(vector<int> vec, int k, int n){
    int prevSum = 0;
    int maxSum = INT16_MIN;
    for(int i=0; i<k; i++){ // total ops = k
        prevSum += vec[i];
    }
    int i = 1;
    int j = k;
    while(j<n){ // total ops = n-k
        maxSum = max(prevSum,maxSum);
        prevSum = prevSum + vec[j] - vec[i-1];
        j++;
        i++;
    }
    return maxSum;
}

int main(){
    vector<int> vec = {7,1,2,5,8,4,9,3,-6};
    int k = 4;
    int n = vec.size();
    // cout << bruteForce(vec,k,n) << endl;
    cout << sliding_window(vec,k,n) << endl;
}