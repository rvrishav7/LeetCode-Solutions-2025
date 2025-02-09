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
    int dfs(TreeNode *root, int &x,int &l, int &r){
        if(!root)
            return 0;
        int left=dfs(root->left,x,l,r);
        int right=dfs(root->right,x,l,r);
        if(root->val == x){
            l=left;
            r=right;
        }
        return left+right+1;
    }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        vector<int>temp(3);
        dfs(root,x,temp[0],temp[1]);
        temp[2]=n-(temp[0]+temp[1]+1);
        sort(temp.begin(),temp.end());
        return temp[2]>(temp[0]+temp[1]+1);
    }
};