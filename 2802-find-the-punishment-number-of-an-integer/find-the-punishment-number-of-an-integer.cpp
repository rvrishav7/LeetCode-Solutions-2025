class Solution {
public:
    bool fun(string &s, int sum, int i, int num){
        if(i>=s.length()&&((sum-num)==0))
            return true;
        if(i>=s.length())
            return false;
        return fun(s,sum-num,i+1,s[i]-'0')||fun(s,sum,i+1,num*10+(s[i]-'0'));
    }
    int punishmentNumber(int n) {
        int ans=0;
        for(int i=1;i<=n;i++){
            string s=to_string(i*i);
            if(fun(s,i,0,0))
                ans+=(i*i);
        }
        return ans;
    }
};