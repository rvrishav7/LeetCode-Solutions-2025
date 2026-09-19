class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        stack<int>s;
        int i=0;
        for(int j=0;j<n;j++)
            if(nums[j]>nums[i])
                i=j;
        
        ans[i]=-1;
        s.push(i);
        for(int j=(i-1+n)%n;j!=i;j=(j-1+n)%n){
            while(!s.empty()&&nums[s.top()]<=nums[j])
                s.pop();
            int val=-1;
            if(!s.empty())
                val=nums[s.top()];
            ans[j]=val;
            s.push(j);
        }
        return ans;
    }
};