#include <iostream>
using namespace std;

class Node{ //user defined data type 
public:
    int val;
    Node* next;
    Node(int val){
        this -> val = val;
        this -> next = NULL;
    }
    
};

class Stack{ //user defined data structure
public: 
    Node* head;
    int size;
    Stack(){
        head = NULL;
        size = 0;
    }

    void push(int val){
        Node* temp = new Node(val);
        temp -> next = head;
        head = temp;
        size++;
    }

    void pop(){
        if(head == NULL){
            cout << "Stack is EMPTY" << endl;
            return;
        }
        head = head -> next;
        size--;
    }

    int top(){
        if(head == NULL){
            cout << "Stack is EMPTY "<< endl;
            return -1;
        }
        return head -> val;
    }

    void print(Node* temp){ //Recursion to print LL(Implemented as Stack) in normal order
        if(temp == NULL) return;
        print(temp -> next);
        cout << temp -> val << endl;
    }

    void display(){
        Node* temp = head; 
        //Print in reverse order 
        // while(temp != NULL){
        //     cout << temp -> val << " ";
        //     temp = temp -> next;
        // }

        //Print in Normal Order
        print(temp);
        cout << endl;
    }
};

int main(){
    Stack st;
    cout << st.top() << endl;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    cout << st.size << endl;
    cout << st.top() << endl;
    st.display();
    return 0;
}