#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include<unordered_map>
using namespace std;

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char,int> mpp;
        for(int i=0; i<s.length(); i++){
            mpp[s[i]]++;
        }
        priority_queue<pair<char,int>> pq;
        for(auto p : mpp){
            pq.push(p); //Pushed map elements into priority queue
        }
        string ans = "";
        while(!pq.empty()){
            auto largest = pq.top();
            pq.pop();
            int len = min(repeatLimit,largest.second);
            for(int i=0; i<len; i++){
                ans += largest.first;
            }  
            pair<char,int> secondLargest;
            if(largest.second - len > 0){
                if(!pq.empty()){
                    secondLargest = pq.top();
                    pq.pop();
                    ans += secondLargest.first;
                }else{ // No further Element present, only useless same elem remains which can't be attached more together
                    return ans;
                }
                if(secondLargest.second - 1 > 0) pq.push({secondLargest.first,secondLargest.second - 1});
                pq.push({largest.first,largest.second - len});
            }  
        }
        return ans;
    }
};
