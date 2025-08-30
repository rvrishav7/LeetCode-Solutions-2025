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
    pair<bool,int> fun(TreeNode* root, priority_queue<int,vector<int>,greater<int>>&q,int &k){
        if(!root)
            return {true,0};
        pair<bool,int> left=fun(root->left,q,k);
        pair<bool,int> right=fun(root->right,q,k);
        if(left.first&&right.first){
            if(left.second==right.second)
                q.push(left.second+right.second+1);
            if(q.size()>k)
                q.pop();
        }
       // cout<<"at "<<root->val<<" : top "<<q.top()<<endl;
        return {left.first&&right.first&&(left.second==right.second),1+(left.second+right.second)};
    }
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        priority_queue<int,vector<int>,greater<int>>q;
        fun(root,q,k);
        return q.size()==k?q.top():-1;
    }
};