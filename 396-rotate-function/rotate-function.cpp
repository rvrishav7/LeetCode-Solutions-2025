class Solution {
public:
    long long int dp[1];
    long long int fun(vector<int>&nums, int n, long long int &sum,long long int &maxi){
        if(n==0)
            return dp[0];
        long long int temp = fun(nums,n-1,sum,maxi)+sum -((nums.size())*(nums[nums.size()-n])); 
        maxi=max(temp,maxi);
        return temp;   
    } 
    int maxRotateFunction(vector<int>& nums) {
       long long int sum=0,maxi=0;
       dp[0]=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            dp[0]+=(i*nums[i]);
        }
        maxi=dp[0];
        fun(nums,nums.size()-1,sum,maxi);
        return maxi;
    }
};