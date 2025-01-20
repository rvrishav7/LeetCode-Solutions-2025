class Solution {
public:
    vector<vector<int>>dp;
    int fun(vector<int>&coins, int n, int amount){
        if(amount==0)
            return 1;
        if(amount<0||n<0)
            return 0;
        if(dp[n][amount]!=-1)
            return dp[n][amount];
        return dp[n][amount]=fun(coins,n,amount-coins[n])+fun(coins,n-1,amount);
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        this->dp=dp;
        return fun(coins,coins.size()-1,amount);
    }
};