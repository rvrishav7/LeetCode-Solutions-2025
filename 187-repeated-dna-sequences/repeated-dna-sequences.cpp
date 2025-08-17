class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int>mp;
        vector<string>ans;
       int n=s.length(),i=0;
       while(i+9<n){
            mp[s.substr(i,10)]++;
            i++;
       }
       for(auto &x: mp){
            if(x.second>1)
                ans.push_back(x.first); 
       }
        return ans;
    }

};