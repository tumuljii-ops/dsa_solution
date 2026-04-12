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
