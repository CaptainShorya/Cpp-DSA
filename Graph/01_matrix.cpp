// 01 Matrix 
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> ans(m, vector<int> (n,-1));
        queue<pair<int,int>> qu;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 0){
                    ans[i][j] = 0;
                    qu.push({i,j});
                }
            }
        }
        
        while(!qu.empty()){
            vector<vector<int>> dis = {{-1,0},{1,0},{0,1},{0,-1}};
            auto curr = qu.front();
            qu.pop();
            int row = curr.first;
            int col = curr.second;
            for(int i=0; i<dis.size(); i++){
                int new_r = row + dis[i][0];
                int new_c = col + dis[i][1];
                if(new_r >= 0 && new_c >= 0 && new_r < m && new_c < n && ans[new_r][new_c] == -1){
                    ans[new_r][new_c] = ans[row][col] + 1;
                    qu.push({new_r,new_c});
                }
            }
        }
    
        return ans;
    }
};
