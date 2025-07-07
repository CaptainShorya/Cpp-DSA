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
//Construct Binary Tree Via BFS traversal(Queue)
Node* constructBTBFS(int arr[], int n){
    queue<Node*> q;
    Node* root = new Node(arr[0]);
    q.push(root);
    int i = 1;
    int j = 2;
    while(q.size() > 0 && i<n){
        Node* temp = q.front();
        q.pop();

        //Create 2 nodes
        Node* l;
        Node* r;

        //Set their values
        if(arr[i] != INT16_MIN) l = new Node(arr[i]);
        else l = NULL;

        if(j != n && arr[j] != INT16_MIN) r = new Node(arr[j]); //TO avoid case, when i = n-1 and j = n;
        else r = NULL;

        //Make their connection 
        temp -> left = l;
        temp -> right = r;

        //Push into queue, so that connecting with next elements become easy and smooth 
        if(l != nullptr) q.push(l);
        if(r != nullptr) q.push(r);

        //Iteration movement
        i += 2;
        j += 2;
    }
    return root;
}

void display(Node* root){
    if(root == nullptr) return;
    cout << root -> val << " ";
    display(root->left);
    display(root->right);
}

int main(){
    int arr[] = {1,2,3,4,5,INT16_MIN,6,INT16_MIN,INT16_MIN,7,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    Node* root = constructBTBFS(arr,n);
    display(root);
} 