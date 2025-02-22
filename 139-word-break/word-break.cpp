class Solution {
public:
    int dp[301][301];
    bool fun(string &s, unordered_map<string,bool>& mp,int l, int h){
        if(mp[s.substr(l,h-l+1)])
            return true;
        bool res=false;
        if(dp[l][h]!=-1)
            return dp[l][h];
        for(int i=l;i<h;i++)
            res|=(fun(s,mp,l,i)&&fun(s,mp,i+1,h));
        return dp[l][h]=res;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(dp,-1,sizeof(dp));
        unordered_map<string,bool>mp;
        for(auto &x: wordDict)
            mp[x]=true;
        return fun(s,mp,0,s.length()-1);
    }
};