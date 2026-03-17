class Solution {
public:
    int combi(vector<int>& nums, int target, vector<int>& dp) {
        if (target == 0) {
            return 1;
        }

        if (target < 0) {
            return 0;
        }

        if (dp[target] != -1) {
            return dp[target];
        }

        int total = 0;

        for (int i = 0; i < nums.size(); i++) {
            total += combi(nums, target - nums[i], dp);
        }

        dp[target] = total;
        return dp[target];
    }

    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1);
        return combi(nums, target, dp);
    }
};