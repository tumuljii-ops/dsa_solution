class Solution {
public:
    int memo(vector<vector<int>>& grid, vector<vector<int>>& moveCost,
             vector<vector<int>>& dp, int row, int col) {

        int n = grid.size();
        int m = grid[0].size();

        if (row == n - 1) return grid[row][col];

        if (dp[row][col] != -1) return dp[row][col];

        int mini = INT_MAX;

        for (int j = 0; j < m; j++) {
            int cost = grid[row][col] 
                     + moveCost[grid[row][col]][j] 
                     + memo(grid, moveCost, dp, row + 1, j);

            mini = min(mini, cost);
        }

        return dp[row][col] = mini;
    }

    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        int ans = INT_MAX;

        for (int j = 0; j < m; j++) {
            ans = min(ans, memo(grid, moveCost, dp, 0, j));
        }

        return ans;
    }
};