typedef struct Node{
    bool isEnd;
    char c;
    unordered_map<int,Node *>child;
    Node(char ch='\0', bool end=true){
        isEnd=end;
        c=ch;
    }
}Node;
class WordDictionary {
public:
    Node *root;
    WordDictionary() {
        root=new Node();
    }
    void add(Node *root, string &s, int p){
        if(p>=s.length())
            return;
        Node *temp;
        if(root->child.find(s[p]-'a')==root->child.end())
            temp=new Node(s[p],false);
        else
            temp=root->child[s[p]-'a'];
        root->child[s[p]-'a']=temp;
        if(p==s.length()-1)
            {   
                temp->isEnd=true;}
        add(temp,s,p+1);
    }
    void addWord(string word) {
        add(root,word,0);
    }
    
    bool finder(Node *root, string &s, int p){
        if(!root)
            return false;
       // cout<<"at "<<root->c<<" checking "<<s[p]<<endl;
        if(p==s.length())
        {   
           // cout<<s<<" found "<<root->isEnd<<endl;
            return root->isEnd;
        }
      //  cout<<s<<" "<<s[p]<<endl;
        if(s[p] =='.'){
            for(auto &x: root->child)
            {   if(x.second!=nullptr)
                {    if(finder(x.second,s,p+1))
                        return true;
                }
            }
        }
        else{
            if(root->child.find(s[p]-'a')==root->child.end())    
                return false;
            
            return finder(root->child[s[p]-'a'],s,p+1);
        }
        return false;
    }
    bool search(string word) {
      //  cout<<"=============== "<<word<<endl;
        return finder(root,word,0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */