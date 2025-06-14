#include <iostream> 
#include <stack>
using namespace std;


int main(){
    stack<int> st;
    cout << st.size() << endl;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    
    //Print elemenets of stack -> emptying the stack
    // while(st.size() > 0){
    //     cout << st.top() << " ";
    //     st.pop();
    // }

    //Print elements of stack without emptying the stack
    // stack<int> temp;

    // while(st.size() > 0){
    //     cout << st.top() << " ";
    //     temp.push(st.top());
    //     st.pop();
    // }
    // cout << endl;
    // cout << "Elements printed from Bottom to Top : " << endl;
    // while(temp.size() > 0){
    //     cout << temp.top() << endl; //Homework problem 
    //     st.push(temp.top());
    //     temp.pop();
    // }

    //Reverse a Stack -> In its original given stack variable
    stack<int> gt;
    stack<int> rt;

    while(st.size() > 0){
        gt.push(st.top());
        gt.pop();
    }
    while(gt.size() > 0){
        rt.push(gt.top());
    }
    while(rt.size() > 0){
        st.push(rt.top());
    }
}