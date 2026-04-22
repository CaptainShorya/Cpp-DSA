#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//BFS Approach 
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cc = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '0'){
                    // it is a water body or visited land portion
                    continue;
                }
                cc++;
                grid[i][j] = '0'; // mark it visited
                queue<pair<int,int>> qu;
                qu.push({i,j}); // stores the source node
                while(!qu.empty()){
                    auto curr = qu.front(); // get the front node
                    qu.pop();
                    // go to all unvisited neighbours of the curr node
                    int currRow = curr.first;
                    int currCol = curr.second;
                    //check-up
                    if(currRow - 1 >= 0 && grid[currRow-1][currCol] == '1'){
                        qu.push({currRow-1,currCol});
                        grid[currRow-1][currCol] = '0';
                    }
                    //check-down
                    if(currRow + 1 < n && grid[currRow+1][currCol] == '1'){
                        qu.push({currRow+1,currCol});
                        grid[currRow+1][currCol] = '0';
                    }
                    //check-right
                    if(currCol + 1 < m && grid[currRow][currCol+1] == '1'){
                        qu.push({currRow,currCol+1});
                        grid[currRow][currCol+1] = '0';
                    }
                    //check-left
                    if(currCol - 1 >= 0 && grid[currRow][currCol-1] == '1'){
                        qu.push({currRow,currCol-1});
                        grid[currRow][currCol-1] = '0';
                    }
                }

            }
        }
        return cc;
    }
};

//DFS Approach 
class Solution {
public:
    vector<vector<bool>> visited;
    void dfs(vector<vector<char>>& grid, int r, int c){
        if(r < 0 || c < 0 || r == grid.size() || c== grid[0].size()) return;
        if(grid[r][c] == '0') return;
        if(visited[r][c] == true) return;
        visited[r][c] = true;
        dfs(grid,r-1,c);
        dfs(grid,r,c-1);
        dfs(grid,r+1,c);
        dfs(grid,r,c+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        visited.resize(n,vector<bool>(m,false));
        int cc = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    cc++;
                    dfs(grid,i,j);
                }
            }
        }
        return cc;
    }
};