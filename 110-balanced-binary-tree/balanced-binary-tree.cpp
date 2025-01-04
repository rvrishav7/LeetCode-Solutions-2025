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
    pair<int,bool> dfs(TreeNode *root){
        if(!root)
            return {0,true};
        pair<int,bool>left=dfs(root->left);
        pair<int,bool>right=dfs(root->right);
        pair<int,bool>ans={0,left.second&&right.second};
        if(abs(left.first-right.first)>1)
            ans.second=false;
        ans.first=max(left.first,right.first)+1;
        return ans;
    }
    bool isBalanced(TreeNode* root) {
        return dfs(root).second;
    }
};