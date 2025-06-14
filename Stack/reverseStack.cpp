#include <iostream> 
#include <stack>
using namespace std;

void print(stack<int> st){
    stack<int> temp;
    while(st.size() > 0){
        temp.push(st.top());
        st.pop();
    }
    while(temp.size() > 0){
        cout << temp.top() << " ";
        st.push(temp.top());
        temp.pop();
    }
    cout << endl;
}

int main(){
    stack<int> st;
    cout << st.size() << endl;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    print(st);
    
    //Two extra stacks are required
    stack<int> gt;
    stack<int> rt;

    //Empty st into gt
    while(st.size() > 0){
        gt.push(st.top());
        st.pop();
    }

    //Empty gt into rt
    while(gt.size() > 0){
        rt.push(gt.top());
        gt.pop();
    }
    
     //Empty rt into st
    while(rt.size() > 0){
        st.push(rt.top());
        rt.pop();
    }

    //Print original stack
    cout << "Reverse a Stack: " << endl;
    print(st);
}