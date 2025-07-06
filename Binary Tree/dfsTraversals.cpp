#include <iostream>
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

void preOrder(Node* root){
    if(root == NULL) return; //base 
    cout << root -> val << " "; //root
    preOrder(root->left); //left
    preOrder(root -> right); //right
}

void inOrder(Node* root){
    if(root == NULL) return; //base 
    inOrder(root->left);//left
    cout << root -> val << " ";//root
    inOrder(root -> right);//right
}

void postOrder(Node* root){
    if(root == NULL) return; //base 
    postOrder(root->left);//left
    postOrder(root -> right);//right
    cout << root -> val << " ";//root
}

int main(){
    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    Node* e = new Node(5);
    Node* f = new Node(6);
    Node* g = new Node(7);

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;

    preOrder(a); // 1 2 4 5 3 6 7
    cout<<endl;
    inOrder(a); // 4 2 5 1 6 3 7
    cout<<endl;
    postOrder(a); // 4 5 2 6 7 3 1
    cout<<endl;
    
} 