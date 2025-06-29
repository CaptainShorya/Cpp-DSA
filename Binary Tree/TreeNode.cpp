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

void displayTree(Node* root){
    if(root == NULL) return;
    cout << root -> val << " ";
    displayTree(root->left);
    displayTree(root -> right);
}

int sumTree(Node* root){
    if(root == NULL) return 0;
    return root -> val + sumTree(root -> left) + sumTree(root -> right);
}

int productTree(Node* root){
    if(root == NULL) return 1;
    return root -> val * productTree(root->left) * productTree(root-> right);
}

int sizeTree(Node* root){
    if(root == NULL) return 0;
    return 1 + sizeTree(root->left) + sizeTree(root->right);
}

int maxNode(Node* root){
    if(root == NULL) return INT8_MIN;
    int lMax = maxNode(root->left);
    int rMax = maxNode(root->right);
    return max(root->val,max(lMax,rMax));
    // return max(root->val,max(maxNode(root->left),maxNode(root->right)));
}

int minNode(Node* root){
    if(root == NULL) return INT16_MAX;
    int lMin = minNode(root->left);
    int rMin = minNode(root->right);
    return min(root->val,min(lMin,rMin));
}

int levels(Node* root){
    if(root == NULL) return 0;
    return 1 + max(levels(root->left),levels(root->right));
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

    displayTree(a); // 1 2 10 5 3 6 7
    cout << endl;
    cout << sumTree(a); // 34
    cout << endl;
    cout << productTree(a); // 5040
    cout<< endl;
    cout << sizeTree(a); // 7
    cout << endl;
    cout << maxNode(a); // 10
    cout << endl;
    cout << minNode(a); // 1
    cout << endl;
    cout << levels(a); // 3
} 