class Solution {
public:
    unordered_map<int,int>dp;
    int fun(map<int,int>&mp, auto p){
        if(p==mp.end())
            return 0;
        if(dp[p->first]!=-1)
            return dp[p->first];
        auto temp=p;
        auto p1=p;
        temp++;
        int ans=0;
        if(temp!=mp.end() && temp->first-p->first==1){
            temp++;
            ans=max(((p->first*p->second)+fun(mp,temp)),fun(mp,++p));
        }
        else
            ans=(p->first*p->second)+fun(mp,++p);
        return dp[p1->first]=ans;
    }
    int deleteAndEarn(vector<int>& nums) {
        map<int,int>mp;

        for(auto &x: nums){
            mp[x]++;
            dp[x]=-1;
        }
        auto p=mp.begin();
        return fun(mp,p);
    }
};