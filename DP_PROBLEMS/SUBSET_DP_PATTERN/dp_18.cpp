class Solution {
public:

    int memo(int ind,
             int target,
             int sum,
             vector<vector<int>>& dp,
             vector<int>& arr) {

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
            memo(ind + 1,
                 target,
                 sum,
                 dp,
                 arr);

        int take = 0;

        if(sum + arr[ind] <= target) {

            take =
                memo(ind + 1,
                     target,
                     sum + arr[ind],
                     dp,
                     arr);
        }

        return dp[ind][sum] = take + nottake;
    }

    int countPartitions(vector<int>& arr, int diff) {

        int totalsum = 0;

        for(int i = 0; i < arr.size(); i++) {
            totalsum += arr[i];
        }

        // parity check
        if((totalsum + diff) % 2 != 0) {
            return 0;
        }

        int target = (totalsum + diff) / 2;

        int n = arr.size();

        vector<vector<int>> dp(
            n,
            vector<int>(target + 1, -1)
        );

        return memo(0, target, 0, dp, arr);
    }
};