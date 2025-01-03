class Solution {
public:
    int arrangeCoins(int n) {
        int ans=1;
        long long int sum=0;
        for(int i=1;i<=92685;i++){
            sum+=i;
            if(sum<=n)
                ans=i;
            else
                break;
        }
        return ans;
    }
};