#include <iostream>
#include <queue>
using namespace std;

int main(){ // TC -> O(nlogK)
    priority_queue<int,vector<int>,greater<int>> pq; //minHeap
    int arr[] = {6,5,3,2,8,10,9};
    int k = 3;
    int n = sizeof(arr)/4;
    int ans[n] = {0}; // alternate,We can push them in the arr array directly without creating the new array
    int j = 0;
    for(int i=0; i<n; i++){ // TC - O(nlogK)
        pq.push(arr[i]);
        if(pq.size() > k){
            ans[j] = pq.top();
            j++;
            pq.pop();
        }
    }
    while(pq.size() > 0){ // TC - O(KlogK)
        ans[j] = pq.top();
        j++;
        pq.pop();
    }
    for(int k=0; k<n; k++){
        cout << ans[k] << " ";
    }
    cout << endl;
}