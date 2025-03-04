typedef struct node {
    char c;
    node *child[26];
    int count;
    node(char c){
        this->c=c;
        memset(child,NULL,sizeof(child));
        count=1;
    }
}node;
class Solution {
public:
    void create(node *root, string &s, int p){
        if(p==s.length())
            return;
        node *temp= root->child[s[p]-'a'];
        if(!temp){
            temp=new node(s[p]);
            root->child[s[p]-'a']=temp;
        }
        else
            temp->count++;
        create(temp,s,p+1); 
    }

    void prefix(node *root, string &s, int p, int &count){
        if(p==s.length())
            return;
        node *temp= root->child[s[p]-'a'];
        if(!temp)
            return;
        count+=(temp->count);
        prefix(temp,s,p+1,count); 
    }

    vector<int> sumPrefixScores(vector<string>& words) {
        int n=words.size(),c=0;
        vector<int>ans(n);
        node *root=new node('\0');

        for(auto &word: words)
            create(root,word,0);
        for(int i=0;i<n;i++){
            c=0;
            prefix(root,words[i],0,c);
            ans[i]=c;
        }
        return ans;
    }
};