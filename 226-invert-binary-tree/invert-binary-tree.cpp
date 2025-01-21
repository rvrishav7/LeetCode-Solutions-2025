/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode *>q;
        TreeNode *temp=NULL;
        if(root)
            q.push(root);
        while(!q.empty()){
            //ans.push_back(q.front()->data);
            temp=q.front()->left;
            if(q.front()->right)
                q.push(q.front()->right);
            if(q.front()->left)
                q.push(q.front()->left);
            q.front()->left=q.front()->right;
            q.front()->right=temp;
            q.pop();
        }
    return  root;    
    }
};