class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n=nums.size();
        int m=l.size();
        vector<bool>res;
        for(int i=0;i<m;i++){
            vector<int>temp;
            for(int j=l[i];j<=r[i];j++)
                temp.push_back(nums[j]);
            sort(temp.begin(),temp.end());
            bool f=true;
            int diff=temp[1]-temp[0];
            for(int j=1;j<temp.size();j++)
                if(diff!=(temp[j]-temp[j-1]))
                    f=false;
            res.push_back(f);
        }
        return res;
    }
};