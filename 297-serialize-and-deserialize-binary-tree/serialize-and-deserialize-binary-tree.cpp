/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void serialise_helper(TreeNode *root, string &s){
        if(!root){
            s.push_back('N');
            return;
        }
        string t=(to_string(root->val));
        for(auto &x: t)
            s.push_back(x);
        s.push_back(' ');
        serialise_helper(root->left,s);
        serialise_helper(root->right,s);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        serialise_helper(root,s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize_helper(string s, int &p){
        if(p>=s.length() || s[p]=='N'){
            p++;
            return NULL;
        }
        int val=0,negative=0;
        if(s[p]=='-'){
            negative=1;
            p++;
        }
        while(p<s.length()&&s[p]!=' '){
            val*=10;
            val+=(s[p]-'0');
            p++;
        }
        p++;
        if(negative)
            val*=(-1);
        TreeNode *root= new TreeNode(val);
        root->left=deserialize_helper(s,p);
        root->right=deserialize_helper(s,p);
        return root;
    }
    TreeNode* deserialize(string &data) {
        int p=0;
        return deserialize_helper(data,p);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));