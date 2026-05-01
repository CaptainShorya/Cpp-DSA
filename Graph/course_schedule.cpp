// Course Schedule : LP 207 and similar to LP 210 (Try that too)
#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //Make it more space optimized than that of Course Schedule 2
        vector<vector<int>> graph(numCourses, vector<int> ());
        vector<int> indegree(numCourses,0);
        queue<int> qu;
        int count = 0;
        for(int i=0; i<prerequisites.size(); i++){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        for(int i=0; i<indegree.size(); i++){
            if(indegree[i] == 0){
                qu.push(i);
            }
        }
        while(!qu.empty()){
            auto curr = qu.front();
            count++;
            qu.pop();
                for(auto neighbour : graph[curr]){
                    if(indegree[neighbour] != 0){
                        indegree[neighbour]--;
                        if(indegree[neighbour] == 0){
                            qu.push(neighbour);
                        }  
                    }
                }
            }
        return numCourses == count;
           
    }
};