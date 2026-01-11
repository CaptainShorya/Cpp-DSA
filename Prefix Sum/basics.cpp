#include <iostream>
#include <vector>
using namespace std;

//Prefix Sum

int main(){
    vector<int> nums = {1,2,3,4};
    for(int i=1; i<nums.size(); i++){
        nums[i] += nums[i-1];
    }
    // TC = O(n) and SC = O(1)
    for(int i=0; i<nums.size(); i++){
        cout << nums[i] << " ";
    }
}
