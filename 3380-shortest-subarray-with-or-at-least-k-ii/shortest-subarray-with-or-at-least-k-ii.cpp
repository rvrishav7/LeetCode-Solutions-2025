class Solution {
public:
    vector<int>temp;
    void add_or(int num, int &curOr){
        int i=0,remainder=0;
        curOr|=num;
        while(num){
            remainder=num&1;
            temp[i++]+=remainder;
            num>>=1;
        }
    } 
    void remove_or(int num, int &curOr){
        int i=0,remainder=0;
        curOr=0;
        while(num){
            remainder=num&1;
            temp[i++]-=remainder;
            num>>=1;
        }
        for(int i=0;i<64;i++)
            curOr|=(temp[i]?(1<<i):curOr);
    } 
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int i=0,j=0,n=nums.size(),curOr=0,ans=INT_MAX;
        vector<int>temp(64);
        this->temp=temp;
        for(j=0;j<n;j++){
            add_or(nums[j],curOr);
            if(curOr<k)
                continue;
            while(curOr>=k&&i<=j){
                ans=min(ans,j-i+1);
                remove_or(nums[i],curOr);
                i++;
            }
        }
        return (ans==INT_MAX)?-1:ans;
    }
};
