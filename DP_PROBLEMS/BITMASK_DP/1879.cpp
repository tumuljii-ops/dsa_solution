class Solution {
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();

        int N = 1 << n;

        vector<int> dp(N, INT_MAX);

        dp[0] = 0;

        for(int mask = 0; mask < N; mask++) {

            int idx = __builtin_popcount(mask);

            for(int j = 0; j < n; j++) {

                if(mask & (1 << j))
                    continue;

                int newMask = mask | (1 << j);

                dp[newMask] = min(
                    dp[newMask],
                    dp[mask] + (nums1[idx] ^ nums2[j])
                );
            }
        }

        return dp[N - 1];
    }
};