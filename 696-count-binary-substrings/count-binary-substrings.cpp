class Solution {
public:
    int countBinarySubstrings(string &s) {
        int zero=0;
        int one=0,cnt=0;
        zero=(s[0]=='0');
        one=(s[0]=='1');
        
        for(int i=1;i<s.length();i++){
            if(s[i]==s[i-1]){
                zero+=(s[i]=='0');
                one+=(s[i]=='1');
            }
            
            if(s[i]!=s[i-1]){
                if(s[i]=='1')
                    one=1;
                else
                    zero=1;
            }
            if(one && zero ){
                if(s[i]=='1'&&one<=zero)
                    cnt++;
                else if(s[i]=='0'&&one>=zero)
                    cnt++;
            }
        }
        return cnt;
    }
};