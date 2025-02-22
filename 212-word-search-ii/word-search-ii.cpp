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
    vector<string> ans;
    int n,m,max_len=0;
    node trie;
    const int xcor[4]={0,0,-1,1};
    const int ycor[4]={-1,1,0,0};
    bool fun(vector<vector<char>>& board, node *root,vector<vector<bool>>&visited,string &s,int x, int y){
        if(s.length()>max_len || !root)
            return false;
        if(root->end){
            ans.push_back(s);
            root->end=false;
        }
        if(x<0||x>=n||y<0||y>=m||visited[x][y])
            return false;
        visited[x][y]=true;
        s.push_back(board[x][y]);
        bool res=false;
        for(int i=0;i<4;i++)
            res=fun(board,root->child[board[x][y]],visited,s,x+xcor[i],y+ycor[i]);
        visited[x][y]=false;
        s.pop_back();
        return res;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        n=board.size();
        m=board[0].size();
        string temp;
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        
        for(auto &x:words){
            insert(x,&trie,0);
            max_len=max(max_len,(int)x.length());
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                fun(board,&trie,visited,temp,i,j);
            }   
        }
        return ans;
    }
};