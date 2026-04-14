class Solution {
public:
    long long memo(int i, int j, vector<int>& robot, vector<int>& pos,
                   vector<vector<long long>>& dp) {
        
        if (i >= robot.size()) return 0;
        if (j >= pos.size()) return 1e18;

        if (dp[i][j] != -1) return dp[i][j];

        long long not_take = memo(i, j + 1, robot, pos, dp);

        long long take = abs(robot[i] - pos[j]) 
                       + memo(i + 1, j + 1, robot, pos, dp);

        return dp[i][j] = min(take, not_take);
    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        vector<int> pos;

        for (auto &f : factory) {
            int position = f[0];
            int capacity = f[1];

            for (int i = 0; i < capacity; i++) {
                pos.push_back(position);
            }
        }

        int n = robot.size();
        int m = pos.size();

        vector<vector<long long>> dp(n, vector<long long>(m, -1));

        return memo(0, 0, robot, pos, dp);
    }
};
