class Solution {
  public:
    int countBT(int h) {
        if (h <= 1) return 1;

        long long MOD = 1000000007;
        vector<long long> dp(h + 1);

        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= h; i++) {
            long long prev1 = dp[i - 1];
            long long prev2 = dp[i - 2];

            long long term1 = (prev1 * prev1) % MOD;
            long long term2 = (2 * prev1 * prev2) % MOD;

            dp[i] = (term1 + term2) % MOD;
        }

        return dp[h];
    }
};