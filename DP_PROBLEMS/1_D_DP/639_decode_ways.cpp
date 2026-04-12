class Solution {
public:
    const int mod = 1e9 + 7;

    long long memo(int i, string &s, vector<long long> &dp) {
        int n = s.length();

        if (i == n) return 1;

        if (dp[i] != -1) return dp[i];

        long long ways = 0;
        
        if (s[i] == '*') {
            ways = (9 * memo(i + 1, s, dp)) % mod;
        } 
        else if (s[i] != '0') {
            ways = memo(i + 1, s, dp);
        }
        if (i + 1 < n) {

            if (s[i] == '*' && s[i + 1] == '*') {
                ways = (ways + 15 * memo(i + 2, s, dp)) % mod;
            }
            else if (s[i] == '*') {
                if (s[i + 1] >= '0' && s[i + 1] <= '6') {
                    ways = (ways + 2 * memo(i + 2, s, dp)) % mod;
                } else {
                    ways = (ways + memo(i + 2, s, dp)) % mod;
                }
            }
            else if (s[i + 1] == '*') {
                if (s[i] == '1') {
                    ways = (ways + 9 * memo(i + 2, s, dp)) % mod;
                } 
                else if (s[i] == '2') {
                    ways = (ways + 6 * memo(i + 2, s, dp)) % mod;
                }
            }
            else {
                int num = (s[i] - '0') * 10 + (s[i + 1] - '0');

                if (num >= 10 && num <= 26) {
                    ways = (ways + memo(i + 2, s, dp)) % mod;
                }
            }
        }

        return dp[i] = ways;
    }

    int numDecodings(string s) {
        int n = s.length();
        vector<long long> dp(n, -1);
        return memo(0, s, dp);
    }
};
