#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void combination(vector<int>& candidates, vector<vector<int>>& vec, vector<int> comb , int index, int target){
        if(target < 0) return;
        if(target == 0){
            vec.push_back(comb);
            return;
        }
        for(int i=index; i<candidates.size(); i++){
            if(i > index && candidates[i] == candidates[i-1]) continue;
            else{
                comb.push_back(candidates[i]);
                combination(candidates,vec,comb,i+1,target-candidates[i]);
                comb.pop_back();
            }   
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> vec;
        vector<int> comb;
        combination(candidates,vec,comb,0,target);
        return vec;
    }
};