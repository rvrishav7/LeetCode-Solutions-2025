class Solution {
public:
    inline string invert(string &s){
        string t=s;
        reverse(t.begin(),t.end());
        for(int i=0;i<t.length();i++)
            t[i]=(t[i]=='0')?'1':'0';
        return t;
    }
    string fun(string s, int i,int n){
        if(i==n)
            return s;
        return fun(s+'1'+invert(s),i+1,n);
    }
    char findKthBit(int &n, int &k) {
        string s="0";
        s=fun(s,1,n);
        return s[k-1];
    }
};