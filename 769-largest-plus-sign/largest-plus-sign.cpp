class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>>ar(n,vector<int>(n,1));
        int ans=0;
        for(auto &x: mines)
            ar[x[0]][x[1]]=0;
        
        vector<vector<int>>top=ar;
        vector<vector<int>>down=ar;
        vector<vector<int>>right=ar;
        vector<vector<int>>left=ar;

        
        
        for(int j=0;j<n;j++){
            for(int i=1;i<n;i++){
                if(!top[i][j])
                    continue;
                top[i][j]+=top[i-1][j];
            }
        }

        for(int j=0;j<n;j++){
            for(int i=n-2;i>=0;i--){
                if(!down[i][j])
                    continue;
                down[i][j]+=down[i+1][j];
            }
        }

        for(int j=0;j<n;j++){
            for(int i=1;i<n;i++){
                if(!left[j][i])
                    continue;
                left[j][i]+=left[j][i-1];
            }
        }

        for(int j=0;j<n;j++){
            for(int i=n-2;i>=0;i--){
                if(!right[j][i])
                    continue;
                right[j][i]+=right[j][i+1];
            }
        }

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(ar[i][j]){
                    ans=max(ans,1+min({top[i][j]-1,down[i][j]-1,left[i][j]-1,right[i][j]-1}));
                }
            
        return ans;
    }
};