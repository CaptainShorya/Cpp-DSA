#include <iostream>
#include <vector>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mindiff(int i, vector<int>& dp, vector<int>& height){
        // Memoization
        if(i == 0) return 0;

        if(dp[i] != -1) return dp[i];

        int left = mindiff(i-1, dp, height) + abs(height[i] - height[i-1]);

        int right = INT_MAX;
        if(i > 1)
            right = mindiff(i-2, dp, height) + abs(height[i] - height[i-2]);

        return dp[i] = min(left, right);
    }

    int minCost(vector<int>& height) {
        vector<int> dp(height.size(), -1);
        return mindiff(height.size()-1, dp, height);
    }
};

void mindiffTab(vector<int>& dp, vector<int>& height){
        // dp[i] = minimum cost to reach stone i
        // Tabulation
        dp[0] = 0;
        for(int i=1; i<height.size(); i++){
            int left = dp[i-1] + abs(height[i] - height[i-1]);

            int right = INT_MAX;
            if(i > 1)
                right = dp[i-2] + abs(height[i] - height[i-2]);
            dp[i] = min(left, right);
        }
    }

int main() {
    int n;
    cout << "Enter number of stones: ";
    cin >> n;

    vector<int> height(n);
    cout << "Enter heights: ";
    for(int i = 0; i < n; i++){
        cin >> height[i];
    }

    // Solution obj;
    // cout << "Minimum Cost: " << obj.minCost(height);

    vector<int> dp(height.size(),-1);
    mindiffTab(dp,height);
    cout << dp[n-1] << endl;
    return 0;
}