class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,set<char>>mp1,mp2;
        for(int i=0;i<s.length();i++)
            {
                mp1[s[i]].insert(t[i]);
                mp2[t[i]].insert(s[i]);
            }
        for(auto &x: mp1)
            if(x.second.size()>1)   
                return false;
        for(auto &x: mp2)
            if(x.second.size()>1)   
                return false;
        return true;
    }
};