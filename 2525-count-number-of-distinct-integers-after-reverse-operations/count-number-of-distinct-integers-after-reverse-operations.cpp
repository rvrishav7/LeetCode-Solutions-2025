class Solution {
public:
    int reverse(int num){
        int rev=0,r,c;
        while(num){
            r=(num%10);
            rev=rev*10+r;
            num/=10;
        }
        return rev;
    }
    int countDistinctIntegers(vector<int>& nums) {
        set<int>temp;
        for(auto &x: nums){
            temp.insert(x);
            temp.insert(reverse(x));
        }
        return temp.size();
    }
};