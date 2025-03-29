int dp[101][3005];
class Solution {
public:
    int sum;
    int fun(vector<int>&nums, int p, int &sum , int target){
        if(p>=nums.size() || (sum-(2*target)<=0))
            return abs((sum-(2*target)));
        if(dp[p][target]!=-1)
            return dp[p][target];
        return dp[p][target]=min(
            fun(nums,p+1,sum,target+nums[p]),
            fun(nums,p+1,sum,target)
        );
    }
    int lastStoneWeightII(vector<int>& stones) {
        memset(dp,-1,sizeof(dp));
        sum=accumulate(stones.begin(),stones.end(),0);
        return fun(stones,0,sum,0);

    }
};

