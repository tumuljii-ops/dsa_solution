class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        const int INF = 1e9;
        vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));

        for (int i = 1; i <= n; i++) {
            dist[i][i] = 0;
        }

        for (auto it : times) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            dist[u][v] = wt;
        }

        for (int via = 1; via <= n; via++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (dist[i][via] != INF && dist[via][j] != INF) {
                        dist[i][j] = min(dist[i][j],
                                          dist[i][via] + dist[via][j]);
                    }
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[k][i] == INF) return -1; 
            ans = max(ans, dist[k][i]);
        }

        return ans;
    }
};
