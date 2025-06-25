#include <iostream>
#include <stack>
#include <queue>
using namespace std;

//ReOrder Queue(Interleave 1st half with 2nd half) 
//Do this using only one stack and queue always of even length

//Input -> {1,2,3,4,5,6,7,8}    
//Output-> {1,5,2,6,3,7,4,8}

//Use for - while loop wisely, It may cause error while solving

int main(){
    queue<int> q;
    stack<int> st;
    for(int i=1; i<=8; i++){
        q.push(i);
    }

    int n = q.size();
    //Step 1
    //Reverse first half and push that in queue
    for(int i=0; i<n/2; i++){
        st.push(q.front());
        q.pop();
    }
    while(st.size() > 0){
        q.push(st.top());
        st.pop();
    }

    //First half in stack from queue, then one by one st to q and q to q.
    for(int i=0; i<n/2; i++){
        st.push(q.front());
        q.pop();
    }
    while(st.size() > 0){
        q.push(st.top());
        st.pop();

        q.push(q.front());
        q.pop();
    }

    //Reverese the queue to get required output
    for(int i=0; i<n; i++){
        st.push(q.front());
        q.pop();
    }
    while(st.size() > 0){
        cout << st.top() << " ";
        q.push(st.top());
        st.pop();
    }
    
}