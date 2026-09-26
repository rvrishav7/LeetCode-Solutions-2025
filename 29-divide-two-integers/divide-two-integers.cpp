class Solution {
public:
    int divide(int dividend, int divisor) {
        long cnt=0,ans=0;
        if(dividend<0)
            cnt++;
        if(divisor<0)
            cnt++;
        
        long div1=dividend;
        long div2=divisor;
        div1=abs(div1);
        div2=abs(div2);
        if(div2==1){
            if(cnt==2||cnt==0)
                ans=div1;
            else
                ans=-div1;
            if(ans>INT_MAX)
                ans=INT_MAX;
            if(ans<INT_MIN)
                ans=INT_MIN;
            
            return ans;
        }
        while(div1>=div2){
            ans++;
            div1-=div2;
        }
        if(cnt&1)
            ans=-ans;
        if(ans>INT_MAX)
            ans=INT_MAX;
        if(ans<INT_MIN)
            ans=INT_MIN;
        return ans;
    }
};