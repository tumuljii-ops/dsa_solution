class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {

        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Build DP table
        for(int i = n - 1; i >= 0; i--) {

            for(int j = m - 1; j >= 0; j--) {

                if(s1[i] == s2[j]) {

                    dp[i][j] =
                        s1[i] + dp[i + 1][j + 1];
                }
                else {

                    dp[i][j] = max(
                        dp[i + 1][j],
                        dp[i][j + 1]
                    );
                }
            }
        }

        int total = 0;

        for(char ch : s1) {
            total += ch;
        }

        for(char ch : s2) {
            total += ch;
        }

        int commonAscii = dp[0][0];

        return total - 2 * commonAscii;
    }
};