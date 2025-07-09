#include <iostream>
#include<vector>
#include<queue>
using namespace std;

//ALL in One Problem comprise of majorly every concept studied yet...

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

void printLevels(Node* root){
    int n = levels(root);
    for(int i=1; i<=n; i++){
        display(root,1,i);
        cout << endl;
    }
}

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

void bottomBoundary(Node* root, vector<int>& vec){
    if(root == NULL) return; //base 
    if(root->left == nullptr && root->right == nullptr) vec.push_back(root->val);
    bottomBoundary(root->left,vec); //left
    bottomBoundary(root -> right,vec); //right
}

void BoundaryTraversal(Node* root,vector<int>& vec){
    if(root) vec.push_back(root->val);

    //Left Boundary 
    Node* temp = root->left;
    
    while(temp){
        //Prevent from printing Right end corner(Lead node)
        if (temp->left != nullptr || temp->right != nullptr) vec.push_back(temp->val);
        
        if (temp->left) temp = temp->left;
        else temp = temp->right;
    }

    //Leaf Nodes
    bottomBoundary(root,vec);

    //Right Boundary
    vector<int> rightBoundary;
    temp = root->right;
    while(temp){
        //Prevent from printing Right end corner(Lead node)
        if (temp->left != nullptr || temp->right != nullptr) rightBoundary.push_back(temp->val);

        if(temp->right) temp = temp -> right;
        else temp = temp -> left;  
    }
    for(int i=rightBoundary.size()-1; i>=0; i--){
        vec.push_back(rightBoundary[i]);
    }
}

int main(){
    int arr[] = {1,2,3,4,5,INT16_MIN,6,7,INT16_MIN,8,INT16_MIN,9,10,INT16_MIN,11,INT16_MIN,12,INT16_MIN,13,INT16_MIN,14,15,16,INT16_MIN,17,INT16_MIN,INT16_MIN,18,INT16_MIN,19,INT16_MIN,INT16_MIN,INT16_MIN,20,21,22,23,INT16_MIN,24,25,26,27,INT16_MIN,INT16_MIN,28,INT16_MIN,INT16_MIN};
    int n = sizeof(arr)/sizeof(arr[0]);
    Node* root = constructBTBFS(arr,n);

    vector<int> vec;
    cout << "Tree Diagram : ";
    printLevels(root);
    BoundaryTraversal(root,vec);
    cout <<"Boundary Traversal : ";
    for(int i=0; i< vec.size(); i++){
        cout << vec[i] << " ";
    }
    cout << endl;
} 