#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> vec;
        vec.push_back(1);
        int f1 = 1;
        int f2 = 1;
        while(true){
            int temp = f2;
            f2 = f2 + f1;
            f1 = temp;
            if(f2 <= k) vec.push_back(f2);
            else break;
        }
        priority_queue<int> pq(vec.begin(),vec.end()); //maxHeap
        int ans = 0;
        while(k != 0){
            if(pq.top() <= k){
                k = k - pq.top();
                ans++;
            }else{
                pq.pop();
            }
        }
        return ans;
    }
};