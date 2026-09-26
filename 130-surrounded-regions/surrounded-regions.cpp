class Solution {
public:
    int xcor[4]={1,-1,0,0};
    int ycor[4]={0,0,1,-1};
    int n,m,f=1;
    void canSurround(vector<vector<char>>& grid,vector<vector<int>>&visited,int x, int y){
        if(x==n-1||x==0||y==0||y==m-1)
            {
                f=false;
                return;
            }
        
        visited[x][y]=-1;
        for(int i=0;i<4;i++){
            if(x+xcor[i]<0 ||x+xcor[i]>=n ||y+ycor[i]<0 || y+ycor[i]>=m)
                continue;
            if(visited[x+xcor[i]][y+ycor[i]])
                continue;
            if(grid[x+xcor[i]][y+ycor[i]] == 'O')
                canSurround(grid,visited,x+xcor[i],y+ycor[i]);
                
        }
    }
    bool Surround(vector<vector<char>>& grid,vector<vector<int>>&visited,int x, int y){
        visited[x][y]=1;
        grid[x][y]='X';
        for(int i=0;i<4;i++){
            if(x+xcor[i]<0 ||x+xcor[i]>=n ||y+ycor[i]<0 || y+ycor[i]>=m|| visited[x+xcor[i]][y+ycor[i]]==1)
                continue;
            if(grid[x+xcor[i]][y+ycor[i]] == 'O' )
                Surround(grid,visited,x+xcor[i],y+ycor[i]);
        }
        
        return true;
    }
    void solve(vector<vector<char>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j] || grid[i][j]=='X')
                    continue;
                f=1;
                canSurround(grid,visited,i,j);
                if(f)
                    Surround(grid,visited,i,j);
            }
        }
    }
};