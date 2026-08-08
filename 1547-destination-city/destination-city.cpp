class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        string ans;
        unordered_map<string,short int>mp;
        for(auto &x: paths){
            mp[x[0]]++;
            mp[x[1]]--;
            
        }
        for(auto &x: mp)
            if(x.second<0)
                ans=x.first;
        return ans;
    }
};