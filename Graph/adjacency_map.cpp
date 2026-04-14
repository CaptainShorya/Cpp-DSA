#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

vector<unordered_map<int,int>> graph;
int v;

void add_edge(int src, int dest, int wt, bool bi_dir=true){
    graph[src][dest] = wt;
    if(bi_dir){
        graph[dest][src] = wt;
    }
}

// Display for directed/undirected(depends on bi_dir) adjacency map graph
void display(){
    for(int i=0; i<graph.size(); i++){
        cout << i << " -> ";
        for(auto el : graph[i]){
            cout <<"("<<  el.first << "," << el.second << ")"<< ",";
        }
        cout << "\n";
    }
}

// Display for undirected adjacency set graph
void display_set(vector<unordered_set<int>> &undirected){
    for(int i=0; i<undirected.size(); i++){
        cout << i << " -> ";
        for(auto el : undirected[i]){
            cout << el << ",";
        }
        cout << "\n";
    }
}

int main(){
    cin >> v;
    graph.resize(v,unordered_map<int,int> ()); // Create unordered_map at every index starting from idx=0 to idx=v-1 
    int e;
    cin >> e;
    while(e--){
        int s, d, wt;
        cin >> s >> d >> wt;
        add_edge(s,d,wt,false); // Directed
    }
    cout << "Directed Weighted Graph:\n";
    display();

    // How can I convert a adjacency map directional to undirected adjacency set graph...
    vector<unordered_set<int>> undirected(v);

    for(int i = 0; i < v; i++){
        for(auto el : graph[i]){
            int u = i;
            int vtx = el.first;

            undirected[u].insert(vtx);
            undirected[vtx].insert(u); // reverse edge
        }
    }

    cout << "\nUndirected Unweighted Graph:\n";
    display_set(undirected);
}