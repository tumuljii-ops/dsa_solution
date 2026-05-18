class Solution {
public:

    bool memo(vector<int>& arr, int sum, int ind,
              vector<vector<int>>& dp, int target) {

        // if target achieved
        if (target == sum) {
            return true;
        }

        // out of bounds
        if (ind >= arr.size() || target > sum) {
            return false;
        }

        // already computed
        if (dp[ind][target] != -1) {
            return dp[ind][target];
        }

        // not take
        bool nottake = memo(arr, sum, ind + 1, dp, target);

        // take
        bool take = false;

        if (target + arr[ind] <= sum) {
            take = memo(arr, sum, ind + 1,
                        dp, target + arr[ind]);
        }

        return dp[ind][target] = take || nottake;
    }

    bool isSubsetSum(vector<int>& arr, int sum) {

        int n = arr.size();

        vector<vector<int>> dp(n,
                               vector<int>(sum + 1, -1));

        return memo(arr, sum, 0, dp, 0);
    }
};