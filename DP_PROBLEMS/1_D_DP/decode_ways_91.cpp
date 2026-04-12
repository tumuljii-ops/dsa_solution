class Solution {
public:
    int memo(vector<int>& dp, string& s, int ind) {
        
        int n = s.length();

        if (ind == n) return 1;  

        if (s[ind] == '0') return 0; 

        if (dp[ind] != -1) return dp[ind];

        int left = memo(dp, s, ind + 1); 

        int right = 0;

        if (ind + 1 < n) {
            int num = (s[ind] - '0') * 10 + (s[ind + 1] - '0');

            if (num >= 10 && num <= 26) {
                right = memo(dp, s, ind + 2);
            }
        }

        return dp[ind] = left + right;
    }

    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n, -1);

        return memo(dp, s, 0);
    }
};

// tabulation -----------------
int numDecodings(string s) {
       int n = s.length();

        vector<int> dp(n + 1, 0);

        dp[n] = 1;  

        for (int i = n - 1; i >= 0; i--) {

            if (s[i] == '0') {
                dp[i] = 0;
                continue;
            }

            int left = dp[i + 1];

            int right = 0;

            if (i + 1 < n) {
                int num = (s[i] - '0') * 10 + (s[i + 1] - '0');

                if (num >= 10 && num <= 26) {
                    right = dp[i + 2];
                }
            }

            dp[i] = left + right;
        }

        return dp[0];
    }
};

