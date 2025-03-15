class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long int ans=0,l=0,h=0,n=prices.size();
        while(h<n){
            h=l+1;
            while(h<n && prices[h]-prices[h-1]==-1)
                h++;
            ans+=(((h-l)*(h-l+1))/2);
            l=h;
        }
        ans+=(((h-l)*(h-l+1))/2);
        return ans;
    }
};