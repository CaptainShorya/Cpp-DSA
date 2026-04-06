// 452. Minimum Number of Arrows to Burst Balloons
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        auto cmp = [](vector<int>& a, vector<int>& b){
            return a[0] < b[0];
        };
        sort(points.begin(),points.end(),cmp);
        int ans = 1;
        vector<int> vec = points[0];
        for(int i=1; i<points.size(); i++){
            vector<int> curr = points[i];
            if(curr[0] <= vec[1]){ // overlap occured
                int left = max(curr[0],vec[0]);
                int right = min(curr[1],vec[1]);
                vec = {left,right};
            }else{
                vec = points[i]; // 
                ans++;
            }
        }
        return ans;

    }
};