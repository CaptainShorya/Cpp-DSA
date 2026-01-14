#include <iostream>
#include <vector>
using namespace std;

//Minimum Size Subarray Sum 

int main(){
    vector<int> vec = {1,2,3,4,6,3,4,3};
    int n = vec.size();
    int target = 10;
    int i = 0;
    int j = 0;
    int sum = 0;
    int minLen = INT16_MAX;
    while(j<n){
        sum += vec[j];
        while(sum >= target){
            minLen = min(minLen,j-i+1);
            sum -= vec[i];
            i++;
        }
        j++;
    }
    cout << minLen << endl;
}