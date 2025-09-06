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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*>q;
        root->val=0;
        q.push(root);
        TreeNode *curr=NULL;
        while(!q.empty()){
            int size=q.size(),sum=0;
            vector<TreeNode*>temp;
            while(size--){
                curr=q.front();
                q.pop();
                if(curr->left)
                    sum+=(curr->left->val);
                if(curr->right)
                    sum+=(curr->right->val);
                q.push(curr);
            }
            size=q.size();
            while(size--){
                curr=q.front();
                q.pop();
                if(curr->left&&curr->right){
                    curr->left->val=curr->right->val=(sum-curr->left->val-curr->right->val);
                    q.push(curr->left);
                    q.push(curr->right);
                }
                else if(curr->left)
                {
                    curr->left->val=(sum-curr->left->val);
                    q.push(curr->left);
                }
                else if(curr->right)
                {
                    curr->right->val=(sum-curr->right->val);
                //    q.push(curr->left);
                    q.push(curr->right);
                }
            }
        }
        return root;
    }
};