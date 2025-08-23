class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i=0, j=0;          // sliding window boundaries [i..j]
        int ans=0;             // stores the maximum length result
        int cnt=0;             // count of zeros inside current window
        int n=nums.size();
        int k=1;               // we are allowed to delete at most 1 zero

        // Expand the window by moving 'j'
        for(; j<n; j++){
            if(nums[j]==0)
                cnt++;         // count zeros in the window

            // If window has more than k zeros → shrink from left
            while(cnt > k){
                if(nums[i]==0)
                    cnt--;     // reduce zero count as we move 'i' forward
                i++;           // shrink window
            }

            // Valid window has at most k zeros.
            // But since we must "delete one element", 
            // we count (j - i) instead of (j - i + 1).
            ans = max(ans, j - i);
        }

        return ans;
    }
};
