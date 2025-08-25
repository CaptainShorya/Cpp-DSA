#include <iostream>
#include <queue>
using namespace std;

int main(){
    // priority_queue<int> pq; // MaxHeap
    // pq.push(10);
    // pq.push(2);
    // pq.push(8);
    // cout << pq.top() << endl; // 10 at top
    // pq.pop(); // 10 is removed
    // cout << pq.top() << endl; // 8 at top 

    priority_queue<int, vector<int>, greater<int>> pq; // minHeap
    pq.push(10); // 10
    pq.push(2);  // 2
    pq.push(8);  // 2
    cout << pq.top() << endl; // 2 at top
    pq.pop(); // 2 is removed
    cout << pq.top() << endl; // 8 at top 
}