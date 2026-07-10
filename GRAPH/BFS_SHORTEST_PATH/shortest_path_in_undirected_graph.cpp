class Solution {
public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        
        vector<vector<int>> adj(V);
        
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> distance(V, 1e9);
        queue<int> q;
        
        distance[src] = 0;
        q.push(src);
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            for (auto it : adj[node]) {
                if (distance[node] + 1 < distance[it]) {
                    distance[it] = distance[node] + 1;
                    q.push(it);  
                }
            }
        }
        
   
        for (int i = 0; i < V; i++) {
            if (distance[i] == 1e9) distance[i] = -1;
        }
        
        return distance;
    }
};
