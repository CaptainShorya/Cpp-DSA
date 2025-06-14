#include <iostream> 
#include <stack>
using namespace std;

void displayRec(stack<int>& st){
    //Base Case
    if(st.size() == 0) return;
    // cout << st.top() << " "; //Display Stack Recursively in Reverse order
    int x = st.top(); 
    st.pop();
    displayRec(st);
    cout << x << " "; //Display Stack Recursively in standard order
    st.push(x);
}

//Recursively 
void pushAtBottom(stack<int>& st, int val){
    //Base Case 
    if(st.size() == 0){
        st.push(val);
        return;
    }
    int x = st.top();
    st.pop();
    pushAtBottom(st,val);
    st.push(x);
}

//Reversing a Stack using Recursion
void reverse(stack<int>& st){
    if(st.size() == 1) return;

    int x = st.top();
    st.pop();
    reverse(st);
    pushAtBottom(st,x);
}

int main(){
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    displayRec(st);
    cout << endl;
    //Reverse a stack by recursion 
    reverse(st);
    cout << "Reverse a Stack using Recursion : ";
    displayRec(st);

}