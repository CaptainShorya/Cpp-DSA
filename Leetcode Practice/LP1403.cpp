// LP1403 : Minimum Subsequence in Non-Increasing Order
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        vector<int> vec;
        sort(nums.begin(),nums.end());
        int totalSum = 0;
        for(int num : nums) totalSum += num;
        int currSum = 0;
        for(int i=nums.size()-1; i>=0; i--){
            if((totalSum/2) >= currSum){
                vec.push_back(nums[i]);
            }
            currSum += nums[i];
        }
        return vec;
    }
};