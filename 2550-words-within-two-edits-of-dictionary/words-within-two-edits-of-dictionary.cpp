typedef struct node{
    bool end=false;
    unordered_map<char,node*>child;
}node;
class Solution {
public:
    void insert(string &s, node *root, int p){
        if(p==s.length()){
            root->end=true;
            return;
        }
        node *temp = root->child[s[p]];
        if(temp==NULL){
            temp =new node;
            root->child[s[p]]=temp;
        }
        insert(s,temp,p+1);
    }
    bool search(string &s, node *root, int i, int skip){
        cout<<s[i]<<" "<<skip<<endl;
        if(skip>2)
            return false;
        if(i==s.length())
            return true;
        bool ans=false;
        for(auto &x: root->child){
            if(!x.second)
                continue;
            if(x.first==s[i])
                ans|=search(s,x.second,i+1,skip);
            else
                ans|=search(s,x.second,i+1,skip+1);
        }
        return ans;
    }
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        node *trie = new node;
        vector<string>ans;
        for(auto &x: dictionary)
            insert(x,trie,0);
        for(auto &x:queries){
            cout<<" calling for "<<x<<endl;
            if(search(x,trie,0,0))
                ans.push_back(x);

        }
        return ans;
    }
};