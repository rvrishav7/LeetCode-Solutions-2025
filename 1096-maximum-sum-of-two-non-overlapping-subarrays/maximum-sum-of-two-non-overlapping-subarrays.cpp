class Solution {
public:
    int firstLen,secondLen;
    vector<int>pre;
    int dp[4][1001];
    long long int fun(vector<int>&nums, int n, int array){
        if(!array)      
            return 0; 
        if(n<0)     //invalid, array can't be build
            return INT_MIN;
        long long int ans=INT_MIN;
        if(dp[array][n]!=-1)
            return dp[array][n];
        if(array==3){
            if(n+1-secondLen>=0)
                ans=max(ans, (-pre[n+1]+pre[n+1-secondLen])+fun(nums,n-secondLen,array&1));
            if(n+1-firstLen>=0)
                ans=max(ans, (-pre[n+1]+pre[n+1-firstLen])+fun(nums,n-firstLen,array&2));
            ans=max(ans,fun(nums,n-1,array));
        }
        if(array==2){    
            if(n+1-secondLen>=0)
                ans=max(ans, (-pre[n+1]+pre[n+1-secondLen])+fun(nums,n-secondLen,array&1));
            ans=max(ans,fun(nums,n-1,array));
          //  cout<<2<<" i="<<n<<" , ans="<<ans<<endl;
        }
        else if(array==1){
            if(n+1-firstLen>=0)
                ans=max(ans, (-pre[n+1]+pre[n+1-firstLen])+fun(nums,n-firstLen,array&2));
            ans=max(ans,fun(nums,n-1,array));
           // cout<<1<<" i="<<n<<" , ans="<<ans<<endl;
        }
        return dp[array][n]=ans;
    }
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        this->secondLen=secondLen;
        this->firstLen=firstLen;
        pre=nums;
        int array=3;//3: build both array, 2: 1: build only second array,1: build only first array 0: array built
        int sum=0;
        memset(dp,-1,sizeof(dp));
        for(int i=nums.size()-1;i>=0;i--){
            sum+=nums[i];
            pre[i]=sum;
        }
        pre.push_back(0);
        return fun(nums,nums.size()-1,array);
    }
};