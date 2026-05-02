#include <iostream>
#include <vector>
using namespace std;

int find(vector<int>& parent, int x){
    // TC = O(log*n)
    //This method returns group/cluster x belongs to
    return parent[x] = (parent[x] == x) ? x : find(parent, parent[x]);
}

bool Union(vector<int>& parent, vector<int>& rank, int a, int b){
    // TC = O(log*n)
    a = find(parent,a);
    b = find(parent,b);
    if(a == b) return true;
    if(rank[a] > rank[b]){
        parent[b] = a;
    }else if(rank[a] < rank[b]) {
        parent[a] = b;
    }else{
        parent[b] = a;
        rank[a]++;
    }
    return false;
}

int main(){ // TC = O(E*(log*V))
    int n, m;
    cin >> n >> m;
    // n -> Number of elements , m -> no of queries/operations
    // for 1,2,3,...,n nodes we need parent[1] to parent[n] : But vectors in C++ are 0-based, so to safely use index n, you create size n+1.
    vector<int> parent(n+1); // n+1 is used to support 1-based indexing
    vector<int> rank(n+1, 0);
    for(int i=0; i<=n; i++){
        parent[i] = i; // Every node is initially its own parent (separate set)
    }
    // Each query is either : union or find
    while(m--){ // processes each query one by one
        int x,y;
        cin >> x >> y;
        bool b = Union(parent,rank,x,y);
        if(b == true) cout << "Cycle Detected" << endl;
    }
}