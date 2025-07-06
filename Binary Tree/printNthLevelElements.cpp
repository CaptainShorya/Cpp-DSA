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

int levels(Node* root){
    if(root == NULL) return 0;
    return 1 + max(levels(root->left),levels(root->right));
}

void display(Node* root,int level,int n){
    if(root == NULL) return; //base 

    //Place this block of code before,between or after these two function calls -> Output remain same in each and every scenario.
    if(level == n){     
        cout << root->val << " ";
        return;
    }
    display(root->left,level+1,n); //left
    display(root -> right,level+1,n); //right
}

void displayRev(Node* root,int level,int n){
    if(root == NULL) return; //base 

    //Place this block of code before,between or after these two function calls -> Output remain same in each and every scenario.
    if(level == n){
        cout << root->val << " ";
        return;
    }
    displayRev(root->right,level+1,n); //right
    displayRev(root ->left,level+1,n); //left
}

void printLevels(Node* root){
    int n = levels(root);
    for(int i=1; i<=n; i++){
        displayRev(root,1,i);
        cout << endl;
    }
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

    printLevels(a);
} 