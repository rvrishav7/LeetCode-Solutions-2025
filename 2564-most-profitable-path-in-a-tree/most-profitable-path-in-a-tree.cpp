#define MAXI 2000000000

class Solution {
public:
    // DFS to simulate Bob's path from his node to the root (node 0),
    // recording the time he reaches each node along that path.
    bool BobWalk(vector<vector<int>>& gr, vector<int>& BobCrossedTime, vector<bool>& visited, int s, int t) {
        // If Bob reaches node 0, mark time and return true
        if(s == 0){
            BobCrossedTime[s] = t;
            return true;
        }

        // If already visited, skip to avoid cycles
        if(visited[s])
            return false;

        visited[s] = true;

        // Explore neighbors recursively
        for(auto &x : gr[s]) {
            if(BobWalk(gr, BobCrossedTime, visited, x, t + 1)) {
                BobCrossedTime[s] = t; // Bob reaches node `s` at time `t` (on the way to root)
                visited[s] = false;    // Backtrack
                return true;
            }
        }

        visited[s] = false; // Backtrack
        return false;
    }

    // DFS to simulate Alice's traversal from root to all leaves,
    // trying all paths and choosing the most profitable one.
    int AliceWalk(vector<vector<int>>& gr, vector<int>& BobCrossedTime, vector<int>& amount, vector<bool>& visited, int s, int t) {
        int ans = INT_MIN;  // Track the max profit across all paths
        visited[s] = true;

        // Explore all unvisited neighbors (children)
        for(auto &x : gr[s]) {
            if(!visited[x]) {
                ans = max(ans, AliceWalk(gr, BobCrossedTime, amount, visited, x, t + 1));
            }
        }

        // If no children (leaf node), base profit is 0
        if(ans == INT_MIN)
            ans = 0;

        // Now, decide how much Alice gets at current node `s`
        if(t < BobCrossedTime[s]) {
            ans += amount[s];         // Alice arrives before Bob
        } else if(t == BobCrossedTime[s]) {
            ans += (amount[s] / 2);   // They arrive at the same time
        }
        // If t > BobCrossedTime[s], Bob already took the money → Alice gets 0

        visited[s] = false; // Backtrack
        return ans;
    }

    // Main function
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = edges.size() + 1;  // Total number of nodes

        vector<int> BobCrossedTime(n, MAXI);  // Time when Bob reaches each node (init to infinity)
        vector<bool> visited(n);              // Visited array for DFS
        vector<vector<int>> gr(n);            // Graph as adjacency list

        // Build the undirected graph from edges
        for(auto &x : edges){
            gr[x[0]].push_back(x[1]);
            gr[x[1]].push_back(x[0]);
        }

        // Step 1: Simulate Bob's walk to record his arrival times
        BobWalk(gr, BobCrossedTime, visited, bob, 0);

        // Step 2: Simulate Alice's walk and compute max profit
        return AliceWalk(gr, BobCrossedTime, amount, visited, 0, 0);
    }
};
