class Solution {
public:
    int n;
    const int NEG = -1000000000;

    int solve(int i, int xr, vector<int>& nums, int target,
              unordered_map<long long, int>& dp) {
        if (i == n) {
            if (xr == target) {
                return 0;
            }
            return NEG;
        }

        long long key = ((long long)i << 32) | (unsigned int)xr;

        if (dp.find(key) != dp.end()) {
            return dp[key];
        }

        int skip = solve(i + 1, xr, nums, target, dp);

        int take = 1 + solve(i + 1, xr ^ nums[i], nums, target, dp);

        dp[key] = max(skip, take);
        return dp[key];
    }

    int minRemovals(vector<int>& nums, int target) {
        n = nums.size();
        unordered_map<long long, int> dp;

        int maxKeep = solve(0, 0, nums, target, dp);

        if (maxKeep < 0) {
            return -1;
        }

        return n - maxKeep;
    }
};