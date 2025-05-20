class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        bool isPossible=true;
        int n=nums.size(),sum=0;
        vector<int>prefix(n+1);
        for(auto &x: queries){
            prefix[x[0]]--;
            prefix[x[1]+1]++;
        }

        for(int i=0;i<n;i++){
            sum+=prefix[i];
            nums[i]+=sum;
            if(nums[i]>0)
                isPossible=false;
        }
        return isPossible;
    }
};