#include <iostream>
using namespace std;

class Node{ //User defined data type
public:
    int val;
    Node* next;

    Node(int value){
        this -> val = value;
        this -> next = NULL;
    }
};

class Queue{
public:
    Node* head;
    Node* tail;
    int size;

    Queue(){
        head = tail = NULL;
        size = 0;
    }

    void push(int val){
        Node* temp = new Node(val); // New Node Created
        if(size == 0) head = tail = temp;
        else{
            tail -> next = temp;
            tail = temp;
        }
        size++;
    }

    void pop(){
        if(size == 0){
            cout << "Queue is EMPTY" << endl;
            return;
        }
        Node* temp = head;
        head = head -> next;
        delete temp; // Free Memory , No wastage 
        size--;

        if (head == NULL) tail = NULL;  // Reset tail when queue becomes empty
    }

    int front(){
        if(size == 0){
            cout << "Queue is Empty" << endl;
            return -1;
        }
        return head -> val;
    }

    int back(){
        if(size == 0){
            cout << "Queue is Empty" << endl;
            return -1;
        }
        return tail -> val;
    }

    int Size(){
        return size;
    }

    bool empty(){
        if(size == 0) return true;
        else return false;
    }

    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp -> val << " ";
            temp = temp -> next;
        }
        cout << endl;
    }

};

int main(){
    Queue q;
    q.pop();
    cout << q.Size() << endl;
    cout << q.empty() << endl;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.display();
    cout << q.Size() << endl;;
    q.push(50);
    q.push(60); 
    q.display();
    q.pop();
    q.display();
}