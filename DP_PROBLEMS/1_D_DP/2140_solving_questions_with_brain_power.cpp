class Solution {
public:
    long long memo(int ind, vector<long long>& dp, vector<vector<int>>& questions) {
        
        int n = questions.size();

        if (ind >= n) return 0;

        if (dp[ind] != -1) return dp[ind];

        long long take = questions[ind][0];
        int next = ind + questions[ind][1] + 1;

        if (next < n)
            take += memo(next, dp, questions);

        long long skip = memo(ind + 1, dp, questions);

        return dp[ind] = max(take, skip);
    }
    
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();

        vector<long long> dp(n, -1);

        return memo(0, dp, questions);
    }
};

// tabulation will be ---------------------
 long long mostPoints(vector<vector<int>>& questions) {
           int n = questions.size();
        vector<long long> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            
            long long take = questions[i][0];
            int next = i + questions[i][1] + 1;

            if (next < n)
                take += dp[next];

            long long skip = dp[i + 1];

            dp[i] = max(take, skip);
        }

        return dp[0];
        
    }
};