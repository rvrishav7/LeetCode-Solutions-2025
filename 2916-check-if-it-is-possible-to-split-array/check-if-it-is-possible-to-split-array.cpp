class Solution {
public:
    vector<int>pre;
    int dp[101][101];
    bool fun(vector<int>&nums, int &m, int l, int h){
        if(l>=h)
            return true;
        if(pre[h+1]-pre[l]<m)
            return false;
        if(dp[l][h]!=-1)
            return dp[l][h];
        bool ans=false;
        for(int i=l;i<h;i++){
            bool temp=fun(nums,m,l,i)&&fun(nums,m,i+1,h);
            ans|=temp;
        }
        return dp[l][h]=ans;
    }
    bool canSplitArray(vector<int>& nums, int&m) {
        if(nums.size()<=2)
            return true;
        int sum=0;
        memset(dp,-1,sizeof(dp));
        pre.push_back(sum);
        for(auto &x:nums){
            sum+=x;
            pre.push_back(sum);
        }
        return fun(nums,m,0,nums.size()-1);
    }
};