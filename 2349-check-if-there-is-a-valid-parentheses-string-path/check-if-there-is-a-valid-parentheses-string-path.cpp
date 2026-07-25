short dp[101][101][205];
class Solution {
public:
    const int xcor[2]={0,1};
    const int ycor[2]={1,0};
    int n, m;
    bool fun(vector<vector<char>>& grid, int x, int y, int cnt){
        if(x<0||y<0||x>=n||y>=m)
            return false;

        cnt=(grid[x][y]=='(')?cnt+1:cnt-1;

        if(cnt<0)
        return false;
        
        if(x==n-1 && y==m-1)
        return cnt==0;
        
        if(dp[x][y][cnt]!=-1)
            return dp[x][y][cnt];

        for(int i=0;i<2;i++)
            if(fun(grid,x+xcor[i],y+ycor[i],cnt))
                return dp[x][y][cnt]=true;
        return dp[x][y][cnt]=false;
    }
    
    bool hasValidPath(vector<vector<char>>& grid) {
        n=grid.size();
        m=grid[0].size();
        memset(dp,-1,sizeof(dp));
        return fun(grid,0,0,0);
    }
};