class Solution {
public:
    int mod = 1000000007;

    int solve(int n, int k, int target, vector<vector<int>>& dp) {
        if (n == 0 && target == 0) {
            return 1;
        }

        if (n == 0 || target < 0) {
            return 0;
        }

        if (dp[n][target] != -1) {
            return dp[n][target];
        }

        long long ways = 0;

        for (int face = 1; face <= k; face++) {
            ways = ways + solve(n - 1, k, target - face, dp);
            ways = ways % mod;
        }

        dp[n][target] = ways;
        return dp[n][target];
    }

    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        return solve(n, k, target, dp);
    }
};