#define MAX_DIS 9000000000
#define MOD 1000000007
class Solution {
public:
    vector<long long int>dijkstra(vector<vector<pair<long long int,long long int>>>&gr, int& n){
        vector<long long int>distance(n+1,MAX_DIS);
        long long int u,weight;
        priority_queue<pair<long long int,long long int>,vector<pair<long long int,long long int>>,greater<pair<long long int,long long int>>>q;
        distance[n]=0;
        q.push({distance[n],n}); //{wt,node}

        while(!q.empty()){
            weight=q.top().first;
            u=q.top().second;
            q.pop();

            for(auto &v: gr[u]){
                if(distance[v.first]>distance[u]+v.second){
                    distance[v.first]=distance[u]+v.second;
                    q.push({distance[v.first],v.first});
                }
            }
        }
        return distance;
    }
    long long int resPaths(vector<vector<pair<long long int,long long int>>>&gr,vector<long long int>&ar,vector<long long int >&dp, long long int s, int n){
        if(s==n)
            return 1;
        if(dp[s]!=-1)
            return dp[s];
        long long int dis=ar[s],count=0,p;
        for(auto &x: gr[s]){
            p=x.first;  // intermmediate node
            if(ar[p]<dis)
                count=((count%MOD)+(resPaths(gr,ar,dp,p,n)%MOD))%MOD;
        }
        return dp[s]=count;
    }
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<vector<pair<long long int,long long int>>>gr(n+1);
        vector<long long int>dis;
        vector<long long int >dp(n+1,-1);
        for(auto &x: edges){
            gr[x[0]].push_back({x[1],x[2]}); //{node,weight}
            gr[x[1]].push_back({x[0],x[2]});
        }
        dis=dijkstra(gr,n);
        return resPaths(gr,dis,dp,1,n);
    }
};