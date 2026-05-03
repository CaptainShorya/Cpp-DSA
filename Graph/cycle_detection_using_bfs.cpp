#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

vector<list<int>> graph;
int v; // No. of vertices

void add_edge(int src, int dest, bool bi_dir=true){
    // graph[i] → list of neighbours of node i
    // Adds an edge from src to dest with weight wt, and if bidirectional, also adds reverse edge
    graph[src].push_back(dest); 
    if(bi_dir){
        graph[dest].push_back(src);
    }
}

bool bfs(int src){
    vector<int> parent;
    unordered_set<int> visited;
    queue<int> qu;
    qu.push(src);
    visited.insert(src);
    parent[src] = -1;
    while(!qu.empty()){
        auto curr = qu.front();
        qu.pop();
        for(auto &neighbour : graph[curr]){
            if(visited.count(neighbour) && parent[curr] != neighbour){
                return true;
            }
            if(!visited.count(neighbour)){
                visited.insert(neighbour);
                qu.push(neighbour);
                parent[neighbour] = curr;
            }
        }
    }
    return false;
}


bool has_cycle(){
    for(int i=0; i<v; i++){
        bool result = bfs(i);
        if(result == true) return true;
    }
    return false;
}

int main(){
    cin >> v;
    graph.resize(v,list<int> ()); // Create list at every index starting from idx=0 to idx=v-1 
    int e;
    cin >> e;
    while(e--){
        int s, d;
        cin >> s >> d ;
        add_edge(s,d); // UnDirected
    }
    // Time Complexity same as O(V + E)
    bool b = has_cycle();
    cout << "Cycle detected = " << b << endl;
}