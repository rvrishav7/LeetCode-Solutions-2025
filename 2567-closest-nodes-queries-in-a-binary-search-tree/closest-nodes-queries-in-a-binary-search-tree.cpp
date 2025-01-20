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
    vector<int>ar;
    void createArray(TreeNode *root){
        if(!root)
            return;
        createArray(root->left);
        ar.push_back(root->val);
        createArray(root->right);
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        int n=queries.size();
        vector<vector<int>>ans(n,vector<int>(2));
        createArray(root);
        for(int i=0;i<n;i++){
            int mini=INT_MAX,maxi=INT_MIN,query=queries[i];
            auto p=lower_bound(ar.begin(),ar.end(),queries[i]);
            if(p!=ar.end()&&(*p)==queries[i])
                mini=maxi=queries[i];
            
            else{
                if(p==ar.end())
                    maxi=-1;
                else
                    maxi=*p;
                if(p==ar.begin())
                    mini=-1;
                else
                    mini=*(--p);
            }
            
            ans[i][0]=mini;
            ans[i][1]=maxi;
        }
        return ans;
    }
};