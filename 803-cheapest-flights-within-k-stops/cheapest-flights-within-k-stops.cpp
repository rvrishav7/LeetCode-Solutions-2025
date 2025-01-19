class Solution {
public:
    vector<vector<int>>ar;
    int n;
    long long dp[104][104];
    long long int dfs(int current, int destination, int k){
        if(current==destination)
            return 0;
        if(k<=0)
            return INT_MAX;
        if(dp[current][k]!=-1)
            return dp[current][k];
        long long int ans=INT_MAX,temp;
        for(int i=0;i<n;i++){
            if(!ar[current][i])
                continue;
            temp=ar[current][i]+dfs(i,destination,k-1);
            ans=min(ans,temp);
        }
        return dp[current][k]=ans;
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>>ar1(n,vector<int>(n));
        memset(dp,-1,sizeof(dp));
        ar=ar1;
        this->n=n;
        for(auto &x: flights)
            ar[x[0]][x[1]]=x[2];
        long long int ans = dfs(src,dst,k+1);
        return ans>=INT_MAX?-1:ans;
    }
};