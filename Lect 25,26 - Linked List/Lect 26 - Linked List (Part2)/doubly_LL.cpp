#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;

    //Constructor
    Node(int val){
        data = val;
        prev = next = NULL;
    }
};

class DoublyLL{
public:
    Node* head;
    Node* tail;

    //Constructor
    DoublyLL(){
        head = tail = NULL;
        
    }

    void push_front(int val){
        Node* newNode= new Node(val);

        if(head == NULL){
            head = tail = newNode;
        }else{
            newNode -> next = head;
            head -> prev = newNode;
            head = newNode;
        }
    }

    void pop_front(){
        if(head == NULL){
            cout << "LL is empty\n";
        }else{
            Node* temp = head;
            head = head -> next;
            if(head != NULL){ // We get hint whether LL containing single node or mutilple
                head -> prev = NULL;
            }
    
            temp -> next = NULL;
            delete(temp);

        }
    }

    void printLL(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp -> data << " <=> ";
            temp = temp -> next;
        }
        cout << "NULL\n";
    }
};



int main(){
    DoublyLL dbll;

    dbll.push_front(4);
    dbll.push_front(3);
    dbll.push_front(2);
    dbll.push_front(1);

    dbll.printLL();

    dbll.pop_front();
    dbll.printLL();
    return 0;
}