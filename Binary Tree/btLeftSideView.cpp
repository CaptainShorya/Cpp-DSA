#include<iostream>
#include<vector>
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
    if(root == nullptr) return 0;
    return 1+max(levels(root->left),levels(root->right));
}

void levelOrderTraversal(Node* root, vector<int>& vec, int level, int currLevel){
    if(root == nullptr) return;
    if(currLevel == level){
        vec[level-1] = root->val;
        return;
    }
    levelOrderTraversal(root->right,vec,level,currLevel+1);
    levelOrderTraversal(root->left,vec,level,currLevel+1);
}

int main(){
    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    // Node* d = new Node(4);
    Node* e = new Node(5);
    Node* f = new Node(6);
    Node* g = new Node(7);

    a->left = b;
    a->right = c;
    // b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;

    int n = levels(a);
    vector<int> vec(n,0);
    for(int i=1; i<=n; i++){
        levelOrderTraversal(a,vec,i,1);
    }
    for(int el : vec){
        cout << el << " ";
    }
}