class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        std::vector<int> ones;
        ones.reserve(n);
        for (int i = 0; i < n; ++i) if (nums[i] == 1) ones.push_back(i);

        long long ans = 0;

        // Case 1: sum == 0 → count all-zero subarrays
        if (goal == 0) {
            long long run = 0;
            for (int x : nums) {
                if (x == 0) {
                    ++run;                // extend current zero-run
                } else {
                    ans += run * (run + 1) / 2; // all subarrays inside the run
                    run = 0;
                }
            }
            ans += run * (run + 1) / 2;        // tail run, if any
            return (int)ans;
        }

        // Case 2: sum == goal > 0
        // For each window of exactly 'goal' ones: ones[i] .. ones[i+goal-1]
        // Choices on the left  = (# zeros before ones[i]) + 1
        // Choices on the right = (# zeros after ones[i+goal-1]) + 1
        // Contribution = leftChoices * rightChoices
        int m = (int)ones.size();
        for (int i = 0; i + goal - 1 < m; ++i) {
            int firstOneIdx = ones[i];
            int lastOneIdx  = ones[i + goal - 1];

            int prevOne = (i == 0) ? -1 : ones[i - 1];               // index before the block
            int nextOne = (i + goal < m) ? ones[i + goal] : n;       // index after the block

            long long leftZeros  = firstOneIdx - prevOne - 1;        // zeros directly to the left
            long long rightZeros = nextOne - lastOneIdx - 1;         // zeros directly to the right

            ans += (leftZeros + 1) * (rightZeros + 1);
        }

        return (int)ans;
    }
};
