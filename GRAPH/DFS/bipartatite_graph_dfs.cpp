class Solution {
public:
    
    bool dfs(int node, vector<int>& color, vector<vector<int>>& adj){
          
        for(auto it : adj[node]){
                 
            if(color[it] == -1){
                color[it] = !color[node];
                if(dfs(it, color, adj) == false) return false;
            }
            else if(color[it] == color[node]){
                return false;
            }
        }
        return true;
    }

    bool isBipartite(int V, vector<vector<int>> &edges) {
          
        vector<vector<int>> adj(V);
          
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
          
        vector<int> color(V, -1);
          
        for(int i = 0; i < V; i++){
            if(color[i] == -1){
                color[i] = 0;  
                if(dfs(i, color, adj) == false){
                    return false;
                }
            }
        }
          
        return true;
    }
};
