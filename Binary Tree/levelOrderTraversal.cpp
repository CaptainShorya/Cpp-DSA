#include <iostream>
#include <queue>
using namespace std;

class Node{ //This is a TreeNode
public:
    int val;
    Node* left;
    Node* right;

    Node(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

//                 BFS Traversal
//Queue Approach(Optimized) for Level Order Traversal 
void levelOrderTraversal(Node* root,queue<Node*> q){
    while(q.size() > 0){
        //Step1
        Node* temp = q.front();
        q.pop();
        cout << temp->val << " ";
        
        //Step 2
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
        //To reverse order of printing, just interchange the position of these 2 lines 
        //Output is -> 1 3 2 7 5 4
    }
}


int main(){
    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    Node* e = new Node(5);
    Node* g = new Node(7);

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->right = g;

    queue<Node*> q;
    q.push(a); //Root element pushed into queue
    levelOrderTraversal(a,q);// 1 2 3 4 5 7
} 