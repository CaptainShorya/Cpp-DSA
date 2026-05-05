// Kruskal Algorithm (MST) 
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int find(vector<int>& parent, int x){
    //path compression
    return parent[x] = ((parent[x] == x) ? x : find(parent, parent[x]));
}

void Union(vector<int>& parent, vector<int>& rank, int a, int b){
    a = find(parent,a);
    b = find(parent,b);
    if(a == b) return;
    if(rank[a] > rank[b]){
        parent[b] = a;
    }else if(rank[a] < rank[b]){
        parent[a] = b;
    }else{
        parent[b] = a;
        rank[a]++;
    }
}

struct Edge{
    int src;
    int dest;
    int wt;
};

bool cmp(Edge e1, Edge e2){
    return e1.wt < e2.wt; // Increasing order sort
}

ll kruskals(vector<Edge>& input, int n, int e){ // O(V + ElogE)
    sort(input.begin(),input.end(),cmp); // O(ElogE)
    vector<int> parent(n+1,0);
    vector<int> rank(n+1,0);

    for(int i=0; i<=n; i++){
        parent[i] = i;
    }
    int edgeCount = 0; // How many Edges I have picked up // n-1
    int i = 0; // Tells us about current pointed edge
    ll ans = 0;
    while(edgeCount < n-1 && i < input.size()){ // O(Vlog*V)
        Edge curr = input[i]; // beacuse input is sorted so we will get min wt edge
        int srcPar = find(parent, curr.src); // O(log*V)
        int destPar = find(parent, curr.dest);
        if(srcPar != destPar){
            // include edge as this will not make cycle
            Union(parent, rank, srcPar, destPar); // O(log*V)
            ans += curr.wt;
            edgeCount++;
        }
        i++; // doesnt matter u picked the last edge or not, we still need to go to the next edge
    }
    return ans;
}

int main(){
    int n , e;
    cin>> n >> e;
    vector<Edge> v(e);
    for(int i=0; i<e; i++){
        cin >> v[i].src >> v[i].dest >> v[i].wt;
    }
    cout << kruskals(v, n, e) << endl;
    return 0;
}