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
    int ans=0;
    pair<int,int> fun(TreeNode *root){
        if(!root)
            return {0,0};
        int sum=root->val,n=1;
        pair<int,int>left=fun(root->left);
        pair<int,int>right=fun(root->right);
        sum+=(left.first+right.first);
        n+=(left.second+right.second);

        if((sum/n)==root->val)
        {    ans++;
                //cout<<root->val<<endl;
        }
        return {sum,n};
    }
    int averageOfSubtree(TreeNode* root) {
        fun(root);
        return ans;
    }
};