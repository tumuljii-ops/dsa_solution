class Solution {
public:

    int memo(int ind,
             vector<int>& arr,
             vector<vector<int>>& dp,
             int target,
             int sum) {

        // all elements processed
        if(ind == arr.size()) {

            if(sum == target) {
                return 1;
            }

            return 0;
        }

        if(dp[ind][sum] != -1) {
            return dp[ind][sum];
        }

        int nottake =
            memo(ind + 1, arr, dp, target, sum);

        int take = 0;

        if(sum + arr[ind] <= target) {

            take =
                memo(ind + 1,
                     arr,
                     dp,
                     target,
                     sum + arr[ind]);
        }

        return dp[ind][sum] = take + nottake;
    }

    int perfectSum(vector<int>& arr, int target) {

        int n = arr.size();

        vector<vector<int>> dp(
            n,
            vector<int>(target + 1, -1)
        );

        return memo(0, arr, dp, target, 0);
    }
};