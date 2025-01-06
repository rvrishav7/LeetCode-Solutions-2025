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
class BSTIterator {
public:
    vector<int>bst;
    int p=0;
    void BSTIterator_helper(TreeNode* root) {
        if(!root)
            return;
        BSTIterator_helper(root->left);
        bst.push_back(root->val);
        BSTIterator_helper(root->right);
    }
    BSTIterator(TreeNode* root) {
        BSTIterator_helper(root);
    }
    
    int next() {
        return bst[p++];
    }
    
    bool hasNext() {
        return p<bst.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */