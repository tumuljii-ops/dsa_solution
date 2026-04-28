class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<long long> horizontal;
        vector<long long> vertical;

        // row sums
        for (int i = 0; i < n; i++) {
            long long sum = 0;
            for (int j = 0; j < m; j++) {
                sum = sum + grid[i][j];
            }
            horizontal.push_back(sum);
        }

        // column sums
        for (int i = 0; i < m; i++) {
            long long sum1 = 0;
            for (int j = 0; j < n; j++) {
                sum1 = sum1 + grid[j][i];
            }
            vertical.push_back(sum1);
        }

        long long total = 0;
        for (int i = 0; i < horizontal.size(); i++) {
            total = total + horizontal[i];
        }

        // check horizontal cuts
        long long prefix = 0;
        for (int i = 0; i < n - 1; i++) {
            prefix = prefix + horizontal[i];
            if (prefix == total - prefix) {
                return true;
            }
        }

        // check vertical cuts
        prefix = 0;
        for (int i = 0; i < m - 1; i++) {
            prefix = prefix + vertical[i];
            if (prefix == total - prefix) {
                return true;
            }
        }

        return false;
    }
};