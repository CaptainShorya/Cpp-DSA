#include <iostream>
#include <queue>
#include <stack>
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

void reverse(queue<int>& q){ // SC : O(n) , TC : O(n)
    stack<int> st;

    //Empty the queue into stack 
    while(q.size() > 0){
        int var = q.front();
        q.pop();
        st.push(var);
    }

    //Empty the stack into queue
    while(st.size() > 0){
        int var = st.top();
        st.pop();
        q.push(var);
    }
    
}

int main(){
    queue<int> q;
    //push
    //pop 
    //front , back
    //size
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    // cout << q.size() << endl;
    // cout << q.back() << endl;
    // q.pop();
    // cout << q.size() << endl;
    // cout << q.front() << endl;

    //Display
    display(q);

    //Reverse Order
    reverse(q);
    display(q);
}