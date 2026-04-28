class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = INT_MIN;

        for (int top = 0; top < m; top++) {
            vector<int> colSum(n, 0);

            for (int bottom = top; bottom < m; bottom++) {
                
                // collapse rows into 1D
                for (int col = 0; col < n; col++) {
                    colSum[col] += matrix[bottom][col];
                }

                // now solve 1D max subarray ≤ k
                set<int> prefixSet;
                prefixSet.insert(0);

                int currSum = 0;

                for (int col = 0; col < n; col++) {
                    currSum += colSum[col];

                    auto it = prefixSet.lower_bound(currSum - k);
                    if (it != prefixSet.end()) {
                        ans = max(ans, currSum - *it);
                    }

                    prefixSet.insert(currSum);
                }
            }
        }

        return ans;
    }
};