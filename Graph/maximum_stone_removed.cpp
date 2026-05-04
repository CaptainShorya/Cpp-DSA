// LP 947: Most Stones Removed with Same Row or Column(Must Try , Something New)
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& stones, int index, vector<bool>& visited){
    visited[index] = true;

    for(int i=0; i<stones.size(); i++){
        int r = stones[index][0];
        int c = stones[index][1];

        if(!visited[i] && (stones[i][0] == r || stones[i][1] == c)){
            dfs(stones, i, visited); 
        }
    }
}

class Solution{
public:
    int removeStone(vector<vector<int>>& stones){
        int n = stones.size();
        vector<bool> visited(n, false);

        int group = 0;
        for(int i=0; i<n; i++){
            if(visited[i] == true) // skip
                continue;

            dfs(stones, i, visited); // After Completing one dfs, we get one gang/group
            group++;
        }
        return n - group;
    }
};