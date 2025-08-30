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

    void serial(TreeNode *root, string &s){
        if(!root){
            s.push_back('N');
            return;
        }
        s=s+to_string(root->val);
        s.push_back(',');
        serial(root->left,s);
        serial(root->right,s);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string encrypted;
        serial(root,encrypted);
        return encrypted;
    }
    TreeNode *deserial(string &s, int &p){
        if(p==s.length()||s[p]=='N'){
            p++;
            return NULL;
        }
        int n=0;
        while(p<s.length()&&s[p]!=','){
            n=n*10+(s[p]-'0');
            p++;
        }
        p++;
        TreeNode *root=new TreeNode(n);
        root->left=deserial(s,p);
        root->right=deserial(s,p);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int p=0;
        return deserial(data,p);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;