#include <bits/stdc++.h>
using namespace std;

// -------- Memoization --------
int solveMemoUtil(int ind, vector<int>& height, vector<int>& dp, int k) {
    if (ind == 0) return 0;
    if (dp[ind] != -1) return dp[ind];

    int mmSteps = INT_MAX;
    for (int j = 1; j <= k; j++) {
        if (ind - j >= 0) {
            int jump = solveMemoUtil(ind - j, height, dp, k) 
                       + abs(height[ind] - height[ind - j]);
            mmSteps = min(mmSteps, jump);
        }
    }
    return dp[ind] = mmSteps;
}

int solveMemo(int n, vector<int>& height, int k) {
    vector<int> dp(n, -1);
    return solveMemoUtil(n - 1, height, dp, k);
}


// -------- Tabulation --------
int solveTab(int n, vector<int>& height, int k) {
    vector<int> dp(n, 0);

    for (int i = 1; i < n; i++) {
        int mmSteps = INT_MAX;

        for (int j = 1; j <= k; j++) {
            if (i - j >= 0) {
                int jump = dp[i - j] 
                           + abs(height[i] - height[i - j]);
                mmSteps = min(mmSteps, jump);
            }
        }
        dp[i] = mmSteps;
    }
    return dp[n - 1];
}

int main() {
    vector<int> height{30, 10, 60, 10, 60, 50};
    int n = height.size();
    int k = 2;

    cout << "Memoization: " << solveMemo(n, height, k) << endl;
    cout << "Tabulation: " << solveTab(n, height, k) << endl;

    
    return 0;
}