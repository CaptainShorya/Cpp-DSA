#include <iostream>
#include <queue>
#include <vector>
using namespace std;

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

//size of tree
int sizeOfTree(Node* root){
    if(root == NULL) return 0;
    return 1 + sizeOfTree(root->left) + sizeOfTree(root->right);
}

//Condition 1 : All descendant of any Node should be smaller
bool isMaxNode(Node* root){
    if(root == NULL) return true;
    if(root->right != NULL && root->val < root->right->val ) return false;
    if(root->left != NULL && root->val < root->left->val) return false;
    return (isMaxNode(root->left) && isMaxNode(root->right));
}

//Condition 2 : It should be a Complete Binary Tree
bool isCBT(Node* root){
    queue<Node*> q;
    int count = 0;
    int size = sizeOfTree(root);
    q.push(root);
    while(count < size){
        Node* temp = q.front();
        q.pop();
        count++;
        if(temp != NULL){ //if node is NULL, then its kids can't exist
            q.push(temp->left);
            q.push(temp->right);
        }
    }
    while(q.size() > 0){
        if(q.front() != NULL) return false;
        q.pop();
    }
    return true;
}

int main(){
    Node* a = new Node(20);
    Node* b = new Node(15);
    Node* c = new Node(10);
    Node* d = new Node(8);
    Node* e = new Node(11);
    Node* f = NULL;
    Node* g = new Node(6);
    a->left = b; a->right = c;
    b->left = d; b->right = e;
    c->left = f;c->right = g;

    if(isCBT(a) && isMaxNode(a)) cout <<"Tree is MaxHeap";
    else cout <<"Tree is not MaxHeap";
}