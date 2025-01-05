class Solution {
public:
    int inline bs(vector<int>& nums, int target, int l, int h){
        if(l>h)
            return -1;
        int m=(l+h)/2;
        if(nums[m]==target)
            return m;
        if(nums[m]>target)
            return bs(nums,target,l,m-1);
        return bs(nums,target,m+1,h);
    } 
    int search(vector<int>& nums, int target) {
        int l=0, h=nums.size()-1;
        return bs(nums,target,l,h);
    }
};