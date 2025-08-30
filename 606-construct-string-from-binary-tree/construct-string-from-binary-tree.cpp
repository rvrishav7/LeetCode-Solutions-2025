class Solution {
public:
    void helper(TreeNode* root, ostringstream &oss) {
        if (!root) return;

        oss << root->val;

        if (!root->left && !root->right) return;

        oss << "(";
        helper(root->left, oss);
        oss << ")";

        if (root->right) {
            oss << "(";
            helper(root->right, oss);
            oss << ")";
        }
    }

    string tree2str(TreeNode* root) {
        ostringstream oss;
        helper(root, oss);
        return oss.str();
    }
};
