class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {

        vector<vector<pair<int,int>>> adj(V);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u,w});
        }

        vector<int> dis(V, INT_MAX);
        dis[src] = 0;

        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> pq;

        pq.push({0, src});

        while (!pq.empty()) {

            auto top = pq.top();
            pq.pop();

            int d = top.first;
            int node = top.second;


            for (auto it : adj[node]) {

                int adjnode = it.first;
                int wt = it.second;

                if (dis[node] + wt < dis[adjnode]) {

                    dis[adjnode] = dis[node] + wt;
                    pq.push({dis[adjnode], adjnode});
                }
            }
        }

        return dis;
    }
};