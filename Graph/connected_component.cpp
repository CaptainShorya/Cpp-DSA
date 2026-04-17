#include <iostream>
#include <vector>
#include <list> 
#include <unordered_set>
using namespace std;

vector<list<int>> graph;
int v; // No. of vertices

void add_edge(int src, int dest, bool bi_dir=true){
    // graph[i] → list of neighbours of node i
    graph[src].push_back(dest); 
    if(bi_dir){
        graph[dest].push_back(src);
    }
}

void dfs(int source, unordered_set<int>& visited){
    visited.insert(source); 
    for(auto neighbour : graph[source]){
        if(!visited.count(neighbour)){
            dfs(neighbour,visited);
        }
    }
}

int connected_component(){
    int cc = 0; // count connected component
    unordered_set<int> visited; // keep track of visited node
    for(int i=0; i<graph.size(); i++){
        //go to every vertex
        // if from a vertex we can initializw a dfs, we got one more cc
        if(!visited.count(i)){ // Means it is not part of any dfs
            cc++;
            dfs(i,visited);
        }
    }
    return cc;
}

int main(){
    cin >> v;
    graph.resize(v,list<int>  ()); // Create list at every index starting from idx=0 to idx=v-1 
    int e;
    cin >> e;
    while(e--){
        int s, d;
        cin >> s >> d;
        add_edge(s,d); // UnDirected
    }
    cout << connected_component();
    return 0;
}