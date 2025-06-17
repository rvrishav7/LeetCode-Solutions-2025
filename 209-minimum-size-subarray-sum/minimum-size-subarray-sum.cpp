class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans=INT_MAX,l=0,h=0,n=nums.size(),sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            while(sum>=target &&l<=i){
                ans=min(ans,i-l+1);
                sum-=nums[l++];
            }
        }

        return ans==INT_MAX?0: ans;
    }
};