class Solution {
public:
    int ar[26][501];
    int beautySum(string s) {
        int n=s.length(),ans=0;
        memset(ar,0,sizeof(ar));
        for(int i=1;i<=n;i++){
            for(int j=0; j<26;j++)
                ar[j][i]=ar[j][i-1];
            ar[s[i-1]-'a'][i]++;
        }
        for(int i=1;i<=n;i++){
            for(int len=1;len<=n;len++){
                if(i+len>n+1)
                    break;
                int maxi=0,mini=501;
                for(int j=0;j<26;j++){
                    maxi=max(maxi,ar[j][i+len-1]-ar[j][i-1]);
                    if(ar[j][i+len-1]-ar[j][i-1])
                        mini=min(mini,ar[j][i+len-1]-ar[j][i-1]);
                }
                if(maxi==len|| mini==len)
                    continue;
                ans+=(maxi-mini);
            }
        }
        return ans;
    }
};