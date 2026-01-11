#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Reducing Dishes (Leetocode - 1402)

// Core Concept -> Greedy Method With Suffix Sum Approach

int main()
{
    vector<int> satisfaction = {-9,-1,-8,0,5};
    sort(satisfaction.begin(), satisfaction.end()); // O(nlogn)
    int n = satisfaction.size();
    int max_sum = 0;
    vector<int> suffixSum(n);
    suffixSum[n - 1] = satisfaction[n - 1];
    // Suffix Sum - Greedy Approach
    int idx = -1;
    for (int i = n - 2; i >= 0; i--)
    { // O(n)
        suffixSum[i] = satisfaction[i] + suffixSum[i + 1];
        if (suffixSum[i] >= 0)
            idx = i;
    }
    if (idx == -1)
        return 0;
    int time = 1;
    for (int i = idx; i < n; i++)
    {
        max_sum += satisfaction[i] * time;
        time++;
    }
    cout << max_sum << endl;
}