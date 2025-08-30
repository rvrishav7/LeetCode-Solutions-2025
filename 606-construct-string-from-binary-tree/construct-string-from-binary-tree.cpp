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
    void helper(TreeNode *root, string &s){
        if(!root)
            return;
        s.append(to_string(root->val)); 
        if(!root->left&&!root->right)
            return;
        //left sub tree
        s.push_back('(');
        helper(root->left,s);
        s.push_back(')');

        //right sub tree
        if(root->right){
            s.push_back('(');
            helper(root->right,s);
            s.push_back(')');
        }
    }
    string tree2str(TreeNode* root) {
        string ans;
        helper(root,ans);
        return ans;
    }
};