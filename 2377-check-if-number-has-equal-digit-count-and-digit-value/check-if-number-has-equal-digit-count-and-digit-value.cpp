class Solution {
public:
    bool digitCount(string &nums) {
        map<int,int>count;
        for(auto &x:nums)
            count[x-'0']++;
        for(int i=0;i<nums.size();i++)
            if(count[i]!=(nums[i]-'0'))
                return false;
        return true;
    }
};