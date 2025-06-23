#include <iostream>
using namespace std;

class Node{ //User defined data type
public:
    int val;
    Node* next;
    Node* prev;

    Node(int value){
        this -> val = value;
        this -> next = NULL;
        this -> prev = NULL;
    }
};

class Deque{
public:
    Node* head;
    Node* tail;
    int size;

    Deque(){
        head = tail = NULL;
        size = 0;
    }

    void push_back(int val){
        Node* temp = new Node(val); // New Node Created
        if(size == 0) head = tail = temp;
        else{
            tail -> next = temp;
            temp -> prev = tail;
            tail = temp;
        }
        size++;
    }

    void push_front(int val){
        Node* temp = new Node(val); // New Node Created
        if(size == 0) head = tail = temp;
        else{
            head -> prev = temp;
            temp -> next = head;
            head = temp;
        }
        size++;
    }

    void pop_front(){
        if(size == 0){
            cout << "Deque is EMPTY" << endl;
            return;
        }
        
        Node* temp = head;

        if(size == 1){
            head = tail = NULL;
        }else{
            head = head -> next;
            head -> prev = NULL;
        }
        
        delete temp; // Free Memory , No wastage 
        size--;

        if (head == NULL) tail = NULL;  // Reset tail when queue becomes empty
    }
    
    
    void pop_back(){
        if(size == 0){
            cout << "Deque is EMPTY" << endl;
            return;
        }
        
        Node* temp = tail;

        if(size == 1){
            head = tail = NULL;
        }else{
            tail = tail -> prev;
            tail -> next = NULL;
        }
        
        delete temp; // Free Memory , No wastage 
        size--;

        if (head == NULL) tail = NULL;  // Reset tail when queue becomes empty
    }

    int front(){
        if(size == 0){
            cout << "Deque is Empty" << endl;
            return -1;
        }
        return head -> val;
    }

    int back(){
        if(size == 0){
            cout << "Deque is Empty" << endl;
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
    Deque q;
    q.pop_front();
    cout << q.Size() << endl;
    cout << q.empty() << endl;
    q.push_back(10);
    q.push_back(20);
    q.push_back(30);
    q.push_back(40);
    q.display();
    cout << q.Size() << endl;;
    q.push_front(50);
    q.push_front(60); 
    q.display();
    q.pop_back();
    q.display();
}