#define ll long long int
class Solution {
public:
    ll dfs(unordered_map<int,vector<int>>&tree,vector<int>& cost,vector<bool>&visited, int root, int &ans){
        if(visited[root])
            return 0;
        ll totalChild=0,maxi=INT_MIN,mini=INT_MAX,temp;
        for(auto &x: tree[root])
            if(!visited[x])
                totalChild++;
        vector<ll>child(totalChild);
        if(totalChild==0)       //leaf node
            return cost[root];

        visited[root]=true;
        for(auto &x: tree[root]){
            if(visited[x])
                continue;
            temp=dfs(tree,cost,visited,x,ans);
            totalChild--;
            child[totalChild]=temp;
            maxi=max(temp,maxi);
            mini=min(temp,mini);
        }
        if(mini!=maxi){
            for(auto &x: child)
                if(x!=maxi)
                    ans++;
        }
        visited[root]=false;
        return cost[root]+maxi;
    }
    int minIncrease(int &n, vector<vector<int>>& edges, vector<int>& cost) {
        int ans=0;
        unordered_map<int,vector<int>>tree;
        vector<bool>visited(n);
        for(auto &x: edges){
            tree[x[0]].push_back(x[1]);
            tree[x[1]].push_back(x[0]);
        }
        dfs(tree,cost,visited,0,ans);
        return ans;
    }
};