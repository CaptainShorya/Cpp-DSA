#include <iostream>
#include <queue>
using namespace std;

void display(queue<int>& q){ // SC : O(1) , TC : O(n)
    int size = q.size();
    while(size > 0){
        cout << q.front() << " ";
        int var = q.front();
        q.pop();
        q.push(var);
        size--;
    }
    cout << endl;
}

//Consider 0-based indexing
void remove(queue<int>& q){ //& should be necessary to actually make changes at original address
    int n = q.size();
    for(int i=0; i<n; i++){
        if(i % 2 == 0) q.pop();
        else{
            int x = q.front();
            q.pop();
            q.push(x);
        }
    }
}

int main(){
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    display(q);

    //After remove at even indices
    remove(q);
    display(q);
}