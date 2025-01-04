class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int n=board.size(),m=board[0].size(),ans=0;
        vector<vector<bool>>visited(n,vector<bool>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='.'||visited[i][j])
                    continue;
                ans++;
                int p;
                if(j+1<m&&board[i][j+1]=='X'){
                    p=j+1;
                    while(p<m&&board[i][p]=='X'){
                        visited[i][p]=true;
                        p++;
                    }
                }
                else if(i+1<n&&board[i+1][j]=='X'){
                    p=i+1;
                    while(p<n&&board[p][j]=='X'){
                        visited[p][j]=true;
                        p++;
                    }
                }
            }
        }
        return ans;
    }
};