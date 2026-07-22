class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        // Min-heap: {cost, node}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        vector<bool> visited(n, false);
        int totalCost = 0;
        
        pq.push({0, 0});

        while (!pq.empty()) {
            auto it = pq.top();   
            pq.pop();

            int wt = it.first;
            int u  = it.second;

            if (visited[u]) continue;

            visited[u] = true;
            totalCost += wt;

            for (int v = 0; v < n; v++) {
                if (!visited[v]) {
                    int cost = abs(points[u][0] - points[v][0]) +
                               abs(points[u][1] - points[v][1]);
                    pq.push({cost, v});
                }
            }
        }

        return totalCost;
    }
};