class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        vector<int>degree(n+1);
        for(auto &x: edges)
            degree[x[0]]++,degree[x[1]]++;
        return max_element(degree.begin(), degree.end())-degree.begin();
    }
};