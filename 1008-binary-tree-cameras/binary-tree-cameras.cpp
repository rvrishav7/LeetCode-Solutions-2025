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
    int countCamera(TreeNode *root, int &count){
         if(!root)
            return 1;
        int l=countCamera(root->left,count);
        int r=countCamera(root->right,count);
        if(l==0|| r==0){
            count++;
            return 2;
        }
        if(l==2||r==2)
            return 1;
        return 0;
    }
    int minCameraCover(TreeNode* root) {
        int count=0;
        int edgeCase=countCamera(root,count);
        return edgeCase==0?count+1:count;
    }
};