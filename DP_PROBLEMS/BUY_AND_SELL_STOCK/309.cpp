class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(0, 1, dp, prices);
    }

    int f(int ind, int buy, vector<vector<int>>& dp, vector<int>& prices) {
        int n = prices.size();
        if (ind >= n) return 0;

        if (dp[ind][buy] != -1) return dp[ind][buy];

        if (buy) {
            dp[ind][buy] = max(-prices[ind] + f(ind + 1, 0, dp, prices),
                               f(ind + 1, 1, dp, prices));
        } else {
            dp[ind][buy] = max(prices[ind] + f(ind + 2, 1, dp, prices),
                               f(ind + 1, 0, dp, prices));
        }
        return dp[ind][buy];
    }
};
