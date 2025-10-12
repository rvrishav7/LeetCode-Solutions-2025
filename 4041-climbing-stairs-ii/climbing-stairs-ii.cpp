class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int>temp(n+1);
        for(int i=0;i<n;i++){
            int j=i+1,ans=INT_MAX;
            if(j-1>=0)
                ans=min(temp[j-1]+costs[i]+1,ans);
            if(j-2>=0)
                ans=min(temp[j-2]+costs[i]+4,ans);
            if(j-3>=0)
                ans=min(temp[j-3]+costs[i]+9,ans);
            
            temp[j]=ans;

        }
        return temp[n];
    }
};