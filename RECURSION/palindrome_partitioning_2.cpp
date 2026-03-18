class Solution {
public:
    bool isPalindrome(string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    int solve(int i, string& s, vector<int>& dp) {
        if (i == s.size()) {
            return 0;
        }

        if (dp[i] != -1) {
            return dp[i];
        }

        int mini = 1e9;

        for (int j = i; j < s.size(); j++) {
            if (isPalindrome(s, i, j)) {
                int pieces = 1 + solve(j + 1, s, dp);
                if (pieces < mini) {
                    mini = pieces;
                }
            }
        }

        dp[i] = mini;
        return dp[i];
    }

    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n, -1);

        return solve(0, s, dp) - 1;
    }
};