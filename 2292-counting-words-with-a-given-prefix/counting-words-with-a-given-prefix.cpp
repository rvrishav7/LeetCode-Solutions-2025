class Solution {
public:
    inline bool fun(string &word, string &pref){
        int i=0;
        while(i<pref.length()&&i<word.length()){
            if(word[i]!=pref[i])
                break;
            i++;
            if(i==pref.length())
                return true;
        }
        return false;
    }
    int prefixCount(vector<string>& words, string &pref) {
        int ans=0;
        for(auto &x: words)
            ans+=fun(x,pref);
        return ans;
    }
};