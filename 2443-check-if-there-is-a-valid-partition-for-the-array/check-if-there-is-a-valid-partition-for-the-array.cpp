class Solution {
public:
    int n;
    bool fun(vector<int>&nums, int n){
        if(n<0)
            return true;
        if(n==1)
            return nums[0]==nums[1];
        if(n>1){
            if(nums[n-1]==nums[n-2]&&nums[n-2]==nums[n]){   //last 3 same elements
                return fun(nums,n-2)||fun(nums,n-3);
            }
            else if(nums[n]-nums[n-1]==1 &&nums[n-1]-nums[n-2]==1)   //increasing
                return fun(nums,n-3);
            else if(nums[n-1]==nums[n]) //last 2 same elements 
                return fun(nums,n-2);
        }
        return false;
    }
    bool validPartition(vector<int>& nums) {
        return fun(nums,nums.size()-1);
    }
};