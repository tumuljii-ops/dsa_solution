class Solution {
public:
    int minCost(vector<vector<int>>& houses) {
        int n = houses.size();

        vector<int> minDist(n, INT_MAX);
        vector<bool> visited(n, false);

        minDist[0] = 0;
        int total_cost = 0;

        for (int count = 0; count < n; count++) {
            int u = -1;

            for (int i = 0; i < n; i++) {
                if (!visited[i] && (u == -1 || minDist[i] < minDist[u])) {
                    u = i;
                }
            }

            visited[u] = true;
            total_cost += minDist[u];

         
            for (int v = 0; v < n; v++) {
                if (!visited[v]) {
                    int cost = abs(houses[u][0] - houses[v][0]) +
                               abs(houses[u][1] - houses[v][1]);
                    minDist[v] = min(minDist[v], cost);
                }
            }
        }

        return total_cost;
    }
};
