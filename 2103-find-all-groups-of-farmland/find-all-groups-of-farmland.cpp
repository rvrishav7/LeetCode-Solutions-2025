class Solution {
public:
    int n,m;
    vector<vector<int>> res;
    int xcor[2]={0,1};
    int ycor[2]={1,0};
    void createGroup(vector<vector<int>>& land,vector<vector<bool>>&visited, int x, int y){
        queue<pair<int,int>>q;
        int lx=x,ly=y,rx=-1,ry=-1;
        q.push({x,y});
        while(!q.empty()){
            pair<int,int>f;
            f=q.front();
            q.pop();
            if(f.first>=n||f.second>=m)
                continue;
            if(visited[f.first][f.second] ||!land[f.first][f.second])
                continue;
            visited[f.first][f.second]=true;
            
            rx=max(rx,f.first);
            ry=max(ry,f.second);

            for(int i=0;i<2;i++)
                q.push({f.first+xcor[i],f.second+ycor[i]});
        }
        res.push_back({lx,ly,rx,ry});
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {    
        n=land.size();
        m=land[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(land[i][j]&&!visited[i][j])
                    createGroup(land,visited,i,j);
        return res;
    }
};