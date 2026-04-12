class Solution {
public:
    const int mod = 1e9 + 7;

    int solve(int i, string &s, vector<int> &dp) {
        int n = s.length();

        if (i == n) return 1;

        if (dp[i] != -1) return dp[i];

        long long ans = 0;

        ans = (ans + solve(i + 1, s, dp)) % mod;

        if (i + 1 < n && s[i] == s[i + 1]) {
            ans = (ans + solve(i + 2, s, dp)) % mod;
        }


        if (i + 2 < n && s[i] == s[i + 1] && s[i] == s[i + 2]) {
            ans = (ans + solve(i + 3, s, dp)) % mod;
        }

        if ((s[i] == '7' || s[i] == '9') &&
            i + 3 < n &&
            s[i] == s[i + 1] &&
            s[i] == s[i + 2] &&
            s[i] == s[i + 3]) {

            ans = (ans + solve(i + 4, s, dp)) % mod;
        }

        return dp[i] = ans;
    }

    int countTexts(string pressedKeys) {
        int n = pressedKeys.length();

        vector<int> dp(n, -1);

        return solve(0, pressedKeys, dp);
    }
};
