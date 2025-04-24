class Solution {
public:
    
    int addEdge(vector<int>&a, vector<int>&b){
        long long int dis= pow(a[0]-b[0],2)+pow(a[1]-b[1],2);
        if(dis<=pow(a[2],2)&&dis<=pow(b[2],2))
            return 3;
        if(dis<=pow(a[2],2))
            return 1;
        if(dis<=pow(b[2],2))
            return 2;
        return 0;
    }
    int dfs(vector<vector<int>>&gr, int s, vector<bool>&visited){
        if(visited[s])
            return 0;
        int ans=1;
        visited[s]=true;
        for(auto &x: gr[s])
            ans+=dfs(gr,x,visited);
        return ans;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size(),ans=0;
        vector<vector<int>>gr(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int res=addEdge(bombs[i],bombs[j]);
                if(!res)
                    continue;
                if(res==3){
                    gr[i].push_back(j);
                    gr[j].push_back(i);
                }
                else if(res==1)
                    gr[i].push_back(j);
                else
                    gr[j].push_back(i);
            }
        }
        
        for(int i=0;i<n;i++){
            vector<bool>visited(n);
            ans=max(ans,dfs(gr,i,visited));
        }
        return ans;
    }
};