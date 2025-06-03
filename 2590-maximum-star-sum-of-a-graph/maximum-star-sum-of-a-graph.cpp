class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();  // Number of nodes in the graph
        long long int ans = INT_MIN, temp;

        // Adjacency list to store the graph. Each node stores its neighboring nodes.
        vector<vector<long long int>> ar(n);

        // Build the undirected graph from the edge list
        for (auto &x : edges) {
            ar[x[0]].push_back(x[1]); // Add edge x[0] -> x[1]
            ar[x[1]].push_back(x[0]); // Add edge x[1] -> x[0] (undirected)
        }

        // Iterate through each node to compute the "star sum" centered at that node
        for (int i = 0; i < n; i++) {
            // Min-heap to keep track of the top k maximum-valued neighbors
            priority_queue<long long int, vector<long long int>, greater<long long int>> q;

            // Start with the value of the central node itself
            temp = vals[i];

            // Add neighbors' values to the priority queue
            for (int j = 0; j < ar[i].size(); j++) {
                q.push(vals[ar[i][j]]);  // Push neighbor value

                // Maintain only the top k largest values (min-heap drops smallest if more than k)
                if (q.size() > k)
                    q.pop();
            }

            // Add the top k neighbors' values to the central node's value if they are positive
            while (!q.empty()) {
                if (temp + q.top() > temp)
                    temp += q.top();  // Add neighbor value only if it increases the sum
                q.pop();
            }

            // Update the answer with the maximum star sum found so far
            ans = max(ans, temp);
        }

        return ans;  // Return the maximum star sum
    }
};
