class Solution {
public:
    vector<vector<int>>dp;
    int fun(vector<int>&prices, int n, int sold){
        if(n<0)
            return 0;
        if(dp[n][sold+1]!=-1)
            return dp[n][sold+1];
        int a,b;
        if(sold<0){                 // not sold yet
            a=fun(prices,n-1,n);    // sold today at n'th day
            b=fun(prices,n-1,sold); // not sold
        }
        else{
            a=max(0,(prices[sold]-prices[n]))+fun(prices,n-2,-1); //since you buy today at nth day you can buy on or before  n-2 day 
            b=fun(prices,n-1,sold);                               // you don't buy today
        }
        return dp[n][sold+1]=max(a,b);
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+2,vector<int>(n+2,-1));
        this->dp=dp;
        return fun(prices,prices.size()-1,-1);
    }
};