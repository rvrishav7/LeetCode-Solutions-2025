class Solution {
public:
    long long int dp[15][10005];
    long long int helper(vector<int>&coins,int n, int amount){
        if(amount==0)
            return 0;
        if(n<0 || amount<0)
            return INT_MAX;
        if(dp[n][amount]!=-1)
            return dp[n][amount];
        return dp[n][amount]=min(1+helper(coins,n,amount-coins[n]),helper(coins,n-1,amount));
    }
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        memset(dp,-1,sizeof(dp));
        long long int ans=helper(coins,coins.size()-1,amount);
        return ans>=INT_MAX?-1:ans;
    }
};