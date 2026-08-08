class Solution {
public:
    bool detectCapitalUse(string word) {
        int cnt=0;
        for(auto &ch: word)
            if(ch>='A'&&ch<='Z')
                cnt++;
        if(cnt==word.length()||cnt==0)
            return true;
        if(cnt==1&&word[0]>='A'&&word[0]<='Z')
            return true;
        return false;
    }
};