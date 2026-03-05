class Solution {
public:
    
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {

        vector<vector<pair<int,int>>> adj(V);

        // build adjacency list
        for(auto e : edges)
        {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v,w});
            adj[v].push_back({u,w});   // remove if graph is directed
        }

        vector<int> dist(V, INT_MAX);

        dist[src] = 0;

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        pq.push({0,src});

        while(!pq.empty())
        {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(d != dist[node])
            {
                continue;
            }

            for(auto edge : adj[node])
            {
                int nextNode = edge.first;
                int weight = edge.second;

                if(dist[node] + weight < dist[nextNode])
                {
                    dist[nextNode] = dist[node] + weight;

                    pq.push({dist[nextNode], nextNode});
                }
            }
        }

        return dist;
    }
};