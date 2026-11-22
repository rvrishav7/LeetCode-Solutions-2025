typedef struct Node{
    int val;
    char ch;
    bool isEnd;
    unordered_map<char,Node*>child;
}Node;


class MapSum {
public:
    Node *root;
    MapSum() {
        root=NULL;
        root=new Node();
    }
    void addValue(Node *root, string &s, int p, int &val){
    if(p>=s.length()){
        root->isEnd=true;
        root->val=val;
        return;
    }

    Node *child=nullptr;
 
    if(root->child.find(s[p])!=root->child.end())
        child=root->child[s[p]];
    if(!child)
        child = new Node();
    root->child[s[p]]=child;
    child->ch=s[p];
    addValue(child,s,p+1,val);
}
    void insert(string key, int val) {
        addValue(root,key,0,val);
    }
    int finder(Node *root, string s, int p){
        if(!root) return 0;
        if(p>=s.length()){
            int sum=root->val;
            for(auto &x: root->child)
                sum+=finder(x.second,s,p);
            return sum;
        }
        if(!root->child[s[p]])
            return 0;
        return finder(root->child[s[p]],s,p+1);
    }
    int sum(string prefix) {
        return finder(root,prefix,0);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */