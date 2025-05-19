class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        int q=queries.size();
        vector<bool>ans(q);
        vector<int>parent(n);
        for(int i=0;i<n;){
            parent[i]=i;
            int j=i;
            while(j+1<n&&nums[j]+maxDiff>=nums[j+1]){
                parent[j+1]=parent[j];
                j++;
            }
            i=j+1;
        }
        for(int i=0;i<q;i++){
            ans[i]=parent[queries[i][0]]==parent[queries[i][1]];
        }
        return ans;
    }
};