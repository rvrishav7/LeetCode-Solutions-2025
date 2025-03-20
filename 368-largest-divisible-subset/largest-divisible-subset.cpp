class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size(),maxi=0,idx=-1;
        sort(nums.begin(),nums.end());
        vector<pair<int,int>>dp(n);
        vector<int>ans;
        for(int i=0;i<n;i++){
            dp[i]={1,i};
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0){
                    if(dp[j].first+1>dp[i].first){
                        dp[i].first=dp[j].first+1;
                        dp[i].second=j;
                    }
                }
            }
            if(dp[i].first>maxi){
                maxi=dp[i].first;
                idx=i;
            }
        }
        while(idx!=dp[idx].second){
            ans.push_back(nums[idx]);
            idx=dp[idx].second;
        }
        ans.push_back(nums[idx]);
        return ans;
    }
};