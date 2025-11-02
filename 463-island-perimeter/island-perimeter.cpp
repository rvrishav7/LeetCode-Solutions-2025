class Solution {
public:
    int xcor[4]={0,0,1,-1};
    int ycor[4]={1,-1,0,0};
    int n,m;
    int findIsLand(vector<vector<int>>&grid,vector<vector<bool>>&visited, int x, int y){
        if(x<0||y<0||x>=n||y>=m)
            return 1;
        if(!grid[x][y])
            return 1;
        if(visited[x][y])
            return 0;
        visited[x][y]=true;
        int ans=0;
        for(int i=0;i<4;i++)
            ans+=findIsLand(grid,visited,xcor[i]+x,ycor[i]+y);
        //visited[x][y]=false;
        return ans;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                    if(!visited[i][j]&&grid[i][j])
                        return findIsLand(grid,visited,i,j);
        return 0;
    }
};