class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size(),maxi=INT_MIN,max_i=-1,i;
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            if(maxi==nums[i])   
                max_i=i;
        }
        stack<int>s;
        s.push(max_i);
        ans[max_i]=-1;
        i=(max_i-1+n)%n;
        while(i!=max_i){
            while(!s.empty()&&nums[s.top()]<=nums[i])
                s.pop();
            ans[i]=-1;
            if(!s.empty())
                ans[i]=nums[s.top()];
            s.push(i);
            i=(i-1+n)%n;
        }
        return ans;
    }
};