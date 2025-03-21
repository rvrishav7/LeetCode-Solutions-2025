class Solution {
public:
    bool static cmp(vector<int>&a,vector<int>&b){
        if(a[0]==b[0])
            return b[1]<a[1];
        return a[0]<b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),cmp);
        int ans=0,h=0;
        vector<int>lis;
        for(auto &x: envelopes){
            h=x[1];
            auto p= lower_bound(lis.begin(),lis.end(),h);
            if(p==lis.end())
                lis.push_back(h);
            else
                *p=h;
        }
        return lis.size();
    }
};