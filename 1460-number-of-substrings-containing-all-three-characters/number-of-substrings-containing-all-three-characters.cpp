class Solution {
public:
    int numberOfSubstrings(string s) {
        int count[3]={0,},i=0,n=s.length(),ans=0;
        for(int j=0;j<n;j++){
            count[s[j]-'a']++;
            while(min({count[0],count[1],count[2]})&&i<=j){
                count[s[i++]-'a']--;
            }
            ans+=i;
        }
        return ans;
    }
};