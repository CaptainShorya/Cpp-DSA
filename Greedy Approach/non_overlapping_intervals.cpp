// Leetcode 435 -> Non Overlapping Intervals
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //Start time sort approach 
        auto cmp = [](vector<int>& a, vector<int>& b){
            return a[0] < b[0];
        };
        sort(intervals.begin(),intervals.end(),cmp);
        int count = 0; // Number of intervals removed
        int lastEnd = intervals[0][1];
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0] < lastEnd){ // overlap 
                count++;
                lastEnd =min(lastEnd,intervals[i][1]);
            }else{ // no overlap -> intervals[i][0] >= lastEnd  
                lastEnd = intervals[i][1]; 
                // if vector would be here,we insert over intervals[i] in it and if not we do not increase the interval counter
            }
        }
        return count;
    }
};