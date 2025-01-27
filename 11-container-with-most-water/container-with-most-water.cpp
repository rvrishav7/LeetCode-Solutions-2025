class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size(),ans=0,temp;
        int l=0,h=n-1;
        while(l<h){
            temp=(h-l)*min(height[l],height[h]);
            ans=max(ans,temp);
            if(height[l]<height[h])
                l++;
            else
                h--;
        }
        return ans;
    }
};