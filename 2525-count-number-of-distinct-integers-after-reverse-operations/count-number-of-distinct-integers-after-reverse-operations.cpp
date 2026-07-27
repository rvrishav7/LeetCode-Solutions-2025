class Solution {
public:

    int countDistinctIntegers(vector<int>& nums) {
        set<int>temp;
        auto rev = [](int num) {
            int rev=0,r,c;
            while(num){
                r=(num%10);
                rev=rev*10+r;
                num/=10;
            }
            return rev;
        };
        for(auto &x: nums){
            temp.insert(x);
            temp.insert(rev(x));
        }
        return temp.size();
    }
};