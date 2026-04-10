//Minimum Distance Between Three Equal Elements 1
#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        // Solution where there exist 4 instance of a integer value
        if(nums.size() < 3) return -1;
        unordered_map<int,vector<int>> mpp;
        int ans = INT_MAX;
        for(int i=0; i<nums.size(); i++) mpp[nums[i]].push_back(i);
        for(auto num : mpp){
            if(num.second.size() >= 3){
                for(int i=0; i<num.second.size()-2; i++){
                    int a = mpp[num.first][i];
                    int b = mpp[num.first][i+1];
                    int c = mpp[num.first][i+2];
                    ans = min(ans,abs(a-b) + abs(b-c) + abs(c-a));
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;   
    }
};