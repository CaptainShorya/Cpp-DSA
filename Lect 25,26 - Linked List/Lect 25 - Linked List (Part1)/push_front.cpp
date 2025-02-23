#include <iostream>
using namespace std;

//Node class creation
class Node{

public:
    int data;
    Node* next;


    //Constructor
    Node(int val){
        data = val;
        next = NULL; //next ptr initialises with NULL value.
    }
};

//List class creation
class List{
    Node* head;
    Node* tail;

public:
    List(){
        head = NULL;
        tail = NULL;
    }

    void push_front(int val){
        Node* newNode = new Node(val); //Dynamic Allocation -> Does not depend on function call
        // Node* newNode(val); //Static memory allocation -> Node will be deleted when the function call ends

        if(head == NULL){
            head = tail = newNode;
        }else{
            newNode->next = head;
            head = newNode;
        }

    }
};

int main(){
    List ll;

    ll.push_front(3); 
    ll.push_front(2);
    ll.push_front(1);
    // 1->2->3 
    return 0;
}