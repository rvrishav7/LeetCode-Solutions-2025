class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
      sort(stockPrices.begin(),stockPrices.end());
      if(stockPrices.size()==1)
        return 0;
        int ans=1; 

        for(int i=2;i<stockPrices.size();i++){
            if(((long long int)((long long int)stockPrices[i-1][1]-(long long int)stockPrices[i-2][1])*((long long int)stockPrices[i][0]-(long long int)stockPrices[i-1][0])) == (((long long int)stockPrices[i][1]-(long long int)stockPrices[i-1][1])*((long long int)stockPrices[i-1][0]-(long long int)stockPrices[i-2][0])))
                continue;
            ans++;
        }
        return ans;
    }
};