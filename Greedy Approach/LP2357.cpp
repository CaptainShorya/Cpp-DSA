// Make Array zero By subtracting Zero Amounts
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>> pq(nums.begin(),nums.end());
        int ans = 0;
        int sub = 0;
        while(pq.size() != 0){
            int elem = pq.top();
            if(elem == 0) pq.pop();
            else{
                if(elem - sub != 0){
                    sub = elem;
                    ans++;
                }  
                pq.pop();
            }
        }
        return ans;
    }
};