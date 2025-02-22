class Solution {
public:
    bool inline GameEnded(vector<string>& board, char c){
        bool f=false;
        int count;
        for(int i=0;i<3;i++){   //check rows 
            count = 0;
            for(int j=0;j<3;j++)
                if(board[i][j]==c)
                    count++;
            if(count==3)
                return true;
        }

        for(int i=0;i<3;i++){ //check column
            count = 0;
            for(int j=0;j<3;j++)
                if(board[j][i]==c)
                    count++;
            if(count==3)
                return true;
        }

        if(board[0][0]==c && board[1][1]==c && board[2][2]==c)  //check prime diagonal
            return true;
        if(board[0][2]==c && board[1][1]==c && board[2][0]==c)  //check secondary diagonal
            return true;
        return false;    
    }
    bool validTicTacToe(vector<string>& board) {
        unordered_map<char,int>mp;
        for(auto &y: board)
            for(auto &x: y)
                mp[x]++;
        bool ended1=GameEnded(board,'X');
        bool ended2=GameEnded(board,'O');
        if(ended1&&ended2)
            return false;
        if(ended1){
            if(mp['X']-mp['O']==1)
                return true;
            return false;
        }
        
        if(ended2){
            if(mp['X']-mp['O']==0)
                return true;
            return false;
        }
        if(mp['X']-mp['O']>=0 && mp['X']-mp['O']<2)
            return true;
        return false;
    }
};