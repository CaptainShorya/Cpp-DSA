// Leetcode 56 -> Merge Intervals
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution { // Sort via end time -> We merge in Right to Left Direction and vice versa true
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) { 
        sort(intervals.begin(), intervals.end(), cmp);

        vector<vector<int>> result;
        int n = intervals.size();

        // Start from last interval
        result.push_back(intervals[n - 1]);

        for (int i = n - 2; i >= 0; i--) {
            vector<int> curr = intervals[i];
            if (curr[1] >= result.back()[0]) {
                // Overlapping case
                result.back()[0] = min(result.back()[0], curr[0]);
                result.back()[1] = max(result.back()[1], curr[1]);
            } else {
                result.push_back(curr);
            }
        }
        reverse(result.begin(),result.end());
        return result;
    }
};