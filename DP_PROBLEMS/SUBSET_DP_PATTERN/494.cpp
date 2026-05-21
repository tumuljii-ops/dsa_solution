class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = 0;
        for (int num : nums) totalSum += num;
        if (totalSum < abs(target) || (totalSum + target) % 2 != 0)
            return 0;

        int S1 = (totalSum + target) / 2;
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(S1 + 1, -1));

        return countSubsets(n - 1, S1, nums, dp);
    }

private:
    int countSubsets(int i, int target, vector<int>& nums, vector<vector<int>>& dp) {
        if (i == 0) {
            if (target == 0 && nums[0] == 0) return 2; 
            if (target == 0 || target == nums[0]) return 1;
            return 0;
        }

        if (dp[i][target] != -1) return dp[i][target];

        int notTake = countSubsets(i - 1, target, nums, dp);
        int take = 0;
        if (nums[i] <= target)
            take = countSubsets(i - 1, target - nums[i], nums, dp);

        return dp[i][target] = take + notTake;
    }
};
