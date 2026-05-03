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

bool dfs(int src, int parent, unordered_set<int>& visited){
    visited.insert(src);
    for(auto &neighbour : graph[src]){
        // Cycle detected
        if(visited.count(neighbour) && parent != neighbour){
            return true; 
        }
        if(!visited.count(neighbour)){
            bool result = dfs(neighbour, src, visited); // Agar ek recursive call true return kregi, to vo peeche vali call mein bhi jayega
            if(result == true) return true;
        }
    }
    return false;
}

//If there is a cycle of n nodes, then it is possible to construct/start cycle from any of the node.

bool has_cycle(){
    unordered_set<int> visited;
    bool result = false;
    for(int i=0; i<v; i++){ //Without loop, you might visit only one component, might miss cycles in other components
        if(!visited.count(i)){
            result = dfs(i, -1, visited);
            if(result) return true;
        }
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