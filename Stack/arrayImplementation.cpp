#include <iostream> 
using namespace std;

class Stack{
public: 
    int arr[5];
    int idx; //Not assign value here, bcz to not show warning(Default member initialization)

    //Constructor
    Stack(){
        idx = -1;
    }

    void push(int val){
        if(idx == sizeof(arr)/sizeof(arr[0]) - 1){
            cout << "Stack is FULL " << endl;
            return;
        }
        idx++;
        arr[idx] = val;
    }

    void pop(){
        if(idx == -1){
            cout << "Stack is EMPTY " << endl;
            return;
        }
        idx--;
    }

    int top(){
        if(idx == -1){
             cout << "Stack is EMPTY " << endl;
             return -1;
        }
        return arr[idx];
    }
    int size(){
        return idx+1;
    }

    void display(){
        for(int i=0; i<idx+1; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
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
    st.display();
}