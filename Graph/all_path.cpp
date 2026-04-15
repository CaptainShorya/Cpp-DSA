#include <iostream>
#include <vector>
#include <list> 
#include <unordered_set>
using namespace std;

//Return all paths that exists between source and destination.

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

void dfs(int curr, int end, vector<int>& vec){
    if(curr == end){
        vec.push_back(curr);
        result.push_back(vec);
        vec.pop_back(); //backtrack
        return;
    }
    visited.insert(curr); // mark visited
    vec.push_back(curr);
    for(auto neighbour : graph[curr]){ 
        if(!visited.count(neighbour)){
            dfs(neighbour,end,vec);
        }
    }
    vec.pop_back(); //backtrack path
    visited.erase(curr);  // unmark visited
}

void all_path(int src, int desc, vector<int> vec){
    visited.clear();// avoids issues in reuse
    dfs(src,desc,vec);
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
    vector<int> vec; // Denotes individual path 
    all_path(0,6,vec);
    for(int i=0; i<result.size(); i++){
        for(int j=0; j<result[i].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}