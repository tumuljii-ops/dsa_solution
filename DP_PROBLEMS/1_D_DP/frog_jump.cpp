class Solution {
public:
    int memo(vector<int>& dp, vector<int>& height, int ind) {
        int n = height.size();

        // base case: reached last stone
        if (ind == n - 1) return 0;

        if (dp[ind] != -1) return dp[ind];

        int oneStep = INT_MAX;
        int twoStep = INT_MAX;

        // jump 1 step
        if (ind + 1 < n) {
            oneStep = abs(height[ind] - height[ind + 1]) 
                      + memo(dp, height, ind + 1);
        }

        // jump 2 steps
        if (ind + 2 < n) {
            twoStep = abs(height[ind] - height[ind + 2]) 
                      + memo(dp, height, ind + 2);
        }

        return dp[ind] = min(oneStep, twoStep);
    }

    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int> dp(n, -1);

        return memo(dp, height, 0);
    }
};
