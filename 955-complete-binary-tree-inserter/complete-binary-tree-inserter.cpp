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
class CBTInserter {
public:
    TreeNode *root=NULL,*front,*temp;
    queue<TreeNode *>q;
    void initialise(){
        q.push(root);
        do{
            front=q.front();
            if(front->left)
                q.push(front->left);
            if(front->right)
                q.push(front->right);
            if(q.front()->left && q.front()->right)
                q.pop();
            if(q.front()->left&&!q.front()->right&&front!=q.front())
                q.push(q.front()->left);
        }while(q.front()->left && q.front()->right);
        
    }
    CBTInserter(TreeNode* root) {
        this->root=root;
        if(root)
            initialise();
    }
    
    int insert(int val) {
        if(!root){
            root= new TreeNode(val);
            q.push(root);
            return root->val;
        }

        front=q.front();
        temp= new TreeNode(val);

        if(!front->left)
            front->left=temp;
        else
            front->right=temp;
        q.push(temp);
        if(front->right)
            q.pop();
        return front->val;
    }
    
    TreeNode* get_root() {
        return root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */