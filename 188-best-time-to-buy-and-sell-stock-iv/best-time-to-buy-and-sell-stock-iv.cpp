#define BUY 1
#define SELL 2
class Solution {
public:
int dp[1005][105][3];
int fun(vector<int>&nums, int n, int k, int state){
    if(n>=nums.size())
        return 0;
    if(k<=0)
        return 0;
    if(dp[n][k][state]!=-1)
        return dp[n][k][state];
    int ans=0,temp;
    if(state==BUY){
        temp=-nums[n]+fun(nums,n+1,k,SELL);
        ans=max(temp,fun(nums,n+1,k,BUY));
    }
    else{
        temp=nums[n]+fun(nums,n+1,k-1,BUY);
        ans=max(temp,fun(nums,n+1,k,SELL));
    }
    return dp[n][k][state]=ans;
}
    int maxProfit(int k, vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return fun(prices,0,k,BUY);
    }
};