class Solution {
public:
int dp[1001][1001];
int fun(string &s, string &t, int n1, int n2){
    if(n2<0)
        return 1;
    if(n1<0)
        return 0;
    if(dp[n1][n2]!=-1)
        return dp[n1][n2];
    if(s[n1]!=t[n2])
        return dp[n1][n2]=fun(s,t,n1-1,n2);
    return dp[n1][n2]=fun(s,t,n1-1,n2)+fun(s,t,n1-1,n2-1);
}
    int numDistinct(string s, string t) {
        memset(dp,-1,sizeof(dp));
        return fun(s,t,s.length()-1, t.length()-1);
    }
};
