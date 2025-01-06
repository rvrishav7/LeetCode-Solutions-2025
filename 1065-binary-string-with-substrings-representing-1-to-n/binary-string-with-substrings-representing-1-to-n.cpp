#define ll long long int
class Solution {
public:
    unordered_map<int,bool>mp;
    bool queryString(string s, int n) {
        int N=s.length(),num=0;
        mp.clear();
        for(int i=0;i<N;i++){
            num=0;
            for(int j=i;j<N;j++){
                num<<=1;
                num|=(s[j]-'0');
                if(num<=n&&num>=1)
                    mp[num]=1;
            }
        }
        return mp.size()==n;
    }
};