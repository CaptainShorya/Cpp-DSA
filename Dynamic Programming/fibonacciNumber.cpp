#include <iostream>
#include <vector>
using namespace std;

//Basic Recursion Way
int method_1(int n){
    if(n == 0 || n == 1) return n;
    return method_1(n-1) + method_1(n-2);
}

//Recursion + memoization(top down approach)
int method_2(int n, vector<int>& dp){
    if(n<=1) return n;
    if(dp[n] != -1) return dp[n];
    dp[n] = method_2(n-1,dp) + method_2(n-2,dp);
    return dp[n];
}

//Tabulation(bottom up approach) -> Iterative DP
int method_3(int n,vector<int> dp){
    for(int i=2; i<=dp.size(); i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int main(){
    int n = 5;
    vector<int> dp(n+1,-1); //Any value can't be -1, so choose -1 to initialize
    cout << method_1(n) << endl;
    cout << method_2(n,dp) << endl;
    vector<int> dp_3(n+1);
    dp_3[0] = 0;
    dp_3[1] = 1;
    cout << method_3(n,dp_3) << endl;
}