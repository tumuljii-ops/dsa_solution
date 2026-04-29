class Solution {
public:
    int lis(vector<vector<int>>& dp, vector<int>& arr, int difference, int ind, int prev) {

        if (ind == arr.size()) return 0;

        if (dp[ind][prev + 1] != -1) return dp[ind][prev + 1];

        int not_take = lis(dp, arr, difference, ind + 1, prev);
        int take = 0;

        if (prev == -1 || (arr[ind] - arr[prev]) == difference) {
            take = 1 + lis(dp, arr, difference, ind + 1, ind);
        }

        return dp[ind][prev + 1] = max(take, not_take);
    }

    int longestSubsequence(vector<int>& arr, int difference) {
        
        unordered_map<int, int> dp;
        int ans = 0;

        for (int x : arr) {
            dp[x] = dp[x - difference] + 1;
            ans = max(ans, dp[x]);
        }

        return ans;
    }
};
