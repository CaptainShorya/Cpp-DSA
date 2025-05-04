// Floyd's cycle Finding Algorithm
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // Constructor
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class List
{
public:
    Node *head;
    Node *tail;

    List()
    {
        head = NULL;
        tail = NULL;
    }

    void push_front(int val)
    {
        Node *newNode = new Node(val);

        if (tail == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void pop_front()
    {
        if (head == NULL)
        {
            return;
        }
        Node *temp = head;
        head = head->next;

        // Deleting unusable Node
        temp->next = NULL;
        delete temp;
    }

    void push_back(int val){
        Node* newNode = new Node(val);

        if(head == NULL){
            head = tail = newNode;

        }else{
            tail -> next = newNode;
            tail = newNode;
        }
        
    }
};

void printLL(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

bool isCycle(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            cout << "Cycle Exists";
            return true;
        }
    }
    cout << "Cycle does not exists";
    return false;
}

void removeCycle(Node *head)
{
    // Detect cycle
    Node *slow = head;
    Node *fast = head;
    bool isCycle = false;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            cout << "Cycle Exists\n";
            isCycle = true;
            break;
        }
    }
    if (!isCycle)
    {
        cout << "Cycle doesn't exist\n";
        return;
    }

    // Step 2
    slow = head;

    // Special Case : When LL is completely in Loop in that case it is seen.
    if (slow == fast)
    {
        while(fast->next != slow)
        {
            fast = fast->next;
        }
        fast->next = NULL; // remove cycle
        return;
    }
    else
    { // Remove Cycle
        Node *prevNode = fast;
        while (slow != fast)
        {
            slow = slow->next;
            prevNode = fast;
            fast = fast->next;
        }
        prevNode->next = NULL; // Remove cycle
    }
}

//Merge Sort on LL
Node* splitAtMid(Node* head){
    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;

    while(fast != NULL && fast->next != NULL){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if(prev != NULL){
        prev -> next = NULL; //Split at Middle
    }
    return slow; //Bcz slow = rightHead
}

Node* merge(Node* left, Node* right){
    List ans;
    Node* i = left;
    Node* j = right;

    while(i != NULL && j != NULL){
        if(i->data <= j->data){
            ans.push_back(i->data);
            i = i->next;
        }else{
            ans.push_back(j->data);
            j = j->next;
        }
    }

    while(i != NULL){
        ans.push_back(i->data);
        i = i->next;
    }
    while(j != NULL){
        ans.push_back(j->data);
        j = j->next;
    }

    return ans.head;
}

Node* mergeSort(Node* head){
    if(head == NULL || head -> next == NULL){
        return head;
    }

    Node* rightHead = splitAtMid(head);

    Node* left = mergeSort(head); //Left Head
    Node* right = mergeSort(rightHead); //Right Head

    return merge(left, right);
}

Node* reverseLL(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while(curr != NULL){
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }

    return prev; // prev is head of reverse Linked List
}

Node* zigZagLL(Node* head){
    Node* rightHead = splitAtMid(head);
    Node* rightHeadRev = reverseLL(rightHead);

    //Alternate Merging 
    Node* left = head;
    Node* right = rightHeadRev;
    Node* tail = NULL;
    while(left != NULL && right != NULL){
        Node* nextleft = left -> next;
        Node* nextright = right -> next;
        
        left -> next = right;
        right -> next = nextleft;

        tail = right;

        left = nextleft;
        right = nextright;
    }
    if(right != NULL){
        tail -> next = right;
    }

    return head;
}


int main()
{
    List ll;

    // Floyd's Algo
    // ll.push_front(4);
    // ll.push_front(3);
    // ll.push_front(2);
    // ll.push_front(1);
    // // 1->2->3->4->1
    // ll.tail->next = ll.head;

    // // isCycle(ll.head);

    // // Remaining Cycle
    // removeCycle(ll.head);
    // printLL(ll.head);

    //Merge Sort on LL
    // ll.push_front(4);
    // ll.push_front(2);
    // ll.push_front(1);
    // ll.push_front(3);
    // ll.push_front(5);

    // printLL(ll.head);
    // ll.head = mergeSort(ll.head);
    // printLL(ll.head);

    //Zig-Zag Linked List
    ll.push_front(5);
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);

    printLL(ll.head);

    ll.head = zigZagLL(ll.head);
    printLL(ll.head);


    return 0;
}
