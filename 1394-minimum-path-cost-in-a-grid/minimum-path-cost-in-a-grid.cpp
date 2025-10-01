class Solution {
public:
    int n,m;
    int dp[51][51];
    int fun(vector<vector<int>>& grid, vector<vector<int>>& moveCost,int x, int y){
        if(x==n-1)
            return grid[x][y];
        if(dp[x][y]!=-1)
            return dp[x][y];
        int mini=INT_MAX,temp;
        for(int j=0;j<m;j++){
            temp=moveCost[grid[x][y]][j]+fun(grid,moveCost,x+1,j);
            mini=min(mini,temp);
        }
        return dp[x][y]=grid[x][y]+mini;
    }
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int ans=INT_MAX;
        n=grid.size();
        m=grid[0].size();
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<m;i++)
            ans=min(ans,fun(grid,moveCost,0,i));
        return ans;
    }
};