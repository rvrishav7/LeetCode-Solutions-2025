class Solution {
public:
    const int xcor[4]={0,0,-1,1};
    const int ycor[4]={-1,1,0,0};
    
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n=isWater.size(), m=isWater[0].size(),x,y,dis;
        vector<vector<int>>res(n,vector<int>(m));
        queue<vector<int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                res[i][j]=INT_MAX;
                if(isWater[i][j])
                    q.push({i,j,0});
            }
        }
        while(!q.empty()){
            x=q.front()[0];
            y=q.front()[1];
            dis=q.front()[2];
            q.pop();
            if(x<0||x>=n||y<0||y>=m)
                continue;
            if(res[x][y]<=dis)
                continue;
            res[x][y]=dis;
            for(int i=0;i<4;i++)
                q.push({xcor[i]+x,ycor[i]+y,dis+1});
        }
        return res;
    }
};