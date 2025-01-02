/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void fun(TreeNode *root, TreeNode *target,vector<TreeNode *>&parent){
        if(!root)
            return;
        parent.push_back(root);
        if(root==target)
            return;
        fun(root->left,target,parent);
        if(parent[parent.size()-1]==target)
            return;
        fun(root->right,target,parent);
        if(parent[parent.size()-1]==target)
            return;
        parent.pop_back();
    }
    void dfs(TreeNode *root, TreeNode *avoid, vector<int>&ans,int k){
        if(k<0||!root ||root==avoid)
            return;
        if(!k)
            ans.push_back(root->val);
        dfs(root->left,avoid,ans,k-1);
        dfs(root->right,avoid,ans,k-1);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<TreeNode *>parent;
        fun(root,target,parent);
        vector<int>ans;
        dfs(parent[parent.size()-1],NULL,ans,k);
        for(int i=0;i<parent.size();i++)
            cout<<(parent[i])->val<<" ";
        for(int i=0;i<parent.size()-1;i++)
            dfs(parent[i],parent[i+1],ans,k-(parent.size()-(i+1)));
        return ans;
    }
};