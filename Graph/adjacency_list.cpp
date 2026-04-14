#include <iostream>
#include <vector>
#include <list> 
using namespace std;

vector<list<pair<int,int>>> graph;
int v; // No. of vertices

void add_edge(int src, int dest, int wt, bool bi_dir=true){
    // graph[i] → list of neighbours of node i
    // Adds an edge from src to dest with weight wt, and if bidirectional, also adds reverse edge
    graph[src].push_back({dest,wt}); 
    if(bi_dir){
        graph[dest].push_back({src,wt});
    }
}

void display(){
    for(int i=0; i<graph.size(); i++){
        cout << i << " -> ";
        for(auto el : graph[i]){ // Iterate ith index linked list 
            cout <<"("<<  el.first << "," << el.second << ")"<< ","; //el.first → destination node, el.second → weight of edge
        }
        cout << "\n";
    }
}

int main(){
    cin >> v;
    graph.resize(v,list<pair<int,int>>  ()); // Create list at every index starting from idx=0 to idx=v-1 
    int e;
    cin >> e;
    while(e--){
        int s, d, wt;
        cin >> s >> d >> wt;
        add_edge(s,d,wt,false); // Directed
    }
    display();
}