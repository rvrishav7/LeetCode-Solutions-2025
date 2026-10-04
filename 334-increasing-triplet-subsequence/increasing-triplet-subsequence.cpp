class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int>temp;
        for(auto &x: nums){
            auto p=lower_bound(temp.begin(),temp.end(),x);
            if(p!=temp.end())
                *p=x;
            else
                temp.push_back(x);
            if(temp.size()==3)
                return true;
        }
        return temp.size()>=3;
    }
};