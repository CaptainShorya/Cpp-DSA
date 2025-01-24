#include <iostream> 
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;

//Subarray Sum equals K 
int countSubarraySumEqualsK(vector<int> vec, int k ){
    unordered_map<int,int> mpp; //<sum,count>
    mpp[0] = 1;
    int count = 0;
    int sum = 0;

    for(int i=0; i<vec.size(); i++){
        sum += vec[i];
        if(mpp.count(sum - k)){ //Check whether sum-k lies or not (if it lies then their must be atleast a subarray with sum = k)
            count += mpp[sum-k];
        }
        if(mpp.count(sum)){ //appending map with subarray sum by iterating over all the indexes.
            mpp[sum]++;
        }else{
            mpp[sum] = 1; 
        }
    }
    return count;
}


int main(){
    vector<int> arr = {10,2,-2,-20,10};
    int k = -10;

    cout << countSubarraySumEqualsK(arr,k);
    return 0;
}