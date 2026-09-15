class Solution {
  public:
    int longestBitonicSequence(int n, vector<int> &nums) {
        vector<int> dp(n, 1);
        vector<int> dp1(n, 1);

        // 1. LIS on original array
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        // 2. LIS on reversed array
        vector<int> ans = nums;
        reverse(ans.begin(), ans.end());

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(ans[j] < ans[i]) {
                    dp1[i] = max(dp1[i], dp1[j] + 1);
                }
            }
        }

        // 3. Combine with valid bitonic conditions
        int maxi = 0;
        for(int i = 0; i < n; i++) {
            int reversed_index = n - 1 - i;

            // BOTH increasing and decreasing parts must exist
            if(dp[i] > 1 && dp1[reversed_index] > 1) {
                maxi = max(maxi, dp[i] + dp1[reversed_index] - 1);
            }
        }

        return maxi;
    }
};