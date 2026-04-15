#include <iostream>
#include <vector>
#include <list> 
#include <unordered_set>
#include <queue>
#include <climits>
using namespace std;

//Shortest path distance from source to all other vertices in undirected unweighted graph

vector<list<int>> graph;
unordered_set<int> visited; // Vertices that are visited
vector<vector<int>> result; // vector carrying all paths
int v; // No. of vertices

void add_edge(int src, int dest, bool bi_dir=true){
    graph[src].push_back(dest); 
    if(bi_dir){
        graph[dest].push_back(src);
    }
}

void bfs(int src, vector<int>& dist){ // BFS → shortest path in unweighted graph
    queue<int> qu;                   // queue for level-order traversal
    dist.resize(v, INT_MAX);         
    dist[src] = 0;                   // distance to source = 0

    visited.insert(src);             // mark source as visited
    qu.push(src);                    // start BFS from source

    while(!qu.empty()){              
        int curr = qu.front();    // get current node
        cout << curr << " ";      //Provide me with the Order in which we traverse around the graph
        qu.pop();                    // remove it from queue
        for(auto neighbour : graph[curr]){  // explore all adjacent nodes
            if(!visited.count(neighbour)){  // process only unvisited nodes
                qu.push(neighbour);         
                visited.insert(neighbour);  // mark visited immediately (avoid duplicates)
                dist[neighbour] = dist[curr] + 1; 
                // Here, we signify that curr is parent node of neighbour
                // update shortest distance (level-wise expansion)
            }
        }
    }
}

int main(){
    cin >> v;
    graph.resize(v,list<int>  ()); 
    int e;
    cin >> e;
    while(e--){
        int s, d;
        cin >> s >> d;
        add_edge(s,d); 
    }
    vector<int> distance;
    bfs(0,distance);
    for(int i=0; i<distance.size(); i++){
        cout << distance[i] << " ";
    }
    return 0;
}