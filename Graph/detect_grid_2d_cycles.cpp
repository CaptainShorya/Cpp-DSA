#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

class Solution { // Time Complexity: O(m * n)
public:

    // 4-directional movement (right, down, up, left)
    vector<vector<int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};

    // DFS to detect cycle
    bool dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int r, int c, int parent_r, int parent_c){
        // mark current cell as visited
        visited[r][c] = true;
        //explore all 4 directions
        for(int i=0; i<dir.size(); i++){
            int new_r = r + dir[i][0];
            int new_c = c + dir[i][1];
            if(new_r < 0 || new_c < 0 || new_r >= grid.size() || new_c >= grid[0].size()) continue; // skip out of bounds
            if(grid[new_r][new_c] != grid[r][c]) continue; // skip if character is different (cycle only valid in same component)
            if(visited[new_r][new_c] && !(parent_r ==  new_r && parent_c == new_c)){ 
                // if already visited and not coming from parent → cycle exist
                return true;
            }
            // if not visited → explore further
            if(!visited[new_r][new_c]){
                bool result = dfs(grid,visited,new_r,new_c,r,c);
                if(result) return true;
            }
        }
        return false; // no cycle found in this path
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m,vector<bool> (n,false));

        // try DFS from every unvisited cell (handles disconnected components)
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!visited[i][j]){
                    bool result = dfs(grid,visited,i,j,-1,-1);
                    if(result) return true; // cycle exist
                }
            }
        }
        return false; // no cycle in entire grid
    }
};