class Solution {
public:
    int solve(int i, vector<int>& points, vector<int>& dp) {
        if (i < 0) return 0;

        if (dp[i] != -1) return dp[i];

        int take = points[i] + solve(i - 2, points, dp);
        int skip = solve(i - 1, points, dp);

        return dp[i] = max(take, skip);
    }

    int deleteAndEarn(vector<int>& nums) {
        if (nums.empty()) return 0;

        int maxVal = 0;
        for (int x : nums) {
            if (x > maxVal) maxVal = x;
        }

        vector<int> freq(maxVal + 1, 0);

        for (int x : nums) {
            freq[x]++;
        }

        vector<int> points(maxVal + 1, 0);
        for (int i = 0; i <= maxVal; i++) {
            points[i] = i * freq[i];
        }

        vector<int> dp(maxVal + 1, -1);

        return solve(maxVal, points, dp);
    }
};