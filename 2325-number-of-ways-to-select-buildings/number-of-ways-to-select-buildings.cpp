class Solution {
public:
    long long numberOfWays(string s) {
        long long n=s.size(),leftOne,rightOne,ans=0;
        vector<long long>pre(n),post(n);  
        if(s[0]=='0')
            pre[0]=1;
        if(s[n-1]=='0')
            post[n-1]=1;
        for(int i=1;i<n;i++){
            int i1=n-i-1;   //reverse
            pre[i]=pre[i-1];
            post[i1]=post[i1+1];

            if(s[i]=='0')
                pre[i]++;
            if(s[i1]=='0')
                post[i1]++;
        }

        for(int i=1;i<n-1;i++){
            leftOne=i-pre[i-1];
            rightOne=(n-i-1)-post[i+1];
            if(s[i]=='1'){
                ans+=(pre[i-1]*post[i+1]);
            }
            else{
                ans+=(leftOne*rightOne);
            }
        }
        return ans;
    }
};