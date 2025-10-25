#define ll long long int 
class Solution {
public:
    vector<vector<ll>>dp;
    ll fun(vector<int>&nums, int n, bool isEven){
        if(n<0)
            return 0;
        if(dp[isEven][n]!=-1)
            return dp[isEven][n];
        if(isEven)
            return  dp[isEven][n]=max(nums[n]+fun(nums,n-1,!isEven),fun(nums,n-1,isEven));
        return  dp[isEven][n]=max((-nums[n])+fun(nums,n-1,!isEven),fun(nums,n-1,isEven)); 
    }
    long long maxAlternatingSum(vector<int>& nums) {
        vector<vector<ll>>dp(2,vector<ll>(nums.size()+1,-1));
        this->dp=dp;
        return fun(nums,nums.size()-1,true);
    }
};