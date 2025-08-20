class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int left,right,ans=0;
        vector<int>one;
        one.push_back(-1);
        for(int i=0;i<nums.size();i++)
            if(nums[i]&1)
                one.push_back(i);
        one.push_back(nums.size());
        for(int i=1;i+k<one.size();i++){
            left=one[i]-one[i-1]-1;
            right=one[i+k]-one[i+k-1]-1;
            ans+=(1+(left*(right+1)+right));
         //   cout<<i<<": "<<left<<" "<<right<<endl;
        }
        return ans;
    }
};