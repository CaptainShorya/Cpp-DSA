// Rotten Oranges
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int time = 0;
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> qu;
        int fresh = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2) qu.push({i,j}); // multi-source bfs
                if(grid[i][j] == 1) fresh++;
            }
        }
        //we have added all the source
        qu.push({-1,-1}); // represents end of one minute or one level completed 
        while(!qu.empty()){
            auto curr = qu.front();   
            qu.pop();
            int r = curr.first;
            int c = curr.second;
            if(r == -1 && c == -1){
                time++;
                if(!qu.empty()) qu.push({-1,-1});
                else break;
            }
            else{
                if(r > 0 && grid[r-1][c] == 1){
                    grid[r-1][c] = 2;
                    qu.push({r-1,c});
                    fresh--;
                }
                if(c > 0 && grid[r][c-1] == 1){
                    grid[r][c-1] = 2;
                    qu.push({r,c-1});
                    fresh--;
                }
                if(r < grid.size()-1 && grid[r+1][c] == 1){
                    grid[r+1][c] = 2;
                    qu.push({r+1,c});
                    fresh--;
                }
                if(c < grid[0].size()-1 && grid[r][c+1] == 1){
                    grid[r][c+1] = 2;
                    qu.push({r,c+1});
                    fresh--;
                }
            } 
        }
        return fresh == 0 ? time-1 : -1; //Do Dry run for Why we used (time-1)
    } 
};

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int time = 0;
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> qu;
        int fresh = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2) qu.push({i,j}); // multi-source bfs
                if(grid[i][j] == 1) fresh++;
            }
        }
        //we have added all the source
        vector<vector<int>> dir = {{-1,0},{1,0},{0,1},{0,-1}};
        qu.push({-1,-1}); // represents end of one minute or one level completed 
        while(!qu.empty()){
            auto curr = qu.front();   
            qu.pop();
            int r = curr.first;
            int c = curr.second;
            if(r == -1 && c == -1){
                time++;
                if(!qu.empty()) qu.push({-1,-1});
                else break;
            }
            else{
                
                for(int d=0; d<4; d++){
                    int nr = r + dir[d][0];
                    int nc = c + dir[d][1];
                    if(nr < 0 || nc < 0 || nr >= m || nc >= n) continue;
                    if(grid[nr][nc] == 2 || grid[nr][nc] == 0) continue;
                    fresh--;
                    grid[nr][nc] = 2;
                    qu.push({nr,nc});
                }
            } 
        }
        return fresh == 0 ? time-1 : -1; //No new infection happens in that last increment,so (time-1)
    } 
};

