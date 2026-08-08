class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>>ar(n+m);
        vector<int>ans;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                ar[i+j].push_back(mat[i][j]);
            
        for(int i=0;i<ar.size();i++){
            if(!(i&1)){
                for(auto p=ar[i].rbegin();p!=ar[i].rend();p++)
                    ans.push_back(*p);
            }
            else
                for(auto &x: ar[i])
                    ans.push_back(x);
        }
        return ans;
    }
};