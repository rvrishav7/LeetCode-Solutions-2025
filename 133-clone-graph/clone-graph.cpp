/*
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
*/

class Solution {
public:
    Node* clone(Node *root, unordered_map<int,Node*>&visited){
        if(!root)
            return NULL;
        Node *temp=new Node(root->val);
        visited[root->val]=temp;
        vector<Node*>neighbours;
        for(auto &x:root->neighbors){
            if(visited[x->val]!=NULL)
                neighbours.push_back(visited[x->val]);
            else
                neighbours.push_back(clone(x,visited));
        }
        temp->neighbors=neighbours;
        return temp;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<int,Node*>visited;
        return clone(node,visited);        
    }
};