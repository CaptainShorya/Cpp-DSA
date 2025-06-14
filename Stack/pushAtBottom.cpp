#include <iostream> 
#include <stack>
using namespace std;

//Display Stack
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

void pushAtBottom(int val,stack<int> &st){ //Without & pass by value hoyega which gives us wrong answer
    //provided stack mein changes karne hain to pass by reference kro
    stack<int> helper;
    while(st.size() > 0){
        helper.push(st.top());
        st.pop();
    }
    st.push(val);
    while(helper.size() > 0){
        st.push(helper.top());
        helper.pop();
    }
}

void pushAtAnyIndex(stack<int> &st,int idx,int val){
    stack<int> helper;
    while(st.size() > idx){
        helper.push(st.top());
        st.pop();
    }
    st.push(val);
    while(helper.size() > 0){
        st.push(helper.top());
        helper.pop();
    }
}

int main(){
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    print(st);

    //Push at Bottom
    pushAtBottom(70,st);
    print(st);

    //Push at Any Index
    pushAtAnyIndex(st,2,90);
    print(st);
}