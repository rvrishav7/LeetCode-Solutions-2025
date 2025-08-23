class Solution {
public:
    int minOperations(vector<int>& nums) {
        int i=0,c=0,n=nums.size();
        for(i=0;i<n;i++){
            while(i<n&&nums[i]) // find next 0
                i++;
            if(i==n || i+2>=n)
                break;
            nums[i+1]=!nums[i+1];
            nums[i+2]=!nums[i+2];
            c++;
        }
        return (i==n)?c:-1;
    }
};