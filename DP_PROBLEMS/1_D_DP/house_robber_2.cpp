class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];  
        vector<int> temp1(nums.begin(), nums.end() - 1);
        vector<int> temp2(nums.begin() + 1, nums.end());

        return max(robLinear(temp1), robLinear(temp2));
    }

private:
    int robLinear(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return f(n - 1, dp, nums);
    }

    int f(int ind, vector<int>& dp, vector<int>& nums) {
        if (ind < 0) return 0;
        if (ind == 0) return nums[0];
        if (dp[ind] != -1) return dp[ind];
        int pick = nums[ind] + f(ind - 2, dp, nums);
        int notpick = f(ind - 1, dp, nums);
        return dp[ind] = max(pick, notpick);
    }
};