class Solution {
public:
    bool isPalindrome(int x) {
       if(x<0)
        return false;
        if(x==0)
            return true;
        long temp=0,num=x;
        while(x){
            long r=(x%10);
            temp*=10;
            temp+=r;
            x/=10;
        }
        return num==temp;
    }
};