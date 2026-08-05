class Solution {
public:
    int countPrefixes(vector<string>& words, string &s) {
        int cnt=0,i;
        for(auto &x: words){
            for(i=0;i<x.length();i++){
                if(x.length()>s.length()||x[i]!=s[i])
                    break;
            }
            if(i==x.length())
                cnt++;
        }
        return cnt;
    }
};