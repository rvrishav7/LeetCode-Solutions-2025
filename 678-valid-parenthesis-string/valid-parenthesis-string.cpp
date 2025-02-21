class Solution {
public:
    int dp[102][102];
    bool fun(string &s, int p, int closed){
        if(closed<0)
            return false;
        if(p>=s.length())
            return closed==0;
        if(dp[p][closed]!=-1)
            return dp[p][closed];
        if(s[p]=='(')
            return dp[p][closed]=fun(s,p+1,closed+1);
        if(s[p]==')')
            return dp[p][closed]=fun(s,p+1,closed-1);
        return dp[p][closed]=fun(s,p+1,closed+1) || fun(s,p+1,closed-1) || fun(s,p+1,closed);
    }
    bool checkValidString(string s) {
        memset(dp,-1,sizeof(dp));
        return fun(s,0,0);
    }
};