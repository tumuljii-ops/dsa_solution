class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        vector<vector<tuple<int,int,int>>> adj(n);
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int start = e[2];
            int end = e[3];
            adj[u].push_back({v, start, end});
        }

        const long long INF = (long long)4e18;
        vector<long long> dist(n, INF);

        priority_queue<pair<long long,int>,
                       vector<pair<long long,int>>,
                       greater<pair<long long,int>>> pq;

        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            long long t = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (t != dist[u]) {
                continue;
            }

            if (u == n - 1) {
                return (int)t;
            }

            for (auto &edge : adj[u]) {
                int v, start, end;
                tie(v, start, end) = edge;

                long long newTime = INF;

                if (t < start) {
                    newTime = (long long)start + 1;
                } else {
                    if (t <= end) {
                        newTime = t + 1;
                    }
                }

                if (newTime < dist[v]) {
                    dist[v] = newTime;
                    pq.push({dist[v], v});
                }
            }
        }

        return -1;
    }
};