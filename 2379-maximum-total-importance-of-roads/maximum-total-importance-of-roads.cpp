class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long>ar(n);
        for(auto &x: roads){
            ar[x[0]]++;
            ar[x[1]]++;
        }
        sort(ar.begin(),ar.end(),greater<int>());
        long long ans=0;
        for(auto &x: ar){
            ans+=(x*n);
            n--;
        }
        return ans;
    }
};