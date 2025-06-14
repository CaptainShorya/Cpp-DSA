#include <iostream>
#include <vector>
using namespace std;


class Stack{
public: 
    vector<int> vec; // No Overflow Condition

    Stack(){

    }

    void push(int val){
        vec.push_back(val);
    }

    void pop(){
        if(vec.size() == 0){
            cout << "Stack is EMPTY " << endl;
            return;
        }
        vec.pop_back();
    }

    int top(){
        if(vec.size() == 0){
             return -1;
        }
        return vec[vec.size()-1];
    }
    int size(){
        return vec.size();
    }

};

int main(){
    Stack st;
    cout << st.size() << endl;
    cout << st.top() << endl;
    st.pop();
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);
    st.pop();
    cout << st.size() << endl;
    cout << st.top() << endl;
}