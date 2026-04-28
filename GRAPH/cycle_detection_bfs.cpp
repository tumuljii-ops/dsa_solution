class Solution {
public:
    bool bfs(int start, vector<vector<int>>& adj, vector<int>& visited) {
        queue<pair<int, int>> q;
        
        visited[start] = 1;
        q.push({start, -1});  // node, parent
        
        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for (auto neighbor : adj[node]) {
                
                if (visited[neighbor] == 0) {
                    visited[neighbor] = 1;
                    q.push({neighbor, node});
                }
                else {
                    if (neighbor != parent) {
                        return true; // cycle detected
                    }
                }
            }
        }
        
        return false;
    }
    
    bool isCycle(int V, vector<vector<int>>& adj) {
        vector<int> visited(V, 0);
        
        for (int i = 0; i < V; i++) {
            if (visited[i] == 0) {
                if (bfs(i, adj, visited) == true) {
                    return true;
                }
            }
        }
        
        return false;
    }
};
