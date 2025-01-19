class Solution {
public:
    bool hasAllCodes(string &s, int k) {
        int p=0;
        if(s.length()<k)
            return false;
        unordered_map<string,bool>mp;
        for(int i=0;i<=s.length()-k;i++)
            mp[s.substr(i,k)]=true;
        return mp.size()==pow(2,k);
    }
};