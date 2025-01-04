class Solution {
public:
    vector<int> constructArray(int n, int k) {
        int isMaxima=0,distance=n-1,i;
        vector<int>ans(n);
        ans[0]=1;
        for(i=0;i<n-1;){
            if(k>1){
                ans[i+1]=ans[i]+((isMaxima)?-distance:+distance);
                k--;
                isMaxima=!isMaxima;
                distance--;
                i++;
            }
            if(k==1)
                break; 
        }
        distance=((isMaxima)?-1:1);
        for(;i<n-1;i++)
            ans[i+1]=ans[i]+distance;
        return ans;
    }
};