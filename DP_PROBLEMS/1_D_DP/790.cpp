class Solution {
public:
    const int mod = 1e9 + 7;

    long long memo(int n, vector<long long>& dp) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        if (n == 3) return 5;

        if (dp[n] != -1) return dp[n];

        long long ans = (2 * memo(n - 1, dp) % mod 
                        + memo(n - 3, dp) % mod) % mod;

        return dp[n] = ans;
    }

    int numTilings(int n) {
        vector<long long> dp(n + 1, -1);
        return memo(n, dp);
    }
};
