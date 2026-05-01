// Topological Sort using BFS : Kahn's Algorithm
#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <unordered_set>
using namespace std;

vector<list<int>> graph;
int v; // No of vertices

void add_edge(int a, int b, bool biDir = true){
    graph[a].push_back(b);
    if(biDir) graph[b].push_back(a);
}

void topoBFS(){
    //Kahn's Algorithm
    vector<int> indegree(v,0);
    for(int i=0; i<v; i++){
        for(auto neighbour : graph[i]){
            // i ---> neighbour
            indegree[neighbour]++;
        }
    }
    queue<int> qu;
    unordered_set<int> visited;
    for(int i=0; i<v; i++){
        if(indegree[i] == 0){
            qu.push(i);
            visited.insert(i);
        }
    }
    while(!qu.empty()){
        int node = qu.front();
        cout << node << " ";
        qu.pop();
        for(auto neighbour : graph[node]){
            if(!visited.count(neighbour)){
                indegree[neighbour]--;
                if(indegree[neighbour] == 0){
                    qu.push(neighbour);
                    visited.insert(neighbour);
                }
            }
        }
    }
}

int main(){
    cin >> v;
    int e;
    cin >> e;
    graph.resize(v,list<int> ());
    while(e--){
        int x, y;
        cin >> x  >> y;
        add_edge(x,y,false);
    }
    topoBFS();
    return 0;
}