// Shortest Bridge
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Core Idea:
// DFS → capture entire first island
// BFS → expand layer by layer until second island is reached

class Solution {
public:
    // Movement in 4 directions → helps traverse grid like a graph
    vector<vector<int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};

    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visitedCell, queue<pair<int,int>>& qu, int r, int c){
        // Stop if out of grid → prevents invalid memory access
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size()) return; // Boundary Constraints
        if(grid[r][c] == 0) return; // Stop if water → DFS only captures land (first island)
        if(visitedCell[r][c] == true) return; // Prevents from revisiting/infinite recursion

        visitedCell[r][c] = true; // Mark this cell as part of FIRST island
        qu.push({r,c}); // Store it in queue → BFS will start expanding from ALL these cells

        for(auto &dir : directions){ // Explore neighbors -> Collect entire island
            int new_r = r + dir[0];
            int new_c = c + dir[1];
            dfs(grid,visitedCell,qu,new_r,new_c);
        }
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // Tracks visited cells:
        // 1. First island cells
        // 2. BFS expanded water cells
        vector<vector<bool>> visitedCell(m,vector<bool>(n,false));
        queue<pair<int,int>> qu;
        bool flag = false;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    dfs(grid,visitedCell,qu,i,j); // DFS will mark entire island + push all cells into queue
                    // Stop searching → we only need ONE island
                    flag = true;
                    break;
                } 
            }
            if(flag) break;
        }
        int ans = 0;
        while(!qu.empty()){
            int size = qu.size(); // Current layer size → represents one "distance level" (1 layer size)
            while(size-- > 0){
                // Take one cell from current BFS layer
                auto curr = qu.front();
                qu.pop();
                int r = curr.first;
                int c = curr.second;
                // Explore all 4 directions
                for(auto &dir : directions){
                    int new_r = r + dir[0];
                    int new_c = c + dir[1];
                    // Check:
                    // 1. Inside grid
                    // 2. Not already visited
                    if(new_r >= 0 && new_c >= 0 && new_r < m  && new_c < n && !visitedCell[new_r][new_c]){
                        // If we hit land again → it's SECOND island
                        // Because first island is already marked visited
                        if(grid[new_r][new_c] == 1){
                            return ans;
                        }
                        // Otherwise it's water → expand BFS
                        // Mark visited so we don't revisit
                        visitedCell[new_r][new_c] = true;
                        qu.push({new_r,new_c}); // Push into queue → next layer expansion
                    }
                }
            }
            // After finishing one full layer → increase distance
            // Each layer = one "flip" of water → bridge length
            ans++;
        }
        return -1;
    }
};