class Solution {
public:
    vector<vector<int>>dp;
    int fun(vector<int>&nums,vector<int>&prefix, int l, int r, bool isAlice){
        if(l>r)
            return 0;
        if(dp[l][r]!=-1)
            return dp[l][r];
        if(isAlice){
            return
            dp[l][r]=max(
                (prefix[r+1]-prefix[l+1])+fun(nums,prefix,l+1,r,!isAlice),  //choose l
                (prefix[r]-prefix[l])+fun(nums,prefix,l,r-1,!isAlice)   // choose r
            );
        }
        return dp[l][r]= 
            min(
                -(prefix[r+1]-prefix[l+1])+fun(nums,prefix,l+1,r,!isAlice),  //choose l
                -(prefix[r]-prefix[l])+fun(nums,prefix,l,r-1,!isAlice)   // choose r
            );
    }
    int stoneGameVII(vector<int>& stones) {
        int n=stones.size();
        vector<int>prefix(n+1);
        vector<vector<int>>dp(n+1,vector<int>(n,-1));
        this->dp=dp;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=stones[i];
            prefix[i+1]=sum;
        }
        return fun(stones,prefix,0,n-1,true);
    }
};