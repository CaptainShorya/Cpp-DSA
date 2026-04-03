// Maximize Sum of Array After K Negotiations
#include <iostream>
#include <queue>
#include <vector>
using namespace std;


class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int num : nums){
            pq.push(num);
        }
        while(k != 0){
            int val = pq.top();
            pq.pop();
            pq.push(val*(-1));
            k--;
        }
        int sum = 0;
        while(!pq.empty()){
            int val = pq.top();
            sum += val;
            pq.pop();
        }
        return sum;
    }
};