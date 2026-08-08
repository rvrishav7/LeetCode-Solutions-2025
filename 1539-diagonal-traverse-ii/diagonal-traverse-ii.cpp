class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>>ar(n+100001);
        vector<int>ans;
        for(int i=0;i<n;i++)
            for(int j=0;j<mat[i].size();j++)
                ar[i+j].push_back(mat[i][j]);
            
        for(int i=0;i<ar.size();i++){
            for(auto p=ar[i].rbegin();p!=ar[i].rend();p++)
                ans.push_back(*p);

        }
        return ans;
    }
};