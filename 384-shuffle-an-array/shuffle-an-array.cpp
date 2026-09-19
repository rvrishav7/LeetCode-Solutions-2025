class Solution {
public:
    int i=1,n;
    vector<int>nums;

    Solution(vector<int>& nums) {
        this->nums=nums; 
        n=nums.size();       
    }
    
    vector<int> reset() {
        i=1;
        return nums;
        
    }
    
    vector<int> shuffle() {
        int j=i;
        vector<int>ans=nums;
        for(int i=0;i<n;i++){
            swap(ans[i],ans[(i+rand())%(n)]);
        }
        
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */