class Solution {
public:
    bool closeStrings(string &word1, string &word2) {
        if(word1.length()!=word2.length())
            return false;
        map<char,int>mp1,mp2;
        for(auto &x: word1)
            mp1[x]++;
        for(auto &x: word2)
            mp2[x]++;
        for(auto &w2:mp2){
            char ch=w2.first;
            int c=w2.second;
            auto p=mp1.find(ch);
            if(p==mp1.end())
                return false;
            if(p->second==c)
                continue;
            while(p!=mp1.end() && p->second!=c)
                p++;
            if(p==mp1.end())
                return false;
            p->second=mp1[ch];
        }
        return true;
    }
};