#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)

class Node{
public:
    int val;
    Node* left;
    Node* right;
    
    Node(int val){
        this->val = val;
        this->right = NULL;
        this -> left = NULL;
    }
};

//We want in decreasing order and to be stored in an array. So reverse InorderTraversal is used.
void inOrderTraversal(Node* root,vector<int>& vec){
    if(root == NULL) return;
    inOrderTraversal(root->right,vec);
    vec.push_back(root->val);
    inOrderTraversal(root->left,vec);
}

//Pushing element in-order to make a "maxHeap" of the Binary search tree.
void preOrderTraversal(Node* root,vector<int>& vec,int& i){
    if(root == NULL) return;
    root->val = vec[i];
    i++;
    preOrderTraversal(root->left,vec,i);
    preOrderTraversal(root->right,vec,i);
}

void LevelOrder(Node* root){
    queue<Node*> q;
    q.push(root);
    while(q.size() > 0){
        Node* temp = q.front();
        q.pop();
        cout << temp -> val << " ";
        if(temp->left != NULL) q.push(temp->left);
        if(temp->right != NULL) q.push(temp->right);
    }
    cout << endl;
}

int main(){
    Node* a = new Node(10);
    Node* b = new Node(5);
    Node* c = new Node(16);
    Node* d = new Node(1);
    Node* e = new Node(8);
    Node* f = new Node(12);
    Node* g = new Node(20);
    a->left = b; a->right = c;
    b->left = d; b->right = e;
    c->left = f; c->right = g;

    vector<int> vec; // reverse inorder
    inOrderTraversal(a,vec);
    LevelOrder(a);
    //Pushing Back element back into the tree;
    int i = 0;
    preOrderTraversal(a,vec,i); // BST -> MaxHeap
    LevelOrder(a);
}