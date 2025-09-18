class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size(),maxLen=1,count=1;
        vector<pair<int,int>>dp(n);
        dp[0]={1,1};    //{length,occurence}
        for(int i=1;i<n;i++){
            dp[i]={1,1};
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    if(dp[i].first<dp[j].first+1)
                        dp[i]={dp[j].first+1,dp[j].second};
                    else if(dp[i].first==dp[j].first+1)
                        dp[i]={dp[j].first+1,dp[i].second+dp[j].second};
                }
                
            }
            if(maxLen<dp[i].first){
                    maxLen=dp[i].first;
                    count=dp[i].second;
                }
                else if(maxLen==dp[i].first)
                    count+=dp[i].second;
            //cout<<i<<" : "<<dp[i].first<<" "<<dp[i].second<<":   "<<maxLen<<" "<<count <<endl;
        }
        return count;
    }
};