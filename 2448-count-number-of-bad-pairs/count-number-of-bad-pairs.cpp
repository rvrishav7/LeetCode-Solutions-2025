class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
            mp[nums[i]-i]++;
        for(auto &x: mp){
            int sum=x.second;
            n-=sum;
            ans+=(sum*n);
        }
        return ans;
    }
};


// 4,0,1,0
// 0: 1,3
// 4: 0
// 1: 2