#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverse(queue<int>& q, int k){
    stack<int> rev;
    int n = q.size();
    //Pushing elem in stack(Now we can access them in reverse order)
    for(int i=0; i<k; i++){
        rev.push(q.front());
        q.pop();
    }
    //Make stack empty and push stack top element into queue
    while(rev.size() > 0){
        q.push(rev.top());
        rev.pop();
    }

    //Self push and pop (for remaining elements)
    for(int i=0; i<n-k; i++){
        int x = q.front();
        q.pop();
        q.push(x);
    }
}

void display(queue<int>& q){
    int n = q.size();
    for(int i=0; i<n; i++){
        int x = q.front();
        cout << x << " ";
        q.pop();
        q.push(x);
    }
    cout << endl;
}

int main(){
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    int k = 3;              
    display(q);
    reverse(q,k);
    display(q);
}