class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minima=prices[0];
        int ans=0;
        for(int i=1;i<prices.size();i++){
            if(minima>prices[i])
                minima=prices[i];
            else{
                ans+=(prices[i]-minima);
                minima=prices[i];
            }
        }
        return ans;
    }
};