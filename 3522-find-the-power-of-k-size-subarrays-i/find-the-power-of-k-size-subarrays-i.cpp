class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if(k==1)
            return nums;
        int n=nums.size(),i=0,p=0;
        vector<int>ans(n-k+1);
        queue<int>unSorted,maxi;
        maxi.push(0);
        for(int i=1;i<k;i++){
            if(nums[i]-nums[i-1]!=1)
                unSorted.push(i-1);
            
            while(!maxi.empty()&&nums[maxi.front()]<nums[i])
                maxi.pop();
            maxi.push(i);
        }
        ans[p++]=(unSorted.size())?-1:nums[maxi.front()];
        for(i=k;i<n;i++){
            if(unSorted.front()==i-k)
                unSorted.pop();
            if(maxi.front()==i-k)
                maxi.pop();
            if(nums[i]-nums[i-1]!=1)
                unSorted.push(i-1);
            while(!maxi.empty()&&nums[maxi.front()]<nums[i])
                maxi.pop();
            maxi.push(i);
            
            if(unSorted.size()&&unSorted.front()<=i){
                ans[p++]=-1;
                continue;
            }
            ans[p++]=nums[maxi.front()];
        }
         return ans;
    }
};