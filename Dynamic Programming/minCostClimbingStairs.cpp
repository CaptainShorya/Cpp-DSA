#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Pure recursion -> TC = O(2^n)
int recursion(vector<int>& cost, int i, vector<int>& dp){
    if(i == 0 || i == 1) return cost[i];
    return cost[i] + min(recursion(cost, i-1, dp),recursion(cost, i-2, dp));
}

//Recursion + Memoization ->  TC = O(n) and SC = O(n)
int helper(vector<int>& cost, int i, vector<int>& dp){
    if(i == 0 || i == 1) return cost[i];
    if(dp[i] != -1) return dp[i];
    return dp[i] = cost[i] + min(helper(cost, i-1, dp),helper(cost, i-2, dp));
}

int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    vector<int> dp(n, -1); 
    // dp[i] -> the minimum cost to reach ith stair from top(ie. n)

    // return min(helper(cost, n-1, dp), helper(cost, n-2, dp));

    return min(recursion(cost, n-1, dp), recursion(cost, n-2, dp));

    
}

int main() {
    vector<int> cost = {1,100,1,1,1,100,1,1,100,1}; //{10,15,10}
    int n = cost.size();
    // cout << "Minimum Cost = " << minCostClimbingStairs(cost) << endl;

    cout << "Minimum Cost = " << minCostClimbingStairs(cost) << endl;

    //Tabulation -> TC = O(n) and SC = O(1) In-place DP Optimization
    // for(int i=2; i<n; i++){
    //     cost[i] = cost[i] + min(cost[i-1],cost[i-2]);
    // }
    // return min(cost[n-1],cost[n-2]);
}
