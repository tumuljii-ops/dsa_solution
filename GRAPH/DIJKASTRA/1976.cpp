class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        const long long mod = 1e9 + 7;

        vector<vector<pair<int,int>>> adj(n);

        for(int i = 0; i < roads.size(); i++) {

            int u = roads[i][0];
            int v = roads[i][1];
            int w = roads[i][2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);

        dist[0] = 0;
        ways[0] = 1;

        pq.push({0, 0});

        while(!pq.empty()) {

            auto top = pq.top();
            pq.pop();

            long long dis = top.first;
            int node = top.second;

            if(dis > dist[node]) {
                continue;
            }

            for(auto it : adj[node]) {

                int adjNode = it.first;
                int wt = it.second;

                // shorter path found
                if(dis + wt < dist[adjNode]) {

                    dist[adjNode] = dis + wt;

                    ways[adjNode] = ways[node];

                    pq.push({dist[adjNode], adjNode});
                }

                // another shortest path found
                else if(dis + wt == dist[adjNode]) {

                    ways[adjNode] =
                        (ways[adjNode] + ways[node]) % mod;
                }
            }
        }

        return ways[n - 1] % mod;
    }
};