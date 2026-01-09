#include <iostream>
#include <vector>
using namespace std;

void buildCombination(vector<int>& candidates,int target,vector<vector<int>>& vec,vector<int> temp_vec,int j){
        if(target<0) return;
        else if(target==0){
            vec.push_back(temp_vec);
            return;
        }

        for(int i=j; i<candidates.size(); i++){
            temp_vec.push_back(candidates[i]);
            buildCombination(candidates,target-candidates[i],vec,temp_vec,i);
            temp_vec.pop_back(); //BackTracking, in order to avoid addition of previous element in the vector
        }
    }

int main(){
        vector<int> candidates = {2,3,6,7};
        vector<vector<int>> vec;
        vector<int> temp_vec;
        int target = 7;
        int j = 0;
        buildCombination(candidates,target,vec,temp_vec,j);
        for(int i=0; i<vec.size(); i++){
            for(int j=0; j<vec[i].size(); j++){
                cout << vec[i][j] << " ";
            }
            cout << endl;
        }
}