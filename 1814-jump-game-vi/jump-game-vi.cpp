class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n=nums.size(),maxi,temp;
        priority_queue<pair<int,int>>q;
        vector<int>dp(n);
        for(int i=0;i<n;i++){
            temp=0;
            while(!q.empty()&&(i-q.top().second>k))
                q.pop();
            if(!q.empty())
                temp=q.top().first;
            dp[i]=nums[i]+temp;
            q.push({dp[i],i});
        }
        return dp[n-1];
    }
};