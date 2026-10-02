class Solution {
public:
    int hIndex(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ahead=0,ans=0;
        for(int i=0;i<nums.size();i++){
            ahead=nums.size()-i;
            ans=max(ans,min(ahead,nums[i]));
        }
        return ans;
    }
};