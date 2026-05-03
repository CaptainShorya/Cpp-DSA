#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

class Solution {
public:
    // stores visited nodes to avoid reprocessing
    unordered_set<int> visited;

    // DFS to calculate size of one connected component
    void dfs(vector<vector<int>>& graph, int src, int& n){
        visited.insert(src); // mark current node visited
        n++; // increase size of current component

        // explore all neighbours
        for(auto &neighbour : graph[src]){
            if(!visited.count(neighbour)){
                dfs(graph,neighbour,n); // recursive DFS
            }
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {

        // adjacency list representation of graph
        vector<vector<int>> graph(n, vector<int> ());

        // will store sizes of all connected components
        vector<int> countCC;

        long long ans = 0;
        for(int i=0; i<edges.size(); i++){ // build graph (undirected)
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }

        // find all connected components using DFS
        for(int i=0; i<n; i++){
            if(!visited.count(i)){
                int node = 0; // size of current component
                dfs(graph,i,node);
                countCC.push_back(node); // store component size
            }
        }

        // Do a Dry Run for this step 
        // total number of nodes remaining to pair with
        long long totalSum = 0;
        // sum of all component sizes
        for(int i = countCC.size()-1; i>=0; i--){
            totalSum += countCC[i];
        }
        // count unreachable pairs
        for(int i=0; i<countCC.size(); i++){
            // pairs = current_component * remaining_nodes
            ans += (long long)countCC[i]*(totalSum-countCC[i]);
            // remove current component from future consideration
            totalSum -= countCC[i];
        }
        return ans;
    }
};