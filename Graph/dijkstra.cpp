#include <bits/stdc++.h>
#define ll long long int 
#define pp pair<int,int>
using namespace std;

vector<list<pair<int,int>>> graph;

// Add edge in graph
void add_edge(int src, int dest, int wt, bool biDir = true){
    graph[src].push_back({dest,wt});

    // For undirected graph
    if(biDir){
        graph[dest].push_back({src,wt});
    }
}

unordered_map<int,int>  dijkstra(int src, int n){

    // Min Heap -> {weight,node}
    priority_queue<pp, vector<pp> , greater<pp>> pq;

    // Stores nodes already included in MST
    unordered_set<int> visited;

    // Helps in printing MST
    vector<int> via(n+1,0);

    // Stores minimum weight needed
    // to connect node into MST
    unordered_map<int,int> mpp;

    // Initially every node has infinite weight
    for(int i=0; i<n; i++){ //O(V)
        mpp[i] = INT_MAX;
    }

    // Start from source node
    pq.push({0,src});
    mpp[src] = 0;

    // Continue until all nodes are visited
    while(!pq.empty()){

        pp curr = pq.top();
        pq.pop();

        int currWt = curr.first;
        int currNode = curr.second;

        // Ignore if already part of MST
        if(visited.count(currNode)){
            continue;
        }

        // Include node into MST
        visited.insert(currNode);

        // Traverse neighbours
        for(auto neighbour : graph[currNode]){ //O((V+E)logV)

            int neighNode = neighbour.first;
            int edgeWt = neighbour.second;

    
            if(!visited.count(neighNode) &&
               edgeWt + mpp[currNode] < mpp[neighNode]){

                mpp[neighNode] = edgeWt + mpp[currNode];

                // Store parent of neighbour
                via[neighNode] = currNode;

                pq.push({edgeWt + mpp[currNode], neighNode});
            }
        }
    }

    return mpp;
}

int main(){

    int n,e;
    cin >> n >> e;

    // Adjacency List
    graph.resize(n , list<pair<int,int>> ());

    while(e--){

        int src, dest, wt;
        cin >> src >> dest >> wt;

        add_edge(src,dest,wt);
    }

    int src;
    cin >> src;
    unordered_map<int,int> sp = dijkstra(src,n);
    for(auto &p : sp){
        cout << p.first << " " << p.second << endl;
    }
    int dest;
    cin >> dest;
    cout << sp[dest] << "\n";
}