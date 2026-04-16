//LP 133 : Clone Graph(Must DO)
#include <iostream>
#include <vector>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    vector<Node*> nodeRegistry; //Stoes address of ith node at ith index
    void dfs(Node* actual, Node* clone){ // Original , Clone 
        for(auto num : actual->neighbors){
            if(nodeRegistry[num->val] == NULL){
                //create the neighbor for the first time
                Node* newNode = new Node(num->val);
                nodeRegistry[newNode->val] = newNode;
                clone->neighbors.push_back(newNode);
                dfs(num,newNode);
            }else{
                //Node already exist
                clone->neighbors.push_back(nodeRegistry[num->val]);
            }
        }
    }

    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        Node* clone = new Node(node->val);
        nodeRegistry.resize(101,NULL); //this array contains reference to the created node
        nodeRegistry[clone->val] = clone;
        dfs(node,clone);
        return clone;
    }
};