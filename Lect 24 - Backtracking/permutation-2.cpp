#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution { // TC = O(n! * n) and SC = O(n) Auxiliary Space(Map) and O(n) Recursive Stack
public:
    int n;
    vector<vector<int>> result;
    void permutations(unordered_map<int,int> mpp, vector<int>& permVec){
        if(permVec.size() == n){
            result.push_back(permVec);
            return;
        }
        for(auto &it : mpp){ // Pass by reference so that we can change the frequency of element
            if(it.second > 0){
                // BackTracking Approach 
                permVec.push_back(it.first);
                it.second -= 1;
                permutations(mpp,permVec);
                it.second += 1;
                permVec.pop_back();
            }  
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        unordered_map<int,int> mpp;
        for(int num : nums) mpp[num]++;
        vector<int> permVec;
        permutations(mpp,permVec);
        return result;
    }
};

// Optimal Swap based Solution
class Solution {
public:

    int n;
    vector<vector<int>> result;

    void permutations(int index, vector<int>& nums){
        if(index == n){
            result.push_back(nums);
            return;
        }
        unordered_set<int> st;
        for(int i=index; i<n; i++){
            if(!st.count(nums[i])){
                st.insert(nums[i]);
                swap(nums[i],nums[index]); // do 
                permutations(index+1,nums); // explore
                swap(nums[i],nums[index]); // undo
            } 
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        permutations(0,nums);
        return result;
    }
};