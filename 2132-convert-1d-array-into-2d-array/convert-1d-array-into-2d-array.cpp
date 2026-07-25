class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(m*n<original.size() || original.size()%(m*n)!=0)
            return {};
        
        vector<vector<int>>ans(m,vector<int>(n));
        int r,c;

        for(int i=0;i<original.size();i++){
            r=i/n;
            c=i%n;
            ans[r][c]=original[i];
        }
        return ans;
    }
};