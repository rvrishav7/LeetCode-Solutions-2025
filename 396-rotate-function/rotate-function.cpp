class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
       long long int sum=0,ans=0,n=nums.size(),temp,dp[1];
       dp[0]=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            dp[0]+=(i*nums[i]);
        }
        ans=dp[0];
        for(int i=1;i<n;i++){
            temp=dp[0]+sum-(n*nums[n-i]);
            ans=max(ans,temp);
            dp[0]=temp;
        }    
        return ans;
    }
};