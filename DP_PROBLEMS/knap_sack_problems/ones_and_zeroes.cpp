class Solution {
public:
    
    int solve(vector<string>& strs, int i, int m, int n, 
              vector<vector<vector<int>>>& dp) {
        
        // base case
        if(i == strs.size()) return 0;

        // memo check
        if(dp[i][m][n] != -1) return dp[i][m][n];

        // count zeros and ones in current string
        int zeros = 0, ones = 0;
        for(char ch : strs[i]) {
            if(ch == '0') zeros++;
            else ones++;
        }

        // option 1: skip
        int notTake = solve(strs, i + 1, m, n, dp);

        // option 2: take (if possible)
        int take = 0;
        if(zeros <= m && ones <= n) {
            take = 1 + solve(strs, i + 1, m - zeros, n - ones, dp);
        }

        return dp[i][m][n] = max(take, notTake);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        
        int size = strs.size();
        
        // 3D DP: index, zeros, ones
        vector<vector<vector<int>>> dp(
            size, vector<vector<int>>(m + 1, vector<int>(n + 1, -1))
        );

        return solve(strs, 0, m, n, dp);
    }
};
