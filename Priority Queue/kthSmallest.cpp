#include <iostream>
#include <queue>
using namespace std;

int main(){
    priority_queue<int> pq; //maxHeap
    int arr[] = {10,20,2,-4,18,6,105,118};
    int k = 3;
    int n = sizeof(arr)/4;
    for(int i=0; i<n; i++){
        pq.push(arr[i]);
        if(pq.size() > k) pq.pop(); 
    }
    cout << pq.top() << endl;
}