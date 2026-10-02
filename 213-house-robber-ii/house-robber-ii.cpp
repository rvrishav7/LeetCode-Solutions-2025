class Solution {
public:
    int dp[1001][4];
    int fun(vector<int>&nums, int n, int lastUsed){
        if(n==0){
            return max(
                (lastUsed&1)?0:((lastUsed!=0)?nums[0]:max(nums[nums.size()-1],nums[0]))
                ,
                (lastUsed)?0:nums[nums.size()-1]
            );
        }
        if(n==-1)
            return (lastUsed)?0:nums[nums.size()-1];
        if(dp[n][lastUsed]!=-1)
            return dp[n][lastUsed];
        int val=0;
        if(n==nums.size()-1)
            val=1;
        if(n==nums.size()-2)
            val=2;
        return dp[n][lastUsed]=max(
            nums[n]+fun(nums,n-2,lastUsed+val),
            fun(nums,n-1,lastUsed)
        );
         
    }
    
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return fun(nums,nums.size()-1,0);
    }
};