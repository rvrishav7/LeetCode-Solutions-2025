class Solution {
public:
    // Depth First Search (DFS) to explore all stones connected via same row or column
    void dfs(unordered_map<int,vector<int>>& row, 
             unordered_map<int,vector<int>>& col, 
             map<pair<int,int>,bool>& vis, 
             int x, int y, int &count) {
        
        // If this stone (x, y) is already visited, skip it
        if (vis[{x, y}])
            return;

        // Mark current stone as visited
        vis[{x, y}] = true;

        // Increment count of stones in this connected component
        count++;

        // Explore all stones in the same row (x)
        for (auto &col1 : row[x]) {
            dfs(row, col, vis, x, col1, count);
        }

        // Explore all stones in the same column (y)
        for (auto &row1 : col[y]) {
            dfs(row, col, vis, row1, y, count);
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        // row[x] -> list of all columns that have a stone in row x
        unordered_map<int, vector<int>> row;
        // col[y] -> list of all rows that have a stone in column y
        unordered_map<int, vector<int>> col;

        // To track visited stones
        // (x, y) is used as key, so use map<pair<int,int>, bool>
        map<pair<int,int>, bool> vis;

        int ans = 0; // Result: total stones that can be removed

        // Step 1: Build row and column adjacency maps
        for (auto &stone : stones) {
            int r = stone[0];
            int c = stone[1];
            row[r].push_back(c); // stone at (r, c) contributes to row r
            col[c].push_back(r); // and to column c
        }

        // Step 2: Explore each connected group of stones
        for (auto &stone : stones) {
            int r = stone[0];
            int c = stone[1];

            // If this stone already visited as part of some component, skip
            if (vis[{r, c}])
                continue;

            int count = 0; // Count stones in current connected component

            // DFS to explore all stones connected (same row/col)
            dfs(row, col, vis, r, c, count);

            // In a connected group of `count` stones, we can remove (count - 1)
            // and leave one stone behind.
            ans += (count - 1);
        }

        // Step 3: Return total removable stones
        return ans;
    }
};
