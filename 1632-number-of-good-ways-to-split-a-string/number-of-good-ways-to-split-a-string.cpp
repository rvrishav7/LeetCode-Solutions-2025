class Solution {
public:
    int numSplits(string s) {
        unordered_map<char,int>mp;
        int n=s.length(),ans=0,count=0;
        vector<int>l(n);
        vector<int>r(n);
        for(int i=0;i<n;i++){
            mp[s[i]]++;
            if(mp[s[i]]==1)
                count++;
            l[i]=count;
        }
        mp.clear();
        count=0;
        for(int i=n-1;i>=0;i--){
            mp[s[i]]++;
            if(mp[s[i]]==1)
                count++;
            r[i]=count;
        }
        for(int i=0;i<n-1;i++)
            if(l[i]==r[i+1])
                ans++;
        return ans;
    }
};