#define ll long long int
#define MAXI 1000000001
ll dp[101][101];
class Solution {
public:
    const int xcor[5]={0,0,0,1,-1};
    const int ycor[5]={0,1,-1,0,0};
    int n,m,x,y,dist,temp;
    int minCost(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                dp[i][j]=MAXI;

        deque<pair<pair<int,int>,int>>q;
        q.push_back({{0,0},0});
        dp[0][0]=0;
        while(!q.empty()){
            pair<pair<int,int>,int>top=q.front();
            q.pop_front();
            
            x=top.first.first;
            y=top.first.second;
            dist=top.second;
        
            for(int i=1;i<=4;i++){
                temp=1;
                if(grid[x][y]==i)
                    temp=0;
                if(x+xcor[i]<0||y+ycor[i]<0||x+xcor[i]>=n||y+ycor[i]>=m)
                    continue;
                if(temp+dp[x][y]<dp[x+xcor[i]][y+ycor[i]]){
                    dp[x+xcor[i]][y+ycor[i]]=temp+dp[x][y];
                    q.push_back({{x+xcor[i],y+ycor[i]},dp[x+xcor[i]][y+ycor[i]]});
                }
            }
        }

        return dp[n-1][m-1];
    }
};