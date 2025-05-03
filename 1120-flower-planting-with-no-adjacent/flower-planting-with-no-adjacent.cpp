class Solution {
public:
    
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>>gr(n+1);
        vector<int>ans(n,-1);
        int u,flower,val;
        for(auto &x: paths){
            gr[x[0]].push_back(x[1]);
            gr[x[1]].push_back(x[0]);
        }
        queue<pair<int,int>>q;
        
        for(int i=1;i<=n;i++){
            if(ans[i-1]>0)
                continue;
            q.push({i,1});
            ans[i-1]=1;
            while(!q.empty()){
                pair<int,int>f;
                f=q.front();
                q.pop();
                u=f.first;
                flower=ans[u-1];
                val=((flower)%4)+1;
                for(auto &x: gr[u]){
                    if(ans[x-1]==-1){
                        q.push({x,val});
                        ans[x-1]=val;
                        val=((val)%4)+1;
                    }
                    else if(ans[x-1]==flower){
                        q.push({x,val});
                        ans[x-1]=val;
                        val=((val)%4)+1;
                    }
                }
            }
        }
        return ans;
    }
};