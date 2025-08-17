class Solution {
public:
    inline int check(map<char,int>&ms,map<char,int>&mt,int &boost){
        return !boost;
    }
    string minWindow(string &s, string &t) {
        pair<int,int>ans={0,INT_MAX}; //{starting pos, min_length}
        int len=t.length(), curr_len=t.length();
        map<char,int>mt,ms;
        int boost=len;
        int l=0,h=0,n=s.length();
        for(int i=0;i<len;i++)
            mt[t[i]]++;
        
        for(int i=0;i<n;i++){
            ms[s[i]]++;
            if(mt[s[i]]&&mt[s[i]]>=ms[s[i]])
                boost--;
            while(check(ms,mt,boost)){   // we have all characters of t in s
                len=i-l+1;
                if(ans.second>len)
                    ans={l,len};
                ms[s[l]]--;
                if(mt[s[l]]&&mt[s[l]]>ms[s[l]])
                    boost++;
                l++;
            }
        }
        return ans.second<INT_MAX?s.substr(ans.first,ans.second):"";
    }
};