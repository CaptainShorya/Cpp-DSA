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

    ~Node(){
        // cout << "~Node" << data << endl; //For understanding purpose
        if(next != NULL){
            delete next;
            next = NULL;
        }
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

    ~List(){
        // cout << "~List" << endl; //For Understanding purpose 
        if(head != NULL){
            delete head; // Triggers Node destructor for head node
            head = NULL;
        }
    }

    void push_front(int val){
        Node* newNode = new Node(val); //Dynamic Allocation -> Does not depend on function call
        // Node* newNode(val); //Static memory allocation -> Node will be deleted when the function call ends

        if(head == NULL){ //If LL is empty
            head = tail = newNode;
        }else{ //If LL exists
            newNode->next = head;
            head = newNode;
        }

    }

    void push_back(int val){
        //node creation
        Node* newNode = new Node(val);

        if(head == NULL){ //If LL is empty
            head = tail = newNode;
        }else{ //If LL exists
            tail->next = newNode;
            tail = newNode;
        }
    }

    void printList(){
        Node* temp = head;

        while(temp != NULL){
            cout << temp->data << "->";
            temp = temp->next;
        }

        cout << "NULL\n";

    }

    void insert(int val, int pos){
        Node* newNode = new Node(val);
        Node* temp = head;

        if(head == NULL){ //If LL is Empty 
            head = tail = newNode;
        }else{
            for(int i=0; i<pos-1; i++){
                if(temp == NULL){ // Handel invalid position 
                    cout << "Position is Invalid\n";
                    return;
                }
                temp = temp->next;
            }

            //temp is now at pos-1 i.e prevNode
            newNode->next = temp->next;
            temp->next = newNode;
        }

    }

    void pop_front(){
        if(head == NULL){
            cout << "LL is Empty\n";
            return;
        }

        Node* temp = head; //To deallocate the memory given to starting node
        head = head->next;
        
        temp->next = NULL; //Connection breaks
        delete temp;
    }

    void pop_back(){
        if(head == NULL){
            cout << "LL is Empty\n";
            return;
        }

        Node* temp = head;
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        temp->next = NULL; //Connection breaks // temp = tail's prev
        delete tail;
        tail = temp;
    }

    int searchitr(int key){ // O(n)
        Node* temp = head;
        int idx = 0;

        while(temp != NULL){
            if(temp->data == key){
                return idx;
            }
            temp = temp->next;
            idx++;
        }
        return -1;
    }


    int helper(Node* temp, int key){
        //Base Case
        if(temp == NULL){
            return -1;
        }

        if(temp->data == key){
            return 0;
        } 

        int idx = helper(temp->next,key);
        if(idx == -1){
            return -1;
        }

        return idx+1;
    }

    int reccursiveSearch(int key){
        return helper(head,key); //This is done bcz main function can't directly access private access modifiers and only accessible inside the same class.
    }

    void reverse(){
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;

        while(curr != NULL){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        head = prev; 
    }

    int size(){
        int sz = 0;
        Node* temp = head;
        while(temp != NULL){
            temp = temp -> next;
            sz++;
        }
        return sz;
    }

    void removeNth(int n){ // TC : O(N)
        int sz = size();
        Node* prev = head;
        for(int i=1; i<(sz - n); i++){
            prev = prev -> next;
        }
        Node* toDel = prev -> next;
        cout << "Going to get deleted: " << toDel -> data << endl;
        prev -> next = prev -> next -> next;
    }
};

int main(){
    List ll;

    // ll.push_front(3); 
    // ll.push_front(2);
    // ll.push_front(1);

    // ll.printList(); // 1->2->3->NULL

    // ll.push_back(4);
    // ll.push_back(5); 
    // ll.printList(); // 1->2->3->4->5->NULL

    // ll.insert(100,2);
    // ll.printList(); // 1->2->100->3->4->5->NULL

    //Delete LL -> Run this by commenting the above code
    // ll.push_front(3); 
    // ll.push_front(2);
    // ll.push_front(1);

    // ll.printList(); // 1->2->3->Null

    // //Delete from start
    // ll.pop_front();
    // ll.printList(); // 2->3->Null

    // //Delete form back
    // ll.pop_back();
    // ll.printList(); // 2->NULL

    //Search iterative for key
    // ll.push_front(3); 
    // ll.push_front(2);
    // ll.push_front(1);

    // ll.printList(); // 1->2->3->Null
    // cout << ll.searchitr(2) << endl;
    // cout << ll.searchitr(4) << endl;

    // //Recursive Search
    // cout << ll.searchitr(3) << endl;
    // cout << ll.searchitr(5) << endl;

    //Reverse LL
    // ll.push_front(3); 
    // ll.push_front(2);
    // ll.push_front(1);

    // ll.printList();
    // ll.reverse();
    // ll.printList();

    //Remove Nth
    ll.push_front(5);
    ll.push_front(4);
    ll.push_front(3); 
    ll.push_front(2);
    ll.push_front(1);

    ll.printList();
    ll.removeNth(2);
    ll.printList();

     
    return 0;
}