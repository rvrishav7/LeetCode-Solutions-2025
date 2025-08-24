class Solution {
public:
    int bit[32];
    int calculate_pos(int n,int pos){
        int res=-1;
        for(int i=0;i<32;i++){
            if(n&1)
                bit[i]=pos;
            n>>=1;
            res=max(res,bit[i]);
        }
        return res;
    }
    vector<int> smallestSubarrays(vector<int>& nums) {
        memset(bit,-1,sizeof(bit));
        int n=nums.size(),res;
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--){
            res=calculate_pos(nums[i],i);
            ans[i]=res<0?1:res-i+1;
        }
        return ans;
    }
};