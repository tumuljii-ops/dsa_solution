#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int minDistance(string word1, string word2) {

        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return f(0, 0, word1, word2, dp);
    }

    int f(int i,
          int j,
          string &s1,
          string &s2,
          vector<vector<int>>& dp) {

        // s1 finished
        if (i == s1.size()) {
            return s2.size() - j;
        }

        // s2 finished
        if (j == s2.size()) {
            return s1.size() - i;
        }

        // Memoization
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // Characters match
        if (s1[i] == s2[j]) {

            return dp[i][j] =
                   f(i + 1, j + 1, s1, s2, dp);
        }

        // Insert
        int insertOp =
            1 + f(i, j + 1, s1, s2, dp);

        // Delete
        int deleteOp =
            1 + f(i + 1, j, s1, s2, dp);

        // Replace
        int replaceOp =
            1 + f(i + 1, j + 1, s1, s2, dp);

        return dp[i][j] =
               min(insertOp,
               min(deleteOp, replaceOp));
    }
};