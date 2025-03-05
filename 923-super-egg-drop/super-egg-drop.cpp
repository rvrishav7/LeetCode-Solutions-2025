int dp[101][10001];
class Solution {
public:
    
    int fun(int egg, int n){
        if(n==0 || n==1)
            return n;
        if(egg==1)
            return n;
        if(dp[egg][n]!=-1)
            return dp[egg][n];
        int ans=INT_MAX,temp;
        int l=0,h=n,mid,left,right;
        while(l<=h){
            mid=(l+h)/2;
            left=fun(egg-1,mid-1);
            right=fun(egg,n-mid);
            if(left<right)
                l=mid+1;
            else
                h=mid-1;    
            temp=1+max(left,right);
            ans=min(ans,temp);
        }
        // for(int i=1;i<=n;i++){
        //     temp=1+max(fun(egg-1,i-1),fun(egg,n-i));
        //     ans=min(ans,temp);
        // }
        return dp[egg][n]=ans;
    }

    int superEggDrop(int k, int n) {
        memset(dp,-1,sizeof(dp));
        return fun(k,n);
    }
};