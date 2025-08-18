class Solution {
public:
    unordered_map<char,int>mp;
    int calculate(string &s, int &start, int &k){
        int ans=0,i=start,n=s.length(),b=0;
        mp.clear();
        for(i=start; i<n;i++){
            mp[s[i]]++;
            for(auto &x: mp)
                if(x.second==k)
                    b=true;
            if(b)
                break;
        }
        
        return (n-i);
    }
    int numberOfSubstrings(string &s, int &k) {
        int ans=0;
        for(int i=0;i<s.length();i++)
            ans+=calculate(s,i,k);
        return ans;
    }
};