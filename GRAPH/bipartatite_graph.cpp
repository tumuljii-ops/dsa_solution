class Solution {
public:
    
    bool bfs(int source, vector<int>& color, vector<vector<int>>& adj){
          
        color[source] = 0;
        queue<int> q;
        q.push(source);
            
        while(!q.empty()){
            int node = q.front();
            q.pop();
                  
            for(auto it : adj[node]){
                        
                if(color[it] == -1){
                    color[it] = !color[node];
                    q.push(it);  // FIX
                }
                else if(color[it] == color[node]){
                    return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(int V, vector<vector<int>> &edges) {
          
        int n = edges.size();
        vector<vector<int>> adj(V);
          
        for(int i = 0; i < n; i++){
            int u = edges[i][0];
            int v = edges[i][1];
                
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
          
        vector<int> color(V, -1);
          
        for(int i = 0; i < V; i++){
            if(color[i] == -1){
                if(bfs(i, color, adj) == false){
                    return false;
                }
            }
        }
          
        return true;
    }
};
