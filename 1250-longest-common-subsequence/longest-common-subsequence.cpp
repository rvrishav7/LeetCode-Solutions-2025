class Solution {
public:
    int lcs(string &x,string &y,int n, int m,vector <vector <int>> &dp)
{
    if(n==0|| m==0)
        return dp[n][m]=0;
    if(dp[n][m]!=-1)
        return dp[n][m];
    if(x[n-1]==y[m-1])
        return dp[n][m]=1+lcs(x,y,n-1,m-1,dp);
    else
        return dp[n][m]=max(lcs(x,y,n-1,m,dp),lcs(x,y,n,m-1,dp));
}
    int longestCommonSubsequence(string x, string y) {
        vector <vector <int>> dp(x.length()+1,vector <int>(y.length()+1,-1));
        return lcs(x,y,x.length(),y.length(),dp);
    }
};