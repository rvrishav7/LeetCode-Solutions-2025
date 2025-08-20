class Solution {
public:
    int count[3]={0,},i=0,n,ans=0;
    int numberOfSubstrings(string &s) {
        n=s.length();
        count[0]=count[1]=count[2]=0;
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