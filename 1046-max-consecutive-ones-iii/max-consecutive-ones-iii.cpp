class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0, j=0;        // sliding window boundaries [i..j]
        int ans=0;           // stores the maximum window length
        int cnt=0;           // number of 0's in the current window
        int n=nums.size();

        // Expand the window by moving 'j'
        for(; j<n; j++){
            if(nums[j]==0)
                cnt++;       // count how many 0's are in the window

            // If we have more than 'k' zeros, shrink the window from the left
            while(cnt > k){
                if(nums[i]==0)
                    cnt--;   // reduce zero count as we move 'i' forward
                i++;         // shrink window from left
            }

            // Now window [i..j] has at most k zeros → valid window
            ans = max(ans, j - i + 1);  // update maximum window length
        }

        return ans;   // maximum length of subarray with at most k zeros
    }
};
