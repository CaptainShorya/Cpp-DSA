#include <iostream>
#include <queue>
using namespace std;
int main()
{
    int arr[] = {2, 7, 1, 4, 8};
    int n = sizeof(arr) / 4;
    int minCost = 0;
    priority_queue<int, vector<int>, greater<int>> pq; //MinHeap
    for(int elem : arr) pq.push(elem);
    while (pq.size() > 1)
    {
        int x = pq.top();
        pq.pop();
        int y = pq.top();
        pq.pop();
        minCost += (x + y);
        pq.push((x + y));
    }
    cout << "Minimum cost to connect all ropes = " << minCost << endl;
}