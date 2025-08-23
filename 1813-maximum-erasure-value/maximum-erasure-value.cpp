class Solution {
public:
    int mp[10001];
    int maximumUniqueSubarray(vector<int>& nums) {
        memset(mp,-1,sizeof(mp));
        int ans=0,n=nums.size(),j=0;
        vector<int>sum(n+1);
        for(int i=0;i<n;i++){
            sum[i+1]=sum[i]+nums[i];
            if(mp[nums[i]]>=0)
                j=max(j,mp[nums[i]]+1);
            mp[nums[i]]=i;
            ans=max(ans,sum[i+1]-sum[j]);
        }
        return ans;
    }
};