class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>temp;
        for(auto &x: nums){
            auto p= lower_bound(temp.begin(),temp.end(),x);
            if(p==temp.end())
                temp.push_back(x);
            else
                *p=x;
        }
        return temp.size();
    }
};