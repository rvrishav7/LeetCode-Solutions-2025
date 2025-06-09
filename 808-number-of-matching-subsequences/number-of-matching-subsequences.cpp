typedef struct Trie{
    char ch;
    unordered_map<char,Trie *>child;
    int pos=-1;
}Trie;
class Solution {
    Trie root;
public:
    bool addTrie(string &s, string &word, Trie *root, int p, int l){
        if(p==word.length())
            return true;
        int pos=s.length();
        for(int i=l;i<s.length();i++){
            if(s[i]==word[p]){
                pos=i;
                break;
            }
        }
        if(pos==s.length())
            return false;
        Trie *newNode = new Trie();
        newNode->ch=word[p];
        newNode->pos=pos;
        root->child[word[p]]=newNode;
        return addTrie(s,word,newNode,p+1,pos+1);
    }
    bool search(string &s, string &word,Trie *root, int p, int l){
        if(p>=word.length())
            return true;
        if(root->child[word[p]]!=NULL){   // word exists in trie
            return search(s,word,root->child[word[p]],p+1,root->pos+1);
        }
        else{
            return addTrie(s,word,root,p,root->pos+1);
        }
        return 0; // dummy
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        int ans=0;
        for(auto &word: words)
            ans+=search(s,word,&root,0,-1);
        
        return ans;
    }
};