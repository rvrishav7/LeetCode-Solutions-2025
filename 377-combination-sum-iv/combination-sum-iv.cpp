int dp[1001];
class Solution {
public:
    int fun(vector<int>&nums, int target){
        if(target==0)
            return 1;
        if(target<0)
            return 0;
        if(dp[target]!=-1)
            return dp[target];
        int ans=0;
        for(int i=0;i<nums.size();i++)
            ans+=fun(nums,target-nums[i]);
        return dp[target]=ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        return fun(nums,target);
    }
};