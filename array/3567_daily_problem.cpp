class Solution {
public:
    int min_dif(vector<int>& ans) {
        if (ans.size() <= 1) {
            return 0;
        }

        int mini = INT_MAX;

        for (int i = 1; i < ans.size(); i++) {
            if (ans[i] != ans[i - 1]) {
                mini = min(mini, ans[i] - ans[i - 1]);
            }
        }

        if (mini == INT_MAX) {
            return 0;
        }

        return mini;
    }

    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int col = grid[0].size();

        int fin_rows = rows - k + 1;
        int fin_col = col - k + 1;

        vector<vector<int>> rowss(fin_rows, vector<int>(fin_col, 0));

        for (int i = 0; i <= rows - k; i++) {
            for (int j = 0; j <= col - k; j++) {
                vector<int> ans;

                for (int u = i; u < i + k; u++) {
                    for (int v = j; v < j + k; v++) {
                        ans.push_back(grid[u][v]);
                    }
                }

                sort(ans.begin(), ans.end());
                int min_diff = min_dif(ans);
                rowss[i][j] = min_diff;
            }
        }

        return rowss;
    }
};