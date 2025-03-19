class Solution {
public:
    long long int dp[101][101];
    long long int fun(vector<vector<int>>&ar, int p, int end, int time){
        if(end>=time)
            return 0;
        if(p==ar.size())
            return INT_MAX-1;
        if(dp[p][end]!=-1)
            return dp[p][end];
        long long int ans=INT_MAX-1;
        if(end<ar[p][0])
            ans=min(ans,fun(ar,p+1,end,time));
        else
            ans = min({
                1+fun(ar,p+1,ar[p][1],time),
                fun(ar,p+1,end,time),
                ans}
                );
        return dp[p][end]=ans;
    }
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(),clips.end());
        memset(dp,-1,sizeof(dp));
        long long int ans=fun(clips,0,0,time);
        return ans>=INT_MAX-1?-1:ans;
    }
};