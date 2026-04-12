class Solution {
public:
    int mod = 1e9 + 7;
     
    int memo(int len, int low, int high, int zero, int one, vector<int>& dp) {
        
        if (len > high) return 0;

        if (dp[len] != -1) return dp[len];

        int count = 0;
          
        if (len >= low) count = 1;

        int left0 = memo(len + zero, low, high, zero, one, dp);
        int right1 = memo(len + one, low, high, zero, one, dp);

        return dp[len] = (count + left0 + right1) % mod;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1, -1);

        return memo(0, low, high, zero, one, dp);
    }
};
