class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        int idx=-1,count=0;
        vector<int>indegree(n,0);
        for(auto &x: edges)
            indegree[x[1]]++;
        for(int i=0;i<n;i++)
            if(!indegree[i]){
                count++;
                idx=i;
            }    
        return (count==1)?idx:-1;
    }
};