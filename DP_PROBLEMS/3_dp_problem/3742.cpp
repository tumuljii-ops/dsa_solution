class Solution {
public:
    
    int m, n;

    int dfs(int i, int j, int c, vector<vector<int>>& grid, int k,
            vector<vector<vector<int>>>& dp) {

        // out of bounds
        if(i >= m || j >= n) return INT_MIN;

        // if cost exceeded
        if(c > k) return INT_MIN;

        // reached destination
        if(i == m - 1 && j == n - 1) {
            return grid[i][j];
        }

        if(dp[i][j][c] != -1) return dp[i][j][c];

        int ans = INT_MIN;

        // move down
        if(i + 1 < m) {
            int val = grid[i + 1][j];
            int cost = (val == 0 ? 0 : 1);

            int temp = dfs(i + 1, j, c + cost, grid, k, dp);
            if(temp != INT_MIN) {
                ans = max(ans, grid[i][j] + temp);
            }
        }

        // move right
        if(j + 1 < n) {
            int val = grid[i][j + 1];
            int cost = (val == 0 ? 0 : 1);

            int temp = dfs(i, j + 1, c + cost, grid, k, dp);
            if(temp != INT_MIN) {
                ans = max(ans, grid[i][j] + temp);
            }
        }

        return dp[i][j][c] = ans;
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        
        m = grid.size();
        n = grid[0].size();

        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(k + 1, -1))
        );

        int startCost = (grid[0][0] == 0 ? 0 : 1);

        int ans = dfs(0, 0, startCost, grid, k, dp);

        if(ans == INT_MIN) return -1;
        return ans;
    }
};
