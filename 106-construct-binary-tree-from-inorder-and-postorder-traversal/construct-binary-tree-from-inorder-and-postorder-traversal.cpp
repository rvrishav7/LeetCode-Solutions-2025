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
    TreeNode* fun(vector<int>& inorder, vector<int>& postorder, int &p, int l, int h){
        if(p<0 || l>h)
            return NULL;
        TreeNode *root=new TreeNode(postorder[p]);
        
        int mid=l;
        while(mid<=h&&inorder[mid]!=postorder[p])
            mid++;
        p--;
        root->right=fun(inorder,postorder,p,mid+1,h);
        root->left=fun(inorder,postorder,p,l,mid-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int p=inorder.size()-1;
        return fun(inorder,postorder,p,0,inorder.size()-1);
    }
};